#include "../include/TemplateRender.h"
#include "../include/HTML.h"
#include "../include/Config.h"
#include <iostream>

void TemplateRender::render(const std::string& templatePath, const std::string& htmlPath, Context* data)
{
	try
	{
		std::string templateHTML = HTML::read(CONFIG::TEMPLATE_DIR + templatePath);
		RenderError::TEMPLATE = templateHTML;
		std::string completedHTML = Parser::parseInline(templateHTML, data);
		completedHTML = Parser::parseTemplate(completedHTML, data);
		HTML::write(completedHTML, CONFIG::ENDPOINT_DIR + htmlPath);
		std::cout << "\nCompleted!";
	}
	catch (RenderError& exc)
	{
		std::cerr << exc.what();
	}
	catch (const std::exception& exc)
	{
		std::cerr << "\nException occurred: " << exc.what() << '.';
	}
	catch (...)
	{
		std::cerr << "\nException occurred: unknown.";
	}
}
