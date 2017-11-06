//для зв'язку між формами

#include "StdAfx.h"
#include "workForm.h"
#include "Form1.h"
#include "loginForm.h"

namespace Program {

	System::Void Form1::startWorkForm(int inSelectedResearch, string* inPatientName, float** inPatientData, int inPatientSizeI, int inPatientDataSizeJ) {
		workForm^ form2 = gcnew workForm(this, inSelectedResearch, inPatientName, inPatientData, inPatientSizeI, inPatientDataSizeJ);
		form2->Show();
		this->Hide();
	}

	System::Void Form1::close() {
		this->Show();
	}

	System::Void loginForm::close() {
		this->Close();
	}

	System::Void loginForm::startForm1() {
		Form1^ form2 = gcnew Form1(this);
		form2->Show();
		this->Hide();
	}
}