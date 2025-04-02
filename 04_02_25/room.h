#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <stdexcept>
enum bldgCode
{
    ACRP,
    DUPHS,
    FWACC,
    FWBYR,
    FWCCC,
    FWCHH,
    FWCHS,
    FWLUT,
    FWMMM,
    FWMTL,
    FWNHM,
    FWNSD,
    FWNSL,
    FWPBH,
    FWPKV,
    FWSPS,
    FWSRV,
    FWSSH,
    FWSTO,
    FWTHR,
    FWWAB,
    FWWSF,
    LUTHP,
    OAMTC,
    PKVWN,
    REGPL,
    WARMC,
    WARTC,
    WDVW
};
enum campusCode
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I
};
class room
{
public:
    room(std::string c, std::string b, int rn);
    int getRoomNum();
    std::string getBuilding();
    std::string getCampus();
    static std::map<bldgCode, std::string> bldgToStr;
    static std::map<std::string, bldgCode> strToBldg;
    static std::map<campusCode, std::string> campusToStr;
    static std::map<std::string, campusCode> strToCampus;

private:
    bldgCode building;
    campusCode campus;
    int roomNum;
};
#endif