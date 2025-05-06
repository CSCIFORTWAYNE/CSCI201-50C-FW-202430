#ifndef _Drinks2_Drinks2_h
#define _Drinks2_Drinks2_h

#include <CtrlLib/CtrlLib.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "cardGUI.h"

using namespace Upp;

#define LAYOUTFILE <Drinks2/Drinks2.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include "drinks.h"

class DrinksWindow : public WithMainAppWindow<TopWindow>
{
public:
	DrinksWindow();
	void checkPrice();
	void saveOrder();
	
private:
	AutoScroller scroller;
	WithDrinksWindowLayout<ParentCtrl> scroller_view;
	Option flavor[NUM_FLAV];
	drink d;
	std::vector<drink> order;
	Button writeBtn;
	OptionTree optree;
};

#endif
