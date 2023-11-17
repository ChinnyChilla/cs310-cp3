#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Actor.h"
using namespace std;
class Movie 
{
	public:
		Movie();
		Movie(unsigned int movieid, unsigned int year, string dirlast, string dirfirst, string title);
		int getIndex();
		void addActorToCast(Actor actor);
		bool removeActorFromCast(unsigned int actorid);
		int findActorIndex(int actorid);
		string getMovieTitle();
		void printCast();
		int binarySearch(int target, int left, int right);
		int findInsertLocation(int target, int left, int right);
		Array<Actor> *cast;

	private:
		unsigned int movieid = 0;
		string movieTitle = "";
		unsigned int releaseYear = 0;
		string dirlast = "";
		string dirfirst = "";
		
};	