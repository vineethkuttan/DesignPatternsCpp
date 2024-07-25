#pragma once
#include "Slide.hpp"
class PresentationBuilder
{
public:
	virtual void addSlide(std::shared_ptr<Slide> slide) = 0;
};