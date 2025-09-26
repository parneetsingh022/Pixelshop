#include "sidebar.h"
#include "../ToolSpec.h"

SidebarPanel::SidebarPanel(wxWindow* parent,
                           wxWindowID id,
                           const wxPoint& pos,
                           const wxSize& size,
                           long style,
                           const wxString& name)
    : PanelBordered(parent, id, pos, size, style, name)
{
    this->setBorder(true, 1, wxRIGHT, BORDER_DEFAULT);
    SetBackgroundColour(BG_DARK);


    // Main Vertical Layout
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    this->DisplayTools(sizer);


    this->SetSizer(sizer);
}


void SidebarPanel::DisplayTools(wxBoxSizer* sizer){
    bool loadedAll = true;
    for(ToolSpec item : sideBarTools){
        wxBitmap bmp(
            item.iconPath,
            wxBITMAP_TYPE_PNG
        );

        if (!bmp.IsOk()) {
            loadedAll = false;
            wxLogWarning("Failed to load icon: %s", item.iconPath);
            continue;
        }
        auto* imgCtrl = new wxStaticBitmap(this, wxID_ANY, bmp);
        sizer->Add(imgCtrl, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    }

    if(!loadedAll) wxLogError("Failed to load some sidebar tool icons!");
}
