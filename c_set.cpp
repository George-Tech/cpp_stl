#include "cpp_base_head.h"

/*
���� set ������ģ�����£�
1.set<T> 
	�������� T ���͵Ķ��󣬶��ұ���Ķ�����Ψһ�ġ�
	���б����Ԫ��������ģ�Ĭ���� less<T> ����Ƚϡ�
	��������ȡ���������ж϶����Ƿ���ͬ��
2.multiSet<T> ����
	�� set<T> �������� T ���Ͷ���ķ�ʽ��ͬ���������Ա����ظ��Ķ���
3.unorderd_set<T> 
	�������� T ���͵Ķ��󣬶��Ҷ�����Ψһ�ġ�
	Ԫ���������е�λ����Ԫ�صĹ�ϣֵ������
	Ĭ���� equal_to<T> �������ж�Ԫ���Ƿ���ȡ�
4.unordered_multiset<T>
	�������� T ���Ͷ���ķ�ʽ�� unorderd_set<T> ��ͬ���������Ա����ظ��Ķ���
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
	//���뵥��Ԫ�ػ᷵��һ�� pair<iterator��bool> ����
	std::set<string, std::greater<string>> words{ "one", "two", "three" };
	auto pr1 = words.insert("four");
	auto pr2 = words.insert(pr1.first, "seven");
	string wrds[] {"eight", "nine", "ten"};
	words.insert(std::begin(wrds), std::end(wrds));

	//��Ա���� clear() ��ɾ�� set ������Ԫ�ء�
	//��Ա���� erase() ��ɾ��������ָ��λ�õ�Ԫ�ػ������ƥ���Ԫ��
	std::set<int> numbers{ 2, 4, 6, 8, 10, 12, 14 };
	auto iter = numbers.erase(++std::begin(numbers));
	auto n = numbers.erase(12);
	n = numbers.erase(13);
	set_print(numbers);
	numbers.clear();

	//set �ĳ�Ա���� find() �᷵��һ���Ͳ���ƥ���Ԫ�صĵ���������������� set �У��᷵��һ������������
	std::set<string> words_{ "one", "two", "three", "four", "five" };
	auto iter_ = words_.find("one"); // iter points to "one"
	iter_ = words_.find(string{ "two" });   // iter points to "two"
	iter_ = words_.find("six");   // iter is std:: end (words)
}