// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Sales_item.h"
#include "Account.h"
#include <vector>

#include <numeric>      // std::accumulate

#include <set>
using std::multiset;

#include <map>
using std::map;

#include <utility>

using std::pair; using std::make_pair;

#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <memory>
#include <new> //460


using namespace std;
using std::vector;




int main() {




	int pause;
	cin>> pause;	
	
	
}

//指標 pointer pt


//read end 862



//498
//有移動建構器的話  拷貝初始化有時會使用移動建構器   或拷貝建構器任一

//拷貝初始化  


////496 7
//沒有定義拷貝控制成員  編譯器會自動定義  幫忙合成一個
//正常來說會逐個成員拷貝其引數的成員到正在建立的物件中
//13.1.6還說  有些合成的拷貝建構器 會防止我們拷貝該類的物件
//
//拷貝建構器
//class Foo {
//public:
//	Foo();				//預設建構器
//	Foo(const Foo&)		//拷貝建構器   幾乎總是const的參考  通常不應是explicit的
//};
//
//類別型別成員 用copy建構器copy
//內建型別成員直接拷貝 (陣列無法拷貝)
//class Sales_data {
//public:
//	Sales_data(Sales_data&);
//private:
//	string bookNo;
//	int units_sold;
//};
//
//Sales_data::Sales_data(const Sales_data &orig) :   //拷貝所有屬性
//	bookNo(orig.bookNo),
//	units_sold(orig.units_sold)
//{}
//
//
//string d(10, 'c')  //直接初始化  用一般建構器
//string d(d2)//直接初始化
//string d = d2;//拷貝初始化
//string null_book = "999-9"//拷貝初始化 拷貝建構器ㄌ
//string n = string(100, '9')//拷貝初始化
//






////495
//總稱拷貝控制
//學習類別如何控制 類別型別被 拷貝 指定 移動 摧毀時 會發生什麼事
//拷貝建構器 移動建構器   拷貝指定運算子  移動指定運算子  解構器



//494
//類別能夠重載的運算子包括 函式呼叫運算子  可以呼叫這種類別的物件  好像他是函式一樣  


////485  6 7  8 9  490
//文字查詢程式
//搜尋檔案中  字詞出現的錯誤  和出現的行號  遞增出現
//
//任務分析
//讀取輸入時  記得個字出現在哪幾行  一次讀一行  拆成個別字詞
//輸出  字詞的關聯行號  遞增 不重複  印出行號上的文字
//
//作法
//用vector<string>  儲存檔案的每一行
//用istringstream 來把行拆成字詞
//set 儲存行號  保證唯一性 遞增性
//map 紀錄  字詞 , 關聯的行號集合  (set of line numbers)    就是可以用字詞  查 行號set
//也會使用shared_ptr
//
//TextQuery 存放一個vector 和 map   (字詞, 字詞關聯的行號)
//回傳資料用  TextQueryResult 存放查詢結果   並且有print函式印出結果
//
//TextQueryResult所需的資料存在TextQuery  像是set vector     當然不想用複製的  他們都很大
//也不適合用迭代器   因為可能物件先被摧毀了
//所以當然是shared_ptr  莫屬
//
//先寫個概念性程式
//void runQuries(ifstream &infile) {
//	TextQuery tq(infile)//儲存檔案  建構查詢的map
//	while (true)
//	{
//		cout << "enter word to look for or q quit" << endl;
//		string s;
//		if ((cin >> s) || s == "q") break;
//		print(tq.query(s)) << endl;//執行查詢並印出
//	}
//}
//
//
//實際來寫類別
//#include <memory>
//#include <string>
//#include <vector>
//#include <map>
//#include <set>
//#include <fstream>
//#include "QueryResult.h"
//
///* this version of the query classes includes two
// * members not covered in the book:
// *   cleanup_str: which removes punctuation and
// *                converst all text to lowercase
// *   display_map: a debugging routine that will print the contents
// *                of the lookup mape
//*/
//
//class QueryResult; // declaration needed for return type in the query function
//class TextQuery {
//public:
//#ifdef TYPE_ALIAS_DECLS
//	using line_no = std::vector<std::string>::size_type;
//#else
//	typedef std::vector<std::string>::size_type line_no;
//#endif
//	TextQuery(std::ifstream&);
//	QueryResult query(const std::string&) const;
//	void display_map();        // debugging aid: print the map
//private:
//	std::shared_ptr<std::vector<std::string>> file; // input file   !!!!!!!!!!!
//	// maps each word to the set of the lines in which that word appears   !!!!!!!!!
//	std::map<std::string,
//		std::shared_ptr<std::set<line_no>>> wm;
//
//	// canonicalizes text: removes punctuation and makes everything lower case
//	static std::string cleanup_str(const std::string&);
//};
//#endif
//
//
//#include <cstddef>
//#include <memory>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <map>
//#include <set>
//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <cstring>
//#include <utility>
//
//using std::size_t;
//using std::shared_ptr;
//using std::istringstream;
//using std::string;
//using std::getline;
//using std::vector;
//using std::map;
//using std::set;
//using std::cerr;
//using std::cout;
//using std::cin;
//using std::ostream;
//using std::endl;
//using std::ifstream;
//using std::ispunct;
//using std::tolower;
//using std::strlen;
//using std::pair;
//
//// read the input file and build the map of lines to line numbers    建構器!!!!!!!!
//TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
//{
//	string text;
//	while (getline(is, text)) {       // for each line in the file
//		file->push_back(text);        // remember this line of text
//		int n = file->size() - 1;     // the current line number
//		istringstream line(text);     // separate the line into words
//		string word;
//		while (line >> word) {        // for each word in that line
//			word = cleanup_str(word);
//			// if word isn't already in wm, subscripting adds a new entry
//			auto &lines = wm[word]; // lines is a shared_ptr 
//			if (!lines) // that pointer is null the first time we see word
//				lines.reset(new set<line_no>); // allocate a new set
//			lines->insert(n);      // insert this line number      就算存在也可以呼叫insert 因為set不會重複新增   保持唯一性
//		}
//	}
//}
//
//// not covered in the book -- cleanup_str removes
//// punctuation and converts all text to lowercase so that
//// the queries operate in a case insensitive manner
//string TextQuery::cleanup_str(const string &word)
//{
//	string ret;
//	for (auto it = word.begin(); it != word.end(); ++it) {
//		if (!ispunct(*it))
//			ret += tolower(*it);
//	}
//	return ret;
//}
//
//QueryResult
//TextQuery::query(const string &sought) const
//{
//	// we'll return a pointer to this set if we don't find sought
//	static shared_ptr<set<line_no>> nodata(new set<line_no>);
//
//	// use find and not a subscript to avoid adding words to wm!              !!!!!!!!!!!!!!
//	auto loc = wm.find(cleanup_str(sought));
//
//	if (loc == wm.end())
//		return QueryResult(sought, nodata, file);  // not found
//	else
//		return QueryResult(sought, loc->second, file);
//}
//
//ostream &print(ostream & os, const QueryResult &qr)    !!!!!!!!!!!!!!!!!!!!!!!!!!!
//{
//	// if the word was found, print the count and all occurrences
//	os << qr.sought << " occurs " << qr.lines->size() << " "
//		<< make_plural(qr.lines->size(), "time", "s") << endl;
//
//	// print each line in which the word appeared
//	for (auto num : *qr.lines) // for every element in the set 
//		// don't confound the user with text lines starting at 0
//		os << "\t(line " << num + 1 << ") "
//		<< *(qr.file->begin() + num) << endl;
//
//	return os;
//}
//
//// debugging routine, not covered in the book
//void TextQuery::display_map()
//{
//	auto iter = wm.cbegin(), iter_end = wm.cend();
//
//	// for each word in the map
//	for (; iter != iter_end; ++iter) {
//		cout << "word: " << iter->first << " {";
//
//		// fetch location vector as a const reference to avoid copying it
//		auto text_locs = iter->second;
//		auto loc_iter = text_locs->cbegin(),
//			loc_iter_end = text_locs->cend();
//
//		// print all line numbers for this word
//		while (loc_iter != loc_iter_end)
//		{
//			cout << *loc_iter;
//
//			if (++loc_iter != loc_iter_end)
//				cout << ", ";
//
//		}
//
//		cout << "}\n";  // end list of output this word
//	}
//	cout << endl;  // finished printing entire map
//}
//
//
//#ifndef QUERYRESULT_H
//#define QUERYRESULT_H
//#include <memory>
//#include <string>
//#include <vector>
//#include <set>
//#include <iostream>
//
//class QueryResult {
//	friend std::ostream& print(std::ostream&, const QueryResult&);
//public:
//	typedef std::vector<std::string>::size_type line_no;
//	typedef std::set<line_no>::const_iterator line_it;
//	QueryResult(std::string s,
//		std::shared_ptr<std::set<line_no>> p,
//		std::shared_ptr<std::vector<std::string>> f) :
//		sought(s), lines(p), file(f) { }
//	std::set<line_no>::size_type size() const { return lines->size(); }
//	line_it begin() const { return lines->cbegin(); }
//	line_it end() const { return lines->cend(); }
//	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
//private:
//	std::string sought;  // word this query represents                 !!!!!!
//	std::shared_ptr<std::set<line_no>> lines; // lines it's on       !!!!!!!
//	std::shared_ptr<std::vector<std::string>> file;  //input file   !!!!!!!!!!!
//};
//
//std::ostream &print(std::ostream&, const QueryResult&);
//#endif







////483   4
//在未初始化的記憶體中建構物件  也在 <memory>
//
//uninitialize_copy(b, e, b2)   b, e範圍的元素  拷貝到 b2代表的原始記憶體  b2大小要能夠存放
//uninitialize_copy_n(b, n, b2) b 開始 拷貝n個 到 b2 ""
//uninitialize__fill(b, e, t)   b e 範圍的原始記憶體  建構物件t的拷貝
//uninitialize_fill_n(b, n, t)  b 未經建構的原始記憶體   開始建構 n 個 t 物件   b要夠大
//
//
//ex vector<int>  n個元素       配置2n個數目的記憶體   我們從原本的vec  拷貝到前n     後半部填入定值
//-------
//auto p =  alloc.allocate(v.size() *2)
//auto q = uninitialize_copy(v.begin(), v.end(), p)  注意跟上面對照
//uninitialize_fill_n(q, v.size(), 42)






//481 2
//new 結合了 配置記憶體 + 建構
//delete 解構 + 釋放
//
//配置 + 建構  可能會浪費記憶體  詳見書
//
//<memory> 的 allocator類別 是模版 可以只配置
//
//一個 allocator 配置記憶體時  有適當的大小  並經過對其排列   配置的記憶體是未經建構的
//allocator<string> alloc;//用來配置string 的物件
//auto const p = alloc.allocate(n);//配置n個未建構的string
//.deallocate(p, n)// 從pt p 開始  解除存放n個物件   p 和 n 必須和allocate的時後的值相同
//.construct(p, args)// args被傳到T的建構器 建構一個p所指的物件
//.destroy(p)//在 T* pt p所指物件上執行解構器
//
//auto q = p // q會指向超過最後一個建構的元素的位置 邊建構會邊往後移動
//alloc.construct(q++);//*q 空string 
//alloc.construct(q++, 10, 'c')	//*q cccccccccc
//alloc.construct(q++, "hi")// *q是hi
//
//cout << *q << endl;//error q指向未經建構的記憶體
//
//物件使用完畢後解構
//while(q != p)
//	alloc.destroy(--q);
//接著
//alloc.deallocate(p, n);




//480
//shared_ptr  要提供刪除器  沒提供未定義
//shared_ptr<int[]> sp(new int[10], [](int *p) {delete[] p};//未初始化
//sp.reset()//使用delete[]刪除指標
//沒有下標運算子
//for (size_t i = 0; i != 10; i++)
//{
//	*(sp.get() + i) = i; //就是這樣用
//}
//
//
//478  9
//也可以串列初始
////int *pia = new int[5]{1,2,3};  //前三個是初始器初始化  後二值初始化
//
//空陣列合法
//char arr[0]//error 陣列長不可0
//char *cp = new char[0] // ok  cp不能被解參考  有點像off the end
//
//// []  沒[]會未定義
//delete[] pia;
//摧毀順序是相反  從最後面開始
//
//
//unique_ptr + 動陣
//unique_ptr<int[]> up(new int[10]);//未初始化
//up.release()//自動使用delete[]刪除指標
//
//up可以用下標運算子存取  當成陣列
//for (size_t i = 0; i != 10; i++)
//{
//	up[i] = i;
//} 
//



//476 7
//new delete 依次配置一個物件
//動態陣列 可以一次配置一個陣列  為allocator模板類別
//
//通常用不到動態陣列  因為容器更好用
//容器有預設的拷貝 指定 解構
//但配置動陣  需要用自己版本的運算管理記憶體

//int *pia = new int[get_size()]; //pia指向第一個元素
//
//用型別別名
//typedef int arrT[42];
//int *p = new arrT;

//配置完並不具備一個陣列型別  所以也沒有begin end for
//上面寫法是 預設初始化 的  要值初始化 跟前面很多慣例相同 加小括號 
//類似上面寫法 不贅述 




//472 3 4 5 
//weak_ptr  不控制他指物件的生命週期
//是由某個shared_ptr管理的
//weak繫結到share  並不改變share的參考計數
//share歸0刪除  就算有weak指向也不影響照刪 所以叫weak
//
//auto p = make_shared<int>(42) 
//weak_ptr<int> wp(p) 
//
//因w指的物件可能不在  所以透過lock判斷呼叫
//if (shared_ptr<int> np = wp.lock()) {
//	//
//}
//
//
//weak_ptr<T> w
//weak_ptr<T> w(sp)   //都跟sp共享所有權
//weak_ptr<T> w = sp
//w.reset()       // w 變 null
//.use_count()    // 共享所有權的sp數目
//.expired()  //usecount ==0 
//lock() //  expired true 回傳 null  shared_ptr  否則回傳sp

//StrBlobPtr下面記錄過了
//為StrBlob定義一個伴隨的指標類別  命名為 StrBlobPtr
//會儲存一個wp指向他從之初使化的data成員
//不影響原本StrBlob所指的vector的生命週期   
//請搜尋  wptr 還有 check 方法
//deref incr也有意思
//begin end 要存取data 所以StrBlob內部要宣告StrBlobPtr為StrBlob的friend


//471
//unique_ptr  可拷貝的例外情境
//編譯器知道即將被摧毀  會進行特殊拷貝 13.6.2
//1
//unique_ptr<int> clone(int p) {
//	return unique_ptr<int>(new int(p))
//}
//unique_ptr<int> clone(int p) {
//	unique_ptr<int> ret(new int(p))
//	return ret
//}
//
//auto_ptr沒在用
//
//刪除器 16.1.6會提到  unique_ptr 刪除器 管理方式和shared_ptr
//						//角括號要指出型別
//unique_ptr<connection, decltype(end_conn)> p(&c, end_conn)


//470
//unique_ptr 擁有own 他的物件  一次只有一個能指向
//所以u被摧毀 物件就被摧毀
//u用直接初始化
////unique_ptr<int> p(new int(42))
////unique_ptr<int> p2(p)  //error no copy
////p3 = p2 // error no assign
//
//unique_ptr<T> u1 
//unique_ptr<T, D> u1   //D 刪除時要執行的動作  D是可呼叫物件
//unique_ptr<T, D> u(d)// 用d來取代delete的物件的 null unique_ptr  
//u = null_ptr //刪除u指的物件  
//u.release()//放棄u持有的指標控制權 回傳u所持有的指標 且u變null
//u.reset()//刪除u所指的物件
//u.reset(q)//刪除u所指的物件   u指向q
//u.reset(nullptr)//刪除u所指的物件   u變null
//
////搭配上面看
////所有權 p1 轉移給 p2
//unique_ptr<string> p2(p1.release()) //p1變null
//unique_ptr<string> p3(new string("T")) 
//p2.reset(p3.release())//所有權 p3 轉移至 p2  
////reset 刪除 p2 曾指向的記憶體
//
//p2.release()// 錯 p2不會是放記憶體  且會失去指標
//auto p = p2.release() // ok 記得delete p





