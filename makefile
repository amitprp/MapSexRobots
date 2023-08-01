Ass4: Robot.o Map.o Game.o Main.o
	g++ Robot.o Map.o Game.o Main.o -o Ass4
	
Robot.o: Robot.cpp Robot.h
	g++ -c Robot.cpp
	
Map.o: Robot.cpp Robot.h Map.cpp Map.h
	g++ -c Robot.cpp Map.cpp
	
Game.o: Robot.cpp Robot.h Map.cpp Map.h Game.cpp Game.h
	g++ -c Robot.cpp Map.cpp Game.cpp
	
Main.o: Robot.cpp Robot.h Map.cpp Map.h Game.cpp Game.h Main.cpp
	g++ -c Robot.cpp Map.cpp Game.cpp Main.cpp
