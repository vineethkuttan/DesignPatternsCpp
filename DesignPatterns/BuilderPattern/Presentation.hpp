#pragma once
#include "PresentationBuilder.hpp"
#include<list>
class Presentation
{
private:
	std::list<std::shared_ptr<Slide>> slides;

public:
	void addSlide(std::shared_ptr<Slide> slide)
	{
		slides.push_back(slide);
	}

	void exportIt(std::shared_ptr<PresentationBuilder> builder)
	{
		builder->addSlide(std::make_shared<Slide>("Copyright"));
		for (auto slide : slides)
		{
			builder->addSlide(slide);
		}

	}
};