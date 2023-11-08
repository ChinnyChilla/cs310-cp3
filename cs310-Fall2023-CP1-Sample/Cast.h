#ifndef __CAST_H_
#define __CAST_H_

#include <iostream>
using namespace std;

#include "ActorDB.h"

class Cast {
	private:
		vector<unsigned int> actors;		
	public:
		Cast();
		bool addActor(const unsigned int act_id);
		void showCast(const ActorDB &actordb) const;
};

#endif
