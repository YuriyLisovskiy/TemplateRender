#include "RenderError.h"
#include <iostream>

std::string RenderError::TEMPLATE = "";

RenderError::RenderError(const std::string& message, const std::string& file, const int line, const std::string& errorLine, const std::string& extraMsg)
{
	this->message = "\nException occurred:\n File: '" + file + "', Line: " + std::to_string(line) + "\n Message: '" + message + "'\n";
	if (errorLine.size() > 0 && RenderError::TEMPLATE.size() > 0)
	{
		this->message += " Template: " + this->getError(errorLine) + '\n';
	}
	if (extraMsg.size() > 0)
	{
		this->message += " Message: " + extraMsg + '\n';
	}
}

const char* RenderError::what() const noexcept
{
	return this->message.c_str();
}

std::string RenderError::getError(const std::string& errorLine)
{
	std::string result("");
	if (RenderError::TEMPLATE.size() > 0)
	{
		size_t errPos = RenderError::TEMPLATE.find(errorLine);
		if (errPos != std::string::npos)
		{
			size_t errLine = 0;
			std::string::iterator begin = RenderError::TEMPLATE.begin(), end = RenderError::TEMPLATE.begin() + errPos;
			for (std::string::iterator it = begin; it != end; it++)
			{
				if (*it == '\n')
				{
					errLine++;
				}
			}
			result = "syntax '" + errorLine + "' is invalid, Line: " + std::to_string(errLine + 1);
		}
		else
		{
			result += errorLine;
		}
	}
	return result;
}
