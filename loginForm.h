#pragma once

namespace Program {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для loginForm
	/// </summary>
	public ref class loginForm : public System::Windows::Forms::Form
	{
	public:
		loginForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void close(); //закрити форму
		void startForm1();
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~loginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  loginTextBox;
	private: System::Windows::Forms::TextBox^  passwordTextBox;
	private: System::Windows::Forms::Button^  enterButton;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->enterButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Логін";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Пароль";
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(53, 6);
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(134, 20);
			this->loginTextBox->TabIndex = 2;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(53, 29);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(134, 20);
			this->passwordTextBox->TabIndex = 3;
			// 
			// enterButton
			// 
			this->enterButton->Location = System::Drawing::Point(64, 55);
			this->enterButton->Name = L"enterButton";
			this->enterButton->Size = System::Drawing::Size(75, 23);
			this->enterButton->TabIndex = 4;
			this->enterButton->Text = L"Увійти";
			this->enterButton->UseVisualStyleBackColor = true;
			this->enterButton->Click += gcnew System::EventHandler(this, &loginForm::enterButton_Click);
			// 
			// loginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(199, 88);
			this->Controls->Add(this->enterButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->loginTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"loginForm";
			this->Text = L"Авторизація";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(loginTextBox->Text == "admin" && passwordTextBox->Text == "admin") {
					startForm1();
				 }
				 else {
					 loginTextBox->Text = ""; 
					 passwordTextBox->Text = "";
				 }
			 }
};
}
