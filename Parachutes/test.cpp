#include "ccc_win.h"

using namespace std;

int ccc_win_main()
{
	cwin.coord(10, 1000, 1000, 10);
	Line line1 = Line(Point(100, 100), Point(200, 200));
	cwin << line1;
	line1.move(200, 0);
	cwin << line1;
	line1.move(0, 200);
	cwin << line1;
	
}
