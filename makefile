CORE := src/Core.cpp src/Functions.cpp

debug: $(CORE)
	g++ -o build/software.exe $(CORE)
