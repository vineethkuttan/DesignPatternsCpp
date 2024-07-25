#pragma once
#include "Presentation.hpp"
#include "PdfDocumentBuilder.hpp"
#include "MovieBuilder.hpp"
int main()
{
	Presentation presentation;
	presentation.addSlide(std::make_shared<Slide>("Slide 1"));
	presentation.addSlide(std::make_shared<Slide>("Slide 2"));

	std::shared_ptr<PdfDocumentBuilder> builder = std::make_shared<PdfDocumentBuilder>();
	presentation.exportIt(builder);
	std::shared_ptr<PdfDocument> pdf = builder->getPdfDocument();

	std::shared_ptr<MovieBuilder> builderM = std::make_shared<MovieBuilder>();
	presentation.exportIt(builderM);
	std::shared_ptr<Movie> movie = builderM->getMovie();
}