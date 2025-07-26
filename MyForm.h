#pragma once

namespace CppWeatherGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	/// 
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ cityname;
		System::Windows::Forms::Label^ temperature;
		System::Windows::Forms::Label^ weatherdetails;
		System::Windows::Forms::Button^ Checkweather;
		System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
		System::Windows::Forms::TextBox^ textBoxtemp;
		System::Windows::Forms::TextBox^ textBoxweather;

		System::ComponentModel::Container^ components;

		// Declare the event handler
		System::Void Checkweather_Click(System::Object^ sender, System::EventArgs^ e);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cityname = (gcnew System::Windows::Forms::Label());
			this->temperature = (gcnew System::Windows::Forms::Label());
			this->weatherdetails = (gcnew System::Windows::Forms::Label());
			this->Checkweather = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBoxtemp = (gcnew System::Windows::Forms::TextBox());
			this->textBoxweather = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(349, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(330, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"My Weather App";
			// 
			// cityname
			// 
			this->cityname->AutoSize = true;
			this->cityname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cityname->Location = System::Drawing::Point(59, 218);
			this->cityname->Name = L"cityname";
			this->cityname->Size = System::Drawing::Size(142, 29);
			this->cityname->TabIndex = 1;
			this->cityname->Text = L"CIty Name : ";
			// 
			// temperature
			// 
			this->temperature->AutoSize = true;
			this->temperature->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->temperature->Location = System::Drawing::Point(50, 381);
			this->temperature->Name = L"temperature";
			this->temperature->Size = System::Drawing::Size(256, 29);
			this->temperature->TabIndex = 2;
			this->temperature->Text = L"Current Temperature : ";
			// 
			// weatherdetails
			// 
			this->weatherdetails->AutoSize = true;
			this->weatherdetails->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weatherdetails->Location = System::Drawing::Point(50, 431);
			this->weatherdetails->Name = L"weatherdetails";
			this->weatherdetails->Size = System::Drawing::Size(201, 29);
			this->weatherdetails->TabIndex = 3;
			this->weatherdetails->Text = L"Weather Details : ";
			// 
			// Checkweather
			// 
			this->Checkweather->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Checkweather->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Checkweather->Location = System::Drawing::Point(55, 285);
			this->Checkweather->Name = L"Checkweather";
			this->Checkweather->Size = System::Drawing::Size(190, 50);
			this->Checkweather->TabIndex = 4;
			this->Checkweather->Text = L"Check Weather";
			this->Checkweather->UseVisualStyleBackColor = false;
			this->Checkweather->Click += gcnew System::EventHandler(this, &MyForm::Checkweather_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maskedTextBox1->Location = System::Drawing::Point(207, 218);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(229, 35);
			this->maskedTextBox1->TabIndex = 5;
			// 
			// textBoxtemp
			// 
			this->textBoxtemp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxtemp->Location = System::Drawing::Point(300, 385);
			this->textBoxtemp->Name = L"textBoxtemp";
			this->textBoxtemp->ReadOnly = true;
			this->textBoxtemp->Size = System::Drawing::Size(101, 35);
			this->textBoxtemp->TabIndex = 6;
			// 
			// textBoxweather
			// 
			this->textBoxweather->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxweather->Location = System::Drawing::Point(257, 431);
			this->textBoxweather->Name = L"textBoxweather";
			this->textBoxweather->ReadOnly = true;
			this->textBoxweather->Size = System::Drawing::Size(229, 35);
			this->textBoxweather->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1032, 643);
			this->Controls->Add(this->textBoxweather);
			this->Controls->Add(this->textBoxtemp);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->Checkweather);
			this->Controls->Add(this->weatherdetails);
			this->Controls->Add(this->temperature);
			this->Controls->Add(this->cityname);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};


}