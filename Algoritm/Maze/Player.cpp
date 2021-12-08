#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		_board->GenerateMap_Prim();
		Init(_board);
		return;
	}

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지 도착 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos { -1, 0 },// UP
		Pos { 0, -1 },// LEFT
		Pos { 1, 0 }, // DOWN
		Pos { 0, 1 }  // RIGHT
	};

	while (pos != dest)
	{
		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인.
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전.
			_dir = newDir;
			// 앞으로 한 보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진 할 수 있는지 확인.
		else if (CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전.
			_dir = (_dir + 1) % DIR_COUNT;

		}
	}

	stack<Pos> s;
	for (int i = 0; i < _path.size() - 1; i++)
	{

		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	if (_path.empty() == false)
		s.push(_path.back());

	vector<Pos> path;

	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	std::reverse(path.begin(), path.end());


	_path = path;
}

void Player::Bfs()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지 도착 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos { -1, 0 },// UP
		Pos { 0, -1 },// LEFT
		Pos { 1, 0 }, // DOWN
		Pos { 0, 1 }  // RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	//vector<vector<Pos>> parent;
	map<Pos, Pos> parent;

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;


	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest)
			break;

		for (int32 dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + front[dir];
			
			if (CanGo(nextPos) == false)
				continue;

			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	_path.clear();

	pos = dest;
	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	::reverse(_path.begin(), _path.end());

	_path.push_back(pos);
}

struct PQNode
{
	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32		f;
	int32		g;
	Pos			pos;
};

void Player::AStar()
{
	// 점수 매기기
	// F = G + H
	// F = 최종 점수 (작을 수록 좋음.)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
	// H = 목적지에서 얼마나 가까울지

	Pos start = _pos;
	Pos dest = _board->GetExitPos();

	enum
	{
		DIR_COUNT = 8
	};

	Pos front[] =
	{
		Pos { -1, 0 },		// UP
		Pos { 0, -1 },		// LEFT
		Pos { 1, 0 },		// DOWN
		Pos { 0, 1 },		// RIGHT
		Pos { -1, -1 },		// UP_LEFT
		Pos { 1, -1 },		// DOWN_LEFT
		Pos { 1, 1 },		//DOWN_RIGHT
		Pos { -1, 1 }		// UP_RIGHT
	};

	int32 cost[] =
	{
		10,			// UP
		10,			// LEFT
		10,			// DOWN
		10,			// RIGHT
		14,			// UP_LEFT
		14,			// DOWN_LEFT
		14,			//DOWN_RIGHT
		14			// UP_RIGHT
	};

	const int32 size = _board->GetSize();

	vector<vector<bool>> closed(size, vector<bool>(size, false));

	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	map<Pos, Pos> parent;
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// 초기값
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode{ g + h, g, start });
		best[start.y][start.x] = g + h;
		parent[start] = start;
	}

	while (pq.empty() == false)
	{
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서
		// 더 빠른 경로로 인해서 이미 방문되면 스킵

		if (closed[node.pos.y][node.pos.x])
			continue;
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + front[dir];

			if (CanGo(nextPos) == false)
				continue;

			if (closed[nextPos.y][nextPos.x])
				continue;

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode{ g + h, g, nextPos });
			parent[nextPos] = node.pos;
		}
	}

	Pos pos = dest;

	_path.clear();
	_pathIndex = 0;

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	::reverse(_path.begin(), _path.end());
}
