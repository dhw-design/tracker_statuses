/********************************************************************************
 * project     Tracker statuses                                                 *
 *                                                                              *
 * file        MainWindow.cpp                                                   *
 * author      Dmitriy Bassamykin                                               *
 * date        12.12.2019                                                       *
 * copyright   The MIT License (MIT). Copyright (c) 2019 Dmitriy Bassamykin     *
 *                                                                              *
 ********************************************************************************/

// -*- C++ -*-
//
// generated by wxGlade 0.9.4 on Thu Dec 12 10:46:42 2019
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include <wx/wx.h>
#include "MainWindow.h"

// begin wxGlade: ::extracode
// end wxGlade

enum {
    spinNavtelecomId = wxID_HIGHEST,
    spinNavisetId,
};

typedef struct _naviset_st {
    unsigned char pwrExt : 1;
    unsigned char move : 1;
    unsigned char security : 1;
    unsigned char gsm : 2;
    unsigned char gprs : 1;
    unsigned char gps : 2;
} naviset_st_t;

typedef struct _navtelecom_st {
    unsigned char gsm : 1;
    unsigned char usb : 1;
    unsigned char hiResGps : 1;
    unsigned char timeSync : 1;
    unsigned char sim : 1;
    unsigned char gsmReg : 1;
    unsigned char rouming : 1;
    unsigned char generator : 1;
} navtelecom_st_t;


MainWindow::MainWindow(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: MainWindow::MainWindow
    SetSize(wxSize(271, 252));
    tabTrackers = new wxNotebook(this, wxID_ANY);
    tabNaviset = new wxPanel(tabTrackers, wxID_ANY);
    tabNavtelecom = new wxPanel(tabTrackers, wxID_ANY);
    spinNavtelecomStatus = new wxSpinCtrl(tabNavtelecom, spinNavtelecomId, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255);
    lblNavtelecomGsm = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomUsb = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomHiResGps = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomTimeSync = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomSim = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomGsmReg = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomRouming = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    lblNavtelecomGenerator = new wxStaticText(tabNavtelecom, wxID_ANY, wxEmptyString);
    spinNavisetStatus = new wxSpinCtrl(tabNaviset, spinNavisetId, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255);
    lblNavisetPwrExt = new wxStaticText(tabNaviset, wxID_ANY, wxEmptyString);
    lblNavisetMove = new wxStaticText(tabNaviset, wxID_ANY, wxEmptyString);
    lblNavisetSecurity = new wxStaticText(tabNaviset, wxID_ANY, wxEmptyString);
    lblNavisetGsm = new wxStaticText(tabNaviset, wxID_ANY, wxEmptyString);
    lblNavisetGprs = new wxStaticText(tabNaviset, wxID_ANY, wxEmptyString);
    lblNavisetGps = new wxStaticText(tabNaviset, wxID_ANY, wxEmptyString);

    set_properties();
    do_layout();
    // end wxGlade
    updateNavisetStatus();
    updateNavtelecomStatus();
}


void MainWindow::set_properties()
{
    // begin wxGlade: MainWindow::set_properties
    SetTitle(wxT("������� ��������"));
    // end wxGlade
    wxIcon icon(wxICON(IDI_ICON1));
    SetIcon(icon);
}


void MainWindow::do_layout()
{
    // begin wxGlade: MainWindow::do_layout
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_5 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* label_1 = new wxStaticText(tabNavtelecom, wxID_ANY, wxT("modules_st"));
    label_1->SetMinSize(wxSize(70, 16));
    sizer_3->Add(label_1, 0, 0, 0);
    sizer_3->Add(spinNavtelecomStatus, 1, 0, 0);
    sizer_2->Add(sizer_3, 1, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomGsm, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomUsb, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomHiResGps, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomTimeSync, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomSim, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomGsmReg, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomRouming, 0, wxEXPAND, 0);
    sizer_2->Add(lblNavtelecomGenerator, 0, wxEXPAND, 0);
    sizer_2->Add(20, 20, 10, wxEXPAND, 0);
    tabNavtelecom->SetSizer(sizer_2);
    wxStaticText* label_2 = new wxStaticText(tabNaviset, wxID_ANY, wxT("status"));
    label_2->SetMinSize(wxSize(70, 16));
    sizer_5->Add(label_2, 0, 0, 0);
    sizer_5->Add(spinNavisetStatus, 1, 0, 0);
    sizer_4->Add(sizer_5, 1, 0, 0);
    sizer_4->Add(lblNavisetPwrExt, 0, wxEXPAND, 0);
    sizer_4->Add(lblNavisetMove, 0, wxEXPAND, 0);
    sizer_4->Add(lblNavisetSecurity, 0, wxEXPAND, 0);
    sizer_4->Add(lblNavisetGsm, 0, wxEXPAND, 0);
    sizer_4->Add(lblNavisetGprs, 0, wxEXPAND, 0);
    sizer_4->Add(lblNavisetGps, 0, wxEXPAND, 0);
    sizer_4->Add(20, 20, 14, wxEXPAND, 0);
    tabNaviset->SetSizer(sizer_4);
    tabTrackers->AddPage(tabNavtelecom, wxT("Navtelecom"));
    tabTrackers->AddPage(tabNaviset, wxT("Naviset"));
    sizer_1->Add(tabTrackers, 1, wxEXPAND, 0);
    SetSizer(sizer_1);
    Layout();
    // end wxGlade
}

