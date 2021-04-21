#include "HomeForm.h"

using namespace System;

System::Void MusicApp::HomeForm::button_record_Click(System::Object^ sender, System::EventArgs^ e) {
	if (record) {
		//������������� ������
		if (waveIn != nullptr) {
			StopRecording();

			record = false;
			button_record->Image = Image::FromFile("./image/icons8_record_48px_start.png");
		}
	}
	else {
		button_record->Image = Image::FromFile("./image/icons8_stop_48px_stop.png");

		record = true;

		//�������� ������
		StartRecordMusic();
	}
}

//������ ������
void MusicApp::HomeForm::StartRecordMusic() {
	SaveAudioForm^ saveAudio = gcnew SaveAudioForm(teme);
	saveAudio->ShowDialog();

	check_music_or_way = saveAudio->getChech_Value();

	if (check_music_or_way != 0) {
		if (check_music_or_way == 1) {
			outFileName = saveAudio->getName_Audio() + ".wav";
			name_creators_in = saveAudio->getCreators();
			access_in = saveAudio->getAccess();
			path_picture_music = saveAudio->getPath_File();
		}
		else if (check_music_or_way == 2) {
			outFileName = saveAudio->getName_Audio() + ".wav";
		}

		try {
			waveIn = gcnew WaveIn();

			//�������� ���-�� ��������� �������
			int waveInDevices = waveIn->DeviceCount;

			//������� ��� ���������� �������
			for (int i = 0; i < waveInDevices; i++) {
				WaveInCapabilities^ deviceInfo = waveIn->GetCapabilities(i);

				MessageBox::Show("Device " + i + ": " + deviceInfo->ProductName + ", " + deviceInfo->Channels + " channels");
			}

			MessageBox::Show("Start Recording");

			waveIn->DeviceNumber = 0;

			//�������� ������ � ��������� � �����
			waveIn->DataAvailable += gcnew EventHandler<WaveInEventArgs^>(this, &HomeForm::waveIn_DataAvailable);
			//����������� �������� ������ � ����������
			waveIn->RecordingStopped += gcnew EventHandler<StoppedEventArgs^>(this, &HomeForm::waveIn_RecordingStopped);

			//������������� ��������� ��� ��������� �����
			waveIn->WaveFormat = gcnew WaveFormat(8000, 1);

			//������� ���� � ������������ �����������
			writer = gcnew WaveFileWriter(outFileName, waveIn->WaveFormat);

			//���������� � ����
			waveIn->StartRecording();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	else {
		button_record->Image = Image::FromFile("./image/icons8_record_48px_start.png");
		record = false;
	}

}

//��������� ������ �� �������� �������
void MusicApp::HomeForm::waveIn_DataAvailable(System::Object^ sender, WaveInEventArgs^ e) {
	if (this->InvokeRequired) {
		this->BeginInvoke(gcnew EventHandler<WaveInEventArgs^>(this, &HomeForm::waveIn_DataAvailable), sender, e);
	}
	else {
		//���������� ������ �� ������ � ����
		writer->WriteData(e->Buffer, 0, e->BytesRecorded);
	}
}

//��������� ������
void MusicApp::HomeForm::waveIn_RecordingStopped(System::Object^ sender, StoppedEventArgs^ e) {
	if (this->InvokeRequired) {
		this->BeginInvoke(gcnew EventHandler<StoppedEventArgs^>(this, &HomeForm::waveIn_RecordingStopped), sender, e);
	}
	else {
		//waveIn->Dispose();

		//waveIn = NULL;
		waveIn = nullptr;
		writer->Close();
		writer = nullptr;

		saveAudioFile();
	}
}

//��������� ������
void MusicApp::HomeForm::StopRecording() {
	MessageBox::Show("Stop Recording");
	waveIn->StopRecording();
}

//��������� ������ �� �������
void MusicApp::HomeForm::saveAudioFile() {
	String^ link = "http://" + ip + ":8011/upload?folderNameMu=" + gl_room_id;
	String^ link_picture = "http://" + ip + ":8011/upload?folderNameMu=picture";
	String^ filePath = outFileName;

	saveFile(link, filePath);

	saveFile(link_picture, path_picture_music);

	addInfoAudioFile(filePath, name_surname, Path::GetFileName(path_picture_music));

	/*OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		filePath = openFileDialog->FileName;

		saveFile(link, filePath);

		addInfoAudioFile(Path::GetFileName(filePath), name_surname, Path::GetFileName(filePath));
	}*/
}

void MusicApp::HomeForm::addInfoAudioFile(String^ name_audio, String^ name_creators, String^ path_picture) {
	NetFunction^ netFunction = gcnew NetFunction();

	int acc;
	String^ link;

	if (check_music_or_way != 0) {
		if (check_music_or_way == 1) {
			if (access_in) {
				acc = 1;
			}
			else {
				acc = 0;
			}

			link = "http://" + ip + ":8011/add_new_audio?name_audio=" + name_audio + "&name_creators=" + name_creators_in + "&id_room=" + gl_room_id + "&access=" + acc + "&path_picture=" + path_picture + "&type=1";
		}
		else if (check_music_or_way == 2) {
			link = "http://" + ip + ":8011/add_new_audio?name_audio=" + name_audio + "&name_creators=" + name_creators + "&id_room=" + gl_room_id + "&access=0&path_picture=" + path_picture + "&type=2";
		}

		String^ resultRequest = netFunction->createRequest(link);
	}
}