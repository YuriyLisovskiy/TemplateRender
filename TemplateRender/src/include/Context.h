#pragma once
#include "RenderError.h"
#include <map>
#include <vector>

class Context
{
private:
	std::map<std::string, std::string> list;
public:
	explicit Context(const std::vector<std::pair<std::string, std::string>>& data);
	std::string getByKey(const std::string& key);
};
