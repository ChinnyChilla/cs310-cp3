#include "Movie.h"

Movie::Movie() : cast() {
}

Movie::Movie(unsigned int mid, unsigned int yr, string ttl,
		string dir_last, string dir_first) : cast() {
	movie_id = mid;
	year = yr; 
	title = ttl;
	director_last = dir_last;
	director_first = dir_first;
}

bool Movie::addActor(unsigned int act_id) {
	return cast.addActor(act_id);
}

void Movie::showCast(const ActorDB &actordb) const {
	cout << title << " features:" << endl;
	cast.showCast(actordb);
}
