/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// FUNCTIONALITY FUNCTIONS /////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "_RANKTOOLFUNCTIONS.h"


namespace RANKTOOLFUNCTIONS {

    //credits earned per rank
    __declspec(dllexport) inline unsigned long long rankCreditEarnings(unsigned long long rank) {

        if (rank < 0) {

            return -1;

        } else {

            return 200 + (5 * rank);

        }
    }

    //rank earned per credits
    __declspec(dllexport) inline unsigned long long creditRankEarnings(unsigned long long credits) {

        if (credits < 200 || credits % 5 > 0 || credits < 0) {

            //Error.
            return -1;

        } else {

            for (unsigned long long i = 200; i <= credits; i += 5) {

                if (credits == i) {

                    return (i - 200) / 5;

                }

            }

        }

    }

    //xp earned per rank
    __declspec(dllexport) inline unsigned long long rankXPRequirement(unsigned long long initial, unsigned long long target, unsigned long long currentRankXPEarnings) {

        unsigned long long requirement = 0;
        std::cin >> currentRankXPEarnings;

        if (target == 0 || target == initial || target < initial || currentRankXPEarnings >(initial + 1) * 1000 || initial < 0 || target < 0 || currentRankXPEarnings < 0) {

            //Error.
            return -1;

        } else {

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
    __declspec(dllexport) inline unsigned long long XPRankRequirement(unsigned long long required) {

        unsigned long long testAccumulation = 0; //used to count up to the correct rank

        if (required == 0 || required < 0 || required > 5000050000000) { //4g prevention

            //Error.
            return -1;

        } else {

            for (unsigned long long i = 0; i < 5000050000000; i = !i ? !i * !i : i + !!i) {

                testAccumulation += i * 1000;

                if (testAccumulation + ((i + 1) * 1000) > required && testAccumulation <= required) { //finds a middle ground that satisfies these properties

                    return i;
                    break;

                }

            }

        }

    }

    //converts char to unsigned long long
    __declspec(dllexport) inline unsigned long long charToUnsignedLongLong(char input[]) {

        char* pNext;
        unsigned long long output;
        output = strtoull(input, &pNext, 10);
        return output;

    }

    //extra redundancy to make it easier for future implementations

    //converts char to long long
    __declspec(dllexport) inline long long charToLongLong(char input[]) {

        char* pNext;
        long long output;
        output = strtoll(input, &pNext, 10);
        return output;

    }


    //converts char to unsigned long
    __declspec(dllexport) inline unsigned long charToUnsignedLong(char input[]) {

        char* pNext;
        unsigned long output;
        output = strtoul(input, &pNext, 10);
        return output;

    }


    //converts char to long
    __declspec(dllexport) inline long charToLong(char input[]) {

        char* pNext;
        long output;
        output = strtol(input, &pNext, 10);
        return output;

    }


    //converts char to int
    __declspec(dllexport) inline int charToInt(char input[]) {

        int output;
        output = std::stoi(input);
        return output;

    }

    //farming
    __declspec(dllexport) inline unsigned long long XPFarmCalculator(long double team1, long double team2, long double delayPerCycle) {

        int time = 15 * 60 - 20; //time to farm
        if (team1 < 0 || team2 < 0 || delayPerCycle < 0 || delayPerCycle > 880)return -1;
        unsigned long long score = (floor(time / ((5 / team2) + (delayPerCycle / 2) + (5 / team1) + (delayPerCycle / 2)))) * 400; //calculation spaghetti
        return score;

    }

    //gets user input and discriminates the gun they select (WARNING: LONG)
    __declspec(dllexport) inline std::string discriminant(std::string input) {

        std::string gunName;


        //case-insensitivity
        std::locale loc;
        for (std::string::size_type i = 0; i < input.length(); ++i) {
            gunName += std::toupper(input[i]);
        }

        //colloquial if...else if... statements

        //BATTLE RIFLES ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if (gunName == ("G3")) { //G3

            return G3.name + misc::sep1 + std::to_string(G3.rank) + misc::sep2 + G3.category;

        } else if (gunName == ("AG3") || gunName == ("AG-3")) { //AG-3

            return AG3.name + misc::sep1 + std::to_string(AG3.rank) + misc::sep2 + AG3.category;

        } else if (gunName == ("HENRY") || gunName == ("HENRY 45-70")) { //Henry 45-70

            return HENRY45_70.name + misc::sep1 + std::to_string(HENRY45_70.rank) + misc::sep2 + HENRY45_70.category;

        } else if (gunName == ("FAL 50.00") || gunName == ("FAL 50")) { //FAL 50.00

            return FAL50_00.name + misc::sep1 + std::to_string(FAL50_00.rank) + misc::sep2 + FAL50_00.category;

        } else if (gunName == ("ECR") || gunName == ("BEOWULF ECR")) { // Bweowulf ECR

            return ECR.name + misc::sep1 + std::to_string(ECR.rank) + misc::sep2 + ECR.category;

        } else if (gunName == ("SCAR H") || gunName == ("SCAR-H")) { //SCAR H

            return SCAR_H.name + misc::sep1 + std::to_string(SCAR_H.rank) + misc::sep2 + SCAR_H.category;

        } else if (gunName == ("AK12BR")) { //AK12BR

            return AK12BR.name + misc::sep1 + std::to_string(AK12BR.rank) + misc::sep2 + AK12BR.category;

        } //DESIGNATED MARKSMAN RIFLES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("MK11")) { //MK11

            return MK11.name + misc::sep1 + std::to_string(MK11.rank) + misc::sep2 + MK11.category;

        } else if (gunName == ("SKS")) { //SKS

            return SKS.name + misc::sep1 + std::to_string(SKS.rank) + misc::sep2 + SKS.category;

        } else if (gunName == ("SL-8") || gunName == ("SL8") || gunName == ("SL 8")) { // SL-8

            return SL_8.name + misc::sep1 + std::to_string(SL_8.rank) + misc::sep2 + SL_8.category;

        } else if (gunName == ("VSS VINTOREZ") || gunName == ("VSS") || gunName == ("VINTOREZ")) { //VSS VINTOREZ

            return VSS_VINTOREZ.name + misc::sep1 + std::to_string(VSS_VINTOREZ.rank) + misc::sep2 + VSS_VINTOREZ.category;

        } else if (gunName == ("MSG90") || gunName == ("MSG")) { //MSG90

            return MSG90.name + misc::sep1 + std::to_string(MSG90.rank) + misc::sep2 + MSG90.category;

        } else if (gunName == ("BEOWULF TCR") || gunName == ("TCR")) { //Beowulf TCR

            return TCR.name + misc::sep1 + std::to_string(TCR.rank) + misc::sep2 + TCR.category;

        } else if (gunName == ("SA58 SPR") || gunName == ("SPR") || gunName == ("SA58")) { //SA58 SPR

            return SA58_SPR.name + misc::sep1 + std::to_string(SA58_SPR.rank) + misc::sep2 + SA58_SPR.category;

        } else if (gunName == ("SCAR SSR") || gunName == ("SSR")) { //SCAR SSR

            return SCAR_SSR.name + misc::sep1 + std::to_string(SCAR_SSR.rank) + misc::sep2 + SCAR_SSR.category;

        }//SNIPER RIFLES ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\

        else if (gunName == ("INTERVENTION")) {

            return INTERVENTION.name + misc::sep1 + std::to_string(INTERVENTION.rank) + misc::sep2 + INTERVENTION.category;

        } else if (gunName == ("REMINGTON 700") || gunName == ("R700") || gunName == ("R 700")) {

            return REMINGTON_700.name + misc::sep1 + std::to_string(REMINGTON_700.rank) + misc::sep2 + REMINGTON_700.category;

        } else if (gunName == ("DRAGUNOV SVU") || gunName == ("SVU")) {

            return DRAGUNOV_SVU.name + misc::sep1 + std::to_string(DRAGUNOV_SVU.rank) + misc::sep2 + DRAGUNOV_SVU.category;

        } else if (gunName == ("AWS") || gunName == ("ARCTIC WARFARE SUPPRESSED")) {

            return AWS.name + misc::sep1 + std::to_string(AWS.rank) + misc::sep2 + AWS.category;

        } else if (gunName == ("BFG 50") || gunName == ("BFG50") || gunName == ("BFG .50") || gunName == ("BFG") || gunName == ("BFG-50")) {

            return BFG_50.name + misc::sep1 + std::to_string(BFG_50.rank) + misc::sep2 + BFG_50.category;

        } else if (gunName == ("AWM") || gunName == ("ARCTIC WARFARE MAGNUM") || gunName == ("L115A3") || gunName == ("L115")) {

            return AWM.name + misc::sep1 + std::to_string(AWM.rank) + misc::sep2 + AWM.category;

        } else if (gunName == ("TRG-42") || gunName == ("TRG42") || gunName == ("TRG 42")) {

            return TRG_42.name + misc::sep1 + std::to_string(TRG_42.rank) + misc::sep2 + TRG_42.category;

        } else if (gunName == ("MOSIN NAGANT") || gunName == ("MOSIN") || gunName == ("NAGANT")) {

            return MOSIN_NAGANT.name + misc::sep1 + std::to_string(MOSIN_NAGANT.rank) + misc::sep2 + MOSIN_NAGANT.category;

        } else if (gunName == ("DRAGUNOV SVDS") || gunName == ("SVDS")) {

            return DRAGUNOV_SVDS.name + misc::sep1 + std::to_string(DRAGUNOV_SVDS.rank) + misc::sep2 + DRAGUNOV_SVDS.category;

        } else if (gunName == ("HECATE II") || gunName == ("HECATE") || gunName == ("HECATE 2") || gunName == ("HÉCATE 2") || gunName == ("HÉCATE II")) {

            return HECATE.name + misc::sep1 + std::to_string(HECATE.rank) + misc::sep2 + HECATE.category;

        } else if (gunName == ("M107") || gunName == ("M82A1")) {

            return M107.name + misc::sep1 + std::to_string(M107.rank) + misc::sep2 + M107.category;

        } else if (gunName == ("STEYR SCOUT") || gunName == ("SCOUT") || gunName == ("STEYR")) {

            return STEYR_SCOUT.name + misc::sep1 + std::to_string(STEYR_SCOUT.rank) + misc::sep2 + STEYR_SCOUT.category;

        } else if (gunName == ("WA2000")) {

            return WA2000.name + misc::sep1 + std::to_string(WA2000.rank) + misc::sep2 + WA2000.category;

        }//ASSAULT RIFLES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

        else if (gunName == ("AK12") || gunName == ("AK-12")) {

            return AK12.name + misc::sep1 + std::to_string(AK12.rank) + misc::sep2 + AK12.category;

        } else if (gunName == ("AN94") || gunName == ("AN-94")) {

            return AN94.name + misc::sep1 + std::to_string(AN94.rank) + misc::sep2 + AN94.category;

        } else if (gunName == ("AS VAL") || gunName == ("VAL")) {

            return AS_VAL.name + misc::sep1 + std::to_string(AS_VAL.rank) + misc::sep2 + AS_VAL.category;

        } else if (gunName == ("SCAR L") || gunName == ("SCAR-L")) {

            return SCAR_L.name + misc::sep1 + std::to_string(SCAR_L.rank) + misc::sep2 + SCAR_L.category;

        } else if (gunName == ("AUG A1")) {

            return AUG_A1.name + misc::sep1 + std::to_string(AUG_A1.rank) + misc::sep2 + AUG_A1.category;

        } else if (gunName == ("M16A4")) {

            return M16A4.name + misc::sep1 + std::to_string(M16A4.rank) + misc::sep2 + M16A4.category;

        } else if (gunName == ("G36")) {

            return G36.name + misc::sep1 + std::to_string(G36.rank) + misc::sep2 + G36.category;

        } else if (gunName == ("M16A3")) {

            return M16A3.name + misc::sep1 + std::to_string(M16A3.rank) + misc::sep2 + M16A3.category;

        } else if (gunName == ("FAMAS") || gunName == ("G2") || gunName == ("FAMAS G2")) {

            return FAMAS_G2.name + misc::sep1 + std::to_string(FAMAS_G2.rank) + misc::sep2 + FAMAS_G2.category;

        } else if (gunName == ("AK47") || gunName == ("AK-47")) {

            return AK47.name + misc::sep1 + std::to_string(AK47.rank) + misc::sep2 + AK47.category;

        } else if (gunName == ("AUG A2")) {

            return AUG_A2.name + misc::sep1 + std::to_string(AUG_A2.rank) + misc::sep2 + AUG_A2.category;

        } else if (gunName == ("AUG A3")) {

            return AUG_A3.name + misc::sep1 + std::to_string(AUG_A3.rank) + misc::sep2 + AUG_A3.category;

        } else if (gunName == ("L85A2") || gunName == ("L85")) {

            return L85A2.name + misc::sep1 + std::to_string(L85A2.rank) + misc::sep2 + L85A2.category;

        } else if (gunName == ("HK416") || gunName == ("416") || gunName == ("HK-416")) {

            return HK416.name + misc::sep1 + std::to_string(HK416.rank) + misc::sep2 + HK416.category;

        } else if (gunName == ("AK74") || gunName == ("AK-74")) {

            return AK74.name + misc::sep1 + std::to_string(AK74.rank) + misc::sep2 + AK74.category;

        } else if (gunName == ("AKM")) {

            return AKM.name + misc::sep1 + std::to_string(AKM.rank) + misc::sep2 + AKM.category;

        } else if (gunName == ("AK103") || gunName == ("AK-103")) {

            return AK103.name + misc::sep1 + std::to_string(AK103.rank) + misc::sep2 + AK103.category;

        } else if (gunName == ("TAR-21") || gunName == ("TAR21") || gunName == ("TAR")) {

            return TAR_21.name + misc::sep1 + std::to_string(TAR_21.rank) + misc::sep2 + TAR_21.category;

        } else if (gunName == ("M231") || gunName == ("M-231")) {

            return M231.name + misc::sep1 + std::to_string(M231.rank) + misc::sep2 + M231.category;

        } else if (gunName == ("G11K2") || gunName == ("G11")) {

            return G11K2.name + misc::sep1 + std::to_string(G11K2.rank) + misc::sep2 + G11K2.category;

        } //LIGHT MACHINE GUNS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("COLT LMG")) {

            return COLT_LMG.name + misc::sep1 + std::to_string(COLT_LMG.rank) + misc::sep2 + COLT_LMG.category;

        } else if (gunName == ("M60")) {

            return M60.name + misc::sep1 + std::to_string(M60.rank) + misc::sep2 + M60.category;

        } else if (gunName == ("AUG HBAR") || gunName == ("HBAR")) {

            return AUG_HBAR.name + misc::sep1 + std::to_string(AUG_HBAR.rank) + misc::sep2 + AUG_HBAR.category;

        } else if (gunName == ("MG36")) {

            return MG36.name + misc::sep1 + std::to_string(MG36.rank) + misc::sep2 + MG36.category;

        } else if (gunName == ("RPK12") || gunName == ("RPK-12")) {

            return RPK12.name + misc::sep1 + std::to_string(RPK12.rank) + misc::sep2 + RPK12.category;

        } else if (gunName == ("L86 LSW") || gunName == ("L86") || gunName == ("LSW")) {

            return L86_LSW.name + misc::sep1 + std::to_string(L86_LSW.rank) + misc::sep2 + L86_LSW.category;

        } else if (gunName == ("RPK")) {

            return RPK.name + misc::sep1 + std::to_string(RPK.rank) + misc::sep2 + RPK.category;

        } else if (gunName == ("HK21") || gunName == ("HK-21")) {

            return HK21.name + misc::sep1 + std::to_string(HK21.rank) + misc::sep2 + HK21.category;

        } else if (gunName == ("SCAR HAMR") || gunName == ("SCAR-HAMR") || gunName == ("HAMR")) {

            return SCAR_HAMR.name + misc::sep1 + std::to_string(SCAR_HAMR.rank) + misc::sep2 + SCAR_HAMR.category;

        } else if (gunName == ("RPK74") || gunName == ("RPK-74")) {

            return RPK74.name + misc::sep1 + std::to_string(RPK74.rank) + misc::sep2 + RPK74.category;

        } else if (gunName == ("MG3KWS") || gunName == ("MG3")) {

            return MG3KWS.name + misc::sep1 + std::to_string(MG3KWS.rank) + misc::sep2 + MG3KWS.category;

        }//CARBINES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("M4A1")) {

