#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Net;
using namespace System::IO;

namespace MusicApp {

	/// <summary>
	/// —водка дл€ ListUserItem
	/// </summary>
	public ref class ListUserItem : public System::Windows::Forms::UserControl
	{
	public:
		ListUserItem(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		ListUserItem(String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			teme = _teme;

			if (teme == "1") {
				SetupInterfaceItem();
			}
		}

	private: String^ teme;
		   String^ ip = "94.141.168.185";
		   String^ path_image;

		   //ƒл€ интерфейса
		   int d_r_back = 15;
		   int d_g_back = 19;
		   int d_b_back = 25;

		   int d_r_elem = 32;
		   int d_g_elem = 36;
		   int d_b_elem = 43;
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;

		   int d_text_color = 238;

	public: void setName_User(String^ _name_user) {
		textBox_name_user->Text = _name_user;
	}

	public: String^ getName_User() {
		return textBox_name_user->Text;
	}

	public: void setPhoto_User(String^ _path_photo) {
		path_image = _path_photo;

		loadSaveImage(path_image);		
	}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ListUserItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ photo_user;
	protected:

	private: System::Windows::Forms::TextBox^ textBox_name_user;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListUserItem::typeid));
			this->photo_user = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->textBox_name_user = (gcnew System::Windows::Forms::TextBox());
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photo_user))->BeginInit();
			this->SuspendLayout();
			// 
			// photo_user
			// 
			this->photo_user->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->photo_user->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"photo_user.Image")));
			this->photo_user->Location = System::Drawing::Point(16, 9);
			this->photo_user->Name = L"photo_user";
			this->photo_user->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->photo_user->ShadowDecoration->Parent = this->photo_user;
			this->photo_user->Size = System::Drawing::Size(36, 36);
			this->photo_user->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->photo_user->TabIndex = 1;
			this->photo_user->TabStop = false;
			// 
			// textBox_name_user
			// 
			this->textBox_name_user->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_name_user->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->textBox_name_user->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_name_user->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_name_user->Location = System::Drawing::Point(58, 17);
			this->textBox_name_user->MaxLength = 30;
			this->textBox_name_user->Name = L"textBox_name_user";
			this->textBox_name_user->ReadOnly = true;
			this->textBox_name_user->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox_name_user->Size = System::Drawing::Size(172, 23);
			this->textBox_name_user->TabIndex = 11;
			this->textBox_name_user->TabStop = false;
			this->textBox_name_user->Text = L"name surname";
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->TargetControl = this;
			// 
			// ListUserItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->textBox_name_user);
			this->Controls->Add(this->photo_user);
			this->Name = L"ListUserItem";
			this->Size = System::Drawing::Size(249, 56);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photo_user))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void SetupInterfaceItem() {		
		textBox_name_user->BackColor = Color::FromArgb(d_r_elem, d_g_elem, d_b_elem);
		textBox_name_user->ForeColor = Color::White;
	}

	private: void loadSaveImage(String^ name_image) {
		String^ link = "http://" + ip + ":8011/uploads/picture/" + name_image;

		WebRequest^ request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(link));

		System::IO::MemoryStream^ memoryStream_in = gcnew System::IO::MemoryStream();

		try {
			WebResponse^ response = request->GetResponse();

			Stream^ data = response->GetResponseStream();

			int count = 0;

			do {
				array<Byte>^ buff = gcnew array<Byte>(1024);

				count = data->Read(buff, 0, 1024);

				memoryStream_in->Write(buff, 0, count);
			} while (data->CanRead && count > 0);

			response->Close();
		}
		catch (Exception^ e) {
			Console::Write(e->Message);
		}

		photo_user->Image = Image::FromStream(memoryStream_in);

		memoryStream_in->Close();
	}
};
}
