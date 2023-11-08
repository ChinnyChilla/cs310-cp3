#include <iostream>
#include <fstream>
using namespace std;
#include <getopt.h>
#include <assert.h>
#include "Parser.h"

#include "MovieDB.h"
#include "ActorDB.h"
MovieDB moviedb;
ActorDB actordb;

void do_add_movie(int movie_id, int year, string dir_last, string dir_first, 
	       string title) {
	/*
	cout << "do_add_movie()" << endl; 
	cout << "   movie_id: " << movie_id << endl; 
	cout << "       year: " << year << endl; 
	cout << "   dir_last: " << dir_last << endl; 
	cout << "  dir_first: " << dir_first << endl; 
	cout << "      title: " << title << endl; 
	*/
	Movie m(movie_id, year, title, dir_last, dir_first);
	if (moviedb.addMovie(m)) 
		cout << "add_movie: Added " << m.getTitle() << " (" <<
		       m.getYear() << ") directed by " << 
	       	       m.getDirector() << endl;
	else
		cout << "add_movie: Error movie id " << m.getID() << 
			" already in use" << endl;
	return;
}

void do_remove_movie(int movie_id) {
	string title = moviedb.getTitle(movie_id); 
	if (moviedb.removeMovie(movie_id))
		cout << "remove_movie: Removed " << title << endl;
	else
		cout << "remove_movie: Error movie id " << movie_id << 
			" does not exist" << endl;
	return;
}

void do_register_actor(int actor_id, string actor_last, string actor_first) {
	/*
	cout << "do_register_actor()" << endl;
	cout << "   actor_id: " << actor_id << endl; 
	cout << " actor_last: " << actor_last << endl; 
	cout << "actor_first: " << actor_first << endl; 
	*/
	Actor a(actor_id, actor_last, actor_first);
	if (actordb.addActor(a)) 
		cout << "register_actor: Registered actor " << 
			a.getName() << endl;
	else
		cout << "register_actor: Error actor id " << actor_id << 
			" already in use" << endl;
	return;
}

void do_join_cast(int actor_id, int movie_id) {
	/*
	cout << "do_join_cast()" << endl; 
	cout << "   actor_id: " << actor_id << endl; 
	cout << "   movie_id: " << movie_id << endl; 
	*/
	if (!moviedb.find(movie_id)) {
		cout << "join_cast: Error movie id " << movie_id <<
			" does not exist" << endl;
		return;
	}
	if (!actordb.find(actor_id)) {
		cout << "join_cast: Error actor id " << actor_id <<
			" does not exist" << endl;
		return;
	}
	if (!moviedb.addActor(movie_id, actor_id)) {
		cout << "join_cast: Error " << actordb.getName(actor_id) << 
		" is already in the cast of " << moviedb.getTitle(movie_id) << 
		endl;
	}
	else {
		cout << "join_cast: Added actor " << 
		actordb.getName(actor_id) << " to the cast of " << 
		moviedb.getTitle(movie_id) << endl;
	}
	return;
}

void do_cast(int movie_id) {
	/*
	cout << "do_cast()" << endl; 
	cout << "   movie_id: " << movie_id << endl; 
	*/
	if (!moviedb.find(movie_id)) {
		cout << "cast: Error movie id " << movie_id <<
			" does not exist" << endl;
		return;
	}
	moviedb.showMovie(movie_id, actordb);
}

/*
void do_career(int actor_id) {
   cout << "do_career()" << endl; 
   cout << "   actor_id: " << actor_id << endl; 
   cout << "NOT IMPLEMENTED" << endl;
}
*/

bool expected(Parser &p, unsigned int howmany) {
   if (p.numArgs() < howmany) { 
      cout << std::endl << "Can't operate with " << MISSING_ARGS << endl;
      return false;
   }
   if (p.numArgs() > howmany) {
      cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
      return true;
   }
   return true;
}

bool assertInt(Parser &p, unsigned int argnum) {
   if (!Parser::isInteger(p.getArg(argnum))) {
      cout << "Error: field " << p.getArg(argnum) << 
              " is not an integer" << endl;
      return false;
   }
   return true;
}

bool accept_commands(istream &is, bool silent=false, bool echo=false) {
   string command;  
   string line;

   while (1) {
      if (!silent) {
         cout << endl << "Enter a command: " << endl;
         cout << "Choose from " << endl <<
            "   add_movie <movieid> <year> <dirlast> <dirfirst> <title>" << endl <<
            "   remove_movie <movieid>" << endl << 
	    "   register_actor <actorid> <last> <first>" << endl << 
	    "   join_cast <actorid> <movieid>" << endl << 
	    "   cast <movieid>" << endl << 
	    // "   career <actorid>" << endl << 
            "   quit" << endl; 
         cout << ": ";
      }

      getline(is, line);
      if (echo) {
         cout << endl;
         cout << "======================================================" << 
		 endl;
         cout << line << endl;
         cout << "======================================================" << 
		 endl;
      }

      Parser p(line);
      if (p.getOperation().empty()) {
         if (is.fail())
            return false;
         continue;
      }

      if (p.getOperation() == "quit") {
         expected(p, 0);
         return true;
      }

      else if (p.getOperation() == "add_movie") {
         if (!expected(p, 5))  
            continue;
	 if (!assertInt(p, 1))
            continue;
	 if (!assertInt(p, 2))
            continue;
         int movie_id = stoi(p.getArg(1));
         int year = stoi(p.getArg(2));
         do_add_movie(movie_id, year, p.getArg(3), p.getArg(4), p.getArg(5));
      }
      else if (p.getOperation() == "remove_movie") {
         if (!expected(p, 1))  
            continue;
	 if (!assertInt(p, 1))
            continue;
         int movie_id = stoi(p.getArg(1)); 
         do_remove_movie(movie_id);
      }
      else if (p.getOperation() == "register_actor") {
         if (!expected(p, 3))  
            continue;
	 if (!assertInt(p, 1))
            continue;
         int actor_id = stoi(p.getArg(1));
         do_register_actor(actor_id, p.getArg(2), p.getArg(3));
      }
      else if (p.getOperation() == "join_cast") {
         if (!expected(p, 2))  
            continue;
	 if (!assertInt(p, 1))
            continue;
	 if (!assertInt(p, 2))
            continue;
         int actor_id = stoi(p.getArg(1));
         int movie_id = stoi(p.getArg(2));
         do_join_cast(actor_id, movie_id);
      }
      else if (p.getOperation() == "cast") {
         if (!expected(p, 1))  
            continue;
	 if (!assertInt(p, 1))
            continue;
         int movie_id = stoi(p.getArg(1)); 
         do_cast(movie_id);
      }
      /*
      else if (p.getOperation() == "career") {
         if (!expected(p, 1))  
            continue;
	 if (!assertInt(p, 1))
            continue;
         int actor_id = stoi(p.getArg(1)); 
         do_career(actor_id);
      }
      */
      else {
         cout << std::endl << 
              "Command not recognized. Please try again." << endl; 
      }
   }
   return true;
}

int main()
{
  accept_commands(cin, false, false);
  return 0;
}
