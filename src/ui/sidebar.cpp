#include "sidebar.h"


#define SIDEBAR_TOOL_SIZE wxSize(25,25)

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
        IconButton* icon = new IconButton(this, wxID_ANY, wxDefaultPosition, SIDEBAR_TOOL_SIZE);
        int status = icon->setImage(item.iconPath);

        // if there is an error loading the image
        if (status != 0) {
            loadedAll = false;
            wxLogWarning("Failed to load icon: %s", item.iconPath);
            continue;
        }
        
        icon->LinkButtons(addedTools);
        sizer->Add(icon, 0, wxALL, 2);
       
        this->addedTools.push_back(icon);
    }

    if(!loadedAll) wxLogError("Failed to load some sidebar tool icons!");
}