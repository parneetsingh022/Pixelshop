#include "sidebar.h"
#include "../colors.h"

SidebarPanel::SidebarPanel(wxWindow* parent,
                           wxWindowID id,
                           const wxPoint& pos,
                           const wxSize& size,
                           long style,
                           const wxString& name)
    : PanelBordered(parent, id, pos, size, style, name)
{
    this->setBorder(true, 1, wxRIGHT, BORDER_COLOR);
    SetBackgroundColour(wxColour(200, 200, 100));
    
}
