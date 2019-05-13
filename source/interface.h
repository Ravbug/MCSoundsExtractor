///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include "wx/artprov.h"
#include "wx/xrc/xmlres.h"
#include "wx/string.h"
#include "wx/stattext.h"
#include "wx/gdicmn.h"
#include "wx/font.h"
#include "wx/colour.h"
#include "wx/settings.h"
#include "wx/textctrl.h"
#include "wx/bitmap.h"
#include "wx/image.h"
#include "wx/icon.h"
#include "wx/button.h"
#include "wx/choice.h"
#include "wx/gauge.h"
#include "wx/gbsizer.h"
#include "wx/frame.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class mainFrame
///////////////////////////////////////////////////////////////////////////////
enum{
    ID_App=1
};
class mainFrame : public wxFrame
{
	private:
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        wxDECLARE_EVENT_TABLE();
	protected:
		wxStaticText* label_1;
		wxTextCtrl* txt_mcDir;
		wxButton* btn_chooseMcDir;
		wxStaticText* label_2;
		wxTextCtrl* txt_outDir;
		wxButton* btn_chooseOutDir;
		wxStaticText* label_3;
		wxChoice* choice_mcVersion;
		wxButton* btn_extract;
		wxGauge* progressBar;

	public:

		mainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Minecraft Sounds Extractor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,250 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~mainFrame();

};
