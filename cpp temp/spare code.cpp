#include <iostream>
#include <string>
#include <locale>

unsigned long long XPFarmCalculator(double team1, double team2, double delayPerCycle){

    int time = 15 * 60 - 20; //time to farm
    std::cout << "\n" << time << "\n";
    long double team1CD = 5 / team1; //duration (S) for team1
    std::cout << std::fixed << team1CD << "\n";
    long double team2CD = 5 / team2; //duration (S) for team2
    std::cout << std::fixed << team2CD << "\n";
    long double total = team2CD + (delayPerCycle / 2) + team1CD + (delayPerCycle / 2); // one whole cycle
    std::cout << std::fixed << total << "\n";
    long double cycles = time/total; //number of cycles (possible decimal)
    std::cout << std::fixed << cycles << "\n";
    unsigned long long floored = floor(cycles); //number of FULL cycles
    std::cout << std::fixed << floored << "\n";
    unsigned long long score = floored * 400;
    std::cout << std::fixed << score << "\n";


    return score;

}

//use this file to perform surgery on functions

