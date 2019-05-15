#pragma once
#include <fstream>

#include <locale>
namespace app2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	using namespace std;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{	
		int  n;
		int d, e1;
	
		int *CryptoText;
	    int *Tdecrypt;
		String ^text;
		String ^textToFile2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;


			
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"загрузить файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(12, 90);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 38);
			this->button3->TabIndex = 3;
			this->button3->Text = L"зашифровать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(12, 150);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(126, 40);
			this->button4->TabIndex = 4;
			this->button4->Text = L"расшифровать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(309, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(415, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 6;
			
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(329, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Ввод секретного ключа";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(329, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"d";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(429, 42);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 17);
			this->label3->TabIndex = 9;
			this->label3->Text = L"n";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 337);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		prepare();
		
		openFileDialog1->Filter = "All files |*.txt";
		
		if (System::Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog())
		{
			text = File::ReadAllText(openFileDialog1->FileName);
			CryptoText = new  int[text->Length];
			Tdecrypt = new  int[text->Length];
			

			button3->Enabled = true;
			button4->Enabled = true;
		}
		
	}


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	
	StreamWriter ^sw = gcnew StreamWriter(openFileDialog1->FileName, false);
	int textToFile;
	int b = 301;
	
	for (int j = 0; j < text->Length; j++)
	{
		int c = 1;
		unsigned int i = 0;
		int ASCIIcode = (static_cast<int>(text[j])) + b;
		while (i<e1)
		{
			c = c*ASCIIcode;
			c = c%n;
			i++;
		}
		CryptoText[j] = c;
		textToFile = CryptoText[j];
		
		//textBox1->AppendText(Convert::ToString(static_cast<int>(text[j]))); ASCII
		sw->WriteLine(Convert::ToString(textToFile));
		b += 1;
	}
	
	String ^showKey = "секретный ключ :{"+ Convert::ToString(d)+","+ Convert::ToString(n)+"}";
	MessageBox::Show(showKey);
	sw->Close();

	
	
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	int d2 = Convert::ToInt32(textBox1->Text);
	int n2 = Convert::ToInt32(textBox2->Text);
	
	StreamReader ^sr = gcnew StreamReader(openFileDialog1->FileName);
	int z = 0;
	while (sr->ReadLine()) {
		z++;
	}
	sr->BaseStream->Position = 0;
	
	int *decrypt = new  int[z];
	for (int i = 0;i < z;i++) {
		decrypt[i] = Convert::ToInt16(sr->ReadLine());
		
	}
	sr->Close();
	StreamWriter ^sw = gcnew StreamWriter(openFileDialog1->FileName, false);
	int b = 301;
	int m;
	for (int j = 0; j < z; j++)
	{
		m = 1;
		unsigned int i = 0;
		while (i<d2)
		{
			m = m*decrypt[j];
			m = m%n2;
			i++;
		}
		m = m - b;
		Tdecrypt[j] = m;
		textToFile2 += Convert::ToChar(Tdecrypt[j]);

		b += 1;

	}

	
	sw->Write(textToFile2);

	sw->Close();
	textToFile2 = "";
	button3->Enabled = false;
	button4->Enabled = false;
	delete[] Tdecrypt;
	delete[] CryptoText;
	delete[] Text;
}
//Алгоритм "решето Сундарама". Выбирает все простые числа
//до заданного (случайно сгенерированного).
int genSimpleNumber(int n)
{
	int *a = new int[n], i, j, k;
	memset(a, 0, sizeof(int) * n);
	for (i = 1; 3 * i + 1 < n; i++)
	{
		for (j = 1; (k = i + j + 2 * i*j) < n && j <= i; j++)
			a[k] = 1;
	}
	//Выбирает из списка простых чисел ближайшее к заданному.
	for (i = n - 1; i >= 1; i--)
		if (a[i] == 0)
		{
			return (2 * i + 1);
			break;
		}
	delete[] a;
}
/////////////////////////////////////////////////////////////////////
//Алгоритм Евклида. Алгоритм для нахождения наибольшего
//общего делителя двух целых чисел. Используется для проверки
//чисел на взаимопростоту.
int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}
/////////////////////////////////////////////////////////////////////
public : void  prepare() {
	srand((unsigned)time(NULL));
	
	// Генерация двух чисел и выбор двух простых чисел.
	int p = rand() % 50+1;
	int q = rand() % 50+1;
	
	int p_simple = genSimpleNumber(p);
	int q_simple = genSimpleNumber(q);
	//Находим число n.
	 n = p_simple*q_simple;
	//Генерация числа d и проверка его на взаимопростоту
	//с числом ((p_simple-1)*(q_simple-1)).
	int  d_simple = 0;
	while (d_simple != 1)
	{
		d = rand() % 100;
		d_simple = gcd(d, ((p_simple - 1)*(q_simple - 1)));
	}
	//Определение числа e, для которого является истинным
	//соотношение (e*d)%((p_simple-1)*(q_simple-1))=1.
	unsigned int e_simple = 0;
	while (e_simple != 1)
	{
		e1 += 1;
		e_simple = (e1*d) % ((p_simple - 1)*(q_simple - 1));
	}
}
};

	
}
