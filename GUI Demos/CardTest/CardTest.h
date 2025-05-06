#ifndef _CardTest_CardTest_h
#define _CardTest_CardTest_h

#include <CtrlLib/CtrlLib.h>
#include "cardGUI.h"

using namespace Upp;

#define LAYOUTFILE <CardTest/CardTest.lay>
#include <CtrlCore/lay.h>

class CardTest : public WithCardTestLayout<TopWindow> {
public:
	CardTest();
};

#endif
