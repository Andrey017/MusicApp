#pragma once

#include "json.hpp"

#include <cliext/vector>

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#include "CreateRoomForm.h"
#include "SaveAudioForm.h"
#include "Tabs.h"
#include "MyForm.h"

#include "MusicEditForm.h"
#include "WayEditorItem.h"
#include "SettingsStudioForm.h"

#include "RoomItem.h"
#include "ListUserItem.h"
#include "ListIconConf.h"
#include "ListAudioItem.h"

#include "NetFunction.h"

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Runtime::InteropServices;

	using namespace System::Text;

	using namespace System::Net;
	using namespace System::IO;

	using json = nlohmann::json;

	using namespace msclr::interop;

	using namespace CefSharp;
	using namespace CefSharp::WinForms;

	using namespace System::Threading;

	using namespace NAudio::Wave;
	using namespace NAudio::FileFormats;
	using namespace NAudio::CoreAudioApi;
	using namespace NAudio;

	/// <summary>
	/// Сводка для HomeForm
	/// </summary>
	public ref class HomeForm : public System::Windows::Forms::Form
	{
	public:
		HomeForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			Panel_home_start_panel->Visible = true;
			panel_home_studio->Visible = false;

			Panel_home_start_panel->Left = w_Visible;
			panel_home_studio->Left = w_Not_Visible;
		}

		HomeForm(int _user_id, String^ _name_surname, String^ _teme, String^ _name_avatar)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			label4->Visible = false;

			user_id = _user_id;
			name_surname = _name_surname;
			name_avatar = _name_avatar;

			textBox_name_surname->Text = name_surname;
			//guna2CirclePictureBox1->Image = Image::FromFile("./load/pictures/" + name_avatar);

			Panel_home_start_panel->Visible = false;
			panel_home_studio->Visible = true;

			Panel_home_start_panel->Left = w_Not_Visible;
			panel_home_studio->Left = w_Visible;

			CefSettings^ settings = gcnew CefSettings();
			settings->CefCommandLineArgs->Add("ignore-certificate-errors");
			settings->CefCommandLineArgs->Add("enable-media-stream", "enable-media-stream");

			Cef::EnableHighDPISupport();
			Cef::Initialize(settings);

			browser = gcnew ChromiumWebBrowser();
			panel_conf->Controls->Add(browser);
			panel_conf->Height = 0;

			teme = "1"; //_teme;

			if (teme == "1") {
				SetupInterface();
			}

			Load_Room();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~HomeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: int user_id;
		     String^ name_surname;
			 String^ name_avatar;

			 String^ teme;

			 String^ gl_room_id;
			 String^ gl_name_room;

			 int w_Visible = 280;
			 int w_Not_Visible = 1370;

			 String^ ip = "94.141.168.185";

			 bool record = false;

			 WaveIn^ waveIn;
			 IWaveIn^ waveIn_wasapiLoopbackCapture;
			 WaveFileWriter^ writer;
			 String^ outFileName; // = "TEST_File.wav";

			 WaveFileReader^ wave = nullptr;
			 DirectSoundOut^ output = nullptr;
			 String^ file_music;
			 bool start_audio = false;

			 int currTime = 0;
			 String^ str_currTime;
			 int minute_current = 0;
			 String^ str_minute_current = "00";

			 String^ name_creators_in;
			 bool access_in;
			 String^ path_picture_music;
			 int check_music_or_way = 0;
			 int change_one_or_more = 0;

			 int sett_sam_freq;
			 int sett_bit;
			 int sett_count_chanel;
			 double sett_thres;

			 int downButton_list = 1;

			 bool call_start = false;
			 bool video_on = false;

			 bool check_open_form_tab = false;
			 bool check_open_form_tuner = false;

			 //Для интерфейса
			 int d_r_back = 15;
			 int d_g_back = 19;
			 int d_b_back = 25;

			 int d_r_elem = 32;
			 int d_g_elem = 36;
			 int d_b_elem = 43;

			 int d_text_color = 238;

	private: ChromiumWebBrowser^ browser;


	private: Guna::UI2::WinForms::Guna2Panel^ panel_home_menu;
	private: Guna::UI2::WinForms::Guna2Button^ button_home_menu_home;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button1;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button2;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button3;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button4;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button6;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button5;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox1;
	private: Guna::UI2::WinForms::Guna2Button^ button_exit;



	private: Guna::UI2::WinForms::Guna2Panel^ Panel_home_start_panel;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel3;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_home_studio;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_studio_conf;


	private: System::Windows::Forms::Label^ label4;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_studio_room;



	private: Guna::UI2::WinForms::Guna2Panel^ panel_studio_users;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_conf;
	private: System::Windows::Forms::Label^ label_conf_name_room;




	private: System::Windows::Forms::TextBox^ textBox_name_surname;
	private: System::Windows::Forms::FlowLayoutPanel^ panel_item_room;
	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_add_room;

	private: Guna::UI2::WinForms::Guna2ImageButton^ guna2ImageButton1;
private: Guna::UI2::WinForms::Guna2ImageButton^ button_add_new_user;

private: Guna::UI2::WinForms::Guna2ImageButton^ button_conf_start_call;

private: Guna::UI2::WinForms::Guna2TextBox^ textBox_add_new_user_room;
private: System::Windows::Forms::FlowLayoutPanel^ panel_list_user_rom;
private: Guna::UI2::WinForms::Guna2ImageButton^ button_record;
private: Guna::UI2::WinForms::Guna2Panel^ panel_music;

private: Guna::UI2::WinForms::Guna2TrackBar^ trackBar_current_position;

private: System::Windows::Forms::Label^ label_music_start_time;
private: System::Windows::Forms::Label^ label_music_total_time;
private: Guna::UI2::WinForms::Guna2Panel^ panel_music_controls;



private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_start_stop_music;
private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_music_stop;
private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
private: System::Windows::Forms::OpenFileDialog^ openFileDialog_audio_file;
private: System::Windows::Forms::Timer^ timer_currentTime_audio;
private: Guna::UI2::WinForms::Guna2Panel^ panel_library;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel_library_item_audio;
private: System::Windows::Forms::Label^ label_name_creator_audio_play;


private: System::Windows::Forms::Label^ label_name_audio_play;
private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_audio_play;

private: Guna::UI2::WinForms::Guna2Button^ button_load_list_way;

private: Guna::UI2::WinForms::Guna2Button^ button_load_list_music;
private: System::Windows::Forms::Label^ label_nothing_1;
private: System::Windows::Forms::Label^ label_nothing_2;
private: Guna::UI2::WinForms::Guna2Panel^ panel_tab;
private: Guna::UI2::WinForms::Guna2Panel^ panel_tab_tab;
private: Guna::UI2::WinForms::Guna2ImageButton^ button_open_tab;
private: Guna::UI2::WinForms::Guna2ImageButton^ button_on_off_camera;
private: Guna::UI2::WinForms::Guna2ImageButton^ button_settings_conf;













