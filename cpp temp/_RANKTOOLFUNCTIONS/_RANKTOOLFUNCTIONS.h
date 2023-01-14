#pragma once

#define _RANKTOOLFUNCTIONS __declspec(dllexport) 
#include "weaponList.h"


namespace RANKTOOLFUNCTIONS {

    __declspec(dllexport) inline unsigned long long rankCreditEarnings(unsigned long long rank);
    __declspec(dllexport) inline unsigned long long creditRankEarnings(unsigned long long credits);
    __declspec(dllexport) inline unsigned long long rankXPRequirement(unsigned long long initial, unsigned long long target, unsigned long long currentRankXPEarnings);
    __declspec(dllexport) inline unsigned long long XPRankRequirement(unsigned long long required);
    __declspec(dllexport) inline unsigned long long charToUnsignedLongLong(char input[]);
    __declspec(dllexport) inline long long charToLongLong(char input[]);
    __declspec(dllexport) inline unsigned long charToUnsignedLong(char input[]);
    __declspec(dllexport) inline long charToLong(char input[]);
    __declspec(dllexport) inline int charToInt(char input[]);
    __declspec(dllexport) inline unsigned long long XPFarmCalculator(long double team1, long double team2, long double delayPerCycle);
    __declspec(dllexport) inline std::string discriminant(std::string);


}


namespace misc {
    static std::string sep1 = ("@");
    static std::string sep2 = ("`");
    static std::string nameReturn, rankReturn, categoryReturn;
}


inline weaponList::weaponList(std::string nameStr, int rankInt) : name(nameStr), rank(rankInt) {

    for (int i = 0; i < 32; i++) { //determines category of weapon

        if (name == categories::BattleRifles[i]) {

            category = ("Battle Rifles");
            break;

        } else if (name == categories::DesignatedMarksmanRifles[i]) {

            category = ("Designated Marksman Rifles");
            break;

        } else if (name == categories::SniperRifles[i]) {

            category = ("Sniper Rifles");
            break;

        } else if (name == categories::Carbines[i]) {

            category = ("Carbines");
            break;

        } else if (name == categories::PersonalDefenseWeapons[i]) {

            category = ("Personal Defense Weapons");
            break;

        } else if (name == categories::LightMachineGuns[i]) {

            category = ("Light Machine Guns");
            break;

        } else if (name == categories::AssaultRifles[i]) {

            category = ("Assault Rifles");
            break;

        } else if (name == categories::Shotguns[i]) {

            category = ("Shotguns");
            break;

        } else if (name == categories::Pistols[i]) {

            category = ("Pistols");
            break;

        } else if (name == categories::MachinePistols[i]) {

            category = ("Machine Pistols");
            break;

        } else if (name == categories::Revolvers[i]) {

            category = ("Revolvers");
            break;

        } else if (name == categories::Other[i]) {

            category = ("Other");
            break;

        } else if (name == categories::RankedMelees[i]) {

            category = ("Ranked Melees");
            break;

        } else if (name == categories::UnrankedMelees[i]) {

            category = ("Unranked Melees");
            break;

        }

        //std::cout << i << "\n";

    }

}

