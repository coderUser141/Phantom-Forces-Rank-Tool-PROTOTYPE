/*#include <iostream>
#include <string>
#include <cmath>
#include "rankxp.h"

//credits earned per rank
inline unsigned long long rankCreditEarnings(unsigned long long rank) {
	if (rank < 0) {
		return -1;
	}else {
		return 200 + (5 * rank);
	}
}

//rank earned per credits
inline unsigned long long creditRankEarnings(unsigned long long credits) {
	if (credits < 200 || credits % 5 > 0 || credits < 0) {
		//Error.
		return -1;
	}
	else {
		for (unsigned long long i = 200; i <= credits; i += 5) {
			if (credits == i) {
				return (i - 200) / 5;
			}
		}
	}
}*/