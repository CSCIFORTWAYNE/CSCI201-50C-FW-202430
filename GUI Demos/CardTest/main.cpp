#include "CardTest.h"

CardTest::CardTest()
{
	CtrlLayout(*this, "Window title");
}

GUI_APP_MAIN
{
	CardTest().Run();
}
