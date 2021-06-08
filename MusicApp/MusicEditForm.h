#pragma once

#include "json.hpp"

#include "NetFunction.h"

#include "SaveAudioForm.h"

#include "WayEditorItem.h"
#include "ListWayItem.h"

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
	using namespace NAudio::Wave::SampleProviders;

	using namespace System::Collections::Generic;
	using namespace System::Linq;

	/// <summary>
	/// Сводка для MusicEditForm
	/// </summary>
	public ref class MusicEditForm : public System::Windows::Forms::Form
	{
	public:
		MusicEditForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			GenerationMap();
			GenerateMapLinear();
		}

		MusicEditForm(int _user_id, String^ _ip, String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			user_id = _user_id;
			ip = _ip;
			teme = _teme;

			if (teme == "1") {
				SetupInterface();
			}

			GenerationMap();
			GenerateMapLinear();

			LoadListWay();
		}

	private: String^ teme = "0";
		   int user_id;

		   int gl_room_id;

	private: WaveIn^ waveIn_Silence;
		   IWaveIn^ waveIn_wasapiLoopbackCapture_Silence;
		   WaveFileWriter^ writer_Silence;
		   String^ outputFilename_Silence;

	private: Object^ currObject = nullptr;
		   Object^ currObject_Del_Cut = nullptr;
		   String^ ip;

		   //Для интерфейса
		   int d_r_back = 15;
		   int d_g_back = 19;
		   int d_b_back = 25;

		   int d_r_elem = 32;
		   int d_g_elem = 36;
		   int d_b_elem = 43;

		   int d_text_color = 238;

	private: Guna::UI2::WinForms::Guna2TrackBar^ guna2TrackBar1;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_controls;

	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MusicEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_add_new_way;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_save_music;
	protected:

	protected:



	protected:


	private: Guna::UI2::WinForms::Guna2Panel^ panel_list_way;
	private: Guna::UI2::WinForms::Guna2Panel^ panel_way_editor;

	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel_list_way;
	private: System::Windows::Forms::Panel^ panel_info_way;



	private: System::Windows::Forms::Label^ label_editor_name_room;

	private: System::Windows::Forms::Label^ label_editor_name_way;
	private: System::Windows::Forms::Label^ label_editor_time_way;



	private: Guna::UI2::WinForms::Guna2Panel^ panel_editor_view;
	private: System::Windows::Forms::Panel^ panel_linear_way;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_delete_way;
	private: Guna::UI2::WinForms::Guna2PictureBox^ pictureBox_cut_way;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MusicEditForm::typeid));
			this->pictureBox_add_new_way = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->pictureBox_save_music = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->panel_list_way = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->flowLayoutPanel_list_way = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel_way_editor = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->panel_editor_view = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->guna2TrackBar1 = (gcnew Guna::UI2::WinForms::Guna2TrackBar());
			this->panel_linear_way = (gcnew System::Windows::Forms::Panel());
			this->panel_info_way = (gcnew System::Windows::Forms::Panel());
			this->label_editor_time_way = (gcnew System::Windows::Forms::Label());
			this->label_editor_name_room = (gcnew System::Windows::Forms::Label());
			this->label_editor_name_way = (gcnew System::Windows::Forms::Label());
			this->pictureBox_delete_way = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->pictureBox_cut_way = (gcnew Guna::UI2::WinForms::Guna2PictureBox());
			this->panel_controls = (gcnew Guna::UI2::WinForms::Guna2Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_add_new_way))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_save_music))->BeginInit();
			this->panel_list_way->SuspendLayout();
			this->panel_way_editor->SuspendLayout();
			this->panel_editor_view->SuspendLayout();
			this->panel_info_way->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_delete_way))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_cut_way))->BeginInit();
			this->panel_controls->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox_add_new_way
			// 
			this->pictureBox_add_new_way->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_add_new_way.Image")));
			this->pictureBox_add_new_way->Location = System::Drawing::Point(8, 12);
			this->pictureBox_add_new_way->Name = L"pictureBox_add_new_way";
			this->pictureBox_add_new_way->ShadowDecoration->Parent = this->pictureBox_add_new_way;
			this->pictureBox_add_new_way->Size = System::Drawing::Size(35, 35);
			this->pictureBox_add_new_way->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_add_new_way->TabIndex = 0;
			this->pictureBox_add_new_way->TabStop = false;
			this->pictureBox_add_new_way->Click += gcnew System::EventHandler(this, &MusicEditForm::pictureBox_add_new_way_Click);
			// 
			// pictureBox_save_music
			// 
			this->pictureBox_save_music->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_save_music.Image")));
			this->pictureBox_save_music->Location = System::Drawing::Point(64, 12);
			this->pictureBox_save_music->Name = L"pictureBox_save_music";
			this->pictureBox_save_music->ShadowDecoration->Parent = this->pictureBox_save_music;
			this->pictureBox_save_music->Size = System::Drawing::Size(35, 35);
			this->pictureBox_save_music->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_save_music->TabIndex = 1;
			this->pictureBox_save_music->TabStop = false;
			this->pictureBox_save_music->Click += gcnew System::EventHandler(this, &MusicEditForm::pictureBox_save_music_Click);
			// 
			// panel_list_way
			// 
			this->panel_list_way->Controls->Add(this->flowLayoutPanel_list_way);
			this->panel_list_way->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_list_way->Location = System::Drawing::Point(0, 0);
			this->panel_list_way->Name = L"panel_list_way";
			this->panel_list_way->ShadowDecoration->Parent = this->panel_list_way;
			this->panel_list_way->Size = System::Drawing::Size(336, 766);
			this->panel_list_way->TabIndex = 2;
			// 
			// flowLayoutPanel_list_way
			// 
			this->flowLayoutPanel_list_way->AutoScroll = true;
			this->flowLayoutPanel_list_way->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel_list_way->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel_list_way->Name = L"flowLayoutPanel_list_way";
			this->flowLayoutPanel_list_way->Size = System::Drawing::Size(336, 766);
			this->flowLayoutPanel_list_way->TabIndex = 5;
			// 
			// panel_way_editor
			// 
			this->panel_way_editor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_way_editor->Controls->Add(this->panel_editor_view);
			this->panel_way_editor->Controls->Add(this->panel_linear_way);
			this->panel_way_editor->Location = System::Drawing::Point(342, 74);
			this->panel_way_editor->Name = L"panel_way_editor";
			this->panel_way_editor->ShadowDecoration->Parent = this->panel_way_editor;
			this->panel_way_editor->Size = System::Drawing::Size(1198, 680);
			this->panel_way_editor->TabIndex = 3;
			// 
			// panel_editor_view
			// 
			this->panel_editor_view->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_editor_view->AutoScroll = true;
			this->panel_editor_view->Controls->Add(this->guna2Panel1);
			this->panel_editor_view->Controls->Add(this->guna2TrackBar1);
			this->panel_editor_view->Location = System::Drawing::Point(0, 48);
			this->panel_editor_view->Name = L"panel_editor_view";
			this->panel_editor_view->ShadowDecoration->Parent = this->panel_editor_view;
			this->panel_editor_view->Size = System::Drawing::Size(1198, 632);
			this->panel_editor_view->TabIndex = 1;
			this->panel_editor_view->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MusicEditForm::panel_editor_view_MouseClick);
			this->panel_editor_view->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MusicEditForm::panel_editor_view_MouseMove);
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->guna2Panel1->BackColor = System::Drawing::Color::Red;
			this->guna2Panel1->Location = System::Drawing::Point(0, 20);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->ShadowDecoration->Parent = this->guna2Panel1;
			this->guna2Panel1->Size = System::Drawing::Size(5, 609);
			this->guna2Panel1->TabIndex = 2;
			// 
			// guna2TrackBar1
			// 
			this->guna2TrackBar1->Dock = System::Windows::Forms::DockStyle::Top;
			this->guna2TrackBar1->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->guna2TrackBar1->HoverState->Parent = this->guna2TrackBar1;
			this->guna2TrackBar1->Location = System::Drawing::Point(0, 0);
			this->guna2TrackBar1->Margin = System::Windows::Forms::Padding(0);
			this->guna2TrackBar1->Maximum = 360;
			this->guna2TrackBar1->Name = L"guna2TrackBar1";
			this->guna2TrackBar1->Size = System::Drawing::Size(1198, 23);
			this->guna2TrackBar1->Style = Guna::UI2::WinForms::Enums::TrackBarStyle::Metro;
			this->guna2TrackBar1->TabIndex = 1;
			this->guna2TrackBar1->ThumbColor = System::Drawing::Color::Black;
			this->guna2TrackBar1->Value = 0;
			this->guna2TrackBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MusicEditForm::guna2TrackBar1_Scroll);
			// 
			// panel_linear_way
			// 
			this->panel_linear_way->AutoScroll = true;
			this->panel_linear_way->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_linear_way->Location = System::Drawing::Point(0, 0);
			this->panel_linear_way->Name = L"panel_linear_way";
			this->panel_linear_way->Size = System::Drawing::Size(1198, 42);
			this->panel_linear_way->TabIndex = 0;
			// 
			// panel_info_way
			// 
			this->panel_info_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->panel_info_way->Controls->Add(this->label_editor_time_way);
			this->panel_info_way->Controls->Add(this->label_editor_name_room);
			this->panel_info_way->Controls->Add(this->label_editor_name_way);
			this->panel_info_way->Location = System::Drawing::Point(318, 3);
			this->panel_info_way->Name = L"panel_info_way";
			this->panel_info_way->Size = System::Drawing::Size(529, 56);
			this->panel_info_way->TabIndex = 4;
			// 
			// label_editor_time_way
			// 
			this->label_editor_time_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_editor_time_way->AutoSize = true;
			this->label_editor_time_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_editor_time_way->Location = System::Drawing::Point(434, 18);
			this->label_editor_time_way->Name = L"label_editor_time_way";
			this->label_editor_time_way->Size = System::Drawing::Size(80, 23);
			this->label_editor_time_way->TabIndex = 3;
			this->label_editor_time_way->Text = L"time_way";
			this->label_editor_time_way->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_editor_name_room
			// 
			this->label_editor_name_room->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_editor_name_room->AutoSize = true;
			this->label_editor_name_room->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_editor_name_room->Location = System::Drawing::Point(71, 32);
			this->label_editor_name_room->Name = L"label_editor_name_room";
			this->label_editor_name_room->Size = System::Drawing::Size(104, 23);
			this->label_editor_name_room->TabIndex = 2;
			this->label_editor_name_room->Text = L"Name_room";
			this->label_editor_name_room->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_editor_name_way
			// 
			this->label_editor_name_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_editor_name_way->AutoSize = true;
			this->label_editor_name_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_editor_name_way->Location = System::Drawing::Point(71, 6);
			this->label_editor_name_way->Name = L"label_editor_name_way";
			this->label_editor_name_way->Size = System::Drawing::Size(92, 23);
			this->label_editor_name_way->TabIndex = 1;
			this->label_editor_name_way->Text = L"Name_way";
			this->label_editor_name_way->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox_delete_way
			// 
			this->pictureBox_delete_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_delete_way->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_delete_way.Image")));
			this->pictureBox_delete_way->Location = System::Drawing::Point(1141, 12);
			this->pictureBox_delete_way->Name = L"pictureBox_delete_way";
			this->pictureBox_delete_way->ShadowDecoration->Parent = this->pictureBox_delete_way;
			this->pictureBox_delete_way->Size = System::Drawing::Size(35, 35);
			this->pictureBox_delete_way->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_delete_way->TabIndex = 5;
			this->pictureBox_delete_way->TabStop = false;
			this->pictureBox_delete_way->Click += gcnew System::EventHandler(this, &MusicEditForm::pictureBox_delete_way_Click);
			// 
			// pictureBox_cut_way
			// 
			this->pictureBox_cut_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox_cut_way->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_cut_way.Image")));
			this->pictureBox_cut_way->Location = System::Drawing::Point(1085, 12);
			this->pictureBox_cut_way->Name = L"pictureBox_cut_way";
			this->pictureBox_cut_way->ShadowDecoration->Parent = this->pictureBox_cut_way;
			this->pictureBox_cut_way->Size = System::Drawing::Size(35, 35);
			this->pictureBox_cut_way->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_cut_way->TabIndex = 6;
			this->pictureBox_cut_way->TabStop = false;
			this->pictureBox_cut_way->Click += gcnew System::EventHandler(this, &MusicEditForm::pictureBox_cut_way_Click);
			// 
			// panel_controls
			// 
			this->panel_controls->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_controls->Controls->Add(this->pictureBox_cut_way);
			this->panel_controls->Controls->Add(this->panel_info_way);
			this->panel_controls->Controls->Add(this->pictureBox_delete_way);
			this->panel_controls->Controls->Add(this->pictureBox_add_new_way);
			this->panel_controls->Controls->Add(this->pictureBox_save_music);
			this->panel_controls->Location = System::Drawing::Point(349, 3);
			this->panel_controls->Name = L"panel_controls";
			this->panel_controls->ShadowDecoration->Parent = this->panel_controls;
			this->panel_controls->Size = System::Drawing::Size(1183, 65);
			this->panel_controls->TabIndex = 3;
			// 
			// MusicEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1552, 766);
			this->Controls->Add(this->panel_controls);
			this->Controls->Add(this->panel_way_editor);
			this->Controls->Add(this->panel_list_way);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MusicEditForm";
			this->Text = L"MusicEditForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MusicEditForm::MusicEditForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_add_new_way))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_save_music))->EndInit();
			this->panel_list_way->ResumeLayout(false);
			this->panel_way_editor->ResumeLayout(false);
			this->panel_editor_view->ResumeLayout(false);
			this->panel_info_way->ResumeLayout(false);
			this->panel_info_way->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_delete_way))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_cut_way))->EndInit();
			this->panel_controls->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	//Определение длины аудио дорожки
	private: int getTotalTimeMusic(String^ file_name);

	//Проверка наличия файла
	private: bool checkFileDownload(String^ fileName);

	//Действие происходящие перед закрытием формы
	private: System::Void MusicEditForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);


	/*--------------------------------Отрисовка интерфейса------------------------------------*/
	//Настройка темы интерфейса
	private: void SetupInterface();

	//Генерация поля для дорожек
	private: void GenerationMap();

	//Генерация временной шкалы
	private: void GenerateMapLinear();

	private: System::Void guna2TrackBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e);


	/*--------------------------------Добавление на поле редактирования дорожки------------------------------------*/
	//Добавление элемента в область
	private: void addWayItem(String^ _name_way, int width_way, String^ _name_studio);

	private: void addWayItem(String^ _name_way, int width_way, String^ _name_studio, int value_left, int value_top);

	//Обработчик нажатия на элемент
	private: void WayEditorClick(System::Object^ sender, System::EventArgs^ e);

	//Перемещение дорожки по области редактирования
	private: System::Void panel_editor_view_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	//Установка дорожки в необходимое место поля редактирования
	private: System::Void panel_editor_view_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);


	/*--------------------------------Сохранение музыкальной конпозиции------------------------------------*/
	//Обработчик кнопки сохранения
	private: System::Void pictureBox_save_music_Click(System::Object^ sender, System::EventArgs^ e);

	//Сохранение файла на сервере
	private: void saveFileAudio(String^ name_output_file, String^ name_creators, bool access, String^ path_picture_music, int check_music_or_way);

	//Сохранение информации о файле
	private: void addInfoAudioFile(String^ name_audio, String^ name_creators, String^ path_picture, int check_music_or_way, bool access_in);

	//Создание файла необходимого размера
	private: void PlusFile(String^ fileName, List<String^>^ sourceFiles);

	//Объединение всех файлов 
	private: void MixWavFile(List<String^>^ files, String^ fileName);


	/*--------------------------------Генерация списка дорожек доступных пользователю------------------------------------*/
	//Загрузка возможных дорожек
	private: void LoadListWay();

	//Добавление дорожки в список
	private: void addItemWayList(std::vector<int> list_id, std::vector<std::string> list_name_way, std::vector<std::string> list_name_room, std::vector<std::string> list_type_way);

	//Обработчик нажатия на элемент списка
	private: void wayItemListDoubleClick(System::Object^ sender, System::EventArgs^ e);


	/*--------------------------------Обработчики нажатия кнопок на форме для редактирования------------------------------------*/
	private: System::Void pictureBox_add_new_way_Click(System::Object^ sender, System::EventArgs^ e) {
		guna2TrackBar1->Visible = true;
	}


	private: System::Void pictureBox_cut_way_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureBox_delete_way_Click(System::Object^ sender, System::EventArgs^ e);
};
}