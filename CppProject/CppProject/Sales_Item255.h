#pragma once

using namespace std;
#include <string>

//255

struct Sales_Data {

	//265
	Sales_Data() = default;
	Sales_Data(const string &s) : bookNo(s){ }
	Sales_Data(const string &s, unsigned n, double p) : 
		bookNo(s), units_sold(n), revenue(p*n){ }  // constructor initialize list 建構器初始串列

	Sales_Data(istream &is);//266沒有提到要這句   我看紅字自己加的  可能要再類別外定義  還是要這樣宣告


	//成員函式  
	std::string isbn() const { 
		return bookNo; 
		//  bookNo 也是 this 的概念  return bookNo 相當於

		// 同  return this->bookNo;

		//this 是永遠指向這物件  所以是const指標  無法修改

		//this 相當於宣告為 Sales_Data *const    //語法  同  p64

		//這邊後面的const 是意義代表 this 是const指標  詳細看258底下的想像的實體this轉化的虛擬程式碼

		//類別內沒有後用的要定義在前方  任意位置視為都可用

	}
	Sales_Data& combine(const Sales_Data&);
	double avg_price() const;
	   
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//非成員函式 但是Sales_Data 介面  函式  介面 都宣告在  類別之外  用 類別::  表示  是給類別用的  
//回憶起很久沒碰的Go 該不會是從這邊抄的吧
Sales_Data add(const Sales_Data&, const Sales_Data&);
std::ostream &print(std::ostream&, const Sales_Data&);
std::istream &read(std::istream&, Sales_Data&);


//類別成員定義  好像是寫在cpp裡

double Sales_Data::avg_price() const {
	if (units_sold)  //這邊很炫  寫在外部還能讀到內部的屬性
		return revenue / units_sold;
	else
		return 0;
}

Sales_Data& Sales_Data::combine(const Sales_Data &rhs) /*注意沒 const*/ {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

//261

// 介面成員定義  寫在類同個h
istream &read(istream &is, /*沒有const*/ Sales_Data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_Data &item) {
	double price = 0;
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_Data add(const Sales_Data &lhs, const Sales_Data &rhs) {
	Sales_Data sum = lhs;
	sum.combine(rhs);
	return sum;  //回傳copy
}



//266  類別外定義建構器
Sales_Data::Sales_Data(istream &is) {
	read(is, *this);//*this的用法
}




