#include <wx/wx.h>
#include "ui/sidebar.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnClick(wxCommandEvent&);

    wxDECLARE_EVENT_TABLE();
};


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
wxEND_EVENT_TABLE()

bool MyApp::OnInit()
{
     // Set the application appearance to dark mode on Windows
    #ifdef __WXMSW__
    SetAppearance(wxApp::Appearance::Dark);
    #endif


    MyFrame* frame = new MyFrame("Hello World", wxDefaultPosition, wxSize(800,600));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame (const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size){
    // wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200,100));
    // panel->SetBackgroundColour(wxColor(100,100,200));
    SidebarPanel* sidebarPanel = new SidebarPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250,-1));



    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(sidebarPanel, 0, wxEXPAND);

    

    this->SetSizer(sizer);
}


void MyFrame::OnClick(wxCommandEvent& e){
    std::cout << "Hey, button clicked. It's id = " << e.GetId() << std::endl;
}