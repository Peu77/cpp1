#include "FileReplacer.h"

#include <iostream>
#include <thread>

FileReplacer::FileReplacer(const std::string &fileName): fileName(fileName) {
	this->outputFileName = fileName + ".replace";

	try {
		input.open(fileName, std::ios::in);
		output.open(this->outputFileName, std::ios::out);
	} catch (std::exception &e) {
		closeFiles();
		std::cerr << "Error opening file: " << fileName << std::endl;
		std::cerr << e.what() << std::endl;
		return;
	}

	if (!input || !output) {
		if (!input)
			std::cerr << "Error opening input file: " << fileName << std::endl;
		if (!output)
			std::cerr << "Error opening output file: " << this->outputFileName << std::endl;

		closeFiles();
	}
}


FileReplacer::~FileReplacer() {
	closeFiles();
}

static void printLoadingBar(size_t processedLines, size_t totalLines) {
	constexpr size_t barWidth = 70;
	std::cout << "\r[";
	size_t pos = barWidth * processedLines / totalLines;
	for (size_t i = 0; i < barWidth; ++i) {
		if (i < pos) std::cout << "=";
		else if (i == pos) std::cout << ">";
		else std::cout << " ";
	}
	std::cout << "] " << processedLines << "/" << totalLines << " ";
}

void FileReplacer::replace(const std::string &oldWord, const std::string &newWord) {
	std::string line;
	size_t processedLines = 0;

	if (!input.is_open() || !output.is_open())
		throw std::runtime_error("Files are not open");

	while (std::getline(input, line)) {
		this->totalLines++;
	}
	input.clear();
	input.seekg(0, std::ios::beg);

	while (std::getline(input, line)) {
		size_t pos = 0;
		while ((pos = line.find(oldWord, pos)) != std::string::npos) {
			line.erase(pos, oldWord.length());
			line.insert(pos, newWord);
			pos += newWord.length();
			this->replacedSymbols++;
		}
		output << line << std::endl;
		processedLines++;
		printLoadingBar(processedLines, totalLines);
		std::cout << std::flush;
		if constexpr (ANIMATION_DELAY > 0)
			std::this_thread::sleep_for(std::chrono::milliseconds(ANIMATION_DELAY));
	}
	std::cout << std::endl;
}

void FileReplacer::closeFiles() {
	if (input.is_open())
		input.close();
	if (output.is_open())
		output.close();
}
