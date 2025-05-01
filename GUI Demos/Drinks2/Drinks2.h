#ifndef _Drinks2_Drinks2_h
#define _Drinks2_Drinks2_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <Drinks2/Drinks2.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include "drinks.h"

class DrinksWindow : public WithMainAppWindow<TopWindow>
{
public:
	DrinksWindow();
private:
	AutoScroller scroller;
	WithDrinksWindowLayout<ParentCtrl> scroller_view;
	Option flavor[NUM_FLAV];
};

#endif
