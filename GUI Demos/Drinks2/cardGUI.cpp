#include "cardGUI.h"

void cardGUI::Paint(Draw &w)
	{
			Size white = GetSize();
			white = white - 4;
			w.DrawRect(GetSize(), Black());
			w.DrawRect(2,2,white.cx, white.cy, White());
			w.DrawText(white.cx/2, white.cy/2, text);
		}
		
void cardGUI::LeftDown(Point pos, dword flags)
{
	text = Format("[%d:%d]", pos.x, pos.y);
	Refresh();
}

 void cardGUI::MouseMove(Point pos, dword flags) {

       text = Format("[%d:%d]", pos.x, pos.y);

       Refresh();

   }