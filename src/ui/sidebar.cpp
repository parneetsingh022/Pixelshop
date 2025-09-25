#include "sidebar.h"

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
    
    wxBitmap bmp(
        "../resources/sidebar_icons/arrow_selector_tool.png",
        wxBITMAP_TYPE_PNG
    );

    if(!bmp.IsOk()){
        wxLogError("Failed to load image.");
    }

    // Main Vertical Layout
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* imgCtrl = new wxStaticBitmap(this, wxID_ANY, bmp);
    sizer->Add(imgCtrl, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


    this->SetSizer(sizer);
}
