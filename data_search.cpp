#include "data_struct_head.h"
#include <vector>

void proc_search()
{
	vector<int> seq{ 2, 4, 1, 3, 6, 8 };
	vector<int> hal{ 1, 2, 3, 4, 5, 6, 9 };
	cout << "顺序查找：3 = " << seq_search(seq, 3) << endl;
	cout << "对半查找：3 = " << half_search(hal, 2) << endl;
	cout << "对半查找：6 = " << half_res_search(hal, 2, 0, 6) << endl;
	vector<int> mon{ 1, 2, 3, 4, 5, 6, 2, 0};
	cout << "moutain_search = " << moutain_search(mon) << endl;
}

int seq_search(vector<int> a, int key)
{
	int k = -1;
	for (int i = 0; i < a.size(); i++) {
		if (key == a[i]) {
			k = i;
			break;
		}

	}
	return k;
}

int half_search(vector<int> a, int key)
{
	int low, mid, high;
	low = 0;
	high = a.size() - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == key)
			return mid;
		else if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
	}
	return -1;
}

int half_res_search(vector<int> a, int key, int low, int high)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (a[mid] == key)
		return mid;
	if (key < a[mid])
		return half_res_search(a, key, low, mid-1);
	if (key > a[mid])
		return half_res_search(a, key, mid+1, high);

}

int moutain_search(vector<int> a)
{
	int low, mid, high;
	low = 0;
	high = a.size();
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] >= a[mid - 1] && a[mid] >= a[mid + 1])
			return a[mid];
		else if (a[mid] < a[mid - 1])
			high = mid;
		else if (a[mid] < a[mid + 1])
			low = mid;
	}
	return a[(low + high) / 2];
}