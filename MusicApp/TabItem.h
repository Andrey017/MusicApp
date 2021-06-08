#pragma once

#include "ElemList.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace MusicApp {

	/// <summary>
	/// Сводка для TabItem
	/// </summary>
	public ref class TabItem : public System::Windows::Forms::UserControl
	{
	public:
		TabItem(void)
		{
			InitializeComponent();
			GenerateLines();
			GenerateElems(0, 0, nullptr);
			//
			//TODO: добавьте код конструктора
			//
		}

		TabItem(int _id, bool isOpen, array<ElemList^>^ elemList)
		{
			InitializeComponent();
			GenerateLines();
			GenerateElems(_id, isOpen, elemList);
			//
			//TODO: добавьте код конструктора
			//
		}

	private:
		array<TextBox^>^ tabsList = gcnew array<TextBox^>(1152);



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TabItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI::WinForms::GunaPanel^ panelTabItem;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelTabItem = (gcnew Guna::UI::WinForms::GunaPanel());
			this->SuspendLayout();
			// 
			// panelTabItem
			// 
			this->panelTabItem->Location = System::Drawing::Point(0, 0);
			this->panelTabItem->Name = L"panelTabItem";
			this->panelTabItem->Size = System::Drawing::Size(120, 120);
			this->panelTabItem->TabIndex = 0;
			// 
			// TabItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Controls->Add(this->panelTabItem);
			this->Name = L"TabItem";
			this->Size = System::Drawing::Size(120, 120);
			this->ResumeLayout(false);

		}
#pragma endregion

		//Генерация линий
		void MusicApp::TabItem::GenerateLines() {
			for (int i = 0; i < 6; i++) {
				PictureBox^ line = gcnew PictureBox();
				line->Location = Point(0, 30 + i * 15);
				line->Size = Drawing::Size(120, 1);
				line->BackColor = Color::White;
				line->BringToFront();
				panelTabItem->Controls->Add(line);
			}
		}

		//Генерация элементов
		void MusicApp::TabItem::GenerateElems(int _id, bool isOpen, array<ElemList^>^ elemList) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 4; j++) {
					int k = 4 * i + j + _id * 24;
					/*elemList[k] = gcnew ElemList();

					elemList[k]->setId(_id);
					elemList[k]->setStringNum(i + _id * 24);
					elemList[k]->setElemNum (j + _id * 24);
					elemList[k]->setEffect("");*/

					tabsList[k] = gcnew TextBox();

					tabsList[k]->GetType()->GetProperty("Location")->SetValue(tabsList[k], Point(10 + 30 * j, 22 + 15 * i));
					tabsList[k]->Name = "textBox" + (k + _id * 24).ToString();
					tabsList[k]->Size = System::Drawing::Size(10, 16);
					tabsList[k]->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
					tabsList[k]->ForeColor = System::Drawing::Color::Transparent;
					tabsList[k]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
						System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
					tabsList[k]->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
					tabsList[k]->BorderStyle = System::Windows::Forms::BorderStyle::None;
					tabsList[k]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
						static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
					tabsList[k]->DoubleClick += gcnew System::EventHandler(this, &TabItem::TabListListDoubleClick);

					// Если открытие файла
					if (isOpen == 1 && elemList[4 * i + j]->getValue() != "") {
						tabsList[k]->Text = elemList[4 * i + j]->getValue();
						tabsList[k]->BringToFront();
					}

					panelTabItem->Controls->Add(tabsList[k]);
				}
			}

			//Увеличиваем значение индекса последней созданной панели
			//lastId++;
		}

		//Обработчик двойного нажатия на текст бокс
		void MusicApp::TabItem::TabListListDoubleClick(System::Object^ sender, System::EventArgs^ e) {
			TextBox^ wayItem = (TextBox^)sender;
			int lastElem = 0;

			for (int i = 0; i < (tabsList->Length); i++) {
				//Если элемент создан и пуст, то перемещаем на задний план
				if (tabsList[i] != nullptr && tabsList[i]->Text == "") {
					tabsList[i]->SendToBack();
				}
			}

			wayItem->BringToFront();
		}

	public: array<String^>^ MusicApp::TabItem::getArray(int _id) {
		array<String^>^ tabsListValues = gcnew array<String^>(24);

		for (int i = 0; i < 24; i++) {
			if (tabsList[i + _id * 24]->Text != nullptr) {
				tabsListValues[i] = tabsList[i + _id * 24]->Text;
			}
			/*else {
				tabsListValues[i] = "";
			}*/

		}
		return tabsListValues;
	}
	};
}
