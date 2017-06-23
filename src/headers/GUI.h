#ifndef GUI_H
#define GUI_H

#define PROTOTYPING "data/Prototyping.png"
#define TEX_DROPDOWN_MENU "data/DropdownMenu.png"
#define TEX_ARROWLEFT "data/ARROW-Left.png"
#define TEX_ARROWRIGHT "data/ARROW-Right.png"
#define TEX_DROPDOWN_BG "data/DropdownBackground.png"
#define TEX_GRAY_BG "data/GrayBackground.png"
#define TEX_PICKER_PANEL "data/CircuitPickerPanel.png"
#define TEX_CHECKBOX_CHECKED "data/CheckboxChecked.png"
#define TEX_DROPDOWN_BOX "data/DropdownBox.png"
#define TEX_PPANEL "data/PropertiesPanel.png"
#define TEX_GRID "data/Grid.png"
#define TEX_IC "data/IC-1.png"

#include "types/GUIElement.h"

enum ToolType
{
   SELECTED,
    WIRE,
    BATTERY,
    RESISTOR,
    CAPACITOR,
    IC,
    NONE
};

void InitGUI();
void UpdateGUI();
void DrawGUI();

#endif
