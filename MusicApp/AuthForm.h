#pragma once

#include "HomeForm.h"
#include "NetFunction.h"

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AuthForm
	/// </summary>
	public ref class AuthForm : public System::Windows::Forms::Form
	{
	public:
		AuthForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			PictureBox__Auth_Dark->Visible = false;

			timer1->Start();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AuthForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: String^ ip = "94.141.168.185";
			 bool slide = true;
			 int user_id;
			 String^ name_surname;

			 String^ file_path;
			 String^ insert_user_id;
			 String^ email_insert_user;

			 String^ gl_name_avatar;

			 System::IO::MemoryStream^ avatarStream_in;

	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;
	private: Guna::UI::WinForms::GunaPanel^ panel_auth;
	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_auth_password;



	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_auth_email;

	private: Guna::UI::WinForms::GunaLabel^ gunaLabel1;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_Auth_White;

	private: Guna::UI2::WinForms::Guna2Button^ guna2Button_auth_login;
	private: Guna::UI::WinForms::GunaPanel^ gunaPanel_reg;

	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_reg_rep_pass;
	private: Guna::UI2::WinForms::Guna2Button^ guna2Button_reg_registration;


	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_reg_pass;

	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_reg_email;

	private: Guna::UI::WinForms::GunaLabel^ gunaLabel2;
	private: System::Windows::Forms::Panel^ panel_close_auth;
	private: System::Windows::Forms::Panel^ panel_close_reg;
	private: System::Windows::Forms::Panel^ panel_back;
	private: System::Windows::Forms::Panel^ panel_front;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox__Auth_Dark;
	private: Guna::UI::WinForms::GunaLabel^ gunaLabel_reg;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_reg_back_blue;
	private: System::Windows::Forms::Timer^ timer3;
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_Close;
	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_reg_surname;
	private: Guna::UI2::WinForms::Guna2TextBox^ guna2TextBox_reg_name;
	private: Guna::UI::WinForms::GunaPanel^ panel_avatar;

	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ pictureBox_add_avatar;


	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
	private: Guna::UI2::WinForms::Guna2Button^ button_add_avatar_in_profil;

	private: Guna::UI::WinForms::GunaLabel^ gunaLabel3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_add_avatar;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AuthForm::typeid));
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->panel_auth = (gcnew Guna::UI::WinForms::GunaPanel());
			this->gunaLabel_reg = (gcnew Guna::UI::WinForms::GunaLabel());
			this->guna2Button_auth_login = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2TextBox_auth_password = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2TextBox_auth_email = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->gunaLabel1 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->PictureBox_Auth_White = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->gunaPanel_reg = (gcnew Guna::UI::WinForms::GunaPanel());
			this->guna2TextBox_reg_surname = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2TextBox_reg_name = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->PictureBox_reg_back_blue = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2TextBox_reg_rep_pass = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2Button_reg_registration = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2TextBox_reg_pass = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->guna2TextBox_reg_email = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			this->gunaLabel2 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->panel_close_auth = (gcnew System::Windows::Forms::Panel());
			this->panel_close_reg = (gcnew System::Windows::Forms::Panel());
			this->panel_back = (gcnew System::Windows::Forms::Panel());
			this->panel_front = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->PictureBox__Auth_Dark = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->PictureBox_Close = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->panel_avatar = (gcnew Guna::UI::WinForms::GunaPanel());
			this->pictureBox_add_avatar = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->button_add_avatar_in_profil = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->gunaLabel3 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->openFileDialog_add_avatar = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel_auth->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Auth_White))->BeginInit();
			this->gunaPanel_reg->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_reg_back_blue))->BeginInit();
			this->panel_back->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox__Auth_Dark))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Close))->BeginInit();
			this->panel_avatar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_add_avatar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->TargetControl = this;
			// 
			// panel_auth
			// 
			this->panel_auth->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_auth->BackColor = System::Drawing::Color::White;
			this->panel_auth->Controls->Add(this->gunaLabel_reg);
			this->panel_auth->Controls->Add(this->guna2Button_auth_login);
			this->panel_auth->Controls->Add(this->guna2TextBox_auth_password);
			this->panel_auth->Controls->Add(this->guna2TextBox_auth_email);
			this->panel_auth->Controls->Add(this->gunaLabel1);
			this->panel_auth->Location = System::Drawing::Point(462, 12);
			this->panel_auth->Name = L"panel_auth";
			this->panel_auth->Size = System::Drawing::Size(386, 465);
			this->panel_auth->TabIndex = 0;
			// 
			// gunaLabel_reg
			// 
			this->gunaLabel_reg->AutoSize = true;
			this->gunaLabel_reg->BackColor = System::Drawing::Color::White;
			this->gunaLabel_reg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaLabel_reg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)));
			this->gunaLabel_reg->Location = System::Drawing::Point(148, 228);
			this->gunaLabel_reg->Name = L"gunaLabel_reg";
			this->gunaLabel_reg->Size = System::Drawing::Size(87, 19);
			this->gunaLabel_reg->TabIndex = 5;
			this->gunaLabel_reg->Text = L"Регистрация";
			this->gunaLabel_reg->Click += gcnew System::EventHandler(this, &AuthForm::gunaLabel_reg_Click);
			// 
			// guna2Button_auth_login
			// 
			this->guna2Button_auth_login->Animated = true;
			this->guna2Button_auth_login->BorderRadius = 8;
			this->guna2Button_auth_login->CheckedState->Parent = this->guna2Button_auth_login;
			this->guna2Button_auth_login->CustomImages->Parent = this->guna2Button_auth_login;
			this->guna2Button_auth_login->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->guna2Button_auth_login->ForeColor = System::Drawing::Color::White;
			this->guna2Button_auth_login->HoverState->Parent = this->guna2Button_auth_login;
			this->guna2Button_auth_login->Location = System::Drawing::Point(108, 285);
			this->guna2Button_auth_login->Name = L"guna2Button_auth_login";
			this->guna2Button_auth_login->ShadowDecoration->Parent = this->guna2Button_auth_login;
			this->guna2Button_auth_login->Size = System::Drawing::Size(166, 45);
			this->guna2Button_auth_login->TabIndex = 4;
			this->guna2Button_auth_login->Text = L"Войти";
			this->guna2Button_auth_login->Click += gcnew System::EventHandler(this, &AuthForm::guna2Button_auth_login_Click);
			// 
			// guna2TextBox_auth_password
			// 
			this->guna2TextBox_auth_password->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_auth_password->Animated = true;
			this->guna2TextBox_auth_password->BackColor = System::Drawing::SystemColors::Window;
			this->guna2TextBox_auth_password->BorderRadius = 8;
			this->guna2TextBox_auth_password->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_auth_password->DefaultText = L"";
			this->guna2TextBox_auth_password->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_auth_password->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_auth_password->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_auth_password->DisabledState->Parent = this->guna2TextBox_auth_password;
			this->guna2TextBox_auth_password->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_auth_password->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_auth_password->FocusedState->Parent = this->guna2TextBox_auth_password;
			this->guna2TextBox_auth_password->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_auth_password->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_auth_password->HoverState->Parent = this->guna2TextBox_auth_password;
			this->guna2TextBox_auth_password->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_auth_password.IconLeft")));
			this->guna2TextBox_auth_password->Location = System::Drawing::Point(42, 170);
			this->guna2TextBox_auth_password->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_auth_password->Name = L"guna2TextBox_auth_password";
			this->guna2TextBox_auth_password->PasswordChar = '*';
			this->guna2TextBox_auth_password->PlaceholderText = L"Пароль";
			this->guna2TextBox_auth_password->SelectedText = L"";
			this->guna2TextBox_auth_password->ShadowDecoration->Parent = this->guna2TextBox_auth_password;
			this->guna2TextBox_auth_password->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_auth_password->TabIndex = 3;
			// 
			// guna2TextBox_auth_email
			// 
			this->guna2TextBox_auth_email->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_auth_email->Animated = true;
			this->guna2TextBox_auth_email->BackColor = System::Drawing::Color::White;
			this->guna2TextBox_auth_email->BorderRadius = 8;
			this->guna2TextBox_auth_email->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_auth_email->DefaultText = L"";
			this->guna2TextBox_auth_email->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_auth_email->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_auth_email->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_auth_email->DisabledState->Parent = this->guna2TextBox_auth_email;
			this->guna2TextBox_auth_email->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_auth_email->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_auth_email->FocusedState->Parent = this->guna2TextBox_auth_email;
			this->guna2TextBox_auth_email->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_auth_email->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_auth_email->HoverState->Parent = this->guna2TextBox_auth_email;
			this->guna2TextBox_auth_email->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_auth_email.IconLeft")));
			this->guna2TextBox_auth_email->Location = System::Drawing::Point(42, 111);
			this->guna2TextBox_auth_email->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_auth_email->Name = L"guna2TextBox_auth_email";
			this->guna2TextBox_auth_email->PasswordChar = '\0';
			this->guna2TextBox_auth_email->PlaceholderText = L"Email";
			this->guna2TextBox_auth_email->SelectedText = L"";
			this->guna2TextBox_auth_email->ShadowDecoration->Parent = this->guna2TextBox_auth_email;
			this->guna2TextBox_auth_email->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_auth_email->TabIndex = 2;
			// 
			// gunaLabel1
			// 
			this->gunaLabel1->AutoSize = true;
			this->gunaLabel1->BackColor = System::Drawing::Color::White;
			this->gunaLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)));
			this->gunaLabel1->Location = System::Drawing::Point(88, 37);
			this->gunaLabel1->Name = L"gunaLabel1";
			this->gunaLabel1->Size = System::Drawing::Size(212, 41);
			this->gunaLabel1->TabIndex = 1;
			this->gunaLabel1->Text = L"Авторизация";
			// 
			// PictureBox_Auth_White
			// 
			this->PictureBox_Auth_White->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->PictureBox_Auth_White->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_Auth_White.Image")));
			this->PictureBox_Auth_White->Location = System::Drawing::Point(0, 483);
			this->PictureBox_Auth_White->Name = L"PictureBox_Auth_White";
			this->PictureBox_Auth_White->ShadowDecoration->Parent = this->PictureBox_Auth_White;
			this->PictureBox_Auth_White->Size = System::Drawing::Size(1325, 191);
			this->PictureBox_Auth_White->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PictureBox_Auth_White->TabIndex = 1;
			this->PictureBox_Auth_White->TabStop = false;
			// 
			// gunaPanel_reg
			// 
			this->gunaPanel_reg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gunaPanel_reg->BackColor = System::Drawing::Color::White;
			this->gunaPanel_reg->Controls->Add(this->guna2TextBox_reg_surname);
			this->gunaPanel_reg->Controls->Add(this->guna2TextBox_reg_name);
			this->gunaPanel_reg->Controls->Add(this->PictureBox_reg_back_blue);
			this->gunaPanel_reg->Controls->Add(this->guna2TextBox_reg_rep_pass);
			this->gunaPanel_reg->Controls->Add(this->guna2Button_reg_registration);
			this->gunaPanel_reg->Controls->Add(this->guna2TextBox_reg_pass);
			this->gunaPanel_reg->Controls->Add(this->guna2TextBox_reg_email);
			this->gunaPanel_reg->Controls->Add(this->gunaLabel2);
			this->gunaPanel_reg->Location = System::Drawing::Point(854, 12);
			this->gunaPanel_reg->Name = L"gunaPanel_reg";
			this->gunaPanel_reg->Size = System::Drawing::Size(386, 465);
			this->gunaPanel_reg->TabIndex = 5;
			// 
			// guna2TextBox_reg_surname
			// 
			this->guna2TextBox_reg_surname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_reg_surname->Animated = true;
			this->guna2TextBox_reg_surname->BackColor = System::Drawing::SystemColors::Window;
			this->guna2TextBox_reg_surname->BorderRadius = 8;
			this->guna2TextBox_reg_surname->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_reg_surname->DefaultText = L"";
			this->guna2TextBox_reg_surname->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_reg_surname->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_reg_surname->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_surname->DisabledState->Parent = this->guna2TextBox_reg_surname;
			this->guna2TextBox_reg_surname->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_surname->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_surname->FocusedState->Parent = this->guna2TextBox_reg_surname;
			this->guna2TextBox_reg_surname->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_reg_surname->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_surname->HoverState->Parent = this->guna2TextBox_reg_surname;
			this->guna2TextBox_reg_surname->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_reg_surname.IconLeft")));
			this->guna2TextBox_reg_surname->Location = System::Drawing::Point(42, 228);
			this->guna2TextBox_reg_surname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_reg_surname->Name = L"guna2TextBox_reg_surname";
			this->guna2TextBox_reg_surname->PasswordChar = '\0';
			this->guna2TextBox_reg_surname->PlaceholderText = L"Фамилия";
			this->guna2TextBox_reg_surname->SelectedText = L"";
			this->guna2TextBox_reg_surname->ShadowDecoration->Parent = this->guna2TextBox_reg_surname;
			this->guna2TextBox_reg_surname->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_reg_surname->TabIndex = 9;
			// 
			// guna2TextBox_reg_name
			// 
			this->guna2TextBox_reg_name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_reg_name->Animated = true;
			this->guna2TextBox_reg_name->BackColor = System::Drawing::SystemColors::Window;
			this->guna2TextBox_reg_name->BorderRadius = 8;
			this->guna2TextBox_reg_name->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_reg_name->DefaultText = L"";
			this->guna2TextBox_reg_name->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_reg_name->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_reg_name->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_name->DisabledState->Parent = this->guna2TextBox_reg_name;
			this->guna2TextBox_reg_name->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_name->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_name->FocusedState->Parent = this->guna2TextBox_reg_name;
			this->guna2TextBox_reg_name->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_reg_name->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_name->HoverState->Parent = this->guna2TextBox_reg_name;
			this->guna2TextBox_reg_name->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_reg_name.IconLeft")));
			this->guna2TextBox_reg_name->Location = System::Drawing::Point(42, 170);
			this->guna2TextBox_reg_name->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_reg_name->Name = L"guna2TextBox_reg_name";
			this->guna2TextBox_reg_name->PasswordChar = '\0';
			this->guna2TextBox_reg_name->PlaceholderText = L"Имя";
			this->guna2TextBox_reg_name->SelectedText = L"";
			this->guna2TextBox_reg_name->ShadowDecoration->Parent = this->guna2TextBox_reg_name;
			this->guna2TextBox_reg_name->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_reg_name->TabIndex = 8;
			// 
			// PictureBox_reg_back_blue
			// 
			this->PictureBox_reg_back_blue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_reg_back_blue.Image")));
			this->PictureBox_reg_back_blue->Location = System::Drawing::Point(3, 3);
			this->PictureBox_reg_back_blue->Name = L"PictureBox_reg_back_blue";
			this->PictureBox_reg_back_blue->ShadowDecoration->Parent = this->PictureBox_reg_back_blue;
			this->PictureBox_reg_back_blue->Size = System::Drawing::Size(68, 47);
			this->PictureBox_reg_back_blue->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox_reg_back_blue->TabIndex = 9;
			this->PictureBox_reg_back_blue->TabStop = false;
			this->PictureBox_reg_back_blue->Click += gcnew System::EventHandler(this, &AuthForm::PictureBox_reg_back_blue_Click);
			// 
			// guna2TextBox_reg_rep_pass
			// 
			this->guna2TextBox_reg_rep_pass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_reg_rep_pass->Animated = true;
			this->guna2TextBox_reg_rep_pass->BackColor = System::Drawing::SystemColors::Window;
			this->guna2TextBox_reg_rep_pass->BorderRadius = 8;
			this->guna2TextBox_reg_rep_pass->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_reg_rep_pass->DefaultText = L"";
			this->guna2TextBox_reg_rep_pass->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_reg_rep_pass->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_reg_rep_pass->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_rep_pass->DisabledState->Parent = this->guna2TextBox_reg_rep_pass;
			this->guna2TextBox_reg_rep_pass->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_rep_pass->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_rep_pass->FocusedState->Parent = this->guna2TextBox_reg_rep_pass;
			this->guna2TextBox_reg_rep_pass->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_reg_rep_pass->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_rep_pass->HoverState->Parent = this->guna2TextBox_reg_rep_pass;
			this->guna2TextBox_reg_rep_pass->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_reg_rep_pass.IconLeft")));
			this->guna2TextBox_reg_rep_pass->Location = System::Drawing::Point(42, 343);
			this->guna2TextBox_reg_rep_pass->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_reg_rep_pass->Name = L"guna2TextBox_reg_rep_pass";
			this->guna2TextBox_reg_rep_pass->PasswordChar = '*';
			this->guna2TextBox_reg_rep_pass->PlaceholderText = L"Повторите пароль";
			this->guna2TextBox_reg_rep_pass->SelectedText = L"";
			this->guna2TextBox_reg_rep_pass->ShadowDecoration->Parent = this->guna2TextBox_reg_rep_pass;
			this->guna2TextBox_reg_rep_pass->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_reg_rep_pass->TabIndex = 11;
			// 
			// guna2Button_reg_registration
			// 
			this->guna2Button_reg_registration->Animated = true;
			this->guna2Button_reg_registration->BorderRadius = 8;
			this->guna2Button_reg_registration->CheckedState->Parent = this->guna2Button_reg_registration;
			this->guna2Button_reg_registration->CustomImages->Parent = this->guna2Button_reg_registration;
			this->guna2Button_reg_registration->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->guna2Button_reg_registration->ForeColor = System::Drawing::Color::White;
			this->guna2Button_reg_registration->HoverState->Parent = this->guna2Button_reg_registration;
			this->guna2Button_reg_registration->Location = System::Drawing::Point(112, 405);
			this->guna2Button_reg_registration->Name = L"guna2Button_reg_registration";
			this->guna2Button_reg_registration->ShadowDecoration->Parent = this->guna2Button_reg_registration;
			this->guna2Button_reg_registration->Size = System::Drawing::Size(166, 45);
			this->guna2Button_reg_registration->TabIndex = 12;
			this->guna2Button_reg_registration->Text = L"Регистрация";
			this->guna2Button_reg_registration->Click += gcnew System::EventHandler(this, &AuthForm::guna2Button_reg_registration_Click);
			// 
			// guna2TextBox_reg_pass
			// 
			this->guna2TextBox_reg_pass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_reg_pass->Animated = true;
			this->guna2TextBox_reg_pass->BackColor = System::Drawing::SystemColors::Window;
			this->guna2TextBox_reg_pass->BorderRadius = 8;
			this->guna2TextBox_reg_pass->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_reg_pass->DefaultText = L"";
			this->guna2TextBox_reg_pass->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_reg_pass->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_reg_pass->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_pass->DisabledState->Parent = this->guna2TextBox_reg_pass;
			this->guna2TextBox_reg_pass->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_pass->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_pass->FocusedState->Parent = this->guna2TextBox_reg_pass;
			this->guna2TextBox_reg_pass->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_reg_pass->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_pass->HoverState->Parent = this->guna2TextBox_reg_pass;
			this->guna2TextBox_reg_pass->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_reg_pass.IconLeft")));
			this->guna2TextBox_reg_pass->Location = System::Drawing::Point(42, 285);
			this->guna2TextBox_reg_pass->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_reg_pass->Name = L"guna2TextBox_reg_pass";
			this->guna2TextBox_reg_pass->PasswordChar = '*';
			this->guna2TextBox_reg_pass->PlaceholderText = L"Пароль";
			this->guna2TextBox_reg_pass->SelectedText = L"";
			this->guna2TextBox_reg_pass->ShadowDecoration->Parent = this->guna2TextBox_reg_pass;
			this->guna2TextBox_reg_pass->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_reg_pass->TabIndex = 10;
			// 
			// guna2TextBox_reg_email
			// 
			this->guna2TextBox_reg_email->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->guna2TextBox_reg_email->Animated = true;
			this->guna2TextBox_reg_email->BackColor = System::Drawing::Color::White;
			this->guna2TextBox_reg_email->BorderRadius = 8;
			this->guna2TextBox_reg_email->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->guna2TextBox_reg_email->DefaultText = L"";
			this->guna2TextBox_reg_email->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->guna2TextBox_reg_email->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->guna2TextBox_reg_email->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_email->DisabledState->Parent = this->guna2TextBox_reg_email;
			this->guna2TextBox_reg_email->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->guna2TextBox_reg_email->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_email->FocusedState->Parent = this->guna2TextBox_reg_email;
			this->guna2TextBox_reg_email->ForeColor = System::Drawing::Color::Black;
			this->guna2TextBox_reg_email->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->guna2TextBox_reg_email->HoverState->Parent = this->guna2TextBox_reg_email;
			this->guna2TextBox_reg_email->IconLeft = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2TextBox_reg_email.IconLeft")));
			this->guna2TextBox_reg_email->Location = System::Drawing::Point(42, 111);
			this->guna2TextBox_reg_email->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->guna2TextBox_reg_email->Name = L"guna2TextBox_reg_email";
			this->guna2TextBox_reg_email->PasswordChar = '\0';
			this->guna2TextBox_reg_email->PlaceholderText = L"Email";
			this->guna2TextBox_reg_email->SelectedText = L"";
			this->guna2TextBox_reg_email->ShadowDecoration->Parent = this->guna2TextBox_reg_email;
			this->guna2TextBox_reg_email->Size = System::Drawing::Size(310, 44);
			this->guna2TextBox_reg_email->TabIndex = 7;
			// 
			// gunaLabel2
			// 
			this->gunaLabel2->AutoSize = true;
			this->gunaLabel2->BackColor = System::Drawing::Color::White;
			this->gunaLabel2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaLabel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)));
			this->gunaLabel2->Location = System::Drawing::Point(95, 37);
			this->gunaLabel2->Name = L"gunaLabel2";
			this->gunaLabel2->Size = System::Drawing::Size(201, 41);
			this->gunaLabel2->TabIndex = 1;
			this->gunaLabel2->Text = L"Регистрация";
			// 
			// panel_close_auth
			// 
			this->panel_close_auth->Location = System::Drawing::Point(63, 12);
			this->panel_close_auth->Name = L"panel_close_auth";
			this->panel_close_auth->Size = System::Drawing::Size(393, 470);
			this->panel_close_auth->TabIndex = 6;
			// 
			// panel_close_reg
			// 
			this->panel_close_reg->Location = System::Drawing::Point(854, 12);
			this->panel_close_reg->Name = L"panel_close_reg";
			this->panel_close_reg->Size = System::Drawing::Size(393, 470);
			this->panel_close_reg->TabIndex = 7;
			// 
			// panel_back
			// 
			this->panel_back->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel_back->Controls->Add(this->panel_front);
			this->panel_back->Location = System::Drawing::Point(1253, 642);
			this->panel_back->Name = L"panel_back";
			this->panel_back->Size = System::Drawing::Size(60, 20);
			this->panel_back->TabIndex = 7;
			this->panel_back->Visible = false;
			// 
			// panel_front
			// 
			this->panel_front->BackColor = System::Drawing::Color::White;
			this->panel_front->Location = System::Drawing::Point(3, 2);
			this->panel_front->Name = L"panel_front";
			this->panel_front->Size = System::Drawing::Size(24, 16);
			this->panel_front->TabIndex = 8;
			this->panel_front->Visible = false;
			this->panel_front->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AuthForm::panel_front_MouseDown);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &AuthForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &AuthForm::timer2_Tick);
			// 
			// PictureBox__Auth_Dark
			// 
			this->PictureBox__Auth_Dark->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox__Auth_Dark.Image")));
			this->PictureBox__Auth_Dark->Location = System::Drawing::Point(0, 483);
			this->PictureBox__Auth_Dark->Name = L"PictureBox__Auth_Dark";
			this->PictureBox__Auth_Dark->ShadowDecoration->Parent = this->PictureBox__Auth_Dark;
			this->PictureBox__Auth_Dark->Size = System::Drawing::Size(1332, 205);
			this->PictureBox__Auth_Dark->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox__Auth_Dark->TabIndex = 8;
			this->PictureBox__Auth_Dark->TabStop = false;
			// 
			// timer3
			// 
			this->timer3->Interval = 1;
			this->timer3->Tick += gcnew System::EventHandler(this, &AuthForm::timer3_Tick);
			// 
			// PictureBox_Close
			// 
			this->PictureBox_Close->BackColor = System::Drawing::Color::White;
			this->PictureBox_Close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_Close.Image")));
			this->PictureBox_Close->Location = System::Drawing::Point(1289, -1);
			this->PictureBox_Close->Name = L"PictureBox_Close";
			this->PictureBox_Close->ShadowDecoration->Parent = this->PictureBox_Close;
			this->PictureBox_Close->Size = System::Drawing::Size(35, 35);
			this->PictureBox_Close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox_Close->TabIndex = 9;
			this->PictureBox_Close->TabStop = false;
			this->PictureBox_Close->Click += gcnew System::EventHandler(this, &AuthForm::PictureBox_Close_Click);
			this->PictureBox_Close->MouseEnter += gcnew System::EventHandler(this, &AuthForm::PictureBox_Close_MouseEnter);
			this->PictureBox_Close->MouseLeave += gcnew System::EventHandler(this, &AuthForm::PictureBox_Close_MouseLeave);
			// 
			// panel_avatar
			// 
			this->panel_avatar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_avatar->BackColor = System::Drawing::Color::White;
			this->panel_avatar->Controls->Add(this->pictureBox_add_avatar);
			this->panel_avatar->Controls->Add(this->guna2PictureBox1);
			this->panel_avatar->Controls->Add(this->button_add_avatar_in_profil);
			this->panel_avatar->Controls->Add(this->gunaLabel3);
			this->panel_avatar->Location = System::Drawing::Point(70, 12);
			this->panel_avatar->Name = L"panel_avatar";
			this->panel_avatar->Size = System::Drawing::Size(386, 465);
			this->panel_avatar->TabIndex = 13;
			// 
			// pictureBox_add_avatar
			// 
			this->pictureBox_add_avatar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_add_avatar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_add_avatar.Image")));
			this->pictureBox_add_avatar->Location = System::Drawing::Point(94, 93);
			this->pictureBox_add_avatar->Name = L"pictureBox_add_avatar";
			this->pictureBox_add_avatar->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->pictureBox_add_avatar->ShadowDecoration->Parent = this->pictureBox_add_avatar;
			this->pictureBox_add_avatar->Size = System::Drawing::Size(200, 200);
			this->pictureBox_add_avatar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_add_avatar->TabIndex = 13;
			this->pictureBox_add_avatar->TabStop = false;
			this->pictureBox_add_avatar->Click += gcnew System::EventHandler(this, &AuthForm::pictureBox_add_avatar_Click);
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->Location = System::Drawing::Point(3, 3);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(68, 47);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2PictureBox1->TabIndex = 9;
			this->guna2PictureBox1->TabStop = false;
			this->guna2PictureBox1->Visible = false;
			// 
			// button_add_avatar_in_profil
			// 
			this->button_add_avatar_in_profil->Animated = true;
			this->button_add_avatar_in_profil->BorderRadius = 8;
			this->button_add_avatar_in_profil->CheckedState->Parent = this->button_add_avatar_in_profil;
			this->button_add_avatar_in_profil->CustomImages->Parent = this->button_add_avatar_in_profil;
			this->button_add_avatar_in_profil->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_add_avatar_in_profil->ForeColor = System::Drawing::Color::White;
			this->button_add_avatar_in_profil->HoverState->Parent = this->button_add_avatar_in_profil;
			this->button_add_avatar_in_profil->Location = System::Drawing::Point(112, 338);
			this->button_add_avatar_in_profil->Name = L"button_add_avatar_in_profil";
			this->button_add_avatar_in_profil->ShadowDecoration->Parent = this->button_add_avatar_in_profil;
			this->button_add_avatar_in_profil->Size = System::Drawing::Size(166, 45);
			this->button_add_avatar_in_profil->TabIndex = 12;
			this->button_add_avatar_in_profil->Text = L"Завершить";
			this->button_add_avatar_in_profil->Click += gcnew System::EventHandler(this, &AuthForm::button_add_avatar_in_profil_Click);
			// 
			// gunaLabel3
			// 
			this->gunaLabel3->AutoSize = true;
			this->gunaLabel3->BackColor = System::Drawing::Color::White;
			this->gunaLabel3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)));
			this->gunaLabel3->Location = System::Drawing::Point(95, 37);
			this->gunaLabel3->Name = L"gunaLabel3";
			this->gunaLabel3->Size = System::Drawing::Size(201, 41);
			this->gunaLabel3->TabIndex = 1;
			this->gunaLabel3->Text = L"Регистрация";
			// 
			// openFileDialog_add_avatar
			// 
			this->openFileDialog_add_avatar->FileName = L"openFileDialog1";
			// 
			// AuthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1325, 674);
			this->Controls->Add(this->panel_close_auth);
			this->Controls->Add(this->panel_avatar);
			this->Controls->Add(this->PictureBox_Close);
			this->Controls->Add(this->panel_back);
			this->Controls->Add(this->PictureBox_Auth_White);
			this->Controls->Add(this->panel_close_reg);
			this->Controls->Add(this->gunaPanel_reg);
			this->Controls->Add(this->panel_auth);
			this->Controls->Add(this->PictureBox__Auth_Dark);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AuthForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Авторизация";
			this->panel_auth->ResumeLayout(false);
			this->panel_auth->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Auth_White))->EndInit();
			this->gunaPanel_reg->ResumeLayout(false);
			this->gunaPanel_reg->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_reg_back_blue))->EndInit();
			this->panel_back->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox__Auth_Dark))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Close))->EndInit();
			this->panel_avatar->ResumeLayout(false);
			this->panel_avatar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_add_avatar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void guna2Button_auth_login_Click(System::Object^ sender, System::EventArgs^ e);

	private: bool Login(String^ email, String^ password);

	private: void setDataLogin(String^ teme);

	private: System::Void guna2Button_reg_registration_Click(System::Object^ sender, System::EventArgs^ e);

	private: String^ Registration(String^ email, String^ password, String^ name, String^ surname);

	//Обработчик нажатия на ползунок для смены темы программы
	private: System::Void panel_front_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	//Таймер для смены интерфейса
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);

	//Переход в область регистрации
	private: System::Void gunaLabel_reg_Click(System::Object^ sender, System::EventArgs^ e);

	//Таймер для перехода в область регистрации
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e);

	//Кнопка для возвращения в область авторизации
	private: System::Void PictureBox_reg_back_blue_Click(System::Object^ sender, System::EventArgs^ e);

	//Таймер для перехода в область авторизации
	private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e);

	//Кнопка для завершения работы приложения
	private: System::Void PictureBox_Close_Click(System::Object^ sender, System::EventArgs^ e);

	//Обработчик для наведение на кнопку закрытия программы
	private: System::Void PictureBox_Close_MouseEnter(System::Object^ sender, System::EventArgs^ e);

	//Обработчик, когда кнопка закрытия становиться не активной
	private: System::Void PictureBox_Close_MouseLeave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureBox_add_avatar_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_add_avatar_in_profil_Click(System::Object^ sender, System::EventArgs^ e);

	private: void loadAvatar(String^ fileNameServer);

	private: void saveFile(String^ uri, String^ filePath);

	private: void loadsaveAvatar(String^ name_file);
};
}
