//
//  main.cpp
//  wxTest
//
//  Created by Main on 3/1/19.
//  Copyright © 2019 Ravbug. All rights reserved.
//

#include "wx/wx.h"
#include "interface.h"

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
    frame->Show( true );
    return true;
}
