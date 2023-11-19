#include <iostream>
#include <fstream>
using namespace std;
#include <getopt.h>
#include <assert.h>
#include "Parser.h"
#include "MovieDatabase.h"

void add_movie(unsigned int movieid, unsigned int year, string lastname, string firstname, string title, MovieDatabase &moviedb) {
   moviedb.addMovie(movieid, year, lastname, firstname, title);
}

void remove_movie(unsigned int movieid, MovieDatabase &moviedb) {
	moviedb.removeMovie(movieid);
}

void register_actor(unsigned int actorid, string lastname, string firstname, MovieDatabase &moviedb)
{
	moviedb.addActor(actorid, firstname, lastname);
}

void join_cast(unsigned int actorid, unsigned int movieid, MovieDatabase &moviedb) {
	moviedb.addActorToMovie(actorid, movieid);
}
void cast(unsigned int movieid, MovieDatabase &mdb) {
	mdb.printCastOfMovie(movieid);
}
void career(unsigned int actorid, MovieDatabase &mdb) {
	mdb.printCareer(actorid);
}
void remove_actor(unsigned int actorid, MovieDatabase &mdb)
{
	mdb.removeActor(actorid);
}

bool accept_commands(istream &is, bool silent=false, bool echo=false) {
   string command;  
   string line;
   MovieDatabase* moviedb = new MovieDatabase();

   while (1) {
      if (!silent) {
         cout << endl << "Enter a command: " << endl;
		 cout << "Choose from " << endl
			  << "   add_movie <movieid> <year> <dirlast> <dirfirst> <title>" << endl
			  << "   remove_movie <movieid>" << endl
			  << "   register_actor <actorid> <last> <first>" << endl
			  << "   join_cast <actorid> <movieid>" << endl
			  << "   cast <movieid>" << endl
			  << "   career <actorid>" << endl
			  << "   remove_actor <actorid>" << endl
			  << "   quit";
		 cout << endl << ": ";
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
         if (p.numArgs() > 0) 
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
         return true;
      }

      else if (p.getOperation() == "add_movie") {
         if (p.numArgs() < 5) 
            cout << std::endl << "Can't operate with " << MISSING_ARGS << endl;
         else {
            if (p.numArgs() > 5) 
               cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
			if (!Parser::isInteger(p.getArg(1)))
			{
				cout << "Error: field " << p.getArg(1) << " is not an integer" << endl;
			}
			else if (!Parser::isInteger(p.getArg(2)))
			{
				cout << "Error: field " << p.getArg(2) << " is not an integer" << endl;
			}
			else {
				add_movie(stoi(p.getArg(1)), stoi(p.getArg(2)), p.getArg(3), p.getArg(4), p.getArg(5), *moviedb);
			}
		 }
      }
      else if (p.getOperation() == "remove_movie") {
         if (p.numArgs() < 1) 
            cout << std::endl << "Can't operate with " << MISSING_ARGS << endl;
         else {
            if (p.numArgs() > 1) 
               cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
			if (!Parser::isInteger(p.getArg(1)))
			{
				cout << "Error: field " << p.getArg(1) << " is not an integer" << endl;
			}
			else {
				remove_movie(stoi(p.getArg(1)), *moviedb);
			}
         }
      }
	  else if (p.getOperation() == "register_actor")
	  {
		  if (p.numArgs() < 3)
			  cout << std::endl
				   << "Can't operate with " << MISSING_ARGS << endl;
		  else
		  {
			  if (p.numArgs() > 3)
				  cout << std::endl
					   << "Ignoring " << UNEXPECTED_ARGS << endl;
			  if (!Parser::isInteger(p.getArg(1)))
			  {
				  cout << "Error: field " << p.getArg(1) << " is not an integer" << endl;
			  }
			  else
			  {
				  register_actor(stoi(p.getArg(1)), p.getArg(2), p.getArg(3), *moviedb);
			  }
		  }
	  }
	  else if (p.getOperation() == "join_cast") {
         if (p.numArgs() < 2) 
            cout << std::endl << "Can't operate with " << MISSING_ARGS << endl;
         else {
            if (p.numArgs() > 2) 
               cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
            if (!Parser::isInteger(p.getArg(1))) {
               cout << "Error: field " << p.getArg(1) << 
                                " is not an integer" << endl;
            }
			else if (!Parser::isInteger(p.getArg(2)))
			{
				cout << "Error: field " << p.getArg(2) << " is not an integer" << endl;
			}
			else {
              join_cast(stoi(p.getArg(1)), stoi(p.getArg(2)), *moviedb);
            }
         }
      }
	  else if (p.getOperation() == "cast")
	  {
		  if (p.numArgs() < 1)
			  cout << std::endl
				   << "Can't operate with " << MISSING_ARGS << endl;
		  else
		  {
			  if (p.numArgs() > 1)
				  cout << std::endl
					   << "Ignoring " << UNEXPECTED_ARGS << endl;
			  if (!Parser::isInteger(p.getArg(1)))
			  {
				  cout << "Error: field " << p.getArg(1) << " is not an integer" << endl;
			  }
			  else
			  {
				  cast(stoi(p.getArg(1)), *moviedb);
			  }
		  }
	  }
	  else if (p.getOperation() == "career")
	  {
		  if (p.numArgs() < 1)
			  cout << std::endl
				   << "Can't operate with " << MISSING_ARGS << endl;
		  else
		  {
			  if (p.numArgs() > 1)
				  cout << std::endl
					   << "Ignoring " << UNEXPECTED_ARGS << endl;
			  if (!Parser::isInteger(p.getArg(1)))
			  {
				  cout << "Error: field " << p.getArg(1) << " is not an integer" << endl;
			  }
			  else
			  {
				  career(stoi(p.getArg(1)), *moviedb);
			  }
		  }
	  }
	  else if (p.getOperation() == "remove_actor")
	  {
		  if (p.numArgs() < 1)
			  cout << std::endl
				   << "Can't operate with " << MISSING_ARGS << endl;
		  else
		  {
			  if (p.numArgs() > 1)
				  cout << std::endl
					   << "Ignoring " << UNEXPECTED_ARGS << endl;
			  if (!Parser::isInteger(p.getArg(1)))
			  {
				  cout << "Error: field " << p.getArg(1) << " is not an integer" << endl;
			  }
			  else
			  {
				  remove_actor(stoi(p.getArg(1)), *moviedb);
			  }
		  }
	  }
	  else {
         cout << std::endl << 
              "Command not recognized. Please try again." << endl; 
      }
   }
   return true;
}

int main()
{
  accept_commands(cin, true, false);
  return 0;
}
