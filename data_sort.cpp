#include "data_struct_head.h"
/*====================常见排序算法分类
-插入排序 ：直接插入 | 希尔排序 | 折半排序 | 2-路插入排序 
-交换排序 ：冒泡排序 | 快速排序
-选择排序 ：选择排序 | 堆排序 
-归并排序 ：归并排序
===========================================================*/

/*=====================时间复杂度-空间复杂度-稳定性
类别  | 排序方法  时间复杂度(even | best | worse)  空间复杂度 | 稳定性
----------------------------------------------------------------------
插入    
直接插入     O(N^2)    O(N)     O(N^2)       O(1)       稳定
希尔排序     O(N^1.3)  O(N)     O(N^2)       O(1)      不稳定
-----------------------------------------------------------------------
选择
选择排序     O(N^2)    O(N^2)   O(N^2)       O(1)      不稳定
堆排序       O(N*lgN） O(N*lgN）O(N*lgN）    O(1)      不稳定
-----------------------------------------------------------------------
交换
冒泡排序     O(N^2)    O(N)     O(N^2)       O(1)       稳定
快速排序     O(N*lgN） O(N*lgN）O(N^2）      O(lgN)    不稳定
-----------------------------------------------------------------------
归并    归并排序     O(N*lgN） O(N*lgN）O(N*lgN）    O(N)      稳定
==================================================================*/

/*=====================排序选择
N较大：时间复杂度位O(N*lgN)的快速排序、堆排序或归并排序
N较大，空间允许，要求稳定：归并排序
N较小，可以直接插入或者选择排序
==================================================================*/

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
	simp_select_sort(arr);
	print_vec(arr);
}

//直接插入排序
void direct_insert_sort(vector<int> &a)
{
	cout << "insert sort" << endl;
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
//冒泡排序
void bubble_sort(vector<int> &a)
{
	cout << "bubble sort" << endl;
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
//快速排序
void quick_sort(vector<int> &a, int low, int high)
{
	cout << "quick sort" << endl;
	if (low >= high)
		return;
	int i = low; 
	int j = high;
	int curValue = a[i];
	while (i < j) {
		while (i < j && a[j] >= curValue) {
			j--;
		}
		a[i] = a[j];
		while (i < j && a[i] <= curValue) {
			i++;
		}
		a[j] = a[i];
	}
	a[i] = curValue;
	quick_sort(a, low, i-1);
	quick_sort(a, i+1, high);

}
//简单选择排序
void simp_select_sort(vector<int> &a)
{
	cout << "select sort" << endl;
	int n = a.size();
	if (n < 2)
		return;
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for (int j = i+1; j < n; j++) {
			if (a[k] > a[j]) {
				k = j;
			}
		}
		if (k != i){
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
	}
}
//堆排序

//归并排序

//基数排序