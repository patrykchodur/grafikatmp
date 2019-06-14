///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1000,700 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	Panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	Panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer1->Add( Panel, 2, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer_Menu;
	bSizer_Menu = new wxBoxSizer( wxVERTICAL );
	
	button_load = new wxButton( this, wxID_ANY, wxT("Wczytaj bitmape"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_Menu->Add( button_load, 0, wxALIGN_CENTER|wxALL, 5 );
	
	label_wages_start = new wxStaticText( this, wxID_ANY, wxT("Wagi:"), wxDefaultPosition, wxDefaultSize, 0 );
	label_wages_start->Wrap( -1 );
	bSizer_Menu->Add( label_wages_start, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer_wagi;
	bSizer_wagi = new wxBoxSizer( wxHORIZONTAL );
	
	C1_text = new wxStaticText( this, wxID_ANY, wxT("C1:"), wxDefaultPosition, wxDefaultSize, 0 );
	C1_text->Wrap( -1 );
	bSizer_wagi->Add( C1_text, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	value_wage_1 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer_wagi->Add( value_wage_1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	C2_text = new wxStaticText( this, wxID_ANY, wxT("C2:"), wxDefaultPosition, wxDefaultSize, 0 );
	C2_text->Wrap( -1 );
	bSizer_wagi->Add( C2_text, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	value_wage_2 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer_wagi->Add( value_wage_2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	C3_text = new wxStaticText( this, wxID_ANY, wxT("C3:"), wxDefaultPosition, wxDefaultSize, 0 );
	C3_text->Wrap( -1 );
	bSizer_wagi->Add( C3_text, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	value_wage_3 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer_wagi->Add( value_wage_3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	C4_text = new wxStaticText( this, wxID_ANY, wxT("C4:"), wxDefaultPosition, wxDefaultSize, 0 );
	C4_text->Wrap( -1 );
	bSizer_wagi->Add( C4_text, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	value_wage_4 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer_wagi->Add( value_wage_4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer_Menu->Add( bSizer_wagi, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	label_angle = new wxStaticText( this, wxID_ANY, wxT("Kąt obrotu do obliczenia wag:"), wxDefaultPosition, wxDefaultSize, 0 );
	label_angle->Wrap( -1 );
	bSizer_Menu->Add( label_angle, 0, wxALIGN_CENTER|wxALL, 5 );
	
	value_angle_control = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_Menu->Add( value_angle_control, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer_rotation;
	bSizer_rotation = new wxBoxSizer( wxVERTICAL );
	
	button_wages = new wxButton( this, wxID_ANY, wxT("Oblicz wagi"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_rotation->Add( button_wages, 0, wxALIGN_CENTER|wxALL, 5 );
	
	button_rotation = new wxButton( this, wxID_ANY, wxT("Obróć \nz zadanymi wagami"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_rotation->Add( button_rotation, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer_Menu->Add( bSizer_rotation, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer_variation;
	bSizer_variation = new wxBoxSizer( wxHORIZONTAL );
	
	label_variation = new wxStaticText( this, wxID_ANY, wxT("Błąd: "), wxDefaultPosition, wxDefaultSize, 0 );
	label_variation->Wrap( -1 );
	bSizer_variation->Add( label_variation, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	value_variation = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	value_variation->Wrap( -1 );
	bSizer_variation->Add( value_variation, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	bSizer_Menu->Add( bSizer_variation, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer_wykres;
	bSizer_wykres = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	bSizer_wykres->Add( m_panel2, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer_Menu->Add( bSizer_wykres, 3, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer_Menu, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	Panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::Panel_Repaint ), NULL, this );
	button_load->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::click_button_load ), NULL, this );
	value_wage_1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_1_Update ), NULL, this );
	value_wage_2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_2_Update ), NULL, this );
	value_wage_3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_3_Update ), NULL, this );
	value_wage_4->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_4_Update ), NULL, this );
	value_angle_control->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Angle_Update ), NULL, this );
	button_wages->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Wages_Calculate ), NULL, this );
	button_rotation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Rotate_Bitmap ), NULL, this );
	m_panel2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::Graph_Paint ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	Panel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::Panel_Repaint ), NULL, this );
	button_load->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::click_button_load ), NULL, this );
	value_wage_1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_1_Update ), NULL, this );
	value_wage_2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_2_Update ), NULL, this );
	value_wage_3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_3_Update ), NULL, this );
	value_wage_4->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Wage_4_Update ), NULL, this );
	value_angle_control->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Angle_Update ), NULL, this );
	button_wages->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Wages_Calculate ), NULL, this );
	button_rotation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::Rotate_Bitmap ), NULL, this );
	m_panel2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::Graph_Paint ), NULL, this );
	
}
