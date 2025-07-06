//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <windows.h>

#include <algorithm>
#include <System.IOUtils.hpp>
#include <string.h>
#include <jpeg.hpp>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

unsigned char* buf;
unsigned char pat[] = {0xff,0xd8,0xff,0xe1};



TJPEGImage* original = new TJPEGImage();
TBitmap* origbitmap = new TBitmap();
TBitmap* gleft = new TBitmap();
TBitmap* gright = new TBitmap();

String lastposition;
String dumpfilebase;


void DispJPS(String filename)
{

	dumpfilebase = filename;

	original->LoadFromFile(filename);
	origbitmap->Assign(original);
	//Image1->Picture->Bitmap = origbitmap;
		TBitmap* bitmap = new TBitmap();
	try {
		bitmap->Assign(original);

		int width = bitmap->Width;
		int height = bitmap->Height;

		// Create a cropped bitmap
		TBitmap* croppedBitmap = new TBitmap();
		try {
			croppedBitmap->Width = width/2;
			croppedBitmap->Height = height;

			// Copy the desired region from the original bitmap
			croppedBitmap->Canvas->CopyRect(
				Rect(0, 0, width/2, height),
				bitmap->Canvas,
				Rect(0,0,width/2, height)   // left image
			);

			if( Form1->Cross->Checked )
				Form1->Image2->Picture->Bitmap = croppedBitmap;
			else
				Form1->Image1->Picture->Bitmap = croppedBitmap;
			//ms = croppedBitmap;
			//gleft = croppedBitmap;

		} __finally {
			delete croppedBitmap;
		}
	} __finally {
		delete bitmap;
	}

	bitmap = new TBitmap();
	try {
		bitmap->Assign(original);

		int width = bitmap->Width;
		int height = bitmap->Height;

		// Create a cropped bitmap
		TBitmap* croppedBitmap = new TBitmap();
		try {
			croppedBitmap->Width = width/2;
			croppedBitmap->Height = height;

			// Copy the desired region from the original bitmap
			croppedBitmap->Canvas->CopyRect(
				Rect(0, 0, width/2, height),
				bitmap->Canvas,
				Rect(width/2,0,width, height)   // right image
//Rect(0,0,width/2, height)   // left image
			);
			if( Form1->Cross->Checked )
				Form1->Image1->Picture->Bitmap = croppedBitmap;
			else
				Form1->Image2->Picture->Bitmap = croppedBitmap;

 //			Form1->Image2->Picture->Bitmap = croppedBitmap;
			//gright = croppedBitmap;
		} __finally {
			delete croppedBitmap;
		}
	} __finally {
		delete bitmap;
	}
}

void DispMPO(String filename)
{

	FILE* fp;
	int found = 0;

	dumpfilebase = filename;
	fp = fopen(AnsiString(filename).c_str(),"rb");
	if(!fp){
	  ShowMessage("file open error\n");
	  return;

	}
	long sz;
	 fseek( fp, 0, SEEK_END );
  sz = ftell( fp );
  //printf( "filesize %d ƒoƒCƒg", sz );
	rewind(fp);
	buf = new unsigned char[sz];

	if( !buf ){
		ShowMessage("not enough core, buy some :-)");
		return;
	}
	int size = fread(buf,1,sz,fp);
	//printf("%d bytes read\n",size);
	fclose(fp);

	unsigned char* p = buf+4; // skip first occurrence
	int	offset = 4;

// int memcmp(const void *ptr1, const void *ptr2, size_t num);

	while( p < buf + size ){
		if( !memcmp(p,pat,4)){
			found = 1;
			break;
		}
		else {
			offset += 4;
			p += 4;
		}
	}

    TMemoryStream* left = new TMemoryStream();
	TMemoryStream* right = new TMemoryStream();

	//ms->WriteBuffer(buf,offset);    // for calling side
	left->WriteBuffer(buf,offset);
	right->WriteBuffer(buf+offset,size-offset);
	//write_out_2files(buf,offset,size);
	left->Position = 0;
	right->Position = 0;

	//Form2->Image1->Picture->LoadFromStream(left);

	if( Form1->Cross->Checked ){
		Form1->Image1->Picture->LoadFromStream(right);
		Form1->Image2->Picture->LoadFromStream(left);
	}
	else {
		Form1->Image1->Picture->LoadFromStream(left);
		Form1->Image2->Picture->LoadFromStream(right);

	}
	delete left;
	delete right;

}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form1->Image1->Visible = false;
	Form1->Image2->Visible = false;

	Form2 = new TForm2(this);

	try {
		 if( Form2->ShowModal() == mrOk ){
			Form1->Image1->Visible = true;
			Form1->Image2->Visible = true;
		 }
		 else
			return;
	} __finally  {

		Form2->Free();
	}

	if( FileExists(Label1->Caption)){
        Label2->Caption = "there";
		//Image1->Picture->Bitmap = gleft;
		//Image2->Picture->Bitmap = gright;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DumpClick(TObject *Sender)
{
/*
BaseName := ChangeFileExt(ExtractFileName(FilePath), '');
Writeln('Base name without extension: ', BaseName); // Output: file
*/

	String outbase = ChangeFileExt(ExtractFileName(dumpfilebase),"");

	if( Cross->Checked ){
		Image1->Picture->SaveToFile(outbase + "_R.jpg");
		Image2->Picture->SaveToFile(outbase + "_L.jpg");

	}
	else {
		Image2->Picture->SaveToFile(outbase + "_R.jpg");
		Image1->Picture->SaveToFile(outbase + "_L.jpg");

    }

}
//---------------------------------------------------------------------------

