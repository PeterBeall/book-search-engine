#pragma once
#include "ResultWindow.h"
#include <vector>
#include <msclr\marshal_cppstd.h>

namespace COP3530Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for application
	/// </summary>
	public ref class InputWindow : public System::Windows::Forms::Form
	{
	public:
		InputWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void searchFunc(std::string title, std::string rating, int pages, std::vector<std::string> genre);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InputWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::TextBox^ genre;
	private: System::Windows::Forms::Label^ KeywordsLabel;
	private: System::Windows::Forms::TextBox^ titleInput;




	private: System::Windows::Forms::Label^ GenreLabel;
	private: System::Windows::Forms::Label^ Subtitle;
	private: System::Windows::Forms::Label^ PageSizeLabel;
	private: System::Windows::Forms::TextBox^ pageSizeMin;
	private: System::Windows::Forms::Label^ PageSizeMinLabel;
	private: System::Windows::Forms::Label^ PageSizeMaxLabel;
	private: System::Windows::Forms::TextBox^ pageSizeMax;
	private: System::Windows::Forms::Label^ AuthorsLabel;



	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::ComboBox^ ratingBox;
	private: System::Windows::Forms::Label^ label1;







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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InputWindow::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ratingBox = (gcnew System::Windows::Forms::ComboBox());
			this->search = (gcnew System::Windows::Forms::Button());
			this->AuthorsLabel = (gcnew System::Windows::Forms::Label());
			this->PageSizeMaxLabel = (gcnew System::Windows::Forms::Label());
			this->pageSizeMax = (gcnew System::Windows::Forms::TextBox());
			this->PageSizeMinLabel = (gcnew System::Windows::Forms::Label());
			this->PageSizeLabel = (gcnew System::Windows::Forms::Label());
			this->pageSizeMin = (gcnew System::Windows::Forms::TextBox());
			this->KeywordsLabel = (gcnew System::Windows::Forms::Label());
			this->titleInput = (gcnew System::Windows::Forms::TextBox());
			this->GenreLabel = (gcnew System::Windows::Forms::Label());
			this->Subtitle = (gcnew System::Windows::Forms::Label());
			this->genre = (gcnew System::Windows::Forms::TextBox());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->ratingBox);
			this->panel1->Controls->Add(this->search);
			this->panel1->Controls->Add(this->AuthorsLabel);
			this->panel1->Controls->Add(this->PageSizeMaxLabel);
			this->panel1->Controls->Add(this->pageSizeMax);
			this->panel1->Controls->Add(this->PageSizeMinLabel);
			this->panel1->Controls->Add(this->PageSizeLabel);
			this->panel1->Controls->Add(this->pageSizeMin);
			this->panel1->Controls->Add(this->KeywordsLabel);
			this->panel1->Controls->Add(this->titleInput);
			this->panel1->Controls->Add(this->GenreLabel);
			this->panel1->Controls->Add(this->Subtitle);
			this->panel1->Controls->Add(this->genre);
			this->panel1->Controls->Add(this->Title);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(758, 433);
			this->panel1->TabIndex = 0;
			// 
			// ratingBox
			// 
			this->ratingBox->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ratingBox->FormattingEnabled = true;
			this->ratingBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ratingBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->ratingBox->Location = System::Drawing::Point(413, 206);
			this->ratingBox->Name = L"ratingBox";
			this->ratingBox->Size = System::Drawing::Size(119, 24);
			this->ratingBox->TabIndex = 15;
			// 
			// search
			// 
			this->search->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->search->Font = (gcnew System::Drawing::Font(L"Moonglade DEMO", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->search->Location = System::Drawing::Point(479, 353);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(161, 40);
			this->search->TabIndex = 14;
			this->search->Text = L"Search!";
			this->search->UseVisualStyleBackColor = false;
			this->search->Click += gcnew System::EventHandler(this, &InputWindow::search_Click);
			// 
			// AuthorsLabel
			// 
			this->AuthorsLabel->AutoSize = true;
			this->AuthorsLabel->BackColor = System::Drawing::Color::Transparent;
			this->AuthorsLabel->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AuthorsLabel->Location = System::Drawing::Point(410, 185);
			this->AuthorsLabel->Name = L"AuthorsLabel";
			this->AuthorsLabel->Size = System::Drawing::Size(100, 18);
			this->AuthorsLabel->TabIndex = 13;
			this->AuthorsLabel->Text = L"What rating\?";
			this->AuthorsLabel->Click += gcnew System::EventHandler(this, &InputWindow::label1_Click_3);
			// 
			// PageSizeMaxLabel
			// 
			this->PageSizeMaxLabel->AutoSize = true;
			this->PageSizeMaxLabel->BackColor = System::Drawing::Color::Transparent;
			this->PageSizeMaxLabel->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PageSizeMaxLabel->Location = System::Drawing::Point(206, 284);
			this->PageSizeMaxLabel->Name = L"PageSizeMaxLabel";
			this->PageSizeMaxLabel->Size = System::Drawing::Size(35, 16);
			this->PageSizeMaxLabel->TabIndex = 11;
			this->PageSizeMaxLabel->Text = L"Max";
			this->PageSizeMaxLabel->Click += gcnew System::EventHandler(this, &InputWindow::PageSizeMaxLabel_Click);
			// 
			// pageSizeMax
			// 
			this->pageSizeMax->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->pageSizeMax->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pageSizeMax->Location = System::Drawing::Point(247, 284);
			this->pageSizeMax->Name = L"pageSizeMax";
			this->pageSizeMax->Size = System::Drawing::Size(136, 22);
			this->pageSizeMax->TabIndex = 10;
			// 
			// PageSizeMinLabel
			// 
			this->PageSizeMinLabel->AutoSize = true;
			this->PageSizeMinLabel->BackColor = System::Drawing::Color::Transparent;
			this->PageSizeMinLabel->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PageSizeMinLabel->Location = System::Drawing::Point(20, 284);
			this->PageSizeMinLabel->Name = L"PageSizeMinLabel";
			this->PageSizeMinLabel->Size = System::Drawing::Size(32, 16);
			this->PageSizeMinLabel->TabIndex = 9;
			this->PageSizeMinLabel->Text = L"Min";
			// 
			// PageSizeLabel
			// 
			this->PageSizeLabel->AutoSize = true;
			this->PageSizeLabel->BackColor = System::Drawing::Color::Transparent;
			this->PageSizeLabel->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PageSizeLabel->Location = System::Drawing::Point(20, 254);
			this->PageSizeLabel->Name = L"PageSizeLabel";
			this->PageSizeLabel->Size = System::Drawing::Size(139, 18);
			this->PageSizeLabel->TabIndex = 7;
			this->PageSizeLabel->Text = L"What page length\?";
			this->PageSizeLabel->Click += gcnew System::EventHandler(this, &InputWindow::label1_Click_2);
			// 
			// pageSizeMin
			// 
			this->pageSizeMin->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->pageSizeMin->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pageSizeMin->Location = System::Drawing::Point(58, 284);
			this->pageSizeMin->Name = L"pageSizeMin";
			this->pageSizeMin->Size = System::Drawing::Size(136, 22);
			this->pageSizeMin->TabIndex = 6;
			this->pageSizeMin->TextChanged += gcnew System::EventHandler(this, &InputWindow::textBox1_TextChanged_1);
			// 
			// KeywordsLabel
			// 
			this->KeywordsLabel->AutoSize = true;
			this->KeywordsLabel->BackColor = System::Drawing::Color::Transparent;
			this->KeywordsLabel->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KeywordsLabel->Location = System::Drawing::Point(410, 254);
			this->KeywordsLabel->Name = L"KeywordsLabel";
			this->KeywordsLabel->Size = System::Drawing::Size(240, 18);
			this->KeywordsLabel->TabIndex = 5;
			this->KeywordsLabel->Text = L"What is a book you enjoy\? (Title)\r\n";
			this->KeywordsLabel->Click += gcnew System::EventHandler(this, &InputWindow::label1_Click_1);
			// 
			// titleInput
			// 
			this->titleInput->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->titleInput->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleInput->Location = System::Drawing::Point(413, 284);
			this->titleInput->Name = L"titleInput";
			this->titleInput->Size = System::Drawing::Size(332, 22);
			this->titleInput->TabIndex = 4;
			this->titleInput->TextChanged += gcnew System::EventHandler(this, &InputWindow::textBox1_TextChanged);
			// 
			// GenreLabel
			// 
			this->GenreLabel->AutoSize = true;
			this->GenreLabel->BackColor = System::Drawing::Color::Transparent;
			this->GenreLabel->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenreLabel->Location = System::Drawing::Point(16, 185);
			this->GenreLabel->Name = L"GenreLabel";
			this->GenreLabel->Size = System::Drawing::Size(194, 18);
			this->GenreLabel->TabIndex = 3;
			this->GenreLabel->Text = L"What genres interest you\?";
			// 
			// Subtitle
			// 
			this->Subtitle->AutoSize = true;
			this->Subtitle->BackColor = System::Drawing::Color::Transparent;
			this->Subtitle->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Subtitle->Location = System::Drawing::Point(16, 104);
			this->Subtitle->Name = L"Subtitle";
			this->Subtitle->Size = System::Drawing::Size(317, 18);
			this->Subtitle->TabIndex = 2;
			this->Subtitle->Text = L"Let us help you find what you\'re looking for!";
			// 
			// genre
			// 
			this->genre->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->genre->Font = (gcnew System::Drawing::Font(L"Georgia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genre->Location = System::Drawing::Point(19, 206);
			this->genre->Name = L"genre";
			this->genre->Size = System::Drawing::Size(364, 22);
			this->genre->TabIndex = 1;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Moonglade DEMO", 26.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->Title->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Title->Location = System::Drawing::Point(12, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(351, 84);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Good Reads Book\r\nRecommendations";
			this->Title->Click += gcnew System::EventHandler(this, &InputWindow::Title_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(538, 210);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 18);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Star(s)";
			// 
			// InputWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 432);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"InputWindow";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Book Recommendation";
			this->Load += gcnew System::EventHandler(this, &InputWindow::application_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void application_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Title_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void PageSizeMaxLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_3(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged_2(System::Object^ sender, System::EventArgs^ e) {
	}

	//Submit Button
	private: System::Void search_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::string title = msclr::interop::marshal_as<std::string>(titleInput->Text);
		std::string pages = msclr::interop::marshal_as<std::string>(pageSizeMax->Text);
		std::string genres = msclr::interop::marshal_as<std::string>(genre->Text);

		std::vector<std::string> genreVec;
		genreVec.push_back(genres);

		std::string rate = msclr::interop::marshal_as<std::string>(ratingBox->GetItemText(ratingBox->SelectedItem));
		
		searchFunc(title, rate, stoi(pages), genreVec);
	}
};
}
