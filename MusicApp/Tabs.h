#pragma once
#include "TabOpen.h"
#include "TabSave.h"
#include "TabItem.h"

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Tabs
	/// </summary>
	public ref class Tabs : public System::Windows::Forms::Form
	{
	public:
		Tabs(void)
		{
			InitializeComponent();
			GenerateTab(0);
			//AddTabPanel(0);
			//gunaLabel1->SendToBack();
			//
			//TODO: добавьте код конструктора
			//
		}

		Tabs(int _id)
		{
			//
			//TODO: добавьте код конструктора
			//
		}

		array<ElemList^>^ elemList = gcnew array<ElemList^>(1152);

	private: Guna::UI::WinForms::GunaPictureBox^ newTabItem;

	public:

		int lastId = 0;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Tabs()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;
	private: Guna::UI::WinForms::GunaElipsePanel^ gunaElipsePanel2;
	private: Guna::UI::WinForms::GunaButton^ gunaButtonSave;
	private: Guna::UI::WinForms::GunaButton^ gunaButtonOpenFile;
	private: Guna::UI::WinForms::GunaElipsePanel^ gunaElipsePanel1;
	private: Guna::UI::WinForms::GunaButton^ gunaButton2;
	private: Guna::UI::WinForms::GunaPictureBox^ exit;
	private: Guna::UI::WinForms::GunaLabel^ gunaLabel1;

	private: Guna::UI::WinForms::GunaContextMenuStrip^ gunaContextMenuStrip1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Tabs::typeid));
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			this->gunaElipsePanel1 = (gcnew Guna::UI::WinForms::GunaElipsePanel());
			this->newTabItem = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->gunaLabel1 = (gcnew Guna::UI::WinForms::GunaLabel());
			this->exit = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->gunaElipsePanel2 = (gcnew Guna::UI::WinForms::GunaElipsePanel());
			this->gunaButton2 = (gcnew Guna::UI::WinForms::GunaButton());
			this->gunaButtonSave = (gcnew Guna::UI::WinForms::GunaButton());
			this->gunaButtonOpenFile = (gcnew Guna::UI::WinForms::GunaButton());
			this->gunaContextMenuStrip1 = (gcnew Guna::UI::WinForms::GunaContextMenuStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newTabItem))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->BeginInit();
			this->gunaElipsePanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->Radius = 5;
			this->gunaElipse1->TargetControl = this;
			// 
			// gunaElipsePanel1
			// 
			this->gunaElipsePanel1->AutoScroll = true;
			this->gunaElipsePanel1->BackColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel1->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->gunaElipsePanel1->Location = System::Drawing::Point(12, 38);
			this->gunaElipsePanel1->Name = L"gunaElipsePanel1";
			this->gunaElipsePanel1->Radius = 10;
			this->gunaElipsePanel1->Size = System::Drawing::Size(1063, 360);
			this->gunaElipsePanel1->TabIndex = 0;
			// 
			// newTabItem
			// 
			this->newTabItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->newTabItem->BaseColor = System::Drawing::Color::White;
			this->newTabItem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->newTabItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newTabItem.Image")));
			this->newTabItem->Location = System::Drawing::Point(194, 90);
			this->newTabItem->Name = L"newTabItem";
			this->newTabItem->Size = System::Drawing::Size(31, 31);
			this->newTabItem->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->newTabItem->TabIndex = 5;
			this->newTabItem->TabStop = false;
			this->newTabItem->Click += gcnew System::EventHandler(this, &Tabs::newTabItem_Click);
			// 
			// gunaLabel1
			// 
			this->gunaLabel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->gunaLabel1->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gunaLabel1->ForeColor = System::Drawing::Color::White;
			this->gunaLabel1->Location = System::Drawing::Point(21, 69);
			this->gunaLabel1->Margin = System::Windows::Forms::Padding(0);
			this->gunaLabel1->Name = L"gunaLabel1";
			this->gunaLabel1->Size = System::Drawing::Size(22, 75);
			this->gunaLabel1->TabIndex = 0;
			this->gunaLabel1->Text = L"T\r\nA\r\nB";
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->BaseColor = System::Drawing::Color::White;
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->ErrorImage = nullptr;
			this->exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.Image")));
			this->exit->InitialImage = nullptr;
			this->exit->Location = System::Drawing::Point(1039, 0);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(31, 31);
			this->exit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->exit->TabIndex = 10;
			this->exit->TabStop = false;
			this->exit->Click += gcnew System::EventHandler(this, &Tabs::exit_Click);
			// 
			// gunaElipsePanel2
			// 
			this->gunaElipsePanel2->BackColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel2->BaseColor = System::Drawing::Color::Transparent;
			this->gunaElipsePanel2->Controls->Add(this->exit);
			this->gunaElipsePanel2->Controls->Add(this->gunaButton2);
			this->gunaElipsePanel2->Controls->Add(this->gunaButtonSave);
			this->gunaElipsePanel2->Controls->Add(this->gunaButtonOpenFile);
			this->gunaElipsePanel2->Location = System::Drawing::Point(12, 4);
			this->gunaElipsePanel2->Name = L"gunaElipsePanel2";
			this->gunaElipsePanel2->Radius = 1;
			this->gunaElipsePanel2->Size = System::Drawing::Size(1063, 31);
			this->gunaElipsePanel2->TabIndex = 1;
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
			this->gunaButton2->Location = System::Drawing::Point(246, 3);
			this->gunaButton2->Name = L"gunaButton2";
			this->gunaButton2->OnHoverBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaButton2->OnHoverBorderColor = System::Drawing::Color::Black;
			this->gunaButton2->OnHoverForeColor = System::Drawing::Color::White;
			this->gunaButton2->OnHoverImage = nullptr;
			this->gunaButton2->OnPressedColor = System::Drawing::Color::Black;
			this->gunaButton2->Size = System::Drawing::Size(124, 25);
			this->gunaButton2->TabIndex = 2;
			this->gunaButton2->Text = L"Эффекты";
			// 
			// gunaButtonSave
			// 
			this->gunaButtonSave->AnimationHoverSpeed = 0.07F;
			this->gunaButtonSave->AnimationSpeed = 0.03F;
			this->gunaButtonSave->BaseColor = System::Drawing::Color::Transparent;
			this->gunaButtonSave->BorderColor = System::Drawing::Color::Black;
			this->gunaButtonSave->DialogResult = System::Windows::Forms::DialogResult::None;
			this->gunaButtonSave->FocusedColor = System::Drawing::Color::Empty;
			this->gunaButtonSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaButtonSave->ForeColor = System::Drawing::Color::White;
			this->gunaButtonSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gunaButtonSave.Image")));
			this->gunaButtonSave->ImageSize = System::Drawing::Size(20, 20);
			this->gunaButtonSave->Location = System::Drawing::Point(116, 3);
			this->gunaButtonSave->Name = L"gunaButtonSave";
			this->gunaButtonSave->OnHoverBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaButtonSave->OnHoverBorderColor = System::Drawing::Color::Black;
			this->gunaButtonSave->OnHoverForeColor = System::Drawing::Color::White;
			this->gunaButtonSave->OnHoverImage = nullptr;
			this->gunaButtonSave->OnPressedColor = System::Drawing::Color::Black;
			this->gunaButtonSave->Size = System::Drawing::Size(124, 25);
			this->gunaButtonSave->TabIndex = 1;
			this->gunaButtonSave->Text = L"Сохранить";
			this->gunaButtonSave->Click += gcnew System::EventHandler(this, &Tabs::gunaButtonSave_Click);
			// 
			// gunaButtonOpenFile
			// 
			this->gunaButtonOpenFile->AnimationHoverSpeed = 0.07F;
			this->gunaButtonOpenFile->AnimationSpeed = 0.03F;
			this->gunaButtonOpenFile->BaseColor = System::Drawing::Color::Transparent;
			this->gunaButtonOpenFile->BorderColor = System::Drawing::Color::Black;
			this->gunaButtonOpenFile->DialogResult = System::Windows::Forms::DialogResult::None;
			this->gunaButtonOpenFile->FocusedColor = System::Drawing::Color::Empty;
			this->gunaButtonOpenFile->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->gunaButtonOpenFile->ForeColor = System::Drawing::Color::White;
			this->gunaButtonOpenFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gunaButtonOpenFile.Image")));
			this->gunaButtonOpenFile->ImageSize = System::Drawing::Size(20, 20);
			this->gunaButtonOpenFile->Location = System::Drawing::Point(3, 3);
			this->gunaButtonOpenFile->Name = L"gunaButtonOpenFile";
			this->gunaButtonOpenFile->OnHoverBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaButtonOpenFile->OnHoverBorderColor = System::Drawing::Color::Black;
			this->gunaButtonOpenFile->OnHoverForeColor = System::Drawing::Color::White;
			this->gunaButtonOpenFile->OnHoverImage = nullptr;
			this->gunaButtonOpenFile->OnPressedColor = System::Drawing::Color::Black;
			this->gunaButtonOpenFile->Size = System::Drawing::Size(107, 25);
			this->gunaButtonOpenFile->TabIndex = 0;
			this->gunaButtonOpenFile->Text = L"Открыть";
			this->gunaButtonOpenFile->Click += gcnew System::EventHandler(this, &Tabs::gunaButtonOpenFile_Click);
			// 
			// gunaContextMenuStrip1
			// 
			this->gunaContextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->gunaContextMenuStrip1->Name = L"gunaContextMenuStrip1";
			this->gunaContextMenuStrip1->RenderStyle->ArrowColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(151)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaContextMenuStrip1->RenderStyle->BorderColor = System::Drawing::Color::Gainsboro;
			this->gunaContextMenuStrip1->RenderStyle->ColorTable = nullptr;
			this->gunaContextMenuStrip1->RenderStyle->RoundedEdges = true;
			this->gunaContextMenuStrip1->RenderStyle->SelectionArrowColor = System::Drawing::Color::White;
			this->gunaContextMenuStrip1->RenderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaContextMenuStrip1->RenderStyle->SelectionForeColor = System::Drawing::Color::White;
			this->gunaContextMenuStrip1->RenderStyle->SeparatorColor = System::Drawing::Color::Gainsboro;
			this->gunaContextMenuStrip1->RenderStyle->TextRenderingHint = Guna::UI::WinForms::DrawingTextRenderingHint::SystemDefault;
			this->gunaContextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// Tabs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1088, 410);
			this->Controls->Add(this->newTabItem);
			this->Controls->Add(this->gunaLabel1);
			this->Controls->Add(this->gunaElipsePanel2);
			this->Controls->Add(this->gunaElipsePanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Tabs";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newTabItem))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->EndInit();
			this->gunaElipsePanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		void MusicApp::Tabs::GenerateTab(int _id) {
			gunaLabel1->BringToFront();
			for (int i = 0; i < 6; i++) {
				PictureBox^ line = gcnew PictureBox();
				line->Location = Point(22, 68 + i * 15);
				line->Size = Drawing::Size(50, 1);
				line->BackColor = Color::White;

				Controls->Add(line);
				line->BringToFront();
			}
			AddTabPanel(_id, 0, nullptr);
		}
		//добавление новой панели
		void MusicApp::Tabs::AddTabPanel(int _id, bool isOpen, array<ElemList^>^ elemList) {

			// Если новый файл
			if (isOpen == 0) {
				TabItem^ tabItem = gcnew TabItem();

				gunaElipsePanel1->Controls->Add(tabItem);

				tabItem->GetType()->GetProperty("Location")->SetValue(tabItem, Point(60 + (_id % 8) * 120, 0 + (_id / 8) * 120));
				tabItem->BringToFront();
			}
			else { // Если открыт файл
				TabItem^ tabItem = gcnew TabItem(_id, isOpen, elemList);

				gunaElipsePanel1->Controls->Add(tabItem);

				tabItem->GetType()->GetProperty("Location")->SetValue(tabItem, Point(60 + (_id % 8) * 120, 0 + (_id / 8) * 120));
				tabItem->BringToFront();
			}
			//lastId++;
		}

		// Открытие XML
		void MusicApp::Tabs::openXML(String^ fileName) {
			XmlDocument^ doc = gcnew XmlDocument();
			doc->Load("./" + fileName + ".xml");
			XmlElement^ root = doc->DocumentElement;

			int l = 0;
			int j = 0;
			int i = 0;
			int k = 0;
			String^ xvalue = "";
			String^ xeffect = "";

			for each (XmlNode ^ xblock in root) {
				if (xblock->Attributes->Count > 0)
				{
					XmlNode^ attr = xblock->Attributes->GetNamedItem("id");
					if (attr != nullptr)
						l = Int32::Parse(attr->Value);
				}
				for each (XmlNode ^ xstring in xblock->ChildNodes) {
					if (xstring->Attributes->Count > 0)
					{
						XmlNode^ attr2 = xstring->Attributes->GetNamedItem("num");
						if (attr2 != nullptr)
							j = Int32::Parse(attr2->Value);
					}
					for each (XmlNode ^ xelement in xstring->ChildNodes) {
						if (xelement->Attributes->Count > 0)
						{
							XmlNode^ attr3 = xelement->Attributes->GetNamedItem("el_id");
							if (attr3 != nullptr)
								i = Int32::Parse(attr3->Value);
						}

						k = i + j * 4 + l * 24;

						for each (XmlNode ^ childnode in xelement->ChildNodes)
						{
							if (childnode->Name == "value")
							{
								xvalue = childnode->InnerText;
							}
							if (childnode->Name == "effect")
							{
								xeffect = childnode->InnerText;
							}
						}
						elemList[k] = gcnew ElemList(xvalue, xeffect);
					}
				}
			}
			lastId = l;

			gunaElipsePanel1->Controls->Clear();

			//отрисовка открытой табулатуры
			array<ElemList^>^ elemListBlock = gcnew array<ElemList^>(24);

			int currentId = 0;
			for (int i = 0; i < (lastId + 1) * 24; i++) {
				elemListBlock[i % 24] = gcnew ElemList(elemList[i]->getValue(), elemList[i]->getEffect());

				if ((i + 1) % 24 == 0 && i != 0 && currentId <= lastId) {
					AddTabPanel(currentId, 1, elemListBlock);
					currentId++;
				}
			}
			newTabItem->GetType()->GetProperty("Location")->SetValue(newTabItem, Point(194 + ((lastId) % 8) * 120, 90 + ((lastId) / 8) * 120));
		}

	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void gunaButtonOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {
		TabOpen^ form = gcnew TabOpen();
		form->ShowDialog();
		//тут функция открытия xml
		openXML("document");
	}

	private: System::Void gunaButtonSave_Click(System::Object^ sender, System::EventArgs^ e) {
		TabSave^ form = gcnew TabSave();
		form->ShowDialog();

		int j = lastId;
		int l = 0;
		for each (Control ^ control in gunaElipsePanel1->Controls) {
			TabItem^ tabs = (TabItem^)control;

			array<String^>^ arr = tabs->getArray(l);
			int k = 24 * j;
			for (int i = 0; i < 24; i++) {
				elemList[i + k] = gcnew ElemList(arr[i], "");
			}
			j--;
			l++;
		}
		elemList[0]->CreateXML(elemList, lastId + 1);
	}

	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
		if (e->ClickedItem->BackColor != Color::FromArgb(94, 148, 255)) {
			e->ClickedItem->BackColor = Color::FromArgb(94, 148, 255);
		}
	}

	private: System::Void newTabItem_Click(System::Object^ sender, System::EventArgs^ e) {
		newTabItem->GetType()->GetProperty("Location")->SetValue(newTabItem, Point(194 + ((lastId + 1) % 8) * 120, 90 + ((lastId + 1) / 8) * 120));
		AddTabPanel(lastId + 1, 0, nullptr);
		lastId++;
	}
	};
}
