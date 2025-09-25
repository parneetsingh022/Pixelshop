#include "panel_bordered.h"

PanelBordered::PanelBordered(wxWindow* parent,
                           wxWindowID id,
                           const wxPoint& pos,
                           const wxSize& size,
                           long style,
                           const wxString& name)
    : wxPanel(parent, id, pos, size, style, name)
{
    //SetBackgroundColour(wxColour(200, 200, 100));
    Bind(wxEVT_PAINT, &PanelBordered::PaintRightBorder, this);
}

void PanelBordered::setBorder(bool border, int size, int flags, wxColor color){
    this->border = border;
    this->borderSize = size;
    this->borderFlags = flags;
    this->borderColor = color;
}

void PanelBordered::PaintRightBorder(wxPaintEvent& event)
{
    if (!border) return;

    wxPaintDC dc(this);                 // or wxAutoBufferedPaintDC to avoid flicker
    const wxSize sz = GetClientSize();

    wxPen pen(this->borderColor, borderSize);
    pen.SetCap(wxCAP_BUTT);
    dc.SetPen(pen);

    const int o = (borderSize + 1) / 2; // ceil(borderSize/2)

    const int left   = o;
    const int right  = sz.x - o;
    const int top    = o;
    const int bottom = sz.y - o;

    // Left
    if (borderFlags & wxLEFT)
        dc.DrawLine(left,  0,    left,  sz.y);

    // Right
    if (borderFlags & wxRIGHT)
        dc.DrawLine(right, 0,    right, sz.y);

    // Top
    if (borderFlags & wxTOP)
        dc.DrawLine(0,  top,    sz.x, top);

    // Bottom
    if (borderFlags & wxBOTTOM)
        dc.DrawLine(0,  bottom, sz.x, bottom);
}