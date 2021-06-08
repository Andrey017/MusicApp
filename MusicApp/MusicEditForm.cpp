#include "MusicEditForm.h"

System::Void MusicApp::MusicEditForm::MusicEditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	DirectoryInfo^ dirInfo = gcnew DirectoryInfo("./load/audio/temp/");

	for each (FileInfo ^ file in dirInfo->GetFiles())
	{
		if (file->Name != "mix") {
			file->Delete();
		}
	}
}

int MusicApp::MusicEditForm::getTotalTimeMusic(String^ file_name) {
	WaveFileReader^ wave = gcnew NAudio::Wave::WaveFileReader(file_name);

	TimeSpan^ timeSpa = wave->TotalTime;

	int totalTimeAudio_min = timeSpa->Minutes;
	int totalTimeAudio_sec = timeSpa->Seconds;

	if (totalTimeAudio_sec >= 60) {
		totalTimeAudio_sec = totalTimeAudio_sec - totalTimeAudio_min * 60;
	}

	String^ totalTime;

	if (totalTimeAudio_min < 10 && totalTimeAudio_sec < 10) {
		totalTime = "0" + totalTimeAudio_min + ":0" + totalTimeAudio_sec;
	}
	else if (totalTimeAudio_min < 10) {
		totalTime = "0" + totalTimeAudio_min + ":" + totalTimeAudio_sec;
	}
	else if (totalTimeAudio_sec < 10) {
		totalTime = "" + totalTimeAudio_min + ":0" + totalTimeAudio_sec;
	}

	label_editor_time_way->Text = totalTime;

	wave->Close();

	return totalTimeAudio_sec;
}

bool MusicApp::MusicEditForm::checkFileDownload(String^ fileName) {
	bool check;

	WIN32_FIND_DATA findFileData;

	pin_ptr<const wchar_t> wnameFile = PtrToStringChars(fileName);

	HANDLE const hFind = FindFirstFile(wnameFile, &findFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		check = false;
	}
	else {
		check = true;
	}

	return check;
}

System::Void MusicApp::MusicEditForm::pictureBox_cut_way_Click(System::Object^ sender, System::EventArgs^ e) {
	WayEditorItem^ wayItem = (WayEditorItem^)currObject_Del_Cut;

	int value_left = 0;
	int value_top = 0;

	if (currObject_Del_Cut != nullptr) {
		int value_slider = guna2Panel1->Left;

		int full_width = wayItem->Width;

		int x_position = wayItem->Location.X;
		int end_position = x_position + full_width;

		if (x_position <= value_slider <= end_position) {
			value_left = value_slider - x_position;

			wayItem->Width = value_left;

			addWayItem(wayItem->getName_Way(), end_position - value_slider, wayItem->getName_Room(), value_slider, wayItem->Top);
		}
	}
}

System::Void MusicApp::MusicEditForm::pictureBox_delete_way_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currObject_Del_Cut != nullptr) {
		for each (Control^ control in panel_editor_view->Controls)
		{
			if (control == currObject_Del_Cut) {
				int index = panel_editor_view->Controls->GetChildIndex(control);
				panel_editor_view->Controls->RemoveAt(index);
			}
		}
	}
}

