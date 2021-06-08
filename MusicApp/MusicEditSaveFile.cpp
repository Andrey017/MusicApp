#include "MusicEditForm.h"

System::Void MusicApp::MusicEditForm::pictureBox_save_music_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveAudioForm^ saveAudio = gcnew SaveAudioForm(teme);
	saveAudio->setVisiblePanel();
	saveAudio->ShowDialog();

	int check_music_or_way = saveAudio->getChech_Value();

	if (check_music_or_way != 0) {

		String^ outputFileMusic = saveAudio->getName_Audio() + ".wav";
		String^ name_creators = saveAudio->getCreators();
		bool access_in = saveAudio->getAccess();
		String^ path_pict_music = saveAudio->getPath_File();

		List<String^>^ audioList = gcnew List<String^>();
		List<int>^ audioListTime = gcnew List<int>();

		for each (WayEditorItem ^ wayEdit in Enumerable::OfType<WayEditorItem^>(panel_editor_view->Controls))
		{
			int x_position = wayEdit->Location.X;

			audioList->Add(wayEdit->getName_Way());
			audioListTime->Add(wayEdit->Location.X);
		}

		for (int i = 0; i < audioList->Count; i++) {
			if (audioListTime[i] != 0) {
				int countSilence = audioListTime[i] / 20;

				List<String^>^ audioListPlus = gcnew List<String^>();

				for (int i = 0; i < countSilence; i++) {
					audioListPlus->Add("./load/audio/temp/mix/RecordSilence.wav");
				}

				audioListPlus->Add("./load/audio/temp/" + audioList[i]);

				PlusFile("ResultPlus_" + audioList[i], audioListPlus);

				audioList[i] = "ResultPlus_" + audioList[i];
			}
		}

		MixWavFile(audioList, outputFileMusic);

		saveFileAudio(outputFileMusic, name_creators, access_in, path_pict_music, check_music_or_way);
	}
}

void MusicApp::MusicEditForm::saveFileAudio(String^ name_output_file, String^ name_creators, bool access, String^ path_picture_music, int check_music_or_way) {
	String^ link = "http://" + ip + ":8011/upload?folderNameMu=" + gl_room_id;
	String^ link_picture = "http://" + ip + ":8011/upload?folderNameMu=picture";

	NetFunction^ netFunction = gcnew NetFunction();

	netFunction->saveFile(link, "./load/audio/" + name_output_file);

	netFunction->saveFile(link_picture, path_picture_music);

	addInfoAudioFile(name_output_file, name_creators, Path::GetFileName(path_picture_music), check_music_or_way, access);
}

void MusicApp::MusicEditForm::addInfoAudioFile(String^ name_audio, String^ name_creators, String^ path_picture, int check_music_or_way, bool access_in) {
	NetFunction^ netFunction = gcnew NetFunction();

	int acc;
	String^ link;

	if (check_music_or_way != 0) {
		if (access_in) {
			acc = 1;
		}
		else {
			acc = 0;
		}

		link = "http://" + ip + ":8011/add_new_audio?name_audio=" + name_audio + "&name_creators=" + name_creators + "&id_room=" + gl_room_id + "&access=" + acc + "&path_picture=" + path_picture + "&type=1";

		String^ resultRequest = netFunction->createRequest(link);
	}
}
