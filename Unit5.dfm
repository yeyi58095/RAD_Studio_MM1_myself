object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Form5'
  ClientHeight = 316
  ClientWidth = 587
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
    Left = 25
    Top = 39
    Width = 79
    Height = 13
    Caption = 'Interarrival Time'
  end
  object ServiceTime: TLabel
    Left = 51
    Top = 66
    Width = 60
    Height = 13
    Caption = 'Service Time'
  end
  object Label2: TLabel
    Left = 38
    Top = 94
    Width = 73
    Height = 13
    Caption = 'Simulation Time'
  end
  object Label3: TLabel
    Left = 29
    Top = 122
    Width = 83
    Height = 13
    Caption = 'Mean Queue Size'
  end
  object Label4: TLabel
    Left = 29
    Top = 148
    Width = 86
    Height = 13
    Caption = 'Mean System Size'
  end
  object CurrentEvent: TLabel
    Left = 50
    Top = 176
    Width = 65
    Height = 13
    Caption = 'CurrentEvent'
  end
  object Label5: TLabel
    Left = 384
    Top = 80
    Width = 31
    Height = 13
    Caption = 'Debug'
  end
  object ITComboBox: TComboBox
    Left = 128
    Top = 36
    Width = 145
    Height = 21
    TabOrder = 0
    Text = 'ITComboBox'
    OnChange = ITComboBoxChange
    Items.Strings = (
      'Uniform R.V'
      'Exponential R.V'
      'Normal R.V'
      'Pareto R.V')
  end
  object STComboBox: TComboBox
    Left = 128
    Top = 63
    Width = 145
    Height = 21
    TabOrder = 1
    Text = 'STComboBox'
    OnChange = STComboBoxChange
    Items.Strings = (
      'Uniform R.V'
      'Exponential R.V'
      'Normal R.V'
      'Pareto R.V')
  end
  object SimulationTEdit: TEdit
    Left = 128
    Top = 90
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '0'
    OnChange = SimulationTEditChange
  end
  object MQSize: TEdit
    Left = 128
    Top = 117
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '0'
    OnChange = MQSizeChange
  end
  object MSSize: TEdit
    Left = 128
    Top = 144
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '0'
    OnChange = MSSizeChange
  end
  object Run: TButton
    Left = 40
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Run'
    TabOrder = 5
    OnClick = RunClick
  end
  object Plot: TButton
    Left = 160
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Plot'
    TabOrder = 6
    OnClick = PlotClick
  end
  object Stop: TButton
    Left = 40
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 7
  end
  object Edit5: TEdit
    Left = 128
    Top = 171
    Width = 81
    Height = 21
    TabOrder = 8
  end
  object Edit6: TEdit
    Left = 215
    Top = 171
    Width = 82
    Height = 21
    TabOrder = 9
  end
end
