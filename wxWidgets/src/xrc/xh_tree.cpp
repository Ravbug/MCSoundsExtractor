/////////////////////////////////////////////////////////////////////////////
// Name:        src/xrc/xh_tree.cpp
// Purpose:     XRC resource for wxTreeCtrl
// Author:      Brian Gavin
// Created:     2000/09/09
// Copyright:   (c) 2000 Brian Gavin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#if wxUSE_XRC && wxUSE_TREECTRL

#include "wx/xrc/xh_tree.h"
#include "wx/treectrl.h"

wxIMPLEMENT_DYNAMIC_CLASS(wxTreeCtrlXmlHandler, wxXmlResourceHandler);

wxTreeCtrlXmlHandler::wxTreeCtrlXmlHandler()
: wxXmlResourceHandler()
{
    XRC_ADD_STYLE(wxTR_EDIT_LABELS);
    XRC_ADD_STYLE(wxTR_NO_BUTTONS);
    XRC_ADD_STYLE(wxTR_HAS_BUTTONS);
    XRC_ADD_STYLE(wxTR_TWIST_BUTTONS);
    XRC_ADD_STYLE(wxTR_NO_LINES);
    XRC_ADD_STYLE(wxTR_FULL_ROW_HIGHLIGHT);
    XRC_ADD_STYLE(wxTR_LINES_AT_ROOT);
    XRC_ADD_STYLE(wxTR_HIDE_ROOT);
    XRC_ADD_STYLE(wxTR_ROW_LINES);
    XRC_ADD_STYLE(wxTR_HAS_VARIABLE_ROW_HEIGHT);
    XRC_ADD_STYLE(wxTR_SINGLE);
    XRC_ADD_STYLE(wxTR_MULTIPLE);
    XRC_ADD_STYLE(wxTR_DEFAULT_STYLE);
#if WXWIN_COMPATIBILITY_2_8
    XRC_ADD_STYLE(wxTR_EXTENDED);
#endif
    AddWindowStyles();
}

wxObject *wxTreeCtrlXmlHandler::DoCreateResource()
{
    XRC_MAKE_INSTANCE(tree, wxTreeCtrl)

    tree->Create(m_parentAsWindow,
                GetID(),
                GetPosition(), GetSize(),
                GetStyle(wxT("style"), wxTR_DEFAULT_STYLE),
                wxDefaultValidator,
                GetName());

    wxImageList *imagelist = GetImageList();
    if ( imagelist )
        tree->AssignImageList(imagelist);

    SetupWindow(tree);

    return tree;
}

bool wxTreeCtrlXmlHandler::CanHandle(wxXmlNode *node)
{
    return IsOfClass(node, wxT("wxTreeCtrl"));
}

#endif // wxUSE_XRC && wxUSE_TREECTRL
