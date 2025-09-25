#ifndef SIDEBARPANEL_H
#define SIDEBARPANEL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include "components/panel_bordered.h"


class SidebarPanel : public PanelBordered
{
public:
    SidebarPanel(wxWindow* parent, 
                 wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxTAB_TRAVERSAL,
                 const wxString& name = wxPanelNameStr);

};

#endif // SIDEBARPANEL_H
