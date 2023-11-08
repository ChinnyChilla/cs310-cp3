COURSE = cs310
SEMESTER = fall2023
CP_NUMBER = 1
LASTNAME = Zheng
GITUSERID = ChinnyChilla
EXE = movie_db
MENU_EXE = menu_sample

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar
ZIPFILE = $(TARFILE).gz

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -Wextra -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/sample_menu.o $(OBJ)/MovieDatabase.o $(OBJ)/Movie.o $(OBJ)/Actor.o $(OBJ)/Array.o
	$(CC) $(FLAGS) $(OBJ)/sample_menu.o $(OBJ)/MovieDatabase.o $(OBJ)/Movie.o $(OBJ)/Actor.o $(OBJ)/Array.o -o $@

$(OBJ)/sample_menu.o: sample_menu.cpp Parser.h
	$(CC) $(FLAGS) -c sample_menu.cpp -o $@

$(OBJ)/MovieDatabase.o: MovieDatabase.cpp MovieDatabase.h Movie.h Actor.h Array.cpp
	$(CC) $(FLAGS) -c MovieDatabase.cpp -o $@

$(OBJ)/Movie.o: Movie.cpp Movie.h Actor.h
	$(CC) $(FLAGS) -c Movie.cpp -o $@

$(OBJ)/Actor.o: Actor.cpp Actor.h
	$(CC) $(FLAGS) -c Actor.cpp -o $@
	
$(OBJ)/Array.o: Array.cpp Array.h
	$(CC) $(FLAGS) -c Array.cpp -o $@
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(ZIPFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(ZIPFILE)
