#include <iostream>
#include <vector>
using namespace std;

typedef struct BTreeNode {
	char data;
	int value;
	struct BTreeNode *leftchild, *rightchild;
}BTreeNode, *PtrBTreeNode;

void direct_insert_sort(vector<int> &a);
void bubble_sort(vector<int> &a);
void quick_sort(vector<int> &a, int low, int high);
void simp_select_sort(vector<int> &a);
void test_sort();

void proc_btree();
PtrBTreeNode creat_test_btree();
void PreorderTraversal(PtrBTreeNode T);
void MidorderTraversal(PtrBTreeNode T);
void PostorderTraversal(PtrBTreeNode T);
void TieroderTraversal(PtrBTreeNode T);
void PreorderVisit(PtrBTreeNode T);
void MidorderVisit(PtrBTreeNode T);
int getDeepthTree(PtrBTreeNode T);


void proc_search();
int seq_search(vector<int> a, int key);
int half_search(vector<int> a, int key);
int half_res_search(vector<int> a, int key, int low, int high);
int moutain_search(vector<int> a);


void cic_matrix(int w, int h);