#pragma once

using namespace std;
#include <string>

//255

struct Sales_Data {
	//�����禡  
	std::string isbn() const { 
		return bookNo; 
		//  bookNo �]�O this ������  return bookNo �۷��

		// �P  return this->bookNo;

		//this �O�û����V�o����  �ҥH�Oconst����  �L�k�ק�

		//this �۷��ŧi�� Sales_Data *const    //�y�k  �P  p64

		//�o��᭱��const �O�N�q�N�� this �Oconst����  �ԲӬ�258���U���Q��������this��ƪ������{���X

		//���O���S����Ϊ��n�w�q�b�e��  ���N��m�������i��

	}
	Sales_Data& combine(const Sales_Data&);
	double avg_price() const;
	   
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//�D�����禡 ���OSales_Data ����  �禡  ���� ���ŧi�b  ���O���~  �� ���O::  ���  �O�����O�Ϊ�  
//�^�а_�ܤ[�S�I��Go �Ӥ��|�O�q�o��۪��a
Sales_Data add(const Sales_Data&, const Sales_Data&);
std::ostream &print(std::ostream&, const Sales_Data&);
std::istream &read(std::istream&, Sales_Data&);


//���O�����w�q  �n���O�g�bcpp��

double Sales_Data::avg_price() const {
	if (units_sold)  //�o��ܬ�  �g�b�~���ٯ�Ū�줺�����ݩ�
		return revenue / units_sold;
	else
		return 0;
}

Sales_Data& Sales_Data::combine(const Sales_Data &rhs) /*�`�N�S const*/ {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// ���������w�q  �g�b���P��h
istream &read(istream &is, const Sales_Data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_Data &item) {
	double price = 0;
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	ret os;
}

Sales_Data add(const Sales_Data &lhs, const Sales_Data &rhs) {
	Sales_Data sum = lhs;
	sum.combine(rhs);
	return sum;
}





