#include "MusicEditForm.h"

void MusicApp::MusicEditForm::LoadListWay() {
	std::vector<int> list_id;
	std::vector<std::string> list_name_way;
	std::vector<std::string> list_name_room_way;
	std::vector<std::string> list_type_way;

	NetFunction^ netFunction = gcnew NetFunction();

	String^ link = "http://" + ip + ":8011/load_audio_info?user_id=" + user_id + "&type=2";

	String^ resultRequest = netFunction->createRequest(link);

	std::string utf8 = netFunction->convertstringToString(resultRequest);

	if (utf8 != "[]") {
		json responseJSON = json::parse(utf8);
		unsigned int size = responseJSON.size();

		for (int i = 0; i < size; i++) {
			int id = responseJSON[i]["id_room"];
			std::string name_way_str = netFunction->UTF8ToANSI(responseJSON[i]["name_audio"]);
			std::string name_room_str = netFunction->UTF8ToANSI(responseJSON[i]["name"]);
			std::string type_str = netFunction->UTF8ToANSI(responseJSON[i]["path_picture"]);

			list_id.push_back(Convert::ToInt32(id));
			list_name_way.push_back(name_way_str);
			list_name_room_way.push_back(name_room_str);
			list_type_way.push_back(type_str);
		}

		addItemWayList(list_id, list_name_way, list_name_room_way, list_type_way);
	}
	else {
		MessageBox::Show("Неудалось найти найти доступные дорожки");
	}
}

void MusicApp::MusicEditForm::addItemWayList(std::vector<int> list_id, std::vector<std::string> list_name_way, std::vector<std::string> list_name_room, std::vector<std::string> list_type_way) {
	String^ id_way;
	String^ name_way;
	String^ name_room_way;
	String^ type_way;

	int size_list = list_id.size();

	array<ListWayItem^>^ wayItem = gcnew array<ListWayItem^>(size_list);

	for (int i = 0; i < size_list; i++) {
		wayItem[i] = gcnew ListWayItem(teme, ip);

		id_way = gcnew String(list_id[i].ToString());
		name_way = gcnew String(list_name_way[i].c_str());
		name_room_way = gcnew String(list_name_room[i].c_str());
		type_way = gcnew String(list_type_way[i].c_str());

		wayItem[i]->setID_way(id_way);
		wayItem[i]->setName_Way(name_way);
		wayItem[i]->setName_Room(name_room_way);
		wayItem[i]->setPath_Picture(type_way);

		flowLayoutPanel_list_way->Controls->Add(wayItem[i]);

		wayItem[i]->DoubleClick += gcnew System::EventHandler(this, &MusicEditForm::wayItemListDoubleClick);
	}
}

void MusicApp::MusicEditForm::wayItemListDoubleClick(System::Object^ sender, System::EventArgs^ e) {
	ListWayItem^ wayItem = (ListWayItem^)sender;

	wayItem->SaveFileInTemp();

	String^ file_name = "./load/audio/temp/" + wayItem->getName_Way();

	int way_width = getTotalTimeMusic(file_name);
	label_editor_name_way->Text = wayItem->getName_Way();
	label_editor_name_room->Text = wayItem->getName_Room();
	gl_room_id = Convert::ToInt32(wayItem->getID_way());

	addWayItem(wayItem->getName_Way(), way_width, wayItem->getName_Room());
}