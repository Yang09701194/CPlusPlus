// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Sales_item.h"
#include <vector>


using namespace std;
using std::vector;



int main() {


	int pause;
	cin >> pause;

}



//96 vector �N�� C# List


//95
	//const string hexdigits = "0123456789ABCDEF";  // possible hex digits

	//cout << "Enter a series of numbers between 0 and 15"
	//     << " separated by spaces.  Hit ENTER when finished: " 
	//     << endl;
	//string result;        // will hold the resulting hexify'd string

	//string::size_type n;  // hold numbers from the input
	//while (cin >> n)
	//	if (n < hexdigits.size())    // ignore invalid input
	//		result += hexdigits[n];  // fetch the indicated hex digit

	//cout << "Your hex number is: " << result << endl;

	//return 0;

//94
//if (!s.empty())
//	cout << s[0] << endl;
//if (!s.empty())
//	s[0] = toupper(s[0]);
//
//// convert first word in s to uppercase
//s = orig;  // restore s to original case
//decltype(s.size()) index = 0;
//
//// process characters in s until we run out of characters 
//// or we hit a whitespace
//while (index != s.size() && !isspace(s[index])) {
//
//	// s[index] returns a reference so we can change 
//	// the underlying character
//	s[index] = toupper(s[index]);
//
//	// increment the index to look at the next character 
//	// on the next iteration
//	++index;
//}


//93  
//�@�ӰѦҤ��L�N�O���@�Ӫ���t�@�ӦW��
//�n���ܦr���̪���  �n�ΰѦ�
//for (auto &c : str)  
//	&c toupper(c); //�Lstring �̪��C��char

//s[0]  �Ĥ@�Ӧr��  �N�@��array����


////91
//string str("abc");  
//for (auto c : str)  �N foreach
//	cout << c << endl; //�Lstring �̪��C��char


//string s("Hello World!!!");
//// punct_cnt has the same type that s.size returns
//decltype(s.size()) punct_cnt = 0;
//
//// count the number of punctuation characters in s
//for (auto c : s)         // for every char in s
//if (ispunct(c))      // if the character is punctuation
//	++punct_cnt;     // increment the punctuation counter
//
//cout << punct_cnt
//	<< " punctuation characters in " << s << endl;
//
//isalnum(c)
//isalpha(c)
//iscntrl
//isdigit
//islower
//isprint
//ispunct
//isspace
//isupper
//isxdigit
//tolower
//toupper


//90
//C++ �z
//���M���� string s = "a" + "b";
//�¦r��۾F�ۥ[�N��  �@�w�n�ܤ֤@��O�Ӧr���ܼ�  �t


////89
//�u�r��p����r��
//�r���i�H��r��ۥ[
//string s3 = s1 + "," + s2 + '\n';


//88

//86
//�r��ާ@
//getline(istream, s)  Ū�@��    �J��newline��
//s.empty()   �O�_��
//s.size() ����   �^�ǭȬO string::size_type  �O�@��unsign�S�ʥB�i�p�ƥ���r����ת����O  �i��auto ��decltype�ӱ����r�����
//s[i]

//string > < �Φr���


//cout << "a" << endl;
//cout << "b" << endl;//����
//
//
//Ū�����ƥئr��  ����eof �εL�Ŀ�J
//while (cin >> word)
//{
//	cout << word << endl;
//}

//while (getline(cin		, line))
//{
//	cout << word << endl;
//}


//84
//string s1;
//string s2 = s1;//�Ŧr��
//string s3 = "abc";
//string s4(10, 'c'); // 10��c
//string s6("afg");
//string s6(s3);
//
//string �i�Φb cin cout




////p82
//string ���ץi�ܪ��@�Ӧr���ǦC
//vector ���ץi�ܪ�����ǦC

////���رi��  �����MC#���P  ���M��ĳ�@�ӭӤޤJ  C#�g����[�N���D�ڥ��S���n   �h�@���B�~���O�u  �X�d�檺�{���X�i��n�[�ӴX�ʦ� �Pı���I��smart
//using std::cin;
//using std::cout;
//using std::endl;

//���ڳ����o��  ������using namespace

