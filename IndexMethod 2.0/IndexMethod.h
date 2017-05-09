#pragma once
#include <string>

#include "TIndexMethod.h"
#include "TInterval.h"
namespace IndexMethod20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::string SystemToStl(String ^s) // Перевод типа String ^ в тип string
	{
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		return std::string(ptr);
	};

	/// <summary>
	/// Summary for IndexMethod
	/// </summary>
	public ref class IndexMethod : public System::Windows::Forms::Form
	{
	public:
		IndexMethod(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			mb->Text = "12";
			rb->Text = "3";
			y1f->Text = "0";
			y1t->Text = "4";
			y2f->Text = "-1";
			y2t->Text = "3";
			sb->Text = "750";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IndexMethod()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  trials;
	private: System::Windows::Forms::Button^  solve_button;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  mb;

	private: System::Windows::Forms::TextBox^  rb;

	private: System::Windows::Forms::TextBox^  sb;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  y2t;

	private: System::Windows::Forms::TextBox^  y2f;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  y1t;

	private: System::Windows::Forms::TextBox^  y1f;

	private: System::Windows::Forms::Label^  label3;
	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->trials = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->solve_button = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->y1f = (gcnew System::Windows::Forms::TextBox());
			this->y1t = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->y2f = (gcnew System::Windows::Forms::TextBox());
			this->y2t = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->sb = (gcnew System::Windows::Forms::TextBox());
			this->rb = (gcnew System::Windows::Forms::TextBox());
			this->mb = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trials))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// trials
			// 
			chartArea1->Name = L"ChartArea1";
			this->trials->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->trials->Legends->Add(legend1);
			this->trials->Location = System::Drawing::Point(12, 12);
			this->trials->Name = L"trials";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"Trials";
			this->trials->Series->Add(series1);
			this->trials->Size = System::Drawing::Size(474, 364);
			this->trials->TabIndex = 0;
			this->trials->Text = L"chart1";
			// 
			// solve_button
			// 
			this->solve_button->Location = System::Drawing::Point(492, 151);
			this->solve_button->Name = L"solve_button";
			this->solve_button->Size = System::Drawing::Size(75, 23);
			this->solve_button->TabIndex = 1;
			this->solve_button->Text = L"Solve";
			this->solve_button->UseVisualStyleBackColor = true;
			this->solve_button->Click += gcnew System::EventHandler(this, &IndexMethod::solve_button_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->mb);
			this->groupBox1->Controls->Add(this->rb);
			this->groupBox1->Controls->Add(this->sb);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(493, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(130, 132);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parameters";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sourcse";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(10, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"r";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 107);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"m";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->y2t);
			this->groupBox2->Controls->Add(this->y2f);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->y1t);
			this->groupBox2->Controls->Add(this->y1f);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Location = System::Drawing::Point(638, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(184, 132);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Intervals";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Y1:  From";
			// 
			// y1f
			// 
			this->y1f->Location = System::Drawing::Point(61, 17);
			this->y1f->Name = L"y1f";
			this->y1f->Size = System::Drawing::Size(39, 20);
			this->y1f->TabIndex = 1;
			// 
			// y1t
			// 
			this->y1t->Location = System::Drawing::Point(132, 17);
			this->y1t->Name = L"y1t";
			this->y1t->Size = System::Drawing::Size(39, 20);
			this->y1t->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Y2:  From";
			// 
			// y2f
			// 
			this->y2f->Location = System::Drawing::Point(61, 60);
			this->y2f->Name = L"y2f";
			this->y2f->Size = System::Drawing::Size(39, 20);
			this->y2f->TabIndex = 4;
			// 
			// y2t
			// 
			this->y2t->Location = System::Drawing::Point(132, 60);
			this->y2t->Name = L"y2t";
			this->y2t->Size = System::Drawing::Size(39, 20);
			this->y2t->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(106, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"To";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(106, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(20, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"To";
			// 
			// sb
			// 
			this->sb->Location = System::Drawing::Point(60, 20);
			this->sb->Name = L"sb";
			this->sb->Size = System::Drawing::Size(64, 20);
			this->sb->TabIndex = 4;
			// 
			// rb
			// 
			this->rb->Location = System::Drawing::Point(60, 60);
			this->rb->Name = L"rb";
			this->rb->Size = System::Drawing::Size(64, 20);
			this->rb->TabIndex = 5;
			// 
			// mb
			// 
			this->mb->Location = System::Drawing::Point(60, 104);
			this->mb->Name = L"mb";
			this->mb->Size = System::Drawing::Size(64, 20);
			this->mb->TabIndex = 6;
			// 
			// IndexMethod
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(834, 388);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->solve_button);
			this->Controls->Add(this->trials);
			this->Name = L"IndexMethod";
			this->Text = L"IndexMethod";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trials))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void solve_button_Click(System::Object^  sender, System::EventArgs^  e) {

				 double r = atof(SystemToStl(rb->Text).c_str());
				 int m = atof(SystemToStl(mb->Text).c_str());
				 int source = atof(SystemToStl(sb->Text).c_str());
				 TInterval y1(atof(SystemToStl(y1f->Text).c_str()), atof(SystemToStl(y1t->Text).c_str()));
				 TInterval y2(atof(SystemToStl(y2f->Text).c_str()), atof(SystemToStl(y2t->Text).c_str()));

				 TIndexMethod indexMethod(y1, y2, r, m, source);
				 indexMethod.solve();
				 int size;
				 double **y = indexMethod.getY(size);
				 //-------print--------------
				 trials->Series["Trials"]->Points->Clear();
				 for (int i = 0; i < size; i++) {
					 trials->Series["Trials"]->Points->AddXY(y[i][0], y[i][1]);
				 }
				 //-------clean-mem--------------
				 for (int i = 0; i < size; i++) {
					 delete[]y[i];
					 y[i] = nullptr;
				 }
				 delete[]y;
				 y = nullptr;
	}
	};
}
