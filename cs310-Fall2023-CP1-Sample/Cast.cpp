#include "Cast.h"

#include <iostream>
using namespace std;

Cast::Cast() {
}

bool Cast::addActor(const unsigned int act_id) {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i] == act_id)
			return false;
	}
	actors.push_back(act_id);
	return true;
}

void Cast::showCast(const ActorDB &actordb) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actordb.find(actors[i]))
			cout << "- " << actordb.getName(actors[i]) << endl;
	}
}