private: System::ComponentModel::IContainer^ components;












	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomeForm::typeid));
			this->panel_home_menu = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Button6 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button5 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button4 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button3 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button2 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Button1 = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->button_home_menu_home = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->Panel_home_start_panel = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel3 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->label_nothing_2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel_ = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->label_nothing_1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->textBox_name_surname = (gcnew System::Windows::Forms::TextBox());
			this->button_exit = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2CirclePictureBox1 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->panel_home_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->panel_studio_conf = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->panel_tab = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->panel_tab_tab = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->button_open_tab = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->panel_studio_users = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->button_settings_conf = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->button_on_off_camera = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->button_record = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->panel_list_user_rom = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox_add_new_user_room = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->button_add_new_user = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->button_conf_start_call = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->label_conf_name_room = (gcnew System::Windows::Forms::Label());
			this->panel_conf = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel_studio_room = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->textBox_add_room = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2ImageButton1 = (gcnew Guna::UI2::WinForms::Guna2ImageButton());
			this->panel_item_room = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel_music = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->label_name_creator_audio_play = (gcnew System::Windows::Forms::Label());
			this->label_name_audio_play = (gcnew System::Windows::Forms::Label());
			this->pictureBox_audio_play = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->panel_music_controls = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->pictureBox_music_stop = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->pictureBox_start_stop_music = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_music_total_time = (gcnew System::Windows::Forms::Label());
			this->trackBar_current_position = (gcnew Guna::UI2::WinForms::Guna2TrackBar());
			this->label_music_start_time = (gcnew System::Windows::Forms::Label());
			this->openFileDialog_audio_file = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer_currentTime_audio = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel_library = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->button_load_list_way = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->button_load_list_music = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->flowLayoutPanel_library_item_audio = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel_home_menu->SuspendLayout();
			this->Panel_home_start_panel->SuspendLayout();
			this->guna2Panel3->SuspendLayout();
			this->panel_->SuspendLayout();
			this->guna2Panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox1))->BeginInit();
			this->panel_home_studio->SuspendLayout();
			this->panel_studio_conf->SuspendLayout();
			this->panel_tab->SuspendLayout();
			this->panel_studio_users->SuspendLayout();
			this->panel_studio_room->SuspendLayout();
			this->panel_music->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_audio_play))->BeginInit();
			this->panel_music_controls->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_music_stop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_start_stop_music))->BeginInit();
			this->panel_library->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_home_menu
			// 
			this->panel_home_menu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel_home_menu->BackColor = System::Drawing::Color::White;
			this->panel_home_menu->Controls->Add(this->guna2Button6);
			this->panel_home_menu->Controls->Add(this->guna2Button5);
			this->panel_home_menu->Controls->Add(this->guna2Button4);
			this->panel_home_menu->Controls->Add(this->guna2Button3);
			this->panel_home_menu->Controls->Add(this->guna2Button2);
			this->panel_home_menu->Controls->Add(this->guna2Button1);
			this->panel_home_menu->Controls->Add(this->button_home_menu_home);
			this->panel_home_menu->Location = System::Drawing::Point(0, 0);
			this->panel_home_menu->Name = L"panel_home_menu";
			this->panel_home_menu->ShadowDecoration->Parent = this->panel_home_menu;
			this->panel_home_menu->Size = System::Drawing::Size(276, 764);
			this->panel_home_menu->TabIndex = 0;
			// 
			// guna2Button6
			// 
			this->guna2Button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Button6->Animated = true;
			this->guna2Button6->CheckedState->Parent = this->guna2Button6;
			this->guna2Button6->CustomImages->Parent = this->guna2Button6;
			this->guna2Button6->FillColor = System::Drawing::Color::White;
			this->guna2Button6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button6->ForeColor = System::Drawing::Color::Black;
			this->guna2Button6->HoverState->Parent = this->guna2Button6;
			this->guna2Button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button6.Image")));
			this->guna2Button6->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->guna2Button6->ImageSize = System::Drawing::Size(30, 30);
			this->guna2Button6->Location = System::Drawing::Point(0, 321);
			this->guna2Button6->Name = L"guna2Button6";
			this->guna2Button6->ShadowDecoration->Parent = this->guna2Button6;
			this->guna2Button6->Size = System::Drawing::Size(276, 45);
			this->guna2Button6->TabIndex = 7;
			this->guna2Button6->Text = L"Тюнер";
			this->guna2Button6->Click += gcnew System::EventHandler(this, &HomeForm::guna2Button6_Click);
			// 
			// guna2Button5
			// 
			this->guna2Button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Button5->Animated = true;
			this->guna2Button5->CheckedState->Parent = this->guna2Button5;
			this->guna2Button5->CustomImages->Parent = this->guna2Button5;
			this->guna2Button5->FillColor = System::Drawing::Color::White;
			this->guna2Button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button5->ForeColor = System::Drawing::Color::Black;
			this->guna2Button5->HoverState->Parent = this->guna2Button5;
			this->guna2Button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button5.Image")));
			this->guna2Button5->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->guna2Button5->ImageSize = System::Drawing::Size(30, 30);
			this->guna2Button5->Location = System::Drawing::Point(0, 270);
			this->guna2Button5->Name = L"guna2Button5";
			this->guna2Button5->ShadowDecoration->Parent = this->guna2Button5;
			this->guna2Button5->Size = System::Drawing::Size(276, 45);
			this->guna2Button5->TabIndex = 6;
			this->guna2Button5->Text = L"Редактор";
			this->guna2Button5->Click += gcnew System::EventHandler(this, &HomeForm::guna2Button5_Click);
			// 
			// guna2Button4
			// 
			this->guna2Button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Button4->Animated = true;
			this->guna2Button4->CheckedState->Parent = this->guna2Button4;
			this->guna2Button4->CustomImages->Parent = this->guna2Button4;
			this->guna2Button4->FillColor = System::Drawing::Color::White;
			this->guna2Button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button4->ForeColor = System::Drawing::Color::Black;
			this->guna2Button4->HoverState->Parent = this->guna2Button4;
			this->guna2Button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button4.Image")));
			this->guna2Button4->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->guna2Button4->ImageSize = System::Drawing::Size(30, 30);
			this->guna2Button4->Location = System::Drawing::Point(0, 219);
			this->guna2Button4->Name = L"guna2Button4";
			this->guna2Button4->ShadowDecoration->Parent = this->guna2Button4;
			this->guna2Button4->Size = System::Drawing::Size(276, 45);
			this->guna2Button4->TabIndex = 5;
			this->guna2Button4->Text = L"Табулатура";
			this->guna2Button4->Click += gcnew System::EventHandler(this, &HomeForm::guna2Button4_Click);
			// 
			// guna2Button3
			// 
			this->guna2Button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Button3->Animated = true;
			this->guna2Button3->CheckedState->Parent = this->guna2Button3;
			this->guna2Button3->CustomImages->Parent = this->guna2Button3;
			this->guna2Button3->FillColor = System::Drawing::Color::White;
			this->guna2Button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button3->ForeColor = System::Drawing::Color::Black;
			this->guna2Button3->HoverState->Parent = this->guna2Button3;
			this->guna2Button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button3.Image")));
			this->guna2Button3->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->guna2Button3->ImageSize = System::Drawing::Size(30, 30);
			this->guna2Button3->Location = System::Drawing::Point(0, 168);
			this->guna2Button3->Name = L"guna2Button3";
			this->guna2Button3->ShadowDecoration->Parent = this->guna2Button3;
			this->guna2Button3->Size = System::Drawing::Size(276, 45);
			this->guna2Button3->TabIndex = 4;
			this->guna2Button3->Text = L"Студия";
			this->guna2Button3->Click += gcnew System::EventHandler(this, &HomeForm::guna2Button3_Click);
			// 
			// guna2Button2
			// 
			this->guna2Button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Button2->Animated = true;
			this->guna2Button2->CheckedState->Parent = this->guna2Button2;
			this->guna2Button2->CustomImages->Parent = this->guna2Button2;
			this->guna2Button2->FillColor = System::Drawing::Color::White;
			this->guna2Button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button2->ForeColor = System::Drawing::Color::Black;
			this->guna2Button2->HoverState->Parent = this->guna2Button2;
			this->guna2Button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button2.Image")));
			this->guna2Button2->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->guna2Button2->ImageSize = System::Drawing::Size(30, 30);
			this->guna2Button2->Location = System::Drawing::Point(0, 96);
			this->guna2Button2->Name = L"guna2Button2";
			this->guna2Button2->ShadowDecoration->Parent = this->guna2Button2;
			this->guna2Button2->Size = System::Drawing::Size(276, 45);
			this->guna2Button2->TabIndex = 3;
			this->guna2Button2->Text = L"Библиотека";
			this->guna2Button2->Click += gcnew System::EventHandler(this, &HomeForm::guna2Button2_Click);
			// 
			// guna2Button1
			// 
			this->guna2Button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Button1->Animated = true;
			this->guna2Button1->CheckedState->Parent = this->guna2Button1;
			this->guna2Button1->CustomImages->Parent = this->guna2Button1;
			this->guna2Button1->FillColor = System::Drawing::Color::White;
			this->guna2Button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->guna2Button1->ForeColor = System::Drawing::Color::Black;
			this->guna2Button1->HoverState->Parent = this->guna2Button1;
			this->guna2Button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2Button1.Image")));
			this->guna2Button1->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->guna2Button1->ImageSize = System::Drawing::Size(30, 30);
			this->guna2Button1->Location = System::Drawing::Point(0, 529);
			this->guna2Button1->Name = L"guna2Button1";
			this->guna2Button1->ShadowDecoration->Parent = this->guna2Button1;
			this->guna2Button1->Size = System::Drawing::Size(276, 45);
			this->guna2Button1->TabIndex = 2;
			this->guna2Button1->Text = L"Поиск";
			this->guna2Button1->Visible = false;
			// 
			// button_home_menu_home
			// 
			this->button_home_menu_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_home_menu_home->Animated = true;
			this->button_home_menu_home->CheckedState->Parent = this->button_home_menu_home;
			this->button_home_menu_home->CustomImages->Parent = this->button_home_menu_home;
			this->button_home_menu_home->FillColor = System::Drawing::Color::White;
			this->button_home_menu_home->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button_home_menu_home->ForeColor = System::Drawing::Color::Black;
			this->button_home_menu_home->HoverState->Parent = this->button_home_menu_home;
			this->button_home_menu_home->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_home_menu_home.Image")));
			this->button_home_menu_home->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->button_home_menu_home->ImageSize = System::Drawing::Size(30, 30);
			this->button_home_menu_home->Location = System::Drawing::Point(0, 478);
			this->button_home_menu_home->Name = L"button_home_menu_home";
			this->button_home_menu_home->ShadowDecoration->Parent = this->button_home_menu_home;
			this->button_home_menu_home->Size = System::Drawing::Size(276, 45);
			this->button_home_menu_home->TabIndex = 1;
			this->button_home_menu_home->Text = L"Главная";
			this->button_home_menu_home->Visible = false;
			this->button_home_menu_home->Click += gcnew System::EventHandler(this, &HomeForm::button_home_menu_home_Click);
			// 
			// Panel_home_start_panel
			// 
			this->Panel_home_start_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Panel_home_start_panel->Controls->Add(this->guna2Panel3);
			this->Panel_home_start_panel->Controls->Add(this->panel_);
			this->Panel_home_start_panel->Location = System::Drawing::Point(1370, 60);
			this->Panel_home_start_panel->Name = L"Panel_home_start_panel";
			this->Panel_home_start_panel->ShadowDecoration->Parent = this->Panel_home_start_panel;
			this->Panel_home_start_panel->Size = System::Drawing::Size(1273, 706);
			this->Panel_home_start_panel->TabIndex = 0;
			// 
			// guna2Panel3
			// 
			this->guna2Panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->guna2Panel3->AutoSize = true;
			this->guna2Panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->guna2Panel3->Controls->Add(this->label_nothing_2);
			this->guna2Panel3->Controls->Add(this->label3);
			this->guna2Panel3->Location = System::Drawing::Point(3, 325);
			this->guna2Panel3->Name = L"guna2Panel3";
			this->guna2Panel3->ShadowDecoration->Parent = this->guna2Panel3;
			this->guna2Panel3->Size = System::Drawing::Size(912, 307);
			this->guna2Panel3->TabIndex = 0;
			// 
			// label_nothing_2
			// 
			this->label_nothing_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label_nothing_2->AutoSize = true;
			this->label_nothing_2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_nothing_2->Location = System::Drawing::Point(323, 174);
			this->label_nothing_2->Name = L"label_nothing_2";
			this->label_nothing_2->Size = System::Drawing::Size(224, 25);
			this->label_nothing_2->TabIndex = 11;
			this->label_nothing_2->Text = L"Здесь пока ничего нет ...";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(336, 41);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Популярные альбомы";
			// 
			// panel_
			// 
			this->panel_->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->panel_->AutoSize = true;
			this->panel_->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->panel_->Controls->Add(this->label_nothing_1);
			this->panel_->Controls->Add(this->label2);
			this->panel_->Location = System::Drawing::Point(3, 8);
			this->panel_->Name = L"panel_";
			this->panel_->ShadowDecoration->Parent = this->panel_;
			this->panel_->Size = System::Drawing::Size(912, 311);
			this->panel_->TabIndex = 0;
			// 
			// label_nothing_1
			// 
			this->label_nothing_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label_nothing_1->AutoSize = true;
			this->label_nothing_1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_nothing_1->Location = System::Drawing::Point(323, 132);
			this->label_nothing_1->Name = L"label_nothing_1";
			this->label_nothing_1->Size = System::Drawing::Size(224, 25);
			this->label_nothing_1->TabIndex = 10;
			this->label_nothing_1->Text = L"Здесь пока ничего нет ...";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 41);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Популярное";
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2Panel1->BackColor = System::Drawing::Color::White;
			this->guna2Panel1->Controls->Add(this->textBox_name_surname);
			this->guna2Panel1->Controls->Add(this->button_exit);
			this->guna2Panel1->Controls->Add(this->guna2CirclePictureBox1);
			this->guna2Panel1->Location = System::Drawing::Point(0, 0);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->ShadowDecoration->Parent = this->guna2Panel1;
			this->guna2Panel1->Size = System::Drawing::Size(1815, 55);
			this->guna2Panel1->TabIndex = 1;
			// 
			// textBox_name_surname
			// 
			this->textBox_name_surname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_name_surname->BackColor = System::Drawing::Color::White;
			this->textBox_name_surname->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_name_surname->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_name_surname->Location = System::Drawing::Point(659, 15);
			this->textBox_name_surname->Name = L"textBox_name_surname";
			this->textBox_name_surname->ReadOnly = true;
			this->textBox_name_surname->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->textBox_name_surname->Size = System::Drawing::Size(793, 23);
			this->textBox_name_surname->TabIndex = 10;
			this->textBox_name_surname->TabStop = false;
			this->textBox_name_surname->Text = L"name surname";
			// 
			// button_exit
			// 
			this->button_exit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_exit->Animated = true;
			this->button_exit->CheckedState->Parent = this->button_exit;
			this->button_exit->CustomImages->Parent = this->button_exit;
			this->button_exit->FillColor = System::Drawing::Color::White;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button_exit->ForeColor = System::Drawing::Color::Black;
			this->button_exit->HoverState->Parent = this->button_exit;
			this->button_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.Image")));
			this->button_exit->ImageAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->button_exit->ImageSize = System::Drawing::Size(30, 30);
			this->button_exit->Location = System::Drawing::Point(1499, 4);
			this->button_exit->Name = L"button_exit";
			this->button_exit->ShadowDecoration->Parent = this->button_exit;
			this->button_exit->Size = System::Drawing::Size(48, 45);
			this->button_exit->TabIndex = 9;
			this->button_exit->Click += gcnew System::EventHandler(this, &HomeForm::button_exit_Click);
			// 
			// guna2CirclePictureBox1
			// 
			this->guna2CirclePictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2CirclePictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox1.Image")));
			this->guna2CirclePictureBox1->Location = System::Drawing::Point(1458, 9);
			this->guna2CirclePictureBox1->Name = L"guna2CirclePictureBox1";
			this->guna2CirclePictureBox1->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox1->ShadowDecoration->Parent = this->guna2CirclePictureBox1;
			this->guna2CirclePictureBox1->Size = System::Drawing::Size(36, 36);
			this->guna2CirclePictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox1->TabIndex = 0;
			this->guna2CirclePictureBox1->TabStop = false;
			// 
			// panel_home_studio
			// 
			this->panel_home_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_home_studio->Controls->Add(this->panel_studio_conf);
			this->panel_home_studio->Controls->Add(this->panel_studio_room);
			this->panel_home_studio->Location = System::Drawing::Point(280, 60);
			this->panel_home_studio->Name = L"panel_home_studio";
			this->panel_home_studio->ShadowDecoration->Parent = this->panel_home_studio;
			this->panel_home_studio->Size = System::Drawing::Size(1272, 706);
			this->panel_home_studio->TabIndex = 1;
			this->panel_home_studio->Visible = false;
			// 
			// panel_studio_conf
			// 
			this->panel_studio_conf->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_studio_conf->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->panel_studio_conf->Controls->Add(this->panel_tab);
			this->panel_studio_conf->Controls->Add(this->panel_studio_users);
			this->panel_studio_conf->Controls->Add(this->panel_conf);
			this->panel_studio_conf->Controls->Add(this->label4);
			this->panel_studio_conf->Location = System::Drawing::Point(412, 10);
			this->panel_studio_conf->Name = L"panel_studio_conf";
			this->panel_studio_conf->ShadowDecoration->Parent = this->panel_studio_conf;
			this->panel_studio_conf->Size = System::Drawing::Size(857, 687);
			this->panel_studio_conf->TabIndex = 10;
			this->panel_studio_conf->Visible = false;
			// 
			// panel_tab
			// 
			this->panel_tab->Controls->Add(this->panel_tab_tab);
			this->panel_tab->Controls->Add(this->button_open_tab);
			this->panel_tab->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_tab->Location = System::Drawing::Point(0, 400);
			this->panel_tab->Name = L"panel_tab";
			this->panel_tab->ShadowDecoration->Parent = this->panel_tab;
			this->panel_tab->Size = System::Drawing::Size(528, 287);
			this->panel_tab->TabIndex = 13;
			// 
			// panel_tab_tab
			// 
			this->panel_tab_tab->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_tab_tab->Location = System::Drawing::Point(0, 47);
			this->panel_tab_tab->Name = L"panel_tab_tab";
			this->panel_tab_tab->ShadowDecoration->Parent = this->panel_tab_tab;
			this->panel_tab_tab->Size = System::Drawing::Size(528, 240);
			this->panel_tab_tab->TabIndex = 19;
			// 
			// button_open_tab
			// 
			this->button_open_tab->CheckedState->Parent = this->button_open_tab;
			this->button_open_tab->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->button_open_tab->HoverState->Parent = this->button_open_tab;
			this->button_open_tab->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_open_tab.Image")));
			this->button_open_tab->ImageSize = System::Drawing::Size(30, 30);
			this->button_open_tab->Location = System::Drawing::Point(10, 8);
			this->button_open_tab->Name = L"button_open_tab";
			this->button_open_tab->PressedState->Parent = this->button_open_tab;
			this->button_open_tab->Size = System::Drawing::Size(36, 36);
			this->button_open_tab->TabIndex = 18;
			// 
			// panel_studio_users
			// 
			this->panel_studio_users->BackColor = System::Drawing::Color::White;
			this->panel_studio_users->Controls->Add(this->button_settings_conf);
			this->panel_studio_users->Controls->Add(this->button_on_off_camera);
			this->panel_studio_users->Controls->Add(this->button_record);
			this->panel_studio_users->Controls->Add(this->panel_list_user_rom);
			this->panel_studio_users->Controls->Add(this->textBox_add_new_user_room);
			this->panel_studio_users->Controls->Add(this->button_add_new_user);
			this->panel_studio_users->Controls->Add(this->button_conf_start_call);
			this->panel_studio_users->Controls->Add(this->label_conf_name_room);
			this->panel_studio_users->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel_studio_users->Location = System::Drawing::Point(528, 400);
			this->panel_studio_users->Name = L"panel_studio_users";
			this->panel_studio_users->ShadowDecoration->Parent = this->panel_studio_users;
			this->panel_studio_users->Size = System::Drawing::Size(329, 287);
			this->panel_studio_users->TabIndex = 12;
			// 
			// button_settings_conf
			// 
			this->button_settings_conf->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_settings_conf->CheckedState->Parent = this->button_settings_conf;
			this->button_settings_conf->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->button_settings_conf->HoverState->Parent = this->button_settings_conf;
			this->button_settings_conf->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_settings_conf.Image")));
			this->button_settings_conf->ImageSize = System::Drawing::Size(30, 30);
			this->button_settings_conf->Location = System::Drawing::Point(242, 44);
			this->button_settings_conf->Name = L"button_settings_conf";
			this->button_settings_conf->PressedState->Parent = this->button_settings_conf;
			this->button_settings_conf->Size = System::Drawing::Size(36, 36);
			this->button_settings_conf->TabIndex = 19;
			this->button_settings_conf->Click += gcnew System::EventHandler(this, &HomeForm::button_settings_conf_Click);
			// 
			// button_on_off_camera
			// 
			this->button_on_off_camera->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_on_off_camera->CheckedState->Parent = this->button_on_off_camera;
			this->button_on_off_camera->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->button_on_off_camera->HoverState->Parent = this->button_on_off_camera;
			this->button_on_off_camera->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_on_off_camera.Image")));
			this->button_on_off_camera->ImageSize = System::Drawing::Size(30, 30);
			this->button_on_off_camera->Location = System::Drawing::Point(126, 44);
			this->button_on_off_camera->Name = L"button_on_off_camera";
			this->button_on_off_camera->PressedState->Parent = this->button_on_off_camera;
			this->button_on_off_camera->Size = System::Drawing::Size(36, 36);
			this->button_on_off_camera->TabIndex = 18;
			this->button_on_off_camera->Click += gcnew System::EventHandler(this, &HomeForm::button_on_off_camera_Click);
			// 
			// button_record
			// 
			this->button_record->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_record->CheckedState->Parent = this->button_record;
			this->button_record->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->button_record->HoverState->Parent = this->button_record;
			this->button_record->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_record.Image")));
			this->button_record->ImageSize = System::Drawing::Size(30, 30);
			this->button_record->Location = System::Drawing::Point(6, 44);
			this->button_record->Name = L"button_record";
			this->button_record->PressedState->Parent = this->button_record;
			this->button_record->Size = System::Drawing::Size(36, 36);
			this->button_record->TabIndex = 17;
			this->button_record->Click += gcnew System::EventHandler(this, &HomeForm::button_record_Click);
			// 
			// panel_list_user_rom
			// 
			this->panel_list_user_rom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_list_user_rom->AutoScroll = true;
			this->panel_list_user_rom->BackColor = System::Drawing::Color::White;
			this->panel_list_user_rom->Location = System::Drawing::Point(6, 140);
			this->panel_list_user_rom->Name = L"panel_list_user_rom";
			this->panel_list_user_rom->Size = System::Drawing::Size(321, 144);
			this->panel_list_user_rom->TabIndex = 16;
			// 
			// textBox_add_new_user_room
			// 
			this->textBox_add_new_user_room->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_add_new_user_room->BorderRadius = 8;
			this->textBox_add_new_user_room->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_add_new_user_room->DefaultText = L"";
			this->textBox_add_new_user_room->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_add_new_user_room->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_add_new_user_room->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_add_new_user_room->DisabledState->Parent = this->textBox_add_new_user_room;
			this->textBox_add_new_user_room->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_add_new_user_room->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_add_new_user_room->FocusedState->Parent = this->textBox_add_new_user_room;
			this->textBox_add_new_user_room->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_add_new_user_room->HoverState->Parent = this->textBox_add_new_user_room;
			this->textBox_add_new_user_room->Location = System::Drawing::Point(6, 89);
			this->textBox_add_new_user_room->Margin = System::Windows::Forms::Padding(6);
			this->textBox_add_new_user_room->Name = L"textBox_add_new_user_room";
			this->textBox_add_new_user_room->PasswordChar = '\0';
			this->textBox_add_new_user_room->PlaceholderText = L"";
			this->textBox_add_new_user_room->SelectedText = L"";
			this->textBox_add_new_user_room->ShadowDecoration->Parent = this->textBox_add_new_user_room;
			this->textBox_add_new_user_room->Size = System::Drawing::Size(317, 42);
			this->textBox_add_new_user_room->TabIndex = 13;
			// 
			// button_add_new_user
			// 
			this->button_add_new_user->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_add_new_user->CheckedState->Parent = this->button_add_new_user;
			this->button_add_new_user->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->button_add_new_user->HoverState->Parent = this->button_add_new_user;
			this->button_add_new_user->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_add_new_user.Image")));
			this->button_add_new_user->ImageSize = System::Drawing::Size(30, 30);
			this->button_add_new_user->Location = System::Drawing::Point(284, 44);
			this->button_add_new_user->Name = L"button_add_new_user";
			this->button_add_new_user->PressedState->Parent = this->button_add_new_user;
			this->button_add_new_user->Size = System::Drawing::Size(36, 36);
			this->button_add_new_user->TabIndex = 14;
			this->button_add_new_user->Click += gcnew System::EventHandler(this, &HomeForm::button_add_new_user_Click);
			// 
			// button_conf_start_call
			// 
			this->button_conf_start_call->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button_conf_start_call->CheckedState->Parent = this->button_conf_start_call;
			this->button_conf_start_call->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->button_conf_start_call->HoverState->Parent = this->button_conf_start_call;
			this->button_conf_start_call->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_conf_start_call.Image")));
			this->button_conf_start_call->ImageSize = System::Drawing::Size(30, 30);
			this->button_conf_start_call->Location = System::Drawing::Point(179, 44);
			this->button_conf_start_call->Name = L"button_conf_start_call";
			this->button_conf_start_call->PressedState->Parent = this->button_conf_start_call;
			this->button_conf_start_call->Size = System::Drawing::Size(36, 36);
			this->button_conf_start_call->TabIndex = 13;
			this->button_conf_start_call->Click += gcnew System::EventHandler(this, &HomeForm::button_conf_start_call_Click);
			// 
			// label_conf_name_room
			// 
			this->label_conf_name_room->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_conf_name_room->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_conf_name_room->Location = System::Drawing::Point(0, 0);
			this->label_conf_name_room->Name = L"label_conf_name_room";
			this->label_conf_name_room->Size = System::Drawing::Size(329, 41);
			this->label_conf_name_room->TabIndex = 13;
			this->label_conf_name_room->Text = L"Name_room";
			this->label_conf_name_room->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_conf
			// 
			this->panel_conf->BackColor = System::Drawing::Color::Yellow;
			this->panel_conf->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_conf->Location = System::Drawing::Point(0, 0);
			this->panel_conf->Name = L"panel_conf";
			this->panel_conf->ShadowDecoration->Parent = this->panel_conf;
			this->panel_conf->Size = System::Drawing::Size(857, 400);
			this->panel_conf->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(3, 2);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 41);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Студия";
			// 
			// panel_studio_room
			// 
			this->panel_studio_room->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel_studio_room->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->panel_studio_room->Controls->Add(this->textBox_add_room);
			this->panel_studio_room->Controls->Add(this->guna2ImageButton1);
			this->panel_studio_room->Controls->Add(this->panel_item_room);
			this->panel_studio_room->Location = System::Drawing::Point(3, 8);
			this->panel_studio_room->Name = L"panel_studio_room";
			this->panel_studio_room->ShadowDecoration->Parent = this->panel_studio_room;
			this->panel_studio_room->Size = System::Drawing::Size(406, 693);
			this->panel_studio_room->TabIndex = 0;
			// 
			// textBox_add_room
			// 
			this->textBox_add_room->BorderRadius = 8;
			this->textBox_add_room->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_add_room->DefaultText = L"";
			this->textBox_add_room->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_add_room->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_add_room->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_add_room->DisabledState->Parent = this->textBox_add_room;
			this->textBox_add_room->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_add_room->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_add_room->FocusedState->Parent = this->textBox_add_room;
			this->textBox_add_room->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_add_room->HoverState->Parent = this->textBox_add_room;
			this->textBox_add_room->Location = System::Drawing::Point(73, 6);
			this->textBox_add_room->Margin = System::Windows::Forms::Padding(5);
			this->textBox_add_room->Name = L"textBox_add_room";
			this->textBox_add_room->PasswordChar = '\0';
			this->textBox_add_room->PlaceholderText = L"";
			this->textBox_add_room->SelectedText = L"";
			this->textBox_add_room->ShadowDecoration->Parent = this->textBox_add_room;
			this->textBox_add_room->Size = System::Drawing::Size(330, 34);
			this->textBox_add_room->TabIndex = 12;
			this->textBox_add_room->Visible = false;
			// 
			// guna2ImageButton1
			// 
			this->guna2ImageButton1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2ImageButton1->CheckedState->Parent = this->guna2ImageButton1;
			this->guna2ImageButton1->HoverState->ImageSize = System::Drawing::Size(30, 30);
			this->guna2ImageButton1->HoverState->Parent = this->guna2ImageButton1;
			this->guna2ImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2ImageButton1.Image")));
			this->guna2ImageButton1->ImageSize = System::Drawing::Size(30, 30);
			this->guna2ImageButton1->Location = System::Drawing::Point(3, 6);
			this->guna2ImageButton1->Name = L"guna2ImageButton1";
			this->guna2ImageButton1->PressedState->Parent = this->guna2ImageButton1;
			this->guna2ImageButton1->Size = System::Drawing::Size(42, 39);
			this->guna2ImageButton1->TabIndex = 11;
			this->guna2ImageButton1->Click += gcnew System::EventHandler(this, &HomeForm::guna2ImageButton1_Click);
			// 
			// panel_item_room
			// 
			this->panel_item_room->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel_item_room->AutoScroll = true;
			this->panel_item_room->Location = System::Drawing::Point(3, 46);
			this->panel_item_room->Name = L"panel_item_room";
			this->panel_item_room->Size = System::Drawing::Size(400, 643);
			this->panel_item_room->TabIndex = 0;
			// 
			// panel_music
			// 
			this->panel_music->BackColor = System::Drawing::Color::White;
			this->panel_music->Controls->Add(this->label_name_creator_audio_play);
			this->panel_music->Controls->Add(this->label_name_audio_play);
			this->panel_music->Controls->Add(this->pictureBox_audio_play);
			this->panel_music->Controls->Add(this->panel_music_controls);
			this->panel_music->Controls->Add(this->label_music_total_time);
			this->panel_music->Controls->Add(this->trackBar_current_position);
			this->panel_music->Controls->Add(this->label_music_start_time);
			this->panel_music->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_music->Location = System::Drawing::Point(0, 666);
			this->panel_music->Name = L"panel_music";
			this->panel_music->ShadowDecoration->Parent = this->panel_music;
			this->panel_music->Size = System::Drawing::Size(1552, 100);
			this->panel_music->TabIndex = 2;
			this->panel_music->Visible = false;
			// 
			// label_name_creator_audio_play
			// 
			this->label_name_creator_audio_play->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_name_creator_audio_play->AutoSize = true;
			this->label_name_creator_audio_play->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_name_creator_audio_play->Location = System::Drawing::Point(96, 70);
			this->label_name_creator_audio_play->Name = L"label_name_creator_audio_play";
			this->label_name_creator_audio_play->Size = System::Drawing::Size(55, 23);
			this->label_name_creator_audio_play->TabIndex = 6;
			this->label_name_creator_audio_play->Text = L"label2";
			// 
			// label_name_audio_play
			// 
			this->label_name_audio_play->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_name_audio_play->AutoSize = true;
			this->label_name_audio_play->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_audio_play->Location = System::Drawing::Point(93, 34);
			this->label_name_audio_play->Name = L"label_name_audio_play";
			this->label_name_audio_play->Size = System::Drawing::Size(65, 28);
			this->label_name_audio_play->TabIndex = 5;
			this->label_name_audio_play->Text = L"label1";
			// 
			// pictureBox_audio_play
			// 
			this->pictureBox_audio_play->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pictureBox_audio_play->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_audio_play.Image")));
			this->pictureBox_audio_play->Location = System::Drawing::Point(18, 35);
			this->pictureBox_audio_play->Name = L"pictureBox_audio_play";
			this->pictureBox_audio_play->ShadowDecoration->Parent = this->pictureBox_audio_play;
			this->pictureBox_audio_play->Size = System::Drawing::Size(60, 60);
			this->pictureBox_audio_play->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_audio_play->TabIndex = 4;
			this->pictureBox_audio_play->TabStop = false;
			// 
			// panel_music_controls
			// 
			this->panel_music_controls->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel_music_controls->BackColor = System::Drawing::Color::White;
			this->panel_music_controls->Controls->Add(this->guna2PictureBox1);
			this->panel_music_controls->Controls->Add(this->pictureBox_music_stop);
			this->panel_music_controls->Controls->Add(this->pictureBox_start_stop_music);
			this->panel_music_controls->Location = System::Drawing::Point(652, 40);
			this->panel_music_controls->Name = L"panel_music_controls";
			this->panel_music_controls->ShadowDecoration->Parent = this->panel_music_controls;
			this->panel_music_controls->Size = System::Drawing::Size(241, 51);
			this->panel_music_controls->TabIndex = 3;
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->BackColor = System::Drawing::Color::White;
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->Location = System::Drawing::Point(26, 3);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(45, 45);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2PictureBox1->TabIndex = 2;
			this->guna2PictureBox1->TabStop = false;
			this->guna2PictureBox1->Click += gcnew System::EventHandler(this, &HomeForm::guna2PictureBox1_Click);
			// 
			// pictureBox_music_stop
			// 
			this->pictureBox_music_stop->BackColor = System::Drawing::Color::White;
			this->pictureBox_music_stop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_music_stop.Image")));
			this->pictureBox_music_stop->Location = System::Drawing::Point(171, 3);
			this->pictureBox_music_stop->Name = L"pictureBox_music_stop";
			this->pictureBox_music_stop->ShadowDecoration->Parent = this->pictureBox_music_stop;
			this->pictureBox_music_stop->Size = System::Drawing::Size(45, 45);
			this->pictureBox_music_stop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_music_stop->TabIndex = 1;
			this->pictureBox_music_stop->TabStop = false;
			this->pictureBox_music_stop->Click += gcnew System::EventHandler(this, &HomeForm::pictureBox_music_stop_Click);
			// 
			// pictureBox_start_stop_music
			// 
			this->pictureBox_start_stop_music->BackColor = System::Drawing::Color::White;
			this->pictureBox_start_stop_music->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_start_stop_music.Image")));
			this->pictureBox_start_stop_music->Location = System::Drawing::Point(99, 3);
			this->pictureBox_start_stop_music->Name = L"pictureBox_start_stop_music";
			this->pictureBox_start_stop_music->ShadowDecoration->Parent = this->pictureBox_start_stop_music;
			this->pictureBox_start_stop_music->Size = System::Drawing::Size(45, 45);
			this->pictureBox_start_stop_music->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_start_stop_music->TabIndex = 0;
			this->pictureBox_start_stop_music->TabStop = false;
			this->pictureBox_start_stop_music->Click += gcnew System::EventHandler(this, &HomeForm::pictureBox_start_stop_music_Click);
			// 
			// label_music_total_time
			// 
			this->label_music_total_time->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label_music_total_time->AutoSize = true;
			this->label_music_total_time->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_music_total_time->Location = System::Drawing::Point(1475, 8);
			this->label_music_total_time->Name = L"label_music_total_time";
			this->label_music_total_time->Size = System::Drawing::Size(60, 28);
			this->label_music_total_time->TabIndex = 2;
			this->label_music_total_time->Text = L"00:00";
			// 
			// trackBar_current_position
			// 
			this->trackBar_current_position->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->trackBar_current_position->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->trackBar_current_position->HoverState->Parent = this->trackBar_current_position;
			this->trackBar_current_position->Location = System::Drawing::Point(94, 11);
			this->trackBar_current_position->Name = L"trackBar_current_position";
			this->trackBar_current_position->Size = System::Drawing::Size(1358, 23);
			this->trackBar_current_position->TabIndex = 1;
			this->trackBar_current_position->ThumbColor = System::Drawing::Color::Black;
			this->trackBar_current_position->Value = 0;
			this->trackBar_current_position->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &HomeForm::trackBar_current_position_MouseUp);
			// 
			// label_music_start_time
			// 
			this->label_music_start_time->AutoSize = true;
			this->label_music_start_time->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_music_start_time->Location = System::Drawing::Point(13, 8);
			this->label_music_start_time->Name = L"label_music_start_time";
			this->label_music_start_time->Size = System::Drawing::Size(60, 28);
			this->label_music_start_time->TabIndex = 0;
			this->label_music_start_time->Text = L"00:00";
			// 
			// openFileDialog_audio_file
			// 
			this->openFileDialog_audio_file->FileName = L"openFileDialog1";
			// 
			// timer_currentTime_audio
			// 
			this->timer_currentTime_audio->Interval = 1000;
			this->timer_currentTime_audio->Tick += gcnew System::EventHandler(this, &HomeForm::timer_currentTime_audio_Tick);
			// 
			// panel_library
			// 
			this->panel_library->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_library->Controls->Add(this->button_load_list_way);
			this->panel_library->Controls->Add(this->button_load_list_music);
			this->panel_library->Controls->Add(this->flowLayoutPanel_library_item_audio);
			this->panel_library->Location = System::Drawing::Point(1370, 60);
			this->panel_library->Name = L"panel_library";
			this->panel_library->ShadowDecoration->Parent = this->panel_library;
			this->panel_library->Size = System::Drawing::Size(1272, 706);
			this->panel_library->TabIndex = 3;
			this->panel_library->Visible = false;
			// 
			// button_load_list_way
			// 
			this->button_load_list_way->BorderRadius = 20;
			this->button_load_list_way->CheckedState->Parent = this->button_load_list_way;
			this->button_load_list_way->CustomImages->Parent = this->button_load_list_way;
			this->button_load_list_way->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button_load_list_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->button_load_list_way->ForeColor = System::Drawing::Color::Black;
			this->button_load_list_way->HoverState->Parent = this->button_load_list_way;
			this->button_load_list_way->Location = System::Drawing::Point(144, 8);
			this->button_load_list_way->Name = L"button_load_list_way";
			this->button_load_list_way->ShadowDecoration->Parent = this->button_load_list_way;
			this->button_load_list_way->Size = System::Drawing::Size(123, 40);
			this->button_load_list_way->TabIndex = 2;
			this->button_load_list_way->Text = L"Дорожки";
			this->button_load_list_way->Click += gcnew System::EventHandler(this, &HomeForm::button_load_list_way_Click);
			// 
			// button_load_list_music
			// 
			this->button_load_list_music->BorderRadius = 20;
			this->button_load_list_music->CheckedState->Parent = this->button_load_list_music;
			this->button_load_list_music->CustomImages->Parent = this->button_load_list_music;
			this->button_load_list_music->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->button_load_list_music->ForeColor = System::Drawing::Color::White;
			this->button_load_list_music->HoverState->Parent = this->button_load_list_music;
			this->button_load_list_music->Location = System::Drawing::Point(13, 8);
			this->button_load_list_music->Name = L"button_load_list_music";
			this->button_load_list_music->ShadowDecoration->Parent = this->button_load_list_music;
			this->button_load_list_music->Size = System::Drawing::Size(123, 40);
			this->button_load_list_music->TabIndex = 1;
			this->button_load_list_music->Text = L"Композиции";
			this->button_load_list_music->Click += gcnew System::EventHandler(this, &HomeForm::button_load_list_music_Click);
			// 
			// flowLayoutPanel_library_item_audio
			// 
			this->flowLayoutPanel_library_item_audio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel_library_item_audio->AutoScroll = true;
			this->flowLayoutPanel_library_item_audio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->flowLayoutPanel_library_item_audio->Location = System::Drawing::Point(3, 54);
			this->flowLayoutPanel_library_item_audio->Name = L"flowLayoutPanel_library_item_audio";
			this->flowLayoutPanel_library_item_audio->Size = System::Drawing::Size(1264, 640);
			this->flowLayoutPanel_library_item_audio->TabIndex = 0;
			this->flowLayoutPanel_library_item_audio->SizeChanged += gcnew System::EventHandler(this, &HomeForm::flowLayoutPanel_library_item_audio_SizeChanged);
			// 
			// HomeForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->ClientSize = System::Drawing::Size(1552, 766);
			this->Controls->Add(this->panel_music);
			this->Controls->Add(this->panel_home_studio);
			this->Controls->Add(this->Panel_home_start_panel);
			this->Controls->Add(this->guna2Panel1);
			this->Controls->Add(this->panel_home_menu);
			this->Controls->Add(this->panel_library);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(1370, 813);
			this->Name = L"HomeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Главное окно";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &HomeForm::HomeForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &HomeForm::HomeForm_FormClosed);
			this->panel_home_menu->ResumeLayout(false);
			this->Panel_home_start_panel->ResumeLayout(false);
			this->Panel_home_start_panel->PerformLayout();
			this->guna2Panel3->ResumeLayout(false);
			this->guna2Panel3->PerformLayout();
			this->panel_->ResumeLayout(false);
			this->panel_->PerformLayout();
			this->guna2Panel1->ResumeLayout(false);
			this->guna2Panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox1))->EndInit();
			this->panel_home_studio->ResumeLayout(false);
			this->panel_studio_conf->ResumeLayout(false);
			this->panel_studio_conf->PerformLayout();
			this->panel_tab->ResumeLayout(false);
			this->panel_studio_users->ResumeLayout(false);
			this->panel_studio_room->ResumeLayout(false);
			this->panel_music->ResumeLayout(false);
			this->panel_music->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_audio_play))->EndInit();
			this->panel_music_controls->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_music_stop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_start_stop_music))->EndInit();
			this->panel_library->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void HomeForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void button_home_menu_home_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel_home_start_panel->Visible = true;
		panel_home_studio->Visible = false;
		panel_library->Visible = false;

		Panel_home_start_panel->Left = w_Visible;
		panel_home_studio->Left = w_Not_Visible;
		panel_library->Left = w_Not_Visible;
	}

	private: System::Void guna2Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel_home_start_panel->Visible = false;
		panel_home_studio->Visible = true;
		panel_library->Visible = false;

		Panel_home_start_panel->Left = w_Not_Visible;
		panel_home_studio->Left = w_Visible;
		panel_library->Left = w_Not_Visible;
	}

	private: System::Void guna2Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel_home_start_panel->Visible = false;
		panel_home_studio->Visible = false;
		panel_library->Visible = true;

		Panel_home_start_panel->Left = w_Not_Visible;
		panel_home_studio->Left = w_Not_Visible;
		panel_library->Left = w_Visible;

		Load_List_Audio();
	}

	private: System::Void guna2Button5_Click(System::Object^ sender, System::EventArgs^ e) {
		MusicEditForm^ editMusic = gcnew MusicEditForm(user_id, ip, teme);
		editMusic->Show();
	}

	private: System::Void guna2Button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Tabs^ tabs = gcnew Tabs();
		tabs->Show();
	}

	private: System::Void guna2Button6_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ myForm = gcnew MyForm();
		myForm->Show();
	}

	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp", true);

		pathFileReport->SetValue("checkLogin", "0");
		pathFileReport->SetValue("userId", "0");
		pathFileReport->SetValue("nameUser", "0");
		pathFileReport->SetValue("teme", "0");

		pathFileReport->Close();

		Application::Restart();
	}

	private: System::Void HomeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		DisposeWave();
	}


	//Создание списка сущесвующих комнат пользователя
	private: void addRoomItem(std::vector<int> list_id, std::vector<std::string> list_name_room, std::vector<std::string> list_path_room_pict, std::vector<std::string> list_creators_room, std::vector<std::string> list_prim_room);

	//Обработчик нажатия на элемент списка
	private: void RoomItemClick(System::Object^ sender, System::EventArgs^ e);

	//Загрузка списка комнат
	private: void Load_Room();

	private: System::Void guna2ImageButton1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_conf_start_call_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_on_off_camera_Click(System::Object^ sender, System::EventArgs^ e);

	private: void WebRTCConf(String^ id, int cam_on);

	private: String^ LoadLinkRoom(String^ id);

	private: System::Void button_conf_cancel_call_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_settings_conf_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void button_add_new_user_Click(System::Object^ sender, System::EventArgs^ e);

	private: int addNewUser(int _user_id, String^ room_id);



	private: int LoadUserId(String^ email_user);

	private: void addUserRoomItem(std::vector<std::string> list_name_user, std::vector<std::string> list_name_avatar);

	private: void LoadUsersRoom();



	private: System::Void button_record_Click(System::Object^ sender, System::EventArgs^ e);

	//Начало записи
	private: void StartRecordMusic();

	//Получение данных из входного буффера
	private: void waveIn_DataAvailable(System::Object^ sender, WaveInEventArgs^ e);

	//Окончание записи
	private: void waveIn_RecordingStopped(System::Object^ sender, StoppedEventArgs^ e);

	//Завершаем запись
	private: void StopRecording();

	private: bool ProcessData(WaveInEventArgs^ e);

	//Для изменения цветов интерфейса
	private: void SetupInterface();

	//Сохраняем запись на сервере
	private: void saveAudioFile();

	//private: void saveFile(String^ uri, String^ filePath);

	private: void addInfoAudioFile(String^ name_audio, String^ name_creators, String^ path_picture);


	//Функции для воспроизведения композиции
	private: System::Void pictureBox_music_stop_Click(System::Object^ sender, System::EventArgs^ e);

	private: void loadMusicFile();

	private: void DisposeWave();

	private: System::Void pictureBox_start_stop_music_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void timer_currentTime_audio_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void trackBar_current_position_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	private: System::Void guna2PictureBox1_Click(System::Object^ sender, System::EventArgs^ e);

	private: void loadSaveImage(String^ name_image);

	private: bool checkFileDownload(String^ fileName) {
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

	private: void addAudioItem(std::vector<int> list_id_audio, std::vector<std::string> list_name_audio, std::vector<std::string> list_creators_audio, std::vector<int> list_id_room, std::vector<int> list_access, std::vector<std::string> list_path_picture);

	//Обработчик нажатия на элемент списка
	private: void AudoiItemClick(System::Object^ sender, System::EventArgs^ e);

	//Загрузка списка комнат
	private: int Load_List_Audio();

	private: System::Void flowLayoutPanel_library_item_audio_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		int count = 0;

		while (count < flowLayoutPanel_library_item_audio->Controls->Count)
		{
			flowLayoutPanel_library_item_audio->Controls[count]->Width = flowLayoutPanel_library_item_audio->Width;
			count++;
		}
	}

	private: void loadsaveAvatar(String^ name_file);

	private: void OnDownloadIndicator(System::Object^ sender, System::Net::DownloadProgressChangedEventArgs^ e);

	private: void stopWaitingLoadFile(System::Object^ sender, AsyncCompletedEventArgs^ e);

	private: System::Void button_load_list_music_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_load_list_way_Click(System::Object^ sender, System::EventArgs^ e);

};
}