//�S��  h�ɤ��ӥ]�tusing  �]��h�|�Q�ޥ�   �e�����L�L�J���{����using�Ĭ�



////p77
//�@��header����Q�ޤJ�h��  �ҥH�i�H��preprocessor(�e�m�B�z��)  �Ӱ���w���ޤJ
//
//_H�N�O�Ih �e���P�ɦW     �o�N�sheader guard  ���j�g
//#ifndef PCH_H
//#define PCH_H
//
//// content here
//
//#endif //PCH_H

//#include �b preprocessor�B�z�|���N�����Ӽ��Y�ɪ����e  �۷��ֶi��

//p76
//���ɤ��u�঳�@�����O�w�q   �h���ɮ�  �C�ɪ����O�w�q�ݬۦP
//�w�q�b���Y�N�i�ޥΦ@��   h�ɦW�� �����O�W�ٲߺD�ۦP


//p75  main
////Sales_data  �p�G�w�q�b�P���ɮ�  �n��bmain�e��
////�ҥH�g�bh��  �ٯu���i�H
//Sales_data d1, d2;
//double price = 0;
//cin >> d1.bookNo >> d1.units_sold >> price;
//d1.revenue = d1.units_sold * price;
////d2�P�z
//
//int pause;
//cin >> pause;


////p71
////�a���A����decltype�û��O �Ѧҫ��O
//decltype((i)) d; // d�O int&�B�n�Q��l��

//p70
//int main()
//{
//	const int i = 42;
//	auto j = i;
//	const auto &k = i;
//	auto *p = &i;
//	const auto j2 = i, &k2 = i;
//
//	// print i means int, and PKi means pointer to const int.
//	std::cout << "j is " << typeid(j).name()
//		<< "\nk is " << typeid(k).name()
//		<< "\np is " << typeid(p).name()
//		<< "\nj2 is " << typeid(j2).name()
//		<< "\nk2 is " << typeid(k2).name()
//		<< std::endl;
//
//	return 0;
//}
//

//decltype  �^�����O  ������
//decltype(f()) sum = 3;


//p69
//auto �ڬݴN�O C#��var
//int i = 0;
//const int ci = i, &crr = i;
//auto &g = ci;  
//auto &h = 42; //  ���i�Ѧ�  ��  �򥻫��O + �i��`�ƫ��O   ( �r����  p66
//const auto &j = 42;// const �Ѧ� �iô�`��   �r����

//p67
//// type alias
//typedef double wages;//wages�Odouble���P�q��
//typedef wages base, *p;//base �Odouble "     p�Odouble*���P�q��
//typedef double wages;
//
////alias declaration  ���O�O�W
//using SI = Sales_item;
//
//typedef char *pstring; // pstring�Ochar*����
//const pstring cstr = 0; // char *  ���Vchar�� �`�ƫ���
//const pstring *ps; // ���Vchar* �� ����

//p66
//�`�ƹB�⦡  �Φb��n�X�h�I�s�������Ҩӷ��O�`��
//constexpr int mf = 20;
//constexpr int mf = size();//���i�ण�O  �i�z�L���g�k�ˬd


////p63
//const����  �X�O�e��  ���V����}������
//int a = 0;
//int *const c = &a;//�û����Va
//const int a = 0;
//const int *const c = &a;//��W�����t���O �n���Vconst���� �̫e���N�n�[�Wconst   �U��a���Ȥ����� �W���i��



//p62
//�Ѧ�
//int i = 2;
//int &r = i;
//const int &r2 = i;//r2�Oconst�Ѧ� ���ள�ӧ��� i  ��r�i�H  �]�]��i�Dcnost
//r1 = 0;//i��0
//r2 = 0;//error

//����
//const int i = 2;
//int *r = &i; // error �Dconst
//const int *r2 = &i;//ok 
//*r2 = 0;//error const���i��


//p61
//�ѦҪ���^ �n�M ���V�����󫬧O�ۦP ����ҥ~
//1. ��Υi�Q�ഫ���ӰѦҫ��O ������B�⦡�Ӫ�l��const���Ѧ�
//2. const�i�H���V�Dconst   �Ϥ�����
//int = 42;
//const int &r1 = i;
//double d = 3.14
//const int &r = d;
//�ѦҦp�W   ���Х�P

