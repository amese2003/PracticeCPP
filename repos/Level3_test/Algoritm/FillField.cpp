#include <iostream>
#include <vector>

using namespace std;

enum Color
{
	BLACK = 1,
	WHITE,
	RED,
	YELLOW,
	GREEN
};

bool PaintFill(vector<vector<Color>>& screen, int r, int c, Color ocolor, Color ncolor)
{
	if (screen[r][c] == ncolor) return false;
	return PaintFill(screen, r, c, screen[r][c], ncolor);
}

bool PaintFillColor(vector<vector<Color>> screen, int r, int c, Color ocolor, Color ncolor)
{
	if (r < 0 || r >= screen.size() || c < 0 || c >= screen[0].size())
		return false;

	if (screen[r][c] == ocolor)
	{
		screen[r][c] = ncolor;
		PaintFill(screen, r - 1, c, ocolor, ncolor);
		PaintFill(screen, r + 1, c, ocolor, ncolor);
		PaintFill(screen, r, c - 1, ocolor, ncolor);
		PaintFill(screen, r, c + 1, ocolor, ncolor);
	}

	return true;
}