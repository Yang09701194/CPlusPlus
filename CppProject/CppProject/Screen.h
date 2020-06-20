#pragma once
/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/


#include <string>
#include <iostream>

class Screen {
public:
	typedef std::string::size_type pos;  // 271 別名定義   public是因為要讓user也能用   也可以用using



//	272
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
	Screen() = default;  // needed because Screen has another constructor
#else
	Screen() : cursor(0), height(0), width(0) { }
#endif
	// cursor initialized to 0 by its in-class initializer
	Screen(pos ht, pos wd, char c) : height(ht), width(wd),
		contents(ht * wd, c) { }

	//280
	friend class Window_mgr;
	
	//281
	//不要整個class當朋友  只要特定成員 ex
	//friend void Window_mgr::clear(ScrrenIndex)

	Screen(pos ht = 0, pos wd = 0) :
		cursor(0), height(ht), width(wd), contents(ht * wd, ' ') { }
	
	char get() const              // get the character at the cursor
	{
		return contents[cursor];   // 272 類別內的成員預設就是inline
	}       // implicitly inline
	inline char get(pos ht, pos wd) const; // explicitly inline      //inline也可以在宣告 定義都 寫 但可省略
	
	Screen &clear(char = bkground);

private:
	static const char bkground = ' ';

public:
	Screen &move(pos r, pos c);      // can be made inline later
	Screen &set(char);
	Screen &set(pos, pos, char);


	// other members as before
	// display overloaded on whether the object is const or not
	Screen &display(std::ostream &os)
	{
		do_display(os); return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os); return *this;
	}

	// 276  Display功能  不會改變物件  所以理論上要宣告為const  但是const後就沒辦法連環call 因為後面繼續call set就要需要能改變  
	//	傳const 過去就會錯誤  
	//  所以巧妙方式   先重載一個非const版本  在另外定義 do_display 是 const  就可以作到變動方法const 外層但回傳非const
	//  這種小函式共用在多個外層 277說是良好的設計  我認同 就盡量重用  放在單一好維護


private:
	// function to do the work of displaying a Screen
	void do_display(std::ostream &os) const { os << contents; }
	// other members as before

private:
#ifdef IN_CLASS_INITS
	pos cursor = 0;
	pos height = 0, width = 0;
#else
	pos cursor;
	pos height, width;
#endif
	std::string contents;
};

Screen &Screen::clear(char c) 
{
	contents = std::string(height*width, c);
	return *this;   // 275 要像 LINQ 或 jQuery 可以連環呼叫   就靠return *this  回傳參考

	//ex
	//Screen myScreen(5, 3);
	//// move the cursor to a given position, and set that character 
	//myScreen.move(4, 0).set('#');
}

inline                   // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c;    // move cursor to the column within that row
	return *this;        // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
	pos row = r * width;      // compute row location
	return contents[row + c]; // return character at the given column
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c; // set the new value at the current cursor location
	return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  // set specified location to given value
	return *this;                  // return this object as an lvalue
}
