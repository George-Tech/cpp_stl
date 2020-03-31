#include "cpp_base_head.h"
/*
map 容器是关联容器的一种。在关联容器中，对象的位置取决于和它关联的键的值。
键可以是基本类型(int string ...)，也可以是类类型。
*/
//------
/*
map 容器有 4 种，每一种都是由类模板定义的。
所有类型的 map 容器保存的都是键值对类型的元素。
map 容器的元素是 pair<const K，T> 类型的对象，这种对象封装了一个 T 类型的对象和一个与其关联的 K 类型的键。
pair 元素中的键是 const，因为修改键会扰乱容器中元素的顺序。
每种 map 容器的模板都有不同的特性：
1.map<K，T>容器，保存的是 pair<const K，T> 类型的元素。
	pair<const K,T> 封装了一对键对象，键的类型是 K，对象的类型是 T。
	每个键都是唯一的，所以不允许有重复的键；但可以保存重复的对象，只要它们的键不同。
	map 容器中的元素都是有序的，元素在容器内的顺序是通过比较键确定的。
	默认使用 less<K> 对象比较。
2.multimap<K，T> 容器和 map<K，T> 容器类似，也会对元素排序。
	它的键必须是可比较的，元素的顺序是通过比较键确定的。
	和 map<K，T> 不同的是，multimap<K，T> 允许使用重复的键。
	因此，一个 multimap 容器可以保存多个具有相同键值的 <const K,T> 元素。
3.unordered_map<K，T> 中 pair< const K，T>元素的顺序并不是直接由键值确定的，而是由键值的哈希值决定的。
哈希值是由一个叫作哈希的过程生成的整数，本章后面会解释这一点。unordered_map<K，T>不允许有重复的键。
4.unordered_multimap<K,T> 也可以通过键值生成的哈希值来确定对象的位置，但它允许有重复的键。
*/
static void map_print(map<int,string> readlog) 
{
	for (auto iter = readlog.begin(); iter != readlog.end(); iter++) {
		cout << "(" << iter->first << ", " << iter->second << ") ";
	}
	cout << endl;
}
void init_c_map()
{
	map<int, string> nickname0;//int 是键的类型， string是对象
	//map <K,T>中，每个元素都是同事封装了对象及其键的pair<const K, T>
	map<int, string> nickname1{ { 5, "five" }, { 2, "two" }, { 1, "one" } };
	map<int, string> nickname2{ make_pair(4, "four"), make_pair(0, "zero") };
	map<int, string> nickname3{ nickname2 };
	map<int, string> nickname4{ ++nickname3.begin(), nickname3.end() };
	cout << "nickname0 :" << endl;
	map_print(nickname0);
	cout << "nickname1 :" << endl;
	map_print(nickname1);
	cout << "nickname2 :" << endl;
	map_print(nickname2);
	cout << "nickname3 :" << endl;
	map_print(nickname3);
	cout << "nickname4 :" << endl;
	map_print(nickname4);
}

void insert_c_map()
{
	map<int, string> nickname{ { 5, "five" }, { 2, "two" }, { 1, "one" } };
	pair<int, string> tmp = make_pair(3, "three");
	pair<map<int, string>::iterator, bool> ret = nickname.insert(tmp);//返回一个迭代器和布偶 的pair
	//写 auto =  nickname.insert(make_pair(3, "three")); 也是ok
	cout << "insert pair : " << ret.first->first << ", " << ret.first->second << endl;
	cout << "insert success : " << ret.second << endl;
	//修改键 对应的 存储值
	ret.first->second = "threeee";
	cout << "nickname :" << endl;
	map_print(nickname);

}

void visit_c_map()
{
	//用iter 遍历 见：static void map_print(map<int,string> readlog) 
	//.at(键) 访问 [键]访问
	map<int, string> nickname{ { 5, "five" }, { 2, "two" }, { 1, "one" } };
	cout << ".at(5) = " << nickname.at(5) << endl;
	cout << "[5] = " << nickname[5] << endl;
	auto itr = nickname.find(5);
	cout << ".find(5).second = " << itr->second << endl;

	nickname.erase(2);
	map_print(nickname);
}

void opt_c_pair()
{
	pair<int, string> my_pair{1,"one"};
	auto your_pair = make_pair(2, "two");
	cout << my_pair.first << ", " << my_pair.second << endl;
	cout << your_pair.first << ", " << your_pair.second << endl;
}