#include "lmc.h"

int main()
{
	LMC* lmc = new LMC("main.txt");

	lmc->assembleIntoRAM();
	lmc->outputRAM();
	lmc->execute();

	delete lmc;

	system("pause");

	return 0;
}
