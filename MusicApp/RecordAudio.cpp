#include "HomeForm.h"

using namespace System;

System::Void MusicApp::HomeForm::button_record_Click(System::Object^ sender, System::EventArgs^ e) {
	if (record) {
		//Останавливаем запись
		if (waveIn != nullptr) {
			StopRecording();

			record = false;
			button_record->Image = Image::FromFile("./image/icons8_record_48px_start.png");
		}

		if (waveIn_wasapiLoopbackCapture != nullptr) {
			StopRecording();

			record = false;
			button_record->Image = Image::FromFile("./image/icons8_record_48px_start.png");
		}
	}
	else {
		button_record->Image = Image::FromFile("./image/icons8_stop_48px_stop.png");

		record = true;

		//Начинаем запись
		StartRecordMusic();
	}
}

//Начало записи
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

		sett_sam_freq = Convert::ToInt32(saveAudio->getSam_freq());
		sett_bit = Convert::ToInt32(saveAudio->getBit());
		sett_count_chanel = Convert::ToInt32(saveAudio->getCount_channel());
		sett_thres = Convert::ToDouble(saveAudio->getThres());

		change_one_or_more = saveAudio->getChange_one_or_more();

		if (change_one_or_more == 1) {
			try {
				waveIn = gcnew WaveIn();

				//Получаем кол-во устройств захвата
				int waveInDevices = waveIn->DeviceCount;

				//Выводим все устройства захвата
				for (int i = 0; i < waveInDevices; i++) {
					WaveInCapabilities^ deviceInfo = waveIn->GetCapabilities(i);

					MessageBox::Show("Device " + i + ": " + deviceInfo->ProductName + ", " + deviceInfo->Channels + " channels");
				}

				MessageBox::Show("Start Recording");

				waveIn->DeviceNumber = 0;

				//Получаем данные с микрофона в буфер
				waveIn->DataAvailable += gcnew EventHandler<WaveInEventArgs^>(this, &HomeForm::waveIn_DataAvailable);
				//Заканчиваем получать данные с устройства
				waveIn->RecordingStopped += gcnew EventHandler<StoppedEventArgs^>(this, &HomeForm::waveIn_RecordingStopped);

				//Устанавливаем параметры для выходного файла
				waveIn->WaveFormat = gcnew WaveFormat(sett_sam_freq, sett_bit, sett_count_chanel);

				//Создаем файл с необходимыми параметрыми
				writer = gcnew WaveFileWriter(outFileName, waveIn->WaveFormat);

				//Записываем в файл
				waveIn->StartRecording();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->Message);
			}
		}
		else if (change_one_or_more == 2) {
			waveIn_wasapiLoopbackCapture = gcnew WasapiLoopbackCapture();

			waveIn_wasapiLoopbackCapture->DataAvailable += gcnew EventHandler<WaveInEventArgs^>(this, &HomeForm::waveIn_DataAvailable);
			waveIn_wasapiLoopbackCapture->RecordingStopped += gcnew EventHandler<StoppedEventArgs^>(this, &HomeForm::waveIn_RecordingStopped);

			writer = gcnew WaveFileWriter(outFileName, waveIn_wasapiLoopbackCapture->WaveFormat);

			waveIn_wasapiLoopbackCapture->StartRecording();
		}

	}
	else {
		button_record->Image = Image::FromFile("./image/icons8_record_48px_start.png");
		record = false;
	}

}

//Получение данных из входного буффера
void MusicApp::HomeForm::waveIn_DataAvailable(System::Object^ sender, WaveInEventArgs^ e) {
	if (this->InvokeRequired) {
		this->BeginInvoke(gcnew EventHandler<WaveInEventArgs^>(this, &HomeForm::waveIn_DataAvailable), sender, e);
	}
	else {
		//Записываем данные из буфера в файл

		if (change_one_or_more == 1) {
			bool result = ProcessData(e);

			if (result) {
				// обрабатываем звуковые данные
				writer->WriteData(e->Buffer, 0, e->BytesRecorded);
			}
			else {
				// если речь не определена на звуковом отрезке
				array<unsigned char>^ buff = gcnew array<unsigned char>(e->BytesRecorded);
				writer->WriteData(buff, 0, e->BytesRecorded);
			}
		}
		else if (change_one_or_more == 2) {
			writer->WriteData(e->Buffer, 0, e->BytesRecorded);
		}
	}
}

//Окончание записи
void MusicApp::HomeForm::waveIn_RecordingStopped(System::Object^ sender, StoppedEventArgs^ e) {
	if (this->InvokeRequired) {
		this->BeginInvoke(gcnew EventHandler<StoppedEventArgs^>(this, &HomeForm::waveIn_RecordingStopped), sender, e);
	}
	else {
		waveIn = nullptr;
		waveIn_wasapiLoopbackCapture = nullptr;

		writer->Close();
		writer = nullptr;

		saveAudioFile();
	}
}

//Завершаем запись
void MusicApp::HomeForm::StopRecording() {
	MessageBox::Show("Stop Recording");

	if (change_one_or_more == 1) {
		waveIn->StopRecording();
	}
	else if (change_one_or_more == 2) {
		waveIn_wasapiLoopbackCapture->StopRecording();
	}
}

bool MusicApp::HomeForm::ProcessData(WaveInEventArgs^ e) {
	double porog = sett_thres;
	bool result = false;
	bool Tr = false;

	double Sum2 = 0;

	int Count = e->BytesRecorded / 2;

	for (int index = 0; index < e->BytesRecorded; index += 2) {
		double Tmp = (short)((e->Buffer[index + 1] << 8) | e->Buffer[index + 0]);

		Tmp /= 32768.0;

		Sum2 += Tmp * Tmp;

		if (Tmp > porog) {
			Tr = true;
		}
	}

	Sum2 /= Count;

	if (Tr || Sum2 > porog) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

//Сохраняем запись на сервере
void MusicApp::HomeForm::saveAudioFile() {
	String^ link = "http://" + ip + ":8011/upload?folderNameMu=" + gl_room_id;
	String^ link_picture = "http://" + ip + ":8011/upload?folderNameMu=picture";
	String^ filePath = outFileName;

	NetFunction^ netFunction = gcnew NetFunction();

	netFunction->saveFile(link, filePath);

	//saveFile(link, filePath);

	if (check_music_or_way == 1) {
		netFunction->saveFile(link_picture, path_picture_music);
		addInfoAudioFile(filePath, name_surname, Path::GetFileName(path_picture_music));
	}
	else {
		addInfoAudioFile(filePath, name_surname, Path::GetFileName(filePath));
	}
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