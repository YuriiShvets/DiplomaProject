// Program.cpp: ������� ���� �������.

#include "stdafx.h"
#include "loginForm.h"

using namespace Program;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew loginForm());
	return 0;
}
