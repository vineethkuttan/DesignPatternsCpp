#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string
#define cout std::cout

class Screen
{
private:
	string description;

public:
	Screen(string _description)
	{
		description = _description;
	}

	void up()
	{
		cout << description.c_str() << " going up\n";
	}

	void down()
	{
		cout << description.c_str() << " going down\n";
	}


	string toString()
	{
		return description;
	}
};
