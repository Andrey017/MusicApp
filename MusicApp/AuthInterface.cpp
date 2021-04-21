#include "AuthForm.h"

using namespace System;

/*
* Для смены фона
*/
//Обработчик нажатия на ползунок для смены темы программы
System::Void MusicApp::AuthForm::panel_front_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	timer1->Start();
}

//Таймер для смены интерфейса
System::Void MusicApp::AuthForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (slide) {
		panel_front->Left += 5;

		if (panel_front->Left >= 33) {
			timer1->Stop();
			slide = false;
			panel_front->BackColor = Color::FromArgb(15, 19, 25);
			panel_back->BackColor = Color::FromArgb(255, 255, 255);
			this->BackColor = Color::FromArgb(15, 19, 25);
			panel_auth->BackColor = Color::FromArgb(15, 19, 25);
			gunaPanel_reg->BackColor = Color::FromArgb(15, 19, 25);

			panel_close_auth->BackColor = Color::FromArgb(15, 19, 25);
			panel_close_reg->BackColor = Color::FromArgb(15, 19, 25);

			guna2TextBox_auth_email->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_auth_email->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_auth_email->ForeColor = Color::White;

			guna2TextBox_auth_password->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_auth_password->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_auth_password->ForeColor = Color::White;

			guna2TextBox_reg_email->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_reg_email->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_reg_email->ForeColor = Color::White;

			guna2TextBox_reg_name->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_reg_name->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_reg_name->ForeColor = Color::White;

			guna2TextBox_reg_surname->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_reg_surname->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_reg_surname->ForeColor = Color::White;

			guna2TextBox_reg_pass->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_reg_pass->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_reg_pass->ForeColor = Color::White;

			guna2TextBox_reg_rep_pass->BackColor = Color::FromArgb(15, 19, 25);
			guna2TextBox_reg_rep_pass->FillColor = Color::FromArgb(31, 35, 41);
			guna2TextBox_reg_rep_pass->ForeColor = Color::White;

			gunaLabel1->BackColor = Color::FromArgb(15, 19, 25);
			gunaLabel2->BackColor = Color::FromArgb(15, 19, 25);

			gunaLabel_reg->BackColor = Color::FromArgb(15, 19, 25);

			PictureBox_Close->BackColor = Color::FromArgb(15, 19, 25);

			PictureBox__Auth_Dark->Visible = true;
			PictureBox_Auth_White->Visible = false;

			PictureBox_reg_back_blue->Load("./image/icons8_left_arrow_96px_white.png");
			PictureBox_Close->Load("./image/icons8_multiply_64px_white.png");
		}
	}
	else {
		panel_front->Left -= 5;

		if (panel_front->Left <= 3) {
			timer1->Stop();
			slide = true;
			panel_front->BackColor = Color::FromArgb(255, 255, 255);
			panel_back->BackColor = Color::FromArgb(15, 19, 25);
			this->BackColor = Color::FromArgb(255, 255, 255);
			panel_auth->BackColor = Color::FromArgb(255, 255, 255);
			gunaPanel_reg->BackColor = Color::FromArgb(255, 255, 255);

			panel_close_auth->BackColor = Color::FromArgb(255, 255, 255);
			panel_close_reg->BackColor = Color::FromArgb(255, 255, 255);

			guna2TextBox_auth_email->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_auth_email->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_auth_email->ForeColor = Color::Black;

			guna2TextBox_auth_password->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_auth_password->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_auth_password->ForeColor = Color::Black;

			guna2TextBox_reg_email->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_email->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_email->ForeColor = Color::Black;

			guna2TextBox_reg_name->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_name->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_name->ForeColor = Color::Black;

			guna2TextBox_reg_surname->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_surname->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_surname->ForeColor = Color::Black;

			guna2TextBox_reg_pass->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_pass->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_pass->ForeColor = Color::Black;

			guna2TextBox_reg_rep_pass->BackColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_rep_pass->FillColor = Color::FromArgb(255, 255, 255);
			guna2TextBox_reg_rep_pass->ForeColor = Color::Black;

			gunaLabel1->BackColor = Color::FromArgb(255, 255, 255);
			gunaLabel2->BackColor = Color::FromArgb(255, 255, 255);

			gunaLabel_reg->BackColor = Color::FromArgb(255, 255, 255);

			PictureBox_Close->BackColor = Color::FromArgb(255, 255, 255);

			PictureBox__Auth_Dark->Visible = false;
			PictureBox_Auth_White->Visible = true;

			PictureBox_reg_back_blue->Load("./image/icons8_left_arrow_96px_blue.png");
			PictureBox_Close->Load("./image/icons8_multiply_64px_black.png");
		}
	}
}

/*
* Для переходов в различные области
*/
//Переход в область регистрации
System::Void MusicApp::AuthForm::gunaLabel_reg_Click(System::Object^ sender, System::EventArgs^ e) {
	timer2->Start();
}

//Таймер для перехода в область регистрации
System::Void MusicApp::AuthForm::timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	panel_auth->Left -= 20;
	gunaPanel_reg->Left -= 20;

	if (panel_auth->Left <= 63 && gunaPanel_reg->Left <= 462) {
		timer2->Stop();
	}
}

//Кнопка для возвращения в область авторизации
System::Void MusicApp::AuthForm::PictureBox_reg_back_blue_Click(System::Object^ sender, System::EventArgs^ e) {
	timer3->Start();
}

//Таймер для перехода в область авторизации
System::Void MusicApp::AuthForm::timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
	panel_auth->Left += 20;
	gunaPanel_reg->Left += 20;

	if (panel_auth->Left >= 462 && gunaPanel_reg->Left >= 854) {
		timer3->Stop();
	}
}

/*
* Различные функции для корректной работы кнопки закрыть
*/
//Кнопка для завершения работы приложения
System::Void MusicApp::AuthForm::PictureBox_Close_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

//Обработчик для наведение на кнопку закрытия программы
System::Void MusicApp::AuthForm::PictureBox_Close_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	PictureBox_Close->BackColor = Color::Red;
}

//Обработчик, когда кнопка закрытия становиться не активной
System::Void MusicApp::AuthForm::PictureBox_Close_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	if (slide) {
		PictureBox_Close->BackColor = Color::White;
	}
	else {
		PictureBox_Close->BackColor = Color::FromArgb(15, 19, 25);
	}
}