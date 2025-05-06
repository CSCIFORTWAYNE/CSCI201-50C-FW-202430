#include "cardGUI.h"
//lecture activity 
//modify LeftDown to generate a new card and refresh
void cardGUI::Paint(Draw &w)
	{
			Size white = GetSize();
			white = white - 4;
			bool cardColor = suit == cardSuit::SPADES || suit == cardSuit::CLUBS;
			w.DrawRect(GetSize(), Black());
			w.DrawRect(2,2,white.cx, white.cy, White());
			w.DrawText(6,4, rankToStr.at(rank),SerifZ(14).Bold(), cardColor ? Black : Red);
			w.DrawText(6,16, suitToStr.at(suit),SerifZ(14).Bold(), cardColor ? Black : Red);
			w.DrawText(white.cx-4,white.cy-14,1800, suitToStr.at(suit),SerifZ(14).Bold(), cardColor ? Black : Red);
			w.DrawText(white.cx-4,white.cy-2,1800, rankToStr.at(rank),SerifZ(14).Bold(), cardColor ? Black : Red);
			w.DrawText(white.cx/3, white.cy/3,suitToStr.at(suit),SerifZ(40).Bold(), cardColor ? Black : Red);
		}
		
void cardGUI::LeftDown(Point pos, dword flags)
{

}
/*
 void cardGUI::MouseMove(Point pos, dword flags) {

       text = Format("[%d:%d]", pos.x, pos.y);

       Refresh();

   }*/
   
cardGUI::cardGUI()
{
	//std::default_random_engine generator;
	std::uniform_int_distribution<int> distSuit(0,3);
	suit = static_cast<cardSuit>(distSuit(generator));
	
	std::uniform_int_distribution<int> distRank(1,13);
	rank = static_cast<cardRank>(distRank(generator));
}
   
std::map<cardSuit, std::string> cardGUI::suitToStr = {{cardSuit::SPADES,"♠"}, {cardSuit::CLUBS,"♣"}, {cardSuit::DIAMONDS,"♦"}, {cardSuit::HEARTS,"♥"}};
std::map<cardRank, std::string> cardGUI::rankToStr = {{cardRank::ACE, "A"}, {cardRank::TWO,"2"}, {cardRank::THREE,"3"}, {cardRank::FOUR,"4"}, {cardRank::FIVE,"5"}, {cardRank::SIX,"6"}, {cardRank::SEVEN,"7"}, {cardRank::EIGHT,"8"}, {cardRank::NINE,"9"}, {cardRank::TEN,"10"},
 {cardRank::JACK,"J"}, {cardRank::QUEEN,"Q"}, {cardRank::KING,"K"}};
