#ifndef _Drinks2_cardGUI_h_
#define _Drinks2_cardGUI_h_
#include <CtrlLib/CtrlLib.h>
using namespace Upp;

class cardGUI : public Ctrl
{
	private:
		String text;
	public:
		void Paint(Draw & w) override;
		void LeftDown(Point pos, dword flags) override;
		void MouseMove(Point pos, dword flags) override ;
};
#endif
