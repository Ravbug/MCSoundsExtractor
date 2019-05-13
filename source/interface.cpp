///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "interface.h"

///////////////////////////////////////////////////////////////////////////

mainFrame::mainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,250 ), wxSize( -1,250 ) );

	wxGridBagSizer* gb_main;
	gb_main = new wxGridBagSizer( 0, 0 );
	gb_main->SetFlexibleDirection( wxHORIZONTAL );
	gb_main->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	label_1 = new wxStaticText( this, wxID_ANY, wxT("Minecraft Folder"), wxDefaultPosition, wxDefaultSize, 0 );
	label_1->Wrap( -1 );
	gb_main->Add( label_1, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	txt_mcDir = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gb_main->Add( txt_mcDir, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );

	btn_chooseMcDir = new wxButton( this, wxID_ANY, wxT("Choose"), wxDefaultPosition, wxDefaultSize, 0 );
	gb_main->Add( btn_chooseMcDir, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	label_2 = new wxStaticText( this, wxID_ANY, wxT("Output Folder"), wxDefaultPosition, wxDefaultSize, 0 );
	label_2->Wrap( -1 );
	gb_main->Add( label_2, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	txt_outDir = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gb_main->Add( txt_outDir, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );

	btn_chooseOutDir = new wxButton( this, wxID_ANY, wxT("Choose"), wxDefaultPosition, wxDefaultSize, 0 );
	gb_main->Add( btn_chooseOutDir, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	label_3 = new wxStaticText( this, wxID_ANY, wxT("Minecraft Version"), wxDefaultPosition, wxDefaultSize, 0 );
	label_3->Wrap( -1 );
	gb_main->Add( label_3, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	wxArrayString choice_mcVersionChoices;
	choice_mcVersion = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choice_mcVersionChoices, 0 );
	choice_mcVersion->SetSelection( 0 );
	gb_main->Add( choice_mcVersion, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );

	btn_extract = new wxButton( this, wxID_ANY, wxT("Extract"), wxDefaultPosition, wxDefaultSize, 0 );
	gb_main->Add( btn_extract, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	progressBar = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	progressBar->SetValue( 0 );
	gb_main->Add( progressBar, wxGBPosition( 6, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );


	gb_main->AddGrowableCol( 0 );

	this->SetSizer( gb_main );
	this->Layout();

	this->Centre( wxBOTH );
}

mainFrame::~mainFrame()
{
}
