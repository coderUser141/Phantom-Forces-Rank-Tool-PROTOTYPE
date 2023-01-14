#include <iostream>
#include <string>
#include "rankxp.h"

//xp earned per rank
inline unsigned long long rankXPRequirement(unsigned long long initial, unsigned long long target, unsigned long long currentRankXPEarnings) {
	unsigned long long requirement = 0;
	std::cin >> currentRankXPEarnings;
	if (target == 0 || target == initial || target < initial || currentRankXPEarnings > (initial + 1) * 1000 || initial < 0 || target < 0 || currentRankXPEarnings < 0) {
		//Error.
		return -1;
	}else {
		for (int i = 0; i <= target; i = !i ? !i * !i : i + !!i) { //for loop meme :P  https://imgur.com/HqokrAg
			requirement += i * 1000; //calculates and accumulates the target rank's xp
		}
		for (int j = 0; j <= initial; j = !j ? !j * !j : j + !!j) {
			requirement -= j * 1000; //subtracts by the accumulation of existing rank
		}
		requirement -= currentRankXPEarnings; //subtracts by rank's earnings
		return requirement;
	}
}

//rank earned per xp
inline unsigned long long XPRankRequirement(unsigned long long required) {
	unsigned long long testAccumulation = 0; //used to count up to the correct rank
	if (required == 0 || required < 0 || required > 5000050000000) { //4g prevention
		//Error.
		return -1;
	}
	else {
		for (unsigned long long i = 0; i < 5000050000000; i = !i ? !i * !i : i + !!i) {
			testAccumulation += i * 1000;
			if (testAccumulation + ((i + 1) * 1000) > required && testAccumulation <= required) { //finds a middle ground that satisfies these properties
				return i;
				break;
			}
		}
	}
}