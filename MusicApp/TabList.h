#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MusicApp {

	/// <summary>
	/// Сводка для TabList
	/// </summary>
	public ref class TabList : public System::Windows::Forms::UserControl
	{
	public:
		TabList(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	public: void setId_tab(String^ _id) {
		id = _id;

		//label_id->Text = id;
	}

	public: String^ getId_tab() {
		return id;
	}

	public: void setName(String^ _name) {
		name = _name;

		labelTabName->Text = name;
	}

	public: String^ getName() {
		return name;
	}

	public: void setCreator(String^ _creator) {
		creator = _creator;

		labelTabAuthor->Text = creator;
	}

	public: String^ getCreator() {
		return creator;
	}

	public: void setAccess(String^ _access) {
		access = _access;
	}

	public: String^ getAccess() {
		return access;
	}

	public: void setId_room(String^ _id_room) {
		id_room = _id_room;
	}

	public: String^ getId_room() {
		return id_room;
	}

	private:
		String^ name;
		String^ creator;
		String^ id;
		String^ access;
		String^ id_room;

		String^ ip;

		String^ user_id;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TabList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;
	protected:
	private: Guna::UI::WinForms::GunaLabel^ labelTabAuthor;
	private: Guna::UI::WinForms::GunaLabel^ labelTabName;
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
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->labelTabName = (gcnew Guna::UI::WinForms::GunaLabel());
			this->labelTabAuthor = (gcnew Guna::UI::WinForms::GunaLabel());
			this->SuspendLayout();
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->Radius = 5;
			this->gunaElipse1->TargetControl = this;
			// 
			// labelTabName
			// 
			this->labelTabName->AutoSize = true;
			this->labelTabName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelTabName->ForeColor = System::Drawing::Color::White;
			this->labelTabName->Location = System::Drawing::Point(12, 5);
			this->labelTabName->Name = L"labelTabName";
			this->labelTabName->Size = System::Drawing::Size(99, 20);
			this->labelTabName->TabIndex = 0;
			this->labelTabName->Text = L"Табулатура 1";
			// 
			// labelTabAuthor
			// 
			this->labelTabAuthor->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelTabAuthor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelTabAuthor->ForeColor = System::Drawing::Color::White;
			this->labelTabAuthor->Location = System::Drawing::Point(405, 6);
			this->labelTabAuthor->Name = L"labelTabAuthor";
			this->labelTabAuthor->Size = System::Drawing::Size(93, 20);
			this->labelTabAuthor->TabIndex = 1;
			this->labelTabAuthor->Text = L"J1gA";
			this->labelTabAuthor->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// TabList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->labelTabAuthor);
			this->Controls->Add(this->labelTabName);
			this->Name = L"TabList";
			this->Size = System::Drawing::Size(510, 32);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
