#include "AuthForm.h"

using namespace System;

System::Void MusicApp::AuthForm::guna2Button_auth_login_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email;
	String^ password;

	email = guna2TextBox_auth_email->Text;
	password = guna2TextBox_auth_password->Text;

	if (Login(email, password)) {
		String^ teme;

		if (slide) {
			teme = "0";
		}
		else {
			teme = "1";
		}

		setDataLogin(teme);

		this->Hide();
		HomeForm^ homeForm = gcnew HomeForm(user_id, name_surname, teme, gl_name_avatar);
		homeForm->Show();
	}
	else {
		//Вывод сообщения, что что-то не так
	}
}

System::Void MusicApp::AuthForm::guna2Button_reg_registration_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = guna2TextBox_reg_email->Text;
	String^ name = guna2TextBox_reg_name->Text;
	String^ surname = guna2TextBox_reg_surname->Text;
	String^ password = guna2TextBox_reg_pass->Text;
	String^ rep_password = guna2TextBox_reg_rep_pass->Text;

	if (password == rep_password) {
		String^ result = Registration(email, password, name, surname);

		if (result != "0") {
			email_insert_user = email;

			insert_user_id = result;

			timer3->Start();
			panel_avatar->Left = 486;
		}
	}
	else {
		//Сообщение, что пароли не совпадают
		MessageBox::Show("Пароли не совпадают");
	}
}

bool MusicApp::AuthForm::Login(String^ email, String^ password) {
	bool logincheck = false;
	
	String^ name;
	String^ surname;
	int active;
	String^ access_token;
	String^ refresh_token;
	
	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/login?email=" + email + "&password=" + password;

	String^ resultRequest = netFunction->createRequest(link);

	std::string utf8 = netFunction->convertstringToString(resultRequest);

	if (utf8 == "0") {
		return logincheck;
	}
	else if (utf8 == "") {
		MessageBox::Show("Не верный логин или пароль");
	}

	if (utf8 != "[]") {
		json responseJSON = json::parse(utf8);

		user_id = responseJSON[0]["id"];
		std::string name_str = netFunction->UTF8ToANSI(responseJSON[0]["name"]);
		std::string surname_str = netFunction->UTF8ToANSI(responseJSON[0]["surname"]);
		active = responseJSON[0]["active"];
		std::string accessToken_str = netFunction->UTF8ToANSI(responseJSON[0]["access_token"]);
		std::string refreshToken_str = netFunction->UTF8ToANSI(responseJSON[0]["refresh_token"]);
		std::string name_avatar_str = netFunction->UTF8ToANSI(responseJSON[0]["path_avatar"]);

		name = gcnew String(name_str.c_str());
		surname = gcnew String(surname_str.c_str());
		access_token = gcnew String(accessToken_str.c_str());
		refresh_token = gcnew String(refreshToken_str.c_str());
		gl_name_avatar = gcnew String(name_avatar_str.c_str());

		name_surname = name + " " + surname;

		loadsaveAvatar(gl_name_avatar);

		logincheck = true;
	}
	else {
		logincheck = false;
		MessageBox::Show("Не верный логин или пароль");
	}

	return logincheck;
}

void MusicApp::AuthForm::setDataLogin(String^ teme) {
	Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

	Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp", true);

	pathFileReport->SetValue("checkLogin", "1");
	pathFileReport->SetValue("userId", "" + user_id);
	pathFileReport->SetValue("nameUser", "" + name_surname);
	pathFileReport->SetValue("teme", "" + teme);
	//pathFileReport->SetValue("access_token", "" + access_token);
	//pathFileReport->SetValue("refresh_token", "" + refresh_token);
	pathFileReport->SetValue("avatar", gl_name_avatar);

	pathFileReport->Close();
}

/*Возвращает 0 - Нет соединения
*			 1 - регистрация прошла успешно
*			 2 - Пользователь с таким email уже существует
*			 3 - Невозможно зарегистрировать
*/
String^ MusicApp::AuthForm::Registration(String^ email, String^ password, String^ name, String^ surname) {
	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/reg?email=" + email + "&name=" + name + "&surname=" + surname + "&password=" + password;

	String^ resultRequest = netFunction->createRequest(link);

	return resultRequest;
}

System::Void MusicApp::AuthForm::pictureBox_add_avatar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog_add_avatar->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		file_path = openFileDialog_add_avatar->FileName;

		pictureBox_add_avatar->Image = Image::FromFile(file_path);
	}
}

System::Void MusicApp::AuthForm::button_add_avatar_in_profil_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ link = "http://" + ip + ":8011/upload?folderNameMu=picture";

	String^ fileNameServer = Path::GetFileName(file_path);
	
	loadAvatar(fileNameServer);

	saveFile(link, file_path);

	panel_avatar->Left = 70;
}

void MusicApp::AuthForm::loadAvatar(String^ fileNameServer) {
	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_avatar?user_id=" + insert_user_id + "&name_avatar=" + fileNameServer;

	String^ resultRequest = netFunction->createRequest(link);
}

void MusicApp::AuthForm::saveFile(String^ uri, String^ filePath) {
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

void MusicApp::AuthForm::loadsaveAvatar(String^ name_file) {
	String^ link = "http://" + ip + ":8011/uploads/picture/" + name_file;

	WebClient^ ws = gcnew WebClient();

	ws->OpenRead(link);
	//String^ size = "" + (Convert::ToInt32(ws->ResponseHeaders->Get(2)) / 1048576);

	//ws->DownloadProgressChanged += gcnew System::Net::DownloadProgressChangedEventHandler(this, &MusicApp::ListAudioItem::OnDownloadProgressChanged);

	//ws->DownloadFile(link, "./uploads/" + name_file);
	ws->DownloadFile(gcnew Uri(link), "./load/pictures/" + name_file);
}