
#include "Cmain.h"

int Cmain::GameLoop()
{
	while (running)
	{
		window.display();
		window.clear();
	}
	return 0;
}