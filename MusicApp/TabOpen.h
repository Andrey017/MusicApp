#pragma once
#include "TabList.h"
//#include "NetFunction.h"

//#include "json.hpp"

//#include <msclr\marshal.h>
//#include <msclr\marshal_cppstd.h>

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//using namespace System::Net;
	//using namespace System::IO;

	////using json = nlohmann::json;

	//using namespace msclr::interop;

	//using namespace System::Runtime::InteropServices;


	/// <summary>
	/// Сводка для TabOpen
	/// </summary>
	public ref class TabOpen : public System::Windows::Forms::Form
	{
	public:
		TabOpen(void)
		{
			InitializeComponent();
			array<TabList^>^ tabList = gcnew array<TabList^>(2);
			for (int i = 0; i < tabList->Length; i++) {
				tabList[i] = gcnew TabList();


				switch (i) {

				case 0:
					tabList[i]->setName("HOME INTRO");
					tabList[i]->setCreator("J1gA");
					break;
				case 1:
					tabList[i]->setName("HOME");
					tabList[i]->setCreator("Jojo");
					break;
				case 2:
					tabList[i]->setName("Do I Wanna Know");
					tabList[i]->setCreator("Andrey");
					break;
				case 3:
					tabList[i]->setName("HOME INTRO");
					tabList[i]->setCreator("Jojo");
					break;
				case 4:
					tabList[i]->setName("Проверка");
					tabList[i]->setCreator("JigA");
					break;
				default:
					tabList[i]->setName("Табулатура");
					tabList[i]->setCreator("JigA");
				}
				//tabList[i]->setCreator("JigA");

				panelTabList->Controls->Add(tabList[i]);
				tabList[i]->DoubleClick += gcnew System::EventHandler(this, &TabOpen::tabListDoubleClick);

				tabList[i]->BringToFront();
				//tabList[i]->GetType()->GetProperty("Location")->SetValue(tabList[i], Point(5, 5 + i * 45));
				//tabList[i]->GetType()->GetProperty("Location")->SetValue(tabList[i], Point(5, 5 + i * 45));
			}

			//
			//TODO: добавьте код конструктора
			//
		}

	private:
		String^ user_id;
	private: Guna::UI::WinForms::GunaElipsePanel^ gunaElipsePanel1;
	private: Guna::UI::WinForms::GunaLabel^ gunaLabel1;
	private: Guna::UI::WinForms::GunaLabel^ gunaLabel2;
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse2;
		   String^ access;


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TabOpen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;


	private: Guna::UI::WinForms::GunaElipsePanel^ gunaPanelTabOpen;
	private: Guna::UI::WinForms::GunaButton^ gunaButton1;
	private: Guna::UI::WinForms::GunaButton^ gunaButton2;
	private: Guna::UI::WinForms::GunaPictureBox^ exit;
	private: Guna::UI::WinForms::GunaPictureBox^ gunaPictureBox1;
	private: Guna::UI::WinForms::GunaLineTextBox^ gunaLineTextBoxSearch;
	private: System::Windows::Forms::FlowLayoutPanel^ panelTabList;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TabOpen::typeid));
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->gunaPanelTabOpen = (gcnew Guna::UI::WinForms::GunaElipsePanel());
			this->gunaPictureBox1 = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->gunaLineTextBoxSearch = (gcnew Guna::UI::WinForms::GunaLineTextBox());
			this->exit = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->gunaButton2 = (gcnew Guna::UI::WinForms::GunaButton());
			this->gunaButton1 = (gcnew Guna::UI::WinForms::GunaButton());
			this->panelTabList = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->gunaElipsePanel1 = (gcnew Guna::UI::WinForms::GunaElipsePanel());
			this->gunaLabel2 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->gunaLabel1 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->gunaElipse2 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->gunaPanelTabOpen->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gunaPictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->BeginInit();
			this->gunaElipsePanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->Radius = 5;
			this->gunaElipse1->TargetControl = this;
			// 
			// gunaPanelTabOpen
			// 
			this->gunaPanelTabOpen->BackColor = System::Drawing::Color::Transparent;
			this->gunaPanelTabOpen->BaseColor = System::Drawing::Color::Transparent;
			this->gunaPanelTabOpen->Controls->Add(this->gunaPictureBox1);
			this->gunaPanelTabOpen->Controls->Add(this->gunaLineTextBoxSearch);
			this->gunaPanelTabOpen->Controls->Add(this->exit);
			this->gunaPanelTabOpen->Controls->Add(this->gunaButton2);
			this->gunaPanelTabOpen->Controls->Add(this->gunaButton1);
			this->gunaPanelTabOpen->Location = System::Drawing::Point(12, 4);
			this->gunaPanelTabOpen->Name = L"gunaPanelTabOpen";
			this->gunaPanelTabOpen->Radius = 1;
			this->gunaPanelTabOpen->Size = System::Drawing::Size(516, 31);
			this->gunaPanelTabOpen->TabIndex = 0;
			// 
			// gunaPictureBox1
			// 
			this->gunaPictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->gunaPictureBox1->BaseColor = System::Drawing::Color::White;
			this->gunaPictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gunaPictureBox1.Image")));
			this->gunaPictureBox1->Location = System::Drawing::Point(254, 3);
			this->gunaPictureBox1->Name = L"gunaPictureBox1";
			this->gunaPictureBox1->Size = System::Drawing::Size(25, 25);
			this->gunaPictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->gunaPictureBox1->TabIndex = 0;
			this->gunaPictureBox1->TabStop = false;
			this->gunaPictureBox1->Click += gcnew System::EventHandler(this, &TabOpen::gunaPictureBox1_Click);
			// 
			// gunaLineTextBoxSearch
			// 
			this->gunaLineTextBoxSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->gunaLineTextBoxSearch->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->gunaLineTextBoxSearch->FocusedLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaLineTextBoxSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaLineTextBoxSearch->ForeColor = System::Drawing::Color::White;
			this->gunaLineTextBoxSearch->LineColor = System::Drawing::Color::White;
			this->gunaLineTextBoxSearch->LineSize = 1;
			this->gunaLineTextBoxSearch->Location = System::Drawing::Point(280, 0);
			this->gunaLineTextBoxSearch->Name = L"gunaLineTextBoxSearch";
			this->gunaLineTextBoxSearch->PasswordChar = '\0';
			this->gunaLineTextBoxSearch->SelectedText = L"";
			this->gunaLineTextBoxSearch->Size = System::Drawing::Size(211, 30);
			this->gunaLineTextBoxSearch->TabIndex = 12;
			this->gunaLineTextBoxSearch->Text = L"Поиск";
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->BaseColor = System::Drawing::Color::White;
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->ErrorImage = nullptr;
			this->exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.Image")));
			this->exit->InitialImage = nullptr;
			this->exit->Location = System::Drawing::Point(491, 1);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(31, 31);
			this->exit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->exit->TabIndex = 11;
			this->exit->TabStop = false;
			this->exit->Click += gcnew System::EventHandler(this, &TabOpen::exit_Click);
			// 
			// gunaButton2
			// 
			this->gunaButton2->AnimationHoverSpeed = 0.07F;
			this->gunaButton2->AnimationSpeed = 0.03F;
			this->gunaButton2->BaseColor = System::Drawing::Color::Transparent;
			this->gunaButton2->BorderColor = System::Drawing::Color::Black;
			this->gunaButton2->DialogResult = System::Windows::Forms::DialogResult::None;
			this->gunaButton2->FocusedColor = System::Drawing::Color::Empty;
			this->gunaButton2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaButton2->ForeColor = System::Drawing::Color::White;
			this->gunaButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gunaButton2.Image")));
			this->gunaButton2->ImageSize = System::Drawing::Size(20, 20);
			this->gunaButton2->Location = System::Drawing::Point(117, 3);
			this->gunaButton2->Name = L"gunaButton2";
			this->gunaButton2->OnHoverBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaButton2->OnHoverBorderColor = System::Drawing::Color::Black;
			this->gunaButton2->OnHoverForeColor = System::Drawing::Color::White;
			this->gunaButton2->OnHoverImage = nullptr;
			this->gunaButton2->OnPressedColor = System::Drawing::Color::Black;
			this->gunaButton2->Size = System::Drawing::Size(131, 25);
			this->gunaButton2->TabIndex = 1;
			this->gunaButton2->Text = L"Публичные";
			// 
			// gunaButton1
			// 
			this->gunaButton1->AnimationHoverSpeed = 0.07F;
			this->gunaButton1->AnimationSpeed = 0.03F;
			this->gunaButton1->BaseColor = System::Drawing::Color::Transparent;
			this->gunaButton1->BorderColor = System::Drawing::Color::Black;
			this->gunaButton1->DialogResult = System::Windows::Forms::DialogResult::None;
			this->gunaButton1->FocusedColor = System::Drawing::Color::Empty;
			this->gunaButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaButton1->ForeColor = System::Drawing::Color::White;
			this->gunaButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gunaButton1.Image")));
			this->gunaButton1->ImageSize = System::Drawing::Size(20, 20);
			this->gunaButton1->Location = System::Drawing::Point(3, 3);
			this->gunaButton1->Name = L"gunaButton1";
			this->gunaButton1->OnHoverBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaButton1->OnHoverBorderColor = System::Drawing::Color::Black;
			this->gunaButton1->OnHoverForeColor = System::Drawing::Color::White;
			this->gunaButton1->OnHoverImage = nullptr;
			this->gunaButton1->OnPressedColor = System::Drawing::Color::Black;
			this->gunaButton1->Size = System::Drawing::Size(108, 25);
			this->gunaButton1->TabIndex = 0;
			this->gunaButton1->Text = L"Личные";
			// 
			// panelTabList
			// 
			this->panelTabList->AutoScroll = true;
			this->panelTabList->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panelTabList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panelTabList->Location = System::Drawing::Point(12, 78);
			this->panelTabList->Name = L"panelTabList";
			this->panelTabList->Size = System::Drawing::Size(516, 234);
			this->panelTabList->TabIndex = 0;
			// 
			// gunaElipsePanel1
			// 
			this->gunaElipsePanel1->BackColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel1->BaseColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel1->Controls->Add(this->gunaLabel2);
			this->gunaElipsePanel1->Controls->Add(this->gunaLabel1);
			this->gunaElipsePanel1->Location = System::Drawing::Point(15, 42);
			this->gunaElipsePanel1->Name = L"gunaElipsePanel1";
			this->gunaElipsePanel1->Radius = 5;
			this->gunaElipsePanel1->Size = System::Drawing::Size(506, 30);
			this->gunaElipsePanel1->TabIndex = 13;
			// 
			// gunaLabel2
			// 
			this->gunaLabel2->AutoSize = true;
			this->gunaLabel2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaLabel2->ForeColor = System::Drawing::Color::White;
			this->gunaLabel2->Location = System::Drawing::Point(446, 5);
			this->gunaLabel2->Name = L"gunaLabel2";
			this->gunaLabel2->Size = System::Drawing::Size(51, 20);
			this->gunaLabel2->TabIndex = 1;
			this->gunaLabel2->Text = L"Автор";
			this->gunaLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// gunaLabel1
			// 
			this->gunaLabel1->AutoSize = true;
			this->gunaLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaLabel1->ForeColor = System::Drawing::Color::White;
			this->gunaLabel1->Location = System::Drawing::Point(12, 5);
			this->gunaLabel1->Name = L"gunaLabel1";
			this->gunaLabel1->Size = System::Drawing::Size(77, 20);
			this->gunaLabel1->TabIndex = 0;
			this->gunaLabel1->Text = L"Название";
			this->gunaLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// gunaElipse2
			// 
			this->gunaElipse2->Radius = 5;
			this->gunaElipse2->TargetControl = this->panelTabList;
			// 
			// TabOpen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(540, 324);
			this->Controls->Add(this->gunaElipsePanel1);
			this->Controls->Add(this->panelTabList);
			this->Controls->Add(this->gunaPanelTabOpen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TabOpen";
			this->Text = L"TabOpen";
			this->gunaPanelTabOpen->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gunaPictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->EndInit();
			this->gunaElipsePanel1->ResumeLayout(false);
			this->gunaElipsePanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		void MusicApp::TabOpen::tabListDoubleClick(System::Object^ sender, System::EventArgs^ e) {

		}
		//private: void AddItemInList(std::vector<int> list_id, std::vector<std::string> list_name, 
		//	std::vector<std::string> list_creator, std::vector<int> list_access, std::vector<int> list_id_room);
		//private: void TabListListDoubleClick(System::Object^ sender, System::EventArgs^ e);
		//private: void LoadListTab();
		//private: void SaveFileInTemp(String^ id, String^ name);
		//private: void AddInfoAudioFile(String^ name, String^ creator, bool access, int room_id);
		//private: void SaveAudioFile(String^ outFileName, int room_id, bool access, String^ creator, String^ name);
	private: System::Void gunaPictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	};
}
