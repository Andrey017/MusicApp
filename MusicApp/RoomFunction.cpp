#include "HomeForm.h"

void MusicApp::HomeForm::addRoomItem(std::vector<int> list_id, std::vector<std::string> list_name_room, std::vector<std::string> list_path_room_pict, std::vector<std::string> list_creators_room, std::vector<std::string> list_prim_room) {
	String^ id_room;
	String^ name_room;
	String^ namePict;
	String^ creators_room;
	String^ prim;

	int size_list = list_id.size();
	
	array<RoomItem^>^ roomItem = gcnew array<RoomItem^>(size_list);

	for (int i = 0; i < size_list; i++) {
		roomItem[i] = gcnew RoomItem(teme);

		if (teme == "1") {
			roomItem[i]->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		}

		id_room = gcnew String(list_id[i].ToString());
		name_room = gcnew String(list_name_room[i].c_str());
		namePict = gcnew String(list_path_room_pict[i].c_str());
		//creators_room = gcnew String(list_creators_room[i].c_str());
		//prim = gcnew String(list_prim_room[i].c_str());

		roomItem[i]->ID_room(id_room);
		roomItem[i]->Name_Room(name_room);
		roomItem[i]->setName_Picture(namePict);
		//roomItem[i]->creators_Room(creators_room);
		//roomItem[i]->Prim(prim);

		panel_item_room->Controls->Add(roomItem[i]);

		roomItem[i]->Click += gcnew System::EventHandler(this, &HomeForm::RoomItemClick);
	}
}

void MusicApp::HomeForm::RoomItemClick(System::Object^ sender, System::EventArgs^ e) {
	RoomItem^ roomI = (RoomItem^)sender;

	gl_room_id = roomI->getId_room();
	gl_name_room = roomI->getName_room();

	panel_studio_conf->Visible = true;
	label_conf_name_room->Text = gl_name_room;

	LoadUsersRoom();
}

void MusicApp::HomeForm::Load_Room() {
	int room_id;

	std::vector<int> list_id;
	std::vector<std::string> list_name_room;
	std::vector<std::string> list_creators_room;
	std::vector<std::string> list_prim_room;
	std::vector<std::string> list_path_room_pict;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_room_user?user_id=" + user_id;

	String^ resultRequest = netFunction->createRequest(link);

	std::string utf8 = netFunction->convertstringToString(resultRequest);

	if (utf8 != "[]") {
		json responseJSON = json::parse(utf8);
		unsigned int size = responseJSON.size();

		for (int i = 0; i < size; i++) {
			room_id = responseJSON[i]["id"];
			std::string name_room_str = netFunction->UTF8ToANSI(responseJSON[i]["name"]);
			std::string fileName_pic_str = netFunction->UTF8ToANSI(responseJSON[i]["path_picture"]);
			//std::string creators_room_str = netFunction->UTF8ToANSI(responseJSON[i]["creator"]);
			//std::string prim_str = netFunction->UTF8ToANSI(responseJSON[i]["prim"]);

			list_id.push_back(Convert::ToInt32(room_id));
			list_name_room.push_back(name_room_str);
			list_path_room_pict.push_back(fileName_pic_str);
			//list_creators_room.push_back(creators_room_str);
			//list_prim_room.push_back(prim_str);
		}

		addRoomItem(list_id, list_name_room, list_path_room_pict, list_creators_room, list_prim_room);
	}
	else {
		MessageBox::Show("Неудалось загрузить список студий");
	}
}

System::Void MusicApp::HomeForm::guna2ImageButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ name_room = textBox_add_room->Text;

	CreateRoomForm^ createRoomForm = gcnew CreateRoomForm(user_id, ip, teme);
	createRoomForm->ShowDialog();

	panel_item_room->Controls->Clear();

	Load_Room();
}

System::Void MusicApp::HomeForm::button_conf_start_call_Click(System::Object^ sender, System::EventArgs^ e) {	
	WebRTCConf(gl_room_id);
}

System::Void MusicApp::HomeForm::button_conf_cancel_call_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ linkRoom = "https://" + ip + ":8443/temp";

	browser->Load(linkRoom);
	
	panel_conf->Height = 0;
	
	button_conf_start_call->Visible = true;
	button_conf_cancel_call->Visible = false;
}

void MusicApp::HomeForm::WebRTCConf(String^ id) {
	String^ codeRoom = LoadLinkRoom(id);

	String^ linkRoom = "https://" + ip + ":8443/?room=" + codeRoom + "&user_name=" + name_surname;

	panel_conf->Height = 400;
	browser->Load(linkRoom);
	browser->Dock = DockStyle::Fill;

	button_conf_start_call->Visible = false;
	button_conf_cancel_call->Visible = true;
}

String^ MusicApp::HomeForm::LoadLinkRoom(String^ id) {
	String^ linkRoom;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_link_room?room_id=" + id;

	linkRoom = netFunction->createRequest(link);

	return linkRoom;
}

