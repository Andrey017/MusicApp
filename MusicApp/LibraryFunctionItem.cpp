#include "HomeForm.h"

using namespace System;

void MusicApp::HomeForm::addAudioItem(std::vector<int> list_id_audio, std::vector<std::string> list_name_audio, std::vector<std::string> list_creators_audio, std::vector<int> list_id_room, std::vector<int> list_access, std::vector<std::string> list_path_picture) {
	String^ id;
	String^ name_audio;
	String^ name_creators_audio;
	String^ id_room;
	String^ path_picture;
	int checkDownload;

	flowLayoutPanel_library_item_audio->Controls->Clear();
	
	int size_list = list_name_audio.size();

	array<ListAudioItem^>^ audioItem = gcnew array<ListAudioItem^>(size_list);

	array<String^>^ only_name;

	for (int i = 0; i < size_list; i++) {
		audioItem[i] = gcnew ListAudioItem(teme);

		if (teme == "1") {
			audioItem[i]->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		}

		id = gcnew String(list_id_audio[i].ToString());
		name_audio = gcnew String(list_name_audio[i].c_str());
		name_creators_audio = gcnew String(list_creators_audio[i].c_str());
		id_room = gcnew String(list_id_room[i].ToString());
		path_picture = gcnew String(list_path_picture[i].c_str());

		only_name = name_audio->Split('.');

		//audioItem[i]->setId_room(id);
		audioItem[i]->setName_Audio(only_name[0]);
		audioItem[i]->setName_Creator_Audio(name_creators_audio);
		audioItem[i]->setId_room(id_room);
		audioItem[i]->setName_in_server(name_audio);
		audioItem[i]->setCheckDownload(checkFileDownload("./load/audio/" + name_audio));
		audioItem[i]->setPath_Picture_Audio(path_picture);

		audioItem[i]->Width = flowLayoutPanel_library_item_audio->Width;

		flowLayoutPanel_library_item_audio->Controls->Add(audioItem[i]);

		audioItem[i]->Click += gcnew System::EventHandler(this, &HomeForm::AudoiItemClick);

		Array::Clear(only_name, 0, only_name->Length);
	}
}

//Обработчик нажатия на элемент списка
void MusicApp::HomeForm::AudoiItemClick(System::Object^ sender, System::EventArgs^ e) {
	ListAudioItem^ audioI = (ListAudioItem^)sender;

	label_name_audio_play->Text = audioI->getName_Audio();
	label_name_creator_audio_play->Text = audioI->getName_Creator_Audio();

	if (checkFileDownload("./load/audio/" + audioI->getName_Audio() + ".wav")) {
		loadSaveImage(audioI->getPath_Picture_Audio());

		panel_music->Visible = true;

		file_music = "./load/audio/" + label_name_audio_play->Text + ".wav";

		loadMusicFile();
	}
	else {
		MessageBox::Show("Выбранный файл не загружен. Необходимо сначала загрузить");
	}
}

//Загрузка списка комнат
int MusicApp::HomeForm::Load_List_Audio() {
	int result = 0;

	std::vector<int> list_id_audio;
	std::vector<std::string> list_name_audio;
	std::vector<std::string> list_creators_audio;
	std::vector<int> list_id_room;
	std::vector<int> list_access;
	std::vector<std::string> list_path_picture;
	std::vector<std::string> list_path_audio;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_audio_info?user_id=" + user_id + "&type=" + downButton_list;

	String^ resultRequest = netFunction->createRequest(link);

	std::string utf8 = netFunction->convertstringToString(resultRequest);

	if (utf8 != "[]") {
		json responseJSON = json::parse(utf8);
		unsigned int size = responseJSON.size();

		for (int i = 0; i < size; i++) {
			int audio_id = responseJSON[i]["id"];
			std::string name_audio_str = netFunction->UTF8ToANSI(responseJSON[i]["name_audio"]);
			std::string name_creators_str = netFunction->UTF8ToANSI(responseJSON[i]["name_creators"]);
			int id_room_str = responseJSON[i]["id_room"];
			int access_str = responseJSON[i]["access"];
			std::string path_picture_str = netFunction->UTF8ToANSI(responseJSON[i]["path_picture"]);
			int type_str = responseJSON[i]["type"];

			list_id_audio.push_back(audio_id);
			list_name_audio.push_back(name_audio_str);
			list_creators_audio.push_back(name_creators_str);
			list_id_room.push_back(id_room_str);
			list_access.push_back(access_str);

			if (type_str == 1) {
				list_path_picture.push_back(path_picture_str);
			}
			else {
				if (teme == "1") {
					list_path_picture.push_back("icons8_music_100px_white.png");
				}
				else {
					list_path_picture.push_back("icons8_music_100px_black.png");
				}
			}
		}

		addAudioItem(list_id_audio, list_name_audio, list_creators_audio, list_id_room, list_access, list_path_picture);

		result = 1;
	}

	return result;
}

System::Void MusicApp::HomeForm::button_load_list_music_Click(System::Object^ sender, System::EventArgs^ e) {
	downButton_list = 1;

	if (teme == "1") {
		button_load_list_music->FillColor = Color::FromArgb(94, 148, 255);
		button_load_list_music->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		button_load_list_way->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		button_load_list_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	}
	else {
		button_load_list_music->FillColor = Color::FromArgb(94, 148, 255);
		button_load_list_music->ForeColor = Color::FromArgb(255, 255, 255);

		button_load_list_way->FillColor = Color::FromArgb(241, 241, 241);
		button_load_list_way->ForeColor = Color::FromArgb(0, 0, 0);
	}

	Load_List_Audio();
}

System::Void MusicApp::HomeForm::button_load_list_way_Click(System::Object^ sender, System::EventArgs^ e) {
	downButton_list = 2;

	if (teme == "1") {
		button_load_list_music->FillColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		button_load_list_music->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		button_load_list_way->FillColor = Color::FromArgb(94, 148, 255);
		button_load_list_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	}
	else {
		button_load_list_music->FillColor = Color::FromArgb(241, 241, 241);
		button_load_list_music->ForeColor = Color::FromArgb(0, 0, 0);

		button_load_list_way->FillColor = Color::FromArgb(94, 148, 255);
		button_load_list_way->ForeColor = Color::FromArgb(255, 255, 255);
	}

	Load_List_Audio();
}

void MusicApp::HomeForm::loadSaveImage(String^ name_image) {
	String^ link = "http://" + ip + ":8011/uploads/picture/" + name_image;

	WebRequest^ request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(link));

	System::IO::MemoryStream^ memoryStream_in = gcnew System::IO::MemoryStream();

	try {
		WebResponse^ response = request->GetResponse();

		Stream^ data = response->GetResponseStream();

		int count = 0;

		do {
			array<Byte>^ buff = gcnew array<Byte>(1024);

			count = data->Read(buff, 0, 1024);

			memoryStream_in->Write(buff, 0, count);
		} while (data->CanRead && count > 0);

		response->Close();
	}
	catch (Exception^ e) {
		Console::Write(e->Message);
	}

	pictureBox_audio_play->Image = Image::FromStream(memoryStream_in);

	memoryStream_in->Close();
}