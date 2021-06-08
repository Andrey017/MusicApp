#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

using namespace System::Net;
using namespace System::IO;

namespace MusicApp {

	/// <summary>
	/// —водка дл€ RoomItem
	/// </summary>
	public ref class RoomItem : public System::Windows::Forms::UserControl
	{
	public:
		RoomItem(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		RoomItem(String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			teme = _teme;

			SetupInterfaceItem();
		}

	public: void Name_Room(String^ _name_room) {
		name_room = _name_room;

		label_name_room->Text = name_room;
	}

	public: String^ getName_room() {
		return label_name_room->Text;
	}

	public: void ID_room(String^ _id_room) {
		id_room = _id_room;

		label_id_room->Text = id_room;
	}

	public: String^ getId_room() {
		return label_id_room->Text;
	}

	public: void setName_Picture(String^ _name_picture) {
		name_picture = _name_picture;

		loadSaveImage(name_picture);
	}

	public: String^ getName_Picture() {
		return name_picture;
	}

	public: void Prim(String^ _prim) {
		prim = _prim;

		textBox_prim->Text = prim;
	}

	public: String^ getPrim() {
		return textBox_prim->Text;
	}

	public: void creators_Room(String^ _creators_room) {
		creators_room = _creators_room;

		label_creators_room->Text = creators_room;
	}

	public: String^ getcreators_room() {
		return label_creators_room->Text;
	}

	public: String^ id_room;
		  String^ name_room;
		  String^ name_picture;
		  String^ prim;
		  String^ creators_room;

		  String^ teme;
		  String^ ip = "94.141.168.185";

		  //ƒл€ интерфейса
		  int d_r_back = 15;
		  int d_g_back = 19;
		  int d_b_back = 25;

		  int d_r_elem = 32;
		  int d_g_elem = 36;
		  int d_b_elem = 43;

		  int d_text_color = 238;


	private: System::Windows::Forms::Label^ label_id_room;
	private: Guna::UI2::WinForms::Guna2TextBox^ textBox_prim;
	public:

	public:
		String^ count_uv;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~RoomItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ pictureBox_image_room;

	private: System::Windows::Forms::Label^ label_name_room;


	private: System::Windows::Forms::Label^ label_creators_room;
	private: Guna::UI2::WinForms::Guna2Button^ button_count_uv;


	protected:
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RoomItem::typeid));
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->pictureBox_image_room = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->label_name_room = (gcnew System::Windows::Forms::Label());
			this->label_creators_room = (gcnew System::Windows::Forms::Label());
			this->button_count_uv = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->label_id_room = (gcnew System::Windows::Forms::Label());
			this->textBox_prim = (gcnew Guna::UI2::WinForms::Guna2TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_image_room))->BeginInit();
			this->SuspendLayout();
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->BorderRadius = 20;
			this->guna2Elipse1->TargetControl = this;
			// 
			// pictureBox_image_room
			// 
			this->pictureBox_image_room->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_image_room.Image")));
			this->pictureBox_image_room->Location = System::Drawing::Point(12, 8);
			this->pictureBox_image_room->Name = L"pictureBox_image_room";
			this->pictureBox_image_room->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->pictureBox_image_room->ShadowDecoration->Parent = this->pictureBox_image_room;
			this->pictureBox_image_room->Size = System::Drawing::Size(82, 73);
			this->pictureBox_image_room->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_image_room->TabIndex = 0;
			this->pictureBox_image_room->TabStop = false;
			// 
			// label_name_room
			// 
			this->label_name_room->AutoSize = true;
			this->label_name_room->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_room->Location = System::Drawing::Point(100, 26);
			this->label_name_room->Name = L"label_name_room";
			this->label_name_room->Size = System::Drawing::Size(149, 35);
			this->label_name_room->TabIndex = 1;
			this->label_name_room->Text = L"name_room";
			// 
			// label_creators_room
			// 
			this->label_creators_room->AutoSize = true;
			this->label_creators_room->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_creators_room->Location = System::Drawing::Point(12, 88);
			this->label_creators_room->Name = L"label_creators_room";
			this->label_creators_room->Size = System::Drawing::Size(97, 19);
			this->label_creators_room->TabIndex = 3;
			this->label_creators_room->Text = L"creators_room";
			this->label_creators_room->Visible = false;
			// 
			// button_count_uv
			// 
			this->button_count_uv->BorderRadius = 8;
			this->button_count_uv->CheckedState->Parent = this->button_count_uv;
			this->button_count_uv->CustomImages->Parent = this->button_count_uv;
			this->button_count_uv->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->button_count_uv->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->button_count_uv->ForeColor = System::Drawing::Color::White;
			this->button_count_uv->HoverState->Parent = this->button_count_uv;
			this->button_count_uv->Location = System::Drawing::Point(327, 77);
			this->button_count_uv->Name = L"button_count_uv";
			this->button_count_uv->ShadowDecoration->Parent = this->button_count_uv;
			this->button_count_uv->Size = System::Drawing::Size(36, 36);
			this->button_count_uv->TabIndex = 4;
			this->button_count_uv->TabStop = false;
			this->button_count_uv->Text = L"0";
			// 
			// label_id_room
			// 
			this->label_id_room->AutoSize = true;
			this->label_id_room->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_id_room->Location = System::Drawing::Point(147, 88);
			this->label_id_room->Name = L"label_id_room";
			this->label_id_room->Size = System::Drawing::Size(59, 19);
			this->label_id_room->TabIndex = 5;
			this->label_id_room->Text = L"id_room";
			this->label_id_room->Visible = false;
			// 
			// textBox_prim
			// 
			this->textBox_prim->BackColor = System::Drawing::Color::White;
			this->textBox_prim->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->textBox_prim->BorderColor = System::Drawing::Color::White;
			this->textBox_prim->BorderThickness = 0;
			this->textBox_prim->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_prim->DefaultText = L"";
			this->textBox_prim->DisabledState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(208)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)), static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->textBox_prim->DisabledState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->textBox_prim->DisabledState->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_prim->DisabledState->Parent = this->textBox_prim;
			this->textBox_prim->DisabledState->PlaceholderForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->textBox_prim->Enabled = false;
			this->textBox_prim->FocusedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_prim->FocusedState->Parent = this->textBox_prim;
			this->textBox_prim->ForeColor = System::Drawing::Color::Black;
			this->textBox_prim->HoverState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox_prim->HoverState->Parent = this->textBox_prim;
			this->textBox_prim->Location = System::Drawing::Point(90, 23);
			this->textBox_prim->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->textBox_prim->Multiline = true;
			this->textBox_prim->Name = L"textBox_prim";
			this->textBox_prim->PasswordChar = '\0';
			this->textBox_prim->PlaceholderForeColor = System::Drawing::Color::Black;
			this->textBox_prim->PlaceholderText = L"";
			this->textBox_prim->ReadOnly = true;
			this->textBox_prim->SelectedText = L"";
			this->textBox_prim->ShadowDecoration->Parent = this->textBox_prim;
			this->textBox_prim->Size = System::Drawing::Size(233, 51);
			this->textBox_prim->TabIndex = 2;
			this->textBox_prim->TabStop = false;
			this->textBox_prim->Visible = false;
			// 
			// RoomItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Controls->Add(this->label_id_room);
			this->Controls->Add(this->button_count_uv);
			this->Controls->Add(this->label_creators_room);
			this->Controls->Add(this->label_name_room);
			this->Controls->Add(this->pictureBox_image_room);
			this->Controls->Add(this->textBox_prim);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->Name = L"RoomItem";
			this->Size = System::Drawing::Size(367, 117);
			this->Load += gcnew System::EventHandler(this, &RoomItem::RoomItem_Load);
			this->MouseEnter += gcnew System::EventHandler(this, &RoomItem::RoomItem_MouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &RoomItem::RoomItem_MouseLeave);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_image_room))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RoomItem_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		if (teme == "0") {
			this->BackColor = Color::FromArgb(241, 241, 241);
		}
		else {
			this->BackColor = Color::FromArgb(40, 40, 40);
			label_name_room->BackColor = Color::FromArgb(40, 40, 40);
			label_creators_room->BackColor = Color::FromArgb(40, 40, 40);
		}
	}

	private: System::Void RoomItem_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (teme == "0") {
			this->BackColor = Color::White;
		}
		else {
			this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_name_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_creators_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		}
	}

	private: System::Void RoomItem_Load(System::Object^ sender, System::EventArgs^ e) {
		/*System::Drawing::Drawing2D::GraphicsPath^ Form_Path = gcnew System::Drawing::Drawing2D::GraphicsPath();
		Form_Path->AddEllipse(-20, -20, this->Width, this->Height);
		this->Region = gcnew System::Drawing::Region(Form_Path);*/

	}

	private: void SetupInterfaceItem() {
		if (teme == "1") {
			label_name_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_name_room->ForeColor = Color::FromArgb(241, 241, 241);

			label_creators_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_creators_room->ForeColor = Color::FromArgb(241, 241, 241);
		}
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

		pictureBox_image_room->Image = Image::FromStream(memoryStream_in);

		memoryStream_in->Close();
	}
};
}
