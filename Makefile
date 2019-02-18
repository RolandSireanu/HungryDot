CPP_SOURCE_FILES = main.cpp 
CPP_SOURCE_FILES += Window.cpp
CPP_SOURCE_FILES += Game.cpp
CPP_SOURCE_FILES += HungryDot.cpp 
CPP_SOURCE_FILES += World.cpp 
CPP_SOURCE_FILES += FpsRegulator.cpp 
CPP_SOURCE_FILES += Arrow.cpp 
CPP_SOURCE_FILES += ArrowsPool.cpp 
CPP_SOURCE_FILES += EventManager.cpp
CPP_SOURCE_FILES += StateManager.cpp
CPP_SOURCE_FILES += StateIntro.cpp

EXECUTABLE = HungryDot


show:
	echo $(CPP_SOURCE_FILES)


all :
	 g++ $(CPP_SOURCE_FILES) -o $(EXECUTABLE) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lOpenGL -std=c++17

debug:
	g++  -g $(CPP_SOURCE_FILES) -o $(EXECUTABLE) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lOpenGL -DDEBUG -Os

run : all
	./$(EXECUTABLE)

runDebug: debug
	./$(EXECUTABLE)
	
clean :
	rm $(EXECUTABLE)
