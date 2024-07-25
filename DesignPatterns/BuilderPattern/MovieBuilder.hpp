#pragma once
#include "PresentationBuilder.hpp"
#include "Movie.hpp"
#include<memory>
class MovieBuilder :public PresentationBuilder
{
private:
	std::shared_ptr<Movie> movie = std::make_shared<Movie>();
public:
	void addSlide(std::shared_ptr<Slide> slide) override
	{
		movie->addFrame(slide->getText(), 3);
	}

	std::shared_ptr<Movie> getMovie() {
		return movie;
	}
};