#ifndef SIDEBARPANEL_H
#define SIDEBARPANEL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/stdpaths.h>

#include "components/panel_bordered.h"
#include "../colors.h"



class SidebarPanel : public PanelBordered
{
public:
    SidebarPanel(wxWindow* parent, 
                 wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxTAB_TRAVERSAL,
                 const wxString& name = wxPanelNameStr);
private:
    void DisplayTools(wxBoxSizer* sizer);

};

#endif // SIDEBARPANEL_H
