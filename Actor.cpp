#include <iostream>
#include <stdlib.h>
#include "Actor.h"
using namespace std;

Actor::Actor(unsigned int actorid, string firstname, string lastname) {
	id = actorid;
	first = firstname;
	last = lastname;
	actorInMovie = new Array<int>;
}
Actor::Actor() {
	id = -1;
	first = "NoName";
	last = "NoName";
}

int Actor::getIndex()
{
	return id;
}
void Actor::addMovie(unsigned int movieid) {
	if (binarySearch(movieid, 0, actorInMovie->count - 1) != -1) return;
	int insertLocation = findInsertLocation(movieid, 0, actorInMovie->count - 1);
	actorInMovie->insert(insertLocation, movieid);
	return;
}
void Actor::deleteMovie(unsigned int movieid) {
	int location = binarySearch(movieid, 0, actorInMovie->count - 1);
	if (location == -1) return;
	actorInMovie->remove(location);
	return;
}

int Actor::binarySearch(int target, int left, int right)
{
	if (right == -1)
		return -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = actorInMovie->at(middle);
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
int Actor::findInsertLocation(int target, int left, int right)
{
	if (right == -1)
		return 0;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = actorInMovie->at(middle);
		if (middle_id == target)
			return middle;
		if (middle_id < target)
		{
			left = middle + 1;
			continue;
		}
		right = middle - 1;
	};
	return right + 1;
};