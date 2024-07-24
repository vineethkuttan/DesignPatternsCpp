#pragma once
#include "IBookParser.hpp"

class BookParser :public IBookParser
{
public:
	string bookName;
	BookParser(string _bookName)
	{
		bookName = _bookName;
		cout << "Book Parser Intialized\n";
	}
	int getNoOfPages() override
	{
		return (int)bookName.length() * 5;
	}
};