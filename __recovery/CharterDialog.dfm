object Charter: TCharter
  Left = 0
  Top = 0
  Caption = 'Charter'
  ClientHeight = 674
  ClientWidth = 877
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 96
    Top = 8
    Width = 745
    Height = 617
    Title.Text.Strings = (
      'TChart')
    View3D = False
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TFastLineSeries
      Title = 'Mean'
      LinePen.Color = 10708548
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      object TeeFunction1: TAverageTeeFunction
        CalcByValue = False
      end
    end
    object Series2: TFastLineSeries
      Selected.Hover.Visible = True
      SeriesColor = clRed
      Title = 'Current'
      LinePen.Color = clRed
      TreatNulls = tnDontPaint
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
end
