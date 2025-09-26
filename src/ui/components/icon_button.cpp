#include "icon_button.h"



IconButton::IconButton(wxWindow* parent, 
                 wxWindowID id,
                 const wxPoint& pos,
                 const wxSize& size,
                 long style,
                 const wxString& name)
                 : wxPanel(parent, id, pos, size, style, name){

    this->SetBackgroundColour(this->backgroundColor);

    this->sizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(sizer);

    this->Bind(wxEVT_ENTER_WINDOW, &IconButton::OnEnter, this);
    this->Bind(wxEVT_LEAVE_WINDOW, &IconButton::OnLeave, this);
    this->Bind(wxEVT_LEFT_DOWN, &IconButton::OnLeftDown, this);


}

int IconButton::setImage(const wxString& svgPath)
{
#if wxUSE_SVG
    const wxSize desiredSize(20, 20);                  // pick your logical icon size

    wxBitmapBundle bundle = wxBitmapBundle::FromSVGFile(svgPath, desiredSize);
    if (!bundle.IsOk()) {
        wxLogWarning("Failed to load SVG: %s", svgPath);
        return -1;
    }

    // wxStaticBitmap has a ctor that accepts wxBitmapBundle in modern wxWidgets.
    wxStaticBitmap* imgCtrl = new wxStaticBitmap(this, wxID_ANY, bundle);
    sizer->Add(imgCtrl, 1, wxALIGN_CENTER_VERTICAL);  // proportion 0 → no stretch
    Layout();

    // Forward hover/click events from the child
    imgCtrl->Bind(wxEVT_ENTER_WINDOW, &IconButton::OnEnter, this);
    imgCtrl->Bind(wxEVT_LEAVE_WINDOW, &IconButton::OnLeave, this);
    imgCtrl->Bind(wxEVT_LEFT_DOWN,    &IconButton::OnLeftDown, this);

    return 0;
#else
    wxLogError("SVG support not available in this wxWidgets build (wxUSE_SVG=0).");
    return -1;
#endif
}


bool IconButton::IsSelected(){
    return this->isSelected;
}

wxDEFINE_EVENT(wxEVT_SIDEBAR_TOOL_SELECTED, wxCommandEvent);

void IconButton::SetSelected(bool selected) {
    
    isSelected = selected;
    SetBackgroundColour(selected ? selectedBackgroundColor : backgroundColor);
    Refresh();
    Update();
}

void IconButton::ApplyHoverStyles(bool on){
    if(this->isSelected) return;
    this->isHover = on;

    SetBackgroundColour(on ? this->hoverBackgroundColor : this->backgroundColor);

    Refresh();
    Update();
}

void IconButton::OnEnter(wxMouseEvent& e){
    SetCursor(wxCURSOR_HAND);
    ApplyHoverStyles(true);
    e.Skip();
}

void IconButton::OnLeave(wxMouseEvent& e){
    const wxPoint screenPt = wxGetMousePosition();
    if (!GetScreenRect().Contains(screenPt)) {
        SetCursor(wxCURSOR_ARROW);
        ApplyHoverStyles(false);
    }
    e.Skip();
}

void IconButton::OnLeftDown(wxMouseEvent& e){
    wxCommandEvent evt(wxEVT_SIDEBAR_TOOL_SELECTED, GetId());
    evt.SetEventObject(this);
    GetParent()->GetEventHandler()->ProcessEvent(evt);

    this->SetSelected(true);

    e.Skip();
}