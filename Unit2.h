//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TFileListBox *FileListBox1;
	TButton *OK;
	TButton *Cancel;
	TDriveComboBox *DriveComboBox1;
	TDirectoryListBox *DirectoryListBox1;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image1;
	void __fastcall OKClick(TObject *Sender);
	void __fastcall CancelClick(TObject *Sender);
	void __fastcall FileListBox1Click(TObject *Sender);
	void __fastcall DirectoryListBox1Change(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
