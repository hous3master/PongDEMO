#pragma once
#include "Game.h"
namespace PongDEMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objGame = new Game();
			bmpBG = gcnew Bitmap("background.png");
			//bmpBG = gcnew Bitmap("background.png");
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
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Game* objGame;
		Bitmap^ bmpBG;
	private: System::Windows::Forms::Label^ player1_points;
	private: System::Windows::Forms::Label^ player2_points;
	private: System::Windows::Forms::Label^ label_winner;


		   //Bitmap^ bmpBG;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->player1_points = (gcnew System::Windows::Forms::Label());
			this->player2_points = (gcnew System::Windows::Forms::Label());
			this->label_winner = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// player1_points
			// 
			this->player1_points->AutoSize = true;
			this->player1_points->BackColor = System::Drawing::Color::Black;
			this->player1_points->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player1_points->ForeColor = System::Drawing::Color::White;
			this->player1_points->Location = System::Drawing::Point(242, 58);
			this->player1_points->Name = L"player1_points";
			this->player1_points->Size = System::Drawing::Size(124, 135);
			this->player1_points->TabIndex = 0;
			this->player1_points->Text = L"#";
			this->player1_points->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// player2_points
			// 
			this->player2_points->AutoSize = true;
			this->player2_points->BackColor = System::Drawing::Color::Black;
			this->player2_points->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player2_points->ForeColor = System::Drawing::Color::White;
			this->player2_points->Location = System::Drawing::Point(416, 58);
			this->player2_points->Name = L"player2_points";
			this->player2_points->Size = System::Drawing::Size(124, 135);
			this->player2_points->TabIndex = 1;
			this->player2_points->Text = L"#";
			this->player2_points->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_winner
			// 
			this->label_winner->AutoSize = true;
			this->label_winner->BackColor = System::Drawing::Color::Black;
			this->label_winner->Enabled = false;
			this->label_winner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_winner->ForeColor = System::Drawing::Color::White;
			this->label_winner->Location = System::Drawing::Point(267, 346);
			this->label_winner->Name = L"label_winner";
			this->label_winner->Size = System::Drawing::Size(227, 46);
			this->label_winner->TabIndex = 2;
			this->label_winner->Text = L"placeholder";
			this->label_winner->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_winner->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 753);
			this->Controls->Add(this->label_winner);
			this->Controls->Add(this->player2_points);
			this->Controls->Add(this->player1_points);
			this->MaximumSize = System::Drawing::Size(800, 800);
			this->MinimumSize = System::Drawing::Size(800, 800);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//BACKGROUND
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = space->Allocate(g, ClientRectangle);
		//bf->Graphics->Clear(Color::Black); //Solid color
		bf->Graphics->DrawImage(bmpBG, 0, 0, bmpBG->Width, bmpBG->Height); //Custom BG

		//Execution
		objGame->Draw_Objects(bf->Graphics);
		objGame->Collision();
		player1_points->Text = objGame->return_player_points(1);
		player2_points->Text = objGame->return_player_points(2);
		if (objGame->End_Game()) {
			label_winner->Text = objGame->return_player_winner();
			label_winner->Visible = true;
			label_winner->Enabled = true;
			timer1->Enabled = false;
		}

		bf->Render(g);
		delete bf, space, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) objGame->new_orientation_player1(direction::up);
		if (e->KeyCode == Keys::S) objGame->new_orientation_player1(direction::down);
		if (e->KeyCode == Keys::Up) objGame->new_orientation_player2(direction::up);
		if (e->KeyCode == Keys::Down) objGame->new_orientation_player2(direction::down);
	}
	};
}
