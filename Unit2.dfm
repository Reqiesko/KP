object Form2: TForm2
  Left = 265
  Top = 451
  Width = 395
  Height = 299
  Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1088#1072#1089#1095#1077#1090#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 377
    Height = 257
    Caption = 'Panel1'
    TabOrder = 0
    object GroupBox2: TGroupBox
      Left = 16
      Top = 8
      Width = 345
      Height = 193
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
      TabOrder = 0
      OnClick = FormShow
      object Label1: TLabel
        Left = 16
        Top = 32
        Width = 100
        Height = 13
        Caption = #1055#1086#1088#1103#1076#1086#1082' '#1088#1077#1072#1082#1094#1080#1080' N'
      end
      object Label2: TLabel
        Left = 16
        Top = 64
        Width = 113
        Height = 13
        Caption = #1050#1086#1085#1089#1090#1072#1085#1090#1072' '#1089#1082#1086#1088#1086#1089#1090#1080' K'
      end
      object Label3: TLabel
        Left = 16
        Top = 96
        Width = 57
        Height = 13
        Caption = #1044#1080#1089#1087#1077#1088#1089#1080#1103
      end
      object Label4: TLabel
        Left = 16
        Top = 128
        Width = 61
        Height = 13
        Caption = #1050#1086#1088#1088#1077#1083#1103#1094#1080#1103
      end
      object Label5: TLabel
        Left = 248
        Top = 64
        Width = 17
        Height = 13
        Caption = '1/'#1089
      end
      object Label6: TLabel
        Left = 248
        Top = 96
        Width = 55
        Height = 13
        Caption = '('#1084#1086#1083#1100'/'#1083')^2'
      end
      object Edit1: TEdit
        Left = 160
        Top = 32
        Width = 81
        Height = 21
        ReadOnly = True
        TabOrder = 0
        Text = 'Edit1'
      end
      object Edit2: TEdit
        Left = 160
        Top = 64
        Width = 81
        Height = 21
        ReadOnly = True
        TabOrder = 1
        Text = 'Edit2'
      end
      object Edit3: TEdit
        Left = 160
        Top = 96
        Width = 81
        Height = 21
        ReadOnly = True
        TabOrder = 2
        Text = 'Edit3'
      end
      object Edit4: TEdit
        Left = 160
        Top = 128
        Width = 81
        Height = 21
        ReadOnly = True
        TabOrder = 3
        Text = 'Edit4'
      end
    end
    object BitBtn1: TBitBtn
      Left = 160
      Top = 216
      Width = 57
      Height = 33
      Caption = #1054#1050
      TabOrder = 1
      OnClick = BitBtn1Click
    end
  end
end
