#include "GUIMyFrame1.h"
#include "minimalize.hpp"
#include "rotate.hpp"
#include "graph.hpp"

#include <string>
#include <wx/log.h>


// for wxGraphicContext
// #include <wx/graphics.h>

static constexpr int depth = 3;

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	wxInitAllImageHandlers();
	m_file_dialog = std::make_shared<wxFileDialog>(this, _("Choose a file"), _(""), _(""), _("."), wxFD_OPEN);

}

void GUIMyFrame1::MainFormClose(wxCloseEvent& event)
{
	this->Destroy();
}

void GUIMyFrame1::repaint() {
	if (image.image.IsOk() == false)
		return;

	wxClientDC dc(Panel);
	dc.Clear();

	auto bitmap = wxBitmap(image.image, depth);
	dc.DrawBitmap(bitmap, 0, 0);


	// image.image.SaveFile("test.png", wxBITMAP_TYPE_PNG);
}

void GUIMyFrame1::repaint_graph() {
	if (graph.IsOk() == false)
		return;

	wxClientDC dc(m_panel2);
	dc.Clear();

	auto bitmap = wxBitmap(graph, depth);
	dc.DrawBitmap(bitmap, 0, 0);
}

void GUIMyFrame1::Panel_Repaint(wxUpdateUIEvent& event)
{
	//repaint();
}

void GUIMyFrame1::click_button_load(wxCommandEvent& event)
{
	// FIXME: 
	// temporarly loading fixed photo

	wxString filename;
	m_file_dialog->SetWildcard("BMP files (*.bmp)|*.bmp");
	if (m_file_dialog->ShowModal() == wxID_OK) {
		filename = m_file_dialog->GetPath();

		wxImage tmpimg;

		tmpimg.LoadFile(filename, wxBITMAP_TYPE_BMP);
		image = tmpimg;
		
	}

	repaint();
}

void GUIMyFrame1::Wage_1_Update(wxCommandEvent& event)
{

}

void GUIMyFrame1::Wage_2_Update(wxCommandEvent& event)
{

}

void GUIMyFrame1::Wage_3_Update(wxCommandEvent& event)
{

}

void GUIMyFrame1::Wage_4_Update(wxCommandEvent& event)
{

}

void GUIMyFrame1::Angle_Update(wxCommandEvent& event)
{

}

void GUIMyFrame1::Wages_Calculate(wxCommandEvent& event)
{
	auto angle_value = std::stof(value_angle_control->GetLineText(0).ToStdString());

	auto angle = AngleDeg(angle_value);


	auto result = minimalize(image, angle);
	auto factrs = result.first;
	auto error_vec = result.second;

	graph = draw_graph(error_vec, m_panel2->GetSize());

	auto text1 = std::to_string(factrs[0]);
	auto text2 = std::to_string(factrs[1]);
	auto text3 = std::to_string(factrs[2]);
	auto text4 = std::to_string(factrs[3]);

	value_wage_1->SetValue(text1);
	value_wage_2->SetValue(text2);
	value_wage_3->SetValue(text3);
	value_wage_4->SetValue(text4);

	value_variation->SetLabel(std::to_string(*error_vec.rbegin()));

	repaint_graph();
}

void GUIMyFrame1::Rotate_Bitmap(wxCommandEvent& event)
{
	auto value1 = std::stof(value_wage_1->GetLineText(0).ToStdString());
	auto value2 = std::stof(value_wage_2->GetLineText(0).ToStdString());
	auto value3 = std::stof(value_wage_3->GetLineText(0).ToStdString());
	auto value4 = std::stof(value_wage_4->GetLineText(0).ToStdString());

	auto factrs = Factors(value1, value2, value3, value4);


	auto angle_value = std::stof(value_angle_control->GetLineText(0).ToStdString());

	auto angle = AngleDeg(angle_value);


	image = rotate(image, angle, factrs);


	repaint();

}

void GUIMyFrame1::Graph_Paint(wxUpdateUIEvent& event)
{

}

void GUIMyFrame1::Variation_Update()
{

}
