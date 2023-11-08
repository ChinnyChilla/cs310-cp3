#ifndef __MOVIEDB_H_
#define __MOVIEDB_H_

#include <iostream>
using namespace std;

#include "Movie.h" 
#include <vector>

class MovieDB {
	private:
		vector<Movie> movies;		
	public:
		MovieDB();
		bool addMovie(const Movie &movie);
		bool removeMovie(unsigned int movieid);
		bool addActor(unsigned int movieid, unsigned int actorid);
		string getTitle(unsigned int movieid);
		bool find(unsigned int movieid);
		void showMovie(unsigned int movieid,
				const ActorDB &actordb) const;
};

#endif
