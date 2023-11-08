#include <cassert>
#include "MovieDB.h"

MovieDB::MovieDB() {
}

bool MovieDB::addMovie(const Movie &movie) {
	for (unsigned int i = 0; i < movies.size(); i++) {
		if (movies[i].getID() == movie.getID())
			return false;
	}
	movies.push_back(movie);
	return true;
}

bool MovieDB::removeMovie(unsigned int movieid) {
	for (unsigned int i = 0; i < movies.size(); i++) {
		if (movies[i].getID() == movieid) {
			for (i = i; i < movies.size()-1; i++) {
				movies[i] = movies[i+1];
			}
			movies.pop_back();
			return true;
		}
	}
	return false;
}

bool MovieDB::addActor(unsigned int movieid, unsigned int actorid) {
	for (unsigned int i = 0; i < movies.size(); i++) 
		if (movies[i].getID() == movieid)
			return movies[i].addActor(actorid);
	return false;
}

string MovieDB::getTitle(unsigned int movieid) {
	for (unsigned int i = 0; i < movies.size(); i++) 
		if (movies[i].getID() == movieid)
			return movies[i].getTitle();
	return("");
}

bool MovieDB::find(unsigned int movieid) {
	for (unsigned int i = 0; i < movies.size(); i++) 
		if (movies[i].getID() == movieid)
			return true; 
	return false;
}

void MovieDB::showMovie(unsigned int movieid, const ActorDB &actordb) const {
	unsigned int i = 0;
	for (i = 0; i < movies.size(); i++) {
		if (movies[i].getID() == movieid) {
			movies[i].showCast(actordb);
			return;
		}
	}
	cout << "movie id " << movieid << " not found" << endl;
}
