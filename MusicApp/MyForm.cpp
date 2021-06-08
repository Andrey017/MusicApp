#include "MyForm.h"
#include <ctime>

using namespace System;
using namespace System::Windows::Forms;
using namespace NAudio::Wave;
using namespace NAudio;

void MusicApp::MyForm::RecordTuner() {
	/*time_t Time = time(nullptr);

	MusicApp::MyForm::StartRecordMusic();
	if (time(nullptr) - Time == 20) {
		MusicApp::MyForm::StopRecording();
	}

	while (1) {
		if (time(nullptr) - Time == 60) {

			MusicApp::MyForm::StopRecording();
			//MusicApp::MyForm::StartRecordMusic();
			//Time = time(NULL);
		}
	}*/
}

void MusicApp::MyForm::StartRecordMusic() {
	try {
		waveIn = gcnew WaveIn();

		//Получаем кол-во устройств захвата
		int waveInDevices = waveIn->DeviceCount;

		//Выводим все устройства захвата
		for (int i = 0; i < waveInDevices; i++) {

			WaveInCapabilities^ deviceInfo = waveIn->GetCapabilities(i);
			String^ deviceName = deviceInfo->ProductName;
			String^ device = "";
			devices[i] = deviceName;

			//for (int j = 0; j < deviceName->Length; j++) {
			//	int o = deviceName->Length;
			//	if (j != 0 && j % 18 == 0) {
			//		device += deviceName[j].ToString();
			//		device += "\n";
			//	}
			//	else {
			//		device += deviceName[j].ToString();
			//	}
			//	//device->Insert(k, deviceName[j].ToString());
			//	
			//}
			//devices[i] = device;
		}

		//comboBoxDevice->Items->Clear();
		if (comboBoxDevice->Items->Count == 0) {
			comboBoxDevice->Items->AddRange(devices);
		}
		//comboBoxDevice->SelectedItem = deviceNumSelected;
		waveIn->DeviceNumber = deviceNumSelected;

		//Получаем данные с микрофона в буфер
		waveIn->DataAvailable += gcnew EventHandler<WaveInEventArgs^>(this, &MyForm::waveIn_DataAvailable);
		//Заканчиваем получать данные с устройства
		waveIn->RecordingStopped += gcnew EventHandler<StoppedEventArgs^>(this, &MyForm::waveIn_RecordingStopped);

		//Устанавливаем параметры для выходного файла

		waveIn->WaveFormat = gcnew WaveFormat(44100, 16, 1);
		/*int blockAlign = (short)((1 * 16 + 7) / 8);
		int averageBytesPerSecond = blockAlign * 44100;
		WaveFormat waveFormat;
		WaveFormatEncoding newWaveFormat;*/
		waveIn->BufferMilliseconds = 250;
		//waveIn->WaveFormat->CreateCustomFormat(newWaveFormat, 44100, 1, averageBytesPerSecond, blockAlign, 16);
		//waveIn->WaveFormat->BlockAlign = (short)((waveIn->WaveFormat->Channels * waveIn->WaveFormat->BitsPerSample + 7) / 8);

		//Создаем файл с необходимыми параметрыми
		writer = gcnew WaveFileWriter(outputFileName, waveIn->WaveFormat);

		//Записываем в файл
		waveIn->StartRecording();
	}
	catch (Exception^ e) {
		//MessageBox::Show(e->Message);
	}
}

//Получение данных из входного буффера
void MusicApp::MyForm::waveIn_DataAvailable(System::Object^ sender, WaveInEventArgs^ e) {
	if (this->InvokeRequired) {
		this->BeginInvoke(gcnew EventHandler<WaveInEventArgs^>(this, &MyForm::waveIn_DataAvailable), sender, e);
	}
	else {

		//переменная для обозначения начала распознавания речевого отрезка
		bool result = MusicApp::MyForm::ProcessData(e);
		// Если записываемый отрезок содержит речь
		//if (result == true)
		//{
		//	array<double>^ arr = gcnew array<double>(e->BytesRecorded);
		//	for (int i = 0; i < e->BytesRecorded; i++) {
		//		arr[i] = ((short)e->Buffer[i]) / 32768.0;
		//	}

		//	double resultFreq = freqCheck.FindFundamentalFrequency(arr, 44100, 60, 440);
		//	labelHz->Text = resultFreq.ToString("f3");
		//}
		//else
		//{
		//	// если речь не определена на звуковом отрезке
		//	labelHz->Text = "0.000";
		//}
		array<Byte>^ buf = gcnew array<Byte>(e->BytesRecorded);
		for (int i = 0; i < e->BytesRecorded; i++) {
			buf[i] = e->Buffer[i];
		}
		array<short>^ ar = gcnew array<short>(e->BytesRecorded);
		for (int i = 0; i < e->BytesRecorded; i++) {
			ar[i] = (short)e->Buffer[i];
		}

		array<double>^ arr = gcnew array<double>(e->BytesRecorded);
		for (int i = 0; i < e->BytesRecorded; i++) {
			arr[i] = ((short)buf[i]) / 32768.0;
		}



		//double resultFreq = freqCheck.FindFundamentalFrequency(arr, 44100, 60, 440);
		//labelHz->Text = resultFreq.ToString("f3");

		//Записываем данные из буфера в файл
		//writer->WriteData(e->Buffer, 0, e->BytesRecorded);

		/*for (int i = 0; i < e->BytesRecorded; i++) {
			dat->Add(e->Buffer[i]);
		}*/


		/*array<double>^ arr = gcnew array<double>(e->BytesRecorded);
		for (int i = 0; i < e->BytesRecorded; i++) {
			arr[i] = e->Buffer[i] / 32768.0;
		}

		double resultFreq = freqCheck.FindFundamentalFrequency(arr, 44100, 60, 440);
		labelHz->Text = resultFreq.ToString("f3");*/
	}
}

//Окончание записи
void MusicApp::MyForm::waveIn_RecordingStopped(System::Object^ sender, StoppedEventArgs^ e) {
	if (this->InvokeRequired) {
		this->BeginInvoke(gcnew EventHandler<StoppedEventArgs^>(this, &MyForm::waveIn_RecordingStopped), sender, e);
	}
	else {
		//waveIn->Dispose();

		//waveIn = NULL;
		waveIn = nullptr;
		writer->Close();
		writer = nullptr;

		//saveAudioFile();
	}
}

//Завершаем запись
void MusicApp::MyForm::StopRecording() {
	//MessageBox::Show("Stop Recording");
	waveIn->StopRecording();
}

// Фильтр шума
bool MusicApp::MyForm::ProcessData(WaveInEventArgs^ e)
{
	// Порог для вычисления наличия звука
	double porog = 0.02;
	bool result = false;
	bool Tr = false;
	double Sum2 = 0;
	int Count = e->BytesRecorded / 2;
	for (int index = 0; index < e->BytesRecorded; index += 2)
	{
		double Tmp = (short)((e->Buffer[index + 1] << 8) | e->Buffer[index + 0]);
		Tmp /= 32768.0;
		Sum2 += Tmp * Tmp;
		if (Tmp > porog)
			Tr = true;
	}
	Sum2 /= Count;
	if (Tr || Sum2 > porog)
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}