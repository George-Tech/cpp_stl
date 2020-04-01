#include "cpp_base_head.h"

/*
定义 set 容器的模板如下：
1.set<T> 
	容器保存 T 类型的对象，而且保存的对象是唯一的。
	其中保存的元素是有序的，默认用 less<T> 对象比较。
	可以用相等、不相等来判断对象是否相同。
2.multiSet<T> 容器
	和 set<T> 容器保存 T 类型对象的方式相同，但它可以保存重复的对象。
3.unorderd_set<T> 
	容器保存 T 类型的对象，而且对象是唯一的。
	元素在容器中的位置由元素的哈希值决定。
	默认用 equal_to<T> 对象来判断元素是否相等。
4.unordered_multiset<T>
	容器保存 T 类型对象的方式和 unorderd_set<T> 相同，但它可以保存重复的对象。
*/
static void set_print(set<int> readlog)
{
	for (auto iter = readlog.begin(); iter != readlog.end(); iter++) {
		cout << *iter << ", " ;
	}
	cout << endl;
}

void init_c_set()
{
	set<int> numbers{ 8, 7, 6, 5, 4, 3, 2, 1 };
	set<int, std::greater<int>> numbers1{ 8, 1, 2, 3, 4, 5, 6, 7 };
	std::set<int> numbers2{ std::begin(numbers1), std::end(numbers1) };
	std::set<int, std::greater<int>> numbers3{ ++std::begin(numbers2), std::end(numbers2) };
	set_print(numbers);
	for (auto iter = numbers1.begin(); iter != numbers1.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl;
}

void put_c_set()
{
	//插入单个元素会返回一个 pair<iterator，bool> 对象
	std::set<string, std::greater<string>> words{ "one", "two", "three" };
	auto pr1 = words.insert("four");
	auto pr2 = words.insert(pr1.first, "seven");
	string wrds[] {"eight", "nine", "ten"};
	words.insert(std::begin(wrds), std::end(wrds));

	//成员函数 clear() 会删除 set 的所有元素。
	//成员函数 erase() 会删除迭代器指定位置的元素或与对象匹配的元素
	std::set<int> numbers{ 2, 4, 6, 8, 10, 12, 14 };
	auto iter = numbers.erase(++std::begin(numbers));
	auto n = numbers.erase(12);
	n = numbers.erase(13);
	set_print(numbers);
	numbers.clear();

	//set 的成员函数 find() 会返回一个和参数匹配的元素的迭代器。如果对象不在 set 中，会返回一个结束迭代器
	std::set<string> words_{ "one", "two", "three", "four", "five" };
	auto iter_ = words_.find("one"); // iter points to "one"
	iter_ = words_.find(string{ "two" });   // iter points to "two"
	iter_ = words_.find("six");   // iter is std:: end (words)
}