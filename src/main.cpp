#include "lmc.h"
#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    // parse commandline arguments
    if (argc == 1) {
        std::cout << "Please enter a file to execute.\n"
                  << "Try 'lmc [FILENAME]' or 'lmc --help'\n\n";
        return 1;
    }

    bool showRamOutput = false; 
    bool showInstruction = false;

    if (argv[1][0] == '-'){
        if (strcmp(argv[1], "--help") == 0) {
            std::cout << "Try 'lmc [OPTIONS] [FILENAME]'\n\n"
                << "OPTIONS are optional but FILENAME is required.\n\n"
                << "OPTIONS include:\n"
                << "\t--help to print this help page\n"
                << "\t-r to show contents of RAM\n"
                << "\t-i to show each program instruction as it is executed.\n\n";

            return 0;
        }

        bool argSet = false;
        int pos = 1;

        while (!argSet) {
            switch (argv[1][pos]) {
            case 'r':
                std::cout << ">> RAM View Enabled.\n";
                showRamOutput = true; 
                break;

            case 'i':
                std::cout << ">> Instruction View Enabled.\n";
                showInstruction = true;
                break;

            case '\0':
                argSet = true;
                break; 

            default:
                std::cout << "lmc: invalid option -- " << argv[1][pos] << '\n';
                std::cout << "Try 'lmc --help' for more information.\n";
            }

            pos++;
        }


        std::cout << '\n';

        if (argc == 2) {
            std::cout << "Please enter a file to execute.\n"
                      << "Try 'lmc [OPTIONS] [FILENAME]'\n\n";
            return 1;
        }
    }

    const char* filename = (argc == 2) ? argv[1] : argv[2];

	LMC lmc(filename);
    lmc.setShowRamOutput(showRamOutput);
    lmc.setShowInstruction(showInstruction);

	lmc.assembleIntoRAM();
	lmc.execute();

	return 0;
}
