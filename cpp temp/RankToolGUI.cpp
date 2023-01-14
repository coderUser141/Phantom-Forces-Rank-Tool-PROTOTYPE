/*

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "XP.cpp"
#include "CREDS.cpp"
#include "STORAGE.cpp"
#include "rankxp.h"

int main() {
	char init; //initiation
	char rankInit; //rank GUI initiation
	char credInit; //credit GUI initiation
	char rankXPStorage;
	char XPRankStorage;
	char rankCreditsStorage;
	char creditRankStorage;
	char action3;
	std::cout << "Welcome to the PF Rank Tool! This tool was made by Kyviro, who can be reached out on Discord (Username is Kyviro#5659). \n \n";
	std::cout << "To start the tool, please input 1 for rank calculations, input 2 for credit calculations, or input 3 to get values from storage. \n";
	std::cin >> init;
	if (init == '1') {
		//rank route
		std::cout << "\nTo determine a rank's required amount of XP, type in 1. To determine what rank is yielded by an amount of XP, type in 2. \n";
		std::cin >> rankInit;
		if (rankInit == '1') {
			//rankXPRequirement function initiation
			int rankXPR = rankXPRequirement();
			std::cout << "\n\nThe required XP is " << rankXPR << "\n";
			std::cout << "Do you want to store this value? (Y/N) \n";
			std::cin >> rankXPStorage;
			if (rankXPStorage == 'Y' || rankXPStorage == 'y') {
				//fileStorageSet
				fileStorage(rankXPR);
			}else if (rankXPStorage == 'N' || rankXPStorage == 'n') {
				std::cout << "Do you want to exit the program? (Y/N) \n";
				std::cin >> action3;
				if (action3 == 'Y' || action3 == 'y') {
					finalPush();
					return 0; //End.
				}else if (action3 == 'N' || action3 == 'n') {
					callMain();
				}else {
					std::cout << "Error; Restarting. \n"; //Error.
					callMain();
				}
			}else {
				std::cout << "Error; Restarting. \n"; //Error.
				callMain();
			}
		}else if (rankInit == '2') {
			//XPRankRequirement function initiation
			int XPRankR = XPRankRequirement();
			std::cout << "\n\nThe rank is " << XPRankR << "\n";
			std::cout << "Do you want to store this value? (Y/N) \n";
			std::cin >> XPRankStorage;
			if (XPRankStorage == 'Y' || XPRankStorage == 'y') {
				//fileStorageSet
				fileStorage(XPRankR);
			}else if (XPRankStorage == 'N' || XPRankStorage == 'n') {
				std::cout << "Do you want to exit the program? (Y/N) \n";
				std::cin >> action3;
				if (action3 == 'Y' || action3 == 'y') {
					finalPush();
					return 0; //End.
				}else if (action3 == 'N' || action3 == 'n') {
					callMain();
				}else {
					std::cout << "Error; Restarting. \n"; //Error.
					callMain();
				}
			}else {
				std::cout << "Error; Restarting. \n"; //Error.
				callMain();
			}
			//fileStorageSet
		}else {
			std::cout << "Error; Restarting. \n"; //Error.
			callMain();
		}
	}else if (init == '2') {
		//credit route
		std::cout << "\nTo deterine the amount of credits a rank earns, type in 1. To determine the amount of ranks to achieve a certain credit earning, type in 2. \n";
		std::cin >> credInit;
		if (credInit == '1') {
			//rankCreditEarnings initiation
			int RankCredR = rankCreditEarnings();
			if (RankCredR > 200) {
				std::cout << "\n\nThe credits earned is equal to " << RankCredR << "\n";
				std::cout << "Do you want to store this value? (Y/N) \n";
				std::cin >> rankCreditsStorage;
				if (rankCreditsStorage == 'Y' || rankCreditsStorage == 'y') {
					//fileStorageSet
					fileStorage(RankCredR);
				}
				else if (rankCreditsStorage == 'N' || rankCreditsStorage == 'n') {
					std::cout << "Do you want to exit the program? (Y/N) \n";
					std::cin >> action3;
					if (action3 == 'Y' || action3 == 'y') {
						finalPush();
						return 0; //End.
					}else if (action3 == 'N' || action3 == 'n') {
						callMain();
					}else {
						std::cout << "Error; Restarting. \n"; //Error.
						callMain();
					}
				}else {
					std::cout << "Error; Restarting. \n"; //Error.
					callMain();
				}
			}else {
				std::cout << "Error; Restarting. \n"; //Error.
				callMain();
			}
		}else if (credInit == '2') {
			//creditRankEarnings initiation
			int CredRankR = creditRankEarnings();
			if (CredRankR >= 0) {
				std::cout << "\n\nThe rank it is earned at is " << CredRankR << "\n";
				std::cout << "Do you want to store this value? (Y/N) \n";
				std::cin >> creditRankStorage;
				if (creditRankStorage == 'Y' || creditRankStorage == 'y') {
					//fileStorageSet
					fileStorage(CredRankR);
				}else if (creditRankStorage == 'N' || creditRankStorage == 'n') {
					std::cout << "Do you want to exit the program? (Y/N) \n";
					std::cin >> action3;
					if (action3 == 'Y' || action3 == 'y') {
						finalPush();
						return 0; //End.
					}else if (action3 == 'N' || action3 == 'n') {
						callMain();
					}else {
						std::cout << "Error; Restarting. \n"; //Error.
						callMain();
					}
				}else {
					std::cout << "Error; Restarting. \n"; //Error.
					callMain();
				}
			}else {
				std::cout << "Error; Restarting. \n"; //Error.
				callMain();
			}
		}else {
			std::cout << "Error; Restarting. \n"; //Error.
			callMain();
		}
	}else if (init == '3') {
		fileStorage(0);
	}else {
		std::cout << "Error. \n"; //Error.
	}
}

void exitLoop() {
	char action2;
	char action3;
	std::cout << "Do you want to set or get again? (Y/N) \n";
	std::cin >> action2;
	if (action2 == 'Y' || action2 == 'y') {
		fileStorage(0);
	}else if (action2 == 'N' || action2 == 'n') {
		std::cout << "Do you want to exit the program? (Y/N) \n";
		std::cin >> action3;
		if (action3 == 'Y' || action3 == 'y') {
			std::cout << push[0];
			finalPush();
			//End.
		}else if (action3 == 'N' || action3 == 'n') {
			callMain();
		}else {
			//Error.
			std::cout << "Error.";
			end();
		}
	}else {
		//Error.
		std::cout << "Error.";
		end();
	}
}

void callMain(){
	main();
}

int end() {
	return 0;
}

*/