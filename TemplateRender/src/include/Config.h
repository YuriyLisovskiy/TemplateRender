#pragma once
#include <string>
#include "Defines.h"

namespace CONFIG
{
	// Info:
	// Location of template.
	static const std::string TEMPLATE_DIR(ROOT_DIR + "test/templates/");

	// Info:
	// Location of rendered HTML document.
	static const std::string ENDPOINT_DIR(ROOT_DIR + "test/");

	// Info:
	// Location of all media files.
	static const std::string MEDIA_DIR(ROOT_DIR + "test/media/");
}