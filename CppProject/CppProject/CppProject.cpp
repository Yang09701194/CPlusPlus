// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Sales_item.h"

using namespace std;


int main() {

	
}






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
