#include "../src/include/Header.h"
#include <ctime>
#include <iostream>
#include <fstream>
#if defined(_WIN32) || defined(_WIN64)
#define LOCAL_TIME(now, t) localtime_s(&now, &t);
#elif defined(__unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)
#define LOCAL_TIME(now, t) localtime_r(&t, &now);
#endif

void TEST_CASE()
{
	srand(time(nullptr));
	std::vector<int> vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(rand() % 1000);
	}
	std::vector<std::pair<std::string, std::string>> context = {
		{ "first_author", "Yuriy Lisovskiy" },
		{ "second_author", "Yuriy Vasko" },
		{ "third_variable", "third``" },
		{ "title", "Index Page" },
		{ "text_in_snippet_1", "'If' text for testing '#include' tag." },
		{ "text_in_snippet_2", "'Else' text for testing '#include' tag." },
		{ "test_image", "test.png" },
		{ "test_collection", TemplateRender::str<int>(vec) }
	};

	std::cout << "Rendering...";
	clock_t start, finish;
	start = clock();

	TemplateRender::render("index.html", "completed.html", new Context(context));

	finish = clock();
	float renderingTime = (float)(finish - start) / CLOCKS_PER_SEC;
	std::cout << "\nRendering time: " << renderingTime << " sec. ";

	time_t t = time(nullptr);
	struct tm now;
	LOCAL_TIME(now, t);
	std::ofstream logFile(CONFIG::ENDPOINT_DIR + "log.txt", std::ios::app);
	logFile << "[" << now.tm_hour << ':' << now.tm_min << ':' << now.tm_sec << "] Rendering time: " << renderingTime << " sec.\n";
	logFile.close();
}
