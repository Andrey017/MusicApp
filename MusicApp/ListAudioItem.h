#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Net;
using namespace System::Threading;
using namespace System::IO;


namespace MusicApp {

	/// <summary>
	/// Сводка для ListAudioItem
	/// </summary>
	public ref class ListAudioItem : public System::Windows::Forms::UserControl
	{
	public:
		ListAudioItem(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		ListAudioItem(String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			teme = _teme;

			SetupInterface();
		}

	public: void setName_Audio(String^ _name_audio) {
		name_audio = _name_audio;
		label_name_audio->Text = name_audio;
	}

	public: String^ getName_Audio() {
		return label_name_audio->Text;
	}

	public: void setName_Creator_Audio(String^ _name_creator_audio) {
		name_creator_audio = _name_creator_audio;
		label_name_creator_audio->Text = name_creator_audio;
	}

	public: String^ getName_Creator_Audio() {
		return label_name_creator_audio->Text;
	}

	public: void setPath_Picture_Audio(String^ _path_picture_audio) {
		path_picture_audio = _path_picture_audio;

		loadSaveImage(path_picture_audio);
	}

	public: String^ getPath_Picture_Audio() {
		return path_picture_audio;
	}

	public: void setCheckDownload(bool _checkDownload) {
		if (teme == "1") {
			if (_checkDownload) {
				pictureBox_download->Image = Image::FromFile("./image/icons8_play_100px_white.png");
			}
			else {
				pictureBox_download->Image = Image::FromFile("./image/icons8_download_50px_white.png");
			}
		}
		else {
			if (_checkDownload) {
				pictureBox_download->Image = Image::FromFile("./image/icons8_play_100px_black.png");
			}
			else {
				pictureBox_download->Image = Image::FromFile("./image/icons8_download_50px_black.png");
			}
		}
	}

	public: void setId_room(String^ _id_room) {
		id_room = _id_room;
		label_room_id->Text = id_room;
	}

	public: void setName_in_server(String^ _name_in_server) {
		name_in_server = _name_in_server;
		label_name_in_server->Text = name_in_server;
	}

	public: String^ name_audio;
		    String^ name_creator_audio;
			String^ path_picture_audio;
			int checkDownload;
			String^ id_room;
			String^ name_in_server;

			//Для интерфейса
			int d_r_back = 15;
			int d_g_back = 19;
			int d_b_back = 25;

			int d_r_elem = 32;
			int d_g_elem = 36;
			int d_b_elem = 43;

			int d_text_color = 238;

	private: System::Windows::Forms::Label^ label_room_id;
	public:

	private: String^ gl_size_file;
	private: Guna::UI2::WinForms::Guna2ProgressBar^ progressBar_load_audio;
	private: System::Windows::Forms::Label^ label_name_in_server;

		   String^ ip = "94.141.168.185";
		   String^ teme;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ListAudioItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_audio;
	protected:

	private: System::Windows::Forms::Label^ label_name_audio;
	private: System::Windows::Forms::Label^ label_name_creator_audio;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_download;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListAudioItem::typeid));
			this->pictureBox_audio = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_name_audio = (gcnew System::Windows::Forms::Label());
			this->label_name_creator_audio = (gcnew System::Windows::Forms::Label());
			this->pictureBox_download = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->label_room_id = (gcnew System::Windows::Forms::Label());
			this->progressBar_load_audio = (gcnew Guna::UI2::WinForms::Guna2ProgressBar());
			this->label_name_in_server = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_audio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_download))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox_audio
			// 
			this->pictureBox_audio->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pictureBox_audio->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_audio.Image")));
			this->pictureBox_audio->Location = System::Drawing::Point(14, 4);
			this->pictureBox_audio->Name = L"pictureBox_audio";
			this->pictureBox_audio->ShadowDecoration->Parent = this->pictureBox_audio;
			this->pictureBox_audio->Size = System::Drawing::Size(84, 78);
			this->pictureBox_audio->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_audio->TabIndex = 0;
			this->pictureBox_audio->TabStop = false;
			// 
			// label_name_audio
			// 
			this->label_name_audio->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_name_audio->AutoSize = true;
			this->label_name_audio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_audio->Location = System::Drawing::Point(105, 4);
			this->label_name_audio->Name = L"label_name_audio";
			this->label_name_audio->Size = System::Drawing::Size(65, 28);
			this->label_name_audio->TabIndex = 1;
			this->label_name_audio->Text = L"label1";
			// 
			// label_name_creator_audio
			// 
			this->label_name_creator_audio->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_name_creator_audio->AutoSize = true;
			this->label_name_creator_audio->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_name_creator_audio->Location = System::Drawing::Point(108, 45);
			this->label_name_creator_audio->Name = L"label_name_creator_audio";
			this->label_name_creator_audio->Size = System::Drawing::Size(55, 23);
			this->label_name_creator_audio->TabIndex = 2;
			this->label_name_creator_audio->Text = L"label2";
			// 
			// pictureBox_download
			// 
			this->pictureBox_download->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->pictureBox_download->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_download.Image")));
			this->pictureBox_download->Location = System::Drawing::Point(1202, 22);
			this->pictureBox_download->Name = L"pictureBox_download";
			this->pictureBox_download->ShadowDecoration->Parent = this->pictureBox_download;
			this->pictureBox_download->Size = System::Drawing::Size(40, 40);
			this->pictureBox_download->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_download->TabIndex = 3;
			this->pictureBox_download->TabStop = false;
			this->pictureBox_download->Click += gcnew System::EventHandler(this, &ListAudioItem::pictureBox_download_Click);
			// 
			// label_room_id
			// 
			this->label_room_id->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_room_id->AutoSize = true;
			this->label_room_id->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_room_id->Location = System::Drawing::Point(205, 45);
			this->label_room_id->Name = L"label_room_id";
			this->label_room_id->Size = System::Drawing::Size(71, 23);
			this->label_room_id->TabIndex = 4;
			this->label_room_id->Text = L"room_id";
			this->label_room_id->Visible = false;
			// 
			// progressBar_load_audio
			// 
			this->progressBar_load_audio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar_load_audio->GradientMode = System::Drawing::Drawing2D::LinearGradientMode::Horizontal;
			this->progressBar_load_audio->Location = System::Drawing::Point(282, 56);
			this->progressBar_load_audio->Name = L"progressBar_load_audio";
			this->progressBar_load_audio->ShadowDecoration->Parent = this->progressBar_load_audio;
			this->progressBar_load_audio->Size = System::Drawing::Size(863, 18);
			this->progressBar_load_audio->TabIndex = 5;
			this->progressBar_load_audio->TextRenderingHint = System::Drawing::Text::TextRenderingHint::SystemDefault;
			this->progressBar_load_audio->Visible = false;
			// 
			// label_name_in_server
			// 
			this->label_name_in_server->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_name_in_server->AutoSize = true;
			this->label_name_in_server->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_in_server->Location = System::Drawing::Point(205, 22);
			this->label_name_in_server->Name = L"label_name_in_server";
			this->label_name_in_server->Size = System::Drawing::Size(124, 23);
			this->label_name_in_server->TabIndex = 6;
			this->label_name_in_server->Text = L"name_in_server";
			this->label_name_in_server->Visible = false;
			// 
			// ListAudioItem
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->label_name_in_server);
			this->Controls->Add(this->progressBar_load_audio);
			this->Controls->Add(this->label_room_id);
			this->Controls->Add(this->pictureBox_download);
			this->Controls->Add(this->label_name_creator_audio);
			this->Controls->Add(this->label_name_audio);
			this->Controls->Add(this->pictureBox_audio);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"ListAudioItem";
			this->Size = System::Drawing::Size(1264, 85);
			this->MouseEnter += gcnew System::EventHandler(this, &ListAudioItem::ListAudioItem_MouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &ListAudioItem::ListAudioItem_MouseLeave);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_audio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_download))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void pictureBox_download_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name_file = label_name_in_server->Text;
		
		SaveFile(name_file);
	}

	private: void SaveFile(String^ name_file) {
		String^ room_id = label_room_id->Text;

		String^ link = "http://" + ip + ":8011/uploads/" + room_id + "/" + name_file;

		WebClient^ ws = gcnew WebClient();

		ws->OpenRead(link);
		String^ size = "" + (Convert::ToInt32(ws->ResponseHeaders->Get(2)) / 1048576);

		gl_size_file = size;

		progressBar_load_audio->Visible = true;

		ws->DownloadProgressChanged += gcnew System::Net::DownloadProgressChangedEventHandler(this, &MusicApp::ListAudioItem::OnDownloadProgressChanged);

		//ws->DownloadFile(link, "./uploads/" + name_file);
		ws->DownloadFileAsync(gcnew Uri(link), "./load/audio/" + name_file);
	}

	public: void OnDownloadProgressChanged(System::Object^ sender, System::Net::DownloadProgressChangedEventArgs^ e) {

		//label_progress->Text = "Размер файла: " + gl_size_file + "\nЗагружено: " + e->ProgressPercentage + "% (" + ((double)e->BytesReceived / 1048576) + ") Мб";
		progressBar_load_audio->Value = e->ProgressPercentage;
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

		pictureBox_audio->Image = Image::FromStream(memoryStream_in);

		memoryStream_in->Close();
	}

	private: void SetupInterface() {
		if (teme == "1") {
			label_name_audio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_name_audio->ForeColor = Color::FromArgb(241, 241, 241);

			label_name_creator_audio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_name_creator_audio->ForeColor = Color::FromArgb(241, 241, 241);
		}
	}
	
	private: System::Void ListAudioItem_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		if (teme == "0") {
			this->BackColor = Color::FromArgb(241, 241, 241);
		}
		else {
			this->BackColor = Color::FromArgb(40, 40, 40);
			label_name_audio->BackColor = Color::FromArgb(40, 40, 40);
			label_name_creator_audio->BackColor = Color::FromArgb(40, 40, 40);
		}
	}

	private: System::Void ListAudioItem_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (teme == "0") {
			this->BackColor = Color::White;
		}
		else {
			this->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_name_audio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
			label_name_creator_audio->BackColor = Color::FromArgb(d_r_back, d_g_back, d_b_back);
		}
	}
};
}
