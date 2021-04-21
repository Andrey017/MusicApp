#pragma once

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SaveAudioForm
	/// </summary>
	public ref class SaveAudioForm : public System::Windows::Forms::Form
	{
	public:
		SaveAudioForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		SaveAudioForm(String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			teme = _teme;

			SetupInterface();
		}


	public: int getChech_Value() {
		return check_value;
	}

	public: String^ getName_Audio() {
		return name_audio;
	}

	public: String^ getCreators() {
		return creators;
	}

	public: bool getAccess() {
		return access;
	}

	public: String^ getPath_File() {
		return path_file;
	}

	public: int check_value = 0;
		  String^ name_audio;
		  String^ creators;
		  bool access;

		  String^ path_file;
		  String^ teme;

		  //Для интерфейса
		  int d_r_back = 15;
		  int d_g_back = 19;
		  int d_b_back = 25;

		  int d_r_elem = 32;
		  int d_g_elem = 36;
		  int d_b_elem = 43;

		  int d_text_color = 238;

	private: Guna::UI2::WinForms::Guna2Panel^ panel_way_wave;
	public:

	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox_save_way_back;
	public:

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel_join_join;
	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_save_audio_way;

	private: Guna::UI2::WinForms::Guna2Button^ button_save_audio_way;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_save_music;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_music_Back;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel2;
	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_save_name_music;

	private: Guna::UI2::WinForms::Guna2Button^ button_save_music;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: Guna::UI2::WinForms::Guna2CheckBox^ checkBox_acess_all_user;
	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_save_creators_music;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_music_ava;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_save_music_avatar;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SaveAudioForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_Close;
	private: System::Windows::Forms::Panel^ panel_main;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_main_join_studio;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_main_join_studio;
	private: System::Windows::Forms::Label^ label_main_join_studio;
	private: Guna::UI2::WinForms::Guna2Button^ button_main_music_way;

	private: Guna::UI2::WinForms::Guna2Panel^ panel_main_create_studio;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_main_create_studio;
	private: System::Windows::Forms::Label^ label_main_create_studio;
	private: Guna::UI2::WinForms::Guna2Button^ button_main_create_music;

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SaveAudioForm::typeid));
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->PictureBox_Close = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->panel_main = (gcnew System::Windows::Forms::Panel());
			this->panel_main_join_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->pictureBox_main_join_studio = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_main_join_studio = (gcnew System::Windows::Forms::Label());
			this->button_main_music_way = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->panel_main_create_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->pictureBox_main_create_studio = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_main_create_studio = (gcnew System::Windows::Forms::Label());
			this->button_main_create_music = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel_way_wave = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2PictureBox_save_way_back = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2Panel_join_join = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->textBox_save_audio_way = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->button_save_audio_way = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel_save_music = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->pictureBox_music_Back = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2Panel2 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->checkBox_acess_all_user = (gcnew Guna::UI2::WinForms::Guna2CheckBox());
			this->textBox_save_creators_music = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->pictureBox_save_music_avatar = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->textBox_save_name_music = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->button_save_music = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog_music_ava = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Close))->BeginInit();
			this->panel_main->SuspendLayout();
			this->panel_main_join_studio->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_join_studio))->BeginInit();
			this->panel_main_create_studio->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_create_studio))->BeginInit();
			this->panel_way_wave->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox_save_way_back))->BeginInit();
			this->guna2Panel_join_join->SuspendLayout();
			this->panel_save_music->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_music_Back))->BeginInit();
			this->guna2Panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_save_music_avatar))->BeginInit();
			this->SuspendLayout();
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->BorderRadius = 4;
			this->guna2Elipse1->TargetControl = this;
			// 
			// PictureBox_Close
			// 
			this->PictureBox_Close->BackColor = System::Drawing::Color::White;
			this->PictureBox_Close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_Close.Image")));
			this->PictureBox_Close->Location = System::Drawing::Point(896, -2);
			this->PictureBox_Close->Name = L"PictureBox_Close";
			this->PictureBox_Close->ShadowDecoration->Parent = this->PictureBox_Close;
			this->PictureBox_Close->Size = System::Drawing::Size(35, 35);
			this->PictureBox_Close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox_Close->TabIndex = 11;
			this->PictureBox_Close->TabStop = false;
			this->PictureBox_Close->Click += gcnew System::EventHandler(this, &SaveAudioForm::PictureBox_Close_Click);
			this->PictureBox_Close->MouseEnter += gcnew System::EventHandler(this, &SaveAudioForm::PictureBox_Close_MouseEnter);
			this->PictureBox_Close->MouseLeave += gcnew System::EventHandler(this, &SaveAudioForm::PictureBox_Close_MouseLeave);
			// 
			// panel_main
			// 
			this->panel_main->Controls->Add(this->panel_main_join_studio);
			this->panel_main->Controls->Add(this->panel_main_create_studio);
			this->panel_main->Controls->Add(this->label1);
			this->panel_main->Location = System::Drawing::Point(12, 12);
			this->panel_main->Name = L"panel_main";
			this->panel_main->Size = System::Drawing::Size(906, 476);
			this->panel_main->TabIndex = 12;
			// 
			// panel_main_join_studio
			// 
			this->panel_main_join_studio->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel_main_join_studio->BorderRadius = 8;
			this->panel_main_join_studio->BorderThickness = 2;
			this->panel_main_join_studio->Controls->Add(this->pictureBox_main_join_studio);
			this->panel_main_join_studio->Controls->Add(this->label_main_join_studio);
			this->panel_main_join_studio->Controls->Add(this->button_main_music_way);
			this->panel_main_join_studio->Location = System::Drawing::Point(504, 105);
			this->panel_main_join_studio->Name = L"panel_main_join_studio";
			this->panel_main_join_studio->ShadowDecoration->Parent = this->panel_main_join_studio;
			this->panel_main_join_studio->Size = System::Drawing::Size(281, 323);
			this->panel_main_join_studio->TabIndex = 4;
			// 
			// pictureBox_main_join_studio
			// 
			this->pictureBox_main_join_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_main_join_studio->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_main_join_studio.Image")));
			this->pictureBox_main_join_studio->Location = System::Drawing::Point(38, 73);
			this->pictureBox_main_join_studio->Name = L"pictureBox_main_join_studio";
			this->pictureBox_main_join_studio->ShadowDecoration->Parent = this->pictureBox_main_join_studio;
			this->pictureBox_main_join_studio->Size = System::Drawing::Size(205, 165);
			this->pictureBox_main_join_studio->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_main_join_studio->TabIndex = 5;
			this->pictureBox_main_join_studio->TabStop = false;
			// 
			// label_main_join_studio
			// 
			this->label_main_join_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_main_join_studio->AutoSize = true;
			this->label_main_join_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_main_join_studio->Location = System::Drawing::Point(5, 3);
			this->label_main_join_studio->Name = L"label_main_join_studio";
			this->label_main_join_studio->Size = System::Drawing::Size(271, 56);
			this->label_main_join_studio->TabIndex = 3;
			this->label_main_join_studio->Text = L"Сохраните файл, как новую \r\nзвуковую дорожку";
			this->label_main_join_studio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_main_music_way
			// 
			this->button_main_music_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_main_music_way->BorderRadius = 8;
			this->button_main_music_way->CheckedState->Parent = this->button_main_music_way;
			this->button_main_music_way->CustomImages->Parent = this->button_main_music_way;
			this->button_main_music_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_main_music_way->ForeColor = System::Drawing::Color::White;
			this->button_main_music_way->HoverState->Parent = this->button_main_music_way;
			this->button_main_music_way->Location = System::Drawing::Point(12, 258);
			this->button_main_music_way->Name = L"button_main_music_way";
			this->button_main_music_way->ShadowDecoration->Parent = this->button_main_music_way;
			this->button_main_music_way->Size = System::Drawing::Size(258, 45);
			this->button_main_music_way->TabIndex = 4;
			this->button_main_music_way->Text = L"Сохранить";
			this->button_main_music_way->Click += gcnew System::EventHandler(this, &SaveAudioForm::button_main_music_way_Click);
			// 
			// panel_main_create_studio
			// 
			this->panel_main_create_studio->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel_main_create_studio->BorderRadius = 8;
			this->panel_main_create_studio->BorderThickness = 2;
			this->panel_main_create_studio->Controls->Add(this->pictureBox_main_create_studio);
			this->panel_main_create_studio->Controls->Add(this->label_main_create_studio);
			this->panel_main_create_studio->Controls->Add(this->button_main_create_music);
			this->panel_main_create_studio->Location = System::Drawing::Point(153, 105);
			this->panel_main_create_studio->Name = L"panel_main_create_studio";
			this->panel_main_create_studio->ShadowDecoration->Parent = this->panel_main_create_studio;
			this->panel_main_create_studio->Size = System::Drawing::Size(281, 323);
			this->panel_main_create_studio->TabIndex = 3;
			// 
			// pictureBox_main_create_studio
			// 
			this->pictureBox_main_create_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_main_create_studio->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_main_create_studio.Image")));
			this->pictureBox_main_create_studio->Location = System::Drawing::Point(43, 73);
			this->pictureBox_main_create_studio->Name = L"pictureBox_main_create_studio";
			this->pictureBox_main_create_studio->ShadowDecoration->Parent = this->pictureBox_main_create_studio;
			this->pictureBox_main_create_studio->Size = System::Drawing::Size(205, 165);
			this->pictureBox_main_create_studio->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_main_create_studio->TabIndex = 2;
			this->pictureBox_main_create_studio->TabStop = false;
			// 
			// label_main_create_studio
			// 
			this->label_main_create_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_main_create_studio->AutoSize = true;
			this->label_main_create_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_main_create_studio->Location = System::Drawing::Point(7, 3);
			this->label_main_create_studio->Name = L"label_main_create_studio";
			this->label_main_create_studio->Size = System::Drawing::Size(271, 56);
			this->label_main_create_studio->TabIndex = 0;
			this->label_main_create_studio->Text = L"Сохраните файл, как новую \r\nмузыкальную композицию";
			this->label_main_create_studio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_main_create_music
			// 
			this->button_main_create_music->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_main_create_music->BorderRadius = 8;
			this->button_main_create_music->CheckedState->Parent = this->button_main_create_music;
			this->button_main_create_music->CustomImages->Parent = this->button_main_create_music;
			this->button_main_create_music->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_main_create_music->ForeColor = System::Drawing::Color::White;
			this->button_main_create_music->HoverState->Parent = this->button_main_create_music;
			this->button_main_create_music->Location = System::Drawing::Point(12, 258);
			this->button_main_create_music->Name = L"button_main_create_music";
			this->button_main_create_music->ShadowDecoration->Parent = this->button_main_create_music;
			this->button_main_create_music->Size = System::Drawing::Size(258, 45);
			this->button_main_create_music->TabIndex = 1;
			this->button_main_create_music->Text = L"Сохранить";
			this->button_main_create_music->Click += gcnew System::EventHandler(this, &SaveAudioForm::button_main_create_music_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(311, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 41);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Сохранить запись";
			// 
			// panel_way_wave
			// 
			this->panel_way_wave->Controls->Add(this->guna2PictureBox_save_way_back);
			this->panel_way_wave->Controls->Add(this->guna2Panel_join_join);
			this->panel_way_wave->Controls->Add(this->label2);
			this->panel_way_wave->Controls->Add(this->label3);
			this->panel_way_wave->Location = System::Drawing::Point(950, 12);
			this->panel_way_wave->Name = L"panel_way_wave";
			this->panel_way_wave->ShadowDecoration->Parent = this->panel_way_wave;
			this->panel_way_wave->Size = System::Drawing::Size(906, 476);
			this->panel_way_wave->TabIndex = 13;
			this->panel_way_wave->Visible = false;
			// 
			// guna2PictureBox_save_way_back
			// 
			this->guna2PictureBox_save_way_back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox_save_way_back.Image")));
			this->guna2PictureBox_save_way_back->Location = System::Drawing::Point(3, 3);
			this->guna2PictureBox_save_way_back->Name = L"guna2PictureBox_save_way_back";
			this->guna2PictureBox_save_way_back->ShadowDecoration->Parent = this->guna2PictureBox_save_way_back;
			this->guna2PictureBox_save_way_back->Size = System::Drawing::Size(68, 47);
			this->guna2PictureBox_save_way_back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2PictureBox_save_way_back->TabIndex = 10;
			this->guna2PictureBox_save_way_back->TabStop = false;
			this->guna2PictureBox_save_way_back->Click += gcnew System::EventHandler(this, &SaveAudioForm::guna2PictureBox_save_way_back_Click);
			// 
			// guna2Panel_join_join
			// 
			this->guna2Panel_join_join->Controls->Add(this->textBox_save_audio_way);
			this->guna2Panel_join_join->Controls->Add(this->button_save_audio_way);
			this->guna2Panel_join_join->Location = System::Drawing::Point(101, 128);
			this->guna2Panel_join_join->Name = L"guna2Panel_join_join";
			this->guna2Panel_join_join->ShadowDecoration->Parent = this->guna2Panel_join_join;
			this->guna2Panel_join_join->Size = System::Drawing::Size(700, 296);
			this->guna2Panel_join_join->TabIndex = 8;
			// 
			// textBox_save_audio_way
			// 
			this->textBox_save_audio_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_save_audio_way->Animated = true;
			this->textBox_save_audio_way->BackColor = System::Drawing::Color::White;
			this->textBox_save_audio_way->BorderRadius = 8;
			this->textBox_save_audio_way->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_save_audio_way->DefaultText = L"";
			this->textBox_save_audio_way->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_save_audio_way->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_save_audio_way->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_save_audio_way->DisabledState->Parent = this->textBox_save_audio_way;
			this->textBox_save_audio_way->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_save_audio_way->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_save_audio_way->FocusedState->Parent = this->textBox_save_audio_way;
			this->textBox_save_audio_way->ForeColor = System::Drawing::Color::Black;
			this->textBox_save_audio_way->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_save_audio_way->HoverState->Parent = this->textBox_save_audio_way;
			this->textBox_save_audio_way->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox_save_audio_way.IconLeft")));
			this->textBox_save_audio_way->Location = System::Drawing::Point(95, 84);
			this->textBox_save_audio_way->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_save_audio_way->Name = L"textBox_save_audio_way";
			this->textBox_save_audio_way->PasswordChar = '\0';
			this->textBox_save_audio_way->PlaceholderText = L"Название";
			this->textBox_save_audio_way->SelectedText = L"";
			this->textBox_save_audio_way->ShadowDecoration->Parent = this->textBox_save_audio_way;
			this->textBox_save_audio_way->Size = System::Drawing::Size(506, 44);
			this->textBox_save_audio_way->TabIndex = 6;
			// 
			// button_save_audio_way
			// 
			this->button_save_audio_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_save_audio_way->BorderRadius = 8;
			this->button_save_audio_way->CheckedState->Parent = this->button_save_audio_way;
			this->button_save_audio_way->CustomImages->Parent = this->button_save_audio_way;
			this->button_save_audio_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_save_audio_way->ForeColor = System::Drawing::Color::White;
			this->button_save_audio_way->HoverState->Parent = this->button_save_audio_way;
			this->button_save_audio_way->Location = System::Drawing::Point(214, 204);
			this->button_save_audio_way->Name = L"button_save_audio_way";
			this->button_save_audio_way->ShadowDecoration->Parent = this->button_save_audio_way;
			this->button_save_audio_way->Size = System::Drawing::Size(258, 45);
			this->button_save_audio_way->TabIndex = 7;
			this->button_save_audio_way->Text = L"Сохранить";
			this->button_save_audio_way->Click += gcnew System::EventHandler(this, &SaveAudioForm::button_save_audio_way_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(226, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(448, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введите ниже название музыкальной дорожки";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(187, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(529, 41);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Сохранить музыкальную дорожку";
			// 
			// panel_save_music
			// 
			this->panel_save_music->Controls->Add(this->pictureBox_music_Back);
			this->panel_save_music->Controls->Add(this->guna2Panel2);
			this->panel_save_music->Controls->Add(this->label4);
			this->panel_save_music->Controls->Add(this->label5);
			this->panel_save_music->Location = System::Drawing::Point(12, 500);
			this->panel_save_music->Name = L"panel_save_music";
			this->panel_save_music->ShadowDecoration->Parent = this->panel_save_music;
			this->panel_save_music->Size = System::Drawing::Size(906, 476);
			this->panel_save_music->TabIndex = 14;
			this->panel_save_music->Visible = false;
			// 
			// pictureBox_music_Back
			// 
			this->pictureBox_music_Back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_music_Back.Image")));
			this->pictureBox_music_Back->Location = System::Drawing::Point(3, 3);
			this->pictureBox_music_Back->Name = L"pictureBox_music_Back";
			this->pictureBox_music_Back->ShadowDecoration->Parent = this->pictureBox_music_Back;
			this->pictureBox_music_Back->Size = System::Drawing::Size(68, 47);
			this->pictureBox_music_Back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_music_Back->TabIndex = 10;
			this->pictureBox_music_Back->TabStop = false;
			this->pictureBox_music_Back->Click += gcnew System::EventHandler(this, &SaveAudioForm::pictureBox_music_Back_Click);
			// 
			// guna2Panel2
			// 
			this->guna2Panel2->Controls->Add(this->checkBox_acess_all_user);
			this->guna2Panel2->Controls->Add(this->textBox_save_creators_music);
			this->guna2Panel2->Controls->Add(this->pictureBox_save_music_avatar);
			this->guna2Panel2->Controls->Add(this->textBox_save_name_music);
			this->guna2Panel2->Controls->Add(this->button_save_music);
			this->guna2Panel2->Location = System::Drawing::Point(101, 128);
			this->guna2Panel2->Name = L"guna2Panel2";
			this->guna2Panel2->ShadowDecoration->Parent = this->guna2Panel2;
			this->guna2Panel2->Size = System::Drawing::Size(700, 296);
			this->guna2Panel2->TabIndex = 8;
			// 
			// checkBox_acess_all_user
			// 
			this->checkBox_acess_all_user->AutoSize = true;
			this->checkBox_acess_all_user->CheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkBox_acess_all_user->CheckedState->BorderRadius = 2;
			this->checkBox_acess_all_user->CheckedState->BorderThickness = 0;
			this->checkBox_acess_all_user->CheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkBox_acess_all_user->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox_acess_all_user->Location = System::Drawing::Point(95, 174);
			this->checkBox_acess_all_user->Name = L"checkBox_acess_all_user";
			this->checkBox_acess_all_user->Size = System::Drawing::Size(281, 24);
			this->checkBox_acess_all_user->TabIndex = 10;
			this->checkBox_acess_all_user->Text = L"Доступным для всех пользователей";
			this->checkBox_acess_all_user->UncheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->checkBox_acess_all_user->UncheckedState->BorderRadius = 2;
			this->checkBox_acess_all_user->UncheckedState->BorderThickness = 0;
			this->checkBox_acess_all_user->UncheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->checkBox_acess_all_user->UseVisualStyleBackColor = true;
			// 
			// textBox_save_creators_music
			// 
			this->textBox_save_creators_music->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_save_creators_music->Animated = true;
			this->textBox_save_creators_music->BackColor = System::Drawing::Color::White;
			this->textBox_save_creators_music->BorderRadius = 8;
			this->textBox_save_creators_music->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_save_creators_music->DefaultText = L"";
			this->textBox_save_creators_music->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_save_creators_music->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_save_creators_music->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_save_creators_music->DisabledState->Parent = this->textBox_save_creators_music;
			this->textBox_save_creators_music->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_save_creators_music->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_save_creators_music->FocusedState->Parent = this->textBox_save_creators_music;
			this->textBox_save_creators_music->ForeColor = System::Drawing::Color::Black;
			this->textBox_save_creators_music->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_save_creators_music->HoverState->Parent = this->textBox_save_creators_music;
			this->textBox_save_creators_music->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox_save_creators_music.IconLeft")));
			this->textBox_save_creators_music->Location = System::Drawing::Point(95, 115);
			this->textBox_save_creators_music->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_save_creators_music->Name = L"textBox_save_creators_music";
			this->textBox_save_creators_music->PasswordChar = '\0';
			this->textBox_save_creators_music->PlaceholderText = L"Автор";
			this->textBox_save_creators_music->SelectedText = L"";
			this->textBox_save_creators_music->ShadowDecoration->Parent = this->textBox_save_creators_music;
			this->textBox_save_creators_music->Size = System::Drawing::Size(339, 44);
			this->textBox_save_creators_music->TabIndex = 9;
			// 
			// pictureBox_save_music_avatar
			// 
			this->pictureBox_save_music_avatar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_save_music_avatar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_save_music_avatar.Image")));
			this->pictureBox_save_music_avatar->Location = System::Drawing::Point(441, 33);
			this->pictureBox_save_music_avatar->Name = L"pictureBox_save_music_avatar";
			this->pictureBox_save_music_avatar->ShadowDecoration->Parent = this->pictureBox_save_music_avatar;
			this->pictureBox_save_music_avatar->Size = System::Drawing::Size(205, 165);
			this->pictureBox_save_music_avatar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_save_music_avatar->TabIndex = 8;
			this->pictureBox_save_music_avatar->TabStop = false;
			this->pictureBox_save_music_avatar->Click += gcnew System::EventHandler(this, &SaveAudioForm::pictureBox_save_music_avatar_Click);
			// 
			// textBox_save_name_music
			// 
			this->textBox_save_name_music->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_save_name_music->Animated = true;
			this->textBox_save_name_music->BackColor = System::Drawing::Color::White;
			this->textBox_save_name_music->BorderRadius = 8;
			this->textBox_save_name_music->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_save_name_music->DefaultText = L"";
			this->textBox_save_name_music->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_save_name_music->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_save_name_music->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_save_name_music->DisabledState->Parent = this->textBox_save_name_music;
			this->textBox_save_name_music->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_save_name_music->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_save_name_music->FocusedState->Parent = this->textBox_save_name_music;
			this->textBox_save_name_music->ForeColor = System::Drawing::Color::Black;
			this->textBox_save_name_music->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_save_name_music->HoverState->Parent = this->textBox_save_name_music;
			this->textBox_save_name_music->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox_save_name_music.IconLeft")));
			this->textBox_save_name_music->Location = System::Drawing::Point(95, 50);
			this->textBox_save_name_music->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_save_name_music->Name = L"textBox_save_name_music";
			this->textBox_save_name_music->PasswordChar = '\0';
			this->textBox_save_name_music->PlaceholderText = L"Название";
			this->textBox_save_name_music->SelectedText = L"";
			this->textBox_save_name_music->ShadowDecoration->Parent = this->textBox_save_name_music;
			this->textBox_save_name_music->Size = System::Drawing::Size(339, 44);
			this->textBox_save_name_music->TabIndex = 6;
			// 
			// button_save_music
			// 
			this->button_save_music->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_save_music->BorderRadius = 8;
			this->button_save_music->CheckedState->Parent = this->button_save_music;
			this->button_save_music->CustomImages->Parent = this->button_save_music;
			this->button_save_music->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_save_music->ForeColor = System::Drawing::Color::White;
			this->button_save_music->HoverState->Parent = this->button_save_music;
			this->button_save_music->Location = System::Drawing::Point(214, 218);
			this->button_save_music->Name = L"button_save_music";
			this->button_save_music->ShadowDecoration->Parent = this->button_save_music;
			this->button_save_music->Size = System::Drawing::Size(258, 45);
			this->button_save_music->TabIndex = 7;
			this->button_save_music->Text = L"Сохранить";
			this->button_save_music->Click += gcnew System::EventHandler(this, &SaveAudioForm::button_save_music_Click);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(212, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(481, 28);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Введите ниже название музыкальной композиции";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(163, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(590, 41);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Сохранить музыкальную композицию";
			// 
			// openFileDialog_music_ava
			// 
			this->openFileDialog_music_ava->FileName = L"openFileDialog1";
			// 
			// SaveAudioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(930, 500);
			this->Controls->Add(this->PictureBox_Close);
			this->Controls->Add(this->panel_save_music);
			this->Controls->Add(this->panel_way_wave);
			this->Controls->Add(this->panel_main);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SaveAudioForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SaveAudioForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Close))->EndInit();
			this->panel_main->ResumeLayout(false);
			this->panel_main->PerformLayout();
			this->panel_main_join_studio->ResumeLayout(false);
			this->panel_main_join_studio->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_join_studio))->EndInit();
			this->panel_main_create_studio->ResumeLayout(false);
			this->panel_main_create_studio->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_create_studio))->EndInit();
			this->panel_way_wave->ResumeLayout(false);
			this->panel_way_wave->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox_save_way_back))->EndInit();
			this->guna2Panel_join_join->ResumeLayout(false);
			this->panel_save_music->ResumeLayout(false);
			this->panel_save_music->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_music_Back))->EndInit();
			this->guna2Panel2->ResumeLayout(false);
			this->guna2Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_save_music_avatar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void SetupInterface();

	private: System::Void PictureBox_Close_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PictureBox_Close_MouseEnter(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PictureBox_Close_MouseLeave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_main_music_way_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void guna2PictureBox_save_way_back_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_save_audio_way_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureBox_music_Back_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_main_create_music_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_save_music_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureBox_save_music_avatar_Click(System::Object^ sender, System::EventArgs^ e);
};
}
