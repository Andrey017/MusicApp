#include "MusicEditForm.h"

void MusicApp::MusicEditForm::PlusFile(String^ fileName, List<String^>^ sourceFiles) {
	String^ outputFile = "./load/audio/temp/" + fileName;

	array<Byte>^ buffer = gcnew array<Byte>(1024);

	WaveFileWriter^ waveFilewriter_plus = nullptr;

	WaveFileReader^ readWaveFormat = gcnew WaveFileReader(sourceFiles[sourceFiles->Count - 1]);

	try {
		for each (String ^ sourceFile in sourceFiles)
		{
			WaveFileReader^ reader = gcnew WaveFileReader(sourceFile);

			if (waveFilewriter_plus == nullptr) {
				waveFilewriter_plus = gcnew WaveFileWriter(outputFile, readWaveFormat->WaveFormat);
			}
			else {
				if (!reader->WaveFormat->Equals(waveFilewriter_plus->WaveFormat)) {
					//MessageBox::Show("Невозможно соединить два файла");
				}
			}

			int read;
			while ((read = reader->Read(buffer, 0, buffer->Length)) > 0) {
				waveFilewriter_plus->WriteData(buffer, 0, read);
			}

			reader->Close();
		}
	}
	finally {
		if (waveFilewriter_plus != nullptr) {
			waveFilewriter_plus->Close();
			waveFilewriter_plus = nullptr;
		}
	}

	readWaveFormat->Close();
}

void MusicApp::MusicEditForm::MixWavFile(List<String^>^ files, String^ fileName) {
	List<ISampleProvider^>^ mixList = gcnew List<ISampleProvider^>();
	List<AudioFileReader^>^ desReader = gcnew List<AudioFileReader^>();

	if (files->Count < 2) {
		MessageBox::Show("Недостаточно файлов для объединения");
	}

	try {
		WaveMixerStream32^ mixer32 = gcnew WaveMixerStream32();

		mixer32->AutoStop = true;

		String^ outputFile = "./load/audio/" + fileName;

		for each (String ^ file in files)
		{
			String^ filePath = Path::Combine("./load/audio/temp/" + file);

			if (File::Exists(filePath)) {
				AudioFileReader^ reader = gcnew AudioFileReader(filePath);

				mixList->Add(reader);
				desReader->Add(reader);
			}
		}

		MixingSampleProvider^ _mixer = gcnew MixingSampleProvider(mixList);

		WaveFileWriter::CreateWaveFile16(outputFile, _mixer);

		mixList->Clear();

		for (int i = 0; i < desReader->Count; i++) {
			desReader[i]->Close();
		}
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
	}
}
