#pragma once

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

using namespace CefSharp;
using namespace CefSharp::WinForms;

using namespace System::Threading;

using namespace NAudio::Wave;
using namespace NAudio::FileFormats;
using namespace NAudio::CoreAudioApi;
using namespace NAudio;

namespace MusicApp {

	/// <summary>
	/// Сводка для ListWayItem
	/// </summary>
	public ref class ListWayItem : public System::Windows::Forms::UserControl
	{
	public:
		ListWayItem(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		ListWayItem(String^ _teme, String^ _ip)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			teme = _teme;
			ip = _ip;

			if (teme == "1") {
				SetupInterface();
			}
		}

	public: void setID_way(String^ _id) {
		id = _id;

		label_id->Text = id;
	}

	public: String^ getID_way() {
		return id;
	}

	public: void setName_Way(String^ _name_way) {
		name_way = _name_way;

		label_name_way->Text = name_way;
	}

	public: String^ getName_Way() {
		return name_way;
	}

	public: void setName_Room(String^ _name_room) {
		name_room = _name_room;

		label_name_room->Text = name_room;
	}

	public: String^ getName_Room() {
		return name_room;
	}

	public: void setPath_Picture(String^ _path_picture) {
		path_picture = _path_picture;
	}

	private: String^ path_picture;
		   String^ name_way;
		   String^ name_room;
		   String^ id;

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

	private: Guna::UI2::WinForms::Guna2CircleProgressBar^ guna2CircleProgressBar1;

	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox2;


	private: System::Windows::Forms::Label^ label_id;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ListWayItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2PictureBox^ guna2PictureBox1;
	private: System::Windows::Forms::Label^ label_name_room;

	private: System::Windows::Forms::Label^ label_name_way;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListWayItem::typeid));
			this->guna2PictureBox1 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_name_room = (gcnew System::Windows::Forms::Label());
			this->label_name_way = (gcnew System::Windows::Forms::Label());
			this->label_id = (gcnew System::Windows::Forms::Label());
			this->guna2CircleProgressBar1 = (gcnew Guna::UI2::WinForms::Guna2CircleProgressBar());
			this->guna2PictureBox2 = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// guna2PictureBox1
			// 
			this->guna2PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox1.Image")));
			this->guna2PictureBox1->Location = System::Drawing::Point(3, 14);
			this->guna2PictureBox1->Name = L"guna2PictureBox1";
			this->guna2PictureBox1->ShadowDecoration->Parent = this->guna2PictureBox1;
			this->guna2PictureBox1->Size = System::Drawing::Size(50, 50);
			this->guna2PictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2PictureBox1->TabIndex = 0;
			this->guna2PictureBox1->TabStop = false;
			// 
			// label_name_room
			// 
			this->label_name_room->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_name_room->AutoSize = true;
			this->label_name_room->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_room->Location = System::Drawing::Point(59, 40);
			this->label_name_room->Name = L"label_name_room";
			this->label_name_room->Size = System::Drawing::Size(104, 23);
			this->label_name_room->TabIndex = 4;
			this->label_name_room->Text = L"Name_room";
			this->label_name_room->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_name_way
			// 
			this->label_name_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_name_way->AutoSize = true;
			this->label_name_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_way->Location = System::Drawing::Point(59, 14);
			this->label_name_way->Name = L"label_name_way";
			this->label_name_way->Size = System::Drawing::Size(92, 23);
			this->label_name_way->TabIndex = 3;
			this->label_name_way->Text = L"Name_way";
			this->label_name_way->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_id
			// 
			this->label_id->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_id->AutoSize = true;
			this->label_id->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_id->Location = System::Drawing::Point(223, 14);
			this->label_id->Name = L"label_id";
			this->label_id->Size = System::Drawing::Size(60, 23);
			this->label_id->TabIndex = 5;
			this->label_id->Text = L"way_id";
			this->label_id->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_id->Visible = false;
			// 
			// guna2CircleProgressBar1
			// 
			this->guna2CircleProgressBar1->FillThickness = 7;
			this->guna2CircleProgressBar1->Location = System::Drawing::Point(277, 14);
			this->guna2CircleProgressBar1->Name = L"guna2CircleProgressBar1";
			this->guna2CircleProgressBar1->ProgressThickness = 10;
			this->guna2CircleProgressBar1->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CircleProgressBar1->ShadowDecoration->Parent = this->guna2CircleProgressBar1;
			this->guna2CircleProgressBar1->Size = System::Drawing::Size(50, 50);
			this->guna2CircleProgressBar1->TabIndex = 6;
			this->guna2CircleProgressBar1->Visible = false;
			// 
			// guna2PictureBox2
			// 
			this->guna2PictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2PictureBox2.Image")));
			this->guna2PictureBox2->Location = System::Drawing::Point(281, 19);
			this->guna2PictureBox2->Name = L"guna2PictureBox2";
			this->guna2PictureBox2->ShadowDecoration->Parent = this->guna2PictureBox2;
			this->guna2PictureBox2->Size = System::Drawing::Size(40, 40);
			this->guna2PictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2PictureBox2->TabIndex = 7;
			this->guna2PictureBox2->TabStop = false;
			// 
			// ListWayItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->guna2PictureBox2);
			this->Controls->Add(this->guna2CircleProgressBar1);
			this->Controls->Add(this->label_id);
			this->Controls->Add(this->label_name_room);
			this->Controls->Add(this->label_name_way);
			this->Controls->Add(this->guna2PictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ListWayItem";
			this->Size = System::Drawing::Size(330, 79);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2PictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: String^ gl_size_file;

	public: void SaveFileInTemp() {
		String^ room_id = label_id->Text;
		String^ name_file = label_name_way->Text;

		String^ link = "http://" + ip + ":8011/uploads/" + room_id + "/" + name_file;

		WebRequest^ request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(link));

		System::IO::MemoryStream^ memoryStream_in = gcnew System::IO::MemoryStream();

		try {
			//guna2CircleProgressBar1->Visible = true;

			WebResponse^ response = request->GetResponse();

			Stream^ data = response->GetResponseStream();

			int count = 0;

			do {
				array<Byte>^ buff = gcnew array<Byte>(1024);

				count = data->Read(buff, 0, 1024);

				memoryStream_in->Write(buff, 0, count);

				//guna2CircleProgressBar1->Value++;

			} while (data->CanRead && count > 0);

			response->Close();
		}
		catch (Exception^ e) {
			Console::Write(e->Message);
		}

		FileStream^ fileStream = gcnew FileStream("./load/audio/temp/" + name_file, FileMode::Create, FileAccess::Write);

		memoryStream_in->WriteTo(fileStream);

		memoryStream_in->Close();
		fileStream->Close();

		guna2PictureBox2->Visible = false;
	}

	public: void OnDownloadProgressChanged(System::Object^ sender, System::Net::DownloadProgressChangedEventArgs^ e) {

		//label_progress->Text = "Размер файла: " + gl_size_file + "\nЗагружено: " + e->ProgressPercentage + "% (" + ((double)e->BytesReceived / 1048576) + ") Мб";
		//guna2CircleProgressBar1->Value = e->ProgressPercentage;
	}

	private: void SetupInterface() {
		this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);

		label_name_way->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		label_name_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		label_name_room->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		label_name_room->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);

		guna2PictureBox1->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		guna2PictureBox1->Image = Image::FromFile("./image/icons8_music_100px_white.png");

		//pictureBox_load->Image = Image::FromFile("./image/icons8_download_50px_white.png");
	}

	};
}
