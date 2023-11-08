#include "Actor.h"

Actor::Actor() {
	first = "";
	last = "";
	actor_id = 0;
}

Actor::Actor(unsigned int act_id, string lname, string fname) {
	first = fname;
	last = lname;
	actor_id = act_id;
}

bool Actor::addMovie(const unsigned int movieid) {
	for (unsigned int i = 0; i < movies.size(); i++) {
		if (movies[i] == movieid)
			return false;
	}
	movies.push_back(movieid);
	return true;
}

/*
void Actor::showCareer(const MovieDB &moviedb) const {
	string movietitle;
	cout << first << " " << last << " has acted in:" << endl;
	for (unsigned int i = 0; i < movies.size(); i++) {
		if (moviedb.find(movies[i])) {
			movietitle = moviedb.getTitle(movies[i].getID());
			cout << "- " << movietitle << endl;
		}
	}
}
*/
