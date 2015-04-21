GCC=g++
CMP=${GCC} ${CMP-FLAGS}
CMP-FLAGS=-c -std=c++0x
LN-FLAGS=${LIBRARIES}
LIBRARIES=-lsfml-graphics -lsfml-system -lsfml-window
OUTPUT=LD32.x

all: BattleManager.o Beast.o Beasts.o City.o Game.o InputManager.o LD32.o main.o Network.o Object.o Utils.o Player.o Resources.o Upgrade.o
	${GCC} -o ${OUTPUT} *.o ${LN-FLAGS}

BattleManager.o: BattleManager.cpp BattleManager.h
	${CMP} BattleManager.cpp

Beast.o: Beast.cpp Beast.h
	${CMP} Beast.cpp

Beasts.o: Beasts.cpp Beasts.h
	${CMP} Beasts.cpp

City.o: City.cpp City.h
	${CMP} City.cpp

Game.o: Game.cpp Game.h
	${CMP} Game.cpp

InputManager.o: InputManager.cpp InputManager.h
	${CMP} InputManager.cpp

LD32.o: LD32.cpp LD32.h
	${CMP} LD32.cpp

main.o: main.cpp
	${CMP} main.cpp

Network.o: Network.cpp Network.h
	${CMP} Network.cpp

Object.o: Object.cpp Object.h
	${CMP} Object.cpp

Utils.o: Utils.cpp Utils.h
	${CMP} Utils.cpp

Player.o: Player.cpp Player.h
	${CMP} Player.cpp

Resources.o: Resources.cpp Resources.h
	${CMP} Resources.cpp

Upgrade.o: Upgrade.cpp Upgrade.h
	${CMP} Upgrade.cpp

clean:
	rm *.o
	rm ${OUTPUT}