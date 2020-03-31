#include "cpp_base_head.h"
//����queue ֻ�ܷ��� queue<T> �����������ĵ�һ�������һ��Ԫ�ء�
//ֻ����������ĩβ�����Ԫ�أ�ֻ�ܴ�ͷ���Ƴ�Ԫ�ء�

void init_c_queue() //queue �����ɷ�ʽ�� stack ��ͬ
{
	std::queue<std::string> words;
	std::queue<std::string> copy_words{ words }; // A duplicate of words
	//stack<T>��queue<T> �����������඼Ĭ�Ϸ�װ��һ�� deque<T> ������Ҳ����ͨ��ָ���ڶ���ģ�����Ͳ�����ʹ���������͵�������
	//�ײ����������ṩ��Щ������front()��back()��push_back()��pop_front()��empty() �� size()��
	std::queue<std::string, std::list<std::string>>words_;
}

/*
queue �� stack ��һЩ��Ա�������ƣ�����һЩ����£�������ʽ��Щ��ͬ��
front()������ queue �е�һ��Ԫ�ص����á���� queue �ǳ������ͷ���һ�������ã���� queue Ϊ�գ�����ֵ��δ����ġ�
back()������ queue �����һ��Ԫ�ص����á���� queue �ǳ������ͷ���һ�������ã���� queue Ϊ�գ�����ֵ��δ����ġ�
push(const T& obj)���� queue ��[β��]���һ��Ԫ�صĸ���������ͨ�����õײ������ĳ�Ա���� push_back() ����ɵġ�
push(T&& obj)�����ƶ��ķ�ʽ�� queue ��β�����Ԫ�ء�����ͨ�����õײ������ľ�����ֵ���ò����ĳ�Ա���� push_back() ����ɵġ�
pop()��ɾ�� queue �е�[��һ��]Ԫ�ء�
size()������ queue ��Ԫ�صĸ�����
empty()����� queue ��û��Ԫ�صĻ������� true��
emplace()���ô��� emplace() �Ĳ������� T �Ĺ��캯������ queue ��β�����ɶ���
swap(queue<T> &other_q)������ǰ queue �е�Ԫ�غͲ��� queue �е�Ԫ�ؽ�����������Ҫ������ͬ���͵�Ԫ�ء�Ҳ���Ե���ȫ�ֺ���ģ�� swap() �����ͬ���Ĳ�����
*/

//priority_queue ����������������һ��Ԫ���������еĶ��С�
//Ĭ�϶���ͷ����Ԫ�����ȼ���ߡ�
//��Ϊ����һ�����У�����ֻ�ܷ��ʵ�һ��Ԫ�أ���Ҳ��ζ�����ȼ���ߵ�Ԫ�����ǵ�һ��������

//priority_queue ģ���� 3 ������������������Ĭ�ϵĲ�����
//��һ�������Ǵ洢��������ͣ��ڶ��������Ǵ洢Ԫ�صĵײ������������������Ǻ���������������һ����������Ԫ��˳��Ķ��ԡ�
void init_c_priority_queue()
{
	//template <typename T, typename Container = std::vector<T>, typename Compare = std::less<T>> class priority_queue
	std::priority_queue<std::string> words_;//���ȼ�����
	std::string wrds[] { "one", "two", "three", "four"};
	std::priority_queue<std::string> words{ std::begin(wrds), std::end(wrds) }; // "two" "three" "one" "four" 
	std::priority_queue<std::string> copy_words{ words }; // copy of words 
	//����
	std::string wrds__[] {"one", "two", "three", "four"};
	std::priority_queue<string, vector<string>, greater<string>> words1{ std::begin(wrds), std::end(wrds) }; //"four" "one" "three" "two"

	//�������� vector �� deque ������Ȼ������������ʼ�� priority_queue������չʾ������� vector ��Ԫ����Ϊ��ʼֵ������ priority_queue ����
	std::vector<int> values{ 21, 22, 12, 3, 24, 54, 56 };
	std::priority_queue<int> numbers{ std::less<int>(), values };

}

/*
�� priority_queue ���в�����һЩ���ƣ�
push(const T& obj)����obj�ĸ����ŵ��������ʵ�λ�ã���ͨ�������һ�����������
push(T&& obj)����obj�ŵ��������ʵ�λ�ã���ͨ�������һ�����������
emplace(T constructor a rgs...)��ͨ�����ô�������Ĺ��캯���������е��ʵ�λ�ù���һ��T����Ϊ��ά������˳��ͨ����Ҫһ�����������
top()���������ȼ������е�һ��Ԫ�ص����á�
pop()���Ƴ���һ��Ԫ�ء�
size()�����ض�����Ԫ�صĸ�����
empty()���������Ϊ�յĻ�������true��
swap(priority_queue<T>& other)���Ͳ�����Ԫ�ؽ��н�������������������ͱ�����ͬ��
*/