#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MusicApp {

	/// <summary>
	/// —водка дл€ WayEditorItem
	/// </summary>
	public ref class WayEditorItem : public System::Windows::Forms::UserControl
	{
	public:
		WayEditorItem(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		WayEditorItem(String^ _teme)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			teme = _teme;

			if (teme == "1") {
				SetupInterface();
			}
		}

	public: void setName_Way(String^ _name_way) {
		name_way = _name_way;

		label_name_way->Text = name_way;
	}

	public: String^ getName_Way() {
		return label_name_way->Text;
	}

	public: void setName_Room(String^ _name_room) {
		name_studio = _name_room;
	}

	public: String^ getName_Room() {
		return name_studio;
	}

	private: String^ name_way;
		   String^ name_studio;
		   String^ teme;

		   //ƒл€ интерфейса
		   int d_r_back = 15;
		   int d_g_back = 19;
		   int d_b_back = 25;

		   int d_r_elem = 32;
		   int d_g_elem = 36;
		   int d_b_elem = 43;
	private: Guna::UI2::WinForms::Guna2Elipse^ guna2Elipse1;

		   int d_text_color = 238;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~WayEditorItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_name_way;
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
			this->label_name_way = (gcnew System::Windows::Forms::Label());
			this->guna2Elipse1 = (gcnew Guna::UI2::WinForms::Guna2Elipse(this->components));
			this->SuspendLayout();
			// 
			// label_name_way
			// 
			this->label_name_way->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_name_way->AutoSize = true;
			this->label_name_way->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_way->Location = System::Drawing::Point(4, 24);
			this->label_name_way->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_name_way->Name = L"label_name_way";
			this->label_name_way->Size = System::Drawing::Size(92, 23);
			this->label_name_way->TabIndex = 2;
			this->label_name_way->Text = L"Name_way";
			this->label_name_way->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// guna2Elipse1
			// 
			this->guna2Elipse1->BorderRadius = 10;
			this->guna2Elipse1->TargetControl = this;
			// 
			// WayEditorItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Controls->Add(this->label_name_way);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"WayEditorItem";
			this->Size = System::Drawing::Size(311, 75);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void SetupInterface() {
		this->BackColor = Color::FromArgb(32, 36, 43);

		label_name_way->BackColor = Color::FromArgb(32, 36, 43);
		label_name_way->ForeColor = Color::FromArgb(d_text_color, d_text_color, d_text_color);
	}
	};
}
