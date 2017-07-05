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

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  buttonTrain;
	private: System::Windows::Forms::Button^  buttonClassif;


	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  buttonAdd;

	private: System::Windows::Forms::GroupBox^  groupBoxclass;

	private: System::Windows::Forms::RadioButton^  radioButtonT;

	private: System::Windows::Forms::RadioButton^  radioButtonC;
	private: System::Windows::Forms::Label^  labelR;
	private: System::Windows::Forms::RadioButton^  radioButtonCI;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonTrain = (gcnew System::Windows::Forms::Button());
			this->buttonClassif = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->groupBoxclass = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonCI = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonT = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonC = (gcnew System::Windows::Forms::RadioButton());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->groupBoxclass->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Abrir Imagen";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Principal_F::button1_Click);
			// 
			// buttonTrain
			// 
			this->buttonTrain->Location = System::Drawing::Point(93, 69);
			this->buttonTrain->Name = L"buttonTrain";
			this->buttonTrain->Size = System::Drawing::Size(75, 23);
			this->buttonTrain->TabIndex = 2;
			this->buttonTrain->Text = L"Entrenar";
			this->buttonTrain->UseVisualStyleBackColor = true;
			this->buttonTrain->Click += gcnew System::EventHandler(this, &Principal_F::button2_Click);
			// 
			// buttonClassif
			// 
			this->buttonClassif->Location = System::Drawing::Point(174, 69);
			this->buttonClassif->Name = L"buttonClassif";
			this->buttonClassif->Size = System::Drawing::Size(75, 23);
			this->buttonClassif->TabIndex = 3;
			this->buttonClassif->Text = L"Clasificar";
			this->buttonClassif->UseVisualStyleBackColor = true;
			this->buttonClassif->Click += gcnew System::EventHandler(this, &Principal_F::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Multiselect = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(12, 69);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 4;
			this->buttonAdd->Text = L"Añadir Data";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Principal_F::button4_Click);
			// 
			// groupBoxclass
			// 
			this->groupBoxclass->Controls->Add(this->radioButtonCI);
			this->groupBoxclass->Controls->Add(this->radioButtonT);
			this->groupBoxclass->Controls->Add(this->radioButtonC);
			this->groupBoxclass->Location = System::Drawing::Point(12, 98);
			this->groupBoxclass->Name = L"groupBoxclass";
			this->groupBoxclass->Size = System::Drawing::Size(99, 93);
			this->groupBoxclass->TabIndex = 5;
			this->groupBoxclass->TabStop = false;
			this->groupBoxclass->Text = L"tipo";
			// 
			// radioButtonCI
			// 
			this->radioButtonCI->AutoSize = true;
			this->radioButtonCI->Location = System::Drawing::Point(7, 68);
			this->radioButtonCI->Name = L"radioButtonCI";
			this->radioButtonCI->Size = System::Drawing::Size(57, 17);
			this->radioButtonCI->TabIndex = 2;
			this->radioButtonCI->Text = L"Circulo";
			this->radioButtonCI->UseVisualStyleBackColor = true;
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
			this->labelR->Font = (gcnew System::Drawing::Font(L"MS PGothic", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelR->Location = System::Drawing::Point(118, 118);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(75, 19);
			this->labelR->TabIndex = 6;
			this->labelR->Text = L"Mensaje";
			// 
			// Principal_F
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(358, 202);
			this->Controls->Add(this->labelR);
			this->Controls->Add(this->groupBoxclass);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->buttonClassif);
			this->Controls->Add(this->buttonTrain);
			this->Controls->Add(this->button1);
			this->Name = L"Principal_F";
			this->Text = L"Principal_F";
			this->groupBoxclass->ResumeLayout(false);
			this->groupBoxclass->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();

		String^ archivo = openFileDialog1->FileName;
		using namespace Runtime::InteropServices;
		const char * chars = (const char*)(Marshal::StringToHGlobalAnsi(archivo)).ToPointer();
		red->mostrar(chars);
		//red.cargar_data();
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		labelR->Text = L"Entrenando...";
		red->entrenar();
		labelR->Text = L"Entrenamiento finalizado";
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//red.predecir();
	openFileDialog1->ShowDialog();

	String^ archivo = openFileDialog1->FileName;
	using namespace Runtime::InteropServices;
	const char * chars = (const char*)(Marshal::StringToHGlobalAnsi(archivo)).ToPointer();
	int r = red->predecir(chars);
	if (r == 0)
		labelR->Text = L"Cuadrado";
	else if (r == 1)
		labelR->Text = L"Triangulo";
	else
		labelR->Text = L"Circulo";
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	
	openFileDialog1->ShowDialog();
	labelR->Text = L"cargando...";
	String^ archivo= openFileDialog1->FileName;
	using namespace Runtime::InteropServices;
	const char * chars;
	
	

	for each (auto archivo in openFileDialog1->FileNames)
	{
		chars = (const char*)(Marshal::StringToHGlobalAnsi(archivo)).ToPointer();
		if (radioButtonC->Checked)
			red->cargar_data(chars, 0);
		else if (radioButtonT->Checked)
			red->cargar_data(chars, 1);
		else
			red->cargar_data(chars, 2);
	}
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	labelR->Text = L"datos cargados";
	}
};
}
