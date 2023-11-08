#include "ActorDB.h"

ActorDB::ActorDB() {
}

bool ActorDB::find(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid)
			return true;
	}
	return false;
}

string ActorDB::getName(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid)
			return actors[i].getName();
	}
	return "EMPTY";
}

bool ActorDB::addActor(const Actor &actor) {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actor.getID())
			return false;
	}
	actors.push_back(actor);
	return true;
}

/*
void ActorDB::showCareer(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid) {
			cout << actors[i].getName << " has acted in:" << 
				endl;
			break;
	}
	if (i < actors.size())
		actors[i].showCareer();
	else 
		cout << "actor id " << actorid << " not found" << endl;
}
*/
