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
#define TEX_RESISTOR "data/Resistor.png"
#define TEX_CAPACITOR "data/Capacitor.png"
#define TEX_SWITCHOPEN "data/Switch-Open.png"
#define TEX_SWITCHCLOSED "data/Switch-Closed.png"
#define TEX_BATTERY "data/Battery.png"
#define TEX_LIGHTBULB "data/Light Bulb.png"
#define TEX_WIRESTRAIGHT "data/Wire.png"
#define TEX_WIREBEND "data/Wire2way.png"
#define TEX_WIRETHREEWAY "data/Wire3way.png"
#define TEX_HIGHLIGHT "data/Border.png"

#include "types/GUIElement.h"

enum ToolType
{
   SELECTED,
   WIRESTRAIGHT,
   WIREBEND,
   WIRETHREEWAY,
    SWITCHOPEN,
    SWITCHCLOSED,
    BATTERY,
    RESISTOR,
    CAPACITOR,
    IC,
    LIGHTBULB,
    NONE
};

extern Texture texWireBend;
extern Texture texWireStraight;
extern Texture texWireThreeWay;

void InitGUI();
void UpdateGUI();
void DrawGUI();

#endif