void MainWindow::updateNavisetStatus(void)
{
    uint8_t status = static_cast<uint8_t>(spinNavisetStatus->GetValue() & 0xff);
    naviset_st_t* status_bits = reinterpret_cast<naviset_st_t*>(&status);

    lblNavisetGsm->SetForegroundColour(wxNullColour);
    lblNavisetGps->SetForegroundColour(wxNullColour);

    lblNavisetPwrExt->SetLabel((status_bits->pwrExt == 0) ?
        wxT("������� ���������� � �����") :
        wxT("������� ���������� ���� �����"));

    lblNavisetPwrExt->SetForegroundColour(status_bits->pwrExt == 0 ? wxNullColour : *wxRED);

    lblNavisetMove->SetLabel((status_bits->move == 0) ?
        wxT("������ �����") :
        wxT("������ � ��������"));

    lblNavisetSecurity->SetLabel(status_bits->security == 0 ?
        wxT("���� � ������") :
        wxT("����� �� ������"));

    switch (status_bits->gsm)
    {
    case 0:
        lblNavisetGsm->SetLabel(wxT("��� �������� ��� �����"));
        break;
    case 1:
        lblNavisetGsm->SetLabel(wxT("�������� ������ ��� �����"));
        break;
    case 2:
        lblNavisetGsm->SetLabel(wxT("�������� ������ ��� �����"));
        break;
    case 3:
        lblNavisetGsm->SetLabel(wxT("�������� ��� ��� �����!!!"));
        lblNavisetGsm->SetForegroundColour(*wxRED);
        break;
    default:
        break;
    }

    lblNavisetGprs->SetLabel(status_bits->gprs == 0 ?
        wxT("GPRS ���������� �����������") :
        wxT("��� GPRS ����������"));

    switch (status_bits->gps)
    {
    case 0:
        lblNavisetGps->SetLabel(wxT("GPS ������� ����������"));
        break;
    case 1:
        lblNavisetGps->SetLabel(wxT("��� ����� � GPS �������"));
        lblNavisetGps->SetForegroundColour(*wxRED);
        break;
    case 2:
        lblNavisetGps->SetLabel(wxT("����������� GPS �������"));
        lblNavisetGps->SetForegroundColour(*wxRED);
        break;
    case 3:
        lblNavisetGps->SetLabel(wxT("�� GPS �������"));
        lblNavisetGps->SetForegroundColour(*wxRED);
        break;
    default:
        break;
    }
}

void MainWindow::updateNavtelecomStatus(void)
{
    uint8_t status = static_cast<uint8_t>(spinNavtelecomStatus->GetValue() & 0xff);
    navtelecom_st_t* status_bits = reinterpret_cast<navtelecom_st_t*>(&status);

    lblNavtelecomGsm->SetLabel(status_bits->gsm == 0 ?
        wxT("GSM ��������") :
        wxT("GSM �������"));

    lblNavtelecomUsb->SetLabel(status_bits->usb == 0 ?
        wxT("USB ��������") :
        wxT("USB �������"));

    lblNavtelecomHiResGps->SetLabel(status_bits->hiResGps == 0 ?
        wxT("������������ �������� ��������") :
        wxT("������������ �������� �������"));

    lblNavtelecomTimeSync->SetLabel(status_bits->timeSync == 0 ?
        wxT("���� ���������������� �� GPS") :
        wxT("���� �� ���������������� �� GPS"));

    lblNavtelecomSim->SetLabel(status_bits->sim == 0 ?
        wxT("�������� ������ ��� �����") :
        wxT("�������� ������ ��� �����"));

    lblNavtelecomGsmReg->SetLabel(status_bits->gsmReg == 0 ?
        wxT("��� ����������� � ������� ����") :
        wxT("����������� � ������� ����"));

    lblNavtelecomRouming->SetLabel(status_bits->rouming == 0 ?
        wxT("�������� ����") :
        wxT("�������"));

    lblNavtelecomGenerator->SetLabel(status_bits->generator == 0 ?
        wxT("��������� (���������) ��������") :
        wxT("��������� (���������) �������"));
}


BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    // begin wxGlade: MainWindow::event_table
    EVT_SPINCTRL(spinNavtelecomId, MainWindow::onSpinNavtelecomHandler)
    EVT_TEXT(spinNavtelecomId, MainWindow::onSpinNavtelecomTextHandler)
    EVT_SPINCTRL(spinNavisetId, MainWindow::onSpinNavisetHandler)
    EVT_TEXT(spinNavisetId, MainWindow::onSpinNavisetTextHandler)
    // end wxGlade
END_EVENT_TABLE();


void MainWindow::onSpinNavtelecomHandler(wxSpinEvent &event)  // wxGlade: MainWindow.<event_handler>
{
    event.Skip();
    updateNavtelecomStatus();
    // notify the user that he hasn't implemented the event handler yet
    //wxLogDebug(wxT("Event handler (MainWindow::onSpinModulesStHandler) not implemented yet"));
}

void MainWindow::onSpinNavisetHandler(wxSpinEvent &event)  // wxGlade: MainWindow.<event_handler>
{
    event.Skip();

    updateNavisetStatus();
    // notify the user that he hasn't implemented the event handler yet
    //wxLogDebug(wxT("Event handler (MainWindow::onSpinStatusHandler) not implemented yet"));
}

void MainWindow::onSpinNavtelecomTextHandler(wxCommandEvent& event)
{
    event.Skip();
    updateNavtelecomStatus();
}

void MainWindow::onSpinNavisetTextHandler(wxCommandEvent& event)
{
    event.Skip();
    updateNavisetStatus();
}


// wxGlade: add MainWindow event handlers

