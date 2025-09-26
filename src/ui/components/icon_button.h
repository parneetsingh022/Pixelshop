#ifndef ICON_BUTTON_H
#define ICON_BUTTON_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/stdpaths.h>
#include <vector>

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
    void SetSelected(bool selected, bool lookForLinkedButtons=true);
    bool IsSelected();
    void LinkButtons(std::vector<IconButton*>& buttons);

private:
        void OnEnter(wxMouseEvent& e);
        void OnLeave(wxMouseEvent& e);
        void OnLeftDown(wxMouseEvent& e);
        void ApplyHoverStyles(bool on);
        

        wxBoxSizer* sizer;
        bool isHover{false};
        bool isSelected{false};

        wxColor backgroundColor{BG_DARK};
        wxColor hoverBackgroundColor{BG_CARD};
        wxColor selectedBackgroundColor{BG_LIGHT};
        std::vector<IconButton*>* linkedButtons;
};

#endif
