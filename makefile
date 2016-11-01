CORE := src/Core.cpp src/Functions.cpp

debug: $(CORE)
	g++ -o software.exe $(CORE)
