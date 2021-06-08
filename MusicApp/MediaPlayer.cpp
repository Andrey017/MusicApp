#include "HomeForm.h"

using namespace System;

System::Void MusicApp::HomeForm::pictureBox_start_stop_music_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ path_pict_button;

	if (!start_audio) {
		timer_currentTime_audio->Start();
		output->Play();
		start_audio = true;

		if (teme == "1") {
			path_pict_button = "./image/icons8_pause_100px_white.png";
		}
		else {
			path_pict_button = "./image/icons8_pause_100px_black.png";
		}

		pictureBox_start_stop_music->Image = Image::FromFile(path_pict_button);
	}
	else {
		if (output != nullptr)
		{
			output->Pause();
			timer_currentTime_audio->Stop();
			start_audio = false;

			if (teme == "1") {
				path_pict_button = "./image/icons8_play_100px_white.png";
			}
			else {
				path_pict_button = "./image/icons8_play_100px_black.png";
			}

			pictureBox_start_stop_music->Image = Image::FromFile(path_pict_button);
		}
	}
}

System::Void MusicApp::HomeForm::pictureBox_music_stop_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ path_pict_button;

	panel_music->Visible = false;
	DisposeWave();

	trackBar_current_position->Value = 0;
	start_audio = false;

	if (teme == "1") {
		path_pict_button = "./image/icons8_play_100px_white.png";
	}
	else {
		path_pict_button = "./image/icons8_play_100px_black.png";
	}


	pictureBox_start_stop_music->Image = Image::FromFile(path_pict_button);
	timer_currentTime_audio->Stop();
	minute_current = 0;
	currTime = 0;
	trackBar_current_position->Value = 0;
}

System::Void MusicApp::HomeForm::guna2PictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	loadMusicFile();
}

System::Void MusicApp::HomeForm::timer_currentTime_audio_Tick(System::Object^ sender, System::EventArgs^ e) {
	trackBar_current_position->Value++;

	if (currTime >= 60) {
		minute_current++;
		currTime = 0;

		if (minute_current < 10) {
			str_minute_current = "0" + minute_current;
		}
		else {
			str_minute_current = "" + minute_current;
		}
	}
	else {
		currTime++;

		if (currTime < 10) {
			str_currTime = "0" + currTime;
		}
		else {
			str_currTime = "" + currTime;
		}
	}

	label_music_start_time->Text = "" + str_minute_current + ":" + str_currTime;

	if (trackBar_current_position->Value == trackBar_current_position->Maximum) {
		timer_currentTime_audio->Stop();
	}
}

System::Void MusicApp::HomeForm::trackBar_current_position_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int currentPosition = trackBar_current_position->Value;

	DisposeWave();

	wave = gcnew NAudio::Wave::WaveFileReader(file_music);

	wave->CurrentTime = wave->CurrentTime.Add(TimeSpan::FromSeconds(currentPosition));

	output = gcnew NAudio::Wave::DirectSoundOut();

	output->Init(gcnew NAudio::Wave::WaveChannel32(wave));
	output->Play();
	timer_currentTime_audio->Start();
}

void MusicApp::HomeForm::loadMusicFile() {
	String^ path_pict_button;
	
	DisposeWave();

	timer_currentTime_audio->Stop();
	minute_current = 0;
	currTime = 0;
	trackBar_current_position->Value = 0;

	//file_music = openFileDialog_audio_file->FileName;

	wave = gcnew NAudio::Wave::WaveFileReader(file_music);

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

	label_music_total_time->Text = totalTime;

	trackBar_current_position->Maximum = timeSpa->Seconds;

	output = gcnew NAudio::Wave::DirectSoundOut();

	output->Init(gcnew NAudio::Wave::WaveChannel32(wave));

	timer_currentTime_audio->Start();
	output->Play();
	start_audio = true;

	if (teme == "1") {
		path_pict_button = "./image/icons8_pause_100px_white.png";
	}
	else {
		path_pict_button = "./image/icons8_pause_100px_black.png";
	}

	pictureBox_start_stop_music->Image = Image::FromFile(path_pict_button);
}

void MusicApp::HomeForm::DisposeWave() {
	if (output != nullptr)
	{
		if (output->PlaybackState == NAudio::Wave::PlaybackState::Playing) output->Stop();
		//output->Dispose();
		output = nullptr;
	}
	if (wave != nullptr)
	{
		//wave->Dispose();
		wave = nullptr;
	}
}