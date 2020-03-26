#include "cpp_base_head.h"

/*
deque<T>，一个定义在 deque 头文件中的容器模板，可以生成包含 T 类型元素的容器，
它以双端队列的形式组织元素。
可以在容器的头部和尾部高效地添加或删除对象，这是它相对于 vector 容器的优势。
当应用包含先入先出的事务处理时，都应该使用 deque 容器。
*/

void init_c_deque()
{
	deque<int> a_deque;    // A deque container with no elements
	deque<int> my_deque(10); // A deque container with 10 elements
	deque<string> words{ "one", "none", "some", "all", "none", "most", "many" };
	deque<string> words_copy{ words };// Makes a copy of the words container
	deque<string> words_part{ std::begin(words), std::begin(words) + 5 };
}

void visit_c_deque()
{
	deque<string> words{ "one", "none", "some", "all", "none", "most", "many" };
	int dsize = words.size();
	//下标访问
	std::cout << words.at(2) << std::endl; // Output the third element in words
	//deque 成员函数 front() 和 back() 的用法也和 vector 相同
	std::cout << "front = " << words.front() << " back = " << words.back() << std::endl;
	//push_bck & pop_back
	words.push_back("newtail");
	words.pop_back();
	//push_front & pop_front
	words.push_front("newhead");
	words.pop_front();
	//emplace_front()
	// insert() 函数也同样适用于 deque 容器。
	//在 deque 的任意位置插入一个元素会让现有的迭代器全部失效，因此需要重新生成它们。
	//deque 的成员函数 erase() 也和 vector 的相同，它的成员函数 clear() 可以移除一些元素。
}