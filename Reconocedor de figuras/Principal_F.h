#pragma once
#include "Red_Neuronal.h"
#include <string>
namespace Reconocedordefiguras {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	Red_Neuronal *red;
	/// <summary>
	/// Resumen de Principal_F
	/// </summary>
	public ref class Principal_F : public System::Windows::Forms::Form
	{
	public:
		
		Principal_F(void)
		{
			InitializeComponent();
			red = new Red_Neuronal();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Principal_F()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBoxclass;

	private: System::Windows::Forms::RadioButton^  radioButtonT;

	private: System::Windows::Forms::RadioButton^  radioButtonC;
	private: System::Windows::Forms::Label^  labelR;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBoxclass = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonT = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonC = (gcnew System::Windows::Forms::RadioButton());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->groupBoxclass->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(392, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Abrir";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Principal_F::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 69);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Entrenar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Principal_F::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(174, 69);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Predecir";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Principal_F::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Multiselect = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 69);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Añadir Data";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Principal_F::button4_Click);
			// 
			// groupBoxclass
			// 
			this->groupBoxclass->Controls->Add(this->radioButtonT);
			this->groupBoxclass->Controls->Add(this->radioButtonC);
			this->groupBoxclass->Location = System::Drawing::Point(12, 98);
			this->groupBoxclass->Name = L"groupBoxclass";
			this->groupBoxclass->Size = System::Drawing::Size(99, 74);
			this->groupBoxclass->TabIndex = 5;
			this->groupBoxclass->TabStop = false;
			this->groupBoxclass->Text = L"tipo";
			// 
			// radioButtonT
			// 
			this->radioButtonT->AutoSize = true;
			this->radioButtonT->Location = System::Drawing::Point(7, 44);
			this->radioButtonT->Name = L"radioButtonT";
			this->radioButtonT->Size = System::Drawing::Size(69, 17);
			this->radioButtonT->TabIndex = 1;
			this->radioButtonT->Text = L"Triangulo";
			this->radioButtonT->UseVisualStyleBackColor = true;
			// 
			// radioButtonC
			// 
			this->radioButtonC->AutoSize = true;
			this->radioButtonC->Checked = true;
			this->radioButtonC->Location = System::Drawing::Point(7, 20);
			this->radioButtonC->Name = L"radioButtonC";
			this->radioButtonC->Size = System::Drawing::Size(71, 17);
			this->radioButtonC->TabIndex = 0;
			this->radioButtonC->TabStop = true;
			this->radioButtonC->Text = L"Cuadrado";
			this->radioButtonC->UseVisualStyleBackColor = true;
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(354, 150);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(50, 13);
			this->labelR->TabIndex = 6;
			this->labelR->Text = L"resultado";
			// 
			// Principal_F
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 172);
			this->Controls->Add(this->labelR);
			this->Controls->Add(this->groupBoxclass);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Principal_F";
			this->Text = L"Principal_F";
			this->groupBoxclass->ResumeLayout(false);
			this->groupBoxclass->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		folderBrowserDialog1->ShowDialog();
		textBox1->Text = folderBrowserDialog1->SelectedPath;
		//red.cargar_data();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		red->entrenar();
		labelR->Text = L"Entrenamiento finalizado";
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//red.predecir();
	openFileDialog1->ShowDialog();

	String^ archivo = openFileDialog1->FileName;
	using namespace Runtime::InteropServices;
	const char * chars = (const char*)(Marshal::StringToHGlobalAnsi(archivo)).ToPointer();
	if (red->predecir(chars))
		labelR->Text = L"Cuadrado";
	else
		labelR->Text = L"Triangulo";
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->ShowDialog();
	
	String^ archivo= openFileDialog1->FileName;
	using namespace Runtime::InteropServices;
	const char * chars;
	
	

	for each (auto archivo in openFileDialog1->FileNames)
	{
		chars = (const char*)(Marshal::StringToHGlobalAnsi(archivo)).ToPointer();
		if (radioButtonC->Checked)
			red->cargar_data(chars, true);
		else
			red->cargar_data(chars, false);
	}
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	labelR->Text = L"datos cargados";
	}
};
}
