#include "room.h"

room::room(std::string c, std::string b, int rn)
{
    if (!strToCampus.count(c))
        throw std::invalid_argument(c + " is not a valid campus code.");
    campus = strToCampus[c];
    if (!strToBldg.count(b))
        throw std::invalid_argument(b + " is not a valid building code.");
    building = strToBldg[b];
    roomNum = rn;
}

int room::getRoomNum()
{
    return roomNum;
}

std::string room::getBuilding()
{
    return bldgToStr[building];
}

std::string room::getCampus()
{
    return campusToStr[campus];
}

std::map<bldgCode, std::string> room::bldgToStr = {{ACRP, "Carpenter's Training Center"},
                                                   {DUPHS, "Dupont Hospital"},
                                                   {FWACC, "Anthis Career Center"},
                                                   {FWBYR, "Byron Health Center"},
                                                   {FWCCC, "Coliseum Campus"},
                                                   {FWCHH, "Charis House"},
                                                   {FWCHS, "Carroll High School"},
                                                   {FWLUT, "Lutheran Hospital"},
                                                   {FWMMM, "Millers Merry Manor"},
                                                   {FWMTL, "Fort Wayne Metals"},
                                                   {FWNHM, "Harshman Hall"},
                                                   {FWNSD, "Steel Dynamics Busse Tech Cent"},
                                                   {FWNSL, "Student Life Center"},
                                                   {FWPBH, "Parkview Behavioral Health"},
                                                   {FWPKV, "Parkview Memorial Hospital"},
                                                   {FWSPS, "Public Safety Academy"},
                                                   {FWSRV, "Sirva"},
                                                   {FWSSH, "Select Specialty Hospital"},
                                                   {FWSTO, "Saint Joseph Hospital"},
                                                   {FWTHR, "Towne House Retirmnt Cmmty"},
                                                   {FWWAB, "Auto Body Building"},
                                                   {FWWSF, "Smith Field Avi Maint Tech Sch"},
                                                   {LUTHP, "Lutheran Home"},
                                                   {OAMTC, "Ortho & Adv Mfr Traning Ctr"},
                                                   {PKVWN, "Parkview North"},
                                                   {REGPL, "Regency Place"},
                                                   {WARMC, "Warsaw Campus"},
                                                   {WARTC, "Warsaw Training Center"},
                                                   {WDVW, "Woodview"}};

std::map<std::string, bldgCode> room::strToBldg = {{"ACRP", ACRP},
                                                   {"DUPHS", DUPHS},
                                                   {"FWACC", FWACC},
                                                   {"FWBYR", FWBYR},
                                                   {"FWCCC", FWCCC},
                                                   {"FWCHH", FWCHH},
                                                   {"FWCHS", FWCHS},
                                                   {"FWLUT", FWLUT},
                                                   {"FWMMM", FWMMM},
                                                   {"FWMTL", FWMTL},
                                                   {"FWNHM", FWNHM},
                                                   {"FWNSD", FWNSD},
                                                   {"FWNSL", FWNSL},
                                                   {"FWPBH", FWPBH},
                                                   {"FWPKV", FWPKV},
                                                   {"FWSPS", FWSPS},
                                                   {"FWSRV", FWSRV},
                                                   {"FWSSH", FWSSH},
                                                   {"FWSTO", FWSTO},
                                                   {"FWTHR", FWTHR},
                                                   {"FWWAB", FWWAB},
                                                   {"FWWSF", FWWSF},
                                                   {"LUTHP", LUTHP},
                                                   {"OAMTC", OAMTC},
                                                   {"PKVWN", PKVWN},
                                                   {"REGPL", REGPL},
                                                   {"WARMC", WARMC},
                                                   {"WARTC", WARTC},
                                                   {"WDVW", WDVW}};

std::map<campusCode, std::string> room::campusToStr = {{A, "Lake County"},
                                                       {B, "South Bend"},
                                                       {C, "Fort Wayne"},
                                                       {D, "Lafayette"},
                                                       {E, "Kokomo"},
                                                       {F, "Marion"},
                                                       {G, "Muncie"},
                                                       {H, "Indianapolis"},
                                                       {I, "Bloomington"}};

std::map<std::string, campusCode> room::strToCampus = {{"A", A},
                                                       {"B", B},
                                                       {"C", C},
                                                       {"D", D},
                                                       {"E", E},
                                                       {"F", F},
                                                       {"G", G},
                                                       {"H", H},
                                                       {"I", I}};