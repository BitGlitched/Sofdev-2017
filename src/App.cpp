#include "headers/Main.h"
#include "headers/GUI.h"

Wire test;

//std::vector<int> v;

//Function called once on startup
//Actually make everything here
void Startup()
{
   InitGUI();
   //test = Wire(Vector2(49.5f, 0.0f), Vector2(0.0f, 0.0f));
}

//Function updated every frame
void Update()
{
   UpdateGUI();
   DrawGUI();
   //test.Draw();
}
