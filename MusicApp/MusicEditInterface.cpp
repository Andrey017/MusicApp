#include "MusicEditForm.h"

void MusicApp::MusicEditForm::SetupInterface() {
	this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	/*----------------------------------------------------------------------------------------------*/
	flowLayoutPanel_list_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	/*----------------------------------------------------------------------------------------------*/
	panel_controls->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	pictureBox_add_new_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	pictureBox_add_new_way->Image = Image::FromFile("./image/icons8_add_50px_white.png");

	pictureBox_save_music->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	pictureBox_save_music->Image = Image::FromFile("./image/icons8_save_50px_white.png");

	pictureBox_cut_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	pictureBox_cut_way->Image = Image::FromFile("./image/icons8_cut_50px_white.png");

	pictureBox_delete_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	pictureBox_delete_way->Image = Image::FromFile("./image/icons8_delete_bin_50px_white.png");

	panel_info_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	label_editor_name_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	label_editor_name_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	label_editor_name_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	label_editor_name_room->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	label_editor_time_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	label_editor_time_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	/*----------------------------------------------------------------------------------------------*/
	panel_way_editor->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	panel_linear_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	panel_editor_view->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	guna2TrackBar1->ThumbColor = Color::White;
}

void MusicApp::MusicEditForm::GenerationMap() {
	//Вертикальные полосы
	for (int i = 0; i < 360; i++) {
		PictureBox^ pic = gcnew PictureBox();

		pic->Location = Point(0 + i * 20, 75);
		pic->Size = Drawing::Size(1, 750);
		pic->BackColor = Color::FromArgb(17, 26, 33);

		panel_editor_view->Controls->Add(pic);
	}

	//Горизонтальные полосы
	for (int i = 0; i < 11; i++) {
		PictureBox^ pic = gcnew PictureBox();

		pic->Location = Point(0, 75 + i * 75);
		pic->Size = Drawing::Size(7181, 1);
		pic->BackColor = Color::Black;

		panel_editor_view->Controls->Add(pic);
	}
}

void MusicApp::MusicEditForm::GenerateMapLinear() {
	int min = 0;
	int value_sec = 0;

	for (int i = 0; i < 36; i++) {
		Label^ pic = gcnew Label();

		if (value_sec == 60) {
			min++;
			value_sec = 0;
		}

		if (value_sec == 0) {
			pic->Text = "0" + min + ":0" + value_sec;
		}
		else {
			pic->Text = "0" + min + ":" + value_sec;
		}

		pic->Location = Point(0 + i * 200, 38);
		pic->Size = Drawing::Size(50, 23);
		
		if (teme == "1") {
			pic->ForeColor = Color::White;
		}

		panel_editor_view->Controls->Add(pic);

		value_sec += 10;
	}
}

System::Void MusicApp::MusicEditForm::guna2TrackBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	int x = (Cursor->Position.X - 340) - Cursor->Position.X % 20;

	guna2Panel1->GetType()->GetProperty("Location")->SetValue(guna2Panel1, Point(x, 23));
}
