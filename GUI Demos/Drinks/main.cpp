#include <CtrlLib/CtrlLib.h>
#include "drinks.h"

using namespace Upp;

struct MyAppWindow: public TopWindow
{
	Switch base;
	MyAppWindow()
	{
		const int LBLSIZE = 120;
		const int MARGIN = 12;
		Add(base.HSizePosZ(LBLSIZE).VSizePosZ(MARGIN));
		base.Add(COFFEE, "Coffee");
		base.Add(TEA, "Tea");
		base.Add(CREAM, "Cream");
		base.SetVertical();
		base = -1;
	};
};

GUI_APP_MAIN
{
	MyAppWindow w;
	w.Run();
}
