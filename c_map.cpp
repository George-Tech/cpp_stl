#include "cpp_base_head.h"
/*
map �����ǹ���������һ�֡��ڹ��������У������λ��ȡ���ں��������ļ���ֵ��
�������ǻ�������(int string ...)��Ҳ�����������͡�
*/
//------
/*
map ������ 4 �֣�ÿһ�ֶ�������ģ�嶨��ġ�
�������͵� map ��������Ķ��Ǽ�ֵ�����͵�Ԫ�ء�
map ������Ԫ���� pair<const K��T> ���͵Ķ������ֶ����װ��һ�� T ���͵Ķ����һ����������� K ���͵ļ���
pair Ԫ���еļ��� const����Ϊ�޸ļ�������������Ԫ�ص�˳��
ÿ�� map ������ģ�嶼�в�ͬ�����ԣ�
1.map<K��T>������������� pair<const K��T> ���͵�Ԫ�ء�
	pair<const K,T> ��װ��һ�Լ����󣬼��������� K������������� T��
	ÿ��������Ψһ�ģ����Բ��������ظ��ļ��������Ա����ظ��Ķ���ֻҪ���ǵļ���ͬ��
	map �����е�Ԫ�ض�������ģ�Ԫ���������ڵ�˳����ͨ���Ƚϼ�ȷ���ġ�
	Ĭ��ʹ�� less<K> ����Ƚϡ�
2.multimap<K��T> ������ map<K��T> �������ƣ�Ҳ���Ԫ������
	���ļ������ǿɱȽϵģ�Ԫ�ص�˳����ͨ���Ƚϼ�ȷ���ġ�
	�� map<K��T> ��ͬ���ǣ�multimap<K��T> ����ʹ���ظ��ļ���
	��ˣ�һ�� multimap �������Ա�����������ͬ��ֵ�� <const K,T> Ԫ�ء�
3.unordered_map<K��T> �� pair< const K��T>Ԫ�ص�˳�򲢲���ֱ���ɼ�ֵȷ���ģ������ɼ�ֵ�Ĺ�ϣֵ�����ġ�
��ϣֵ����һ��������ϣ�Ĺ������ɵ����������º���������һ�㡣unordered_map<K��T>���������ظ��ļ���
4.unordered_multimap<K,T> Ҳ����ͨ����ֵ���ɵĹ�ϣֵ��ȷ�������λ�ã������������ظ��ļ���
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
	map<int, string> nickname0;//int �Ǽ������ͣ� string�Ƕ���
	//map <K,T>�У�ÿ��Ԫ�ض���ͬ�·�װ�˶��������pair<const K, T>
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
	pair<map<int, string>::iterator, bool> ret = nickname.insert(tmp);//����һ���������Ͳ�ż ��pair
	//д auto =  nickname.insert(make_pair(3, "three")); Ҳ��ok
	cout << "insert pair : " << ret.first->first << ", " << ret.first->second << endl;
	cout << "insert success : " << ret.second << endl;
	//�޸ļ� ��Ӧ�� �洢ֵ
	ret.first->second = "threeee";
	cout << "nickname :" << endl;
	map_print(nickname);

}

void visit_c_map()
{
	//��iter ���� ����static void map_print(map<int,string> readlog) 
	//.at(��) ���� [��]����
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