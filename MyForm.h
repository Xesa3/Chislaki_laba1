#pragma once
#include <math.h>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include "TestTask.h"
#include "MainTask1.h"

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  I;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  F_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  F_2;
	private: System::Windows::Forms::Label^ label_x_min;
	private: System::Windows::Forms::TextBox^ textBox_x_min;
	private: System::Windows::Forms::Label^ label_u0;
	private: System::Windows::Forms::TextBox^ textBox_u0;
	private: System::Windows::Forms::Label^ label_h;
	private: System::Windows::Forms::TextBox^ textBox_h;






	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^ textBox_u_shtrix_0;

	private: System::Windows::Forms::Label^ label_u_shtrix_0;

	private: System::Windows::Forms::TextBox^ textBox_x_max;

	private: System::Windows::Forms::Label^ label_x_max;
	private: System::Windows::Forms::TextBox^ textBox_alpha;
	private: System::Windows::Forms::Label^ label_alpha;
	private: System::Windows::Forms::TextBox^ textBox_betta;
	private: System::Windows::Forms::Label^ label_betta;
	private: System::Windows::Forms::TextBox^ textBox__max_h;
	private: System::Windows::Forms::Label^ label_max_h;
	private: System::Windows::Forms::TextBox^ textBox__granica;
	private: System::Windows::Forms::Label^ label_granica;
	private: System::Windows::Forms::TextBox^ textBox__loc_pogr;
	private: System::Windows::Forms::Label^ label_loc_pogr;









	private: System::Windows::Forms::CheckBox^ checkBox_LP;
	private: System::Windows::Forms::Label^ label_info;
	private: System::Windows::Forms::ComboBox^ comboBox_Zadachi;
	private: System::Windows::Forms::Label^ label_Info_zada;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Step;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V2_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vi_V2i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OLP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ C2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ui;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ui_Vi;





	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Step = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V2_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vi_V2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OLP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ui = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Ui_Vi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label_x_min = (gcnew System::Windows::Forms::Label());
			this->textBox_x_min = (gcnew System::Windows::Forms::TextBox());
			this->label_u0 = (gcnew System::Windows::Forms::Label());
			this->textBox_u0 = (gcnew System::Windows::Forms::TextBox());
			this->label_h = (gcnew System::Windows::Forms::Label());
			this->textBox_h = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox_u_shtrix_0 = (gcnew System::Windows::Forms::TextBox());
			this->label_u_shtrix_0 = (gcnew System::Windows::Forms::Label());
			this->textBox_x_max = (gcnew System::Windows::Forms::TextBox());
			this->label_x_max = (gcnew System::Windows::Forms::Label());
			this->textBox_alpha = (gcnew System::Windows::Forms::TextBox());
			this->label_alpha = (gcnew System::Windows::Forms::Label());
			this->textBox_betta = (gcnew System::Windows::Forms::TextBox());
			this->label_betta = (gcnew System::Windows::Forms::Label());
			this->textBox__max_h = (gcnew System::Windows::Forms::TextBox());
			this->label_max_h = (gcnew System::Windows::Forms::Label());
			this->textBox__granica = (gcnew System::Windows::Forms::TextBox());
			this->label_granica = (gcnew System::Windows::Forms::Label());
			this->textBox__loc_pogr = (gcnew System::Windows::Forms::TextBox());
			this->label_loc_pogr = (gcnew System::Windows::Forms::Label());
			this->checkBox_LP = (gcnew System::Windows::Forms::CheckBox());
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->comboBox_Zadachi = (gcnew System::Windows::Forms::ComboBox());
			this->label_Info_zada = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(274, 30);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(501, 327);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(633, 386);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->Step, this->X_i,
					this->V_i, this->V2_i, this->Vi_V2i, this->OLP, this->Hi, this->C1, this->C2, this->Ui, this->Ui_Vi
			});
			this->dataGridView1->Location = System::Drawing::Point(828, 30);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(399, 327);
			this->dataGridView1->TabIndex = 2;
			// 
			// Step
			// 
			this->Step->HeaderText = L"i";
			this->Step->Name = L"Step";
			// 
			// X_i
			// 
			this->X_i->HeaderText = L"X_i";
			this->X_i->Name = L"X_i";
			this->X_i->ReadOnly = true;
			// 
			// V_i
			// 
			this->V_i->HeaderText = L"V_i";
			this->V_i->Name = L"V_i";
			this->V_i->ReadOnly = true;
			// 
			// V2_i
			// 
			this->V2_i->HeaderText = L"V2_i";
			this->V2_i->Name = L"V2_i";
			// 
			// Vi_V2i
			// 
			this->Vi_V2i->HeaderText = L"V_i-V2_i";
			this->Vi_V2i->Name = L"Vi_V2i";
			this->Vi_V2i->ReadOnly = true;
			// 
			// OLP
			// 
			this->OLP->HeaderText = L"ОЛП";
			this->OLP->Name = L"OLP";
			this->OLP->ReadOnly = true;
			// 
			// Hi
			// 
			this->Hi->HeaderText = L"h_i";
			this->Hi->Name = L"Hi";
			// 
			// C1
			// 
			this->C1->HeaderText = L"C1";
			this->C1->Name = L"C1";
			this->C1->ReadOnly = true;
			// 
			// C2
			// 
			this->C2->HeaderText = L"C2";
			this->C2->Name = L"C2";
			this->C2->ReadOnly = true;
			// 
			// Ui
			// 
			this->Ui->HeaderText = L"ui";
			this->Ui->Name = L"Ui";
			// 
			// Ui_Vi
			// 
			this->Ui_Vi->HeaderText = L"|ui-vi|";
			this->Ui_Vi->Name = L"Ui_Vi";
			// 
			// label_x_min
			// 
			this->label_x_min->AutoSize = true;
			this->label_x_min->Location = System::Drawing::Point(16, 374);
			this->label_x_min->Name = L"label_x_min";
			this->label_x_min->Size = System::Drawing::Size(34, 13);
			this->label_x_min->TabIndex = 3;
			this->label_x_min->Text = L"x_min";
			// 
			// textBox_x_min
			// 
			this->textBox_x_min->Location = System::Drawing::Point(56, 370);
			this->textBox_x_min->Name = L"textBox_x_min";
			this->textBox_x_min->Size = System::Drawing::Size(48, 20);
			this->textBox_x_min->TabIndex = 4;
			this->textBox_x_min->Text = L"0";
			// 
			// label_u0
			// 
			this->label_u0->AutoSize = true;
			this->label_u0->Location = System::Drawing::Point(16, 425);
			this->label_u0->Name = L"label_u0";
			this->label_u0->Size = System::Drawing::Size(19, 13);
			this->label_u0->TabIndex = 5;
			this->label_u0->Text = L"u0";
			// 
			// textBox_u0
			// 
			this->textBox_u0->Location = System::Drawing::Point(55, 422);
			this->textBox_u0->Name = L"textBox_u0";
			this->textBox_u0->Size = System::Drawing::Size(49, 20);
			this->textBox_u0->TabIndex = 6;
			this->textBox_u0->Text = L"7";
			
			// 
			// label_h
			// 
			this->label_h->AutoSize = true;
			this->label_h->Location = System::Drawing::Point(170, 373);
			this->label_h->Name = L"label_h";
			this->label_h->Size = System::Drawing::Size(13, 13);
			this->label_h->TabIndex = 7;
			this->label_h->Text = L"h";
			// 
			// textBox_h
			// 
			this->textBox_h->Location = System::Drawing::Point(191, 370);
			this->textBox_h->Name = L"textBox_h";
			this->textBox_h->Size = System::Drawing::Size(61, 20);
			this->textBox_h->TabIndex = 8;
			this->textBox_h->Text = L"0,01";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(633, 437);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 29);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Увеличить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox_u_shtrix_0
			// 
			this->textBox_u_shtrix_0->Location = System::Drawing::Point(55, 448);
			this->textBox_u_shtrix_0->Name = L"textBox_u_shtrix_0";
			this->textBox_u_shtrix_0->Size = System::Drawing::Size(49, 20);
			this->textBox_u_shtrix_0->TabIndex = 13;
			this->textBox_u_shtrix_0->Text = L"1";
			// 
			// label_u_shtrix_0
			// 
			this->label_u_shtrix_0->AutoSize = true;
			this->label_u_shtrix_0->Location = System::Drawing::Point(16, 451);
			this->label_u_shtrix_0->Name = L"label_u_shtrix_0";
			this->label_u_shtrix_0->Size = System::Drawing::Size(21, 13);
			this->label_u_shtrix_0->TabIndex = 12;
			this->label_u_shtrix_0->Text = L"u\'0";
			// 
			// textBox_x_max
			// 
			this->textBox_x_max->Location = System::Drawing::Point(56, 396);
			this->textBox_x_max->Name = L"textBox_x_max";
			this->textBox_x_max->Size = System::Drawing::Size(48, 20);
			this->textBox_x_max->TabIndex = 11;
			this->textBox_x_max->Text = L"1";

			// 
			// label_x_max
			// 
			this->label_x_max->AutoSize = true;
			this->label_x_max->Location = System::Drawing::Point(16, 397);
			this->label_x_max->Name = L"label_x_max";
			this->label_x_max->Size = System::Drawing::Size(37, 13);
			this->label_x_max->TabIndex = 10;
			this->label_x_max->Text = L"x_max";
			// 
			// textBox_alpha
			// 
			this->textBox_alpha->Location = System::Drawing::Point(191, 407);
			this->textBox_alpha->Name = L"textBox_alpha";
			this->textBox_alpha->Size = System::Drawing::Size(61, 20);
			this->textBox_alpha->TabIndex = 15;
			this->textBox_alpha->Text = L"0,1";
			// 
			// label_alpha
			// 
			this->label_alpha->AutoSize = true;
			this->label_alpha->Location = System::Drawing::Point(152, 410);
			this->label_alpha->Name = L"label_alpha";
			this->label_alpha->Size = System::Drawing::Size(33, 13);
			this->label_alpha->TabIndex = 14;
			this->label_alpha->Text = L"alpha";
			// 
			// textBox_betta
			// 
			this->textBox_betta->Location = System::Drawing::Point(191, 437);
			this->textBox_betta->Name = L"textBox_betta";
			this->textBox_betta->Size = System::Drawing::Size(61, 20);
			this->textBox_betta->TabIndex = 17;
			this->textBox_betta->Text = L"0,1";
			// 
			// label_betta
			// 
			this->label_betta->AutoSize = true;
			this->label_betta->Location = System::Drawing::Point(152, 441);
			this->label_betta->Name = L"label_betta";
			this->label_betta->Size = System::Drawing::Size(31, 13);
			this->label_betta->TabIndex = 16;
			this->label_betta->Text = L"betta";
			// 
			// textBox__max_h
			// 
			this->textBox__max_h->Location = System::Drawing::Point(490, 437);
			this->textBox__max_h->Name = L"textBox__max_h";
			this->textBox__max_h->Size = System::Drawing::Size(61, 20);
			this->textBox__max_h->TabIndex = 23;
			this->textBox__max_h->Text = L"1000";
			// 
			// label_max_h
			// 
			this->label_max_h->AutoSize = true;
			this->label_max_h->Location = System::Drawing::Point(377, 441);
			this->label_max_h->Name = L"label_max_h";
			this->label_max_h->Size = System::Drawing::Size(107, 13);
			this->label_max_h->TabIndex = 22;
			this->label_max_h->Text = L"Макс. кол-во шагов";
			// 
			// textBox__granica
			// 
			this->textBox__granica->Location = System::Drawing::Point(490, 407);
			this->textBox__granica->Name = L"textBox__granica";
			this->textBox__granica->Size = System::Drawing::Size(61, 20);
			this->textBox__granica->TabIndex = 21;
			this->textBox__granica->Text = L"1e-7";
			// 
			// label_granica
			// 
			this->label_granica->AutoSize = true;
			this->label_granica->Location = System::Drawing::Point(328, 410);
			this->label_granica->Name = L"label_granica";
			this->label_granica->Size = System::Drawing::Size(156, 13);
			this->label_granica->TabIndex = 20;
			this->label_granica->Text = L"Параметр выхода за границу";
			// 
			// textBox__loc_pogr
			// 
			this->textBox__loc_pogr->Location = System::Drawing::Point(490, 370);
			this->textBox__loc_pogr->Name = L"textBox__loc_pogr";
			this->textBox__loc_pogr->Size = System::Drawing::Size(61, 20);
			this->textBox__loc_pogr->TabIndex = 19;
			this->textBox__loc_pogr->Text = L"1e-7";
			// 
			// label_loc_pogr
			// 
			this->label_loc_pogr->AutoSize = true;
			this->label_loc_pogr->Location = System::Drawing::Point(354, 373);
			this->label_loc_pogr->Name = L"label_loc_pogr";
			this->label_loc_pogr->Size = System::Drawing::Size(130, 13);
			this->label_loc_pogr->TabIndex = 18;
			this->label_loc_pogr->Text = L"Параметр контроля Л.П";
			// 
			// checkBox_LP
			// 
			this->checkBox_LP->AutoSize = true;
			this->checkBox_LP->Location = System::Drawing::Point(337, 471);
			this->checkBox_LP->Name = L"checkBox_LP";
			this->checkBox_LP->Size = System::Drawing::Size(214, 17);
			this->checkBox_LP->TabIndex = 24;
			this->checkBox_LP->Text = L"Контроль Л.П за счет двойного шага";
			this->checkBox_LP->UseVisualStyleBackColor = true;
			
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_info->Location = System::Drawing::Point(825, 360);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(0, 16);
			this->label_info->TabIndex = 25;
			// 
			// comboBox_Zadachi
			// 
			this->comboBox_Zadachi->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_Zadachi->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->comboBox_Zadachi->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Тестовая задача", L"Основная задача 1",
					L"Основная задача 2"
			});
			this->comboBox_Zadachi->Location = System::Drawing::Point(12, 30);
			this->comboBox_Zadachi->Name = L"comboBox_Zadachi";
			this->comboBox_Zadachi->Size = System::Drawing::Size(121, 21);
			this->comboBox_Zadachi->TabIndex = 27;
			this->comboBox_Zadachi->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label_Info_zada
			// 
			this->label_Info_zada->AutoSize = true;
			this->label_Info_zada->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Info_zada->Location = System::Drawing::Point(16, 105);
			this->label_Info_zada->Name = L"label_Info_zada";
			this->label_Info_zada->Size = System::Drawing::Size(0, 16);
			this->label_Info_zada->TabIndex = 28;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1257, 500);
			this->Controls->Add(this->label_Info_zada);
			this->Controls->Add(this->comboBox_Zadachi);
			this->Controls->Add(this->label_info);
			this->Controls->Add(this->checkBox_LP);
			this->Controls->Add(this->textBox__max_h);
			this->Controls->Add(this->label_max_h);
			this->Controls->Add(this->textBox__granica);
			this->Controls->Add(this->label_granica);
			this->Controls->Add(this->textBox__loc_pogr);
			this->Controls->Add(this->label_loc_pogr);
			this->Controls->Add(this->textBox_betta);
			this->Controls->Add(this->label_betta);
			this->Controls->Add(this->textBox_alpha);
			this->Controls->Add(this->label_alpha);
			this->Controls->Add(this->textBox_u_shtrix_0);
			this->Controls->Add(this->label_u_shtrix_0);
			this->Controls->Add(this->textBox_x_max);
			this->Controls->Add(this->label_x_max);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox_h);
			this->Controls->Add(this->label_h);
			this->Controls->Add(this->textBox_u0);
			this->Controls->Add(this->label_u0);
			this->Controls->Add(this->textBox_x_min);
			this->Controls->Add(this->label_x_min);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		// отдельная функция для точного решения для тестовой задачи
		double exact_test(double x, double u0) {
			return u0 * std::exp(3.0 * x); // точное решение u' = 3u, u(0) = u0
		}

		//Тут прописано все для тестовой задачи
		void SolveTaskTest() {
			GraphPane^ panel = zedGraphControl1->GraphPane;
			panel->CurveList->Clear();

			PointPairList^ f_list = gcnew PointPairList();   // приближённое решение
			PointPairList^ exact_list = gcnew PointPairList(); // точное решение

			// Считываем нужные нам данные для решения задачи
			// Тут мы не используем alpha betta и v' так как это для 2ой задачи
			double x0 = Convert::ToDouble(textBox_x_min->Text);
			double xmax = Convert::ToDouble(textBox_x_max->Text);
			double u0 = Convert::ToDouble(textBox_u0->Text);
			double h0 = Convert::ToDouble(textBox_h->Text);
			int smax = Convert::ToInt32(textBox__max_h->Text);
			double barier = Convert::ToDouble(textBox__granica->Text);
			double eps = 0;

			// Если используем Контроль то берем параметр ибо у нас адаптивная функция
			if (checkBox_LP->Checked) {
				eps = Convert::ToDouble(textBox__loc_pogr->Text);
			}

			std::vector<StepData2> table = RK4_table(x0, u0, xmax, h0, eps, smax,barier);

			// Параметры для вычисления и вывода информации
			double max_abs_err = 0.0;
			double x_at_max = 0.0;
			double x_at_maxh = 0.0;
			double x_at_minh = 0.0;
			double h_min = 1000000;
			double h_max = 0.0;
			int count_C1 = 0;
			int count_C2 = 0;

			for (const auto& row : table) {
				if (row.abs_err > max_abs_err) {
					max_abs_err = row.abs_err;
					x_at_max = row.xi;
				}
				if (row.hi < h_min) { h_min = row.hi; x_at_minh = row.xi; };
				if (row.hi > h_max) { h_max = row.hi;  x_at_maxh = row.xi; };
				if (row.C1 > 0) count_C1 += row.C1;
				if (row.C2 > 0) count_C2 += row.C2;
			}
			int steps_count = table.size();
			double distance_to_boundary = xmax - table.back().xi;

			//Выводим инфу в lable
			if (checkBox_LP->Checked) {
				label_info->Text =
					"Количество шагов = " + steps_count +
					"\nМаксимальное |U-V| = " + max_abs_err.ToString("F8") +
					" при x = " + x_at_max.ToString("F8") +
					"\nРасстояние до границы = " + distance_to_boundary.ToString("F8") +
					"\n\nМинимальный шаг h_min = " + h_min.ToString("F8") +
					" при x = " + x_at_minh.ToString("F8") +
					"\nМаксимальный шаг h_max = " + h_max.ToString("F8") +
					" при x = " + x_at_maxh.ToString("F8") +
					"\nКоличество увеличений шага = " + count_C1 +
					"\nКоличество уменьшений шага = " + count_C2;
			}
			else {
				label_info->Text = "Количество шагов = " + steps_count +
					"\nМаксимальное |U-V| = " +
					max_abs_err.ToString("F8") +
					"  при x = " + x_at_max.ToString("F8") +
					"\nРасстояние до границы = " +
					distance_to_boundary.ToString("F8");
			}


			// Заполняем DataGridView и список для графика
			dataGridView1->Rows->Clear();
			int row = 0;
			for (auto& step : table)
			{
				// DataGridView
				dataGridView1->Rows->Add();
				dataGridView1->Rows[row]->Cells[0]->Value = (step.i);
				dataGridView1->Rows[row]->Cells[1]->Value = step.xi.ToString("F8");
				dataGridView1->Rows[row]->Cells[2]->Value = step.vi.ToString("F8");
				dataGridView1->Rows[row]->Cells[3]->Value = step.v2i.ToString("F8");
				dataGridView1->Rows[row]->Cells[4]->Value = step.vi_v2i.ToString("F8");
				dataGridView1->Rows[row]->Cells[5]->Value = step.error.ToString("F8");
				dataGridView1->Rows[row]->Cells[6]->Value = step.hi.ToString("F8");
				dataGridView1->Rows[row]->Cells[7]->Value = step.C1;
				dataGridView1->Rows[row]->Cells[8]->Value = step.C2;
				dataGridView1->Rows[row]->Cells[9]->Value = step.ui.ToString("F8");
				dataGridView1->Rows[row]->Cells[10]->Value = step.abs_err.ToString("F8");
				row++;

				// График (например, метод с текущим шагом vi)
				f_list->Add(step.xi, step.vi);
				exact_list->Add(step.xi, exact_test(step.xi, u0));
			}

			// добавляем кривые на график
			panel->AddCurve("Приближенное решение", f_list, Color::Red, SymbolType::Circle);
			panel->AddCurve("Точное решение", exact_list, Color::Blue, SymbolType::Plus);

			panel->XAxis->Scale->Min = x0 - 0.1;
			panel->XAxis->Scale->Max = xmax + 0.1;
			panel->YAxis->Title->Text = "u(x)";
			panel->XAxis->Title->Text = "x";

			zedGraphControl1->AxisChange();
			zedGraphControl1->Invalidate();
		}

		//Решение Основной задачи 1
		void SolveTaskMain1() {
			GraphPane^ panel = zedGraphControl1->GraphPane;
			panel->CurveList->Clear();
			PointPairList^ f_list = gcnew PointPairList();

			// Считываем нужные нам данные для решения задачи
			// Тут мы не используем alpha betta и v' так как это для 2ой задачи
			double x0 = Convert::ToDouble(textBox_x_min->Text);
			double xmax = Convert::ToDouble(textBox_x_max->Text);
			double u0 = Convert::ToDouble(textBox_u0->Text);
			double h0 = Convert::ToDouble(textBox_h->Text);
			int smax = Convert::ToInt32(textBox__max_h->Text);
			double barier = Convert::ToDouble(textBox__granica->Text);
			double eps = 0;

			// Если используем Контроль то берем параметр ибо у нас адаптивная функция
			if (checkBox_LP->Checked) {
				eps = Convert::ToDouble(textBox__loc_pogr->Text);
			}

			std::vector<StepData> table = RK4_table1(x0, u0, xmax, h0, eps, smax, barier);

			// Параметры для вычисления и вывода информации
			double x_at_maxh = 0.0;
			double x_at_minh = 0.0;
			double h_min = 1000000;
			double h_max = 0.0;
			int count_C1 = 0;
			int count_C2 = 0;

			for (const auto& row : table) {
				if (row.hi < h_min) { h_min = row.hi; x_at_minh = row.xi; };
				if (row.hi > h_max) { h_max = row.hi;  x_at_maxh = row.xi; };
				if (row.c1 > 0) count_C1 += row.c1;
				if (row.c2 > 0) count_C2 += row.c2;
			}
			int steps_count = table.size();
			double distance_to_boundary = xmax - table.back().xi;

			//Выводим инфу в lable
			if (checkBox_LP->Checked) {
				label_info->Text =
					"Количество шагов = " + steps_count +
					"\nРасстояние до границы = " + distance_to_boundary.ToString("F8") +
					"\n\nМинимальный шаг h_min = " + h_min.ToString("F8") +
					" при x = " + x_at_minh.ToString("F8") +
					"\nМаксимальный шаг h_max = " + h_max.ToString("F8") +
					" при x = " + x_at_maxh.ToString("F8") +
					"\nКоличество увеличений шага = " + count_C1 +
					"\nКоличество уменьшений шага = " + count_C2;
			}
			else {
				label_info->Text = "Количество шагов = " + steps_count +
					"\nРасстояние до границы = " +
					distance_to_boundary.ToString("F8");
			}


			// Заполняем DataGridView и список для графика
			dataGridView1->Rows->Clear();
			int row = 0;
			for (auto& step : table)
			{
				// DataGridView
				dataGridView1->Rows->Add();
				dataGridView1->Rows[row]->Cells[0]->Value = (step.i);
				dataGridView1->Rows[row]->Cells[1]->Value = step.xi.ToString("F8");
				dataGridView1->Rows[row]->Cells[2]->Value = step.vi.ToString("F8");
				dataGridView1->Rows[row]->Cells[3]->Value = step.v2i.ToString("F8");
				dataGridView1->Rows[row]->Cells[4]->Value = step.vi_v2i.ToString("F8");
				dataGridView1->Rows[row]->Cells[5]->Value = step.error.ToString("F8");
				dataGridView1->Rows[row]->Cells[6]->Value = step.hi.ToString("F8");
				dataGridView1->Rows[row]->Cells[7]->Value = step.c1;
				dataGridView1->Rows[row]->Cells[8]->Value = step.c2;
				row++;

				// График (например, метод с текущим шагом vi)
				f_list->Add(step.xi, step.vi);
			}

			// добавляем кривые на график
			panel->AddCurve("Приближенное решение", f_list, Color::Red, SymbolType::Circle);

			panel->XAxis->Scale->Min = x0 - 0.1;
			panel->XAxis->Scale->Max = xmax + 0.1;
			panel->YAxis->Title->Text = "u(x)";
			panel->XAxis->Title->Text = "x";

			zedGraphControl1->AxisChange();
			zedGraphControl1->Invalidate();


		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		// Тут мы запускаем задачи в зависимости от выбранной, функии выше
		int index = comboBox_Zadachi->SelectedIndex;
		if (index == -1) {
			return;
		}
		if (index == 0) {
			SolveTaskTest();
		}
		else if (index == 1) SolveTaskMain1();
		//else if (index == 2) SolveTask3();


	}
	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	// конопка увеличения графика
	GraphPane^ panel = zedGraphControl1->GraphPane;
	double xmin = Convert::ToDouble(textBox_x_min->Text);
	double xmax = Convert::ToDouble(textBox_x_max->Text);
	// Устанавливаем интересующий нас интервал по оси X
	panel->XAxis->Scale->Min = xmin;
	panel->XAxis->Scale->Max = xmax;

	// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
	// В противном случае на рисунке будет показана только часть графика, 
	// которая умещается в интервалы по осям, установленные по умолчанию
	zedGraphControl1->AxisChange();
	// Обновляем график
	zedGraphControl1->Invalidate();

}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//Тут мы выбираем задачу из списка и она выводится на экране
	
	int index = comboBox_Zadachi->SelectedIndex;

	switch (index)
	{
	case 0: // Задача 1
		label_Info_zada->Text = "Тестовая задача: \ndu/dx = 3*u\nu(0)=u0";
		break;
	case 1: // Задача 2
		label_Info_zada->Text = "Основная задача 1: \ndu/dx = 1/(2x+x^2)*u^2 + u - u^3*sin(10x)\nu(0)=u0";
		//Задал заранее значения адекватные ибо там U(x) в космос улетает
		textBox_x_min->Text = "0,1";
		textBox_x_max->Text = "1";
		textBox_u0->Text = "0,1";
		textBox_h->Text = "0,001";
		break;
	case 2: // Задача 3
		label_Info_zada->Text = "Задача 3: u' = e^x - 3u";
		break;
	default:
		label_Info_zada->Text = "";
		break;
	}
}
};
}
