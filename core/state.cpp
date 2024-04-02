#include "state.h"
namespace State 
{
	static int states = 0; //0 for not logged, 1 for admin, 2 for maintainer, 3 for user

	void SetState(int n) //0 for not logged, 1 for admin, 2 for maintainer, 3 for user
	{
		states = n;
	}
	int GetState()
	{
		return states;
	}
}