//p60
//const���@�νd��O����ɮ�
//�ҥH�h���ɮ׳��n�Ψ�  �C���ɳ��n�gdefinition
//
//�p�G�n�@�ɩw�q�h�ɯ�ѷӦ@��
//.h
//extern const int bufSize;  //extern���O�ϰ��ܼ� �ӬO��L�ɮץi�ݨ�
//.cc
//extern const int bufSize = fcn();



////p59
//const �L�k�ܧ��ܼ�    �@�w�n��l����
//const int i = getVal() �� 42;



//p58   ����**  dereference�]�O**
//int ival = 1024;
//int *pi = &ival;   // pi points to an int
//int **ppi = &pi;   // ppi points to a pointer to an int
//cout << "The value of ival\n"
//<< "direct value: " << ival << "\n"
//<< "indirect value: " << *pi << "\n"
//<< "doubly indirect value: " << **ppi
//<< endl;
//
//int i = 2;
//int *p1 = &i;     // p1 points to i
//*p1 = *p1 * *p1;  // equivalent to i = i * i
//cout << "i  = " << i << endl;
//
//*p1 *= *p1;       // equivalent to i *= i
//cout << "i  = " << i << endl;
//
//return 0;

//int i = 42;
//int *p;// p�O��int���@�ӫ���
//int *&r = p;//r�O�����p���@�ӰѦ�   &r �i�H�ݦ��N�Or  ���N��  �Ѧҽ�Ȯɼg&r  ����ާ@���O��r  
////�ҥH���� int *r = p �]�N�Or�N�Op
//r = &i;// r = p = &i >> p = i����}
//*r = 0;// r = p = i����}  ��*���� = 0  >> i = 0;



//p57 
//int* p, p2  //p���� p2�u�Oint    *���|�۰ʮM��  ���}��

//p56
//void* �i�������������  �����O���� �ҥH�వ���ƫܤ�



//p55
//int v = 12;
//int *pi = 0;
//int *pi2 = &v;
//if(pi) // 0���� false
//if(pi2)// �D0���� true
//���Хi�� == ���


////p53
//int ival = 3;
//int *p = &ival;   �k���}  �ǵ��������
//cout << *p;   �o��*p�N�O���ȤF
//*p = 123; //= ival���
// p = 0; �������ܦ�null����   �S�����V���󪫥�

// int *p1 = nullptr; //�ŭȫ���  �S�����V���� = int *p = 0;


//p52   
//int v = 42;
//int *p = &v;


//p51������w�q�ѦҪ��Ѧ�   �]���ѦҤ��O����  �L�̨S����}
//��13�٦n���� ��* pointer?
//�ѦҤ�����V�¶q�����O��   �Ҧp�r��Ʀr
//���Ъ����O�n�������V���󪺫��O
//p51    &�]�i�Φb�ŧi   ����&���I�������o���󪺧O�W  �i�H�b��Lget set ���P��쥻���Ⱦާ@
//int i = 1024, i2 = 2;
//int &r = i, r2 = i2;

//p50
//int ival = 1024;
//int &refVal = ival;    int & �����Q�{�O�O�W
//refVal = 2;// = ival = 2
//int ii = refVal;



// p 49
//// Program for illustration purposes only: It is bad style for a function
//// to use a global variable and also define a local variable with the same name
//
//int reused = 42;  // reused has global scope
//
//int main()
//{
//	int unique = 0; // unique has block scope
//
//	// output #1: uses global reused; prints 42 0
//	std::cout << reused << " " << unique << std::endl;
//
//	int reused = 0; // new, local object named reused hides global reused
//
//	// output #2: uses local reused; prints 0 0
//	std::cout << reused << " " << unique << std::endl;
//
//	// output #3: explicitly requests the global reused; prints 42 0
//	std::cout << ::reused << " " << unique << std::endl;
//
//	return 0;
//}

//p45
// extern  https://www.youtube.com/watch?v=j9H3LN9_dJg


//p42
//string book("123-456");
//cout << book << endl;



//unsigned i = 1;
//cout << --i << endl;    0
//cout << --i << endl;    �ܤj���Ʀr
//cout << --i << endl;
//cin >> i;
//cout << i;
//
//cin >> i;


