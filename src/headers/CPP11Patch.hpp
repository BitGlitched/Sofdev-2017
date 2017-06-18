#ifndef CPP11PATCH_HPP
#define CPP11PATCH_HPP

#include <fstream>
#include <string>
#include <sstream>

namespace Patch
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

   int stoi(std::string str)
   {
      std::stringstream ss;
      int i;

      ss << str; // sends the contents of str to the stringstream ss
      ss >> i; // extracts the contents of the stringstream, converts to a float (if a valid conversion is possible) and assigns the result (if possible) to fl
      ss.clear(); // clears any error and eof flags so the stringstream can be used again after it has reached eof (or some error)
                  // (the eof flag is set each time you extract all of its contents with >>)
      return (int)i; // stores an empty string in the stringstream -- you may or may not need this depending on the rest of your program.
   }

   float stof(std::string str)
   {
      std::stringstream ss;
      double fl;

      ss << str; // sends the contents of str to the stringstream ss
      ss >> fl; // extracts the contents of the stringstream, converts to a float (if a valid conversion is possible) and assigns the result (if possible) to fl
      ss.clear(); // clears any error and eof flags so the stringstream can be used again after it has reached eof (or some error)
                  // (the eof flag is set each time you extract all of its contents with >>)
      return (float)fl; // stores an empty string in the stringstream -- you may or may not need this depending on the rest of your program.
   }

   double stod(std::string str)
   {
      std::stringstream ss;
      double fl;

      ss << str; // sends the contents of str to the stringstream ss
      ss >> fl; // extracts the contents of the stringstream, converts to a float (if a valid conversion is possible) and assigns the result (if possible) to fl
      ss.clear(); // clears any error and eof flags so the stringstream can be used again after it has reached eof (or some error)
                  // (the eof flag is set each time you extract all of its contents with >>)
      return (double)fl; // stores an empty string in the stringstream -- you may or may not need this depending on the rest of your program.
   }
}

#endif
