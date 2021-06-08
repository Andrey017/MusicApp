#pragma once

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace NAudio::Wave;
	using namespace NAudio::FileFormats;
	using namespace NAudio::CoreAudioApi;
	using namespace NAudio;

	/// <summary>
	/// Сводка для SettingsStudioForm
	/// </summary>
	public ref class SettingsStudioForm : public System::Windows::Forms::Form
	{
	public:
		SettingsStudioForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			MMDeviceEnumerator^ devicesEnum = gcnew MMDeviceEnumerator();

			MMDeviceCollection^ devices = devicesEnum->EnumerateAudioEndPoints(DataFlow::All, DeviceState::Active);

			int count = devices->Count;

			for (int i = 0; i < count; i++) {
				String^ dev = devices[i]->ToString();

				array<String^>^ arr_dev = dev->Split(' ');

				if (arr_dev[0] == "Динамики" || arr_dev[0] == "Наушники") {
					comboBox_dum->Items->Add(devices[i]);
				}
				else {
					comboBox_mic->Items->Add(devices[i]);
				}
			}

			comboBox_dum->SelectedIndex = 0;
			comboBox_mic->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SettingsStudioForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;
	private: System::Windows::Forms::Label^ label1;
	private: Guna::UI::WinForms::GunaComboBox^ comboBox_mic;
	private: Guna::UI2::WinForms::Guna2Button^ button_save;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: Guna::UI::WinForms::GunaComboBox^ comboBox_dum;
	private: Guna::UI2::WinForms::Guna2Panel^ guna2Panel1;

	protected:
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
			this->components = (gcnew System::ComponentModel::Container());
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox_mic = (gcnew Guna::UI::WinForms::GunaComboBox());
			this->comboBox_dum = (gcnew Guna::UI::WinForms::GunaComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_save = (gcnew Guna::UI2::WinForms::Guna2Button());
			this->guna2Panel1 = (gcnew Guna::UI2::WinForms::Guna2Panel());
			this->SuspendLayout();
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->BorderRadius = 4;
			this->guna2Elipse1->TargetControl = this;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(115, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(282, 41);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Настройка студии";
			// 
			// comboBox_mic
			// 
			this->comboBox_mic->BackColor = System::Drawing::Color::Transparent;
			this->comboBox_mic->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->comboBox_mic->BorderColor = System::Drawing::Color::White;
			this->comboBox_mic->BorderSize = 1;
			this->comboBox_mic->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox_mic->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBox_mic->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_mic->FocusedColor = System::Drawing::Color::Empty;
			this->comboBox_mic->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->comboBox_mic->ForeColor = System::Drawing::Color::White;
			this->comboBox_mic->FormattingEnabled = true;
			this->comboBox_mic->Location = System::Drawing::Point(12, 87);
			this->comboBox_mic->Name = L"comboBox_mic";
			this->comboBox_mic->OnHoverItemBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->comboBox_mic->OnHoverItemForeColor = System::Drawing::Color::White;
			this->comboBox_mic->Radius = 5;
			this->comboBox_mic->Size = System::Drawing::Size(503, 31);
			this->comboBox_mic->TabIndex = 7;
			this->comboBox_mic->Tag = L"";
			// 
			// comboBox_dum
			// 
			this->comboBox_dum->BackColor = System::Drawing::Color::Transparent;
			this->comboBox_dum->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->comboBox_dum->BorderColor = System::Drawing::Color::White;
			this->comboBox_dum->BorderSize = 1;
			this->comboBox_dum->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox_dum->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBox_dum->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_dum->FocusedColor = System::Drawing::Color::Empty;
			this->comboBox_dum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->comboBox_dum->ForeColor = System::Drawing::Color::White;
			this->comboBox_dum->FormattingEnabled = true;
			this->comboBox_dum->Location = System::Drawing::Point(12, 159);
			this->comboBox_dum->Name = L"comboBox_dum";
			this->comboBox_dum->OnHoverItemBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->comboBox_dum->OnHoverItemForeColor = System::Drawing::Color::White;
			this->comboBox_dum->Radius = 5;
			this->comboBox_dum->Size = System::Drawing::Size(503, 31);
			this->comboBox_dum->TabIndex = 8;
			this->comboBox_dum->Tag = L"";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(12, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Выбор микрофона";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(12, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Выбор динамика";
			// 
			// button_save
			// 
			this->button_save->BorderRadius = 20;
			this->button_save->CheckedState->Parent = this->button_save;
			this->button_save->CustomImages->Parent = this->button_save;
			this->button_save->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_save->ForeColor = System::Drawing::Color::White;
			this->button_save->HoverState->Parent = this->button_save;
			this->button_save->Location = System::Drawing::Point(180, 207);
			this->button_save->Name = L"button_save";
			this->button_save->ShadowDecoration->Parent = this->button_save;
			this->button_save->Size = System::Drawing::Size(180, 45);
			this->button_save->TabIndex = 11;
			this->button_save->Text = L"Готово";
			this->button_save->Click += gcnew System::EventHandler(this, &SettingsStudioForm::button_save_Click);
			// 
			// guna2Panel1
			// 
			this->guna2Panel1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->guna2Panel1->BorderRadius = 4;
			this->guna2Panel1->BorderThickness = 1;
			this->guna2Panel1->Location = System::Drawing::Point(0, 1);
			this->guna2Panel1->Name = L"guna2Panel1";
			this->guna2Panel1->ShadowDecoration->Parent = this->guna2Panel1;
			this->guna2Panel1->Size = System::Drawing::Size(524, 262);
			this->guna2Panel1->TabIndex = 12;
			// 
			// SettingsStudioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(527, 264);
			this->Controls->Add(this->button_save);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox_dum);
			this->Controls->Add(this->comboBox_mic);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->guna2Panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SettingsStudioForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SettingsStudioForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}
