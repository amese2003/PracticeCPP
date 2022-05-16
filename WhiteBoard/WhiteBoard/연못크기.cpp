#include "pch.h"

int computeSize(vector<vector<int>> land, vector<vector<bool>> visited, int col, int row)
{
	if (col < 0 || row < 0 || col >= land.size() || row >= land[col].size() || visited[col][row] || land[col][row] != 0)
		return 0;

	int size = 1;
	visited[col][row] = true;

	for (int coldir = -1; coldir <= 1; coldir++)
	{
		for (int rowdir = -1; rowdir <= 1; rowdir++)
		{
			size += computeSize(land, visited, col + coldir, row + rowdir);
		}
	}

	return size;
}

vector<int> computePondSize(vector<vector<int>> land)
{
	vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
	vector<int> pondSize;

	for (size_t col = 0; col < land.size(); col++)
	{
		for (size_t row = 0; row < land[col].size(); row++)
		{
			int size = computeSize(land, visited, col, row);
			if (size > 0)
				pondSize.push_back(size);
		}
	}

	return pondSize;
}

int lakeSize()
{
	vector<int> res = computePondSize({
		{0,2,1,0},
		{0,1,0,1},
		{1,1,0,1},
		{0,1,0,1}
		});

	cout << res[0] << endl;

	return 0;
}