//�Q�T��
//
//int *p = (int*)malloc(100000000);//�t�m�O����  �u�@�޲z����ݨ��z�W
//
//int i;
//cin >> i;
//
//free(p);//����   �u�@��  �ܶW�C  �ߨ�ϬM
//cin >> i;
//



//��3
////http://www.cplusplus.com/reference/cstdio/fgets/
////fgets
////char * fgets(char * str, int num, FILE * stream);
////Get string from stream
////
////char *name;   /* name �|�����V���Ī��Ŷ� */
////printf("Your name, please: ");
////fgets(name, 20, stdin);   /* �z�T�w�n�g�J�������Ŷ��X�k��??? */
////printf("Hello, %s\n", name);
//

//�o�O�]�� gets �禡�L�k���D�r���}�C���j�p�A�ӬO�̿ഫ��Ÿ��� EOF �~�|������J�A�]�����i��޵o�w�İϷ��쪺�w�����D�A������i�H�ѦҡqWhy is the gets function so dangerous that it should not be used ? �r�C
//
//�q C11 ����Agets �w�g���A�O�зǨ禡���@�A�A�i�H�ϥ� fgets �Ө��N get�A�ϥήɥ������w�r���}�C�B�j�p�H�� stdin�G
//
//char str[20];
//
//puts("�п�J�r��G");
//gets(str);
//
//puts("��J���r�ꬰ�G");
//puts(str);
//
//return 0;

//��6
//int *p = (int*)malloc(sizeof(int));
//free(p);
//p = NULL;
//free(p);
//
//C++11��s�W�������(smart pointer) : unique_ptr
//��unique_ptr�ҫ���������ɡA�|�۰������O����A���ݭndelete�C
//
//�ҡG
//#include <memory>    // �tunique_ptr�����Y��
//std::unique_ptr<int> p1(new int(5));
//
//��10
//C :
//int *array = (int*)malloc(10000000 * sizeof(int));
//
//C++:
//std::vector<int> v;
//v.resize(10000000);
//
//�����G��ĳ�N�ϥΪŶ����j���ܼƥ�malloc / new�t�m�b heap �W�A�ѩ󦹮� stack
//�W�u�ݰt�m�@�� int* ���Ŷ�����bheap�����ܼơA�i�קK stack overflow�C
//
//�ϥ� heap �ɡA���M��� process �i�Ϊ��Ŷ��O�������A���ĥΰʺA���
//���覡�Anew �L�k�t�m�ɷ|��X std::bad_alloc �ҥ~�Amalloc �L�k�t�m
//�ɷ|�^�� null(��2)�A���|�v�T�쥿�`�ϥΤU���{���\��

//
//& * �Ϊk   &����}  *����   *�ŧi�ɥN�����
//int num1 = 2, num2 = 3;
//int *pi_1, *pi_2;  //�ŧi���V��ƪ������ܼ�
//pi_1 = &num1;  //�Ϋ���pi_1���Vnum1����m
//printf("pi_1 = %d\r\n", *pi_1); //pi=2
//pi_2 = &num2;//�Ϋ���pi_2���Vnum2����m
//printf("pi_2 = %d\r\n", *pi_2); //pi=2


