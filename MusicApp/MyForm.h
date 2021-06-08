#pragma once
#include "FrequencyCheck.h"
#include "Tabs.h"

namespace MusicApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NAudio::Wave;
	using namespace NAudio;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			// тут запись начинаетс€ и врубаетс€ таймер
			MusicApp::MyForm::StartRecordMusic();
			//MusicApp::MyForm::RecordTuner();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// WaveIn - поток дл€ записи
		WaveIn^ waveIn;
		//  ласс дл€ записи в файл
		WaveFileWriter^ writer;
		// »м€ файла дл€ записи
		String^ outputFileName = "Test_sound.wav";

		array<String^>^ devices = gcnew array<String^>(2);

		WaveFileReader^ wave = nullptr;
		DirectSoundOut^ output = nullptr;

		int deviceNum = 0;
		int deviceNumSelected = 0;

		// —писок с данными записанного отрезка аудио из буфера
		System::Collections::Generic::List<double>^ dat = gcnew System::Collections::Generic::List<double>;

		FFTTuner::FrequencyCheck freqCheck;




	protected:



	private: Guna::UI::WinForms::GunaProgressBar^ gunaProgressBar1;
	private: Guna::UI::WinForms::GunaComboBox^ comboBoxNote;
	private: Guna::UI::WinForms::GunaComboBox^ comboBoxDevice;
	private: Guna::UI::WinForms::GunaLabel^ labelTergetFrequency;
	private: Guna::UI::WinForms::GunaLabel^ labelHz;
	private: Guna::UI::WinForms::GunaPictureBox^ exit;
	private: Guna::UI::WinForms::GunaLabel^ redTarget;
	private: Guna::UI::WinForms::GunaComboBox^ comboBoxInstrument;
	private: Guna::UI::WinForms::GunaElipse^ gunaElipse1;
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->gunaProgressBar1 = (gcnew Guna::UI::WinForms::GunaProgressBar());
			this->comboBoxNote = (gcnew Guna::UI::WinForms::GunaComboBox());
			this->comboBoxDevice = (gcnew Guna::UI::WinForms::GunaComboBox());
			this->labelTergetFrequency = (gcnew Guna::UI::WinForms::GunaLabel());
			this->labelHz = (gcnew Guna::UI::WinForms::GunaLabel());
			this->exit = (gcnew Guna::UI::WinForms::GunaPictureBox());
			this->redTarget = (gcnew Guna::UI::WinForms::GunaLabel());
			this->comboBoxInstrument = (gcnew Guna::UI::WinForms::GunaComboBox());
			this->gunaElipse1 = (gcnew Guna::UI::WinForms::GunaElipse(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->BeginInit();
			this->SuspendLayout();
			// 
			// gunaProgressBar1
			// 
			this->gunaProgressBar1->BackColor = System::Drawing::Color::Transparent;
			this->gunaProgressBar1->BorderColor = System::Drawing::Color::Black;
			this->gunaProgressBar1->ColorStyle = Guna::UI::WinForms::ColorStyle::Default;
			this->gunaProgressBar1->Cursor = System::Windows::Forms::Cursors::Default;
			this->gunaProgressBar1->IdleColor = System::Drawing::Color::White;
			this->gunaProgressBar1->Location = System::Drawing::Point(12, 76);
			this->gunaProgressBar1->Name = L"gunaProgressBar1";
			this->gunaProgressBar1->ProgressMaxColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaProgressBar1->ProgressMinColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gunaProgressBar1->Radius = 3;
			this->gunaProgressBar1->Size = System::Drawing::Size(572, 23);
			this->gunaProgressBar1->TabIndex = 5;
			this->gunaProgressBar1->Value = 23;
			// 
			// comboBoxNote
			// 
			this->comboBoxNote->BackColor = System::Drawing::Color::Transparent;
			this->comboBoxNote->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->comboBoxNote->BorderColor = System::Drawing::Color::White;
			this->comboBoxNote->BorderSize = 1;
			this->comboBoxNote->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBoxNote->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBoxNote->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxNote->FocusedColor = System::Drawing::Color::Empty;
			this->comboBoxNote->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->comboBoxNote->ForeColor = System::Drawing::Color::White;
			this->comboBoxNote->FormattingEnabled = true;
			this->comboBoxNote->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"E", L"B", L"G", L"D", L"A", L"E" });
			this->comboBoxNote->Location = System::Drawing::Point(212, 11);
			this->comboBoxNote->Name = L"comboBoxNote";
			this->comboBoxNote->OnHoverItemBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->comboBoxNote->OnHoverItemForeColor = System::Drawing::Color::White;
			this->comboBoxNote->Radius = 5;
			this->comboBoxNote->Size = System::Drawing::Size(42, 31);
			this->comboBoxNote->TabIndex = 5;
			this->comboBoxNote->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::gunaComboBox2_SelectedIndexChanged);
			// 
			// comboBoxDevice
			// 
			this->comboBoxDevice->BackColor = System::Drawing::Color::Transparent;
			this->comboBoxDevice->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->comboBoxDevice->BorderColor = System::Drawing::Color::White;
			this->comboBoxDevice->BorderSize = 1;
			this->comboBoxDevice->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBoxDevice->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBoxDevice->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxDevice->FocusedColor = System::Drawing::Color::Empty;
			this->comboBoxDevice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->comboBoxDevice->ForeColor = System::Drawing::Color::White;
			this->comboBoxDevice->FormattingEnabled = true;
			this->comboBoxDevice->Location = System::Drawing::Point(260, 11);
			this->comboBoxDevice->Name = L"comboBoxDevice";
			this->comboBoxDevice->OnHoverItemBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->comboBoxDevice->OnHoverItemForeColor = System::Drawing::Color::White;
			this->comboBoxDevice->Radius = 5;
			this->comboBoxDevice->Size = System::Drawing::Size(303, 31);
			this->comboBoxDevice->TabIndex = 6;
			this->comboBoxDevice->Tag = L"";
			this->comboBoxDevice->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxDevice_SelectedIndexChanged);
			// 
			// labelTergetFrequency
			// 
			this->labelTergetFrequency->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTergetFrequency->Cursor = System::Windows::Forms::Cursors::Default;
			this->labelTergetFrequency->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->labelTergetFrequency->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->labelTergetFrequency->Location = System::Drawing::Point(12, 45);
			this->labelTergetFrequency->Name = L"labelTergetFrequency";
			this->labelTergetFrequency->Size = System::Drawing::Size(572, 28);
			this->labelTergetFrequency->TabIndex = 7;
			this->labelTergetFrequency->Text = L"146.832 √ц";
			this->labelTergetFrequency->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelTergetFrequency->Click += gcnew System::EventHandler(this, &MyForm::gunaLabel1_Click);
			// 
			// labelHz
			// 
			this->labelHz->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelHz->Cursor = System::Windows::Forms::Cursors::Default;
			this->labelHz->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->labelHz->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelHz->Location = System::Drawing::Point(12, 102);
			this->labelHz->Name = L"labelHz";
			this->labelHz->Size = System::Drawing::Size(572, 28);
			this->labelHz->TabIndex = 8;
			this->labelHz->Text = L"138.658 √ц";
			this->labelHz->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelHz->Click += gcnew System::EventHandler(this, &MyForm::labelHz_Click_1);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->BaseColor = System::Drawing::Color::White;
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->ErrorImage = nullptr;
			this->exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.Image")));
			this->exit->InitialImage = nullptr;
			this->exit->Location = System::Drawing::Point(559, 12);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(33, 31);
			this->exit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->exit->TabIndex = 9;
			this->exit->TabStop = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::gunaPictureBox1_Click);
			// 
			// redTarget
			// 
			this->redTarget->BackColor = System::Drawing::Color::Red;
			this->redTarget->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->redTarget->Font = (gcnew System::Drawing::Font(L"Segoe UI", 1));
			this->redTarget->ForeColor = System::Drawing::Color::Red;
			this->redTarget->Location = System::Drawing::Point(295, 71);
			this->redTarget->Name = L"redTarget";
			this->redTarget->Size = System::Drawing::Size(5, 32);
			this->redTarget->TabIndex = 10;
			this->redTarget->UseMnemonic = false;
			this->redTarget->Click += gcnew System::EventHandler(this, &MyForm::gunaLabel2_Click);
			// 
			// comboBoxInstrument
			// 
			this->comboBoxInstrument->BackColor = System::Drawing::Color::Transparent;
			this->comboBoxInstrument->BaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->comboBoxInstrument->BorderColor = System::Drawing::Color::White;
			this->comboBoxInstrument->BorderSize = 1;
			this->comboBoxInstrument->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBoxInstrument->DisplayMember = L"0";
			this->comboBoxInstrument->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->comboBoxInstrument->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxInstrument->FocusedColor = System::Drawing::Color::Empty;
			this->comboBoxInstrument->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->comboBoxInstrument->ForeColor = System::Drawing::Color::White;
			this->comboBoxInstrument->FormattingEnabled = true;
			this->comboBoxInstrument->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"јкустическа€ гитара", L"7-струнна€ гитара",
					L"12-струнна€ гитара", L"”кулеле"
			});
			this->comboBoxInstrument->Location = System::Drawing::Point(12, 11);
			this->comboBoxInstrument->Name = L"comboBoxInstrument";
			this->comboBoxInstrument->OnHoverItemBaseColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->comboBoxInstrument->OnHoverItemForeColor = System::Drawing::Color::White;
			this->comboBoxInstrument->Radius = 5;
			this->comboBoxInstrument->Size = System::Drawing::Size(194, 31);
			this->comboBoxInstrument->TabIndex = 11;
			this->comboBoxInstrument->ValueMember = L"0";
			// 
			// gunaElipse1
			// 
			this->gunaElipse1->Radius = 5;
			this->gunaElipse1->TargetControl = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(596, 133);
			this->ControlBox = false;
			this->Controls->Add(this->comboBoxInstrument);
			this->Controls->Add(this->redTarget);
			this->Controls->Add(this->labelHz);
			this->Controls->Add(this->labelTergetFrequency);
			this->Controls->Add(this->comboBoxDevice);
			this->Controls->Add(this->comboBoxNote);
			this->Controls->Add(this->gunaProgressBar1);
			this->Controls->Add(this->exit);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exit))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelNote_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelHz_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void StartRecordMusic();
	private: void waveIn_DataAvailable(System::Object^ sender, WaveInEventArgs^ e);
	private: void waveIn_RecordingStopped(System::Object^ sender, StoppedEventArgs^ e);
	private: void StopRecording();
	private: void RecordTuner();
	private: bool ProcessData(WaveInEventArgs^ e);


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MusicApp::MyForm::StartRecordMusic();
	}

	private: System::Void buttonStopRecord_Click(System::Object^ sender, System::EventArgs^ e) {
		MusicApp::MyForm::StopRecording();
	}

		   //таймер
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (waveIn != nullptr) {
			MusicApp::MyForm::StopRecording();
		}
		array<double>^ data = gcnew array<double>(dat->Count);
		for (int i = 0; i < dat->Count; i++) {
			data[i] = dat[i] / 32768.0;
		}
		//dat->Clear();

		double resultFreq = freqCheck.FindFundamentalFrequency(data, 44100, 60, 440);
		labelHz->Text = resultFreq.ToString();

		MusicApp::MyForm::StartRecordMusic();
	}
	private: System::Void gunaLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gunaComboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gunaPictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		Tabs^ form = gcnew Tabs();
		form->Show();
	}
	private: System::Void gunaLabel2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBoxDevice_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		//MusicApp::MyForm::StopRecording();

		switch (comboBoxDevice->SelectedIndex)
		{
		case 1:
			deviceNum = 0;
		case 2:
			deviceNum = 1;
		default:
			break;
		}

		deviceNumSelected = comboBoxDevice->SelectedIndex;

		//MusicApp::MyForm::StartRecordMusic();
	}
	private: System::Void labelHz_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
