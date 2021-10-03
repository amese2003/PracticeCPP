#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Point
{
public:
	Point(int row, int col) : _row(row), _col(col) {}
	~Point() {};
public:
private:
	int _row;
	int _col;

};


vector<Point> GetPath(vector<vector<bool>> maze)
{
	if (maze.empty() || maze.size() == 0)
		return {};

	vector<Point> path;
	unordered_set<Point> failedPoint;

	if (GetPath(maze, maze.size() - 1, maze[0].size() - 1, path, failedPoint))
		return path;

	return {};
}

bool GetPath(vector<vector<bool>> maze, int row, int col, vector<Point>& path, unordered_set<Point>& failedPoints)
{
	if (col < 0 || row < 0 || !maze[row][col])
		return false;

	Point p(row, col);

	if (failedPoints.find(p) == failedPoints.end())
		return false;

	bool isAtOrigin = (row == 0) && (col == 0);

	if (isAtOrigin || GetPath(maze, row, col - 1, path, failedPoints)
		|| GetPath(maze, row - 1, col, path, failedPoints)) {
		path.push_back(p);
		return true;
	}

	failedPoints.insert(p);
	return false;
}