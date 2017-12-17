cmake_minimum_required(VERSION 3.9)
project(template_render)

set(CMAKE_CXX_STANDARD 11)

add_executable(template_render
		TemplateRender/src/bl/HTML.cpp
		TemplateRender/src/include/HTML.h
		TemplateRender/src/bl/IfStatement.cpp
		TemplateRender/src/include/IfStatement.h
		TemplateRender/src/bl/LoopStatement.cpp
		TemplateRender/src/include/LoopStatement.h
		TemplateRender/src/bl/Parameters.cpp
		TemplateRender/src/include/Parameters.h
		TemplateRender/src/bl/Parser.cpp
		TemplateRender/src/include/Parser.h
		TemplateRender/src/include/Regex.h
		TemplateRender/src/include/Config.h
		TemplateRender/src/context/Context.cpp
		TemplateRender/src/include/Context.h
		TemplateRender/src/render/TemplateRender.cpp
		TemplateRender/src/include/TemplateRender.h
		TemplateRender/test/Tests.h
		TemplateRender/src/include/Header.h
		TemplateRender/src/utils/RenderError.cpp
		TemplateRender/src/include/RenderError.h
		TemplateRender/AppStart.cpp
		TemplateRender/src/config/Config.cpp
		TemplateRender/src/include/Defines.h)
