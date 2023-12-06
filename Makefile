all:
	g++ -I src/include -L src/lib  Events.cpp utils.cpp math.cpp Entity.cpp main.cpp renderwindow.cpp  -o Simulador -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 