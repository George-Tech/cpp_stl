#include "data_struct_head.h"
#include <vector>

void cic_matrix(int w, int h)
{
	int k = 0;
	vector <vector<int> > vec;
	vector<int> temp(w);
	vec.resize(h, temp);
	int left = 0, right = w-1, up = 0, down = h-1;
	int i = 0;
	while (1) {
		for (i = left; i <= right; i++)
			vec[up][i] = (k++);
		if (++up > down)
			break;
		for (i = up; i <= down; i++)
			vec[i][right] = (k++);
		if (--right < left)
			break;
		for (i = right; i >= left; i--)
			vec[down][i] = (k++);
		if (--down < up)
			break;
		for (i = down; i >= up; i--)
			vec[i][left] = (k++);
		if (++left > right)
			break;
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++)
			cout << vec[y][x]<< " ";
		cout << endl;
	}
}