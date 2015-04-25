flags = -std=c++0x


all: main.o Utils.o Game.o InputManager.o Object.o Player.o Resources.o LD32.o Beasts.o Beast.o Network.o City.o BattleManager.o Upgrade.o
	g++ main.o Utils.o Game.o InputManager.o Object.o Player.o Resources.o LD32.o Beasts.o Beast.o Network.o City.o BattleManager.o Upgrade.o -o a.out -L SFML-2.2/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=SFML-2.2/lib

clean:
	rm *.o

main.o: main.cpp
	g++ -c $(flags) main.cpp -I SFML-2.2/include

Game.o: Game.cpp Game.h
	g++ -c $(flags) Game.cpp -I SFML-2.2/include

InputManager.o: InputManager.cpp InputManager.h
	g++ -c $(flags) InputManager.cpp -I SFML-2.2/include

Object.o: Object.cpp Object.h
	g++ -c $(flags) Object.cpp -I SFML-2.2/include

Utils.o: Utils.cpp Utils.h
	g++ -c $(flags) Utils.cpp -I SFML-2.2/include

Player.o: Player.cpp Player.h Utils.o
	g++ -c $(flags) Player.cpp -I SFML-2.2/include

LD32.o: LD32.cpp LD32.h
	g++ -c $(flags) LD32.cpp -I SFML-2.2/include

Resources.o: Resources.cpp Resources.h
	g++ -c $(flags) Resources.cpp -I SFML-2.2/include

Beasts.o: Beasts.cpp Beasts.h
	g++ -c $(flags) Beasts.cpp -I SFML-2.2/include

Beast.o: Beast.cpp Beast.h
	g++ -c $(flags) Beast.cpp -I SFML-2.2/include

Network.o: Network.cpp Network.h
	g++ -c $(flags) Network.cpp -I SFML-2.2/include

City.o: City.cpp City.h
	g++ -c $(flags) City.cpp -I SFML-2.2/include

BattleManager.o: BattleManager.cpp BattleManager.h
	g++ -c $(flags) BattleManager.cpp -I SFML-2.2/include

Upgrade.o: Upgrade.cpp Upgrade.h
	g++ -c $(flags) Upgrade.cpp -I SFML-2.2/include

