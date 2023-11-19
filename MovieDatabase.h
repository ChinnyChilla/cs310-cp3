#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Movie.h"
using namespace std;

class MovieDatabase {

	public:
		Array<Movie*>* movies;
		Array<Actor*>* actors;
		MovieDatabase();
		~MovieDatabase();
		int findMovieIndex(int movieId);
		int findActorIndex(int actorId);
		void addMovie(unsigned int movieid, unsigned int year, string dirlast, string dirfirst, string title);
		void addActor(unsigned int actorid, string first, string last);
		void removeMovie(unsigned int movieid);
		void removeActor(unsigned int actorid);
		void addActorToMovie(unsigned int actorid, unsigned int movieid);
		void printCastOfMovie(unsigned int movieid);
		int binarySearchMovie(int target, int left, int right);
		int binarySearchActor(int target, int left, int right);
		void printCareer(unsigned int actorid); 
		int findInsertLocationMovie(int target, int left, int right);
		int findInsertLocationActor(int target, int left, int right);
		void printMovieVector(Array<Movie> v);
		void printActorVector(Array<Actor> v);
		
};