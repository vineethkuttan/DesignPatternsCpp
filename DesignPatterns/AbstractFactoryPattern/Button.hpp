#include<iostream>
#include<memory>
#define unique_ptr std::unique_ptr
#define shared_ptr std::shared_ptr
#define string std::string
class Button
{
public:
	virtual ~Button() = default;
	virtual void paint() = 0;
};

class MacOsButton :public Button
{
public:
	void paint() override
	{
		printf("Painting MacOsButton\n");
	}
};

class WindowsOsButton :public Button
{
public:
	void paint()
	{
		printf("Painting WindowsOsButton\n");
	}
};