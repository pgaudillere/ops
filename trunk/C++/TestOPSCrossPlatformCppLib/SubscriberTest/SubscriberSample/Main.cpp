


#include "PizzaSubscriber.h"


int main()
{
	PizzaSub main;

	ops::Participant::getIOService()->run();
	while(true)
	{
		Sleep(10000);
	}
	return 0;

}