            return M4A1.name + misc::sep1 + std::to_string(M4A1.rank) + misc::sep2 + M4A1.category;

        } else if (gunName == ("G36K")) {

            return G36K.name + misc::sep1 + std::to_string(G36K.rank) + misc::sep2 + G36K.category;

        } else if (gunName == ("L22")) {

            return L22.name + misc::sep1 + std::to_string(L22.rank) + misc::sep2 + L22.category;

        } else if (gunName == ("M4")) {

            return M4.name + misc::sep1 + std::to_string(M4.rank) + misc::sep2 + M4.category;

        } else if (gunName == ("SCAR PDW")) {

            return SCAR_PDW.name + misc::sep1 + std::to_string(SCAR_PDW.rank) + misc::sep2 + SCAR_PDW.category;

        } else if (gunName == ("AKU12") || gunName == ("AKU") || gunName == ("AKU-12")) {

            return AKU12.name + misc::sep1 + std::to_string(AKU12.rank) + misc::sep2 + AKU12.category;

        } else if (gunName == ("AK12C") || gunName == ("12C") || gunName == ("AK-12C")) {

            return AK12C.name + misc::sep1 + std::to_string(AK12C.rank) + misc::sep2 + AK12C.category;

        } else if (gunName == ("HONEY BADGER") || gunName == ("HONEY") || gunName == ("BADGER")) {

            return HONEY_BADGER.name + misc::sep1 + std::to_string(HONEY_BADGER.rank) + misc::sep2 + HONEY_BADGER.category;

        } else if (gunName == ("GROZA 1") || gunName == ("GROZA-1")) {

            return GROZA_1.name + misc::sep1 + std::to_string(GROZA_1.rank) + misc::sep2 + GROZA_1.category;

        } else if (gunName == ("SR-3M") || gunName == ("3M") || gunName == ("SR3M")) {

            return SR_3M.name + misc::sep1 + std::to_string(SR_3M.rank) + misc::sep2 + SR_3M.category;

        } else if (gunName == ("GROZA 4") || gunName == ("GROZA-4")) {

            return GROZA_4.name + misc::sep1 + std::to_string(GROZA_4.rank) + misc::sep2 + GROZA_4.category;

        } else if (gunName == ("FAL 50.63 PARA") || gunName == ("FAL PARA") || gunName == ("FAL 50.63") || gunName == ("50.63 PARA") || gunName == ("50.63")) {

            return FAL50_63PARA.name + misc::sep1 + std::to_string(FAL50_63PARA.rank) + misc::sep2 + FAL50_63PARA.category;

        } else if (gunName == ("1858 CARBINE") || gunName == ("1858C")) {

            return R1858CARBINE.name + misc::sep1 + std::to_string(R1858CARBINE.rank) + misc::sep2 + R1858CARBINE.category;

        } else if (gunName == ("JURY")) {

            return JURY.name + misc::sep1 + std::to_string(JURY.rank) + misc::sep2 + JURY.category;

        } else if (gunName == ("AK105") || gunName == ("AK-105")) {

            return AK105.name + misc::sep1 + std::to_string(AK105.rank) + misc::sep2 + AK105.category;

        } else if (gunName == ("KAC SRR") || gunName == ("KAC") || gunName == ("SRR")) {

            return KAC_SRR.name + misc::sep1 + std::to_string(KAC_SRR.rank) + misc::sep2 + KAC_SRR.category;

        } else if (gunName == ("X95R")) {

            return X95R.name + misc::sep1 + std::to_string(X95R.rank) + misc::sep2 + X95R.category;

        } else if (gunName == ("MC51SD") || gunName == ("51SD") || gunName == ("MC51")) {

            return MC51SD.name + misc::sep1 + std::to_string(MC51SD.rank) + misc::sep2 + MC51SD.category;

        }//PERSONAL DEFENSE WEAPONS /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("MP5K")) {

            return MP5K.name + misc::sep1 + std::to_string(MP5K.rank) + misc::sep2 + MP5K.category;

        } else if (gunName == ("UMP45") || gunName == ("UMP")) {

            return UMP45.name + misc::sep1 + std::to_string(UMP45.rank) + misc::sep2 + UMP45.category;

        } else if (gunName == ("G36C")) {

            return UMP45.name + misc::sep1 + std::to_string(UMP45.rank) + misc::sep2 + UMP45.category;

        } else if (gunName == ("MP7")) {

            return MP7.name + misc::sep1 + std::to_string(MP7.rank) + misc::sep2 + MP7.category;

        } else if (gunName == ("MAC10") || gunName == ("MAC")) {

            return MAC10.name + misc::sep1 + std::to_string(MAC10.rank) + misc::sep2 + MAC10.category;

        } else if (gunName == ("P90")) {

            return P90.name + misc::sep1 + std::to_string(P90.rank) + misc::sep2 + P90.category;

        } else if (gunName == ("MP5")) {

            return MP5.name + misc::sep1 + std::to_string(MP5.rank) + misc::sep2 + MP5.category;

        } else if (gunName == ("COLT SMG 635") || gunName == ("COLT SMG") || gunName == ("COLT 635") || gunName == ("SMG 635") || gunName == ("635")) {

            return COLTSMG635.name + misc::sep1 + std::to_string(COLTSMG635.rank) + misc::sep2 + COLTSMG635.category;

        } else if (gunName == ("L2A3")) {

            return L2A3.name + misc::sep1 + std::to_string(L2A3.rank) + misc::sep2 + L2A3.category;

        } else if (gunName == ("MP5SD")) {

            return MP5SD.name + misc::sep1 + std::to_string(MP5SD.rank) + misc::sep2 + MP5SD.category;

        } else if (gunName == ("MP10")) {

            return MP10.name + misc::sep1 + std::to_string(MP10.rank) + misc::sep2 + MP10.category;

        } else if (gunName == ("M3A1")) {

            return M3A1.name + misc::sep1 + std::to_string(M3A1.rank) + misc::sep2 + M3A1.category;

        } else if (gunName == ("MP5/10")) {

            return MP5_10.name + misc::sep1 + std::to_string(MP5_10.rank) + misc::sep2 + MP5_10.category;

        } else if (gunName == ("UZI")) {

            return UZI.name + misc::sep1 + std::to_string(UZI.rank) + misc::sep2 + UZI.category;

        } else if (gunName == ("AUG A3 PARA") || gunName == ("AUG PARA") || gunName == ("A3 PARA")) {

            return AUG_A3_PARA.name + misc::sep1 + std::to_string(AUG_A3_PARA.rank) + misc::sep2 + AUG_A3_PARA.category;

        } else if (gunName == ("PPSH-41") || gunName == ("PPSH 41") || gunName == ("PPSH")) {

            return PPSH_41.name + misc::sep1 + std::to_string(PPSH_41.rank) + misc::sep2 + PPSH_41.category;

        } else if (gunName == ("FAL PARA SHORTY") || gunName == ("FAL SHORTY") || gunName == ("SHORTY") || gunName == ("PARA SHORTY") || gunName == ("FAL PARA SHORTY  ")) {

            return FAL_PARA_SHORTY.name + misc::sep1 + std::to_string(FAL_PARA_SHORTY.rank) + misc::sep2 + FAL_PARA_SHORTY.category;

        } else if (gunName == ("KRISS VECTOR") || gunName == ("VECTOR") || gunName == ("KRISS")) {

            return KRISS_VECTOR.name + misc::sep1 + std::to_string(KRISS_VECTOR.rank) + misc::sep2 + KRISS_VECTOR.category;

        } else if (gunName == ("MP40")) {

            return MP40.name + misc::sep1 + std::to_string(MP40.rank) + misc::sep2 + MP40.category;

        } else if (gunName == ("TOMMY GUN") || gunName == ("THOMPSON") || gunName == ("TOMMY")) {

            return TOMMY_GUN.name + misc::sep1 + std::to_string(TOMMY_GUN.rank) + misc::sep2 + TOMMY_GUN.category;

        } else if (gunName == ("X95R SMG")) {

            return X95R_SMG.name + misc::sep1 + std::to_string(X95R_SMG.rank) + misc::sep2 + X95R_SMG.category;

        } //SHOTGUNS ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("KSG-12") || gunName == ("KSG") || gunName == ("KSG 12")) {

            return KSG_12.name + misc::sep1 + std::to_string(KSG_12.rank) + misc::sep2 + KSG_12.category;

        } else if (gunName == ("REMINGTON 870") || gunName == ("R870")) {

            return REMINGTON_870.name + misc::sep1 + std::to_string(REMINGTON_870.rank) + misc::sep2 + REMINGTON_870.category;

        } else if (gunName == ("DBV-12") || gunName == ("DBV12") || gunName == ("DBV 12") || gunName == ("DBV")) {

            return DBV_12.name + misc::sep1 + std::to_string(DBV_12.rank) + misc::sep2 + DBV_12.category;

        } else if (gunName == ("KS-23M") || gunName == ("KS23M")) {

            return KS_23M.name + misc::sep1 + std::to_string(KS_23M.rank) + misc::sep2 + KS_23M.category;

        } else if (gunName == ("SAIGA-12") || gunName == ("SAIGA 12")) {

            return SAIGA_12.name + misc::sep1 + std::to_string(SAIGA_12.rank) + misc::sep2 + SAIGA_12.category;

        } else if (gunName == ("STEVENS DB") || gunName == ("STEVENS") || gunName == ("DB")) {

            return STEVENS_DB.name + misc::sep1 + std::to_string(STEVENS_DB.rank) + misc::sep2 + STEVENS_DB.category;

        } else if (gunName == ("AA-12") || gunName == ("AA12") || gunName == ("AA")) {

            return AA_12.name + misc::sep1 + std::to_string(AA_12.rank) + misc::sep2 + AA_12.category;

        } else if (gunName == ("SPAS-12") || gunName == ("SPAS 12") || gunName == ("SPAS")) {

            return SPAS_12.name + misc::sep1 + std::to_string(SPAS_12.rank) + misc::sep2 + SPAS_12.category;

        }//PISTOLS ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("G17") || gunName == ("GLOCK 17")) {

            return G17.name + misc::sep1 + std::to_string(G17.rank) + misc::sep2 + G17.category;

        } else if (gunName == ("M9")) {

            return M9.name + misc::sep1 + std::to_string(M9.rank) + misc::sep2 + M9.category;

        } else if (gunName == ("M1911")) {

            return M1911.name + misc::sep1 + std::to_string(M1911.rank) + misc::sep2 + M1911.category;

        } else if (gunName == ("DEAGLE L5") || gunName == ("DESERT EAGLE L5") || gunName == ("DEAGLE .44") || gunName == ("DESERT EAGLE .44")) {

            return DEAGLE_L5.name + misc::sep1 + std::to_string(DEAGLE_L5.rank) + misc::sep2 + DEAGLE_L5.category;

        } else if (gunName == ("M45A1") || gunName == ("M45")) {

            return M45A1.name + misc::sep1 + std::to_string(M45A1.rank) + misc::sep2 + M45A1.category;

        } else if (gunName == ("FIVE-SEVEN") || gunName == ("5-7") || gunName == ("5 7") || gunName == ("FIVE SEVEN")) {

            return FIVE_SEVEN.name + misc::sep1 + std::to_string(FIVE_SEVEN.rank) + misc::sep2 + FIVE_SEVEN.category;

        } else if (gunName == ("ZIP 22") || gunName == ("ZIP") || gunName == ("ZIP .22")) {

            return ZIP_22.name + misc::sep1 + std::to_string(ZIP_22.rank) + misc::sep2 + ZIP_22.category;

        } else if (gunName == ("DEAGLE XIX") || gunName == ("DESERT EAGLE XIX") || gunName == ("DEAGLE 19") || gunName == ("DESERT EAGLE 19") || gunName == ("DEAGLE .50") || gunName == ("DESERT EAGLE .50")) {

            return DEAGLE_XIX.name + misc::sep1 + std::to_string(DEAGLE_XIX.rank) + misc::sep2 + DEAGLE_XIX.category;

        }//MACHINE PISTOLS /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("G18") || gunName == ("GLOCK 18")) {

            return G18.name + misc::sep1 + std::to_string(G18.rank) + misc::sep2 + G18.category;

        } else if (gunName == ("M93R") || gunName == ("93R")) {

            return M93R.name + misc::sep1 + std::to_string(M93R.rank) + misc::sep2 + M93R.category;

        } else if (gunName == ("TEC-9") || gunName == ("TEC 9") || gunName == ("TEC")) {

            return TEC_9.name + misc::sep1 + std::to_string(TEC_9.rank) + misc::sep2 + TEC_9.category;

        } else if (gunName == ("MICRO UZI")) {

            return MICRO_UZI.name + misc::sep1 + std::to_string(MICRO_UZI.rank) + misc::sep2 + MICRO_UZI.category;

        } else if (gunName == ("MP1911")) {

            return MP1911.name + misc::sep1 + std::to_string(MP1911.rank) + misc::sep2 + MP1911.category;

        }// REVOLVERS /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("MP412 REX") || gunName == ("MP412REX")) {

            return MP412REX.name + misc::sep1 + std::to_string(MP412REX.rank) + misc::sep2 + MP412REX.category;

        } else if (gunName == ("MATEBA-6") || gunName == ("MATEBA 6") || gunName == ("MATEBA")) {

            return MATEBA_6.name + misc::sep1 + std::to_string(MATEBA_6.rank) + misc::sep2 + MATEBA_6.category;

        } else if (gunName == ("1858 NEW ARMY") || gunName == ("1858NA") || gunName == ("NEW ARMY")) {

            return R1858_NEW_ARMY.name + misc::sep1 + std::to_string(R1858_NEW_ARMY.rank) + misc::sep2 + R1858_NEW_ARMY.category;

        }

        if (gunName == ("REDHAWK .44") || gunName == ("REDHAWK") || gunName == ("REDHAWK 44")) {

            return REDHAWK_44.name + misc::sep1 + std::to_string(REDHAWK_44.rank) + misc::sep2 + REDHAWK_44.category;

        } else if (gunName == ("JUDGE")) {

            return JUDGE.name + misc::sep1 + std::to_string(JUDGE.rank) + misc::sep2 + JUDGE.category;

        } else if (gunName == ("EXECUTIONER")) {

            return EXECUTIONER.name + misc::sep1 + std::to_string(EXECUTIONER.rank) + misc::sep2 + EXECUTIONER.category;

        }//OTHER /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (gunName == ("SERBU SHOTGUN") || gunName == ("SERBU SUPER-SHORTY")) {

            return SERBU_SHOTGUN.name + misc::sep1 + std::to_string(SERBU_SHOTGUN.rank) + misc::sep2 + SERBU_SHOTGUN.category;

        } else if (gunName == ("SFG 50") || gunName == ("SFG") || gunName == ("SFG-50")) {

            return SFG_50.name + misc::sep1 + std::to_string(SFG_50.rank) + misc::sep2 + SFG_50.category;

        } else if (gunName == ("SAWED-OFF") || gunName == ("SAWED OFF")) {

            return SAWED_OFF.name + misc::sep1 + std::to_string(SAWED_OFF.rank) + misc::sep2 + SAWED_OFF.category;

        } else if (gunName == ("SAIGA-12U") || gunName == ("SAIGA 12U")) {

            return SAIGA_12U.name + misc::sep1 + std::to_string(SAIGA_12U.rank) + misc::sep2 + SAIGA_12U.category;

        } else if (gunName == ("OBREZ")) {

            return OBREZ.name + misc::sep1 + std::to_string(OBREZ.rank) + misc::sep2 + OBREZ.category;

        }//MELEES ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
        else if (gunName == ("TRENCH MACE")) {

            return TRENCH_MACE.name + misc::sep1 + std::to_string(TRENCH_MACE.rank) + misc::sep2 + TRENCH_MACE.category;

        } else if (gunName == ("KNIFE")) {

            return KNIFE.name + misc::sep1 + std::to_string(KNIFE.rank) + misc::sep2 + KNIFE.category;

        } else if (gunName == ("CROWBAR")) {

            return CROWBAR.name + misc::sep1 + std::to_string(CROWBAR.rank) + misc::sep2 + CROWBAR.category;

        } else if (gunName == ("BASEBALL BAT")) {

            return BASEBALL_BAT.name + misc::sep1 + std::to_string(BASEBALL_BAT.rank) + misc::sep2 + BASEBALL_BAT.category;

        } else if (gunName == ("NIGHTSTICK")) {

            return NIGHTSTICK.name + misc::sep1 + std::to_string(NIGHTSTICK.rank) + misc::sep2 + NIGHTSTICK.category;

        } else if (gunName == ("ICE PICK")) {

            return ICE_PICK.name + misc::sep1 + std::to_string(ICE_PICK.rank) + misc::sep2 + ICE_PICK.category;

        } else if (gunName == ("TOMAHAWK")) {

            return TOMAHAWK.name + misc::sep1 + std::to_string(TOMAHAWK.rank) + misc::sep2 + TOMAHAWK.category;

        } else if (gunName == ("BRASS KNUCKLE")) {

            return BRASS_KNUCKLE.name + misc::sep1 + std::to_string(BRASS_KNUCKLE.rank) + misc::sep2 + BRASS_KNUCKLE.category;

        } else if (gunName == ("CRICKET BAT")) {

            return CRICKET_BAT.name + misc::sep1 + std::to_string(CRICKET_BAT.rank) + misc::sep2 + CRICKET_BAT.category;

        } else if (gunName == ("JASON")) {

            return JASON.name + misc::sep1 + std::to_string(JASON.rank) + misc::sep2 + JASON.category;

        } else if (gunName == ("MACHETE")) {

            return MACHETE.name + misc::sep1 + std::to_string(MACHETE.rank) + misc::sep2 + MACHETE.category;

        } else if (gunName == ("LONGSWORD")) {

            return LONGSWORD.name + misc::sep1 + std::to_string(LONGSWORD.rank) + misc::sep2 + LONGSWORD.category;

        } else if (gunName == ("FRYING PAN") || gunName == ("PAN") || gunName == ("FRYING PAN!") || gunName == ("PAN!")) {

            return FRYING_PAN.name + misc::sep1 + std::to_string(FRYING_PAN.rank) + misc::sep2 + FRYING_PAN.category;

        } else if (gunName == ("CRANE")) {

            return CRANE.name + misc::sep1 + std::to_string(CRANE.rank) + misc::sep2 + CRANE.category;

        } else if (gunName == ("JADE KEY") || gunName == ("JKEY")) {

            return JADE_KEY.name + misc::sep1 + std::to_string(JADE_KEY.rank) + misc::sep2 + JADE_KEY.category;

        } else if (gunName == ("FIRE AXE")) {

            return FIRE_AXE.name + misc::sep1 + std::to_string(FIRE_AXE.rank) + misc::sep2 + FIRE_AXE.category;

        } else if (gunName == ("BANJO")) {

            return BANJO.name + misc::sep1 + std::to_string(BANJO.rank) + misc::sep2 + BANJO.category;

        } else if (gunName == ("ASP BATON") || gunName == ("ASP")) {

            return ASP_BATON.name + misc::sep1 + std::to_string(ASP_BATON.rank) + misc::sep2 + ASP_BATON.category;

        } else if (gunName == ("CHOSEN ONE")) {

            return CHOSEN_ONE.name + misc::sep1 + std::to_string(CHOSEN_ONE.rank) + misc::sep2 + CHOSEN_ONE.category;

        } else if (gunName == ("KARAMBIT") || gunName == ("KARAMBIT (R)")) {

            return KARAMBIT.name + misc::sep1 + std::to_string(KARAMBIT.rank) + misc::sep2 + KARAMBIT.category;

        } else if (gunName == ("MEK'LETH") || gunName == ("MEKLETH")) {

            return MEK_LETH.name + misc::sep1 + std::to_string(MEK_LETH.rank) + misc::sep2 + MEK_LETH.category;

        } else if (gunName == ("HUNTING KNIFE")) {

            return HUNTING_KNIFE.name + misc::sep1 + std::to_string(HUNTING_KNIFE.rank) + misc::sep2 + HUNTING_KNIFE.category;

        } else if (gunName == ("CLEAVER")) {

            return CLEAVER.name + misc::sep1 + std::to_string(CLEAVER.rank) + misc::sep2 + CLEAVER.category;

        } else if (gunName == ("HATTORI")) {

            return HATTORI.name + misc::sep1 + std::to_string(HATTORI.rank) + misc::sep2 + HATTORI.category;

        } else if (gunName == ("REAPER")) {

            return REAPER.name + misc::sep1 + std::to_string(REAPER.rank) + misc::sep2 + REAPER.category;

        } else if (gunName == ("NORDIC WAR AXE") || gunName == ("WAR AXE")) {

            return NORDIC_WAR_AXE.name + misc::sep1 + std::to_string(NORDIC_WAR_AXE.rank) + misc::sep2 + NORDIC_WAR_AXE.category;

        } else if (gunName == ("STICK GRENADE")) {

            return STICK_GRENADE.name + misc::sep1 + std::to_string(STICK_GRENADE.rank) + misc::sep2 + STICK_GRENADE.category;

        } else if (gunName == ("SLEDGEHAMMER")) {

            return SLEDGEHAMMER.name + misc::sep1 + std::to_string(SLEDGEHAMMER.rank) + misc::sep2 + SLEDGEHAMMER.category;

        } else if (gunName == ("MORNING STAR")) {

            return MORNING_STAR.name + misc::sep1 + std::to_string(MORNING_STAR.rank) + misc::sep2 + MORNING_STAR.category;

        } else if (gunName == ("TACTICAL SPATULA") || gunName == ("SPATULA")) {

            return TACTICAL_SPATULA.name + misc::sep1 + std::to_string(TACTICAL_SPATULA.rank) + misc::sep2 + TACTICAL_SPATULA.category;

        }///some jokes lol

        else if (gunName == ("HK")) { //lol those kids

            return ("are") + misc::sep1 + ("you") + misc::sep2 + ("stupid?");

        } else if (gunName == ("HK51B") || gunName == ("HK51")) {

            return HK51B.name + misc::sep1 + std::to_string(HK51B.rank) + misc::sep2 + HK51B.category;

        } else if (gunName == ("C7A2") || gunName == ("C7")) {

            return C7A2.name + misc::sep1 + std::to_string(C7A2.rank) + misc::sep2 + C7A2.category;

        } else if(gunName == ("KRINKOV") || gunName == ("KRINK")){
        
            return KRINKOV.name + misc::sep1 + std::to_string(KRINKOV.rank) + misc::sep2 + KRINKOV.category;

        } else if(gunName == ("PP19") || gunName == ("PP-19") || gunName == ("PP BIZON") || gunName == ("PP-19 BIZON") || gunName == ("BIZON") || gunName == ("PP 19 BIZON")){

            return PP19_BIZON.name + misc::sep1 + std::to_string(PP19_BIZON.rank) + misc::sep2 + PP19_BIZON.category;
        
        } else if(gunName == ("TYPE-88") || gunName == ("TYPE 88")){

            return TYPE_88.name + misc::sep1 + std::to_string(TYPE_88.rank) + misc::sep2 + TYPE_88.category;
        
        } else if (gunName == ("RITUAL SICKLE") || gunName == ("Sicle")) {

            return RITUAL_SICKLE.name + misc::sep1 + std::to_string(RITUAL_SICKLE.rank) + misc::sep2 + RITUAL_SICKLE.category;

        } else if (gunName == ("KEY")){
        
            return KEY.name + misc::sep1 + std::to_string(KEY.rank) + misc::sep2 + KEY.category;

        } else if (gunName == ("POCKET KNIFE") || gunName == ("SWISS ARMY KNIFE")) {

            return POCKET_KNIFE.name + misc::sep1 + std::to_string(POCKET_KNIFE.rank) + misc::sep2 + POCKET_KNIFE.category;
        
        } else if (gunName == ("DARKHEART")) {

            return DARKHEART.name + misc::sep1 + std::to_string(DARKHEART.rank) + misc::sep2 + DARKHEART.category;
        
        } else if (gunName == ("ZWEIHANDER")) {

            return ZWEIHANDER.name + misc::sep1 + std::to_string(ZWEIHANDER.rank) + misc::sep2 + ZWEIHANDER.category;

        } else if (gunName == ("CLEMENTINE")) {

            return CLEMENTINE.name + misc::sep1 + std::to_string(CLEMENTINE.rank) + misc::sep2 + CLEMENTINE.category;

        } else if (gunName == ("VOID STAFF")) {

            return VOID_STAFF.name + misc::sep1 + std::to_string(VOID_STAFF.rank) + misc::sep2 + VOID_STAFF.category;

        } else if (gunName == ("HOCKEY STICK")) {

            return HOCKEY_STICK.name + misc::sep1 + std::to_string(HOCKEY_STICK.rank) + misc::sep2 + HOCKEY_STICK.category;

        } else if (gunName == ("TANZANITE BLADE") || gunName == ("TANZANITE BLADE ")) {

            return TANZANITE_BLADE.name + misc::sep1 + std::to_string(TANZANITE_BLADE.rank) + misc::sep2 + TANZANITE_BLADE.category;

        } else if (gunName == ("NOOBSLAYER")) {

            return NOOBSLAYER.name + misc::sep1 + std::to_string(NOOBSLAYER.rank) + misc::sep2 + NOOBSLAYER.category;

        } else if (gunName == ("WORLD BUSTER")) {

            return WORLD_BUSTER.name + misc::sep1 + std::to_string(WORLD_BUSTER.rank) + misc::sep2 + WORLD_BUSTER.category;

        } else if (gunName == ("ZIRCON TRIDENT") || gunName == ("TRIDENT")) {

            return ZIRCON_TRIDENT.name + misc::sep1 + std::to_string(ZIRCON_TRIDENT.rank) + misc::sep2 + ZIRCON_TRIDENT.category;

        } else if (gunName == ("TANZANITE PICK") || gunName == ("PICKAXE") || gunName == ("TANZANITE PICKAXE")) {

            return TANZANITE_PICK.name + misc::sep1 + std::to_string(TANZANITE_PICK.rank) + misc::sep2 + TANZANITE_PICK.category;

        } else if (gunName == ("MAGLITE CLUB") || gunName == ("FLASHLIGHT") || gunName == ("MAGLITE")) {

            return MAGLITE_CLUB.name + misc::sep1 + std::to_string(MAGLITE_CLUB.rank) + misc::sep2 + MAGLITE_CLUB.category;

        } else if (gunName == ("KEYBOARD")) {

            return KEYBOARD.name + misc::sep1 + std::to_string(KEYBOARD.rank) + misc::sep2 + KEYBOARD.category;

        } else if (gunName == ("MJOLNIR") || gunName == ("MJOLNIR ")) {

            return MJOLNIR.name + misc::sep1 + std::to_string(MJOLNIR.rank) + misc::sep2 + MJOLNIR.category;

        } else if (gunName == ("ZIRCON SLAMSICKLE") || gunName == ("SLAMSICKLE")) {

            return ZIRCON_SLAMSICKLE.name + misc::sep1 + std::to_string(ZIRCON_SLAMSICKLE.rank) + misc::sep2 + ZIRCON_SLAMSICKLE.category;

        } else {

            return ("0");

        }

    }

}
/*
ritual sickle, 49
key, 69 
pocket knife, 89
darkheart, 150
zweihander, 185
clementine, 132
void staff, 190
hockey stick, 0
*/
/*
tanzanite blade
noobslayer
world buster
zircon trident
tanzanite pick
maglite club
keyboard
mjolnir
zircon slamsickle

*/