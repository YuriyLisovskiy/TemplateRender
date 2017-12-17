#pragma once
#include <string>

class RenderError : public std::exception
{
private:
	std::string message;
public:
	RenderError(const std::string& message, const std::string& file, int line, const std::string& errorLine = "", const std::string& extraMsg = "");
	const char* what() const noexcept final;
	static std::string TEMPLATE;
private:
	std::string getError(const std::string& errorLine);
};
