#include "SaveAudioForm.h"

using namespace System;

void MusicApp::SaveAudioForm::SetupInterface() {
	if (teme == "1") {
		this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		PictureBox_Close->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		PictureBox_Close->Image = Image::FromFile("./image/icons8_multiply_64px_white.png");

		//-----------------------------------------------------//
		panel_main->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		panel_main_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label_main_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		label_main_create_studio->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		pictureBox_main_create_studio->Image = Image::FromFile("./image/Add_Create_Studio_black.png");

		panel_main_join_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label1->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		label_main_join_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		label_main_join_studio->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		pictureBox_main_join_studio->Image = Image::FromFile("./image/Invite_Create_Studio_black.png");

		//-----------------------------------------------------//
		panel_save_music->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		guna2Panel2->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		pictureBox_music_Back->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label5->ForeColor = Color::White;
		label4->ForeColor = Color::White;

		textBox_save_name_music->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_save_name_music->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_save_name_music->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		textBox_save_creators_music->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_save_creators_music->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_save_creators_music->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		pictureBox_save_music_avatar->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		pictureBox_save_music_avatar->Image = Image::FromFile("./image/icons8_add_127px_white.png");

		//-----------------------------------------------------//
		panel_way_wave->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		guna2Panel_join_join->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		guna2PictureBox_save_way_back->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label3->ForeColor = Color::White;
		label2->ForeColor = Color::White;

		//textBox_save_audio_way
		textBox_save_audio_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_save_audio_way->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_save_audio_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		//-----------------------------------------------------//
		panel_settings->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		guna2Panel3->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		
		label7->ForeColor = Color::White;
		label6->ForeColor = Color::White;

		radioButton_one->ForeColor = Color::White;
		radioButton_more->ForeColor = Color::White;

		label8->ForeColor = Color::White;
		label9->ForeColor = Color::White;
		label10->ForeColor = Color::White;
		label11->ForeColor = Color::White;

		pictureBox_back_settings->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		comboBox_sam_freq->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		comboBox_sam_freq->ForeColor = Color::White;

		comboBox_bit->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		comboBox_bit->ForeColor = Color::White;

		comboBox_count_chanel->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		comboBox_count_chanel->ForeColor = Color::White;

		comboBox_thres->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		comboBox_thres->ForeColor = Color::White;
	}
}

System::Void MusicApp::SaveAudioForm::PictureBox_Close_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}

System::Void MusicApp::SaveAudioForm::PictureBox_Close_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	PictureBox_Close->BackColor = Color::Red;
}

System::Void MusicApp::SaveAudioForm::PictureBox_Close_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	if (teme == "1") {
		PictureBox_Close->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	}
	else {
		PictureBox_Close->BackColor = Color::White;
	}
}

System::Void MusicApp::SaveAudioForm::button_main_music_way_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 950;
	panel_main->Visible = false;

	panel_way_wave->Left = 12;
	panel_way_wave->Visible = true;
}

System::Void MusicApp::SaveAudioForm::guna2PictureBox_save_way_back_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 12;
	panel_main->Visible = true;

	panel_way_wave->Left = 950;
	panel_way_wave->Visible = false;
}

System::Void MusicApp::SaveAudioForm::button_save_audio_way_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_save_audio_way->Text != "") {
		name_audio = textBox_save_audio_way->Text;
		check_value = 2;

		//Close();

		mus_or_way = 2;

		panel_settings->Left = 12;
		panel_settings->Top = 12;
		panel_settings->Visible = true;

		panel_way_wave->Left = 950;
		panel_way_wave->Visible = false;
	}
	else {
		MessageBox::Show("Введите название");
	}
}

System::Void MusicApp::SaveAudioForm::pictureBox_music_Back_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 12;
	panel_main->Visible = true;

	panel_save_music->Top = 500;
	panel_save_music->Visible = false;
}

System::Void MusicApp::SaveAudioForm::button_main_create_music_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 950;
	panel_main->Visible = false;

	panel_save_music->Top = 12;
	panel_save_music->Visible = true;
}

System::Void MusicApp::SaveAudioForm::button_save_music_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox_save_name_music->Text != "" || textBox_save_creators_music->Text != "") {
		name_audio = textBox_save_name_music->Text;
		creators = textBox_save_creators_music->Text;
		access = checkBox_acess_all_user->Checked;
		check_value = 1;

		//Close();

		mus_or_way = 1;

		panel_settings->Left = 12;
		panel_settings->Top = 12;
		panel_settings->Visible = true;

		panel_save_music->Top = 500;
		panel_save_music->Visible = false;
	}
	else {
		MessageBox::Show("Заполните все поля");
	}
}

System::Void MusicApp::SaveAudioForm::pictureBox_save_music_avatar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog_music_ava->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		path_file = openFileDialog_music_ava->FileName;

		pictureBox_save_music_avatar->Image = Image::FromFile(path_file);
	}
}

System::Void MusicApp::SaveAudioForm::pictureBox_back_settings_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_settings->Left = 950;
	panel_settings->Top = 500;
	panel_settings->Visible = false;

	if (mus_or_way == 1) {
		panel_save_music->Top = 12;
		panel_save_music->Visible = true;
	}
	else if (mus_or_way == 2) {
		panel_way_wave->Left = 12;
		panel_way_wave->Visible = true;
	}
}

System::Void MusicApp::SaveAudioForm::radioButton_one_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	radioButton_more->Checked = false;
	change_one_or_more = 1;
}

System::Void MusicApp::SaveAudioForm::radioButton_more_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	radioButton_one->Checked = false;
	change_one_or_more = 2;
}

System::Void MusicApp::SaveAudioForm::button_save_settings_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox_sam_freq->Text != "" && comboBox_bit->Text != "" && comboBox_count_chanel->Text != "" && comboBox_thres->Text != "") {
		sett_sam_freq = comboBox_sam_freq->Text;
		sett_bit = comboBox_bit->Text;
		sett_count_chanel = comboBox_count_chanel->Text;
		sett_thres = comboBox_thres->Text;

		Close();
	}
	else {
		MessageBox::Show("Заполните все поля");
	}
}