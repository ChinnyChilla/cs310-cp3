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
		~Actor();
		Actor(unsigned int id, string firstname, string lastname);
		void addMovie(unsigned int movieid);
		void deleteMovie(unsigned int movieid);
		int findInsertLocation(int t, int left, int right);
		int binarySearch(int t, int left, int right);
	private:
		int id;
};	