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



//臨時看到  竟然初始有包在ifdef
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




//124
char* arr = str // error char指標不能用string初始化 
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
vector<int>::iterator it;  //可讀寫  不能用在const類型的vector  
vector<int>::const_iterator it2; //可讀不能寫    用在const類型的vector  本身就是常數不能寫  
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
//└────┘  ��  └────┘  ��  └────┘  ��  └────┘  ��
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
