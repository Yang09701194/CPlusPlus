// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Sales_item.h"

using namespace std;


int main() {


	int *p = (int*)malloc(100000000);//�t�m�O����  �u�@�޲z����ݨ��z�W
	
	int i;
	cin >> i;

	free(p);//����   �u�@��  �ܶW�C  �ߨ�ϬM
	cin >> i;


}


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
