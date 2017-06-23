#include "headers/Main.h"
#include <fstream>
#include <string>
#include <sstream>

namespace patch
{
   template <typename T>
   std::string to_string(T value)
   {
     //create an output string stream
     std::ostringstream os;

     //throw the value into the string stream
     os << value;

     //convert the string stream into a string and return
     return os.str();
   }

   float stof(std::string str)
   {
      stringstream ss;
      double fl;

      ss << str; // sends the contents of str to the stringstream ss
      ss >> fl; // extracts the contents of the stringstream, converts to a float (if a valid conversion is possible) and assigns the result (if possible) to fl
      ss.clear(); // clears any error and eof flags so the stringstream can be used again after it has reached eof (or some error)
                  // (the eof flag is set each time you extract all of its contents with >>)
      return (float)fl; // stores an empty string in the stringstream -- you may or may not need this depending on the rest of your program.
   }
}

#define NEW_FILE "NewCircuit.oc"

void CreateComponent(int compID, Vector2 transform, int rotation)
{
   components.push_back(new GUIElement(transform.x, transform.y, 1.0f, 1.0f));

   if (compID == COMPBATTERY)
   {
      components.at(components.size() - 1)->texture = texBattery;
   }
   else if (compID == COMPSWITCH)
   {
      components.at(components.size() - 1)->texture = texSwitchOpen;
   }
   else if (compID == COMPWIRE)
   {
      components.at(components.size() - 1)->texture = texWire;
   }
   else if (compID == COMPWIRE90)
   {
      components.at(components.size() - 1)->texture = texWireBend;
   }
   else if (compID == COMPRESISTOR)
   {
      components.at(components.size() - 1)->texture = texResistor;
   }
   else if (compID == COMPIC)
   {
      components.at(components.size() - 1)->texture = texIC;
   }
   else if (compID == COMPLIGHT)
   {
      components.at(components.size() - 1)->texture = texLight;
   }

   components.at(components.size() - 1)->rotation = rotation;
}

void SaveFile()
{
   //Open the room file
   FILE* file = fopen(NEW_FILE, "w");

   //If there is no new file opened/created
   if (!file)
   {
      //If we could not open the room file, abort saving
      printf("ERROR: Could not open the %s file. This means the schematic will not be saved.\n", NEW_FILE);
      return;
   }

   //Loops through all the elements in the editor
   for (GUIElement* i : components)
   {
      std::string buffer = patch::to_string(i->ID) + ":" + patch::to_string(i->transform.x) + "," + patch::to_string(i->transform.y) + ";" + patch::to_string(i->rotation) + ";";
      fprintf(file, buffer.c_str());
   }

   fclose (file);
}

void ReadFile()
{
   //Open the room file
   std::ifstream file(NEW_FILE);

   int ObjectCount = 0;

   //If there is no room file opened/created
   if (!file.is_open())
   {
      //If we could not open the room file, abort saving
      printf("ERROR: Could not open the %s file. This means the schematic will not be loaded.\n", ROOM_FILE);
      return;
   }

   //Buffer to store file info in
   std::string buffer;

   std::getline(file, buffer);

   bool passedID = false;
   bool passedX = false;
   bool passedY = false;

   int objID = -1;

   std::string posBuffer;

   Vector2 objPosition;

   for (std::string::size_type i = 0; i < buffer.size(); i++)
   {
      //Sees whether the ID has been completed yet
      if (!passedID)
      {
         if (buffer[i] == ':')
         {
            passedID = true;
            //printf("Passed the ID!\n");
            printf("Before: %i\n", objID + 47);
            printf("After:%i\n\n", objID);
            continue;
         }

         //If there was a previous integer and the ID already has a number in it
         else if (objID != -1)
         {
            //We make it the front digit/s by multiplying it by 10
            objID = (objID * 10);
            //printf("Increased by ten\n");
         }

         int accum = (int)(objID / 10.0f);

         //Add the number to the ID
         objID += (int)buffer[i] - 47 - accum;

         //printf("Started ID\n");
      }
      else if (!passedX)
      {
         if (buffer[i] == ',')
         {
            objPosition.x = patch::stof(posBuffer);
            posBuffer = "";
            passedX = true;
            //printf("Finished X pos buffer\n");
         }
         else
         {
            posBuffer += buffer[i];
            //printf("Added to the X pos buffer %c\n", buffer[i]);
         }
      }
      else if (!passedY)
      {
         if (buffer[i] == ';')
         {
            objPosition.y = patch::stof(posBuffer);
            posBuffer = "";
            passedY = true;

         }
         else
         {
            posBuffer += buffer[i];
            //printf("Added to the Y pos buffer %c\n", buffer[i]);
         }
      }
      else
      {
         if (buffer[i] == ';')
         {
            rotation = patch::stoi(posBuffer);
            posBuffer = "";
            //printf("ID: %i\n", objID);
            //printf("Position: %f, %f\n", objPosition.x, objPosition.y);
            CreateComponent(objID, objPosition, rotation);
            ObjectCount++;
            //printf("%i\n", ObjectCount);
            //Reset Variables
            objID = -1;
            objPosition = Vector2();
            passedID = false;
            passedX = false;
            passedY = false;
            rotation = 1;
         }
         else
         {
            posBuffer += buffer[i];
            //printf("Added to the Y pos buffer %c\n", buffer[i]);
         }
      }
   }

   printf("Room file contents: %s\n", buffer.c_str());
   return;
}
