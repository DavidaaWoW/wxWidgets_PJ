#include "cMain.h"
#include "string"
#include <vector>
#include <math.h>

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(1000, OnButton1Clicked)
    EVT_BUTTON(1001, OnButton2Clicked)
    EVT_BUTTON(1002, OnButton3Clicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, 12, "Matrix", wxPoint(0,0), wxSize(800,600),wxSYSTEM_MENU | wxRESIZE_BORDER | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
    button1 = new wxButton(this, 1000, "3x3", wxPoint(100,100), wxSize(600,200));
    button2 = new wxButton(this, 1001, "2x2", wxPoint(100,300), wxSize(600,200));
    button3 = new wxButton(this, 1002, "SOLVE!", wxPoint(100,401), wxSize(300,100));
    button3 -> Hide();
}

cMain::~cMain()
{
    //dtor
}

void cMain::OnButton1Clicked(wxCommandEvent &evt)
{
    flag = 1;
    text1 = new wxTextCtrl(this, 100, "", wxPoint(100,100), wxSize(100,100));
    text2 = new wxTextCtrl(this, 101, "", wxPoint(100,200), wxSize(100,100));
    text3 = new wxTextCtrl(this, 102, "", wxPoint(100,300), wxSize(100,100));
    text4 = new wxTextCtrl(this, 103, "", wxPoint(200,100), wxSize(100,100));
    text5 = new wxTextCtrl(this, 104, "", wxPoint(200,200), wxSize(100,100));
    text6 = new wxTextCtrl(this, 105, "", wxPoint(200,300), wxSize(100,100));
    text7 = new wxTextCtrl(this, 106, "", wxPoint(300,100), wxSize(100,100));
    text8 = new wxTextCtrl(this, 107, "", wxPoint(300,200), wxSize(100,100));
    text9 = new wxTextCtrl(this, 108, "", wxPoint(300,300), wxSize(100,100));
    text_ctrl1 = new wxTextCtrl(this, 2000, wxEmptyString, wxPoint(500,150), wxSize(200,200),wxTE_READONLY);
    button1 -> Hide();
    button2 -> Hide();
    button3 -> Show();
}

void cMain::OnButton2Clicked(wxCommandEvent &evt)
{
    flag = 2;
    text1 = new wxTextCtrl(this, 100, "", wxPoint(100,100), wxSize(100,100));
    text2 = new wxTextCtrl(this, 101, "", wxPoint(100,200), wxSize(100,100));
    text3 = new wxTextCtrl(this, 102, "", wxPoint(200,100), wxSize(100,100));
    text4 = new wxTextCtrl(this, 103, "", wxPoint(200,200), wxSize(100,100));
    text_ctrl1 = new wxTextCtrl(this, 2000, wxEmptyString, wxPoint(500,150), wxSize(200,200),wxTE_READONLY);
    button1 -> Hide();
    button2 -> Hide();
    button3 -> Show();
}
void cMain::OnButton3Clicked(wxCommandEvent &evt)
{
    text_ctrl1 -> Clear();
    s = text1 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    //cout << "AMA FLAG1 = " << flag1 << " ama v.size = " << v.size() << endl;
    if(flag1 == v.size())
    helper2(0);
    helper1();
    s = text2 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(1);
    helper1();
    s = text3 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(2);
    helper1();
    s = text4 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(3);
    helper1();
    if(flag == 1)
    {
    s = text5 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(4);
    helper1();
        s = text6 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(5);
    helper1();
        s = text7 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(6);
    helper1();
        s = text8 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(7);
    helper1();
        s = text9 -> GetValue();
    copy(s.begin(), s.end(), back_inserter(v));
    helper();
    if(flag1 == v.size())
    helper2(8);
    helper1();
    }
    if(flag == 2)
    {
        cout << "AMA num[0] = " << num[0] << " AMA num[1] = " << num[1] << " AMA num[2] = " << num[2] << " AMA num[3] = " << num[3] << endl;
        answer = num[0]*num[3]-num[1]*num[2];
        ss << answer;
        ss >> s;
        answer = 0;
        ss = {};
        text_ctrl1 -> AppendText(s);
        s = "";
        helper3();
    }
    else
    {
        answer = num[0]*num[4]*num[8]+num[1]*num[5]*num[6]+num[2]*num[3]*num[7]-num[0]*num[5]*num[7]-num[1]*num[3]*num[8]-num[2]*num[4]*num[6];
        ss<<answer;
        ss>>s;
        answer = 0;
        ss={};
        text_ctrl1 -> AppendText(s);
        s="";
        helper3();
    }
}
