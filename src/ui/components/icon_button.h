#ifndef ICON_BUTTON_H
#define ICON_BUTTON_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/stdpaths.h>
#include "../../colors.h"

class IconButton : public wxPanel
{
public:
    IconButton(wxWindow* parent, 
                 wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxTAB_TRAVERSAL,
                 const wxString& name = wxPanelNameStr);

    int setImage(const wxString& svgPath);

private:
        void OnEnter(wxMouseEvent& e);
        void OnLeave(wxMouseEvent& e);
        void OnLeftDown(wxMouseEvent& e);
        void ApplyHoverStyles(bool on);

        wxBoxSizer* sizer;
        bool isHover{false};

        wxColor backgroundColor{BG_DARK};
        wxColor hoverBackgroundColor{BG_CARD};
};

#endif
