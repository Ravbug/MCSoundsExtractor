//
//  main.cpp
//  wxTest
//
//  Created by Main on 3/1/19.
//  Copyright © 2019 Ravbug. All rights reserved.
//

#include "interface.h"
#include "wx/wx.h"

class App: public wxApp
{
public:
    virtual bool OnInit();
};

//wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
//EVT_MENU(wxID_EXIT,  mainFrame::OnExit)
//EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
//wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(App);

//called when the application launches
bool App::OnInit()
{
    mainFrame *frame = new mainFrame( NULL );
    frame->Show( true );
    return true;
}

