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

void insert_c_vector()
{
	//emplace 第一个参数是一个迭代器，它确定了对象生成的位置。
	//对象会被插入到迭代器所指定元素的后面。第一个参数后的参数，都作为插入元素的构造函数的参数传入
	vector<int> nums{0,3};
	vector<int>::iterator iter = nums.emplace(++nums.begin(), 1);
	nums.emplace(++iter, 2);
	//insert
	nums.insert(iter, 10);
	int a = 1;
}