System::Void MusicApp::HomeForm::button_add_new_user_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email_new_user = textBox_add_new_user_room->Text;
	
	int _user_id = LoadUserId(email_new_user);
	if (_user_id != 0) {
		int result = addNewUser(_user_id, gl_room_id);

		if (result == 0) {
			MessageBox::Show("Пользователь не добавлен");
		}
		else {
			MessageBox::Show("Пользователь добавлен");
		}
	}
	else {
		MessageBox::Show("Такого пользователя не существует. Проверьте введенный email или отправьте ссылку на выбранную студию");
	}
}

int MusicApp::HomeForm::addNewUser(int _user_id, String^ room_id) {
	int result_add = 0;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/add_new_user?id_user=" + _user_id + "&id_room=" + room_id;

	result_add = Convert::ToInt32(netFunction->createRequest(link));

	return result_add;
}

int MusicApp::HomeForm::LoadUserId(String^ email_user) {
	int newuser_id = 0;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_id_user?email_user=" + email_user;

	newuser_id = Convert::ToInt32(netFunction->createRequest(link));

	return newuser_id;
}

void MusicApp::HomeForm::LoadUsersRoom() {
	String^ name_avatar_users;

	std::vector<std::string> list_name_user;
	std::vector<std::string> list_name_avatar;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_user_in_room?room_id=" + gl_room_id;

	String^ resultRequest = netFunction->createRequest(link);

	std::string utf8 = netFunction->convertstringToString(resultRequest);

	if (utf8 != "[]") {
		json responseJSON = json::parse(utf8);
		unsigned int size = responseJSON.size();

		for (int i = 0; i < size; i++) {
			int in_id = responseJSON[i]["id"];
			if (in_id != user_id) {
				list_name_user.push_back(netFunction->UTF8ToANSI(responseJSON[i]["name"]) + " " + netFunction->UTF8ToANSI(responseJSON[i]["surname"]));

				std::string name_avatar_str = netFunction->UTF8ToANSI(responseJSON[i]["path_avatar"]);

				list_name_avatar.push_back(name_avatar_str);

				name_avatar_users = gcnew String(name_avatar_str.c_str());

				//loadsaveAvatar(name_avatar_users);
			}
		}

		addUserRoomItem(list_name_user, list_name_avatar);
	}
}

void MusicApp::HomeForm::addUserRoomItem(std::vector<std::string> list_name_user, std::vector<std::string> list_name_avatar) {
	String^ name_user;
	String^ name_avatar;

	int size_list = list_name_user.size();

	panel_list_user_rom->Controls->Clear();

	array<ListUserItem^>^ userItem = gcnew array<ListUserItem^>(size_list);

	for (int i = 0; i < size_list; i++) {
		userItem[i] = gcnew ListUserItem(teme);

		if (teme == "1") {
			userItem[i]->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
		}

		name_user = gcnew String(list_name_user[i].c_str());
		name_avatar = gcnew String(list_name_avatar[i].c_str());

		userItem[i]->setName_User(name_user);
		userItem[i]->setPhoto_User(name_avatar);

		panel_list_user_rom->Controls->Add(userItem[i]);
	}
}

void MusicApp::HomeForm::saveFile(String^ uri, String^ filePath) {
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

void MusicApp::HomeForm::loadsaveAvatar(String^ name_file) {
	String^ link = "http://" + ip + ":8011/uploads/picture/" + name_file;

	WebClient^ ws = gcnew WebClient();

	ws->OpenRead(link);
	//String^ size = "" + (Convert::ToInt32(ws->ResponseHeaders->Get(2)) / 1048576);

	//progressIndicator_user_load->Start();
	//progressIndicator_user_load->Visible = true;

	//ws->DownloadProgressChanged += gcnew System::Net::DownloadProgressChangedEventHandler(this, &MusicApp::HomeForm::OnDownloadIndicator);
	//ws->DownloadFileCompleted += gcnew AsyncCompletedEventHandler(this, &MusicApp::HomeForm::stopWaitingLoadFile);

	//ws->DownloadFile(link, "./uploads/" + name_file);
	ws->DownloadFile(gcnew Uri(link), "./load/pictures/" + name_file);

	//progressIndicator_user_load->Stop();
	//progressIndicator_user_load->Visible = false;
}

void MusicApp::HomeForm::OnDownloadIndicator(System::Object^ sender, System::Net::DownloadProgressChangedEventArgs^ e) {
	//throw gcnew System::NotImplementedException();

	progressIndicator_user_load->Start();
	progressIndicator_user_load->Visible = true;
}

void MusicApp::HomeForm::stopWaitingLoadFile(System::Object^ sender, AsyncCompletedEventArgs^ e) {
	progressIndicator_user_load->Stop();
	progressIndicator_user_load->Visible = false;
}