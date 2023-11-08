#ifndef __MOVIE_H_
#define __MOVIE_H_

#include <iostream>
using namespace std;

#include "Cast.h"

class Movie {
	private:
		unsigned int movie_id;
		unsigned int year;
		string title;
		string director_last;
		string director_first;
		Cast cast;		
	public:
		Movie();
		Movie(unsigned int mid, unsigned int year, string ttl,
			string dir_last, string dir_first); 
		bool addActor(unsigned int act_id);
		void showCast(const ActorDB &actordb) const;

		unsigned int getID() const { return movie_id; }
		unsigned int getYear() const { return year; }
		string getTitle() const { return title; }
		string getDirector() const {
			return director_first + " " + director_last;
		}
};

#endif
