#include "MusicEditForm.h"

/*--------------------------------Добавление на поле редактирования дорожки------------------------------------*/

void MusicApp::MusicEditForm::addWayItem(String^ _name_way, int width_way, String^ _name_studio) {
	array<WayEditorItem^>^ wayEditor = gcnew array<WayEditorItem^>(1);

	for (int i = 0; i < 1; i++) {
		wayEditor[i] = gcnew WayEditorItem(teme);

		wayEditor[i]->setName_Way(_name_way);
		wayEditor[i]->setName_Room(_name_studio);

		panel_editor_view->Controls->Add(wayEditor[i]);

		wayEditor[i]->BringToFront();
		wayEditor[i]->Width = width_way * 20;
		wayEditor[i]->GetType()->GetProperty("Location")->SetValue(wayEditor[i], Point(0, 75));

		wayEditor[i]->Click += gcnew System::EventHandler(this, &MusicEditForm::WayEditorClick);

		guna2Panel1->BringToFront();
	}
}

void MusicApp::MusicEditForm::addWayItem(String^ _name_way, int width_way, String^ _name_studio, int value_left, int value_top) {
	array<WayEditorItem^>^ wayEditor = gcnew array<WayEditorItem^>(1);

	for (int i = 0; i < 1; i++) {
		wayEditor[i] = gcnew WayEditorItem(teme);

		wayEditor[i]->setName_Way(_name_way);
		wayEditor[i]->setName_Room(_name_studio);

		panel_editor_view->Controls->Add(wayEditor[i]);

		wayEditor[i]->BringToFront();
		wayEditor[i]->Width = width_way;
		wayEditor[i]->GetType()->GetProperty("Location")->SetValue(wayEditor[i], Point(value_left, value_top));

		wayEditor[i]->Click += gcnew System::EventHandler(this, &MusicEditForm::WayEditorClick);

		guna2Panel1->BringToFront();
	}
}

void MusicApp::MusicEditForm::WayEditorClick(System::Object^ sender, System::EventArgs^ e) {
	WayEditorItem^ wayEdit = (WayEditorItem^)sender;

	currObject = sender;
	currObject_Del_Cut = sender;

	String^ file_name = "./load/audio/temp/" + wayEdit->getName_Way();

	getTotalTimeMusic(file_name);

	label_editor_name_way->Text = wayEdit->getName_Way();
	label_editor_name_room->Text = wayEdit->getName_Room();
}

System::Void MusicApp::MusicEditForm::panel_editor_view_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (currObject != nullptr) {
		currObject->GetType()->GetProperty("Location")->SetValue(currObject, Point(Cursor->Position.X - 340, Cursor->Position.Y - 150));
	}
}

System::Void MusicApp::MusicEditForm::panel_editor_view_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button.ToString() == "Right") {
		int x = (Cursor->Position.X - 340) - Cursor->Position.X % 20;
		int y = (Cursor->Position.Y - 150) - Cursor->Position.Y % 75;

		currObject->GetType()->GetProperty("Location")->SetValue(currObject, Point(x, y));

		currObject = nullptr;
	}
}