//467 8 9
//
//shared_ptr 可以保證在ex發生時  自動計數遞減 0則釋放
//
//new delete就要自己注意
//
//
//如果類別沒有定義良好的解構器 釋放資源  特別是設計讓C和C++同時使用的類比較不會要求user明確釋放
//這時就可以參數傳入解構方法
//ex   connect這個類字有點多省略不打  需要再翻 只記關鍵
//connection c = connect(&d)
//shared_ptr<connection> p(&c, end_connection)
//
//當要執行del時   實際上是呼叫end_connection


//465 6
//
//別混合使用普通指標  和 SP
//
//shared_ptr<T> p(q)  //q指向new配置的記憶體
//shared_ptr<T> p(u)  //p預設來自unique_ptr的所有權 使u變null
//shared_ptr<T> p(q / p, d)  //d可呼叫物件 取代delete釋放q
//
//
//////如果p是指向其物件的唯一一個shared_ptr  
////reset會釋放p現有的物件  如果傳入q  就讓p指向q 否則p變為null
////d來釋放q
//p.reset()
//p.reset(q)
//p.reset(q, d)
//
//int *x(new int(4))
//process(x)
//process(shared_ptr<int>(x))
//int j = *x//上面process完 x 就被釋放了  繼續使用就是未定義  
////這種用法就錯  所以避免混用
//
//別用get來初始另個SP
//get使用時機是  傳給無法使用SP的程式使用
//使用get回傳值的程式碼  必不能delete那個指標  所以另一邊被摧毀之後  這個指標就不能用了
//
//shared_ptr<int> p(new int(42))
//int* q = p.get();
//{
//	shared_ptr<int>(q)
//}//結束後q被摧毀
//int foo = *p//未定義  p指的記憶體已被釋放   且若再delete
//
///////
//
//shared_ptr<int> p(new int(42))
//p = new int(4) //error 不能指定指標給share...
//p.reset(new int(4))//ok  指向新的物件   會更新參考計數   適當時刪除p原本指向的物件
//
//
//reset 常會與unique 一起控制對數個 share_ptr的變更
//變更物件前 先檢查是否為唯一使用者  不是就在更動前先製作一個新的拷貝
//if (!p.unique())
//	p.reset(new string(*p))//拷貝後  自己就變唯一使用者 就不會干擾到他人
//*p += newVal;
//
//
//464
//混用 shared_ptr  new   
//shared_ptr<double> p1
//shared_ptr<double> p2(new int(42))   //建構器是explicit的  所以不能 p2 = new int(42
//
//初始一個SP的指標要指向動態記憶體  因為 shared_ptr 也是用 delete來釋放




 
////460  1 2 3
//自由存放區  記憶體耗盡時  new 會丟bad_alloc 例外
//要避免用
//int *p = new(nothrow) int;//錯誤時回傳null指標   這叫placement new	 這兩個瓷都定義在 <new>
//
//
//釋放動態記憶體  delete p;
//刪除非new指標 或多於一次 > 未定義
//
//double d = new double(33);
//delete d;    //const new也適用
//
//前面 shared_ptr 是在引用數歸0自動摧毀
//new 則是沒delete錢都會存在
//
//Foo* factory(T arg) {
//	return new Foo(arg)
//}
//
//void use_fac(T arg) {
//	Foo *p = factory(arg)
//}//離開後p仍然存在 不會被摧毀
////加上delete p 就會摧毀
//
//動態記憶體容易出錯
//1 忘記 del > memory leak 很難找    除非完全耗盡
//2 物件刪除後還使用  有時可以在del後設為null (nullptr) 來偵測
//3 重複刪除  
//上面易犯  要找出來很難
//
//多個指標指向同個記憶體 刪掉一個後 其他的指向的記憶體會無效  但難偵測
//int *p(new int(3)), *r = new int(100)
//r = q 
//delete p
//p = nullptr





//458  9
//直接管理記憶體  用 new delete
//
//在自由存放區free store配置的物件是無名的
//所以 new 回傳pt 指向物件
//
//int *pi = new int;//動態配置  無名  未初始化    Debug實測  真的是一個亂數
//new是預設初始化 :  內建/複合型別>未定義的值   類別>預設建構器初始化

//string *ps = new string ;//空字串 

//
//也可以
//int *p = new int(1024);
//string *s = new string(10, '9')
//vec *v = new vec<int>{ 1,2,3 };
//
//如果有加空括號  就是值初始化  int > 0
//int *p = new int();
//
//用auto配一個參數  可以都用auto  編譯器推論型別
//auto a = new auto(obj)
//
//const 也可 new 
//const int *p = new const int(10)

//const 有預設建構器的類別型別 可隱含初始化  其他類別 都要被明確初始化
//
//new const回傳 對const的指標





//456 7
//
//存放群集 是用現有的vector  但是為了達到v2摧毀 v1還在   把vector放在動態記憶體
//一樣 拷貝 指定 摧毀 StrBlob   裡面的data也會 ""
// 
//但data只有在全部使用到的地方都被摧毀後  才會自動摧毀 
//
//#ifndef STRBLOB_H
//#define STRBLOB_H
//
//#include <vector>
//#include <string>
//#include <memory>
//#include <stdexcept>
//
//#ifdef LIST_INIT
//#include <initializer_list>
//#endif
//
//// forward declaration needed for friend declaration in StrBlob
//class StrBlobPtr;
//
//class StrBlob {
//	friend class StrBlobPtr;
//public:
//	typedef std::vector<std::string>::size_type size_type;
//
//	// constructors
//	//  !!!!!!!!!  就是這邊用make_shared  做到
//	StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
//#ifdef LIST_INIT
//	StrBlob(std::initializer_list<std::string> il);//!!接受串列初始
//#else
//	StrBlob(std::string *, std::string*);
//#endif
//
//	// size operations
//	size_type size() const { return data->size(); }   //!!!!!都是使用共用的 data 作用 
//	bool empty() const { return data->empty(); }
//
//	// add and remove elements
//	void push_back(const std::string &t) { data->push_back(t); }
//	void pop_back();
//
//	// element access
//	std::string& front();   //應該還要重載於const上
//	std::string& back();
//
//	// interface to StrBlobPtr
//	StrBlobPtr begin();  // can't be defined until StrBlobPtr is
//	StrBlobPtr end();
//private:
//	std::shared_ptr<std::vector<std::string>> data;  //共用的
//	// throws msg if data[i] isn't valid
//	void check(size_type i, const std::string &msg) const;    //最後一個const  表用this時視為const 物件  不可改變成員值  除mutable
//};
//
////我抄書上寫的   源碼無  !!!!  因為轉介屬性 所以要先檢查 有沒有元素 0個就丟錯
//void StrBlob::check(size_type i, const std::string &msg) const
//{
//	if (i >= data->size())
//		throw out_of_range(msg);
//}
//string& StrBlob::front() {
//	check(0, "front on empty strblob");
//	return data->front();
//	//back 
//	//popback同理
//}
//
//
//
//// constructor
//#ifdef LIST_INIT
//inline
//StrBlob::StrBlob(std::initializer_list<std::string> il) :
//	data(std::make_shared<std::vector<std::string>>(il)) { }
//#else
//inline
//StrBlob::StrBlob(std::string *b, std::string *e) :
//	data(std::make_shared<std::vector<std::string>>(b, e)) { }
//#endif
//
//// StrBlobPtr throws an exception on attempts to access a nonexistent element 
//class StrBlobPtr {
//	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
//public:
//	StrBlobPtr() : curr(0) { }
//	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
//
//	std::string& deref() const;
//	StrBlobPtr& incr();       // prefix version
//	StrBlobPtr& decr();       // prefix version
//private:
//	// check returns a shared_ptr to the vector if the check succeeds
//	std::shared_ptr<std::vector<std::string>>
//		check(std::size_t, const std::string&) const;
//
//	// store a weak_ptr, which means the underlying vector might be destroyed
//	std::weak_ptr<std::vector<std::string>> wptr;
//	std::size_t curr;      // current position within the array
//};
//
//inline
//std::string& StrBlobPtr::deref() const
//{
//	auto p = check(curr, "dereference past end");
//	return (*p)[curr];  // (*p) is the vector to which this object points
//}
//
//inline
//std::shared_ptr<std::vector<std::string>>
//StrBlobPtr::check(std::size_t i, const std::string &msg) const
//{
//	auto ret = wptr.lock();   // is the vector still around?
//	if (!ret)
//		throw std::runtime_error("unbound StrBlobPtr");
//
//	if (i >= ret->size())
//		throw std::out_of_range(msg);
//	return ret; // otherwise, return a shared_ptr to the vector
//}
//
//// prefix: return a reference to the incremented object
//inline
//StrBlobPtr& StrBlobPtr::incr()
//{
//	// if curr already points past the end of the container, can't increment it
//	check(curr, "increment past end of StrBlobPtr");
//	++curr;       // advance the current state
//	return *this;
//}
//
//inline
//StrBlobPtr& StrBlobPtr::decr()
//{
//	// if curr is zero, decrementing it will yield an invalid subscript
//	--curr;       // move the current state back one element}
//	check(-1, "decrement past begin of StrBlobPtr");
//	return *this;
//}
//
//// begin and end members for StrBlob
//inline
//StrBlobPtr
//StrBlob::begin()
//{
//	return StrBlobPtr(*this);
//}
//
//inline
//StrBlobPtr
//StrBlob::end()
//{
//	auto ret = StrBlobPtr(*this, data->size());
//	return ret;
//}
//
//// named equality operators for StrBlobPtr
//inline
//bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
//{
//	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
//	// if the underlying vector is the same 
//	if (l == r)
//		// then they're equal if they're both null or 
//		// if they point to the same element
//		return (!r || lhs.curr == rhs.curr);
//	else
//		return false; // if they point to difference vectors, they're not equal
//}
//
//inline
//bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
//{
//	return !eq(lhs, rhs);
//}
//#endif






//454 5
//使用動態記憶體的原因
//不知道將會需要多少物件     ex容器類別
//不清楚物件的確切型別       this ch
//想在數個物件之間共用資料   ch15 
//
//ex copy vec  兩vec 是分別的東西彼此無關
//
//例如 
//vec v2 = {"a","b"}
//v1 = v2
//這兩者自己被摧毀時就真的沒了
//
//假設我們想做到一個類  也可以存放群集元素  但是拷貝後會指向相同的元素
//
//例如
//b1
//{
//	b1 = b2
//}
////b2被摧毀  但b2裡的元素還會在   b1還指向使用他們



//452 3
//shared_ptr<T> s    指向null的智慧指標
//unique_ptr<T> u
//p   有指向物件為true
//*p 取得物件
//p->mem   (*p).mem
//p.get()         回傳p的指標    小心指的物件會在SP刪除時消失
//swap(p, q)   對調彼此的指標
//p.swap(q)
//
//++--下面說過了
//
//
//p = q  遞減p的參考計數   遞增q   p降到0則刪
//
//
//shared_ptr<Foo> factory(T args) {
//	
//	//...
//	
//	return make_shared<Foo>(args);
//}
//
//void use_factory(T args) {
//	shared_ptr<Foo> p = factory(arg);
//	//...
//}//結束時 p 自動釋放 > SP的好用的地方 不會怕忘記delete

//但shared_ptr要小心存到容器之後  沒用到時要記得erase


//但假如又return p  就會等取得p的地方用完才會再釋放




////451  smart pointer 簡稱SP
//shared_ptr 是template
//
//shared_ptr<string> p1   預設初始化的 SP 為null指標
//
//if(p1/*測試非null*/ && p1->empty())
//	*p1 = "a";
//
//使用動態記憶體 最安全是  呼叫 make_shared
//
//shared_ptr<int> p = make_shared<int>(42); //指向值為42的 int
//shared_ptr<string> p = make_shared<string >(10, '9'); //9999999999
//shared_ptr<int> p = make_shared<int>(); //0
//make_shared 引數  也是建構器的引數同emplace
//
//用auto接shared_ptr<int>  更方便
//
//拷貝 或  指定 或 以值傳入函數  以值回傳  shared_ptr  內部機制都會計數 +1  計數器  稱 reference count 參考計數
//摧毀時 -1   例如變數離開scope
//歸0時  會自動釋放他管理的物件  利用解構器 destructor
//
//shared_ptr<int> p = make_shared<int>(42); //指向值為42的 int
//auto q(p)  //copy   有兩個指標指向相同物件
//
//
//shared_ptr<T>
//unique_ptr<T>
//p
//*p
//p->mem
//p.get()
//swap(p, q)
//p.swap(q)
//
//
//shared_ptr<int> p = make_shared<int>(42); //指向值為42的 int
//p = c;  歸0  釋放





//450
//
//靜態記憶體 static  用於 static物件 成員 任何函式外的變數
//堆疊記憶體 stack        函式內的非static物件      
//兩者的物件由編譯器自動創建和摧毀      存活週期  跟一般觀念相同
//
//除此這兩個  還有集區pool記憶體可以用      稱作  自由存放區free store 或 heap堆積
//用於  動態run time 配置的物件  由程式控制生命週期   要明確摧毀
//
//動態記憶體  與 智慧指標
//
//new 在動態記憶體 配置 並選擇性初始化一個物件  並回傳指向該物件的一個指標
//delete 摧毀該物件  並釋放關聯的記憶體
//
//智慧指標 smart pointer    重點在  會在沒用到時自動刪除 
//shared_ptr  允許多個指標指向相同物件
//unique_ptr  擁有他指的物件
//weak_ptr 指向一個shared_ptr管理的物件    都在<memory>




//446
//
//宣告multiset
//using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>
//SD_multiset bookstore(42/*這個是有點怪  竟然是貯體大小  跟函式宣告不同*/, hasher, eqOp);


//// unordered_map version of the word count program
//int main()
//{
//	// count occurrences, but the words won't be in alphabetical order
//	unordered_map<string, size_t> word_count;
//	string word;
//	while (cin >> word)
//		++word_count[word]; // fetch and increment the counter for word
//
//	for (const auto &w : word_count) // for each element in the map
//		// print the results
//		cout << w.first << " occurs " << w.second
//		<< ((w.second > 1) ? " times" : " time") << endl;
//
//	return 0;
//}
//
//// how to override default hash and equality operator on key_type
//size_t hasher(const Sales_data &sd)
//{
//	return hash<string>()(sd.isbn());//
//}
//bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
//{
//	return lhs.isbn() == rhs.isbn();
//}


//444  5
//unorder 四種 無序 不用比較運算子 組織元素   而是用hash function
//
//使用時機   元素間沒有明顯順序  或 維護順序的成本很高
//
//hash要設計好   才能得到好的平均效能
//不然一般   用有序容器比較容易  經常效能也比較好
//
//也有 find insert等
//
//無序 for印出值  就也是無序的
//
//無序容器  透過 hash function 把元素hash value雜湊值  相同的對應至 bucket(貯體)
//
//所以效能和hash function的品質  貯體數量  大小
//
//hash func每次計算的值要相同
//
//c.
//bucket_count
//max_bucket_count
//bucket_size(n)
//bucket_size()
//
//local_iterator
//const_local_iterator
//
// begin end
//
//load_factor
//max_load_factor     有需要再回來查
//
//rehash  reserve




//441 2 3
//
//map<string, string> buildMap(ifstream &map_file)
//{
//	map<string, string> trans_map;   // holds the transformations
//	string key;    // a word to transform
//	string value;  // phrase to use instead
//	// read the first word into key and the rest of the line into value
//	while (map_file >> key && getline(map_file, value))
//		if (value.size() > 1) // check that there is a transformation
//			trans_map[key] = value.substr(1); // skip leading space 
//		else
//			throw runtime_error("no rule for " + key);
//	return trans_map;
//}
//
//const string &
//transform(const string &s, const map<string, string> &m)
//{
//	// the actual map work; this part is the heart of the program
//	auto map_it = m.find(s);
//	// if this word is in the transformation map
//	if (map_it != m.cend())
//		return map_it->second; // use the replacement word
//	else
//		return s;              // otherwise return the original unchanged
//}
//
//// first argument is the transformations file; 
//// second is file to transform
//void word_transform(ifstream &map_file, ifstream &input)
//{
//	auto trans_map = buildMap(map_file); // store the transformations
//
//	// for debugging purposes print the map after its built
//	cout << "Here is our transformation map: \n\n";
//	for (auto entry : trans_map)
//		cout << "key: " << entry.first
//		<< "\tvalue: " << entry.second << endl;
//	cout << "\n\n";
//
//	// do the transformation of the given text 
//	string text;                    // hold each line from the input
//	while (getline(input, text)) {  // read a line of input
//		istringstream stream(text); // read each word 
//		string word;
//		bool firstword = true;      // controls whether a space is printed 
//		while (stream >> word) {
//			if (firstword)
//				firstword = false;
//			else
//				cout << " ";  // print a space between words
//			// transform returns its first argument or its transformation 
//			cout << transform(word, trans_map); // print the output 
//		}
//		cout << endl;        // done with this line of input
//	}
//}
//
//int main(int argc, char **argv)
//{
//	// open and check both files
//	if (argc != 3)
//		throw runtime_error("wrong number of arguments");
//
//	ifstream map_file(argv[1]); // open transformation file 
//	if (!map_file)              // check that open succeeded
//		throw runtime_error("no transformation file");
//
//	ifstream input(argv[2]);    // open file of text to transform
//	if (!input)                 // check that open succeeded
//		throw runtime_error("no input file");
//
//	word_transform(map_file, input);
//
//	return 0;  // exiting main will automatically close the files
//}


