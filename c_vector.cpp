#include "cpp_base_head.h"
void init_c_vector()
{
	vector<int> values;//empty
	vector<int> nums{0,1,2,3,4,5};//1,2,3,4,5
	vector<int> numzeores(4);//0,0,0,0
	vector<int> numones(4,1);//1,1,1,1
	vector<int> cpynums(nums);
	cout << "init down" << endl;
}

void visit_c_vector()
{
	vector<int> nums{ 0, 1, 2, 3, 4, 5 };
	cout << "nums[1] = " << nums[1] << endl;
	cout << "nums.front = " << nums.front() << endl;
	cout << "nums.back = " << nums.back() << endl;
	//iterator
	vector<int>::iterator iter;
	for (iter = nums.begin(); iter != nums.end(); iter++) {
		cout << *iter << " ";
	}
}

void insert_delete_c_vector()
{
	//emplace ��һ��������һ������������ȷ���˶������ɵ�λ�á�
	//����ᱻ���뵽��������ָ��Ԫ�صĺ��档��һ��������Ĳ���������Ϊ����Ԫ�صĹ��캯���Ĳ�������
	vector<int> nums{0,3,4,5,6};
	vector<int>::iterator iter = nums.emplace(++nums.begin(), 1);
	iter = nums.emplace(++iter, 2);
	//insert
	iter = nums.insert(iter, 10);
	//delete
	//delete all : nums.clear();
	nums.push_back(11);//����β��
	nums.pop_back();//ɾ��ĩβ
	//erase
	nums.erase(iter);
	nums.erase(++nums.begin(), --nums.end());
	int a = 1;
}