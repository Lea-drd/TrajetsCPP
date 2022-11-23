EXE = exe
OBJETS = Try.o Trajet.o TrajetSimple.o TrajetCompose.o Liste.o Catalogue.o
FLAGS = -c -g# pour débug -c -g

$(EXE): $(OBJETS)
	g++ -o $(EXE) $(OBJETS)

TrajetSimple: Try.o Trajet.o TrajetSimple.o
	g++ -o TrajetSimple Trajet.o TrajetSimple.o Try.o
TrajetCompose: Trajet.o TrajetCompose.o
	g++ -o TrajetCompose Trajet.o TrajetCompose.o Try.o

	
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
Try.o: Try.cpp
	g++ $(FLAGS) Try.cpp

test: $(OBJETS)
	g++ -DMAP -o test $(OBJETS)
