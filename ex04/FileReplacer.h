#ifndef FILEREPLACER_H
#define FILEREPLACER_H

#include <fstream>
#include <string>

#ifndef ANIMATION_DELAY
#define ANIMATION_DELAY 0
#endif

class FileReplacer {
private:
	std::string fileName;
	std::ifstream input;
	std::ofstream output;

	void closeFiles();

public:
	size_t totalLines = 0;
	size_t replacedSymbols = 0;
	std::string outputFileName;

	explicit FileReplacer(const std::string &fileName);

	~FileReplacer();

	void replace(const std::string &oldWord, const std::string &newWord);
};


#endif //FILEREPLACER_H
