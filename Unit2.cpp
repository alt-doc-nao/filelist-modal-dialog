//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <jpeg.hpp>

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;


extern TBitmap* gleft;
extern TBitmap* gright;
extern String lastposition;

void DispMPO(String filename);
void DispJPS(String filename);

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	if( lastposition != "" )
		DirectoryListBox1->Directory = lastposition;
	else
		DirectoryListBox1->Directory = "C:\\Users\\";
}

//---------------------------------------------------------------------------
void __fastcall TForm2::OKClick(TObject *Sender)
{
	Form1->Label1->Caption = FileListBox1->FileName;
    ModalResult = mrOk;
}

//---------------------------------------------------------------------------
void __fastcall TForm2::CancelClick(TObject *Sender)
{
	ModalResult = mrCancel;
}

//---------------------------------------------------------------------------
// FileListBox1.Mask := '*.txt;*.docx';

void __fastcall TForm2::FileListBox1Click(TObject *Sender)
{
	String fname = FileListBox1->FileName;

	Form1->Label1->Caption =  fname;

	String ext = ExtractFileExt(fname).LowerCase();
	Label2->Caption = ext;

	if( ext == ".jpg" ){

		TJPEGImage* original = new TJPEGImage();
		TBitmap* origbitmap = new TBitmap();

		original->LoadFromFile(fname);
		origbitmap->Assign(original);
		Image1->Picture->Bitmap = origbitmap;

		delete original;
		delete origbitmap;
	}
	else if( ext == ".mpo" ){
	/*
		TMemoryStream* ms = new TMemoryStream();
		DispMPO(fname,ms);
		ms->Position = 0;

		Image1->Picture->LoadFromStream(ms);

		delete ms;
	*/
		DispMPO(fname);
		Image1->Picture->Assign(Form1->Image1->Picture);
		//Image1->Picture->Bitmap = Form1->Image1->Picture->Bitmap; // copy
	}
	else {  // jps Image2.Picture.Assign(Image1.Picture);

		//TBitmap* ms = new TBitmap();
		DispJPS(fname);
		Image1->Picture->Assign(Form1->Image1->Picture);

	}


}
//---------------------------------------------------------------------------

void __fastcall TForm2::DirectoryListBox1Change(TObject *Sender)
{
	lastposition = DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------

