#include "lmc.h"
#include <iostream>
#include <algorithm>
#include <sstream>

LMC::LMC(const char* filename) : filename(filename) {
	file_manager.open(filename);

	if (!file_manager.is_open()) {
		std::cout << "Error: Unable to open file.\n";
	}
}

LMC::~LMC() { }

void LMC::assembleIntoRAM()
{
	std::cout << "Assembling program into RAM...\n\n";

	std::string line, arg1, arg2 ,arg3;

	while (file_manager) {
		arg1 = ""; arg2 = ""; arg3 = "";

		std::getline(file_manager, line, '\n');
		std::stringstream ss(line);
		std::getline(ss, arg1, ' ');

		if (arg1.compare("#") == 0) {
			continue;
		}

		std::getline(ss, arg2, ' ');
		std::getline(ss, arg3, '\n');

		if (arg1.compare("") == 0 && arg2.compare("") == 0 && arg3.compare("") == 0) {
			continue;
		}

		if (!file_manager)
			break;
	
		incrementPC();
		update(arg1, arg2, arg3);
	}

	clearWaitingList();
    if (showRamOutput) outputRAM();
}

// Assembles one line of LMC code to RAM.
void LMC::translateKeywords(std::string label, std::string opcode, std::string operand) {
	if (opcode.compare("DAT") == 0) {
		if (operand.compare("") != 0) {
			RAM[data_ptr] = stoi(operand);
			label_lookup.insert({ label, data_ptr });
		}

		else {
			RAM[data_ptr] = 0;
			label_lookup.insert({ label, data_ptr });
		}

		data_ptr--;
		return;
	}

	// Checks if there is a label in the label column;
	else if (label.compare("") != 0) {
		label_lookup.insert({ label, PC });
	}

	if (opcode.compare("INP") == 0) {
		RAM[PC] = 901;
		return;
	}

	if (opcode.compare("OUT") == 0) {
		RAM[PC] = 902;
		return;
	}

	if (opcode.compare("ADD") == 0) {
		RAM[PC] = 100 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("SUB") == 0) {
		RAM[PC] = 200 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("STA") == 0) {
		RAM[PC] = 300 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("LDA") == 0) {
		RAM[PC] = 500 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("BRA") == 0) {
		RAM[PC] = 600 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("BRZ") == 0) {
		RAM[PC] = 700 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("BRP") == 0) {
		RAM[PC] = 800 + getBranchAddress(operand);
		return;
	}

	if (opcode.compare("HLT") == 0) {
		RAM[PC] = 0;
	}

	return;
}

// Converts arguments into labels, opcodes and operands.
void LMC::update(std::string arg1, std::string arg2 = "", std::string arg3 = "") {
	// If arg1 has the opcode, arg2 may contain an operand or nothing.
	if (containsOpcode(arg1)) {
		// Opcode
		if (arg2.compare("") == 0) {
			translateKeywords("", arg1, "");
			return;
		}

		// Opcode + Operand
		translateKeywords("", arg1, arg2);
		return;
	}

	// If arg2 has the opcode, arg1 is the label and arg3 may contain an operand or nothing.
	else if (containsOpcode(arg2)) {
		// Label + Opcode
		if (arg3.compare("") == 0) {
			translateKeywords(arg1, arg2, "");
			return;
		}

		// Label + Opcode + Operand
		translateKeywords(arg1, arg2, arg3);
		return;
	}
}

void LMC::execute()
{
	std::cout << "Executing program ...\n\n";

	resetPC();

	while (running) {
		// If there was a branch instruction, do not increment the PC.
		if (!branched) incrementPC();
		else branched = false;
			
		CIR = RAM[PC];

        if (showRamOutput) outputRAM();
		if (showInstruction) 
        std::cout << "PC: " << PC + 1 
                  << " CIR: " << CIR 
                  << " ACC: " << ACC 
                  << " Instruction: ";

		switch (CIR) {
		case 901:
		if (showInstruction) 
			std::cout << "INP\n";
			std::cout << "Input: ";
			std::cin >> ACC;
			continue;

		case 902:
		if (showInstruction) 
			std::cout << "OUT\n";
			std::cout << "Output: " << ACC << "\n";
			continue;

		case 0:
		if (showInstruction) 
			std::cout << "HLT\n";
			running = false;
			continue;
		}

		if (CIR >= BRP)
		{
		if (showInstruction) 
			std::cout << "BRP\n";

			if (ACC >= 0) {
				PC = CIR - 800;
				branched = true;
			}
			
			continue;
		}

		if (CIR >= BRZ)
		{
		if (showInstruction) 
			std::cout << "BRZ\n";

			if (ACC == 0) {
				PC = CIR - BRZ;
				branched = true;
			}
			
			continue;
		}

		if (CIR >= BRA)
		{
		if (showInstruction) 
			std::cout << "BRA\n";
			PC = CIR - BRA;
			branched = true;
			continue;
		}

		if (CIR >= LDA)
		{
		if (showInstruction) 
			std::cout << "LDA\n";

			ACC = RAM[CIR - LDA];
			continue;
		}

		if (CIR >= STA)
		{
		if (showInstruction) 
			std::cout << "STA\n";

			RAM[CIR - STA] = ACC;
			continue;
		}

		if (CIR >= SUB)
		{
		if (showInstruction) 
			std::cout << "SUB\n";
			ACC -= RAM[CIR - SUB];
			continue;
		}

		if (CIR >= ADD)
		{
		    if (showInstruction) std::cout << "ADD\n";
			ACC += RAM[CIR - ADD];
		}
	}
}

void LMC::resetPC() { PC = -1; }
void LMC::incrementPC() { PC++; }

void LMC::clearRAM() { RAM = {}; }

void LMC::outputRAM() {
	const int MAX_DISPLAYED = 32;

    std::cout << "RAM:\n";

	for (int i = 0; i < RAM_size; i++) {
		if (i % MAX_DISPLAYED != MAX_DISPLAYED - 1) {
			std::cout << RAM[i] << " ";
			continue;
		}

		else std::cout << RAM[i] << "\n";
	}

	std::cout << "\n\n";
}

bool LMC::containsOpcode(std::string opcode_query) {
	for (int i = 0; i < 11; i++) {
		if (opcode_query.compare(opcodes[i]) == 0) {
			return true;
		}
	}

	return false;
}

// Find where the label points to.
int LMC::getBranchAddress(std::string label_query) {
	if (label_lookup.find(label_query) != label_lookup.end()) {
		int address = label_lookup.at(label_query);
		return address;
	}

	label_wait.push_back(label_query);
	value_wait.push_back(PC);
	return 0;
}

// Ensure labels are converted to locations in memory.
void LMC::clearWaitingList() {
	for (int i = 0; i < label_wait.size(); i++) {
		RAM[value_wait[i]] += label_lookup[label_wait[i]];
	}
}

void LMC::setShowRamOutput(bool value) {
    showRamOutput = value;
}

void LMC::setShowInstruction(bool value) {
    showInstruction = value;
}
