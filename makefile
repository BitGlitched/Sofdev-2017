BACKEND := src/Main.cpp src/font.cpp src/Rendering.cpp src/headers/types/Shader.cpp src/Interface.cpp src/headers/types/Texture.cpp src/headers/types/Color.cpp

FRONTEND := src/App.cpp

INCLUDE_PATHS = -Iinclude\SDL2

LIBRARY_PATHS := -Llib

LIBS := lib/GL/GLFW/glfw3dll.a lib/GL/libglew32.dll.a lib/GL/libSOIL.a

LINKER_FLAGS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -L./lib/GL -lopengl32 -lglew32

COMPILER_FLAGS := -fpermissive -Wwrite-strings -std=c++11 -Iinclude

OUTPUT := -o bin/OpenCircuit.exe

debug: $(CORE)
	g++ $(OUTPUT) $(BACKEND) $(FRONTEND) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBS) $(LIBRARY_PATHS) $(LINKER_FLAGS)
