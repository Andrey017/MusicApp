#pragma once

#include "NetFunction.h"

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CreateRoomForm
	/// </summary>
	public ref class CreateRoomForm : public System::Windows::Forms::Form
	{
	public:
		CreateRoomForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		CreateRoomForm(int _user_id, String^ _ip, String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			user_id = _user_id;
			ip = _ip;
			teme = _teme;

			SetupInterface();
		}

	private: int user_id;
		   String^ ip;
		   String^ teme;

		   //Для интерфейса
		   int d_r_back = 15;
		   int d_g_back = 19;
		   int d_b_back = 25;

		   int d_r_elem = 32;
		   int d_g_elem = 36;
		   int d_b_elem = 43;

		   int d_text_color = 238;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_add_picture;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_join_room;
	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox_join_back;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel_join_join;
	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_join_invite;
	private: Guna::UI2::WinForms::Guna2Button^ button_join;






	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

		   String^ path_file;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CreateRoomForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_main_create_studio;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_main_create_studio;
	private: Guna::UI2::WinForms::Guna2Button^ button_main_create_studio;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_main_join_studio;
	private: Guna::UI2::WinForms::Guna2Button^ button_main_join_studio;













	private: System::Windows::Forms::Label^ label_main_join_studio;

	private: System::Windows::Forms::Panel^ panel_main;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_main_join_studio;

	private: Guna::UI2::WinForms::Guna2Panel^ panel_main_create_studio;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_create_studio;
	private: System::Windows::Forms::Label^ label_create_studio_info;

	private: System::Windows::Forms::Label^ label_create_studio;
	private: Guna::UI2::WinForms::Guna2Button^ button_create_studio;


	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_create_studio_avatar;


	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_name_create_studio;


	private: Guna::UI2::WinForms::Guna2Panel^ panel_in_create_studio;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_Close;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_back_blue;



	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateRoomForm::typeid));
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_main_create_studio = (gcnew System::Windows::Forms::Label());
			this->button_main_create_studio = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->pictureBox_main_create_studio = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->pictureBox_main_join_studio = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->button_main_join_studio = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label_main_join_studio = (gcnew System::Windows::Forms::Label());
			this->panel_main = (gcnew System::Windows::Forms::Panel());
			this->panel_main_join_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->panel_main_create_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->panel_create_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->PictureBox_back_blue = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->panel_in_create_studio = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->textBox_name_create_studio = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->button_create_studio = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->pictureBox_create_studio_avatar = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_create_studio_info = (gcnew System::Windows::Forms::Label());
			this->label_create_studio = (gcnew System::Windows::Forms::Label());
			this->PictureBox_Close = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->openFileDialog_add_picture = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel_join_room = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2PictureBox_join_back = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2Panel_join_join = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->textBox_join_invite = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->button_join = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_create_studio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_join_studio))->BeginInit();
			this->panel_main->SuspendLayout();
			this->panel_main_join_studio->SuspendLayout();
			this->panel_main_create_studio->SuspendLayout();
			this->panel_create_studio->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_back_blue))->BeginInit();
			this->panel_in_create_studio->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_create_studio_avatar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Close))->BeginInit();
			this->panel_join_room->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox_join_back))->BeginInit();
			this->guna2Panel_join_join->SuspendLayout();
			this->SuspendLayout();
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->TargetControl = this;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(267, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(380, 41);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Добавить новую студию";
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
			this->label_main_create_studio->Size = System::Drawing::Size(263, 56);
			this->label_main_create_studio->TabIndex = 0;
			this->label_main_create_studio->Text = L"Создать новый сервер и \r\nпригласить пользователей.";
			this->label_main_create_studio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_main_create_studio
			// 
			this->button_main_create_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_main_create_studio->BorderRadius = 8;
			this->button_main_create_studio->CheckedState->Parent = this->button_main_create_studio;
			this->button_main_create_studio->CustomImages->Parent = this->button_main_create_studio;
			this->button_main_create_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_main_create_studio->ForeColor = System::Drawing::Color::White;
			this->button_main_create_studio->HoverState->Parent = this->button_main_create_studio;
			this->button_main_create_studio->Location = System::Drawing::Point(12, 258);
			this->button_main_create_studio->Name = L"button_main_create_studio";
			this->button_main_create_studio->ShadowDecoration->Parent = this->button_main_create_studio;
			this->button_main_create_studio->Size = System::Drawing::Size(258, 45);
			this->button_main_create_studio->TabIndex = 1;
			this->button_main_create_studio->Text = L"Создать студию";
			this->button_main_create_studio->Click += gcnew System::EventHandler(this, &CreateRoomForm::button_main_create_studio_Click);
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
			// button_main_join_studio
			// 
			this->button_main_join_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_main_join_studio->BorderRadius = 8;
			this->button_main_join_studio->CheckedState->Parent = this->button_main_join_studio;
			this->button_main_join_studio->CustomImages->Parent = this->button_main_join_studio;
			this->button_main_join_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_main_join_studio->ForeColor = System::Drawing::Color::White;
			this->button_main_join_studio->HoverState->Parent = this->button_main_join_studio;
			this->button_main_join_studio->Location = System::Drawing::Point(12, 258);
			this->button_main_join_studio->Name = L"button_main_join_studio";
			this->button_main_join_studio->ShadowDecoration->Parent = this->button_main_join_studio;
			this->button_main_join_studio->Size = System::Drawing::Size(258, 45);
			this->button_main_join_studio->TabIndex = 4;
			this->button_main_join_studio->Text = L"Присоедениться к студии";
			this->button_main_join_studio->Click += gcnew System::EventHandler(this, &CreateRoomForm::button_main_join_studio_Click);
			// 
			// label_main_join_studio
			// 
			this->label_main_join_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_main_join_studio->AutoSize = true;
			this->label_main_join_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_main_join_studio->Location = System::Drawing::Point(16, 3);
			this->label_main_join_studio->Name = L"label_main_join_studio";
			this->label_main_join_studio->Size = System::Drawing::Size(250, 56);
			this->label_main_join_studio->TabIndex = 3;
			this->label_main_join_studio->Text = L"Присоедениться к студии \r\nпо ссылке приглашения.";
			this->label_main_join_studio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_main
			// 
			this->panel_main->Controls->Add(this->panel_main_join_studio);
			this->panel_main->Controls->Add(this->panel_main_create_studio);
			this->panel_main->Controls->Add(this->label1);
			this->panel_main->Location = System::Drawing::Point(12, 12);
			this->panel_main->Name = L"panel_main";
			this->panel_main->Size = System::Drawing::Size(906, 476);
			this->panel_main->TabIndex = 3;
			// 
			// panel_main_join_studio
			// 
			this->panel_main_join_studio->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel_main_join_studio->BorderRadius = 8;
			this->panel_main_join_studio->BorderThickness = 2;
			this->panel_main_join_studio->Controls->Add(this->pictureBox_main_join_studio);
			this->panel_main_join_studio->Controls->Add(this->label_main_join_studio);
			this->panel_main_join_studio->Controls->Add(this->button_main_join_studio);
			this->panel_main_join_studio->Location = System::Drawing::Point(504, 105);
			this->panel_main_join_studio->Name = L"panel_main_join_studio";
			this->panel_main_join_studio->ShadowDecoration->Parent = this->panel_main_join_studio;
			this->panel_main_join_studio->Size = System::Drawing::Size(281, 323);
			this->panel_main_join_studio->TabIndex = 4;
			// 
			// panel_main_create_studio
			// 
			this->panel_main_create_studio->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel_main_create_studio->BorderRadius = 8;
			this->panel_main_create_studio->BorderThickness = 2;
			this->panel_main_create_studio->Controls->Add(this->pictureBox_main_create_studio);
			this->panel_main_create_studio->Controls->Add(this->label_main_create_studio);
			this->panel_main_create_studio->Controls->Add(this->button_main_create_studio);
			this->panel_main_create_studio->Location = System::Drawing::Point(153, 105);
			this->panel_main_create_studio->Name = L"panel_main_create_studio";
			this->panel_main_create_studio->ShadowDecoration->Parent = this->panel_main_create_studio;
			this->panel_main_create_studio->Size = System::Drawing::Size(281, 323);
			this->panel_main_create_studio->TabIndex = 3;
			// 
			// panel_create_studio
			// 
			this->panel_create_studio->Controls->Add(this->PictureBox_back_blue);
			this->panel_create_studio->Controls->Add(this->panel_in_create_studio);
			this->panel_create_studio->Controls->Add(this->label_create_studio_info);
			this->panel_create_studio->Controls->Add(this->label_create_studio);
			this->panel_create_studio->Location = System::Drawing::Point(950, 12);
			this->panel_create_studio->Name = L"panel_create_studio";
			this->panel_create_studio->ShadowDecoration->Parent = this->panel_create_studio;
			this->panel_create_studio->Size = System::Drawing::Size(906, 476);
			this->panel_create_studio->TabIndex = 4;
			this->panel_create_studio->Visible = false;
			// 
			// PictureBox_back_blue
			// 
			this->PictureBox_back_blue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_back_blue.Image")));
			this->PictureBox_back_blue->Location = System::Drawing::Point(3, 3);
			this->PictureBox_back_blue->Name = L"PictureBox_back_blue";
			this->PictureBox_back_blue->ShadowDecoration->Parent = this->PictureBox_back_blue;
			this->PictureBox_back_blue->Size = System::Drawing::Size(68, 47);
			this->PictureBox_back_blue->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox_back_blue->TabIndex = 10;
			this->PictureBox_back_blue->TabStop = false;
			this->PictureBox_back_blue->Click += gcnew System::EventHandler(this, &CreateRoomForm::PictureBox_back_blue_Click);
			// 
			// panel_in_create_studio
			// 
			this->panel_in_create_studio->Controls->Add(this->textBox_name_create_studio);
			this->panel_in_create_studio->Controls->Add(this->button_create_studio);
			this->panel_in_create_studio->Controls->Add(this->pictureBox_create_studio_avatar);
			this->panel_in_create_studio->Location = System::Drawing::Point(101, 145);
			this->panel_in_create_studio->Name = L"panel_in_create_studio";
			this->panel_in_create_studio->ShadowDecoration->Parent = this->panel_in_create_studio;
			this->panel_in_create_studio->Size = System::Drawing::Size(700, 296);
			this->panel_in_create_studio->TabIndex = 8;
			// 
			// textBox_name_create_studio
			// 
			this->textBox_name_create_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_name_create_studio->Animated = true;
			this->textBox_name_create_studio->BackColor = System::Drawing::Color::White;
			this->textBox_name_create_studio->BorderRadius = 8;
			this->textBox_name_create_studio->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_name_create_studio->DefaultText = L"";
			this->textBox_name_create_studio->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_name_create_studio->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_name_create_studio->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_name_create_studio->DisabledState->Parent = this->textBox_name_create_studio;
			this->textBox_name_create_studio->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_name_create_studio->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_name_create_studio->FocusedState->Parent = this->textBox_name_create_studio;
			this->textBox_name_create_studio->ForeColor = System::Drawing::Color::Black;
			this->textBox_name_create_studio->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_name_create_studio->HoverState->Parent = this->textBox_name_create_studio;
			this->textBox_name_create_studio->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox_name_create_studio.IconLeft")));
			this->textBox_name_create_studio->Location = System::Drawing::Point(85, 84);
			this->textBox_name_create_studio->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_name_create_studio->Name = L"textBox_name_create_studio";
			this->textBox_name_create_studio->PasswordChar = '\0';
			this->textBox_name_create_studio->PlaceholderText = L"Имя студии";
			this->textBox_name_create_studio->SelectedText = L"";
			this->textBox_name_create_studio->ShadowDecoration->Parent = this->textBox_name_create_studio;
			this->textBox_name_create_studio->Size = System::Drawing::Size(310, 44);
			this->textBox_name_create_studio->TabIndex = 6;
			// 
			// button_create_studio
			// 
			this->button_create_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_create_studio->BorderRadius = 8;
			this->button_create_studio->CheckedState->Parent = this->button_create_studio;
			this->button_create_studio->CustomImages->Parent = this->button_create_studio;
			this->button_create_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_create_studio->ForeColor = System::Drawing::Color::White;
			this->button_create_studio->HoverState->Parent = this->button_create_studio;
			this->button_create_studio->Location = System::Drawing::Point(199, 208);
			this->button_create_studio->Name = L"button_create_studio";
			this->button_create_studio->ShadowDecoration->Parent = this->button_create_studio;
			this->button_create_studio->Size = System::Drawing::Size(258, 45);
			this->button_create_studio->TabIndex = 7;
			this->button_create_studio->Text = L"Создать студию";
			this->button_create_studio->Click += gcnew System::EventHandler(this, &CreateRoomForm::button_create_studio_Click);
			// 
			// pictureBox_create_studio_avatar
			// 
			this->pictureBox_create_studio_avatar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_create_studio_avatar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_create_studio_avatar.Image")));
			this->pictureBox_create_studio_avatar->Location = System::Drawing::Point(420, 23);
			this->pictureBox_create_studio_avatar->Name = L"pictureBox_create_studio_avatar";
			this->pictureBox_create_studio_avatar->ShadowDecoration->Parent = this->pictureBox_create_studio_avatar;
			this->pictureBox_create_studio_avatar->Size = System::Drawing::Size(205, 165);
			this->pictureBox_create_studio_avatar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_create_studio_avatar->TabIndex = 3;
			this->pictureBox_create_studio_avatar->TabStop = false;
			this->pictureBox_create_studio_avatar->Click += gcnew System::EventHandler(this, &CreateRoomForm::pictureBox_create_studio_avatar_Click);
			// 
			// label_create_studio_info
			// 
			this->label_create_studio_info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_create_studio_info->AutoSize = true;
			this->label_create_studio_info->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_create_studio_info->Location = System::Drawing::Point(201, 73);
			this->label_create_studio_info->Name = L"label_create_studio_info";
			this->label_create_studio_info->Size = System::Drawing::Size(485, 56);
			this->label_create_studio_info->TabIndex = 3;
			this->label_create_studio_info->Text = L"Создав студию, вы получите доступ к бесплатному \r\nсозданию музыкальных композиций"
				L"";
			this->label_create_studio_info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_create_studio
			// 
			this->label_create_studio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_create_studio->AutoSize = true;
			this->label_create_studio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_create_studio->Location = System::Drawing::Point(259, 32);
			this->label_create_studio->Name = L"label_create_studio";
			this->label_create_studio->Size = System::Drawing::Size(380, 41);
			this->label_create_studio->TabIndex = 5;
			this->label_create_studio->Text = L"Добавить новую студию";
			// 
			// PictureBox_Close
			// 
			this->PictureBox_Close->BackColor = System::Drawing::Color::White;
			this->PictureBox_Close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_Close.Image")));
			this->PictureBox_Close->Location = System::Drawing::Point(895, -3);
			this->PictureBox_Close->Name = L"PictureBox_Close";
			this->PictureBox_Close->ShadowDecoration->Parent = this->PictureBox_Close;
			this->PictureBox_Close->Size = System::Drawing::Size(35, 35);
			this->PictureBox_Close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox_Close->TabIndex = 10;
			this->PictureBox_Close->TabStop = false;
			this->PictureBox_Close->Click += gcnew System::EventHandler(this, &CreateRoomForm::PictureBox_Close_Click);
			this->PictureBox_Close->MouseEnter += gcnew System::EventHandler(this, &CreateRoomForm::PictureBox_Close_MouseEnter);
			this->PictureBox_Close->MouseLeave += gcnew System::EventHandler(this, &CreateRoomForm::PictureBox_Close_MouseLeave);
			// 
			// openFileDialog_add_picture
			// 
			this->openFileDialog_add_picture->FileName = L"openFileDialog1";
			// 
			// panel_join_room
			// 
			this->panel_join_room->Controls->Add(this->guna2PictureBox_join_back);
			this->panel_join_room->Controls->Add(this->guna2Panel_join_join);
			this->panel_join_room->Controls->Add(this->label2);
			this->panel_join_room->Controls->Add(this->label3);
			this->panel_join_room->Location = System::Drawing::Point(12, 500);
			this->panel_join_room->Name = L"panel_join_room";
			this->panel_join_room->ShadowDecoration->Parent = this->panel_join_room;
			this->panel_join_room->Size = System::Drawing::Size(906, 476);
			this->panel_join_room->TabIndex = 11;
			this->panel_join_room->Visible = false;
			// 
			// guna2PictureBox_join_back
			// 
			this->guna2PictureBox_join_back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox_join_back.Image")));
			this->guna2PictureBox_join_back->Location = System::Drawing::Point(3, 3);
			this->guna2PictureBox_join_back->Name = L"guna2PictureBox_join_back";
			this->guna2PictureBox_join_back->ShadowDecoration->Parent = this->guna2PictureBox_join_back;
			this->guna2PictureBox_join_back->Size = System::Drawing::Size(68, 47);
			this->guna2PictureBox_join_back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2PictureBox_join_back->TabIndex = 10;
			this->guna2PictureBox_join_back->TabStop = false;
			this->guna2PictureBox_join_back->Click += gcnew System::EventHandler(this, &CreateRoomForm::guna2PictureBox_join_back_Click);
			// 
			// guna2Panel_join_join
			// 
			this->guna2Panel_join_join->Controls->Add(this->textBox_join_invite);
			this->guna2Panel_join_join->Controls->Add(this->button_join);
			this->guna2Panel_join_join->Location = System::Drawing::Point(101, 145);
			this->guna2Panel_join_join->Name = L"guna2Panel_join_join";
			this->guna2Panel_join_join->ShadowDecoration->Parent = this->guna2Panel_join_join;
			this->guna2Panel_join_join->Size = System::Drawing::Size(700, 296);
			this->guna2Panel_join_join->TabIndex = 8;
			// 
			// textBox_join_invite
			// 
			this->textBox_join_invite->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_join_invite->Animated = true;
			this->textBox_join_invite->BackColor = System::Drawing::Color::White;
			this->textBox_join_invite->BorderRadius = 8;
			this->textBox_join_invite->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_join_invite->DefaultText = L"";
			this->textBox_join_invite->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_join_invite->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_join_invite->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_join_invite->DisabledState->Parent = this->textBox_join_invite;
			this->textBox_join_invite->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_join_invite->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_join_invite->FocusedState->Parent = this->textBox_join_invite;
			this->textBox_join_invite->ForeColor = System::Drawing::Color::Black;
			this->textBox_join_invite->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_join_invite->HoverState->Parent = this->textBox_join_invite;
			this->textBox_join_invite->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textBox_join_invite.IconLeft")));
			this->textBox_join_invite->Location = System::Drawing::Point(95, 84);
			this->textBox_join_invite->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_join_invite->Name = L"textBox_join_invite";
			this->textBox_join_invite->PasswordChar = '\0';
			this->textBox_join_invite->PlaceholderText = L"Приглашение";
			this->textBox_join_invite->SelectedText = L"";
			this->textBox_join_invite->ShadowDecoration->Parent = this->textBox_join_invite;
			this->textBox_join_invite->Size = System::Drawing::Size(506, 44);
			this->textBox_join_invite->TabIndex = 6;
			// 
			// button_join
			// 
			this->button_join->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_join->BorderRadius = 8;
			this->button_join->CheckedState->Parent = this->button_join;
			this->button_join->CustomImages->Parent = this->button_join;
			this->button_join->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_join->ForeColor = System::Drawing::Color::White;
			this->button_join->HoverState->Parent = this->button_join;
			this->button_join->Location = System::Drawing::Point(214, 204);
			this->button_join->Name = L"button_join";
			this->button_join->ShadowDecoration->Parent = this->button_join;
			this->button_join->Size = System::Drawing::Size(258, 45);
			this->button_join->TabIndex = 7;
			this->button_join->Text = L"Присоедениться";
			this->button_join->Click += gcnew System::EventHandler(this, &CreateRoomForm::button_join_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(201, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(501, 56);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введите ниже приглашение, чтобы примоединиться \r\nк существующей студии.";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(233, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(419, 41);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Присоединиться к комнате";
			// 
			// CreateRoomForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(930, 500);
			this->Controls->Add(this->PictureBox_Close);
			this->Controls->Add(this->panel_join_room);
			this->Controls->Add(this->panel_create_studio);
			this->Controls->Add(this->panel_main);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"CreateRoomForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CreateRoomForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_create_studio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_main_join_studio))->EndInit();
			this->panel_main->ResumeLayout(false);
			this->panel_main->PerformLayout();
			this->panel_main_join_studio->ResumeLayout(false);
			this->panel_main_join_studio->PerformLayout();
			this->panel_main_create_studio->ResumeLayout(false);
			this->panel_main_create_studio->PerformLayout();
			this->panel_create_studio->ResumeLayout(false);
			this->panel_create_studio->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_back_blue))->EndInit();
			this->panel_in_create_studio->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_create_studio_avatar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Close))->EndInit();
			this->panel_join_room->ResumeLayout(false);
			this->panel_join_room->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox_join_back))->EndInit();
			this->guna2Panel_join_join->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void SetupInterface();

	private: System::Void button_main_create_studio_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PictureBox_Close_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PictureBox_Close_MouseEnter(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PictureBox_Close_MouseLeave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void PictureBox_back_blue_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_create_studio_Click(System::Object^ sender, System::EventArgs^ e);

	private: void AddNewRoom(String^ name_room, String^ fileName);

	private: void LoadAvatarRoom(String^ uri, String^ filePath);

	private: System::Void pictureBox_create_studio_avatar_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_main_join_studio_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void guna2PictureBox_join_back_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_join_Click(System::Object^ sender, System::EventArgs^ e);

	private: int Join_in_room(String^ invite_code);
};
}
