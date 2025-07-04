object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 421
  ClientWidth = 759
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 64
    Top = 24
    Width = 34
    Height = 15
    Caption = 'Label1'
  end
  object Image1: TImage
    Left = 8
    Top = 144
    Width = 320
    Height = 240
    Proportional = True
    Stretch = True
  end
  object Image2: TImage
    Left = 416
    Top = 144
    Width = 320
    Height = 240
    Proportional = True
    Stretch = True
  end
  object Label2: TLabel
    Left = 184
    Top = 76
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Button1: TButton
    Left = 64
    Top = 73
    Width = 75
    Height = 23
    Caption = 'Open'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Cross: TCheckBox
    Left = 384
    Top = 56
    Width = 97
    Height = 17
    Caption = 'Cross'
    TabOrder = 1
  end
end
