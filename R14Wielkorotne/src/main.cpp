#include <iostream>
#include "klasa.h"

using namespace std;

int main()
{
	Waiter bob(5,"Robert Gruszka",314L);
	Singer bev("Beverly Hills",456L,3);

	Waiter t_wait;
	Singer t_sing;


	Worker * pw[4] = {&bob, &bev, &t_wait, &t_sing};

	int i;

	for (i = 2; i < 4; i++)
	{
		pw[i]->Set();
	}

	for (i = 0; i < 4; i++)
	{
		pw[i]->Show();
		cout <<endl;
	}

	return 0;
}
