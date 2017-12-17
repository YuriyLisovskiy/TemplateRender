#pragma once
#include <string>

namespace REGEX
{
	static const std::string FOR_REGEX(R"(for\s*\(\s*(auto|size_t|int)\s*\w+\s*=\s*\d+\s*;\s*\w+\s*(<|>|==|\!=)?\s*\d+\s*;\s*\w*(\+{0,2}|\-{0,2})\s*\))");
	static const std::string FOREACH_REGEX(R"(foreach\s*\(\s*\w+\s+\w+\s*:?\s*\w+\s*\))");
	static const std::string IF_REGEX(R"(if\s*\(\s*((\w+)|(\w+\s*(<|>|==|!=|<=|>=)\s*\w+))\s*\))");
	static const std::string VAR_REGEX(R"(\{\{\s*\w*\s*\}\})");
	static const std::string ELSE_REGEX(R"(\{\s*%\s*else\s*%\s*\})");
	static const std::string BEGIN_IF_REGEX(R"(\{\s*%\s*)" + IF_REGEX + R"(\s*%\s*\})");
	static const std::string BEGIN_FOR_REGEX(R"(\{\s*%\s*)" + FOR_REGEX + R"(\s*%\s*\})");
	static const std::string BEGIN_FOREACH_REGEX(R"(\{\s*%\s*)" + FOREACH_REGEX + R"(\s*%\s*\})");
	static const std::string BEGIN_COMMENT_REGEX(R"(\{\s*%\s*comment\s*\".*\"\s*%\s*\})");
	static const std::string BEGIN_TAG_REGEX("(" + BEGIN_FOR_REGEX + ")|(" + BEGIN_COMMENT_REGEX + ")|(" + BEGIN_IF_REGEX + ")|(" + BEGIN_FOREACH_REGEX + ")");
	static const std::string END_TAG_REGEX(R"(\{\s*%\s*end(for|if|comment)\s*%\s*\})");
	static const std::string COMPARISON_SYMBOL_REGEX(R"(\s*(<|>|==|\!=|<=|>=)\s*)");
	static const std::string INCLUDE_TAG_REGEX(R"(\{\s*%\s*#include\s*\"\w+\.(html|htm)\"\s*%\s*\})");
	static const std::string BLOCK_TAG_REGEX("(" + BEGIN_TAG_REGEX + ")|(" + END_TAG_REGEX + ")");
	static const std::string STATIC_TAG_REGEX(R"(\{\s*%\s*#(?!include)\w*\s*'?\w+(\.\w+)?'?\s*%\s*\})");
	static const std::string EMPTY_TAG(R"(\{\s*%\s*%\s*\})");
	static const std::string INLINE_TAG_REGEX("(" + VAR_REGEX + ")|(" + INCLUDE_TAG_REGEX + ")|(" + STATIC_TAG_REGEX + ")|(" + EMPTY_TAG + ")");
}
