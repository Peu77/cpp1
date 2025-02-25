#include "Harl.h"

#include <iostream>

int main(int argc, char** argv) {
	Harl harl;

   	if(argc != 2) {
  		std::cerr << "Usage: " << argv[0] << " <complaint level>" << std::endl;
		return 1;
	}

    std::string userComplaint = argv[1];
    for (size_t i = 0; i < userComplaint.length(); i++)
		userComplaint[i] = toupper(userComplaint[i]);
	harl.complain(userComplaint);
}
