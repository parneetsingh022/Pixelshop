#ifndef PANEL_BORDERED_H
#define PANEL_BORDERED_H

#include <wx/wx.h>
#include <wx/panel.h>


class PanelBordered : public wxPanel
{
public:
    PanelBordered(wxWindow* parent, 
                 wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxTAB_TRAVERSAL,
                 const wxString& name = wxPanelNameStr);
    void setBorder(bool border, int size = 1, int flags=wxALL, wxColor color = *wxBLACK);
    void PaintRightBorder(wxPaintEvent& event);
private:
        bool border = false;
        int borderSize = 0;
        int borderFlags = wxALL;
        wxColor borderColor = *wxBLACK;
};

#endif
