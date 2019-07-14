//
//  main.cpp
//  wxTest
//
//  Created by Main on 3/1/19.
//  Copyright © 2019 Ravbug. All rights reserved.
//

#include "wx/wx.h"
#include "interface.h"

//include the icon file on linux
#ifdef __linux
#include "wxlin.xpm"
#endif


class App: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(App);

//called when the application launches
bool App::OnInit()
{
    mainFrame *frame = new mainFrame( NULL );
	//set the icon
#ifdef _WIN32
	//name is the same as the one used in the resource file definition
	frame->SetIcon(wxIcon("IDI_WXWIN"));
#elif __linux
	frame->SetIcon(wxIcon(wxICON(wxlin)));
#endif 

    frame->Show( true );
    return true;
}
