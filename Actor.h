#include <iostream>
#include <stdlib.h>
#include "Array.cpp"
using namespace std;

class Actor
{
	public:
		string first;
		string last;
		Array<int>* actorInMovie;
		int getIndex();
		Actor();
		Actor(unsigned int id, string firstname, string lastname);
	private:
		int id;
};	