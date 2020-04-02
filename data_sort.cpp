#include "data_struct_head.h"

//÷±Ω”≤Â»Î≈≈–Ú
void print_vec(vector<int> p) {
	for (int i = 0; i < p.size(); i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

void test_sort()
{
	vector<int> arr{6,5,3,1,2,4};
	print_vec(arr);
	bubble_sort(arr);
	print_vec(arr);
}

void direct_insert_sort(vector<int> &a)
{
	int n = a.size();
	if (n < 2)
		return;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] <= a[i]) {
			continue;
		} else {
			int j = i-1;
			int tmp = a[i];
			while (j >-1 && a[j] > tmp) {
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = tmp;
		}
	}
	return;
}

void bubble_sort(vector<int> &a)
{
	int n = a.size();
	if (n < 2)
		return;
	for (int i = 0; i < n; i++) {
		bool key = true;
		for (int j = 0; j < n - i -1; j++) {
			if (a[j+1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				key = false;
			}
		}
		if (key)
			break;
	}
}