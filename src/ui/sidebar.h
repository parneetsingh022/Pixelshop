#ifndef SIDEBARPANEL_H
#define SIDEBARPANEL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/stdpaths.h>

#include <vector>

#include "components/panel_bordered.h"
#include "../colors.h"
#include "../ToolSpec.h"
#include "components/icon_button.h"


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
    IconButton* selectedButton{nullptr};

};

#endif // SIDEBARPANEL_H
