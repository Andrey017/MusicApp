#include "CreateRoomForm.h"
#include <time.h>

void MusicApp::CreateRoomForm::SetupInterface() {
	if (teme == "1") {
		this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		PictureBox_Close->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		PictureBox_Close->Image = Image::FromFile("./image/icons8_multiply_64px_white.png");

		//-------------------------------------------------------------//
		panel_main->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label1->ForeColor = Color::White;

		panel_main_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		panel_main_join_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label_main_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		label_main_create_studio->ForeColor = Color::White;

		label_main_join_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		label_main_join_studio->ForeColor = Color::White;

		pictureBox_main_create_studio->Image = Image::FromFile("./image/Add_Create_Studio_black.png");
		pictureBox_main_join_studio->Image = Image::FromFile("./image/Invite_Create_Studio_black.png");

		//-------------------------------------------------------------//
		panel_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		panel_in_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label_create_studio->ForeColor = Color::White;
		label_create_studio_info->ForeColor = Color::White;

		textBox_name_create_studio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_name_create_studio->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
		textBox_name_create_studio->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		pictureBox_create_studio_avatar->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		PictureBox_back_blue->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		pictureBox_create_studio_avatar->Image = Image::FromFile("./image/icons8_add_127px_white.png");

		//-------------------------------------------------------------//
		panel_join_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		guna2Panel_join_join->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label3->ForeColor = Color::White;
		label2->ForeColor = Color::White;

		textBox_join_invite->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		textBox_join_invite->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
		textBox_join_invite->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		guna2PictureBox_join_back->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	}
}

System::Void MusicApp::CreateRoomForm::PictureBox_Close_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

System::Void MusicApp::CreateRoomForm::PictureBox_Close_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	PictureBox_Close->BackColor = Color::Red;
}

System::Void MusicApp::CreateRoomForm::PictureBox_Close_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	if (teme == "1") {
		PictureBox_Close->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
	}
	else {
		PictureBox_Close->BackColor = Color::White;
	}
}

System::Void MusicApp::CreateRoomForm::PictureBox_back_blue_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 12;
	panel_main->Visible = true;

	panel_create_studio->Left = 950;
	panel_create_studio->Visible = false;
}

System::Void MusicApp::CreateRoomForm::button_main_create_studio_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 950;
	panel_main->Visible = false;

	panel_create_studio->Left = 12;
	panel_create_studio->Visible = true;
}

System::Void MusicApp::CreateRoomForm::button_main_join_studio_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 950;
	panel_main->Visible = false;

	panel_join_room->Top = 12;
	panel_join_room->Visible = true;
}

System::Void MusicApp::CreateRoomForm::guna2PictureBox_join_back_Click(System::Object^ sender, System::EventArgs^ e) {
	panel_main->Left = 12;
	panel_main->Visible = true;

	panel_join_room->Top = 500;
	panel_join_room->Visible = false;
}

System::Void MusicApp::CreateRoomForm::button_create_studio_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ link = "http://" + ip + ":8011/upload?folderNameMu=picture";

	String^ name_room = textBox_name_create_studio->Text;
	String^ fileName = Path::GetFileName(path_file);

	AddNewRoom(name_room, fileName);

	LoadAvatarRoom(link, path_file);

	Close();
}

System::Void MusicApp::CreateRoomForm::pictureBox_create_studio_avatar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog_add_picture->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		path_file = openFileDialog_add_picture->FileName;

		pictureBox_create_studio_avatar->Image = Image::FromFile(path_file);
	}
}

void MusicApp::CreateRoomForm::AddNewRoom(String^ name_room, String^ fileName) {
	int id_room = 0;

	if (name_room != "") {

		String^ link = "http://" + ip + ":8011/create_room?user_id=" + user_id + "&name_room=" + name_room + "&path_picture=" + fileName;

		NetFunction^ netFunction = gcnew NetFunction();

		String^ resultRequest = netFunction->createRequest(link);

		id_room = Convert::ToInt32(resultRequest);
	}
	else {
		MessageBox::Show("Введите имя комнаты");
	}
}

void MusicApp::CreateRoomForm::LoadAvatarRoom(String^ uri, String^ filePath) {
	String^ formdataTemplate = "Content-Disposition: form-data; name=\"filedata\"; filename=\"{0}\";\r\nContent-Type: image/png\r\n\r\n";

	time_t tim = time(NULL);

	String^ boundary = "---------------------------" + tim; //DateTime::Now;
	array<Byte>^ boundarybytes = Encoding::ASCII->GetBytes("\r\n--" + boundary + "\r\n");

	WebRequest^ request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(uri));
	request->Method = "POST";
	request->ContentType = "multipart/form-data; boundary=" + boundary;

	FileStream^ fileStream = gcnew FileStream(filePath, FileMode::Open, FileAccess::Read, FileShare::Read);

	Stream^ requestStream = request->GetRequestStream();

	requestStream->Write(boundarybytes, 0, boundarybytes->Length);
	String^ formItem = String::Format(formdataTemplate, Path::GetFileName(filePath));
	array<Byte>^ formBytes = Encoding::UTF8->GetBytes(formItem);
	requestStream->Write(formBytes, 0, formBytes->Length);
	array<Byte>^ buffer = gcnew array<Byte>(1024 * 4);
	int bytesLeft = 0;

	while ((bytesLeft = fileStream->Read(buffer, 0, buffer->Length)) > 0)
	{
		requestStream->Write(buffer, 0, bytesLeft);
	}

	try {
		WebResponse^ response = request->GetResponse();

		Stream^ data = response->GetResponseStream();
		StreamReader^ reader = gcnew StreamReader(data);
		String^ data_result = reader->ReadToEnd();

		response->Close();
	}
	catch (Exception^ e) {
		Console::Write(e->Message);
	}
}

System::Void MusicApp::CreateRoomForm::button_join_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ invite_link = textBox_join_invite->Text;

	if (invite_link != "") {
		array<String^>^ invite_code = invite_link->Split('=');

		int res = Join_in_room(invite_code[1]);

		if (res != 0) {
			Close();
		}
		else {
			MessageBox::Show("Неверная ссылка приглашения");
		}
	}
	else {
		MessageBox::Show("Введите ссылку приглашения");
	}
}

int MusicApp::CreateRoomForm::Join_in_room(String^ invite_code) {
	int id_room = 0;

	String^ link = "http://" + ip + ":8011/join_room?id_user=" + user_id + "&code=" + invite_code;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ resultRequest = netFunction->createRequest(link);

	id_room = Convert::ToInt32(resultRequest);

	return id_room;
}