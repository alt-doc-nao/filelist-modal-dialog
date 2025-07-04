object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Form2'
  ClientHeight = 499
  ClientWidth = 621
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 16
    Top = 35
    Width = 112
    Height = 15
    Caption = 'C:\...\Studio\23.0\bin'
  end
  object Label2: TLabel
    Left = 264
    Top = 8
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Image1: TImage
    Left = 8
    Top = 320
    Width = 282
    Height = 171
    Proportional = True
    Stretch = True
  end
  object FileListBox1: TFileListBox
    Left = 204
    Top = 64
    Width = 401
    Height = 233
    ItemHeight = 15
    Mask = '*.jpg;*.jps;*.mpo'
    TabOrder = 0
    OnClick = FileListBox1Click
  end
  object OK: TButton
    Left = 360
    Top = 376
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OKClick
  end
  object Cancel: TButton
    Left = 488
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = CancelClick
  end
  object DriveComboBox1: TDriveComboBox
    Left = 16
    Top = 8
    Width = 145
    Height = 21
    DirList = DirectoryListBox1
    TabOrder = 3
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 16
    Top = 64
    Width = 169
    Height = 233
    DirLabel = Label1
    FileList = FileListBox1
    TabOrder = 4
    OnChange = DirectoryListBox1Change
  end
end
