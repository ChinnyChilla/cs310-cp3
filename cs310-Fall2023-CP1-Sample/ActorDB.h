#ifndef __ACTORDB_H_
#define __ACTORDB_H_

#include <iostream>
using namespace std;

#include <vector>
#include "Actor.h"

class ActorDB {
	private:
		vector<Actor> actors;		
	public:
		ActorDB();
		bool find(unsigned int actorid) const;
		string getName(unsigned int actorid) const;
		bool addActor(const Actor &actor);
		//void showCareer(unsigned int actorid) const;
};

#endif
