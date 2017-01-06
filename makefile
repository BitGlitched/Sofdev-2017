BACKEND := src/Main.cpp src/Functions.cpp

INCLUDE_PATHS = -Iinclude\SDL2

LIBRARY_PATHS := -Llib

LINKER_FLAGS := -lmingw32 -lSDL2main -lSDL2

COMPILER_FLAGS := -fpermissive -Wwrite-strings -std=c++11 -Iinclude

debug: $(CORE)
	g++ $(BACKEND) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o bin/OpenCircuit.exe
