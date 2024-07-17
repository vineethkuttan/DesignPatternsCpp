#pragma once
#include "BookParser.hpp"
class LazyBookParser : IBookParser
{
private:
	string book;
	shared_ptr<BookParser> bPtr;
public:
	LazyBookParser(string _book)
	{
		book = _book;
		cout << "Lazy Book Parser Intialized\n";
	}
	int getNoOfPages() override
	{
		cout << __FUNCTION__<<" called\n";
		if (bPtr == nullptr)
			bPtr = std::make_shared<BookParser>(book);
		return bPtr->getNoOfPages();
	}
};
