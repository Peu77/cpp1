#include <iostream>
#include "colors.h"
#include "FileReplacer.h"

int main(const int argc, char *argv[]) {
	const auto printUsage = [argv]() {
		std::cerr << RED << "Usage: " << RESET << argv[0] << " <filename> <oldword> <newword>" << std::endl;
	};

	if (argc != 4) {
		printUsage();
		return 1;
	}

	if (!argv[1][0] || !argv[2][0] || !argv[3][0]) {
		std::cerr << RED << "None of these arguments should be empty" << RESET << std::endl;
		printUsage();
		return 1;
	}
	const std::string fileName(argv[1]);
	const std::string oldWord(argv[2]);
	const std::string newWord(argv[3]);

	if (!std::filesystem::exists(fileName)) {
		std::cerr << RED << "The input file doas not exist" << RESET << std::endl;
		return 1;
	}

	if (!std::filesystem::is_regular_file(fileName)) {
		std::cerr << RED << "The input file is not a regular file" << RESET << std::endl;
		return 1;
	}

	FileReplacer fileReplacer(fileName);
	try {
		fileReplacer.replace(oldWord, newWord);
		std::cout << GREEN << BOLD << "File replaced successfully:" << RESET << std::endl;
		std::cout << std::right << GREEN << "Output file:            " << RESET << fileReplacer.outputFileName << std::endl;
		std::cout << std::right << GREEN << "Total replaced symbols: " << RESET << fileReplacer.replacedSymbols << std::endl;
		std::cout << std::right << GREEN << "Total lines:            " << RESET << fileReplacer.totalLines << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Error while replacing file: " << RESET << e.what() << std::endl;
		return 1;
	}
	return 0;
}
