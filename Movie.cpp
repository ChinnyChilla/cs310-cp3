#include <iostream>
#include <stdlib.h>
#include "Movie.h"
using namespace std;

Movie::Movie(unsigned int id, unsigned int year, string directorLast, string directorFirst, string title )
{
	movieid = id;
	movieTitle = title;
	releaseYear = year;
	dirlast = directorLast;
	dirfirst = directorFirst;
	cast = new Array<Actor>;
	
}

Movie::Movie() {
	movieid = -1;
	movieTitle = "";
	releaseYear = 0;
	dirlast = "";
	dirfirst = "";
	cast = new Array<Actor>;
}
int Movie::getIndex() {
	return movieid;
}
string Movie::getMovieTitle() {
	return movieTitle;
}
int Movie::findActorIndex(int actorid) {
	for (unsigned int i = 0; i < cast->count; i++)
	{
		Actor curr = cast->at(i);
		if (curr.getIndex() == actorid)
		{
			return i;
		}
	}
	return -1;
}

int Movie::binarySearch(int target, int left, int right)
{
	if (right == -1) return -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = cast->at(middle).getIndex();
		if (middle_id == target)
			return middle;

		if (middle_id < target)
		{
			left = middle + 1;
			continue;
		}
		right = middle - 1;
	};
	return -1;
};
int Movie::findInsertLocation(int target, int left, int right)
{
	if (right == -1) return 0;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = cast->at(middle).getIndex();
		if (middle_id == target)
			return middle;
		if (middle_id < target) {
			left = middle + 1;
			continue;
		}
		right = middle - 1;
	};
	return right + 1;
};
void Movie::addActorToCast(Actor actor) {
	if (binarySearch(actor.getIndex(), 0, cast->count - 1) != -1) {
		cout << "join_cast: Error " << actor.first << " " << actor.last << " is already in the cast of " << movieTitle << endl;
		return;
	}
	int insertLocation = findInsertLocation(actor.getIndex(), 0, cast->count - 1);
	cast->insert(insertLocation, actor);
	cout << "join_cast: Added actor " << actor.first << " " << actor.last << " to the cast of " << movieTitle << endl;
	cout << "join_cast: Associated movie " << movieTitle << " with " << actor.first << " " << actor.last << endl; 
	actor.addMovie(movieid);
	return;
}
bool Movie::removeActorFromCast(unsigned int actorid) {
	int actorIndex = binarySearch(actorid, 0, cast->count - 1);
	if (actorIndex == -1)
	{
		// cout << "join_cast: Error " << actor.first << " " << actor.last << " is not in the cast of " << movieTitle << endl;
		return false;
	}
	cast->remove(actorIndex);
	return true;
}
void Movie::printCast() {
	cout << movieTitle << " features:" << endl;
	for (unsigned int i=0; i<cast->count; i++) {
		Actor curr = cast->at(i);
		cout << "- " << curr.first << " " << curr.last << endl;
	}
	return;
}