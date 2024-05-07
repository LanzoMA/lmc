#pragma once

#include <array>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

class LMC
{
public:
	LMC(const char* filename);
	~LMC();

	// Main methods
	void assembleIntoRAM();
	void translateKeywords(std::string label, std::string opcode, std::string operand);
	void execute();

	// RAM methods
	void clearRAM();
	void outputRAM();

    void setShowRamOutput(bool value);
    void setShowInstruction(bool value);

private:
    bool showRamOutput = false;
    bool showInstruction = false;

	int PC = -1;
	int CIR = 999;
	int ACC = 0;

	const int RAM_size = 100;
	std::array<int, 100> RAM = {};

	const int ADD = 100;
	const int SUB = 200;
	const int STA = 300;
	const int LDA = 500;
	const int BRA = 600;
	const int BRZ = 700;
	const int BRP = 800;
	const int INP = 901;
	const int OUT = 902;

	std::string opcodes[11] = {
		"INP", "OUT", "LDA", "STA", "ADD", "SUB", "BRA", "BRZ", "BRP", "HLT", "DAT"
	};

	std::unordered_map<std::string, int> label_lookup;
	std::vector<std::string> label_wait;
	std::vector<int> value_wait;

	const char* filename = "";
	std::ifstream file_manager;

	int data_ptr = 99;

	bool running = true;
	bool branched = false;

	void update(std::string arg1, std::string arg2, std::string arg3);

	bool containsOpcode(std::string opcode_query);
	int getBranchAddress(std::string label_query);

	void clearWaitingList();

	void resetPC();
	void incrementPC();
};
