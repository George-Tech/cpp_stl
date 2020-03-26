#include "cpp_base_head.h"
/*
list<T> ����ģ�嶨���� list ͷ�ļ��У��� T ���Ͷ����˫������

list ��������һЩ vector �� deque ���������߱������ƣ�
�������ڳ���ʱ���ڣ���������֪���κ�λ�ò����ɾ��Ԫ�ء�
��������ʹ�� list������ʹ�� vector �� deque ��������Ҫԭ��

list ��ȱ�����޷�ͨ��λ����ֱ�ӷ��������е�Ԫ�أ�Ҳ����˵����������Ԫ�ء�
Ϊ�˷��� list �ڲ���һ��Ԫ�أ�����һ��һ���ر���Ԫ�أ�
ͨ���ӵ�һ��Ԫ�ػ����һ��Ԫ�ؿ�ʼ������
*/

void init_c_list()
{
	list<std::string> words;
	list<std::string> sayings{ 20 };
	list<double> values(5, 3.14159265);//һ������ 50 �� double ��ֵ���б�����ÿһ��ֵ������ �С�
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
	//clear erase ��vectorһ��
	data.erase(iter);
	//remove  numbers �г��ֵ�����ֵ���� 99 ��Ԫ�ء�
	data.remove(99);
	//unique() �ǳ�����˼���������Ƴ��������ظ�Ԫ�أ�ֻ�������еĵ�һ����
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
	//list �ĳ�Ա���� merge() ����һ��������ͬ����Ԫ�ص� list ������Ϊ������
	//���������е�Ԫ�ض����������򡣲��� list �����е�Ԫ�ػᱻ�ϲ�����ǰ�� list ������
	std::list<int> my_values{ 2, 4, 6, 14 };
	std::list<int> your_values{ -2, 1, 7, 10 };
	my_values.merge(your_values);//my_values contains: -2 1 2 4 6 7 10 14
	your_values.empty(); // Returns true
	//Ԫ�ش� your_values ת�Ƶ� my_values��
	//��ˣ���ִ�������������your_values �о�û��Ԫ���ˡ�
	//�ı�ÿ�� list �ڵ��ָ�룬���ʵ���λ�ý����Ǻ͵�ǰ������Ԫ������������
	//������ʵ����Ԫ�ص�ת�ơ�list �ڵ����ڴ��е�λ�ò���ı䣻ֻ���������ǵ�ָ����ˡ�
	//�ںϲ��Ĺ����У����������е�Ԫ��ʹ�� operator()() ���бȽϡ�
}

void visit_c_list()
{
	//begin() �� end() �ֱ𷵻ص���ָ���һ�������һ��Ԫ����һ��λ�õ�˫���������
	//rbegin() �� rend() �������ص�˫��������������������������Ԫ��
	std::list<int> my_values{ 0,1,2,3,4,5};
	list<int>::iterator iter1 = ++my_values.begin();
	list<int>::iterator iter2 = --my_values.end();
	cout << *iter1 << " " << *iter2 << endl;	
	for (auto iter3 = my_values.rbegin(); iter3 != my_values.rend(); iter3++)
		cout << *iter3 << " ";
	int a = 0;

}


/*
forward_list �����Ե��������ʽ�洢Ԫ�ء�
forward_list ��ģ�嶨����ͷ�ļ� forward_list �С�
fdrward_list �� list ����Ҫ��������:�����ܷ������Ԫ�أ�ֻ�ܴ�ͷ��β������
*/
void c_forwad_list()
{
	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	auto count = std::distance(std::begin(my_words), std::end(my_words));
	// Result is 3
	std::forward_list<int> data{ 10, 21, 43, 87, 175, 351 };
	auto iter = std::begin(data);
	size_t n{ 3 };
	std::advance(iter, n);//distance() �ĵ�һ��������һ����ʼ���������ڶ���������һ������������������ָ����Ԫ�ط�Χ������Ҫ��ǰ��������ƶ����λ��ʱ
	std::cout << "The " << n + 1 << "th element is n "<< *iter << std::endl;
	// Outputs 87
	//forward_list ������Ա����splice_after() �� insert_after()��
	//�������� list ������ splice() �� insert()��
	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	std::forward_list<std::string> your_words{ "seven", "four", "nine" };
	my_words.splice_after(my_words.before_begin(), your_words, ++std::begin(your_words));
	//forward_list �� list �������г�Ա���� sort() �� merge()������Ҳ���� remove()��remove_if() ��unique()��������Щ�������÷����� list ��ͬ
}