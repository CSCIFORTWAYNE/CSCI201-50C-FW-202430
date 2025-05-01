#include "Drinks2.h"


DrinksWindow::DrinksWindow()
{
	CtrlLayout(*this, "Drink Order Form");
	Sizeable().Zoomable();
	scroller.EnableScroll();
	Add(scroller.SizePos());
	CtrlLayout(scroller_view);
	scroller.AddPane(scroller_view);
	scroller_view.base = -1;
	scroller_view.temp = -1;
	scroller_view.size = -1;
	for(int i = 0; i < NUM_DAIRY; i++)
	{
		scroller_view.dairy.Add(dairyStr[i]);
	}
	//int left_start = 0;
	int optionSize = 100;
	int checkDist = 20;
	int checkCount = 0;
	for(int i = 0; i < NUM_FLAV; i++)
	{
		flavor[i].SetLabel(flavStr[i].c_str());
		scroller_view.flavorOptions.Add(flavor[i].LeftPosZ(optionSize*(i%2), optionSize).TopPosZ(checkDist * checkCount));
		if(i%2 == 1)
		{
			checkCount++;
		}
	}
}