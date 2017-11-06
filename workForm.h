#pragma once

#include "Form1.h"
#include "fann.h"
#include "floatfann.h"

namespace Program {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для workForm
	/// </summary>
	public ref class workForm : public System::Windows::Forms::Form
	{
	public:

		Form1^ form1;		//стартова форма
		int selectedResearch;
		string* patientName;
		float** patientData;
		int patientSizeI;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::ComboBox^  ageComboBox;

	private: System::Windows::Forms::ComboBox^  sexComboBox;
	private: System::Windows::Forms::ComboBox^  chestPainComboBox;
	private: System::Windows::Forms::MaskedTextBox^  pressureMaskedTextBox;
	private: System::Windows::Forms::MaskedTextBox^  cholesterolMaskedTextBox;
	private: System::Windows::Forms::ComboBox^  sugarComboBox;
	private: System::Windows::Forms::ComboBox^  ECGComboBox;
	private: System::Windows::Forms::MaskedTextBox^  heartRateMaskedTextBox;
	private: System::Windows::Forms::ComboBox^  anginaComboBox;
	private: System::Windows::Forms::MaskedTextBox^  STMaskedTextBox;
	private: System::Windows::Forms::ComboBox^  STComboBox;
	private: System::Windows::Forms::ComboBox^  heartVesselsComboBox;
	private: System::Windows::Forms::ComboBox^  thalassemiaComboBox;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Button^  calculiteButton;






	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::TextBox^  diagnoseTextBox;



	private: System::Windows::Forms::Label^  label17;










	public: 
		int patientDataSizeJ;

		workForm(Form1^ parent, int inSelectedResearch, string* inPatientName, float** inPatientData, int inPatientSizeI, int inPatientDataSizeJ)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			form1 = parent;
			selectedResearch = inSelectedResearch;
			patientName = inPatientName;
			patientData = inPatientData;
			patientSizeI = inPatientSizeI;
			patientDataSizeJ = inPatientDataSizeJ;

			//
			//попередньо заповнюємо поля вводу
			//

			String ^systemstring = gcnew String((patientName[selectedResearch]).c_str());
			researchMaskedTextBox->Text = systemstring;
			delete systemstring;


			for (int i = 0; i <= 99; i++)
			{
				ageComboBox->Items->Add("" + i);
			}
			ageComboBox->SelectedIndex = (int)patientData[selectedResearch][0];


			sexComboBox->Items->Add("Жінка");
			sexComboBox->Items->Add("Чоловік");
			sexComboBox->SelectedIndex = (int)patientData[selectedResearch][1];


			chestPainComboBox->Items->Add("Типова стенокардія");
			chestPainComboBox->Items->Add("Атипова стенокардія");
			chestPainComboBox->Items->Add("Не ангінальний біль");
			chestPainComboBox->Items->Add("Безсимптомно");
			chestPainComboBox->SelectedIndex = (int) patientData[selectedResearch][2] - 1;


			pressureMaskedTextBox->Text = "" + patientData[selectedResearch][3];


			cholesterolMaskedTextBox->Text = "" + patientData[selectedResearch][4];


			sugarComboBox->Items->Add("Більше 120 мг/дл");
			sugarComboBox->Items->Add("Менше 120 мг/дл");
			sugarComboBox->SelectedIndex = (int) patientData[selectedResearch][5];


			ECGComboBox->Items->Add("Норма");
			ECGComboBox->Items->Add("Наявність ST-T аномалії");
			ECGComboBox->Items->Add("Гіпертрофія лівого шлуночка");
			ECGComboBox->SelectedIndex = (int) patientData[selectedResearch][6];


			heartRateMaskedTextBox->Text = "" + patientData[selectedResearch][7];


			anginaComboBox->Items->Add("Присутня");
			anginaComboBox->Items->Add("Відсутня");
			anginaComboBox->SelectedIndex = (int) patientData[selectedResearch][8];


			STMaskedTextBox->Text = "" + patientData[selectedResearch][9];


			STComboBox->Items->Add("Визхідна");
			STComboBox->Items->Add("Плоска");
			STComboBox->Items->Add("Низхідна");
			STComboBox->SelectedIndex = (int) patientData[selectedResearch][10] - 1;

			
			heartVesselsComboBox->Items->Add("Не використовується");
			heartVesselsComboBox->Items->Add("0");
			heartVesselsComboBox->Items->Add("1");
			heartVesselsComboBox->Items->Add("2");
			heartVesselsComboBox->Items->Add("3");
			heartVesselsComboBox->SelectedIndex = (int) patientData[selectedResearch][11] + 1;


			thalassemiaComboBox->Items->Add("Норма");
			thalassemiaComboBox->Items->Add("Фіксований дефект");
			thalassemiaComboBox->Items->Add("Оборотний дефект");
			switch((int) patientData[selectedResearch][12]) {
				case 3: {
							thalassemiaComboBox->SelectedIndex = 0;
							break;
						}
				case 6: {
							thalassemiaComboBox->SelectedIndex = 1;
							break;
						}
				case 7: {
							thalassemiaComboBox->SelectedIndex = 2;
							break;
						}
			}

		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~workForm()
		{
			if (components)
			{
				delete components;
			}
			form1->close();
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MaskedTextBox^  researchMaskedTextBox;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->researchMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->ageComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->sexComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->chestPainComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->pressureMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->cholesterolMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->sugarComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ECGComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->heartRateMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->anginaComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->STMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->STComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->heartVesselsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->thalassemiaComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->calculiteButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->diagnoseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Дослідження:";
			this->label1->Click += gcnew System::EventHandler(this, &workForm::label1_Click);
			// 
			// researchMaskedTextBox
			// 
			this->researchMaskedTextBox->Location = System::Drawing::Point(96, 10);
			this->researchMaskedTextBox->Name = L"researchMaskedTextBox";
			this->researchMaskedTextBox->Size = System::Drawing::Size(335, 20);
			this->researchMaskedTextBox->TabIndex = 1;
			this->researchMaskedTextBox->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &workForm::maskedTextBox1_MaskInputRejected);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Вік пацієнта:";
			this->label2->Click += gcnew System::EventHandler(this, &workForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Стать пацієнта:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Тип болю у грудях:";
			this->label4->Click += gcnew System::EventHandler(this, &workForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(233, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Систолічний тиск у стані спокою (мм рт. ст.):";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 129);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(233, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Вміст холестерину в сироватці крові (мг/дл):";
			this->label6->Click += gcnew System::EventHandler(this, &workForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 155);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(177, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Натщесерце рівень цукру у крові:";
			this->label7->Click += gcnew System::EventHandler(this, &workForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 181);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(168, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Результат електрокардіографії:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 208);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(229, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Максимальна частота серцевих скорочень:";
			this->label9->Click += gcnew System::EventHandler(this, &workForm::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 228);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(176, 13);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Стенокардія викликана фізичним";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 266);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(210, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Різниця рівнів піку ST сегменту в період";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 310);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(231, 13);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Форма ST сегменту під час фізичних вправ:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(12, 334);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(165, 13);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Кількість великих судин серця:";
			this->label13->Click += gcnew System::EventHandler(this, &workForm::label13_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(12, 360);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(142, 13);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Результат велоергометрії:";
			this->label14->Click += gcnew System::EventHandler(this, &workForm::label14_Click);
			// 
			// ageComboBox
			// 
			this->ageComboBox->FormattingEnabled = true;
			this->ageComboBox->Location = System::Drawing::Point(265, 32);
			this->ageComboBox->Name = L"ageComboBox";
			this->ageComboBox->Size = System::Drawing::Size(166, 21);
			this->ageComboBox->TabIndex = 15;
			// 
			// sexComboBox
			// 
			this->sexComboBox->FormattingEnabled = true;
			this->sexComboBox->Location = System::Drawing::Point(265, 55);
			this->sexComboBox->Name = L"sexComboBox";
			this->sexComboBox->Size = System::Drawing::Size(166, 21);
			this->sexComboBox->TabIndex = 15;
			// 
			// chestPainComboBox
			// 
			this->chestPainComboBox->FormattingEnabled = true;
			this->chestPainComboBox->Location = System::Drawing::Point(265, 78);
			this->chestPainComboBox->Name = L"chestPainComboBox";
			this->chestPainComboBox->Size = System::Drawing::Size(166, 21);
			this->chestPainComboBox->TabIndex = 15;
			// 
			// pressureMaskedTextBox
			// 
			this->pressureMaskedTextBox->Location = System::Drawing::Point(265, 100);
			this->pressureMaskedTextBox->Name = L"pressureMaskedTextBox";
			this->pressureMaskedTextBox->Size = System::Drawing::Size(166, 20);
			this->pressureMaskedTextBox->TabIndex = 16;
			// 
			// cholesterolMaskedTextBox
			// 
			this->cholesterolMaskedTextBox->Location = System::Drawing::Point(265, 126);
			this->cholesterolMaskedTextBox->Name = L"cholesterolMaskedTextBox";
			this->cholesterolMaskedTextBox->Size = System::Drawing::Size(166, 20);
			this->cholesterolMaskedTextBox->TabIndex = 16;
			this->cholesterolMaskedTextBox->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &workForm::cholesterolMaskedTextBox_MaskInputRejected);
			// 
			// sugarComboBox
			// 
			this->sugarComboBox->FormattingEnabled = true;
			this->sugarComboBox->Location = System::Drawing::Point(265, 152);
			this->sugarComboBox->Name = L"sugarComboBox";
			this->sugarComboBox->Size = System::Drawing::Size(166, 21);
			this->sugarComboBox->TabIndex = 15;
			// 
			// ECGComboBox
			// 
			this->ECGComboBox->FormattingEnabled = true;
			this->ECGComboBox->Location = System::Drawing::Point(265, 178);
			this->ECGComboBox->Name = L"ECGComboBox";
			this->ECGComboBox->Size = System::Drawing::Size(166, 21);
			this->ECGComboBox->TabIndex = 15;
			// 
			// heartRateMaskedTextBox
			// 
			this->heartRateMaskedTextBox->Location = System::Drawing::Point(265, 205);
			this->heartRateMaskedTextBox->Name = L"heartRateMaskedTextBox";
			this->heartRateMaskedTextBox->Size = System::Drawing::Size(166, 20);
			this->heartRateMaskedTextBox->TabIndex = 16;
			this->heartRateMaskedTextBox->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &workForm::cholesterolMaskedTextBox_MaskInputRejected);
			// 
			// anginaComboBox
			// 
			this->anginaComboBox->FormattingEnabled = true;
			this->anginaComboBox->Location = System::Drawing::Point(265, 234);
			this->anginaComboBox->Name = L"anginaComboBox";
			this->anginaComboBox->Size = System::Drawing::Size(166, 21);
			this->anginaComboBox->TabIndex = 15;
			// 
			// STMaskedTextBox
			// 
			this->STMaskedTextBox->Location = System::Drawing::Point(265, 272);
			this->STMaskedTextBox->Name = L"STMaskedTextBox";
			this->STMaskedTextBox->Size = System::Drawing::Size(166, 20);
			this->STMaskedTextBox->TabIndex = 16;
			this->STMaskedTextBox->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &workForm::cholesterolMaskedTextBox_MaskInputRejected);
			// 
			// STComboBox
			// 
			this->STComboBox->FormattingEnabled = true;
			this->STComboBox->Location = System::Drawing::Point(265, 307);
			this->STComboBox->Name = L"STComboBox";
			this->STComboBox->Size = System::Drawing::Size(166, 21);
			this->STComboBox->TabIndex = 15;
			// 
			// heartVesselsComboBox
			// 
			this->heartVesselsComboBox->FormattingEnabled = true;
			this->heartVesselsComboBox->Location = System::Drawing::Point(265, 331);
			this->heartVesselsComboBox->Name = L"heartVesselsComboBox";
			this->heartVesselsComboBox->Size = System::Drawing::Size(166, 21);
			this->heartVesselsComboBox->TabIndex = 15;
			// 
			// thalassemiaComboBox
			// 
			this->thalassemiaComboBox->FormattingEnabled = true;
			this->thalassemiaComboBox->Location = System::Drawing::Point(265, 357);
			this->thalassemiaComboBox->Name = L"thalassemiaComboBox";
			this->thalassemiaComboBox->Size = System::Drawing::Size(166, 21);
			this->thalassemiaComboBox->TabIndex = 15;
			this->thalassemiaComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &workForm::thalassemiaComboBox_SelectedIndexChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(13, 285);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(195, 13);
			this->label15->TabIndex = 17;
			this->label15->Text = L"фізичного навантаження та в спокої:";
			// 
			// calculiteButton
			// 
			this->calculiteButton->Location = System::Drawing::Point(205, 391);
			this->calculiteButton->Name = L"calculiteButton";
			this->calculiteButton->Size = System::Drawing::Size(226, 23);
			this->calculiteButton->TabIndex = 18;
			this->calculiteButton->Text = L"Визначити рівень звуження судин серця";
			this->calculiteButton->UseVisualStyleBackColor = true;
			this->calculiteButton->Click += gcnew System::EventHandler(this, &workForm::button1_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(356, 420);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 23;
			this->SaveButton->Text = L"Зберегти";
			this->SaveButton->UseVisualStyleBackColor = true;
			// 
			// diagnoseTextBox
			// 
			this->diagnoseTextBox->Location = System::Drawing::Point(15, 391);
			this->diagnoseTextBox->Multiline = true;
			this->diagnoseTextBox->Name = L"diagnoseTextBox";
			this->diagnoseTextBox->Size = System::Drawing::Size(184, 52);
			this->diagnoseTextBox->TabIndex = 24;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 242);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(91, 13);
			this->label17->TabIndex = 28;
			this->label17->Text = L"навантаженням:";
			this->label17->Click += gcnew System::EventHandler(this, &workForm::label17_Click);
			// 
			// workForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(443, 450);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->diagnoseTextBox);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->calculiteButton);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->STMaskedTextBox);
			this->Controls->Add(this->heartRateMaskedTextBox);
			this->Controls->Add(this->cholesterolMaskedTextBox);
			this->Controls->Add(this->pressureMaskedTextBox);
			this->Controls->Add(this->thalassemiaComboBox);
			this->Controls->Add(this->heartVesselsComboBox);
			this->Controls->Add(this->STComboBox);
			this->Controls->Add(this->anginaComboBox);
			this->Controls->Add(this->ECGComboBox);
			this->Controls->Add(this->sugarComboBox);
			this->Controls->Add(this->chestPainComboBox);
			this->Controls->Add(this->sexComboBox);
			this->Controls->Add(this->ageComboBox);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->researchMaskedTextBox);
			this->Controls->Add(this->label1);
			this->Name = L"workForm";
			this->Text = L"DSHV1 © Швець Юрій";
			this->Load += gcnew System::EventHandler(this, &workForm::workForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void workForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
			 }
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cholesterolMaskedTextBox_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void thalassemiaComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label14_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 fann_type input[26];
			 fann_type input2[22];	//ввод для нейронної мережі без кількості судин
				fann_type *calc_out;
				struct fann *ann = fann_create_from_file("float.net");
				struct fann *ann2 = fann_create_from_file("float2.net");	//нейронна мережа без кількості судин


				// создание нейронной сети с именем ann
				//struct fann *ann = fann_create_standard(num_layers, num_input,
				//    num_neurons_hidden, num_output);

				fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
				fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);


				//задание значений входным нейронам
				input[0] = ((float)ageComboBox->SelectedIndex - 29.0) / (77.0 - 29.0);	//вік

				if(sexComboBox->SelectedIndex) {
					input[1] = 0;	//стать
					input[2] = 1;	//
				}
				else {
					input[1] = 1;	//стать
					input[2] = 0;
				}

				switch(chestPainComboBox->SelectedIndex) {
				case 0: {
							input[3] = 1;	//
							input[4] = 0;	//
							input[5] = 0;	//тип грудного болю
							input[6] = 0;
							break;
						}
				case 1: {
							input[3] = 0;	//
							input[4] = 1;	//
							input[5] = 0;	//тип грудного болю
							input[6] = 0;
							break;
						}
				case 2: {
							input[3] = 0;	//
							input[4] = 0;	//
							input[5] = 1;	//тип грудного болю
							input[6] = 0;
							break;
						}
				case 3: {
							input[3] = 0;	//
							input[4] = 0;	//
							input[5] = 0;	//тип грудного болю
							input[6] = 1;
							break;
						}
				}

				input[7] = (Convert::ToDouble(pressureMaskedTextBox->Text) - 94.0) / (200.0 - 94.0);	//тиск крові
				
				input[8] = (Convert::ToDouble(cholesterolMaskedTextBox->Text) - 126.0) / (564.0 - 126.0);	//вміст холестерину

				input[9] = sugarComboBox->SelectedIndex;	//рівень цукру
				
				switch(ECGComboBox->SelectedIndex) {

				case 0: {
							input[10] = 1;	//
							input[11] = 0;	//результати електрокардіографії
							input[12] = 0;	//
							break;
						}
				case 1: {
							input[10] = 0;	//
							input[11] = 1;	//результати електрокардіографії
							input[12] = 0;	//
							break;
						}
				case 2: {
							input[10] = 0;	//
							input[11] = 0;	//результати електрокардіографії
							input[12] = 1;	//
							break;
						}
				}

				input[13] = (Convert::ToDouble(heartRateMaskedTextBox->Text) - 71.0) / (202.0 - 71.0);	//максимальний серцевий ритм
				
				input[14] = anginaComboBox->SelectedIndex;	//стенокардія

				input[15] = (Convert::ToDouble(STMaskedTextBox->Text) - 0.0) / (6.2 - 0.0);	//депресія зубця ст

				switch(STComboBox->SelectedIndex) {
					case 0: {
								input[16] = 1;	//
								input[17] = 0;	//нахил піку зубця ст
								input[18] = 0;	//
								break;
							}
					case 1: {
								input[16] = 0;	//
								input[17] = 1;	//нахил піку зубця ст
								input[18] = 0;	//
								break;
							}
					case 2: {
								input[16] = 0;	//
								input[17] = 0;	//нахил піку зубця ст
								input[18] = 1;	//
								break;
							}
				}

				switch(heartVesselsComboBox->SelectedIndex) {
					case 1: {
								input[19] = 1;	//
								input[20] = 0;	//кількість великих судин
								input[21] = 0;	//
								input[22] = 0;	//
								break;
							}
					case 2: {
								input[19] = 0;	//
								input[20] = 1;	//кількість великих судин
								input[21] = 0;	//
								input[22] = 0;	//
								break;
							}
					case 3: {
								input[19] = 0;	//
								input[20] = 0;	//кількість великих судин
								input[21] = 1;	//
								input[22] = 0;	//
								break;
							}
					case 4: {
								input[19] = 0;	//
								input[20] = 0;	//кількість великих судин
								input[21] = 0;	//
								input[22] = 1;	//
								break;
							}
				}

				switch(thalassemiaComboBox->SelectedIndex) {
					case 0: {
								input[23] = 1;	//
								input[24] = 0;	//талассемія
								input[25] = 0;	//
								break;
							}
					case 1: {
								input[23] = 0;	//
								input[24] = 1;	//талассемія
								input[25] = 0;	//
								break;
							}
					case 2: {
								input[23] = 0;	//
								input[24] = 0;	//талассемія
								input[25] = 1;	//
								break;
							}
				}
				if(heartVesselsComboBox->SelectedIndex != 0)	//якщо використовується кількість судин
					calc_out = fann_run(ann, input);
				else {
					for(int i = 0; i < 22; i++) {
						if(i < 19)
							input2[i] = input[i];
						else
							input2[i] = input[i + 4];
					}
					calc_out = fann_run(ann2, input2);
				}

				//вывод результатов c выходного нейрона
				//printf("test (%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f) -> %f\n", input[0], input[1], input[2], input[3], input[4], input[5], input[6], input[7], input[8], input[9], input[10], input[11], input[12], calc_out[0]);

				//сохранение обученной сети в файл


				 
				 if(calc_out[0] > calc_out[1]){
					 diagnoseTextBox->Text = "Рівень звуження діаметру судин серця: < 50 %.";
				 }

				 if(calc_out[1] > calc_out[0]){
					 diagnoseTextBox->Text = "Рівень звуження діаметру судин серця: > 50 %.";
				 }

		 }

private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label16_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label17_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