//437 8 9 40

//set<int> = set;
//set.find(1)
//set.count(1)
//
//如果想要鍵值不在  也不新增  可以先用find檢驗
//if (w.find("val") == w.end())
//	cout << "not exists" << endl; 
//
//
//multi set map   是有序的  所以鍵值相同的會相鄰
//
//
//c.
//lower_bound(k)  //回傳第一個鍵值 >=k 的iter
//upper_bound(k) //回傳第一個鍵值  >k 的iter
//equal_range(k) //               =k   的一對起迄iter   無元素 兩個都end
//
//
//找出相同作者的
//
//法一
//string search_item("alain bottn")
//auto entries = authors.count(search_item)
//auto iter = authors.find(search_item)
//while (entries)
//{
//	cout << iter->second << endl;
//	++iter 
//	--entries //靠數量 + iter
//}
//
//法2
//for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
//{
//	cout << beg->second << endl;
//}
//
//法3
//for (auto pos = authors.equal_range(search_item); beg != end; ++beg)
//{
//	cout << pos.first->second << endl;
//}



//435  6
//map unordered_map 有 下標運算子  (不存在新增)  和 at函式(不存在出out of range)    都接受key  取得value  
//(set沒有一對值所以不用用key取val所以沒這類運算)
//
//如果key不存在 map新增後回傳的是mapped_type  即是 pair
//如果key存在 map新增後回傳的是value_type
//
//想知道一個key在不在  最好是用find    count在multi類的  要計算比較多 




//434
//
//multimap set insert後  只回傳迭代器  指向新插入的元素  因為允許多個 不需判斷已存在
//multimap<string, int> authors;
//authors.insert("A", "B")
//authors.insert("A", "C")   可允許同鍵多筆
//
//用key erase   回傳多少元素被移除了
//if (w.erase(word))
//	cout << "ok" << endl; 
//else
//	cout << "not found" << endl;
//
//erase(val)
//erase(iter)  回傳iter後的元素
//erase(b, e)



//431  2 3
//
//
////set
//vector<int> ivec = {2,3,4}
//set<int> set2;
//set2.insert(ivec.cb, ivec.end)
//set2.insert({1,2,3,1,2,3})     //insert時   重複的都只進一個  
//
//
////map   insert psir
//w.insert({"s","d"})  //其他pair語法都可  make_pair(a,b)  pair<c,d>(a,b)   pair<c,d>::value_type(word, 1)
//
//c
//.insert(v) //value_type
//.emplace(args) //同建構式
//insert(b,e)
//insert(il)//串列
//insert(p, v)     // p迭代器  告知要哪裡找新元素的地方
//emplace(p, v)

//這邊動作完都是回傳 迭代器  指向新插入的元素 


//insert回傳值    對於唯一 鍵的容器   回傳一個pair   first 迭代器  指向新插入的元素  second 是否是   插入true  或已存在false
//
//用  insert iter 改寫420
//
//map<string, size_t> word_count; // empty map from string to size_t
//string word;
//while (cin >> word)
//{
//	auto ret = word_count.insert({ "a", 3 })
//		if (!ret.second)
//			++ret.first->second;// first是insert map後的iter元素   map的元素是pair  所以second就是value計數  
//}
//	++word_count[word];  //遞增word計數器  不存在會創建並值初始化為0
//
//for (const auto &w : word_count)
//	cout << w.first << " occurs " << w.second << " times" << endl;//first key   second value




////429  30
//
//set map的鍵值 都是const
//
//key_type   set map的鍵值type
//value_type   map的val type
//mapped_type  set來說就key_type  map是pair<const key_type, mapped_type>
//
//型別成員一樣用 map<string, int>::key_type 類似寫法
//
//關聯式容器的  迭代器
//auto map_it = word_cou.begin();
////*map_it 會是 pair<const key_type, mapped_type>
//cout << map_it -> first << endl; 
//++map_it->second;
//
//set 的iterator 或 const_oterator 都唯讀
//
//set<int> iset = {1,2,3}
//set<int>::iterator set_it = iset.begin();
//if (set_it != iset.end()) {
//	cout << *set_it++ << endl;    
//}
//
//auto map_it = w.cbegin()
//while (map_it != w.cend())
//{
//	cout << map_it -> first + " " + map_it->second << endl; 
//}
//
//一般 演算法不會用 關聯式容器
//find也是用內建的比較快
//有的有用例如  copy 一個關容器  到另一個
//或者  inserter關連到 關容器  可以有其他用途


//427 428


//p1 == p2 是字典比較   他有寫一個很複雜的無喇直接感覺合理 先不管  !(p2.first < p1.first)
//
//<utility> 的 pair 就是一對值  也是tempalte
//pair<string, size_t> word_count; //會值初始化   也可以串列初始  word{"a", 3}

// p(v1, v2)     p = { v1, v2 }   make_pair(v1, v2) 這種寫法能用大括號取代同義

//
//pair<string, string >  F(vector<string> v) {   回傳pair
//	if (!v.empty())
//		return { v.back(), "t" }
//	else
//		return pair<string, string >();
//}




//423   4  5 6
//關聯式容器支援9.2通用容器運算   不支援位置運算(而是用key)
//無序容器 提供調整hash效能的運算
//迭代器是雙向的
//
//
//map set 鍵值型別     必須要有 < 運算子  在程式庫知道  就比較好分析民眾問題
//	而且小於   嚴格的遞減     嚴格的弱次序    書上寫了一些很數學的描述 a> b則 b不< a  a <= b b<=a 推得 a==b  之類的
//
//鍵值型別  使用自訂的  比較函式  如下例
//
//bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
//	return lhs.isbn() < rhs.isbn()
//}
//
////這是一行   加註解才斷行
//multiset<Sales_data, decltype(compareIsbn)*> //指向compareIsbn的函式指標型別  記得*
//								bookstore(compareIsbn);//可省略&  因為函式名稱需要時  會自動轉為一個指標




//
//set<string> exclude = { "The", "But", "And", "Or", "An", "A",
//					   "the", "but", "and", "or", "an", "a" };
//map<string, string> exclude = { {"The", "But"},
//								{"And", "Or"},
//								{"An", "A"},  
//					   };
//初始器裡的值必須能   轉換至 set map值型別
//
//vector<int> ivec;
//for (vector<int>::size_type i = 0; i != 10; ++i) {
//	ivec.push_back(i);
//	ivec.push_back(i);  // duplicate copies of each number
//}
//
//// iset holds unique elements from ivec; miset holds all 20 elements
//
//set<int> iset(ivec.cbegin(), ivec.cend());
//multiset<int> miset(ivec.cbegin(), ivec.cend());   //1~10重複兩次
//
//cout << ivec.size() << endl;    // prints 20
//cout << iset.size() << endl;    // prints 10  自動去掉重複的         
//cout << miset.size() << endl;   // prints 20  multi沒有去掉重複的
//





//422
//
//map<string, size_t> word_count; // empty map from string to size_t
//
//set<string> exclude = { "The", "But", "And", "Or", "An", "A",
//					   "the", "but", "and", "or", "an", "a" };
//
//while(cin >> word )
//	if(exclude.find(word) == exclude.end()) // set  全key 用 find == end
//		  ++word_count[word];


////420 1
//關聯式容器 associative-container    透過鍵值高速查找取回
//
//map : key-value pair
//set : key
//
//map set                //有序的             
//multimap multiset      //key可相同多個
//unordered_map unordered_set //hash 組織的
//unordered_multimap unordered_multiset  // hash + multi
//
//
//map<keyType, valueType>     map也是模板template  (C#的泛型)
//
//
//// count the number of times each word occurs in the input
//map<string, size_t> word_count; // empty map from string to size_t
//string word;
//while (cin >> word)
//	++word_count[word];  //遞增word計數器  不存在會創建並值初始化為0
//
//for (const auto &w : word_count)
//	cout << w.first << " occurs " << w.second << " times" << endl;//first key   second value



//415 6
//list  forward_list  自定義數個演算法 sort merge remove reverse unique
//用內建的  會比泛用的 效能更好
//內建的會調換swap元素    而非元素的值  所以會更快
//
//l.
//merge(l2)
//merge(l2, comp2)  //會排序   完成後l2會是空的
//remove(val) //底層呼叫erase
//remove_if(pred) //erase
//reverse()
//sort   //<
//sort(compare)
//unique
//unique(pred)
//
//splice是串列專屬的
//
//l.splice() splice_after()
//
//(p, l2)       //l2 移到 l 的p之前/後的位置
//(p, l2, p2)   //p2 為l2的迭代器  p2移到l  或p2緊接後的到l  兩者可以是同個串列
//(p, l2, b,e)  //be 為l2 的範圍  移動範圍  兩者可同串列  但p不可在範圍
//
//串列的運算確實會改變容器內的元素  相對於泛用版本不會


//414  演算法慣例
//有 < > 功能的  通常有一個重載版本是  接受一個predicate的判斷式`
//
//unique(b, e) // ==
//unique(b, e, compare/*predicate*/) 
//find(b, e. val)
//find_if(b, e, predicate/*為ture的*/)
//
//reverse(b, e)
//reverse_copy(b, e, dest)
//
//
//remove_if(b, e, [](int i) { reutrn i%2})
//remove_copy_if(b, e, back_inserter(v2),[](int i) { reutrn i % 2})

//411  13
//
////輸入      input          == != ++ * ->    find accumulate
////正向      forward        同上 + 多次讀寫相同元素 replace    forward_list上的iter
////雙向      bidirectional  同上 --  除forward_list之外的容器都是
////隨機存取  rrandom-access  < <= > >=  += -= -距離   下標運算子[i]   sort   array deque vector
//
//algo參數模式
//
//alg(b, e, args)
//alg(b, e, dest, args)
//alg(b, e, b2, args)
//alg(b, e, b2, e2, args)




////410
//
//相對於 401  的另一種  五種迭代器 分類法
//
//輸入      input        讀取 不寫入 單回  遞增
//輸出      output      寫入  不讀取  單回  遞增
//正向      forward        讀寫  多回  遞增
//雙向      bidirectional  讀寫  多回  遞增減
//隨機存取  rrandom-access  讀寫  多回  完整算術
//
//
//ostream_iterator  遞增 解參考  指定
//vector string deque 遞增 解參考  指定 遞減 關係  運算子
//
//除輸出   其他四種 有功能上包下的關係
//
//find 輸入
//replace 一對 正向  
//reaplce_copy 一對 正向 一個輸出







//407

//反向迭代器  reverse iterator
//
//++往前  --往後
//begin最後  end最前面再往前一個
//
//用法差不多
//
//用 v.rbegin rend crbegin crend
//
//例如說 sort(v.b, v.e)    //  大 -> 小
//例如說 sort(v.rb, v.re)  //反向排序  小-> 大
//
//
//auto comma = find(line.cb, line.ce, ',')    //找第一個字
//auto comma = find(line.crb, line.cre, ',')  //找最後一個字
//
//對於  FIRST, SECOND, THIRD  用r找到最後,
//
//印 cout << string(line.crb, comma) << endl; 會變  DRIHT
//所以要  string(comma.base()/*往後位置指一個 是一般迭代器*/, line.end())  就會印出 THIRD
//

//406
//
//用 i ostream_iterator 改寫  1.6 程式
//
//#include <iterator>
//using std::istream_iterator; using std::ostream_iterator;
//
//#include <iostream>
//using std::cin; using std::cout;
//
//#include "Sales_item.h"
//
//int main()
//{
//	// iterators that can read and write Sales_items
//	istream_iterator<Sales_item> item_iter(cin), eof;
//	ostream_iterator<Sales_item> out_iter(cout, "\n");
//
//	// store the first transaction in sum and read the next record
//	Sales_item sum = *item_iter++;
//
//	while (item_iter != eof) {
//		// if the current transaction (which is in item_iter) 
//		// has the same ISBN
//		if (item_iter->isbn() == sum.isbn())
//			sum += *item_iter++; // add it to sum 
//								 // and read the next transaction
//		else {
//			out_iter = sum;      // write the current sum
//			sum = *item_iter++;  // read the next transaction
//		}
//	}
//	out_iter = sum;  // remember to print the last set of records
//
//	return 0;
//}
//
//


//405
////istream_iterator 
//有 lazy evaluation 允許延遲讀取
//
//ostream_iterator<T> out(os)
//ostream_iterator<T> out(os, val)  //每次輸出的文字後面都會加 val
//
//ostream_iterator<int> outit(cout, " ");
//for (auto e : vec)
//	*outit++ = e; //e寫到cout
//cout << endl;
//
//for (auto e : vec)
//	outit = e; //對o來說  * 跟++ 可省略 無用 同意
//cout << endl;
//
//
//更簡
//
//copy(vec.begin(), vec.end(), out_iter);





//403 4

//istream_iterator 
//o                 用在IO讀寫
//
//istream_iterator<int> int_it(cin)  //從cin讀
//istream_iterator<int> int_eof  //空表eof
//ifstream in("file") 
//ifstream_iterator str_it(in)//檔案牘
//
//while (in_it != int_eof)
//{
//	v.push_back(*in_it++)  持續讀取 儲存到v注意有++
//}
//
//上面等同更簡潔的語法
//istream_iterator<int> int_it(cin), eof
//vector<int> vec(in_it, eof) //迭代器範圍件購
//
//in1 == in2   繫結到相同資料留就相等
//!
//*in1 讀取
//in1->mem(*in).mem
//++  等於用 >> 讀取下個值
//
//也可用在演算法
//cout << accumulate(int_it, eof, 0) << endl; 
//就會印出 所有輸入的 加總



//402
//insert iter   inserter 是種迭代器轉接器  三種
//back_inserter  用 push_back            後
//fornt ""               front     插到最前面
//inserter          insert  插到迭代器表示的元素前
//
//用 it = t 就會作上三種插入的動作
//
//ex it 是 inserter(c, iter)
//
//*it = val 相當於
//
//it = c.insert(it, val);
//++it;  //  插入到之前  再把指標往前移回原本的位置
//
//
//List<int> l = {1,2,3,4}
//copy(l.cb, l.ce, front_inserter(l2))  //4321
//copy(l.cb, l.ce, inserter(l2))     //1234
//
//
//401
//
//舊的 C++ 的 bind 用 bind1st, bind2nd
//
//四種   迭代器           iterator
//插入          insert             繫結到容器 可插入 
//資料流        stream             繫結I O 資料流
//反向          reverse            往回移動 非前進  容器除forward_list都有
//移動          move               



//
////400
//sort(w.b, w.e, isShorter);				//
//sort(w.b, w.e, bind(isShorter, _2, _1); // 1 2 倒過來 就可以反轉順序
//
//bind 會拷貝引數  如果要傳參考  要特別寫ref
//
//ostream &print(ostream &os, const string &s, char c) {
//	return os << s << c;
//}
//
//for_each(w.b, w.e, bind(print, ref(os), _1, '' ))//加 ref 
//
//cref 則是 const 的參考


//397 9
//lambda適合少量地方使用   常用還是寫成func
//
//bind
//定義在 <functional>
//接受一個可呼叫物件  並產生一個新callable 轉接原物件的參數列
//auto newCallable = bind(callable, arg_list)
//
//arg_list可以包含 _n   _1 _2 _3 ...
//會為將來傳入的引數佔位置
//                             //字串, 長度
//auto check6 = bind(check_size, _1, 6)
//
//bool b - check6(str)
//
//
//auto wc = find_if(w.b, w.e, [sz](const string &a))
//同義於
//auto wc = find_if(w.b, w.e, bind(check_size, _1, sz))
//                                            //str                                
//
//placeholder
//using std::placeholder::_1  _2....
//乾脆直接
//using std::placeholder
//就可以 _1  _2 ...
//
//
//_2 _1的順序如果交換   那相當於原傳入參數的順序會依照 _1 _2的擺放順序跟著對應   跟C# Strin.Format差不多意思
//
//f(a,b,_2,c,_1)
//g(X,Y)  傳入到f
//相當於
//f(a,b,Y,c,X)



