/*#include <string>
#include <fstream>
#include "rankxp.h"

static int push[64];

inline void fileStorage(int value) {
	std::string action;
	std::cout << "Set or Get?\n";
	std::cin >> action;
	if (action == "Set" || action == "set" || action == "SET") {
		//push array
		for (int i = 0; i < 64; i = !i ? !i * !i : i + !!i) {
			if (push[i] == 0) {
				push[i] = value;
			}
			break;
		}
		exitLoop();
	}else if (action == "Get" || action == "get" || action == "GET") {
		std::string retrievalString;
		std::ifstream dataR;
		dataR.open("PFRANKTOOL.pfrt");
		while (getline(dataR, retrievalString)) {
			std::cout << retrievalString << "\n";
		}
		dataR.close();
		exitLoop();
	}
}

inline void getFileStorage() {
	std::string retrievalString;
	std::ifstream dataR;
	dataR.open("PFRANKTOOL.pfrt");
	while (getline(dataR, retrievalString)) {
		std::cout << retrievalString << "\n";
	}
	dataR.close();
	exitLoop();
}

inline void finalPush() {
	std::ofstream dataW("PFRANKTOOL.pfrt", std::ios_base::app);
	for (int i = 0; i < 64; i = !i ? !i * !i : i + !!i) {
		if (push[i] == 0) {
			break;
		}else {
			dataW << push[i];
			std::cout << push[i];
		}
	}
	dataW.close();
	end();
}*/