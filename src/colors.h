#pragma once
#include <wx/wx.h>

// ----------------------------
// Background Layers
// ----------------------------
#define BG_BASE        wxColor(59, 59, 59)   // Main background
#define BG_DARK        wxColor(45, 45, 45)   // Side panels, secondary areas
#define BG_LIGHT       wxColor(70, 70, 70)   // Toolbars, headers
#define BG_CARD        wxColor(75, 75, 75)   // Cards, grouped content
#define BG_INPUT       wxColor(66, 66, 66)   // Input fields
#define BG_POPUP       wxColor(50, 50, 50)   // Menus, dropdowns
#define BG_OVERLAY     wxColor(30, 30, 30, 200) // Modal overlay (semi-transparent)

// ----------------------------
// Borders & Dividers
// ----------------------------
#define BORDER_DEFAULT wxColor(173, 173, 173)
#define BORDER_SUBTLE  wxColor(90, 90, 90)
#define DIVIDER_COLOR  wxColor(80, 80, 80)

// ----------------------------
// Text
// ----------------------------
#define TEXT_PRIMARY   wxColor(230, 230, 230) // High contrast
#define TEXT_SECONDARY wxColor(180, 180, 180) // Labels, hints
#define TEXT_DISABLED  wxColor(120, 120, 120)

// ----------------------------
// Accents & Interactive
// ----------------------------
#define ACCENT_COLOR   wxColor(0, 122, 204)   // Primary accent (blue)
#define HOVER_COLOR    wxColor(80, 80, 80)    // Hover background
#define ACTIVE_COLOR   wxColor(100, 100, 100) // Active/pressed
#define FOCUS_COLOR    wxColor(0, 150, 255)   // Focus ring

// ----------------------------
// Feedback States
// ----------------------------
#define SUCCESS_COLOR  wxColor(76, 175, 80)
#define WARNING_COLOR  wxColor(255, 193, 7)
#define ERROR_COLOR    wxColor(204, 51, 51)
#define INFO_COLOR     wxColor(41, 128, 185)
