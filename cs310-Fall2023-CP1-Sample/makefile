COURSE = cs310
SEMESTER = Fall2023
CP_NUMBER = 1
LASTNAME = Lewis
GITUSERID = mlewis608
EXE = movie_db_sample
MENU_EXE = menu_sample

# REPODIR = ../$(COURSE)-$(SEMESTER)-$(CP_NUMBER)-$(GITUSERID)
REPODIR = ../$(COURSE)-$(SEMESTER)-CP1-Sample
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/movie_db.o $(OBJ)/Movie.o $(OBJ)/Cast.o \
		$(OBJ)/ActorDB.o $(OBJ)/MovieDB.o $(OBJ)/Actor.o
	$(CC) $(FLAGS) $(OBJ)/movie_db.o $(OBJ)/Movie.o \
		$(OBJ)/Cast.o $(OBJ)/ActorDB.o $(OBJ)/MovieDB.o \
		$(OBJ)/Actor.o -o $@

$(OBJ)/movie_db.o: movie_db.cpp Parser.h
	$(CC) $(FLAGS) -c movie_db.cpp -o $@

$(OBJ)/Movie.o: Movie.cpp Movie.h
	$(CC) $(FLAGS) -c Movie.cpp -o $@

$(OBJ)/Actor.o: Actor.cpp Actor.h
	$(CC) $(FLAGS) -c Actor.cpp -o $@

$(OBJ)/Cast.o: Cast.cpp Cast.h
	$(CC) $(FLAGS) -c Cast.cpp -o $@

$(OBJ)/ActorDB.o: ActorDB.cpp ActorDB.h
	$(CC) $(FLAGS) -c ActorDB.cpp -o $@

$(OBJ)/MovieDB.o: MovieDB.cpp MovieDB.h
	$(CC) $(FLAGS) -c MovieDB.cpp -o $@

$(BIN)/$(MENU_EXE): $(OBJ)/sample_menu.o
	$(CC) $(FLAGS) $(OBJ)/sample_menu.o -o $@

$(OBJ)/sample_menu.o: sample_menu.cpp Parser.h
	$(CC) $(FLAGS) -c sample_menu.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
