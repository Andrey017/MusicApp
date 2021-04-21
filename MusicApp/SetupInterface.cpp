#include "HomeForm.h"

void MusicApp::HomeForm::SetupInterface() {
	this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	//Настройки меню и верхней панели
	panel_home_menu->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Panel1->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);

	button_home_menu_home->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	button_home_menu_home->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	button_home_menu_home->Image = Image::FromFile("./image/icons8_home_50px_white.png");

	guna2Button1->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Button1->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	guna2Button1->Image = Image::FromFile("./image/icons8_search_50px_white.png");

	guna2Button2->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Button2->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	guna2Button2->Image = Image::FromFile("./image/icons8_music_library_50px_white.png");

	guna2Button3->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Button3->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	guna2Button3->Image = Image::FromFile("./image/icons8_wechat_50px_white.png");

	guna2Button4->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Button4->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	guna2Button4->Image = Image::FromFile("./image/icons8_create_50px_white.png");

	guna2Button5->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Button5->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	guna2Button5->Image = Image::FromFile("./image/icons8_adjust_50px_white.png");

	guna2Button6->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	guna2Button6->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	guna2Button6->Image = Image::FromFile("./image/icons8_audio_wave2_50px_white.png");

	textBox_name_surname->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	textBox_name_surname->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	button_exit->FillColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	button_exit->Image = Image::FromFile("./image/icons8_exit_50px_white.png");

	//Настройки раздела Главная
	Panel_home_start_panel->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	label2->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	label2->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	label3->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	label3->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	guna2Panel3->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	panel_->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	label_nothing_1->ForeColor = Color::White;
	label_nothing_2->ForeColor = Color::White;

	//Настройка раздела Студия
	panel_home_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	panel_studio_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	panel_studio_conf->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	textBox_add_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	textBox_add_room->FillColor = Color::FromArgb(40, 40, 40);
	textBox_add_room->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	guna2ImageButton1->Image = Image::FromFile("./image/icons8_add_50px_white.png");

	panel_studio_users->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);

	label_conf_name_room->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
	label_conf_name_room->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	textBox_add_new_user_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	textBox_add_new_user_room->FillColor = Color::FromArgb(40, 40, 40);
	textBox_add_new_user_room->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	panel_list_user_rom->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);

	button_add_new_user->Image = Image::FromFile("./image/icons8_add_50px_white.png");
	button_conf_start_call->Image = Image::FromFile("./image/icons8_call_50px_white.png");
	button_conf_cancel_call->Image = Image::FromFile("./image/icons8_call_disconnected_50px_white.png");

	//Настройка раздела Библиотека
	flowLayoutPanel_library_item_audio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	
	button_load_list_music->FillColor = Color::FromArgb(94, 148, 255);
	button_load_list_music->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	button_load_list_way->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	button_load_list_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

	//Настройка медиаплеера
	panel_music->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	panel_music_controls->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	label_music_start_time->ForeColor = Color::White;
	label_music_total_time->ForeColor = Color::White;
	label_name_audio_play->ForeColor = Color::White;
	label_name_creator_audio_play->ForeColor = Color::White;

	guna2PictureBox1->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	guna2PictureBox1->Image = Image::FromFile("./image/icons8_rewind_100px_white.png");

	pictureBox_start_stop_music->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	pictureBox_start_stop_music->Image = Image::FromFile("./image/icons8_play_100px_white.png");

	pictureBox_music_stop->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	pictureBox_music_stop->Image = Image::FromFile("./image/icons8_stop_100px_white.png");

	pictureBox_audio_play->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

	trackBar_current_position->ThumbColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
}