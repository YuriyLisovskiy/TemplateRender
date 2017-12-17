cmake_minimum_required(VERSION 3.9)
project(template_render)

set(CMAKE_CXX_STANDARD 11)

add_executable(template_render
		TemplateRender/BL/HTML.cpp
		TemplateRender/BL/HTML.h
		TemplateRender/BL/IfStatement.cpp
		TemplateRender/BL/IfStatement.h
		TemplateRender/BL/LoopStatement.cpp
		TemplateRender/BL/LoopStatement.h
		TemplateRender/BL/Parameters.cpp
		TemplateRender/BL/Parameters.h
		TemplateRender/BL/Parser.cpp
		TemplateRender/BL/Parser.h
		TemplateRender/BL/Regex.h
		TemplateRender/Config/Config.h
		TemplateRender/DTO/Context.cpp
		TemplateRender/DTO/Context.h
		TemplateRender/Render/TemplateRender.cpp
		TemplateRender/Render/TemplateRender.h
		TemplateRender/Tests/Tests.h
		TemplateRender/Utils/Header.h
		TemplateRender/Utils/RenderError.cpp
		TemplateRender/Utils/RenderError.h
		TemplateRender/AppStart.cpp
		README.md)
