#include <iostream>
#include <stdlib.h>
#include "MovieDatabase.h"

MovieDatabase::MovieDatabase() {
	movies = new Array<Movie*>;
	actors = new Array<Actor*>;
}

MovieDatabase::~MovieDatabase()
{
	for (unsigned int i=0; i<movies->count; i++) {
		delete movies->arr[i];
	}
	delete movies;
	for (unsigned int i = 0; i < actors->count; i++)
	{
		delete actors->arr[i];
	}
	delete actors;
}
int MovieDatabase::findMovieIndex(int movieid)
{
	for (unsigned int i = 0; i < movies->count; i++)
	{
		Movie* curr = movies->at(i);
		if (curr->getIndex() == movieid)
		{
			return i;
		}
	}
	return -1;
}
int MovieDatabase::findActorIndex(int actorid)
{
	for (unsigned int i = 0; i < actors->count; i++)
	{
		Actor* curr = actors->at(i);
		if (curr->getIndex() == actorid)
		{
			return i;
		}
	}
	return -1;
}
int MovieDatabase::binarySearchMovie(int target, int left, int right)
{
	if (right == -1) return -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = movies->at(middle)->getIndex();
		if (middle_id == target) return middle;

		if (middle_id < target)
		{
			left = middle + 1;
			continue;
		}
		right = middle-1;
	};
	return -1;
};
int MovieDatabase::binarySearchActor(int target, int left, int right)
{
	if (right == -1)
		return -1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = actors->at(middle)->getIndex();
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
int MovieDatabase::findInsertLocationMovie(int target, int left, int right)
{
	if (right == -1) return 0;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = movies->at(middle)->getIndex();
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
int MovieDatabase::findInsertLocationActor(int target, int left, int right)
{
	if (right == -1)
		return 0;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int middle_id = actors->at(middle)->getIndex();
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
void MovieDatabase::addMovie(unsigned int movieid, unsigned int year, string dirlast, string dirfirst, string title) {
	if (binarySearchMovie(movieid, 0, movies->count - 1) != -1) {
		cout << "add_movie: Error movie id " << movieid << " already in use" << endl;
		return; 
	};
	Movie* newMovie = new Movie(movieid, year, dirlast, dirfirst, title);
	int insertLocation = findInsertLocationMovie(movieid, 0 , movies->count - 1);
 	movies->insert(insertLocation, newMovie);
	cout << "add_movie: " << "Added " << title << " (" << year << ") directed by " << dirfirst << " " << dirlast << endl;
	return;
}
void MovieDatabase::addActor(unsigned int actorid, string first, string last)
{
	if (binarySearchActor(actorid, 0, actors->count - 1) != -1)
	{
		cout << "register_actor: Error actor id " << actorid << " already in use" << endl;
		return;
	};
	Actor* newActor = new Actor(actorid, first, last);
	int insertLocation = findInsertLocationActor(actorid, 0, actors->count - 1);
	actors->insert(insertLocation, newActor);
	cout << "register_actor: Registered actor " << newActor->first << " " << newActor->last << endl;
	return;
}

void MovieDatabase::removeMovie(unsigned int movieid) {
	int location = binarySearchMovie(movieid, 0, movies->count - 1);

	if (location == -1) {
		cout << "remove_movie: Error movie id " << movieid << " does not exist" << endl;
		return;
	}
	Movie* movieToDelete = movies->at(location);
	for (unsigned int i=0; i<movieToDelete->cast->count; i++) {
		int currActorLocation = binarySearchActor(movieToDelete->cast->at(i), 0, movieToDelete->cast->count);
		Actor* currActor = actors->at(currActorLocation);
		currActor->deleteMovie(movieToDelete->getIndex());
	};
	cout << "remove_movie: Removed " << movieToDelete->getMovieTitle() << endl;
	movies->remove(location);
	delete movieToDelete;
	return;
}

void MovieDatabase::addActorToMovie(unsigned int actorid, unsigned int movieid) {
	int actorLocation = binarySearchActor(actorid, 0, actors->count - 1);
	if (actorLocation == -1) {
		cout << "join_cast: Error actor id " << actorid << " does not exist" << endl;
		return;
	}
	int movieLocation = binarySearchMovie(movieid, 0, movies->count - 1);
	if (movieLocation == -1) {
		cout << "join_cast: Error movie id " << movieid << " does not exist" << endl;
		return;
	}
	Movie* currMovie = movies->at(movieLocation);
	Actor* currActor = actors->at(actorLocation);
	currMovie->addActorToCast(currActor);
	return;
}
void MovieDatabase::printCastOfMovie(unsigned int movieid) {
	int location = binarySearchMovie(movieid, 0, movies->count - 1);
	if (location == -1) {
		cout << "cast: Error movie id " << movieid << " does not exist" << endl;
		return;
	}
	movies->at(location)->printCast();
	cout << movies->at(location)->getMovieTitle() << " features:" << endl;
	Array<int> *cast = movies->at(location)->cast;
	for (unsigned int i = 0; i < cast->count; i++)
	{
		int actorLocation = binarySearchActor(cast->at(i), 0, cast->count - 1);
		Actor* curr = actors->at(actorLocation);
		cout << "- " << curr->first << " " << curr->last << endl;
	}
	return;
}
void MovieDatabase::printCareer(unsigned int actorid) {
	int actorLocation = binarySearchActor(actorid, 0, actors->count - 1);
	if (actorLocation == -1)
	{
		cout << "career: Error actor id " << actorid << " does not exist" << endl;
		return;
	}
	Actor* actor = actors->at(actorLocation);
	cout << actor->first << " " << actor->last << " has acted in:" << endl;
	for (unsigned int i=0; i < actor->actorInMovie->count; i ++) {
		int movieLocation = binarySearchMovie(actor->actorInMovie->at(i), 0, movies->count - 1);
		if (movieLocation == -1) {continue;}
		Movie* movie = movies->at(movieLocation);
		cout << "- " << movie->getMovieTitle() << endl;
	};
	return;
}
void MovieDatabase::removeActor(unsigned int actorid) {
	int actorLocation = binarySearchActor(actorid, 0, actors->count - 1);
	if (actorLocation == -1)
	{
		cout << "remove_actor: Error actor id " << actorid << " does not exist" << endl;
		return;
	}
	Actor* actor = actors->at(actorLocation);
	for (unsigned int i = 0; i < actor->actorInMovie->count; i++)
	{
		int movieLocation = binarySearchMovie(actor->actorInMovie->at(i), 0, movies->count - 1);
		if (movieLocation == -1)
		{
			continue;
		}
		Movie* movie = movies->at(movieLocation);
		movie->removeActorFromCast(actorid);
	};
	// cout << "Removed Actor with id:" << actorid << endl;
	cout << actor->first << " " << actor->last << " removed from the program and all casts" << endl;
	actors->remove(actorLocation);
	delete actor;
	return;
}
void MovieDatabase::printMovieVector(Array<Movie> v) {
	cout << "starting " << endl;
	for (unsigned int i=0; i<v.count; i++ ){
		cout << "id: " << v.at(i).getIndex() << " | " << v.at(i).getMovieTitle() << endl;
	}
	cout << "end" << endl;
	return;
}
void MovieDatabase::printActorVector(Array<Actor> v)
{
	cout << "starting " << endl;
	for (unsigned int i = 0; i < v.count; i++)
	{
		cout << v.at(i).first << endl;
	}
	cout << "end" << endl;
	return;
}