//395
//
//預設lambda不能改變  []裡 值拷貝的變數值  要改變用mutable  >>>不能省略()
//
////auto f = [v] () mutable {return v++; };
//
//如果是capture by ref  那就看參考所指的 是不是const 決定能不能修改
//
//396 回傳型別  下面有寫過了


//392  4
//定義了一個Lamba  編譯器會產生新的無名類別 對應   14.8
//並且以物件傳給函式
//變數會對應於類別的資料成員
//
//
//size_t v = 3;
//auto f = [v] {return v; }//capture by value
//
//size_t v = 3;
//auto f = [&v] {return v; }//capture by reference
////要小心使用時  參考還在   例如區域變數使用完可能就消失了
//
//ex
//
//biggies(&os = cout, cahr c = '')  !! &os
//	for_each(words.begin(), words.end(), [](const string &os, c) {os << s << endl;  }

//可以從函式回傳一個lambda  也就是個可呼叫物件   那lambda必定不能有參考捕捉  就跟不能回傳區域變數參考理由一樣


//隱含捕捉  省打字用的吧  可讀性低
//[]裡面只放 & 或 =  會自動去推斷可能的外層的變數值 或參考  

//biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = '')
//	for_each(words.begin(), words.end(), [&, c](const string &s) {cout << s << endl;  }
//	for_each(words.begin(), words.end(), [=, &os](const string &s) {cout << s << endl;  }
//	 



//391
//
//for_each(words.begin(), words.end(), [](const string &s) {cout << s << endl;  }
//
//biggies(vector<string> &words, vector<string>::size_type sz)
//{
//	elimDups(words); // put words in alphabetical order and remove duplicates
//	// sort words by size, but maintain alphabetical order for words of the same size
//	stable_sort(words.begin(), words.end(),
//		[](const string &a, const string &b)
//	{ return a.size() < b.size(); });
//
//	// get an iterator to the first element whose size() is >= sz
//	auto wc = find_if(words.begin(), words.end(),
//		[sz](const string &a)
//	{ return a.size() >= sz; });
//
//	// compute the number of elements with size >= sz 
//	auto count = words.end() - wc;
//	cout << count << " " << make_plural(count, "word", "s")
//		<< " of length " << sz << " or longer" << endl;
//
//	// print words of the given size or longer, each one followed by a space
//	for_each(wc, words.end(),
//		[](const string &s) {cout << s << " "; });
//	cout << endl;
//}





//390
//要使用區域變數  放在捕捉串列

//int sz = 42;
//auto f = [sz] (const string &s1){return s1.size()  >= sz; };//有引數

//而不能不放在[]  就在{}使用

//auto wc = find_if(w.b, w.e, [sz] (const string &s1){return s1.size()  >= sz; }) 



//388 9
//find_if接受  單元判斷式
//
//如果要找 長度大於常數大小   就需要 string  和大小兩個參數
//
//可以轉成Lambda去傳入
//
//我們可傳入任何種類的callable object 給演算法    其實就是函數的意思  e是callable  就可以寫成e(args)
//
//callable 有   函式   函式指標    重載了函式呼叫運算子的類別  Lambda expression運算式
//
//Lambda expression運算式  可想成   無名的 inline函式
//
//Lambda 可以被定義在函式裡
//
//[capture list](parameter list) -> return type{ function body }
//
//參數列  回傳型別  可省略
//
//auto f = [] {return 42; };//ex   無引數
//
//cout << f() << endl; 
//
//只有一句return 回傳型別會自動推論  有其他述句  會被視為void  
//p396才繼續提到  多句最後一句return 就要指定 ->回傳型別   來讓Lambda知道回傳類型
//
//auto f = [] (const string &s1, const string &s2){return s1.size() < s2.size(); };//有引數
//
//stable_sort(w.b, w.e, [](onst string &s1, const string &s2) {return s1.size() < s2.size(); });







//385 7
//用自訂運算 取代 > < == 等等
//
//傳遞函式給演算法  predicate
//
//演算法使用 單元/二元判斷式     unary   binary
//
//接受 二元判斷式 的sort 可給自訂
//
//
//// comparison function to be used to sort by word length
//bool isShorter(const string &s1, const string &s2)
//{
//	return s1.size() < s2.size();
//}
//
//// sort by length using a function
//elimDups(words)//有用字母排序
//stable_sort(words.begin(), words.end(), isShorter);   //長度相同的字詞間維持字母順序  stable意義
//print(words);
//
//words = cpy; // return to the original data                  
//// sort the original input on word length, shortest to longest
//sort(words.begin(), words.end(), isShorter);                                   //依照長度排序  由短到長





//384
//void elimDups(vector<string> &words)
//{
//	// sort words alphabetically so we can find the duplicates
//	sort(words.begin(), words.end());
//	for_each(words.begin(), words.end(),
//		[](const string &s) { cout << s << " "; });
//	cout << endl;
//
//
//	// unique reorders the input so that each word appears once in the
//	// front part of the range   把不重複的字放到最前面  消除相鄰的重複項(因為排序過了)    後面不確定是什麼值 
//	// returns an iterator one past the unique range
//	auto end_unique = unique(words.begin(), words.end());
//	for_each(words.begin(), words.end(),
//		[](const string &s) { cout << s << " "; });
//	cout << endl;
//
//	// erase uses a vector operation to remove the nonunique elements
//	words.erase(end_unique, words.end());   //清除重複的
//	for_each(words.begin(), words.end(),  
//		[](const string &s) { cout << s << " "; });
//	cout << endl;
//}





//382 3
//如果使用的是  insert iterator  就可以新增院速到容器

//vector<int> v;
//auto it = back_inserter(v);//取得可insert的iter
//*it = 42 //這樣賦值就會執行新增
//
//int a = { 1,2,3 };
//int a2[sizeof(a)/sizeof(*a1)]//a2大小同a
//copy(begin(a), end(a), a2);//a拷貝到a2  兩者值相同
//
//copy回傳拷貝到a2最後一個元素的地方  
//
//
//replace(a.begin(), a.end(), 0, 42);//0 -> 42
//
//replace_copy(a.begin(), a.end(), back_inserter(vec), 0, 42);// a copy 到 vec 且 vec 的 0 -> 42
//

//381  會寫入容器元素的演算法  是改變元素的值  但演算法不會作榮器運算  所以不會改變容器大小

//ex
//fill(vec.cbegin(), vec.cend(), 0); //全設為0
//
//fill_n(vec.cbegin(), j, 0); //往後寫j個0
//演算法不會幫忙檢查iter有沒有在容器範圍   超出的話結果是未定義的





//379 80 ======= 唯讀演算法  =========
//最好可搭配 cbegin cend
//
//ex  accumulate 逐一累加
//
//vector<int> vec(10);              // default initialized to 0
//fill(vec.begin(), vec.end(), 1);  // reset each element to 1
//
//// sum the elements in vec starting the summation with the value 0
//
//// !!  起   迄   初始值
//
//int sum = accumulate(vec.cbegin(), vec.cend(), 0);
//cout << sum << endl;
//
//// set a subsequence of the container to 10
//fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
//cout << accumulate(vec.begin(), vec.end(), 0) << endl;
//
//
//// roster2 should have at least as many elements as roster1
//equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
//
//起1 , 迄1,  起2   (假設迄2起2間距等於1的)






//377 78
//迭代器   讓演算法獨立於容器
//但確實依存於元素型別的運算   ex == < > 
//演算法以迭代器運算   而非藉由容器運算
//
//程式庫100多個演算法  在附錄A
//
//唯讀演算法
//會寫入元素的演算法
//重新排序的演算法




//376  泛用演算法
//algorithm.h
//對一個泛為作用 而非整個容器  
//

//舉例  find
//#include <algorithm>
//using std::find;
//
//#include <iterator>
//using std::begin; using std::end;
//
//#include <vector>
//using std::vector;
//
//#include <list>
//using std::list;
//
//#include <string>
//using std::string;
//
//#include <iostream>
//using std::cout; using std::endl;
//
//int main()
//{
//	int ia[] = { 27, 210, 12, 47, 109, 83 };
//	int val = 83;
//	int* result = find(begin(ia), end(ia), val);
//	cout << "The value " << val
//		<< (result == end(ia)                                  !!!!! end判斷有無找到
//			? " is not present" : " is present") << endl;
//
//	// search starting from ia[1] up to but not including ia[4]
//	result = find(ia + 1, ia + 4, val);
//
//	// initialize the vector with some values
//#ifdef LIST_INIT
//	vector<int> vec = { 27, 210, 12, 47, 109, 83 };
//#else
//	int temp[] = { 27, 210, 12, 47, 109, 83 };
//	vector<int> vec(begin(temp), end(temp));
//#endif
//	val = 42; // value we'll look for
//
//	// result2 will denote the element we want if it's in vec, 
//	// or vec.cend() if not
//	auto result2 = find(vec.cbegin(), vec.cend(), val);
//
//	// report the result
//	cout << "The value " << val
//		<< (result2 == vec.cend()
//			? " is not present" : " is present") << endl;
//
//	// now use find to look in a list of strings
//#ifdef LIST_INIT
//	list<string> lst = { "val1", "val2", "val3" };
//#else
//	string temp2[] = { "val1", "val2", "val3" };
//	list<string> lst(begin(temp2), end(temp2));
//#endif
//
//	string sval = "a value";  // value we'll look for
//	// this call to find looks through string elements in a list
//	auto result3 = find(lst.cbegin(), lst.cend(), sval);
//	cout << "The value " << sval
//		<< (result3 == lst.cend()
//			? " is not present" : " is present") << endl;
//
//	return 0;




//371
//用轉接器  不能使用底層的容器運算 要透過外包的轉接器的運算去操作底層

//queue priorityQ
//pop()
//front()
//back top push emplace
//
//
//Q FIFO
//Priori Q  新增的元素  優先高的放在優先低的之前




////369  70 容器轉接器
//stack queue priority_queue
//stack接受循序容器   除了array forward_list 因為要增刪
//
//容器轉接器  共通運算型別
//size_type  value_type container_type(轉接器實做的底層容器型別)
//A a;
//A a(c);
//a.empty()
//a.size()
//swap(a, b)
//a.swap(b)
//
//stack<int> stk(deq)  // 將deq的元素拷貝到stk
//預設 stack q 都用 deque來實作的
//priority_queue則是在vector上實作的
//
//要換容器   給第二引數
//stack<string, vector<string>> str_stk
//stack<string, vector<string>> str_stk(vec)
//
//stack要 push_back pop_back back  > 任何容器
//queeue push_back back front push_front  > list 或 deque
//priorty queue    push_back back front push_front 要隨機存取   > vector 或 deque  不能list
//
////////////
//
//stack<int> intStack;  // empty stack
//
//	// fill up the stack
//for (size_t ix = 0; ix != 10; ++ix)
//intStack.push(ix);   // intStack holds 0 . . . 9 inclusive
//
//// while there are still values in intStack
//while (!intStack.empty()) {
//	int value = intStack.top();
//	// code that uses value
//	cout << value << endl;
//	intStack.pop(); // pop the top element, and repeat
//}
//
//stack:  
//pop 
//push(item) emplace(args)
//top


//368
//to_string  數字>文字
//stoi
//stol
//stoul
//stoll
//stoull
//stof
//stod
//stold
//參數s ,p對size_t的一個指標 ,b數值基數
//s可以代正負號


////364 6
//string 六個搜尋函數  有分大小寫
//找到的話  回傳 string::size_type  符合處的索引
//沒有  回傳static string::npos  是const string::size_type  以-1初始 但unsigned 所以是string最大可能大小
//
//auto  pos = str.find("abc")
//
//find  
//rfind  最後一個出現處
//find_first_of          args任一字元第   一個出現處
//find_last_of           args       最後
//find_first_not_of  不在           第  
//find_last_of       不在           最後  
//
//如果是args, pos   就從pos之後開始找起   while持續找的話 記得pos++
//
//compare 類似 C strcmp  回傳   0 +值 -值  對應 = > <
//s2
//pos1 n1 s2
//pos1 n1 s2 pos2 n2
//
//cp
//pos1 n1 cp
//pos1 n1  cp n2




//363
//
//insert 在pos前插入args   回傳指向插入的第一個字元的 迭代器/參考
//erease pos ~尾端 或pos+len
//assign 取代整個內容
//append 附加尾端
//replace 
//
//接收參數  
//
//str   
//str pos len
//cp len
//cp
//n c
//begin end
//詳細列表需要再查



//362
//
//string支援前面提過的 assign insert erase    用法同前
//s.insert(s.size(), 5, '!');//結尾插入5個!
//s.erase(s.size() - 5, 5);//移除最後五字元
//
//額外支援 C style字元陣列   insert assign
//const char *cp = "Stately, plump Buck"
//s.assign(cp, 7) // "Stately"
//s.insert(s.size(), cp + 7) //拷貝超過前7的字元 直到null 
//
//s.insert(s.size(), "abc");//尾端插入abc
//s.insert(0, s2, 0, s2.size())//插入 s2 從 s2[0] ~ s2[0 + size] 到 s2之前
//
//s.append(" 4th Ed.");  // 接到尾端
//
//s2.replace(11, 3, "5th") // 從11開始 消除三個字元  然後插入5th
//
//
//361
//
//string s  
//子字串
//s.substr(pos, n)//pos預設0   n不給就到最後  兩個都給 pos ~ pos + n


//360

//string 運算   
//string(char pointer(cp), n)//拷貝前n字
//string(s2, pos2) //從pos2開始的字元    pos2大於size為 未定義
//string(s2, pos2, len2)//pos2開始到len2的拷貝


//356~59
//同 C# vector string 通常會配置大於當下所需的能量
//比較能降低 一直配置mem的次數
//
//capacity 容器目前可放多少元素
//reserve 至少會配置 >= 請求的空間
//小於capacity會被忽略  因為沒更大
//
//新程式庫提供  shrink_to_fit 歸還不需要的記憶體
//
//可以用ls.capacity()  可以用ls.size()  來取得最薪值
//
//size capacity 
//0 0
//24 32 
//
//沒超過capacity  vector也不能增加空間配置

//每個實做都被要求push_back  要快   創建n元素的容器  必須要在O(n)完成




//355
//end  每次刷新  就能避免增刪的影響
//
//while (begin != v.end()) {
//	++begin;
//	begin = v.insert(begin, 42);
//	++begin;
//}


//353  開發時  最小化iter被要求有效的部分  
//並且在更改容器後 適當重新定位過相關iter
//auto prev  = ls.before_begin();
//auto curr  = ls.begin()
//while (it != ls.end()) {
//	if (*it % 2)
//		it = ls.insert(iter, *iter)  //複製目前元素
	  //it+=2;   //推進自己和新插入的
//	else
//		{
		//iter = iter.erase()   指到消除元素之後的元素  所以剛剛好不用特別處理
//       }
//}



//352
//除Array外 可resize
//list<int> ilist(10, 42) // 10個42
//ls.resize(15);//多增加5個0
//ls.resize(25, -1)//後面多一堆-1
//ls.resize(5)//清除後20個 留前5個

//增刪可能使iter無效
//
//vector string 如果有發生重新配置  插入點前的參考有效 之後無效
//
//對deque在中間新增 則所有 iter 參考 指標  都會無效
//在前後新增  iter會無效   但既有的 參考 指標  有效
//
//對list forward_list      iter 參考 指標  都有效




//351
//forward_list  的before_begin 是在第一個的更前一個位置  off-the-begining
//
//lst.
//before_begin()
//cbefore_begin()//const itr
//insert_after(iter, t)//在p之後 插入元素
//insert_after(iter, n個, t)   //回傳itr指向  最後一個插入的元素     p是off the end 則未定義
//insert_after(iter, begin, end)
//insert_after(iter, il大括號的元素集合)
//
//emplace_after(iter, args) //同上
//
//erase_after(iter)              //iter之後的被刪
//erase_after(begin, end)        //刪除 being ~ end 不包括end   

//已修正 0621
//prev = curr
//++curr

