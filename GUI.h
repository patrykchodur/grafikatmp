///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		wxPanel* Panel;
		wxButton* button_load;
		wxStaticText* label_wages_start;
		wxStaticText* C1_text;
		wxTextCtrl* value_wage_1;
		wxStaticText* C2_text;
		wxTextCtrl* value_wage_2;
		wxStaticText* C3_text;
		wxTextCtrl* value_wage_3;
		wxStaticText* C4_text;
		wxTextCtrl* value_wage_4;
		wxStaticText* label_angle;
		wxTextCtrl* value_angle_control;
		wxButton* button_wages;
		wxButton* button_rotation;
		wxStaticText* label_variation;
		wxStaticText* value_variation;
		wxPanel* m_panel2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void MainFormClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void Panel_Repaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void click_button_load( wxCommandEvent& event ) { event.Skip(); }
		virtual void Wage_1_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void Wage_2_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void Wage_3_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void Wage_4_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void Angle_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void Wages_Calculate( wxCommandEvent& event ) { event.Skip(); }
		virtual void Rotate_Bitmap( wxCommandEvent& event ) { event.Skip(); }
		virtual void Graph_Paint( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Projekt"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,689 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

#endif //__GUI_H__
