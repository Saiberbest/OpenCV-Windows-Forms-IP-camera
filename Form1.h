#include "Utils.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <urlmon.h>
#include <wininet.h>
#include <iostream>


namespace OpenCvWinFormsIpCamera {

  using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing::Imaging;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private: System::Windows::Forms::Button^  btnStart;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  ipAdress;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lCounter;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->ipAdress = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lCounter = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(41, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(661, 467);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(597, 559);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(105, 32);
			this->btnStart->TabIndex = 2;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(41, 560);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 31);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Сброс";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// ipAdress
			// 
			this->ipAdress->Location = System::Drawing::Point(95, 497);
			this->ipAdress->Name = L"ipAdress";
			this->ipAdress->Size = System::Drawing::Size(607, 20);
			this->ipAdress->TabIndex = 4;
			this->ipAdress->Text = L"http://192.168.1.111/image\?res=full&x0=0&y0=0&x1=1600&y1=1200.jpg";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 503);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"IpAdress";
			// 
			// lCounter
			// 
			this->lCounter->AutoSize = true;
			this->lCounter->Location = System::Drawing::Point(658, 520);
			this->lCounter->Name = L"lCounter";
			this->lCounter->Size = System::Drawing::Size(44, 13);
			this->lCounter->TabIndex = 6;
			this->lCounter->Text = L"Counter";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 603);
			this->Controls->Add(this->lCounter);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ipAdress);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Class members
	private:
		int counter;
		String ^ipaddress;
		Image ^img;
		// Class methods
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 counter=0;
				 timer1->Enabled=false;
				 //cv::namedWindow("Video");
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (timer1->Enabled == true){
					 ipaddress=ipAdress->Text;
					 timer1->Enabled=false;
					 btnStart->Text="Старт";

				 }else{
					 timer1->Enabled=true;
					 btnStart->Text="Стоп";
				 }
			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			const char *filename = "img.jpg";
			img=nullptr;
			
			ipaddress=ipAdress->Text;
			// Standard C++ string declaration
			std::string str;
	
			// Convert Managed (.Net) String to standard C++ string
			// (Look in the Utils.cpp file of the project)
			ToStdString(ipaddress,str);
			const char *chIpAddress=str.c_str();
			//Если скачивание с камеры успешно, то...
			if (URLDownloadToFileA(NULL,LPCSTR(chIpAddress),LPCSTR(filename),0,NULL)==S_OK) 
			{
				//Считываем скаченный кадр с IP-камеры
				cv::Mat frame=cv::imread("img.jpg");
				int size=frame.elemSize();
				int step=frame.step;
				//Преобразуем в .NET
				img = gcnew Bitmap(frame.cols, frame.rows,step,PixelFormat::Format24bppRgb, IntPtr(frame.data));				
				//Выводим на pictureBox1
				this->pictureBox1->Image=img;
				this->pictureBox1->Refresh();
				//освобождаем память
				frame.release();
				//Очищаем кэш для следующего кадра
				DeleteUrlCacheEntryA(LPCSTR(chIpAddress));
				//Если не удалось подключиться к камере и получить кадр, то тормозим процесс
			}else{
				timer1->Enabled=false;
				btnStart->Enabled=true;
				btnStart->Text="Старт";
				MessageBox::Show("Не могу подключиться к камере");
				lCounter->Text=counter.ToString();
				counter=0;
				DeleteUrlCacheEntryA(LPCSTR(chIpAddress));
				
			}
			lCounter->Text=counter.ToString();
			counter++;
			//pictureBox1->Enabled=true;

		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled=false;
			 counter=0;
			 btnStart->Enabled=true;
			 btnStart->Text="Старт";
			 lCounter->Text=counter.ToString();
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