//auto prev  = ls.before_begin();
//auto curr  = ls.begin()
//while (it != ls.end()) {
//	if (*it % 2)
//		it = ls.erase_after(prev)  //是傳前一個進去 會刪掉後一個
//	else
//		{
		//prev = curr;   注意兩個都要移動
		//++curr;
//       }
//}





//350
//forward_list是 singly linked list
//a > b > c > d
//移除c 是要把 b 改成指向 d
//但單向llist 沒有簡單方法可以取得前置元素
//所以forw ls 新增移除   是更改在給定後的元素 的  做法
//所以她有一些特殊的操作方法
//insert_after
//emplace ""
//erase ""


//349
//c.
//pop_back()  //移除最後一個元素  c為空未定義   void
//pop_front() //    第
//erase(p)    //移除p  回傳iter指向被刪除元素後一個iter  如果p是off the end 則未定義
//erase(b, e) //   b~e                     最後一個
//clear()      //移除全部
//
//while (1ilist.empty()) {
//	process(ilist.front())
//	ilist.pop_Front()
//}
//
//while (it != ls.end()) {
//	if (*it % 2)
//		it = ls.erase(it)
//	else
//		++it;
//}



//347
//at 下標運算子 subscriptor operator  只對 string vector deque array有效
//back對 forward_list無效
//
//c.back() 回傳一個參考指向最後一個元素
//  front()               第
//c[n]     n要 < c.size()  否則未定義
//c.at(n)                   否則 out of range
//
//容器是const  就回傳const參考  不能改變值    不是const 回傳普通參考 可以改變值
//auto &v = c.back()//參考   變更會變更原物件值
//auto v2 = c.back()//拷貝  不影響原物件值


//346
//確認有存取到元素
//可以用if(!v.empty()) {
//	auto val = *c.begin(), val2 = c.front();//都是第一個值的copy
//
//	//forward_list的iter不能遞減
//	*(--last) //error
//	//forward_list沒有支援 .back()
//
//}
//
//對一個沒有指向元素的iter解參考  運算會是未定義的


//345
//
//insert回傳第一個的特性使得可以這樣寫達成無窮push_front
//
//list<string> ls;
//auto iter = ls.begin()
//while(cin >> word)
//	iter = ls.insert(iter, word) //等同push_front
//
//insert 是copy   emplace等同於建構子接受的參數  是建構
//emplace等於在使用建構子



//342 ~ 4
//除了 array forward_list 每個 循序容器string 也是  支援push_back 後插入
//list forward_list deque 支援 push_front  前插入
//
//void c.push_back
//c.emplace_back
//void c.push_front
//c.emplace_front
//迭代器指向新插入的元素  c.insert(p, t)  在iter p前插入
//c.emplace(p, args)  在iter p前插入
//
//迭代器指向新插入的第一個元素  c.insert(p, b, e)  在iter p前插入  b ~e
//迭代器指向新插入的第一個元素  c.insert(p, n, t)  在iter p前插入  n 個 t
//迭代器指向新插入的第一個元素  c.insert(p, il/*大括號串列*/)  在iter p前插入  il
//
//vec要push_front t 相當於 v.insert(v.begin(), t);





//340看
//max_size() 大於等於榮豈能包含的元素數
//(特例forward_list提供max_size empty 但沒size)
//== !=  所有元素相等  反之不相等
//< <= >= >    要有定義３叫運算子  才能真實比繳
//如果有包含關係  子集比較小
//沒有包含關係  就看第一個不相等元素之比較




////339
//array 之外的 swap 速度都很快 常數時間    元素不會互換   是換內部的資料結構
//所以迭帶器 參考指標  都仍有效
//所指的元素與對調前相同
//
//但在string 呼叫swap會導致無效
//
//
//array上swap 會實際調換元素 所以O(n)
//所以迭帶器 參考指標  都仍有效
//所指的元素與對調前相同  但是值換了
//
//最好是使用泛型版的swap


//338
//array<int, 10> a2 = { 0 };//10個0
//a2 = {0} //error不能這樣用
//a1 = a2 ok
//
//swap(c1, c2)
//c1.swap(c2)  互換比拷貝快
//assign的作用是 !!取代!!
//seq.assign(begin, end)   可型別相容  例子char* string   忘了再查
//seq.assign(i1)   以初始器串列i1的元素取代seq
//seq.assign(n, t)  n個t取代seq




////336
//Array宣告要同時指定 大小 和型別
//array<int, 42>
//array<string, 10>
//
////337
//array<int, 10>  a1  10個int
//array<int, 10>  a1 = {1,2,3,4,...,10 } 手動初始
//array<int, 10>  a1 = {1,2,3,4 } 後6 0
//
//array可以指定拷貝   []陣列不行


//334  335
//大多容器 預設建構器是空的   但array好像是固定大小的初始化好的元素
//要拷貝另個容器  可以直接拷貝  或用一對迭帶器表示的一個範圍
//直接拷貝 容器內元素型別要完全相同
//迭代器範圍拷貝  可以相容可轉型就好了   例如char*和string  就是  很清楚我省略舉例 需要再查
//這裡的操作  都是下面有列的

//copy it前的元素  不包括it 這就符合 end指向最後的下一個  end本身沒用
//deque<string> aList(bList.begin(), it)


//332  333 同之前vector說iter的觀念

//331 iterator一些操作 ++-- 相減diff 
//begin 第一元素  end 最後的往後一個的點




//330
//iterator   const_iterator
//size_type  difference_type
//value_type
//reference  const_reference
//C c;
//C c1(c2)
//C c1(begin, end)
//C c1 {a,b,c}
//
//c1 = c2
//c1 = {a,b,c}
//a.swap(b)
//swap(a, b)
//
//c.size()
//c.max_size()
//c.empty()  //是否無元素
//
//c.insert(args)
//c.emplace(inits)
//c.erase(args)
//c.clear()
//
//== != 
//< <= >= > 
//
//c.begin() c.end()
//c.cbegin() c.cend()
//
//reverse_iterator const_reverse_iterator
//c.rbegin()  c.rend()
//c.crbegin()  c.crend()

//327~9
//先中間新增  後續隨機存取
//先用list輸入完畢 再拷貝到vector隨機存取
//如果既隨機又中間插入  同時   因為不明顯哪個有優勢  可以list  forward list   vector deque 實際做效能測試
//
//vector<noEdfault> v(10, init) //元素沒初始器  後面有給初始器　　ok
//vector<noEdfault> v(10)  //err 元素沒初始器  不能直接用數字初始



//
//326
//container  
//循序容器 擺放順序依照放入順序       關聯式容器 key值存取
//
//
//循序容器 
//vector   大小可變  快速隨機存取 insert del 不在後端會慢
//deque  double end q   快速隨機存取 前後 ins del快
//list  doubly linked list  雙向循序存取 任一點ins del都快
//forward list   singly linked list   單向循序存取  任一點ins del都快   設計用意是希望筆的上最佳的手寫單向LinkedList 所以沒size運算
//其他類型size運算是常數時間
//array     大小固定 又和[]稍有不同  無法del ins 
//string     快速隨機存取  後端ins del快
//
//string vector 存放連續記憶體位置  可以直接 start + index*size計算元素位址
//
//優先
//沒特別理由 > vector
//很多小型元素  空間額外負擔有關係 > list forward_list
//隨機存取 > vector deque
//中間插入元素 list forward list
//前後插入元素 deque




//323  ostringstream   ex 想要format後輸出
//for (const auto &entry : people)
//{
//	ostringstream formatted, badNums;
//	for (const auto &nums : entry.phones)
//		if (!valid(nums)) badNums << " " << nums;
//		else formatted << " " << format(nums);
//	if (badNums.str().empty())
//		cout << entry.name << " " << formatted.str() << endl;
//	else
//		cerr << "input error: " << entry.name
//		<< " invalid number(s) " << badNums.str() << endl;
//}
//
//return 0;
//}




//321
//istringstream ostringstream stringstream  


//struct PersonInfo {
//	string name;
//	vector<string> phones;
//};
//
//int main()
//{
//	string line, word;
//	vector<PersonInfo> people;
//	istringstream record;
//	while (getline(cin, line))  !!!
//	{
//		PersonInfo info;
//
//		record.clear();
//		record.str(line);
//      //這兩句書寫  istringstream record(line); !!!

//		record >> info.name;
//		while (record >> word)   !!!
//			info.phones.push_back(word);
//		people.push_back(info);
//	}
//
//	for (auto &p : people)
//	{
//		std::cout << p.name << " ";
//		for (auto &s : p.phones)
//			std::cout << s << " ";
//		std::cout << std::endl;
//	}
//
//	return 0;
//}





//320
//會被截斷
//ofstream out("file")
//ofstream out("file",ofstream::out) 
//ofstream out("file",ofstream::out | ofstream::trunc)  //三個都隱含有  out + trunc 
//保留
//ofstream out("file",ofstream::app) 

//可以open close open close 每次open可獨立指定不同檔案 模式

//ex8.8
//ifstream input(argv[1]);
//ofstream output(argv[2], ofstream::app);
//
//Sales_data total;
//if (read(input, total))
//{
//	Sales_data trans;
//	while (read(input, trans))
//	{
//		if (total.isbn() == trans.isbn())
//			total.combine(trans);
//		else
//		{
//			print(output, total) << endl;
//			total = trans;
//			..........
//


//319  
//file mode
//in 輸入
//out 輸出
//app  寫入前移到尾端  沒trunc可指定     會被永遠開啟在輸出模式
//ate  開啟後移到尾端
//trunc  截斷檔案      out有指定才能設定
//binary  二進位模式作業


//預設用out開啟的檔案會被截斷   要保留 設app  則只能寫道尾端  如果再加in 就可讀寫
//ate binary可任意搭配




//317  8
//iostream& 的地方  可接受 fstream sstream  因為是父類
//
//ostream o;
//o.open(file);
//if(o) //多一層檢查成功比較穩   呼叫失敗的話 failbit會被設定

//不能重複open 錯誤 並設定failbit

//main 接收一個檔案清單    逐一處理
//for (auto p = argv + 1; p != argv + argc; ++p)
//{
//	istream input(p*);//創建intput並open
//	if (input) {
//		process(input)
//	}
//	else {
//		cerr << "couldn't open" << string(*p);
//	}
//}
//



//316
//資料流綁定  s.tie() 回傳目前被綁至的stream指標  空的話回傳null
//s.tie(s2)  s綁到s2

//
//ifstream 讀檔  ofstream寫檔
//
//可以用 << >> 讀寫檔案  可以getline 讀ifstream
//
//
//
//fstream f(fileName)   //會自動open
//fstream f(fileName, mode)
//f.open(filename)
//f.open(filename, mode)
//f.close()
//f.is_open()
//


//314
//關閉failbit badbit  其他不變
//cin.clear(ciin.rstd::istream& func(std::istream &is)


//ex8.1
//std::istream& func(std::istream &is)
//{
//	std::string buf;
//	while (is >> buf)
//		std::cout << buf << std::endl;
//	is.clear();//回傳前設定為有效
//	return is;
//}

//
//緩衝區被清掉的情況
//滿了     endl指定清除  unitbuf每次清除   cerr預設有unitbuf
//輸出資料流綁定到輸入時  輸入一讀 輸出會被清掉

//cout <<  << endl 尾端加newline清除 / flush 清除 / ends 尾端加null

//cout << unitbuff //立刻清掉
//
//cout << nounitbuff //恢復一般緩衝





//313
//istream::iostate
//istream::badbit
//s表任一strean名稱
//s:iostate
//s:badbit
//s:eofbit
//s:failbit
//s:goodbit
//s.eof()  / s.bad()  ...
//s.clear()
//s.clear(flags)
//s.setstate(flags)
//s.rdstate() // read state 讀目前狀態

//auto old_state = cin.rdstate();//紀錄當前狀態
//cin.clear() //使cin變有效
//process(cin) //使用cin
//cin.setstate(old_state)//恢復






//312
//
//cin >> i 如果輸入字元就會出錯  可以由狀態知道
//ex while (cin >> word)  truefalse判斷式
//
//狀態 iostate
//有四種iostate型別的constexpr值
//可以和位元運算子使用 以設定或測試多個旗標
//
//badbit   系統錯誤 無法再使用
//fallbit  如字元讀到int錯誤 可復原更正繼續使用
//檔案結尾 > eofbit 和 fallbit
//正確  值0 的 goodbit
//
//good以外的三種任一設定 資料流就失敗
//
//上面關鍵字去掉bit就是讀取狀態的方法了  bad fail ...




//310   IO  ch8
//istream ostream cin cout <<  << endl;  cerr  >>  << getline可以從istream讀一行到給定的string 
//wcin wcout wcerr

//主控台 檔案 字串
//istream ostream iostream   w
//ifstream ofstream fstream w
//istringstream ostringstream stringstream  w       寬字元用wchar_t

//他們繼承自 istream  ostream   所以都可以用在cin cout cerr   如果參數指標宣告成父類   子類也都可以適用

// io 物件 不能 拷貝 指定



//302 3 
//static成員不可在類別內初始化  要在外部初始化
//static成員只能被定義一次
//
//定義並初始化一個static成員
////double Account::interestRate - initRate()

//但  const static int這種就可以類別內初始化   並且是用constexpr的字面值型別初始
//static const int period = 30;// period is a constant expression


//如果像只在類別內使用static成員 如daliy_tbl  則period可不必在外部定義
//如果要在外部使用  需定義  因已初始化所以只須宣告不用初始
//constexpr int Account::period;

//static可以用一些一般屬性不能用的用法
//可以是不完整型別
//可以是型別本身 (一般只能型別本身的參考指標
//可以當成預設引數



//300 1 
//static  同C#    所有物件共用   也是直接用類別名稱::存取
// static 可為 public private const 參考陣列類別等
//  ex >　Account.h

//double d;
//d = Account::rate();    名稱存取

//Account a;
//Account *a2 = &a;
//d = a.rate();           物件存取   這邊就跟C#不同  C#不行這樣
//d = a2->rate();




//299
//字面值類別

//全部成員都是字面值型別
//至少有一個constexpr建構器
//類別內初始器有的話  都要是常數運算式  
//或有類別型別成員   初始器就要用自己的constexpr建構器
//類別必須為解構器使用預設定義  負責摧毀物件的成員

//解構器不可以是const 
//建構器可以是constexpr
//constexpr建構器  可以 = default  或 = delete 函式   
//要符合建構器所以可以沒reutrn述句    constexpr函式本身又只能有return述句   所以結果是  主體通常是空的
//
//#ifndef DEBUG_H
//#define DEBUG_H
//class Debug {
//public:
//#ifdef CONSTEXPR_CTORS
//	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
//	constexpr Debug(bool h, bool i, bool o) :
//		hw(h), io(i), other(o) { }
//	constexpr bool any() { return hw || io || other; }
//	constexpr bool hardware() { return hw || io; }
//	constexpr bool app() { return other; }
//#else
//	Debug(bool b = true) : hw(b), io(b), other(b) { }
//	Debug(bool h, bool i, bool o) :
//		hw(h), io(i), other(o) { }
//	bool any() const { return hw || io || other; }
//	bool hardware() const { return hw || io; }
//	bool app() const { return other; }
//#endif
//	void set_io(bool b) { io = b; }
//	void set_hw(bool b) { hw = b; }
//	void set_other(bool b) { hw = b; }
//private:
//	bool hw;    // hardware errors other than IO errors
//	bool io;    // IO errors
//	bool other; // other errors
//};




//298 aggregate class
//所有成員public
//無建構器
//無類別內初始器
//無父類別base classes 或 virtual函式

//例如說struct
//
//struct Data {
//	int v;
//	string s; 
//};
//
//就可以依屬性順序大括號初始化
//
//Data v1 = { 0, "Anna" };
//未依順序為error


//296  7
//如果將建構器宣告為explicit(明確的)
//
//explicit Sales_data(const string &s): bookNo(s) {}
//
//就不能用於隱含轉換

//只能用在直接初始化
//Sales_Data item1(nullBook); //ok
//Sales_Data item12 = nullBook; //error 不能用於拷貝形式的初始化

//具explicit的程式庫
//接受const char * 的單參數string 建構器  不是explicit
//接受一個大小的vector建構器是explicit



