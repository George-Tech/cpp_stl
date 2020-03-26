#include "cpp_base_head.h"

/*
deque<T>��һ�������� deque ͷ�ļ��е�����ģ�壬�������ɰ��� T ����Ԫ�ص�������
����˫�˶��е���ʽ��֯Ԫ�ء�
������������ͷ����β����Ч����ӻ�ɾ����������������� vector ���������ơ�
��Ӧ�ð��������ȳ���������ʱ����Ӧ��ʹ�� deque ������
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
	//�±����
	std::cout << words.at(2) << std::endl; // Output the third element in words
	//deque ��Ա���� front() �� back() ���÷�Ҳ�� vector ��ͬ
	std::cout << "front = " << words.front() << " back = " << words.back() << std::endl;
	//push_bck & pop_back
	words.push_back("newtail");
	words.pop_back();
	//push_front & pop_front
	words.push_front("newhead");
	words.pop_front();
	//emplace_front()
	// insert() ����Ҳͬ�������� deque ������
	//�� deque ������λ�ò���һ��Ԫ�ػ������еĵ�����ȫ��ʧЧ�������Ҫ�����������ǡ�
	//deque �ĳ�Ա���� erase() Ҳ�� vector ����ͬ�����ĳ�Ա���� clear() �����Ƴ�һЩԪ�ء�
}