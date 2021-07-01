// Utility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <string>
//#include <codecvt>
//#include <locale>

#include <iostream>
//#include <fstream>
#include <sstream>

#include <io.h>

using namespace std;


int main()
{
	//  HTTP GET
	curlpp::Cleanup myCleanup;
	std::ostringstream os;
	os << curlpp::options::Url(std::string("http://example.com"));
	string html = os.str();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
