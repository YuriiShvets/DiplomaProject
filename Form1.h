#pragma once

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include "loginForm.h"
using namespace std;



namespace Program {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		string *patientName;
		float **patientData;
		int patientSizeI; //кількість записів
		int patientDataSizeJ;
		int selectedResearch;
		loginForm^ previousForm;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  deleteButton;

	private: System::Windows::Forms::Button^  openButton;
	public: 

		Form1(loginForm^ inLoginForm)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			previousForm = inLoginForm;
			patientDataSizeJ = 13;

			ifstream F ("db.txt");
			if (F.is_open()) {

				int intBuf;			//буфер
				string stringBuf;
				float floatBuf;

				F >> intBuf;
				patientSizeI = intBuf;
				//maskedTextBox1->Text = "" + patientSizeI;
				//
				// створюємо масиви з даними
				//
				patientName = new string[patientSizeI];
				patientData = new float*[patientSizeI];
				for(int i = 0; i < patientSizeI; i++) {
					patientData[i] = new float[patientDataSizeJ];
				}
				for(int i = 0; i < patientSizeI; i++) {
					F >> stringBuf;
					for(int j = 0; j < stringBuf.size(); j++){
						if(stringBuf[j] == '_') {
							stringBuf[j] = ' ';
						}
					}
					patientName[i] = stringBuf;
					for (int j = 0; j < patientDataSizeJ; j++) {
						F >> floatBuf;
						patientData[i][j] = floatBuf;
					}
				}
				F.close();

				//
				//заповнюємо ComboBox
				//
				/*array<Object^>^temp1 = gcnew array<Object^>(patientSizeI + 1);
				temp1[0] = "Новий паціент";
				for(int i = 0; i < patientSizeI; i++) {
					temp1[i + 1] = ;			
				}*/
			
				//this->patientComboBox->Items->AddRange( temp1 );
				this->patientComboBox->Items->Insert(0, "Додати нове дослідження");
				for(int i = 0; i < patientSizeI; i++) {
					//string buf = (patientName[i][0] + " " + patientName[i][1]);
					//char *buf2 = new char[buf.length() + 1];
					//strcpy(buf2, buf.c_str());
					String ^systemstring = gcnew String((patientName[i]).c_str());
					this->patientComboBox->Items->Insert(i + 1,systemstring);
					delete systemstring;
				}
				patientComboBox->SelectedIndex = 0;
			}
		}

		void startWorkForm(int inSelectedResearch, string* inPatientName, float** inPatientData, int inPatientSizeI, int inPatientDataSizeJ);

		void close(); //закрити форму

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}

			previousForm -> close();
			//delete patientName;
			for(int i = 0; i < patientSizeI; i++) {
				delete patientData[i];
			}
			delete patientData;
		}
	private: System::Windows::Forms::ComboBox^  patientComboBox;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->patientComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// patientComboBox
			// 
			this->patientComboBox->CausesValidation = false;
			this->patientComboBox->FormattingEnabled = true;
			this->patientComboBox->Location = System::Drawing::Point(86, 12);
			this->patientComboBox->Name = L"patientComboBox";
			this->patientComboBox->Size = System::Drawing::Size(281, 21);
			this->patientComboBox->TabIndex = 0;
			this->patientComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::patientComboBox_SelectedIndexChanged);
			// 
			// openButton
			// 
			this->openButton->Location = System::Drawing::Point(10, 39);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(75, 23);
			this->openButton->TabIndex = 2;
			this->openButton->Text = L"Відкрити";
			this->openButton->UseVisualStyleBackColor = true;
			this->openButton->Click += gcnew System::EventHandler(this, &Form1::openButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Дослідження";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(91, 38);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 4;
			this->deleteButton->Text = L"Видалити";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 73);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->openButton);
			this->Controls->Add(this->patientComboBox);
			this->Name = L"Form1";
			this->Text = L"DSHV1 © Швець Юрій";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void patientComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void openButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(patientComboBox->SelectedItem == "Додати нове дослідження") {	//додаємо одне дослідження
				string *newPatientName;
				float **newPatientData;

				newPatientName = new string[patientSizeI + 1];
				newPatientData = new float*[patientSizeI + 1];
				for(int i = 0; i < patientSizeI + 1; i++) {
					newPatientData[i] = new float[patientDataSizeJ];
				}
				for(int i = 0; i < patientSizeI; i++) {
					newPatientName[i] = patientName[i];
					for (int j = 0; j < patientDataSizeJ; j++) {
						newPatientData[i][j] = patientData[i][j];
					}
				}
				patientSizeI++;
				newPatientName[patientSizeI - 1] = "Нове дослідження";
				for (int j = 0; j < patientDataSizeJ; j++) {
					newPatientData[patientSizeI - 1][j] = 0;
				}

				//delete patientName;
				for(int i = 0; i < patientSizeI - 1; i++) {
					delete patientData[i];
				}
				delete patientData;

				patientName = newPatientName;
				patientData = newPatientData;
				selectedResearch = patientSizeI - 1;
			 }
			 else
				selectedResearch = patientComboBox->SelectedIndex - 1;
			 this->startWorkForm(selectedResearch, patientName, patientData, patientSizeI, patientDataSizeJ);
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

