object STForm: TSTForm
  Left = 0
  Top = 0
  Caption = 'STForm'
  ClientHeight = 73
  ClientWidth = 566
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 25
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 240
    Top = 24
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Edit1: TEdit
    Left = 96
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '0'
  end
  object Edit2: TEdit
    Left = 312
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object Button1: TButton
    Left = 448
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 448
    Top = 39
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Button2Click
  end
end
