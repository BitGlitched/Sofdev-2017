#include "headers/Main.h"
#include "headers/GUI.h"

//std::vector<int> v;

//Function called once on startup
//Actually make everything here
void Startup()
{
   InitGUI();
}

//Function updated every frame
void Update()
{
   UpdateGUI();
   DrawGUI();
}
