#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MusicApp {

	/// <summary>
	/// —водка дл€ ListIconConf
	/// </summary>
	public ref class ListIconConf : public System::Windows::Forms::UserControl
	{
	public:
		ListIconConf(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ListIconConf()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI2::WinForms::Guna2CirclePictureBox^ guna2CirclePictureBox1;
	private: System::Windows::Forms::Label^ label_icon_conf;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListIconConf::typeid));
			this->guna2CirclePictureBox1 = (gcnew Guna::UI2::WinForms::Guna2CirclePictureBox());
			this->label_icon_conf = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// guna2CirclePictureBox1
			// 
			this->guna2CirclePictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"guna2CirclePictureBox1.Image")));
			this->guna2CirclePictureBox1->Location = System::Drawing::Point(38, 3);
			this->guna2CirclePictureBox1->Name = L"guna2CirclePictureBox1";
			this->guna2CirclePictureBox1->ShadowDecoration->Mode = Guna::UI2::WinForms::Enums::ShadowMode::Circle;
			this->guna2CirclePictureBox1->ShadowDecoration->Parent = this->guna2CirclePictureBox1;
			this->guna2CirclePictureBox1->Size = System::Drawing::Size(100, 100);
			this->guna2CirclePictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->guna2CirclePictureBox1->TabIndex = 0;
			this->guna2CirclePictureBox1->TabStop = false;
			// 
			// label_icon_conf
			// 
			this->label_icon_conf->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_icon_conf->AutoSize = true;
			this->label_icon_conf->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_icon_conf->Location = System::Drawing::Point(35, 115);
			this->label_icon_conf->Name = L"label_icon_conf";
			this->label_icon_conf->Size = System::Drawing::Size(106, 25);
			this->label_icon_conf->TabIndex = 14;
			this->label_icon_conf->Text = L"Name_user";
			this->label_icon_conf->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ListIconConf
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label_icon_conf);
			this->Controls->Add(this->guna2CirclePictureBox1);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"ListIconConf";
			this->Size = System::Drawing::Size(179, 150);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->guna2CirclePictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
