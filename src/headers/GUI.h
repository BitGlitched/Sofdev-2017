#ifndef GUI_H
#define GUI_H

#define PROTOTYPING "data/Prototyping.png"
#define TEX_DROPDOWN_MENU "data/DropdownMenu.png"
#define TEX_ARROW "data/ARROW.png"
#define TEX_DROPDOWN_BG "data/DropdownBackground.png"
#define TEX_GRAY_BG "data/GrayBackground.png"
#define TEX_PICKER_PANEL "data/CircuitPickerPanel.png"
#define TEX_CHECKBOX_CHECKED "data/CheckboxChecked.png"
#define TEX_DROPDOWN_BOX "data/DropdownBox.png"
#define TEX_PPANEL "data/PropertiesPanel.png"
#define TEX_IC "data/IC.png"

#include "types/GUIElement.h"

void InitGUI();
void UpdateGUI();
void DrawGUI();

#endif
