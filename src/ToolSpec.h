// ToolSpec.h
#pragma once
#include <wx/string.h>
#include <vector>

enum class ToolCategory {
    Cursor,
    Draw,
    Shapes,
    Edit
};

struct ToolSpec {
    wxString id;        // stable identifier: "arrow", "brush", ...
    wxString name;      // user-visible
    wxString iconPath;  // relative to your resources dir
    ToolCategory cat;
};

inline const std::vector<ToolSpec> sideBarTools = {
    { "arrow",     "Arrow",     "../resources/sidebar_icons/arrow_selector_tool.svg", ToolCategory::Cursor },
    { "drag pan",     "Drag Pan",     "../resources/sidebar_icons/drag_pan_tool.svg", ToolCategory::Cursor },
    
};