//��13
//�禡�� new �X�Ӫ��Ŷ��O�o�n���D�{�������б���
//
//
//����Ф����x���ϥΪ̷|�H���H�U���{���X�O�ŦX�w����
//
//
//void newArray(int* local, int size) {
//	local = (int*)malloc(size * sizeof(int));
//}
//
//int main() {
//	int* ptr;
//	newArray(ptr, 10);
//}
//
//
//���۴N�|��F�ܤ[�� bug�A�̫ᤴ�M�d���������� ptr �S�����V��讳�쪺�X�k�Ŷ�
//
//
//���ڭ̦A�^�U�@���A�åB�ιϪ��(�P��Hazukashiine�O�ʹ��ѹϸ�)
//
//�z�w�w�w�w�{      �z�w�w�w�w�{      �z�w�w�w�w�{      �z�w�w�w�w�{
//Heap   �x        �x      �x        �x      �x �s�t�m �x      �x �w�n�| �x
//�x        �x      �x        �x      �x ���Ŷ� �բw�{  �x ���Ŷ� �x
//�x        �x      �x        �x      �x(allocd)�x  �x  �x(leaked)�x
//�x        �x      �x        �x      �u�w�w�w�w�t  �x  �u�w�w�w�w�t
//�x        �x      �x        �x      �x   �G   �x  �x  �x        �x
//�x        �x      �x        �x      �x   �G   �x  �x  �x   �G   �x
//�x        �x      �u�w�w�w�w�t      �u�w�w�w�w�t  �x  �x   �G   �x
//�x        �x      �x local  �u�w�{  �x local  �u�w�}  �x        �x
//�u�w�w�w�w�t      �u�w�w�w�w�t  �x  �u�w�w�w�w�t      �u�w�w�w�w�t
//Stack  �x  ptr   �u�w�{  �x  ptr   �u�w�t  �x  ptr   �u�w�{  �x  ptr   �u�w�{
//�|�w�w�w�w�}  ��  �|�w�w�w�w�}  ��  �|�w�w�w�w�}  ��  �|�w�w�w�w�}  ��
//
//
//����l��          �禡�I�s          �t�m�Ŷ�          �禡��^
//int *ptr;       local = ptr;    local = malloc();
//
//
//�ιϬ����Ӥ@���N�����դF�A�ڤ]���ݤ�������
//
//
//�]�\���H�|�Q�ݡA���Ф��O�ǧ}�ܡH
//
//��T�����A���Ф]�O�ǭȡA�u���L�ӭȬO�@�Ӧ�}(ex: 0xfefefefe)




//p22   1.22
// sales_item total;
//if (cin >> total) {
//	Sales_item trans;
//	while (cin >> trans)
//	{
//		if (trans.isbn() == total.isbn()) {
//			total += trans;
//		}
//		else {
//			cout << total << endl;
//			total = trans;
//		}
//	}
//	cout << total << endl;
//
//}
//else {
//	cerr << "No Data?!" << endl;
//	return -1;
//}


//��5
//char *getstr(char *name)
//{
//	char buf[30] = "hello, "; /*�N�r��`��"hello, "�����e�ƻs��buf�}�C*/
//	strcat(buf, name);
//	return buf;
//}
//
//
//void getstr(char buf[], int buflen, char const *name)
//{
//	char const s[] = "hello, ";
//	strcpy(buf, s);
//	strcat(buf, name);
//}
//
//
//int* foo()
//{
//	int* pInteger = (int*)malloc(10 * sizeof(int));
//	return pInteger;
//}
//
//int main()
//{
//	int* pFromfoo = foo();
//}
//
//
//#include <string>    /* �ëD #include <cstring> */
//using std::string;
//
//string getstr(string const &name)
//{
//	return string("hello, ") += name;
//}




//p22 1.21 ans
//Sales_item item1, item2;
//std::cin >> item1 >> item2;
//if (item1.isbn() == item2.isbn()) {
//	std::cout << item1 + item2 << std::endl;
//	return 0;
//}
//else {
//	std::cerr << "Data must refer to same ISBN." << std::endl;
//	return -1;
//}


//p 21
//Sales_item book, book2;
//cin >> book >> book2;
//cout << book + book2
//<< endl;
//return 0;
//
/////////////////
///*Sales_item book;
//cin >> book;
//cout << book << endl;
//return 0;
//*/

//p17 ex 1.16
//int value = 0, sum = 0;
//cout << "c" << endl;
//
//while (std::cin >> value)
//{
//	sum += value;
//}
//
//cout << sum << endl;
//
//return 0;


//p15
//cin  �@��Ū�쵲���ο��~�D�Ʀr    �G�M��  ��o�䥴�o�q�{�������m�שM���r�t��  �w�g��C#�t���h�F
//
//int value = 0;
//cout << "c" << endl;
//
//while (std::cin >> value)    Ctrl Z �u���O eof
//{
//	cout << "c" << endl;    �o���  ���|�i��  
//}
//
//return 0;


//p6
//
//
//int main() {
//
//	cout << "Enter 2 numbers:" << endl;
//	int v1 = 0, v2 = 0;
//	cin >> v1 >> v2;
//	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
//	return 0;
//}
//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
