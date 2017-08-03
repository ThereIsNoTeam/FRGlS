
#include "Cmain.h"

int Cmain::FirstConnectLoop() noexcept
{
	//for (;;)
	while (running)
	{
		window.display();
		while (window.pollEvent(mainevent))
		{
			switch (mainevent.type)
			{
				case sf::Event::EventType::Closed:
					running = false;
				break;
			}
		}
		window.clear();
	}
	return 0;
}