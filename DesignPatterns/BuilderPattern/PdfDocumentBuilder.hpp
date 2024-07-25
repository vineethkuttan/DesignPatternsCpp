#pragma once
#include "PresentationBuilder.hpp"
#include "PdfDocument.hpp"
#include<memory>
class PdfDocumentBuilder :public PresentationBuilder
{
private:
	std::shared_ptr<PdfDocument> document = std::make_shared<PdfDocument>();
public:
	void addSlide(std::shared_ptr<Slide> slide) override
	{
		document->addPage(slide->getText());
	}

	std::shared_ptr<PdfDocument> getPdfDocument()
	{
		return document;
	}
};