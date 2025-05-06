#ifndef _Drinks2_cardGUI_h_
#define _Drinks2_cardGUI_h_
#include <CtrlLib/CtrlLib.h>
#include <map>
#include <string>
#include <random>
using namespace Upp;

enum class cardSuit {SPADES, CLUBS, DIAMONDS, HEARTS};
enum class cardRank{ACE =1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN,
KING};
class cardGUI : public Ctrl
{
	private:
		cardSuit suit;
		cardRank rank;
		std::default_random_engine generator;
	public:
		void Paint(Draw & w) override;
		void LeftDown(Point pos, dword flags) override;
		//void MouseMove(Point pos, dword flags) override;
		static std::map<cardSuit, std::string> suitToStr;
		static std::map<cardRank, std::string> rankToStr;
		cardGUI();
};
#endif