//295  隱含轉換  這個就炫了
//string nullBook = "111-111-11";
//item.combine(nullBook)  //Sales_data的方法  接收一個Sales_Data 因為建構式可吃字串  所以字串自動套用吃字串的建構式變Sales_Data
//這樣子編譯器產生的是一個暫時物件用完就摧毀  也沒有想宣告變數 Sales_Data sales;  一樣會留著





//
//294
//SomeClass obj();//變函式了
//SomeClass obj;//ok 物件


//293  一個類沒預設建構器   其他類有這個類的資料成員  可能就無法套用預設建構器 會報錯 感覺少見  遇到再說


//292 delegating constructors   就是用其他定義好的建構式 初始
//
////非dele
//Sales_data(const std::string &s, unsigned c, double p) : bookNo(s), units_sold(c), price(c) { }
////dele
//Sales_data() : Sales_data("",0,0){ }
//Sales_data(const std::string &s) : Sales_data(s, 0, 0) { }



//290
//很細的問題了  初始化參數的順序  那是要成員用成員初始化  否則不用考慮  所以盡量不要成員初始成員  用參數值接帶



//288  289
//
//初始化
//Screen() : cursor(0), height(0), width(0) { }
//
//指定
//Screen() : (const string &s, unsigned cnt, double price) {
//	bookNo = s;
//	units_sold = cnt;
//	revenue = cnt * price;
//
//}
//

//初始有時必要
//class ConstRef {
//public:
//	ConstRef(int i);
//
//private:
//	int i;
//	const int ci;
//	int &i;
//};
//
//ConstRef(int ii) {
//	//用指定會出錯
//	i = ii; //ok
//	ci = ii;//error const不能改值
//	ri - i; // error ri參考沒初始化
//
//}
//所以要用類似 vvv 初始才行
////Screen() : cursor(0), height(0), width(0) { }




//286
//
//一個類有height屬性   方法參數也有height
//int height;
//void func(int height) {
//	//要呼叫類別成員height 用
//	this->height;
//
//	//要呼叫類別外的全域屬性
//	::height
//}



//283 4
//一般名稱查找
//1 在名稱使用的區塊往前查
//2 找不到去外層區塊查
//類別
//1整個類的成員宣告先被編譯
//2看完整個類別 函式主體才被編譯
//類別成員
//1成員2類別 3 函式定義之前整個範疇中查找
//
//
//typedef using 別名要宣告在使用前  且定義後  隻露不能在重複定義使用 或同個名稱指派給另個別名




//282
//Sales_data c;
//c.bookNo;   物件取法
//Sales_data* p;
//p->bookNo;  指標取法


//280 1
//friend沒有遞移性  A是B友  C是B友  不會A是C友
//重仔函式 要個別宣告friend

//279  類別可以讓另個類別變成friend
//類別可以讓另個類別特定成員變成friend  預設inline
//A class 將 B 標為好友
//B就可以存取A的private成員




//278   前向宣告  forward declaration   不完整的型別 incomplete type
//就是例如只寫  class Screen;   不完整定義內部屬性成員
//否則編譯器 不可能知道那個類別有什麼成員

//一個類別沒辦法有自己營別的資料成員  然而  類別名稱一看就  就被視為已宣告  但尚未定義   一個類別直到其類別主體完結前都尚未被定義
//因為視為已宣告  所以可以又只向自己型別的   指標 成員
//class c {
//	c *next;
//	c *previous;
//};



//274   mutable 永遠都不會是const  即使被宣告為const 也能改變
////so const成員函式可以修改其值
//class Screen {
//public:
//	void someMem() const;
//private:
//	mutable size_t access_ctr;
//};
//
//void Screen::someMem() const {
//	++access_ctr;//雖然宣告為const 但可修改
//}



//268 
//struct > class
//Sales_Item268.h

//struct class差異
//struct預設都public    class預設都private   所以要有private 就用class



//267
//類別copy的情境  1初始化變數  2 以值回傳

//類變數 = 類變數   意義如同  每個屬性賦值過去 copy

//編譯器會為我們合成    拷貝 指定 解構運算  但  會再類別物件外配置資源的類別 不能正確運作     ex ch13.1.4 動態記憶體




//262 3 4
//constructors 建構式/器  大多概念同C#
//類別沒給建構式   編譯器會隱含地幫忙定義預設建構式   就是把所有屬性都給預設值
//如果是複合類別  類別中有其他類別的成員  就要通判考慮所有屬性的初始化正確性   如果有其他類別屬性 沒給建構式會不正確初始  就要再加上去

//如果有加上任何有參建構式  就一定要再宣告無參預設建構式
// >> Sales_Item255.h



//255 ~ 261
//Sales_Item255.h




////249 50
//void Bigger(const string &s1, const string &s2, bool(*pf)(const string &, const string &))
//void Bigger(const string &s1, const string &s2, bool pf(const string &, const string &))
////兩者函是參數實際上都是function pointer
//

//typedef bool func(const string &, const string &);
//typedef decltype(lenCompare) Func2;//等效型別
//
//typedef bool (*func)(const string &, const string &);
//typedef decltype(lenCompare) *Func2;//等效型別


//void Bigger(const string &s1, const string &s2, Func)
//void Bigger(const string &s1, const string &s2, Func2)//same

//無法回傳一個函式型別    但可回傳 f pointer
//using F = int(int*, int); //函式型別 非指標
//using PF = int(*)(int*, int);  //指標型別


//PF f1(int) //ok
//F f1(int) //err
//PF *f1(int) //ok
//
//auto f1(int) -> int(*)(int*, int) //same
//

//
//string::size_type sumLen(const string &s1, const string &s2)
//
//decltype(sumLen) *getFcn(const string &)  // *  return f p


//247 8 讚  函是指標 你好
//funciton pointer
//bool (*pf)(const string &, const string &)    *表指標
//
//使用很寬鬆
//pf = lenCompare
//pf = &lenCompare  //same
//
//bool b = pf("a", "b")
//bool b = (*pf)("a", "b")
//bool b = lenCompare("a", "b")  //same







//243-6 又是func 匹配  大多同直覺  需要再細查
//
//最佳匹配順序
//1 完全符合
//2 const轉換
//3 算術轉換 short double轉int之類   指標轉換
//4 class轉換


//241 2
//巨集 assert NDEBUG
//
//assert定義在cassert.h中
//
//assert用在不可能發生的情況   內部運算為false 就直接停止程式
//assert(word.size() > threshold)
//
//如果NDEBUG有定義  assert就不會有動作
//可以用#define NDEBUG定義  或者編譯器參數下 $CC -D NEDEBUG main.c 
//
//沒定義NDEBUG   #ifdef #endif之間程式碼會被執行  反之不會
//
//void printf(const int ia[], size_t size)
//{
//#ifdef NDEBUG
//cerr << __func__ << "array size is " << size << endl;
//#endif
//
//}
//if (w.size() > threshold)
//	cerr << "Error: " << __FILE__
//	<< in function << __func
//	at line __LINE__
//	Compiled on  __DATE__
//	at __TIME__
//	word read was w
//	Length too short


//239 240
//constexpr int new_sz() { return 42; /*裡面可以很複雜 只要每個部件堆到最底都是常數*/}
//constexpr是可用在常數運算式的函式
//
//constexpr inline 的函式可以被定義多次  但每個都要相同
//所以一般都定義在標頭檔中



//
//238
//inline 可以減少函式呼叫的負擔  (一般func 呼叫要進行很多工作   呼叫前儲存registers暫存器 回傳後復原
//	引數可能需拷貝  程式會分支到新位置  )
//如果shorStr 被宣告 inline
//cout << shortStr s1 s2 << endl; 
//編譯過程會直接展開在行內
//cout << s1.size() < s2.size() ? s1 : s2 << endl; 
//
//inline通常用在小函式    幾十行的通常inline不太合用    編譯器可能忽略



//236  func的參數的  預設引數  規則同C#
//typedef string::size_type sz;
//string screen(sz ht, sz wid = 80, char background = '')
//
//如果要對同個參數多次宣告
//每次宣告 定義多的引數  只能增加還沒給預設值的   已經給過的不能再給 直接不加 =
//string screen(sz = 30, sz, char)


//區域變數不能當   預設引數
//全域變數或函式可當 ""
//
//sz wd = 80;
//sz ht();
//char def = ' ';
//string screen(sz = ht(), sz = wd, char = def);


//234 重載  就要匹配參數最符合的  最佳匹配  沒有匹配  模糊多個相同的呼叫無法辨識
//這邊概念看過  需要再回來查

//區塊內變數名稱   也會遮蔽函數名稱   名稱查找優於型別檢查



//233
//const string &shorten(const string &s1, const string &s2)
////{....}
//可以用
//
//string &shorten(string &s1, string &s2)
//{
//	auto &r = shorten(const_cast<const string&>(s1), const_cast<const string&>(s2))
//		return const_cast<string&>(r);  //用const_cast轉成const 以匹配const版shorten宣告
//}


//232
//參數有無const是一樣的 對傳入到函式的物件沒有效果   宣告視為相同
//
//但實際傳給參數的值  帶const的 只能傳const修飾的給他
//沒帶const的  傳有 或 無 const的  都可
//
//Record lookup(Account&)
//Record lookup(const Account&)
//Record lookup(Account*)
//Record lookup(const Account&)


//231
//重載 overload 就 同函數名稱 不同參數組合  但只有回傳值型別不同不算重載
//
//下面每對相同
//Record lookup(const Account &acct)
//Record lookup(const Account&)//名可略
//typedef Phone Tel
//Record lookup(const Tel&)
//Record lookup(const Phone&)


//230
// Trailing Return Type
//auto func(int i) -> int(*)[10];

//用decltype 對陣列回傳的型別是陣列  不是指標  所以要加一個*表指標
//
//int odd[] = { 1, 3, 5, 7, 9 };
//decltype(odd) *arrPtr(int i) {
//	return (i % 2) ? &odd : &even;
//}




//229
//回傳對陣列的一個指標
//typedef int arrT[10];
//using arrT = int[10];  //同上都定義型別同義詞
//arrT* func(int i);  //就回傳了  指向10 int arr的指標

//不使用別名直接宣告   記得維度要給
//
//int arr[10]  //10 int arr
//int *p1[10]   // 10 ref arr
//int (*p2)[10]  = &arr // pointer to 10 int arr
//
//函式宣告  維度跟在func後  func要括號
//
//int (*func(int i))[10];
//





//227
//return 0;  表示成功  其他大多都表失敗
//
//還有  EXIT_FAILURE   EXIT_SUCCESS  可用

//226
//除了之前ref的寫法  回傳多個值 也可以用例如vector
//vector<string> process()

//可以  return {};
//可以  return {"a", "b"};
//可以  return {stra, "c"};


//f &getval(string &str, string::size_type ix)
//{
//	return str[ix];
//}
//int main() {
//	string s = "s";
//	cout << s << endl;
//	getval(s, 0) = 'a';  //改變s[0]的值
//	cout << s << endl; 
//}



//225
//不要回傳  區域變數的參考  因為離開之後就被值摧毀了



//222
//Ellipsis
//有點像是
//void f(pList, ...)
//void f(...)
//
//是為了和C的varargs互動  只限定用於 C 與 C++共通的型別


//221
//220
//數量不一定的引數  initializer_list  型別相同    型別不同用 variadic template 16.4
//initializer_list<T> ls;
//initializer_list<T> ls{a,b,c};
//ls(ls2)
//ls = ls2
//ls.size()
//ls.begin()
//ls.end()

//用法同vector

//ls({"a", strb, strc})


////219
//main 傳參數  a b -c -d e
//可以 int main(int argc, char *argv[])
//可以 int main(int argc, char **argv)   表 argv指向 char*
//
//argc 是參數個數 5
//argv 就是參數值陣列
//argv[0] = "a" ...類推


//218
//多維陣列  會作為指標傳入  指向1st元素   因為多維arr是arr的arr   所以1st元素會是一個arr 所以用arr pointer
//void print(int(*arr)[10]/*10 int arr*/, int rowSize/*第二維度的大小*/)   //不可寫int *arr[10] 是10個指標的陣列   
//等同
//void print(int[][10]/*10 int arr*/, int rowSize/*第二維度的大小*/)   //不可寫int *arr[10] 是10個指標的陣列   



//217
//如果不需要對陣列寫入  就用const指標參數
//要寫入 就用普通參數

//陣列參考參數
//void print(int(&arr)[10])   // 10 int 組成的陣列的參考      不可寫 &arr[10]  是由參考組成的陣列
//{
//	for (auto ele : arr) {
//		cout << ele << endl;
//	}
//}
//但這邊 明確寫10 真的就只能傳剛好10個元素的陣列進來


//陣列參考  怎麼知道結尾位置
//C Style字串  可以靠null結尾判斷
//
//或者起訖
//void print(const int * beg, const int * end)  //前面有講過怎麼取beg end 
//{
//	while (beg != end)
//	{
//		cout << *beg++ << endl; 
//	}
//}
//
//或者起 大小
//void print(const int ia[], size_t size)  //前面有講過怎麼取beg end 
//{
//	while (beg != end)
//	{
//		cout << *beg++ << endl; 
//	}
//}






//215  傳陣列就是用  傳參考
//void print(const int *)
//void print(const int[])
//void print(const int[10])//三者同  都是const int *


////213
//void f(const int i)
//void f(int i)// error 重複  等同上
//
//可以用非const 初始low level const 但反過來不行   所以int參數  不能傳 const int進去
//
//固定值的參數進量明確寫int  會讓叫用者更清楚
//
//直接要傳字串進去 f("a")  要用const string &s


//212
//top level const  也就是   變數本身是const
//const int c = 1; //就是 top level const
//拷貝引述會忽略頂層const
//func(const int i) >>   傳 int   const int 都可
//i 可讀不可寫
//
//
//211 參考 > 可避免拷貝超大物件  或無法拷貝的物件  這裡是說 參考  不是說 指標喔!!!
//
//string很長 >
//bool isshorter(const string &s1, const string &s2)
//
//要回傳多個值  這裡介紹  出乎意料  不是用class屬性紀錄  不是dynamic 不是tuple 不是陣列  
//而是多個參考參數  參數修改完等同回傳值  就是 C#  ref 參數 的作用


//210
//對參考進行的運算  是在參考指涉的物件上進行的  
//和下面相比
//void reset(int &i) {
//	i = 0;//改變外部傳入引數參考繫結的值
//}
//
//int i = 42;
//reset(i)   直接丟
//cout << i << endl;  // i 是 0 但位址不變



//209  很直覺
//int n = 0, i = 42;
//int *p = &n, *q = &i;
//*p = 42;   p沒變
//p = q;
//
//
//void reset(int *ip) {
//	*ip = 0;//改變外部傳入引數指標指向的值
//	ip = 0;//不會改變外部傳入的引數的位址  改變內部 如區域變數
//}
//
//int i = 42;
//reset(&i)
//cout << i << endl;  // i 是 0 但位址不變


//208
//函是式數 parameters
//參數是 參考  pass by reference , call by reference   參考 之前講過  就是  繫結物件的  別名
//  參考會繫結至bound to初始化他的物件
//否則  非參考型別 就是  拷貝值        value                     value

//指標 跟非參考一樣   是copy指標值    拷貝後就是兩個不同的東西了





//206
//同變數  函數  在標頭檔h宣告  在源碼檔cpp 定義  就declaration definition
//也可寫在cpp  合法  但可能多個宣告 要改要改多個  放在h只要改一個
//h include

//if fact函式寫在 fact.cc  宣告在 ch6.h   main在 factMain.cc
//編譯指令如這裡前面都有$表cmd  

//編譯整個程式產生可執行檔
//CC factMain.cc fact.cc #產生factMain.exe or a.out
//CC factMain.cc fact.cc -o main #產生main or main.exe  
//  # obj Windows   o Linux

//   假設只改一個檔  編譯單個檔案
//CC -c factMain.cc #產生factMain.o
//CC -c fact.cc #產生fact.o
//CC factMain.o fact.o #產生factMain.exe or a.out
//CC factMain.o fact.o -o main #產生main or main.exe  


//205
//一般變數在區塊結束後被摧毀
//但宣告成static就可以持續保存
//
//size_t count_calls()
//{
//	static size_t ctr = 0;  // value will persist across calls
//	return ++ctr;
//}
//
//int main()
//{
//	for (size_t i = 0; i != 10; ++i)
//		cout << count_calls() << endl;
//	return 0;
//}
//



//204
//void f1(){}
//void f1(void){}//同上 表無參  C風格
//
//回傳型別  不能是 陣列/函數    但可為指標
//pointers to functions 函式指標 6.3.3



