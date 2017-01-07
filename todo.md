- Make the interface
	- Use GUIElements
	- Make it scale to the screen size

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
-- Finish before show and tell --
---------------------------------

- Create a circuits class
	- Similar to GUIElement for drawing
	- Can store properties, such as what type of component it is

- Create a wire class
	- Draws a line with SDL_RenderDrawLine
	- For connecting circuits together
	- Can only be straight


- Code a system to store created circuits and draw them
	- Store circuits using std::vector
	- Function to add a circuit to the std::vector
	- Function to go through and delete a circuit from the std::vector
