#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <iostream>
using namespace std;
#include <vector>

//#include "MovieDB.h"

class Actor {
	private:
		unsigned int actor_id;
		string last;
		string first;
		vector<unsigned int> movies;		
	public:
		Actor();
		Actor(unsigned int act_id, string last, string first); 
		bool addMovie(const unsigned int movie_id);
		//void showCareer(const MovieDB &moviedb) const;

		string getName() const { 
			return first + " " + last;
		}
		unsigned int getID() const { return actor_id; }
};

#endif