//202
//// factorial of val is val * (val - 1) *  (val - 2) . . . * ((val -  (val - 1)) * 1)
//int fact(int val)
//{
//	int ret = 1; // local variable to hold the result as we calculate it
//	while (val > 1)
//		ret *= val--;  // assign ret * val to ret and decrement val
//	return ret;        // return the result
//}




//196  197

//錯誤一直往上往外傳  都沒有被適當的catch到
//就會轉移到一個叫 terminate 的函式    是系統決定要做什麼後續行為
//
//exception 
//runtime_error
//range_error
//overflow_error
//underflow_error
//logic_error
//domain_error
//invalid_argument
//length_error
//out_of_range
//
//
//exception bad_alloc bad_cast   只能用預設初始化   無法提供自訂初始器 initializer
//其他exception可以用字串初始化 但無法預設初始化
//
//
//what回傳 const char* 指向一個 C-Style字元字串


////194
//if(xxx)
//	throw runtime_error("err msg");
//
//try
//{
//
//}
//catch (const std::exception&)//這 intellisence 自己產的  沒看過  炫
//{
//
//}
//
//try  書的
//{
//	//....
//	throw runtime_error("err");
//}
//catch (runtime_error err)//這 intellisence 自己產的  沒看過  炫
//{
//	cout << err.what() << endl; 
//}
//catch (runtime_error err)//這 intellisence 自己產的  沒看過  炫
//{
//	cout << err.what() << endl; 
//}
//


//192
//goto somelabel;
//
//
//somelabel: reutrn;
//
//兩者要在同個函式內

//190  跳躍述句
//break continue goto reutrn

//189
//do whlie



//188
//range for   如果要改變元素值  要用參考型別
//vector<int> v = { 0,1,2 };
//for (auto &r : v)
//	r *= 2;
//
//等同
//
//for (auto beg = v.begin(), end = v.end(); beg != end; ++beg)
//{
//	auto &r = *beg;
//	r * = 2;
//}

//但記得range for裡的 集合大小不能被改變  一遍iterator就無效了  所以不能增刪 push_back

//https://www.geeksforgeeks.org/difference-between-stdremove-and-vectorerase-for-vectors/
//vector erase  好像比較花時間  每次刪都回全部一動一次
//vector remove  好像比較省時間   全部刪完才移動



//187
//vector<int>::iterator beg = v.begin();
//for (; beg != v.end() && *beg >= 0; ++beg)
//	;
//for (int i = 0;  ; ++i)

//vector<int> v;
//for (int i = 0; cin >> i; )
//	v.push_back(i);




//186
//
//vector<int> v;
//for (decltype(v.size()) index = 0; index != v.size() && !isspace(s[index]); ++index)
//{
//	s[index] = toupper(s[index]);
//}

//for (decltype(v.size()) index = 0, sz = v.size(); index != sz; ++index)
//{




//182
//switch 的 case  可以用大括號包住區塊  裡面宣告的變數含初始話就比較獨立
//沒有用大括號  有定義變數的話   跳過case能讀到變數宣告 但部會初始化
//case 'A':
//	{
//	string str = "a";
//	//...
//	}
//case 'B'
//	{
//	string str = 'test';
//	//...
//	}
//
//可以同行 case 'a': case 'b': case 'c'
//也可以 case 'a', 'b', 'c'



//173

//165  舊式強制轉型
//早期版本的C++
//type(expr);
//(type)expr;
//
////強制轉型會干擾正常的型別檢查  所以建議能避則避  看能循一般正常途徑做到
//



//163 強制轉型
//static_cast   除了const轉非const  合理的都可用
//int i, j;
//double slope = i / j;
////轉成double運算
//double slope = static_cast<double>(j) / i;
//
//static_cast常用在大型別轉小型別  不加的話  編譯器會給警告訊息  加就不會 等於告訴編譯器  不在乎精度損失

//double d;
//void* p = &d;//d先暫存在void*
//double*dp = static_cast<double*>(p);
//


//const_cast   const轉非const
//const char *pc;
//char *p = const_cast<char*>(pc);

//------------------233原來有提到 string &s1;   const string &p = const_cast<const string&>(s1);
//------------------可以把非const 轉為const

//reinterpret_cast   是對位元模式低階的重新解讀
//int * ip;
//char *pc = reinterpret_cast<char*>(ip);
//但由於pc到底指到哪個東西 不知道  所以這種用法很危險





//158
//隱含的轉換 implicit conversions
//算術型別會盡量保留精確度
//所以 int ival = 3.541 + 3
//右邊會先都轉成double  算完再轉成int給左邊
//
//這裡有一些 兩個型別擺在一起   要怎麼同化成哪個型別例如小的轉大的  有需要再回來查


//157
//sizeof 回傳一個 運算式 或 型別 的大小   結果是一個size_t
//sizeof (type)
//sizeof expr
//
//Sales_data data, *p;
//sizeof(Sales_data); // size required to hold an object of type Sales_data 
//sizeof data; // size of data's type, i.e., sizeof(Sales_data)
//sizeof p;    // size of a pointer
//sizeof *p;   // size of the type to which p points, i.e., sizeof(Sales_data)
//sizeof data.revenue; // size of the type of Sales_data's revenue member 
//#ifdef SIZEOF_MEMBER
//sizeof Sales_data::revenue; // alternative way to get the size of revenue
//#else
//sizeof Sales_data().revenue; // use an object
//#endif
//
//sizeof char 1
//sizeof 參考型別  物件大小
//sizeof 指標 大小
//sizeof 解參考  物件大小
//sizeof 陣列  元素sizeof * 數量
//sizeof string vector 只有固定部分大小  不是真的多大
//
//> arr幾個元素
//constexpr size_t = sizeof(ia) / sizeof(*ia);
//int arr2[sz];



//156
//優先序
//cout << 42 + 10;
//cout << (42 < 10);

//155
//unsigned long quiz1 = 0;
//auto u27 = 1UL << 27;
//quiz1 |= 1UL << 27;
//quiz1 &= ~(1UL << 27;
//
//quiz1 & (1UL << 27;


//154
//兩數一個1一個0 為true   其他false

//位元運算相關
//! & | ^(XOR)  ~(NOT)


////152
//grade < 60要括起來  不然60會直接被cout吃了  
//
//cout << grade < 60 ? "Fail" : "PASS" << endl; 



//150
//成員存取運算子
//string s1 = "abc", *p = &s;
//n = (*p).size();
//n = p->size();//兩舉同等


//141
//除法若兩運算元有相同正負號  商數就正 否則負
//%  兩運算元任一為負   模數就負   否則正

//135
//lvalue 可以想成址   rvalue想成值



//128
//
//#include "Version_test.h"
//
//#include <iterator>
//	using std::begin; using std::end;
//
//#include <vector>
//	using std::vector;
//#include <iostream>
//	using std::cout; using std::endl;
//
//#include <cstddef>
//	using std::size_t;
//
//	int main()
//	{
//		// array of size 3; each element is an array of 4 uninitailzed ints 
//		int ia1[3][4];
//
//		// array of size 10; each element is a 20-element array 
//		// whose elements are arrays of 30 ints
//		int arr[10][20][30] = { 0 }; // initialize all elements to 0
//
//		// assigns the first element of arr to the last element 
//		// in the last row of ia
//		ia1[2][3] = arr[0][0][0];
//
//		// binds row to the second four-element array in ia 
//		int(&row)[4] = ia1[1];
//
//		// three elements, each element is an array of size 4
//		int ia2[3][4] = {
//			{0, 1, 2, 3},   // initializers for the row indexed by 0
//			{4, 5, 6, 7},   // initializers for the row indexed by 1
//			{8, 9, 10, 11}  // initializers for the row indexed by 2
//		};
//
//		// equivalent initialization without the optional 
//		// nested braces for each row
//		int ia3[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
//
//		// explicitly initialize only element 0 in each row
//		int ia4[3][4] = { { 0 }, { 4 }, { 8 } };
//
//		// explicitly initialize row 0; the remaining elements 
//		// are value initialized
//		int ix[3][4] = { 0, 3, 6, 9 };
//
//		// prints 9 0 0 
//		cout << ix[0][3] << ' ' << ix[1][0] << ' ' << ix[2][0] << endl;
//
//#ifdef CONSTEXPR_VARS
//		constexpr size_t rowCnt = 3, colCnt = 4;
//#else
//		const size_t rowCnt = 3, colCnt = 4;
//#endif
//		int ia[rowCnt][colCnt];   // 12 uninitialized elements 
//		
//		//!!!!!多維陣列常用 多層迴圈處理
//		
//		// for each row
//		for (size_t i = 0; i != rowCnt; ++i) {
//			// for each column within the row
//			for (size_t j = 0; j != colCnt; ++j) {
//				// assign the element's positional index as its value
//				ia[i][j] = i * colCnt + j;
//			}
//		}
//
//
//		//!!!!!對元素range for 時  要改變元素的值  用參考&
//		//不加&  對元素遍歷的時候  都會被轉為陣列第一個元素的指標
//		
//		// four ways to print the contents of ia
//		// 1. using nested range for loops
//		for (const auto &row : ia) // for every element in the outer array
//			for (auto col : row)   // for every element in the inner array
//				cout << col << endl; // print the element's value
//		cout << ia[0][0] << ' ' << ia[2][3] << endl; // prints 0 11
//


////129
//int ia[3][4];
//int(*p)[4] = ia; 指向第一個四int的陣列
//p = &ia[2];   指向第三個四int的陣列

//底下 ia + rowCnt 就是這個意涵

//							
//		// 2. using pointers and a traditional for loop
//		//    with pointer arithmetic to calculate the end pointers 
//		for (auto p = ia; p != ia + rowCnt; ++p) {
//			// q points to the first element of an array of four ints; 
//			// that is, q points to an int
//			for (auto q = *p; q != *p + colCnt; ++q)
//				cout << *q << ' ';
//			cout << endl;
//		}
//

//p130   注意 begin end 裡面有接*

//		// 3. using pointers and a traditional for loop
//		//    with the library begin and end functions to manage the pointers
//		for (auto p = begin(ia); p != end(ia); ++p) {
//			// q points to the first element in an inner array
//			for (auto q = begin(*p); q != end(*p); ++q)
//				cout << *q << ' ';  // prints the int value to which q points
//			cout << endl;
//		}
//
//		// 4. using a type alias to declare the loop control variable
//#ifdef TYPE_ALIAS_DECLS
//		using int_array = int[4]; // new style type alias declaration 
//#else
//		typedef int int_array[4]; // equivalent typedef declaration
//#endif
//
//		for (int_array *p = ia; p != ia + 3; ++p) {
//			for (int *q = *p; q != *p + 4; ++q)
//				cout << *q << ' ';
//			cout << endl;
//		}
//
//		// alternative way to assign positional index to elements 
//		// in a two-dimensional array
//		int alt_ia[rowCnt][colCnt]; // 12 uninitialized elements 
//		size_t cnt = 0;
//		for (auto &row : alt_ia)    // for every element in the outer array
//			for (auto &col : row) { // for every element in the inner array
//				col = cnt;          // give this element the next value
//				++cnt;              // increment cnt
//			}
//		// now print the value of the array
//		for (const auto &row : alt_ia) // for every element in the outer array
//			for (auto col : row)     // for every element in the inner array
//				cout << col << endl;
//
//		return 0;
//	}
//





//127
//ia[2][3] = arr[0][0][0];
//int(&row)[4] = ia[1];  //row 繫結至  ia第二個四元素的00陣列


//126
//多維陣列  是陣列所構成的陣列
//int ia[3][4];   大小3  每個元素都是大小4的陣列
//int arr[10][20][30] = {0}; 所有元素初始為 0
//二維可看作  arr[列][行 欄]

//int ia[3][4] = {
//	{0,1,2,3},
//	{4,1,2,3},
//	{0,1,5,3},
//};  //ok 等同
//int ia[3][4] = {
//	0,1,2,3,4,1,2,3,0,1,5,3
//};
//
//
//int ia[3][4] = {
//	{0},
//	{4},
//	{5},//初始每列第一行  每列後三個都0
//};
//int ia[3][4] = {
//	0,1,2,3 //初始第一列
//};
//


//125
//用陣列初始化vec  v(begin(temp), end(temp));
//#ifdef LIST_INIT
//vector<int> v{ 1,2,3,4,5,6,7,8,9 };
//#else
//int temp[] = { 1,2,3,4,5,6,7,8,9 };
//vector<int> v(begin(temp), end(temp));
//#endif
//for (auto &i : v) // for each element in v (note: i is a reference)
//i *= i;           // square the element value
//for (auto i : v)      // for each element in v
//cout << i << " "; // print the element
//cout << endl;
//
//return 0;

//vector<int> v(arr + 1, arr + 4); //用arr的子集

//他是建議   不要用array 指標 多用vector iterator比較現代和高階的操作  我是覺得都OK




//124
//char* arr = str // error char指標不能用string初始化 
//const char *str = s.c_str();  //SSok 回傳Ctyle字元字串的字元陣列的開頭

//123
//cat cpy  容納的陣列要夠裝 包含null結尾
//strcpy(lsrgrStr, cal);
//
//要計算得很清楚
//這些都叫C Style 字串  所以建議進量都使用string   更安全 更有效率



//122
//標準C程式庫  The Standard C Library 在C Style的字串上運算
//傳入的變數  一定要null結尾  不然他會一直往後找到null為止
//char c = { "C","A" };
//cout << strlen(ca) << endl; //error
//
//strlen(p)
//strcmp(p1, p2)
//strcat(p1, p2)
//strcpy(p1, p2)
//
//C Style字串的比對 > < 不是用字典  而是直接比對字串指標位置
//	要用strcmp才可以字典比大小


//121
//int *p = &ia[2];
//int j = p[1];

//int k = p[-2];//指向p[0]


//120
//auto n = end(arr) - begin(arr); // 指標相減 型別是 ptrdiff_t  可負的有號
//
//也可以
//int * b = arr, *e = arr + sz;//相當於指向off-the-end   長度10的arr  0+10剛好超過最後一個元素+1
//while (b < e)
//{
//	++b;
//}
//
//int ia[] = { 1, 2, 3, 4 };
//int last = *(ia + 4); //相當於指向ia[4]
//如果寫 *ia + 4 就是ia指向物件的值+4


//119
//int ia[] = { 1, 2 };
//int *pbeg = begin(ia), *pend = end(ia);
//while (pbeg != pend && *pbeg >= 0)//找出第一個負的元素
//	++pbeg;//找下一個

//int arr[] = { 1, 2 };
//int *ip = arr;//arr[0]  
//int *ip2 = ip +  4; //指向arr[4]


//118
//int arr[] = { 1, 2 };
//int *p = arr;
//++p;  //指到arr[1] 
//
//int *e = &arr[2]; //類似 off-the-end   不存在的元素
//for (int *b = arr; *b < e; b++)
//{
//	cout << *b << endl; 
//}

//int ia[] = { 1, 2 };
//int *beg = begin(ia); //陣列用這個
//int *last = end(ia);






//117
//string nums[] = { "1", "2" };
//string *p = &nums[0];
//string *p2 = nums;//兩者同  都指向第0個元素  (一般口語是說第一個
//decltype(nums) nu2 = { "5","6" };//decltype ok




//116
//陣列存取一樣用 arr[index]
//index型別通常是size_t 是無號型別
//一樣可以套用 range版 for



//115
//int *ptrs[10]; //十個對int的指標
//int &refs[10] = ?; //沒有參考組的陣列
//int (*Parray)[10] = &arr;//Parray指向  10 int arr
//int (&arrRef)[10] = arr;//arrRef 參考  10 int arr
//int *(&arry)[10] = ptrs;//arry是一個參考  指涉 10 int arr


//114
//int a[3] = { 0,1,2 };
//int a2[] = { 0,1,2 };
//int a[5] = { 0,1,2 }; //後面兩個初始  0 1 2 0 0
//
//string的字元陣列  特殊規則 都是以null結尾
//
//char a3[] = "abc"; //程式自動在後面加一個null終止符 terminator
//char a3[3] = "abc"; //error  後面不夠放null






//113  陣列  array
//array尺寸要是const  可以用constexpr
//
//unsigned cc = 3;
//constexpr unsigned sz = 3;
//int arr[10];
//int *arr[10];// 10個對int的指標組成的陣列
//int arr[sz];
//int arr[cc];//error
//陣列中存的是物件  所以沒有參考組成的陣列


