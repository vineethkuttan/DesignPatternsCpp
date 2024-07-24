#include "History.hpp"
#include "Editor.hpp"

int main()
{
	Editor es;
	History hs;
	es.content = "First";
	hs.pushState(es.CreateState());
	es.content = "Second";
	hs.pushState(es.CreateState());
	std::cout << es.content << "\n";
	es.restore(hs.popState());
	std::cout << es.content << "\n";
	es.content = "Third";
	hs.pushState(es.CreateState());
	es.content = "Fourth";
	hs.pushState(es.CreateState());
	std::cout << es.content << "\n";
	es.restore(hs.popState());
	std::cout << es.content << "\n";
	es.restore(hs.popState());
	std::cout << es.content << "\n";
}
