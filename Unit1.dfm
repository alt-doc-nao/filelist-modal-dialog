object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 409
  ClientWidth = 712
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  DesignSize = (
    712
    409)
  TextHeight = 15
  object Label1: TLabel
    Left = 80
    Top = 280
    Width = 34
    Height = 15
    Caption = 'Label1'
  end
  object Image1: TImage
    Left = 16
    Top = 8
    Width = 320
    Height = 240
    Proportional = True
    Stretch = True
  end
  object Image2: TImage
    Left = 369
    Top = 8
    Width = 320
    Height = 240
    Anchors = [akTop, akRight]
    Proportional = True
    Stretch = True
    ExplicitLeft = 384
  end
  object Label2: TLabel
    Left = 200
    Top = 332
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Button1: TButton
    Left = 80
    Top = 329
    Width = 75
    Height = 23
    Caption = 'Open'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Cross: TCheckBox
    Left = 200
    Top = 280
    Width = 97
    Height = 17
    Caption = 'Cross'
    TabOrder = 1
  end
  object Dump: TButton
    Left = 369
    Top = 322
    Width = 75
    Height = 25
    Caption = 'Dump'
    TabOrder = 2
    OnClick = DumpClick
  end
end
