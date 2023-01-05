EXE = trajets
OBJETS = Menu.o Trajet.o TrajetSimple.o TrajetCompose.o Maillon.o Liste.o Catalogue.o 
FLAGS = -c -std=c++11 -ansi -Wall -pedantic # pour débug -c -DMAP -std=c++11 -ansi -Wall -pedantic

$(EXE): $(OBJETS)
	g++ -o $(EXE) $(OBJETS)
	rm *.o

Trajet.o: Trajet.cpp
	g++ $(FLAGS) Trajet.cpp
TrajetSimple.o: TrajetSimple.cpp
	g++ $(FLAGS) TrajetSimple.cpp
TrajetCompose.o: TrajetCompose.cpp
	g++ $(FLAGS) TrajetCompose.cpp
Liste.o: Liste.cpp
	g++ $(FLAGS) Liste.cpp
Catalogue.o: Catalogue.cpp
	g++ $(FLAGS) Catalogue.cpp
Menu.o: Menu.cpp
	g++ $(FLAGS) Menu.cpp
Maillon.o: Maillon.cpp
	g++ $(FLAGS) Maillon.cpp
clean:
	rm $(OBJETS) $(EXE)
