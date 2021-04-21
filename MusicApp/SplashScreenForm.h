#pragma once

#include "AuthForm.h"
#include "HomeForm.h"

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ SplashScreenForm
	/// </summary>
	public ref class SplashScreenForm : public System::Windows::Forms::Form
	{
	public:
		SplashScreenForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			gl_new_app = LoadDataApp();

			gl_ip = loadDataIP();
			gl_teme = loadDataTeme();
			gl_checkLogin = loadDataCheckLogin();
			gl_nameUser = loadDataNameUser();
			gl_idUser = loadDataIdUser();
			gl_name_avatar = loadDataNameAvatar();
		}

	private:  String^ gl_new_app;
		      String^ gl_ip;
		      String^ gl_teme;
		      String^ gl_checkLogin;
		      String^ gl_nameUser;
		      String^ gl_idUser;
			  String^ gl_name_avatar;


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SplashScreenForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2PictureBox^ PictureBox_Auth_White;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SplashScreenForm::typeid));
			this->PictureBox_Auth_White = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel2 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Auth_White))->BeginInit();
			this->guna2Panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// PictureBox_Auth_White
			// 
			this->PictureBox_Auth_White->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->PictureBox_Auth_White->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox_Auth_White.Image")));
			this->PictureBox_Auth_White->Location = System::Drawing::Point(0, 148);
			this->PictureBox_Auth_White->Name = L"PictureBox_Auth_White";
			this->PictureBox_Auth_White->ShadowDecoration->Parent = this->PictureBox_Auth_White;
			this->PictureBox_Auth_White->Size = System::Drawing::Size(895, 175);
			this->PictureBox_Auth_White->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PictureBox_Auth_White->TabIndex = 2;
			this->PictureBox_Auth_White->TabStop = false;
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->Controls->Add(this->guna2Panel2);
			this->guna2Panel1->Location = System::Drawing::Point(62, 117);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->ShadowDecoration->Parent = this->guna2Panel1;
			this->guna2Panel1->Size = System::Drawing::Size(780, 30);
			this->guna2Panel1->TabIndex = 3;
			// 
			// guna2Panel2
			// 
			this->guna2Panel2->BackColor = System::Drawing::Color::White;
			this->guna2Panel2->Location = System::Drawing::Point(3, 3);
			this->guna2Panel2->Name = L"guna2Panel2";
			this->guna2Panel2->ShadowDecoration->Parent = this->guna2Panel2;
			this->guna2Panel2->Size = System::Drawing::Size(20, 25);
			this->guna2Panel2->TabIndex = 4;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &SplashScreenForm::timer1_Tick);
			// 
			// SplashScreenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->ClientSize = System::Drawing::Size(895, 323);
			this->Controls->Add(this->guna2Panel1);
			this->Controls->Add(this->PictureBox_Auth_White);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"SplashScreenForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SplashScreenForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox_Auth_White))->EndInit();
			this->guna2Panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		guna2Panel2->Width += 20;

		if (guna2Panel2->Width >= 774) {
			timer1->Stop();

			if (gl_checkLogin == "1") {
				int _id = Convert::ToInt32(gl_idUser);
				HomeForm^ homeForm = gcnew HomeForm(_id, gl_nameUser, gl_teme, gl_name_avatar);
				homeForm->Show();
				this->Hide();
			}
			else {
				AuthForm^ authForm = gcnew AuthForm();
				authForm->Show();
				this->Hide();
			}
		}
	}

	private: String^ LoadDataApp() {
		String^ newApp = "0";

		String^ ip = loadDataIP();
		String^ teme = loadDataTeme();
		String^ checkLogin = loadDataCheckLogin();
		String^ nameUser = loadDataNameUser();
		String^ idUser = loadDataIdUser();
		String^ name_avatar = loadDataNameAvatar();

		if (ip == "" || teme == "" || checkLogin == "" || nameUser == "") {
			setDataApp("94.141.168.185", "0", "0", "0", "0", "0");
			return newApp;
		}
		else {
			newApp = "1";
			return newApp;
		}
	}

	private: String^ loadDataTeme() {
		String^ teme;

		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		try {
			Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp");

			teme = pathFileReport->GetValue("teme")->ToString();

			pathFileReport->Close();
		}
		catch (NullReferenceException^ e) {
			teme = "";
		}

		return teme;
	}

	private: String^ loadDataIP() {
		String^ ip;

		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		try {
			Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp");

			ip = pathFileReport->GetValue("ip")->ToString();

			pathFileReport->Close();
		}
		catch (NullReferenceException^ e) {
			ip = "";
		}

		return ip;
	}

	private: String^ loadDataCheckLogin() {
		String^ checkLogin;

		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		try {
			Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp");

			checkLogin = pathFileReport->GetValue("checkLogin")->ToString();

			pathFileReport->Close();
		}
		catch (NullReferenceException^ e) {
			checkLogin = "";
		}

		return checkLogin;
	}

	private: String^ loadDataNameUser() {
		String^ name_user;

		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		try {
			Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp");

			name_user = pathFileReport->GetValue("nameUser")->ToString();

			pathFileReport->Close();
		}
		catch (NullReferenceException^ e) {
			name_user = "";
		}

		return name_user;
	}

	private: String^ loadDataIdUser() {
		String^ id_user;

		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		try {
			Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp");

			id_user = pathFileReport->GetValue("userId")->ToString();

			pathFileReport->Close();
		}
		catch (NullReferenceException^ e) {
			id_user = "";
		}

		return id_user;
	}

	private: String^ loadDataNameAvatar() {
		String^ name_avatar;

		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		try {
			Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->OpenSubKey("MusicApp");

			name_avatar = pathFileReport->GetValue("avatar")->ToString();

			pathFileReport->Close();
		}
		catch (NullReferenceException^ e) {
			name_avatar = "";
		}

		return name_avatar;
	}

	private: void setDataApp(String^ ip, String^ teme, String^ checkLogin, String^ nameUser, String^ idUser, String^ name_avatar) {
		Microsoft::Win32::RegistryKey^ currentPathKEY = Microsoft::Win32::Registry::CurrentUser;

		Microsoft::Win32::RegistryKey^ pathFileReport = currentPathKEY->CreateSubKey("MusicApp");

		pathFileReport->SetValue("ip", ip);
		pathFileReport->SetValue("teme", teme);
		pathFileReport->SetValue("checkLogin", checkLogin);
		pathFileReport->SetValue("nameUser", nameUser);
		pathFileReport->SetValue("userId", idUser);
		pathFileReport->SetValue("avatar", name_avatar);

		pathFileReport->Close();
	}
};
}
