#include "cpp_base_head.h"
/*
list<T> 容器模板定义在 list 头文件中，是 T 类型对象的双向链表。

list 容器具有一些 vector 和 deque 容器所不具备的优势，
它可以在常规时间内，在序列已知的任何位置插入或删除元素。
这是我们使用 list，而不使用 vector 或 deque 容器的主要原因。

list 的缺点是无法通过位置来直接访问序列中的元素，也就是说，不能索引元素。
为了访问 list 内部的一个元素，必须一个一个地遍历元素，
通常从第一个元素或最后一个元素开始遍历。
*/

void init_c_list()
{
	list<std::string> words;
	list<std::string> sayings{ 20 };
	list<double> values(5, 3.14159265);//一个具有 50 个 double 型值的列表，并且每一个值都等于 π。
	list<double> save_values{ values }; // Duplicate of values
	list<double> samples{ ++cbegin(values), --cend(values) };//init by part of values
}

void put_c_list()
{
	//push_front() & push_back()
	std::list<std::string> names{ "Jane", "Jim", "Jules", "Janet" };
	names.push_front("Ian"); // Add string ("Ian") to the front of the list
	names.push_back("Kitty"); // Append string ("Kitty") to the end of the list
	//emplace_front & emplace_back
	names.emplace_front("Ian");//Create string ("Ian") in place at the front of the list
	names.emplace_back("Kitty");// Create string ("Kitty") in place at the end of the list
	//insert
	std::list<int> data{ 0, 1, 2, 3 }; 
	data.insert(++begin(data), 99); // Insert 99 as the second element
	list<int> ::iterator iter = data.begin();
	iter = data.insert(++iter, 88);
	//clear erase 与vector一致
	data.erase(iter);
	//remove  numbers 中出现的所有值等于 99 的元素。
	data.remove(99);
	//unique() 非常有意思，它可以移除连续的重复元素，只留下其中的第一个。
	std::list<std::string> words{ "one", "two", "two", "two", "three", "four", "four" };
	words.unique(); // Now contains "one" "two" "three" "four"
}

class my_greater
{
public:
	bool operator () (int s1, int s2)
	{
		if (s1 > s2)
			return 1;
		else
			return 0;
	}
};

bool cmp(int x, int y) {
	return x > y ? 1 : 0;
}

void sort_c_list()
{
	std::list<int> data{ 4, 0, 3, 1, 2 };
	list<int> datacopy{ data };
	data.sort();
	data.sort(my_greater());
	datacopy.sort([](int x, int y) {return x > y ? 1 : 0;});//datacopy.sort(cmp())
	
	//merge
	//list 的成员函数 merge() 以另一个具有相同类型元素的 list 容器作为参数。
	//两个容器中的元素都必须是升序。参数 list 容器中的元素会被合并到当前的 list 容器中
	std::list<int> my_values{ 2, 4, 6, 14 };
	std::list<int> your_values{ -2, 1, 7, 10 };
	my_values.merge(your_values);//my_values contains: -2 1 2 4 6 7 10 14
	your_values.empty(); // Returns true
	//元素从 your_values 转移到 my_values，
	//因此，在执行完这个操作后，your_values 中就没有元素了。
	//改变每个 list 节点的指针，在适当的位置将它们和当前容器的元素链接起来，
	//这样就实现了元素的转移。list 节点在内存中的位置不会改变；只有链接它们的指针变了。
	//在合并的过程中，两个容器中的元素使用 operator()() 进行比较。
}

void visit_c_list()
{
	//begin() 和 end() 分别返回的是指向第一个和最后一个元素下一个位置的双向迭代器。
	//rbegin() 和 rend() 函数返回的双向迭代器，可以让我们逆序遍历元素
	std::list<int> my_values{ 0,1,2,3,4,5};
	list<int>::iterator iter1 = ++my_values.begin();
	list<int>::iterator iter2 = --my_values.end();
	cout << *iter1 << " " << *iter2 << endl;	
	for (auto iter3 = my_values.rbegin(); iter3 != my_values.rend(); iter3++)
		cout << *iter3 << " ";
	int a = 0;

}


/*
forward_list 容器以单链表的形式存储元素。
forward_list 的模板定义在头文件 forward_list 中。
fdrward_list 和 list 最主要的区别是:它不能反向遍历元素；只能从头到尾遍历。
*/
void c_forwad_list()
{
	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	auto count = std::distance(std::begin(my_words), std::end(my_words));
	// Result is 3
	std::forward_list<int> data{ 10, 21, 43, 87, 175, 351 };
	auto iter = std::begin(data);
	size_t n{ 3 };
	std::advance(iter, n);//distance() 的第一个参数是一个开始迭代器，第二个参数是一个结束迭代器，它们指定了元素范围。当需要将前向迭代器移动多个位置时
	std::cout << "The " << n + 1 << "th element is n "<< *iter << std::endl;
	// Outputs 87
	//forward_list 包含成员函数splice_after() 和 insert_after()，
	//用来代替 list 容器的 splice() 和 insert()；
	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	std::forward_list<std::string> your_words{ "seven", "four", "nine" };
	my_words.splice_after(my_words.before_begin(), your_words, ++std::begin(your_words));
	//forward_list 和 list —样都有成员函数 sort() 和 merge()，它们也都有 remove()、remove_if() 和unique()，所有这些函数的用法都和 list 相同
}