//112
////binary search using iterator
//auto beg = text.begin(), end = text.end();
//auto mid = text.begin() + (end - beg)/2;
//while (mid != end && *mid != sought)
//{
//	if (sought < *mid)//往前半找
//		end = mid;
//	else              //往後半找
//		beg = mid + 1;
//	mid = beg + (end - beg) / 2;//新的中點
//}




//111
//iter + n
//iter - n
//iter += n
//iter -= n
//> < <= >= 就想成目前在vector裡的位置比較  很直覺  數字index比大小而已
// iter - iter 得到 位置差  型別是difference_type



//110
//印出每一列  直到那列是空白
//// print each line in text up to the first blank line
//for (auto it = text.cbegin();
//	it != text.cend() && !(*it).empty(); ++it)
//	cout << *it << endl;
//
//// equivalent loop using arrow to dereference it and call empty
//for (auto it = text.cbegin();
//	it != text.cend() && !it->empty(); ++it)   ->同(* ).
//	cout << *it << endl;


//range 版 for 跟C# foreach一樣  集合變數不能被變動例如增刪  一變iter就失效了



//109
//vector<int> v;
//const vector<int> v2;
//auto it1 = v.begin(); //預設回傳iter
//auto it2 = v2.begin();//預設回傳const_iterator
//auto it1c = v2.cbegin();//cbegin  cend固定回傳const_iterator
//
//(*it).empty()   //(*it)要括號包起來 不然會先應用到it身上 錯


//108
//for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
//{
//	*it = toupper(*it);//全轉大寫
//}

//iter型別有  iterator  const_iterator
//vector<int>::iterator it;  //可讀寫  不能用在const類型的vector  
//vector<int>::const_iterator it2; //可讀不能寫    用在const類型的vector  本身就是常數不能寫  
//也可以用在非const類型vector 一樣有唯讀效果





//107
//迭代器可以用*解參考 dereference
//string("abc");
//if (s.begin() != s.end()) {//非空
//	auto it = s.begin();//第一個字元
//	*it = toupper(*it);   //首字轉大寫
//}
//
//*iter 
//iter->mem   //(*iter).mem
//++iter
//--
//
//但end 不代表任何元素  不能 ++ --

//105-6 iterator 迭代器
//auto b = v.begin(), e = v.end();//end 是最後一個位置的後面  off-the-end是不存在的元素 就是再往後移一格
//兩個iter == 是代表的元素相同  或是同一個容器的off the end
//!=
//string vector 都有iterator


//104   把輸入的分數依照十分一個等級分群  計算每個十分範圍的數量
//vector<unsigned> grades;
//// count the number of grades by clusters of ten:
//// 0--9, 10--19, . . . 90--99, 100
//unsigned scores[11] = {};  // 11 buckets, all value initialized to 0
//unsigned grade;
//while (cin >> grade) {
//	if (grade <= 100)
//		// increment the counter for the current cluster
//		++scores[grade / 10];
//	grades.push_back(grade);
//}
//cout << "grades.size = " << grades.size() << endl;
//
//for (auto g : grades)  // for every element in grades
//cout << g << " ";
//cout << endl;
//
//for (auto i : scores)       // for each counter in scores
//cout << i << " ";       // print the value of that counter
//cout << endl;


//// vector 的 for 的 i 類型都用 decltype(v.size())
//vector<char> v;
//for (decltype(v.size()) index = 0; 	index != v.size() ; ++index)
//	v[index] = toupper(v[index]); // capitalize the current character




//102
//vector<int> v{ 1,2,3,4,5 }
//for (auto &i : v)
//	i *= i;
//for (auto &i : v)
//	cout << i << endl;
//
//vector 也有 size(回傳 vector<CC>::size_type 類型 ) 和 empty是否空 方法
//
//vec 相等  就是內部元素和順序都相等
//> < 就是字串用字典的概念去比美個元素   不然就每種型別的 > < 運算   不支援><就vec無法比較



//101 
//vector<int> v2;
//for (int i = 0; i != 100; i++)
//{
//	v2.push_back(i)
//}
//
//string word;
//vector<string> text;
//while (cin >> word) {
//	text.push_back(word);
//}


//96-98 vector 就像 C# List
//vector<int> ivec;
//vector<Sales_item> vss;
//vector<vector<string>> file;
//
//vector<int> ivec = ivec2;
//vector<int> ivec(ivec2);//此二  copy另個vec
//vector<string> ivec = { "a", "b", "c" };
//vector<string> ivec{ "a", "b", "c" };//此二串列初始化
//vector<int> ivec(10, -1);//10個-1
//vector<string> ivec(10, "a");//10 個a
//vector<int> ivec(10, -1);//10個-1
//vector<string> ivec(10);//10 個預設值
//
//vector<string> ivec{ 10 };//10 個預設值   特殊用法   因為10不能給string  編譯器自己繞路設想



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
//一個參考不過就是給一個物件另一個名稱
//要改變字元裡的值  要用參考
//for (auto &c : str)  
//	&c toupper(c); //印string 裡的每個char

//s[0]  第一個字元  就一般array概念


////91
//string str("abc");  
//for (auto c : str)  就 foreach
//	cout << c << endl; //印string 裡的每個char


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
//C++ 弱
//竟然不能 string s = "a" + "b";
//純字串相鄰相加就錯  一定要至少一邊是個字串變數  差


////89
//短字串小於長字串
//字元可以跟字串相加
//string s3 = s1 + "," + s2 + '\n';


//88

//86
//字串操作
//getline(istream, s)  讀一行    遇到newline停
//s.empty()   是否空
//s.size() 長度   回傳值是 string::size_type  是一個unsign特性且可計數任何字串長度的型別  可用auto 或decltype來接打字比較少
//s[i]

//string > < 用字典序


//cout << "a" << endl;
//cout << "b" << endl;//換行
//
//
//讀未知數目字串  直到eof 或無效輸入
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
//string s2 = s1;//空字串
//string s3 = "abc";
//string s4(10, 'c'); // 10個c
//string s6("afg");
//string s6(s3);
//
//string 可用在 cin cout




////p82
//string 長度可變的一個字元序列
//vector 長度可變的物件序列

////滿誇張的  說的和C#不同  竟然建議一個個引入  C#寫那麼久就知道根本沒必要   多一堆額外的費工  幾千行的程式碼可能要加個幾百行 感覺有點不smart
//using std::cin;
//using std::cout;
//using std::endl;

//像我都很聰明  直接用using namespace

//又說  h檔不該包含using  因為h會被引用   容易跟其他印入的程式的using衝突



////p77
//一個header不能被引入多次  所以可以用preprocessor(前置處理器)  來做到安全引入
//
//_H就是點h 前面同檔名     這就叫header guard  都大寫
//#ifndef PCH_H
//#define PCH_H
//
//// content here
//
//#endif //PCH_H

//#include 在 preprocessor處理會替代成那個標頭檔的內容  相當於併進來

//p76
//單檔中只能有一個類別定義   多個檔案  每檔的類別定義需相同
//定義在標頭就可引用共用   h檔名稱 跟類別名稱習慣相同


//p75  main
////Sales_data  如果定義在同個檔案  要放在main前面
////所以寫在h檔  還真的可以
//Sales_data d1, d2;
//double price = 0;
//cin >> d1.bookNo >> d1.units_sold >> price;
//d1.revenue = d1.units_sold * price;
////d2同理
//
//int pause;
//cin >> pause;


////p71
////帶雙括號的decltype永遠是 參考型別
//decltype((i)) d; // d是 int&且要被初始化

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

//decltype  擷取型別  不取值
//decltype(f()) sum = 3;


//p69
//auto 我看就是 C#的var
//int i = 0;
//const int ci = i, &crr = i;
//auto &g = ci;  
//auto &h = 42; //  不可參考  到  基本型別 + 可當常數型別   ( 字面值  p66
//const auto &j = 42;// const 參考 可繫節至   字面值

//p67
//// type alias
//typedef double wages;//wages是double的同義詞
//typedef wages base, *p;//base 是double "     p是double*的同義詞
//typedef double wages;
//
////alias declaration  類別別名
//using SI = Sales_item;
//
//typedef char *pstring; // pstring是char*指標
//const pstring cstr = 0; // char *  指向char的 常數指標
//const pstring *ps; // 指向char* 的 指標

//p66
//常數運算式  用在跨好幾層呼叫的值驗證來源是常數
//constexpr int mf = 20;
//constexpr int mf = size();//有可能不是  可透過此寫法檢查


////p63
//const指標  出是畫後  指向的位址不能變
//int a = 0;
//int *const c = &a;//永遠指向a
//const int a = 0;
//const int *const c = &a;//跟上面的差異是 要指向const物件 最前面就要加上const   下面a的值不能變 上面可變



//p62
//參考
//int i = 2;
//int &r = i;
//const int &r2 = i;//r2是const參考 不能拿來改變 i  但r可以  也因為i非cnost
//r1 = 0;//i變0
//r2 = 0;//error

//指標
//const int i = 2;
//int *r = &i; // error 非const
//const int *r2 = &i;//ok 
//*r2 = 0;//error const不可變


//p61
//參考的行跌 要和 指向的物件型別相同 有兩例外
//1. 能用可被轉換為該參考型別 的任何運算式來初始對const的參考
//2. const可以指向非const   反之不行
//int = 42;
//const int &r1 = i;
//double d = 3.14
//const int &r = d;
//參考如上   指標亦同

//p60
//const的作用範圍是單個檔案
//所以多個檔案都要用到  每個檔都要寫definition
//
//如果要一檔定義多檔能參照共用
//.h
//extern const int bufSize;  //extern表不是區域變數 而是其他檔案可看見
//.cc
//extern const int bufSize = fcn();



////p59
//const 無法變更的變數    一定要初始給值
//const int i = getVal() 或 42;



//p58   指標**  dereference也是**
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
//int *p;// p是對int的一個指標
//int *&r = p;//r是對指標p的一個參考   &r 可以看成就是r  的意思  參考賦值時寫&r  之後操作都是用r  
////所以類似 int *r = p 也就是r就是p
//r = &i;// r = p = &i >> p = i的位址
//*r = 0;// r = p = i的位址  的*取值 = 0  >> i = 0;



//p57 
//int* p, p2  //p指標 p2只是int    *不會自動套用  分開看

//p56
//void* 可放任何類型指標  但型別未知 所以能做的事很少



//p55
//int v = 12;
//int *pi = 0;
//int *pi2 = &v;
//if(pi) // 0指標 false
//if(pi2)// 非0指標 true
//指標可用 == 比較


////p53
//int ival = 3;
//int *p = &ival;   右邊位址  傳給左邊指標
//cout << *p;   這裡*p就是取值了
//*p = 123; //= ival賦值
// p = 0; 讓指標變成null指標   沒有指向任何物件

// int *p1 = nullptr; //空值指標  沒有指向任何物 = int *p = 0;


//p52   
//int v = 42;
//int *p = &v;


//p51說不能定義參考的參考   因為參考不是物件  他們沒有位址
//但13戒好像有 雙* pointer?
//參考不能指向純量的型別值   例如字串數字
//指標的型別要對應指向物件的型別
//p51    &也可用在宣告   取完&有點類似取得物件的別名  可以在對他get set 等同對原本的值操作
//int i = 1024, i2 = 2;
//int &r = i, r2 = i2;

//p50
//int ival = 1024;
//int &refVal = ival;    int & 直接想程是別名
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
//cout << --i << endl;    很大的數字
//cout << --i << endl;
//cin >> i;
//cout << i;
//
//cin >> i;


//十三戒
//
//int *p = (int*)malloc(100000000);//配置記憶體  工作管理員能看到爆增
//
//int i;
//cin >> i;
//
//free(p);//釋放   工作管  變超低  立刻反映
//cin >> i;
//



//戒3
////http://www.cplusplus.com/reference/cstdio/fgets/
////fgets
////char * fgets(char * str, int num, FILE * stream);
////Get string from stream
////
////char *name;   /* name 尚未指向有效的空間 */
////printf("Your name, please: ");
////fgets(name, 20, stdin);   /* 您確定要寫入的那塊空間合法嗎??? */
////printf("Hello, %s\n", name);
//

//這是因為 gets 函式無法知道字元陣列的大小，而是依賴換行符號或 EOF 才會結束輸入，因此有可能引發緩衝區溢位的安全問題，有興趣可以參考〈Why is the gets function so dangerous that it should not be used ? 〉。
//
//從 C11 之後，gets 已經不再是標準函式之一，你可以使用 fgets 來取代 get，使用時必須指定字元陣列、大小以及 stdin：
//
//char str[20];
//
//puts("請輸入字串：");
//gets(str);
//
//puts("輸入的字串為：");
//puts(str);
//
//return 0;

//戒6
//int *p = (int*)malloc(sizeof(int));
//free(p);
//p = NULL;
//free(p);
//
//C++11後新增智能指標(smart pointer) : unique_ptr
//當unique_ptr所指物件消失時，會自動釋放其記憶體，不需要delete。
//
//例：
//#include <memory>    // 含unique_ptr的標頭檔
//std::unique_ptr<int> p1(new int(5));
//
//戒10
//C :
//int *array = (int*)malloc(10000000 * sizeof(int));
//
//C++:
//std::vector<int> v;
//v.resize(10000000);
//
//說明：建議將使用空間較大的變數用malloc / new配置在 heap 上，由於此時 stack
//上只需配置一個 int* 的空間指到在heap的該變數，可避免 stack overflow。
//
//使用 heap 時，雖然整個 process 可用的空間是有限的，但採用動態抓取
//的方式，new 無法配置時會丟出 std::bad_alloc 例外，malloc 無法配置
//時會回傳 null(註2)，不會影響到正常使用下的程式功能

//
//& * 用法   &取位址  *取值   *宣告時代表指標
//int num1 = 2, num2 = 3;
//int *pi_1, *pi_2;  //宣告指向整數的指標變數
//pi_1 = &num1;  //用指標pi_1指向num1的位置
//printf("pi_1 = %d\r\n", *pi_1); //pi=2
//pi_2 = &num2;//用指標pi_2指向num2的位置
//printf("pi_2 = %d\r\n", *pi_2); //pi=2


//戒13
//函式內 new 出來的空間記得要讓主程式的指標接住
//
//
//對指標不熟悉的使用者會以為以下的程式碼是符合預期的
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
//接著就會找了很久的 bug，最後仍然搞不懂為什麼 ptr 沒有指向剛剛拿到的合法空間
//
//
//讓我們再回顧一次，並且用圖表示(感謝Hazukashiine板友提供圖解)
//
//┌────┐      ┌────┐      ┌────┐      ┌────┐
//Heap   │        │      │        │      │ 新配置 │      │ 已泄漏 │
//│        │      │        │      │ 的空間 ＜─┐  │ 的空間 │
//│        │      │        │      │(allocd)│  │  │(leaked)│
//│        │      │        │      ├────┤  │  ├────┤
//│        │      │        │      │   ：   │  │  │        │
//│        │      │        │      │   ：   │  │  │   ：   │
//│        │      ├────┤      ├────┤  │  │   ：   │
//│        │      │ local  ├─┐  │ local  ├─┘  │        │
//├────┤      ├────┤  │  ├────┤      ├────┤
//Stack  │  ptr   ├─┐  │  ptr   ├─┤  │  ptr   ├─┐  │  ptr   ├─┐
//└────┘  ╧  └────┘  ╧  └────┘  ╧  └────┘  ╧
//
//
//未初始化          函式呼叫          配置空間          函式返回
//int *ptr;       local = ptr;    local = malloc();
//
//
//用圖看應該一切就都明白了，我也不需冗言解釋
//
//
//也許有人會想問，指標不是傳址嗎？
//
//精確來講，指標也是傳值，只不過該值是一個位址(ex: 0xfefefefe)




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


//戒5
//char *getstr(char *name)
//{
//	char buf[30] = "hello, "; /*將字串常數"hello, "的內容複製到buf陣列*/
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
//#include <string>    /* 並非 #include <cstring> */
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
//cin  一直讀到結尾或錯誤非數字    果然快  到這邊打這段程式的熟練度和打字速度  已經跟C#差不多了
//
//int value = 0;
//cout << "c" << endl;
//
//while (std::cin >> value)    Ctrl Z 真的是 eof
//{
//	cout << "c" << endl;    這邊怪  不會進來  
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
