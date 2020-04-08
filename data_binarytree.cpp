#include "data_struct_head.h"
#include <queue>
#include <stack>

static void print_tree(BTreeNode *t)
{
	cout << t->data;
}


void proc_btree()
{
	PtrBTreeNode root_t = creat_test_btree();
	cout << endl << "PreorderTraversal" << endl;
	PreorderTraversal(root_t);
	cout << endl;
	PreorderVisit(root_t);
	cout << endl;
	cout << endl << "MidorderTraversal" << endl;
	MidorderTraversal(root_t);
	cout << endl;
	MidorderVisit(root_t);
	cout << endl;
	cout << endl << "PostorderTraversal" << endl;
	PostorderTraversal(root_t);
	cout << endl << "TieroderTraversal" << endl;
	TieroderTraversal(root_t);

	cout << endl << "cal deep :" << getDeepthTree(root_t) << endl;
	
}

PtrBTreeNode creat_test_btree()
{
	BTreeNode* A = new BTreeNode; //root
	BTreeNode* B = new BTreeNode;
	BTreeNode* C = new BTreeNode;
	BTreeNode* D = new BTreeNode;
	BTreeNode* E = new BTreeNode;
	BTreeNode* F = new BTreeNode;
	A->data = 'A';
	B->data = 'B';
	C->data = 'C';
	D->data = 'D';
	E->data = 'E';
	F->data = 'F';
	A->leftchild = B;
	A->rightchild = C;
	B->leftchild = D;
	B->rightchild = E;
	C->leftchild = F;
	C->rightchild = NULL;
	D->leftchild = NULL;
	D->rightchild = NULL;
	E->leftchild = NULL;
	E->rightchild = NULL;
	F->leftchild = NULL;
	F->rightchild = NULL;
	return A;
}

void PreorderTraversal(PtrBTreeNode T)
{
	if (T == NULL)
		return;
	print_tree(T);
	PreorderTraversal(T->leftchild);
	PreorderTraversal(T->rightchild);
}

void MidorderTraversal(PtrBTreeNode T)
{
	if (T == NULL)
		return;
	MidorderTraversal(T->leftchild);
	print_tree(T);
	MidorderTraversal(T->rightchild);
}

void PostorderTraversal(PtrBTreeNode T)
{
	if (T == NULL)
		return;
	PostorderTraversal(T->leftchild);
	PostorderTraversal(T->rightchild);
	print_tree(T);
}

void TieroderTraversal(PtrBTreeNode T)
{
	queue<BTreeNode *> tierQ;
	BTreeNode *it = T;
	tierQ.push(it);
	while (!tierQ.empty()) {
		it = tierQ.front();
		print_tree(it);
		tierQ.pop();
		if (it->leftchild)
			tierQ.push(it->leftchild);
		if (it->rightchild)
			tierQ.push(it->rightchild);
	}
}

void PreorderVisit(PtrBTreeNode T)
{
	stack<BTreeNode *> tierS;
	BTreeNode *it = T;
	tierS.push(it);
	while (!tierS.empty()) {
		it = tierS.top();
		print_tree(it);
		tierS.pop();
		if (it->rightchild)
			tierS.push(it->rightchild);
		if (it->leftchild)
			tierS.push(it->leftchild);

	}
}

void MidorderVisit(PtrBTreeNode T)
{
	stack<BTreeNode *> tierS;
	BTreeNode *it = T;
	while (it || !tierS.empty()) {
		if (it) {
			tierS.push(it);
			it = it->leftchild;
		} else {
			it = tierS.top();
			print_tree(it);
			tierS.pop();
			it = it->rightchild;
		}
	}

}

void PostorderVisit(PtrBTreeNode T)
{
	if (T == NULL)
		return;
	stack<BTreeNode *> tierS;
	tierS.push(T);
	BTreeNode* pre = NULL;
	BTreeNode* cur = NULL;
	while (!tierS.empty()) {
		cur = tierS.top();
		if ((cur->leftchild == NULL && cur->rightchild == NULL) || (pre != NULL && (pre == cur->leftchild || pre == cur->rightchild))){
			print_tree(cur);
			tierS.pop();
			pre = cur;
		}
		else {
			if (cur->rightchild != NULL)
				tierS.push(cur->rightchild);
			if (cur->leftchild != NULL)
				tierS.push(cur->leftchild);
		}
	}
}

void DeepVisit(PtrBTreeNode T)
{
	stack<BTreeNode *> tierS;
	BTreeNode *it = T;
	tierS.push(it);
	while (!tierS.empty()) {
		it = tierS.top();
		print_tree(it);
		tierS.pop();
		if (it->rightchild)
			tierS.push(it->rightchild);
		if (it->leftchild)
			tierS.push(it->leftchild);
	}
}

void WideVisit(PtrBTreeNode T)
{
	queue<BTreeNode *> tierQ;
	BTreeNode *it = T;
	tierQ.push(it);
	while (!tierQ.empty()) {
		it = tierQ.front();
		print_tree(it);
		tierQ.pop();
		if (it->leftchild)
			tierQ.push(it->leftchild);
		if (it->rightchild)
			tierQ.push(it->rightchild);
	}
}

int getDeepthTree(PtrBTreeNode T)
{
	if (T == NULL)
		return 0;
	int left = getDeepthTree(T->leftchild);
	int right = getDeepthTree(T->rightchild);
	return left > right ? left + 1 : right + 1;
}

int getMinDeep(PtrBTreeNode T) {
	if (T == NULL)
		return 0;
	int left = getMinDeep(T->leftchild);
	int right = getMinDeep(T->rightchild);
	if (left == 0)
		return right + 1;
	if (right == 0)
		return left + 1;
	return left < right ? left + 1 : right + 1;
}

int getNodeNum(PtrBTreeNode T)
{
	if (T == NULL)
		return 0;
	return getNodeNum(T->leftchild) + getNodeNum(T->rightchild) + 1;
}

int getLeafNum(PtrBTreeNode T)
{
	if (T == NULL)
		return 0;
	if (T->leftchild == NULL && T->leftchild == NULL)
		return 1;
	return getLeafNum(T->leftchild) + getLeafNum(T->rightchild);
}

