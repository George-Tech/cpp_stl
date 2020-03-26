#include "cpp_base_head.h"

void init_c_string() //����
{
	string str("12345678");
	char ch[] = "abcdefgh";
	string a; //����һ�����ַ���
	string str_1(str); //���캯����ȫ������ -> 123456
	string str_2(str, 2, 5); //���캯�������ַ���str�ĵ�2��Ԫ�ؿ�ʼ������5��Ԫ�أ���ֵ��str_2 -> 34567
	string str_3(ch, 5); //���ַ���ch��ǰ5��Ԫ�ظ�ֵ��str_3 -> abcde
	string str_4(5, 'X'); //�� 5 �� 'X' ��ɵ��ַ��� "XXXXX" ��ֵ�� str_4   ->  XXXXX
	string str_5(str.begin(), str.end()); //�����ַ��� str ������Ԫ�أ�����ֵ�� str_5 -> 12345678
	cout << str << endl;
	cout << a << endl;
	cout << str_1 << endl;
	cout << str_2 << endl;
	cout << str_3 << endl;
	cout << str_4 << endl;
	cout << str_5 << endl;
}

void visit_c_string() //���ʡ��޸�
{
	string str("abcdefgh");
	int len = str.length();
	char head = str[0];//�±����
	char end = str.at(len-1);
	cout << len << endl;
	cout << head << endl;
	cout << end << endl;

	//assgin ��ֵ----
	cout << "---assign test---" << endl;
	string str1("123456");
	string str2("abcdefghijklmn");
	str.assign(str1);//123456
	cout << str << endl;
	str.assign(str1, 3, 3);//456
	cout << str << endl;
	str.assign(5, 'X');//xxxxx
	cout << str << endl;
	string::iterator itB;
	string::iterator itE;
	itB = str1.begin();
	itE = str1.end();
	str.assign(itB, (--itE));//12345
	cout << str << endl;
	str = str1;//123456
	cout << str << endl;

	//erase ɾ��---- str.erase (str* begin(), str.end());  str.erase (n);(����ǰn��)
	cout << "---erase test---" << endl;
	str.erase(3);//123
	cout << str << endl;
	str.erase(str.begin(), --str.end());
	cout << ":" << str << ":" << endl;//:3:

	//swap �Ի�
	cout << "---swap test---" << endl;
	str.swap(str2);
	cout << str << endl;

	//insert 
	cout << "---insert test---" << endl;
	string A("012345");
	string B("HHH");
	B.insert(2, A);//��A���뵽B�ĵ�1��λ��
	cout << B << endl;
	B = "HH";
	B.insert(1, "012345", 3); //��012345��3������ ���뵽B��1λ��
	cout << "����: " << B << endl;
	B = "HH";
	B.insert(1, A, 2, 2);//��A�ĵ�2��λ�ú��2������ ���뵽B��1λ��
	cout << "����: " << B << endl;
	B = "HH";
	string::iterator itF = A.begin();
	string::iterator itG = A.end();
	B.insert(++B.begin(), ++itF, --itG);
	cout << "����: " << B << endl;

	//append
	cout << "---swap test---" << endl;
	A = "ello";	B = "H";
	B.append(A);
	cout << "B.append(A); ׷�ӣ�" << B << endl;
	B = "H";
	cout << "A = " << A << ", B= " << B << endl;
	B.append("12345", 2);
	cout << "B.append(12345, 2); ׷�ӣ�" << B << endl;
	A = "ello";	B = "H";
	B.append("12345", 2, 3);
	cout << "B.append(12345, 2, 3) ׷�ӣ�" << B << endl;
	A = "ello";	B = "H";
	B.append(10, 'a');
	cout << "B.append(10, 'a') ׷��:" << B << endl;
	A = "ello";	B = "H";
	B.append(A.begin(), A.end());
	cout << "B.append(A.begin(), A.end()) ׷��:" << B << endl;
}

static void TrueOrFalse(int x)
{
	cout << (x ? "True" : "False") << endl;
}


void comp_c_string() //�Ƚ�
{
	string A("aBcdef");
	string B("AbcdEf");
	string C("123456");
	string D("123dfg");
	//�����Ǹ��ֱȽϷ���
	//������Ƚϵ�������ֵ��ͬ���������� 0�����ַ��� S ���ֵ�˳��Ҫ���� S2���򷵻ظ�ֵ����֮���򷵻���ֵ
	int m = A.compare(B); //������A��B�ıȽ�
	int n = A.compare(1, 5, B, 4, 2); //"Bcdef"��"AbcdEf"�Ƚ�
	int p = A.compare(1, 5, B, 4, 2); //"Bcdef"��"Ef"�Ƚ�
	int q = C.compare(0, 3, D, 0, 3); //"123"��"123"�Ƚ�
	cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl; //m = 1, n = -1, p = -1, q = 0

	string S1 = "DEF";
	string CP1 = "ABC";
	string CP2 = "DEF";
	string CP3 = "DEFG";
	string CP4 = "def";
	cout << "S1= " << S1 << endl;
	cout << "CP1 = " << CP1 << endl;
	cout << "CP2 = " << CP2 << endl;
	cout << "CP3 = " << CP3 << endl;
	cout << "CP4 = " << CP4 << endl;
	cout << "S1 <= CP1 returned ";
	TrueOrFalse(S1 <= CP1);
	cout << "S1 <= CP2 returned ";
	TrueOrFalse(S1 <= CP2);
	cout << "S1 <= CP3 returned ";
	TrueOrFalse(S1 <= CP3);
	cout << "CP1 <= S1 returned ";
	TrueOrFalse(CP1 <= S1);
	cout << "CP2 <= S1 returned ";
	TrueOrFalse(CP2 <= S1);
	cout << "CP4 <= S1 returned ";
	TrueOrFalse(CP4 <= S1);
}

void find_c_string() //����
{
	//replace
	string s1 = "abbba";
	s1.replace(s1.find("b"), 3, "c");
	cout << "replace : " << s1 << endl;
	//substr
	s1 = "012345";
	string substr1 = s1.substr(1,3);
	cout << "substr : " << substr1 << endl;
	//find
	string str("0123456789");
	string str_sub("456");
	int m = str.find('3', 1);
	int rm = str.rfind('3', 6);
	cout << "Example - find() : The position (forward) of '3' is: " << (int)m << endl;
	cout << "Example - rfind(): The position (reverse) of '3' is: " << (int)rm << endl;
	m = str.find(str_sub, 1);
	rm = str.rfind(str_sub, 6);
	cout << "Example - find() : The position (forward) of 'str_sub' is: " << (int)m << endl;
	cout << "Example - rfind(): The position (reverse) of 'str_sub' is: " << (int)rm << endl;
}