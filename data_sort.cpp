#include "data_struct_head.h"
/*====================���������㷨����
-�������� ��ֱ�Ӳ��� | ϣ������ | �۰����� | 2-·�������� 
-�������� ��ð������ | ��������
-ѡ������ ��ѡ������ | ������ 
-�鲢���� ���鲢����
===========================================================*/

/*=====================ʱ�临�Ӷ�-�ռ临�Ӷ�-�ȶ���
���  | ���򷽷�  ʱ�临�Ӷ�(even | best | worse)  �ռ临�Ӷ� | �ȶ���
----------------------------------------------------------------------
����    
ֱ�Ӳ���     O(N^2)    O(N)     O(N^2)       O(1)       �ȶ�
ϣ������     O(N^1.3)  O(N)     O(N^2)       O(1)      ���ȶ�
-----------------------------------------------------------------------
ѡ��
ѡ������     O(N^2)    O(N^2)   O(N^2)       O(1)      ���ȶ�
������       O(N*lgN�� O(N*lgN��O(N*lgN��    O(1)      ���ȶ�
-----------------------------------------------------------------------
����
ð������     O(N^2)    O(N)     O(N^2)       O(1)       �ȶ�
��������     O(N*lgN�� O(N*lgN��O(N^2��      O(lgN)    ���ȶ�
-----------------------------------------------------------------------
�鲢    �鲢����     O(N*lgN�� O(N*lgN��O(N*lgN��    O(N)      �ȶ�
==================================================================*/

/*=====================����ѡ��
N�ϴ�ʱ�临�Ӷ�λO(N*lgN)�Ŀ������򡢶������鲢����
N�ϴ󣬿ռ�����Ҫ���ȶ����鲢����
N��С������ֱ�Ӳ������ѡ������
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

//ֱ�Ӳ�������
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
//ð������
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
//��������
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
//��ѡ������
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
//������

//�鲢����

//��������