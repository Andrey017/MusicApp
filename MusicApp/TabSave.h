#pragma once

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TabSave
	/// </summary>
	public ref class TabSave : public System::Windows::Forms::Form
	{
	public:
		TabSave(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TabSave()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI::WinForms::GunaElipsePanel^ gunaElipsePanel2;
	protected:
	private: Guna::UI::WinForms::GunaPictureBox^ exit;
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;
	private: Guna::UI::WinForms::GunaPictureBox^ gunaPictureBox1;
	private: Guna::UI::WinForms::GunaLabel^ gunaLabel1;
	private: Guna::UI::WinForms::GunaElipsePanel^ gunaElipsePanelTabName;


	private: Guna::UI::WinForms::GunaPictureBox^ gunaPictureBox3;
	private: Guna::UI::WinForms::GunaTextBox^ gunaTextBox1;

	private: Guna::UI::WinForms::GunaRadioButton^ gunaRadioButtonPublicTab;
	private: Guna::UI::WinForms::GunaRadioButton^ gunaRadioButtonPrivateTab;
	private: Guna::UI::WinForms::GunaButton^ gunaButton1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TabSave::typeid));
			this->gunaElipsePanel2 = (gcnew Guna::UI::WinForms::GunaElipsePanel());
			this->gunaLabel1 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->gunaPictureBox1 = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->exit = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->gunaElipsePanelTabName = (gcnew Guna::UI::WinForms::GunaElipsePanel());
			this->gunaButton1 = (gcnew Guna::UI::WinForms::GunaButton());
			this->gunaRadioButtonPublicTab = (gcnew Guna::UI::WinForms::GunaRadioButton());
			this->gunaRadioButtonPrivateTab = (gcnew Guna::UI::WinForms::GunaRadioButton());
			this->gunaTextBox1 = (gcnew Guna::UI::WinForms::GunaTextBox());
			this->gunaPictureBox3 = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->gunaElipsePanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gunaPictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->BeginInit();
			this->gunaElipsePanelTabName->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gunaPictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// gunaElipsePanel2
			// 
			this->gunaElipsePanel2->BackColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel2->BaseColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel2->Controls->Add(this->gunaLabel1);
			this->gunaElipsePanel2->Controls->Add(this->gunaPictureBox1);
			this->gunaElipsePanel2->Controls->Add(this->exit);
			this->gunaElipsePanel2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaElipsePanel2->Location = System::Drawing::Point(12, 3);
			this->gunaElipsePanel2->Name = L"gunaElipsePanel2";
			this->gunaElipsePanel2->Radius = 1;
			this->gunaElipsePanel2->Size = System::Drawing::Size(347, 31);
			this->gunaElipsePanel2->TabIndex = 2;
			// 
			// gunaLabel1
			// 
			this->gunaLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaLabel1->ForeColor = System::Drawing::Color::White;
			this->gunaLabel1->Location = System::Drawing::Point(126, 4);
			this->gunaLabel1->Name = L"gunaLabel1";
			this->gunaLabel1->Size = System::Drawing::Size(94, 23);
			this->gunaLabel1->TabIndex = 12;
			this->gunaLabel1->Text = L"Сохранение";
			this->gunaLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gunaPictureBox1
			// 
			this->gunaPictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->gunaPictureBox1->BaseColor = System::Drawing::Color::White;
			this->gunaPictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gunaPictureBox1->ErrorImage = nullptr;
			this->gunaPictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gunaPictureBox1.Image")));
			this->gunaPictureBox1->InitialImage = nullptr;
			this->gunaPictureBox1->Location = System::Drawing::Point(322, 0);
			this->gunaPictureBox1->Name = L"gunaPictureBox1";
			this->gunaPictureBox1->Size = System::Drawing::Size(31, 31);
			this->gunaPictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->gunaPictureBox1->TabIndex = 11;
			this->gunaPictureBox1->TabStop = false;
			this->gunaPictureBox1->Click += gcnew System::EventHandler(this, &TabSave::gunaPictureBox1_Click);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->BaseColor = System::Drawing::Color::White;
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->ErrorImage = nullptr;
			this->exit->InitialImage = nullptr;
			this->exit->Location = System::Drawing::Point(1074, 1);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(31, 31);
			this->exit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->exit->TabIndex = 10;
			this->exit->TabStop = false;
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->Radius = 5;
			this->gunaElipse1->TargetControl = this;
			// 
			// gunaElipsePanelTabName
			// 
			this->gunaElipsePanelTabName->BackColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanelTabName->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->gunaElipsePanelTabName->Controls->Add(this->gunaButton1);
			this->gunaElipsePanelTabName->Controls->Add(this->gunaRadioButtonPublicTab);
			this->gunaElipsePanelTabName->Controls->Add(this->gunaRadioButtonPrivateTab);
			this->gunaElipsePanelTabName->Controls->Add(this->gunaTextBox1);
			this->gunaElipsePanelTabName->Controls->Add(this->gunaPictureBox3);
			this->gunaElipsePanelTabName->Location = System::Drawing::Point(12, 33);
			this->gunaElipsePanelTabName->Name = L"gunaElipsePanelTabName";
			this->gunaElipsePanelTabName->Radius = 5;
			this->gunaElipsePanelTabName->Size = System::Drawing::Size(347, 84);
			this->gunaElipsePanelTabName->TabIndex = 13;
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
			this->gunaButton1->Location = System::Drawing::Point(213, 55);
			this->gunaButton1->Name = L"gunaButton1";
			this->gunaButton1->OnHoverBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaButton1->OnHoverBorderColor = System::Drawing::Color::Black;
			this->gunaButton1->OnHoverForeColor = System::Drawing::Color::White;
			this->gunaButton1->OnHoverImage = nullptr;
			this->gunaButton1->OnPressedColor = System::Drawing::Color::Black;
			this->gunaButton1->Size = System::Drawing::Size(124, 25);
			this->gunaButton1->TabIndex = 15;
			this->gunaButton1->Text = L"Сохранить";
			// 
			// gunaRadioButtonPublicTab
			// 
			this->gunaRadioButtonPublicTab->BaseColor = System::Drawing::SystemColors::Control;
			this->gunaRadioButtonPublicTab->CheckedOffColor = System::Drawing::Color::Gray;
			this->gunaRadioButtonPublicTab->CheckedOnColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaRadioButtonPublicTab->FillColor = System::Drawing::Color::White;
			this->gunaRadioButtonPublicTab->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaRadioButtonPublicTab->ForeColor = System::Drawing::Color::White;
			this->gunaRadioButtonPublicTab->Location = System::Drawing::Point(104, 56);
			this->gunaRadioButtonPublicTab->Name = L"gunaRadioButtonPublicTab";
			this->gunaRadioButtonPublicTab->Size = System::Drawing::Size(113, 24);
			this->gunaRadioButtonPublicTab->TabIndex = 14;
			this->gunaRadioButtonPublicTab->Text = L"Публичный";
			this->gunaRadioButtonPublicTab->CheckedChanged += gcnew System::EventHandler(this, &TabSave::gunaRadioButtonPublicTab_CheckedChanged);
			// 
			// gunaRadioButtonPrivateTab
			// 
			this->gunaRadioButtonPrivateTab->BaseColor = System::Drawing::SystemColors::Control;
			this->gunaRadioButtonPrivateTab->Checked = true;
			this->gunaRadioButtonPrivateTab->CheckedOffColor = System::Drawing::Color::Gray;
			this->gunaRadioButtonPrivateTab->CheckedOnColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaRadioButtonPrivateTab->FillColor = System::Drawing::Color::White;
			this->gunaRadioButtonPrivateTab->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaRadioButtonPrivateTab->ForeColor = System::Drawing::Color::White;
			this->gunaRadioButtonPrivateTab->Location = System::Drawing::Point(10, 56);
			this->gunaRadioButtonPrivateTab->Name = L"gunaRadioButtonPrivateTab";
			this->gunaRadioButtonPrivateTab->Size = System::Drawing::Size(88, 24);
			this->gunaRadioButtonPrivateTab->TabIndex = 13;
			this->gunaRadioButtonPrivateTab->Text = L"Личный";
			// 
			// gunaTextBox1
			// 
			this->gunaTextBox1->BackColor = System::Drawing::Color::Transparent;
			this->gunaTextBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->gunaTextBox1->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->gunaTextBox1->BorderColor = System::Drawing::Color::Silver;
			this->gunaTextBox1->BorderSize = 1;
			this->gunaTextBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->gunaTextBox1->FocusedBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->gunaTextBox1->FocusedBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaTextBox1->FocusedForeColor = System::Drawing::Color::White;
			this->gunaTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaTextBox1->ForeColor = System::Drawing::Color::White;
			this->gunaTextBox1->Location = System::Drawing::Point(10, 10);
			this->gunaTextBox1->Margin = System::Windows::Forms::Padding(10);
			this->gunaTextBox1->MaxLength = 50;
			this->gunaTextBox1->Name = L"gunaTextBox1";
			this->gunaTextBox1->PasswordChar = '\0';
			this->gunaTextBox1->Radius = 5;
			this->gunaTextBox1->SelectedText = L"";
			this->gunaTextBox1->Size = System::Drawing::Size(327, 32);
			this->gunaTextBox1->TabIndex = 11;
			this->gunaTextBox1->Text = L"Название";
			// 
			// gunaPictureBox3
			// 
			this->gunaPictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->gunaPictureBox3->BaseColor = System::Drawing::Color::White;
			this->gunaPictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gunaPictureBox3->ErrorImage = nullptr;
			this->gunaPictureBox3->InitialImage = nullptr;
			this->gunaPictureBox3->Location = System::Drawing::Point(1074, 1);
			this->gunaPictureBox3->Name = L"gunaPictureBox3";
			this->gunaPictureBox3->Size = System::Drawing::Size(31, 31);
			this->gunaPictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->gunaPictureBox3->TabIndex = 10;
			this->gunaPictureBox3->TabStop = false;
			// 
			// TabSave
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(371, 129);
			this->Controls->Add(this->gunaElipsePanelTabName);
			this->Controls->Add(this->gunaElipsePanel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TabSave";
			this->Text = L"TabSave";
			this->gunaElipsePanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gunaPictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->EndInit();
			this->gunaElipsePanelTabName->ResumeLayout(false);
			this->gunaElipsePanelTabName->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gunaPictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void gunaLabel2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gunaRadioButtonPublicTab_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gunaPictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
