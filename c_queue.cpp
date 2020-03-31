#include "cpp_base_head.h"
//队列queue 只能访问 queue<T> 容器适配器的第一个和最后一个元素。
//只能在容器的末尾添加新元素，只能从头部移除元素。

void init_c_queue() //queue 的生成方式和 stack 相同
{
	std::queue<std::string> words;
	std::queue<std::string> copy_words{ words }; // A duplicate of words
	//stack<T>、queue<T> 这类适配器类都默认封装了一个 deque<T> 容器，也可以通过指定第二个模板类型参数来使用其他类型的容器：
	//底层容器必须提供这些操作：front()、back()、push_back()、pop_front()、empty() 和 size()。
	std::queue<std::string, std::list<std::string>>words_;
}

/*
queue 和 stack 有一些成员函数相似，但在一些情况下，工作方式有些不同：
front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
push(const T& obj)：在 queue 的[尾部]添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
pop()：删除 queue 中的[第一个]元素。
size()：返回 queue 中元素的个数。
empty()：如果 queue 中没有元素的话，返回 true。
emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。
*/

//priority_queue 容器适配器定义了一个元素有序排列的队列。
//默认队列头部的元素优先级最高。
//因为它是一个队列，所以只能访问第一个元素，这也意味着优先级最高的元素总是第一个被处理。

//priority_queue 模板有 3 个参数，其中两个有默认的参数；
//第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言。
void init_c_priority_queue()
{
	//template <typename T, typename Container = std::vector<T>, typename Compare = std::less<T>> class priority_queue
	std::priority_queue<std::string> words_;//优先级队列
	std::string wrds[] { "one", "two", "three", "four"};
	std::priority_queue<std::string> words{ std::begin(wrds), std::end(wrds) }; // "two" "three" "one" "four" 
	std::priority_queue<std::string> copy_words{ words }; // copy of words 
	//反向：
	std::string wrds__[] {"one", "two", "three", "four"};
	std::priority_queue<string, vector<string>, greater<string>> words1{ std::begin(wrds), std::end(wrds) }; //"four" "one" "three" "two"

	//可以生成 vector 或 deque 容器，然后用它们来初始化 priority_queue。下面展示了如何以 vector 的元素作为初始值来生成 priority_queue 对象：
	std::vector<int> values{ 21, 22, 12, 3, 24, 54, 56 };
	std::priority_queue<int> numbers{ std::less<int>(), values };

}

/*
对 priority_queue 进行操作有一些限制：
push(const T& obj)：将obj的副本放到容器的适当位置，这通常会包含一个排序操作。
push(T&& obj)：将obj放到容器的适当位置，这通常会包含一个排序操作。
emplace(T constructor a rgs...)：通过调用传入参数的构造函数，在序列的适当位置构造一个T对象。为了维持优先顺序，通常需要一个排序操作。
top()：返回优先级队列中第一个元素的引用。
pop()：移除第一个元素。
size()：返回队列中元素的个数。
empty()：如果队列为空的话，返回true。
swap(priority_queue<T>& other)：和参数的元素进行交换，所包含对象的类型必须相同。
*/