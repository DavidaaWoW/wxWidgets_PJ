#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"
#include "wx/listctrl.h"
#include <sstream>
#include <vector>

using namespace std;

class cMain : public wxFrame
{
    public:
        cMain();
        ~cMain();
    public:
        wxTextCtrl *text1 = nullptr;
        wxTextCtrl *text2 = nullptr;
        wxTextCtrl *text3 = nullptr;
        wxTextCtrl *text4 = nullptr;
        wxTextCtrl *text5 = nullptr;
        wxTextCtrl *text6 = nullptr;
        wxTextCtrl *text7 = nullptr;
        wxTextCtrl *text8 = nullptr;
        wxTextCtrl *text9 = nullptr;
        wxButton *button1 = nullptr;
        wxButton *button2 = nullptr;
        wxButton *button3 = nullptr;
        wxTextCtrl *text_ctrl1 = nullptr;
    public:
        int counter = 0;
        int flag,flag1;
        vector <char> v = {};
        string s;
        bool flag100 = false;
        char b = '0';
        float num[4] = {0,0,0,0},num1[9] = {0,0,0,0,0,0,0,0,0};
        float answer,temp;
        stringstream ss;
    void helper()
    {
        if(s != ""){
        for(int a = 0; a<v.size(); a++)
    {
        for(int c = 0; c<10; c++)
        {
            if(v[a]!= b)
                counter++;
            //cout << "AMA v[a] = " << v[a] << " AMA b = " << b << endl;
            b++;
        }
        b = '0';
        //cout << counter << endl;
        if(v[a] == ','&&flag100 == false)
            {
            counter--;
            flag100 = true;
            }
        if(counter == 10) //вывести сообщение об ошибке
        {
            counter = 0;
            break;
            text_ctrl1 -> AppendText("error!");
        }
        else if(counter == 9)
            flag1++;
        counter = 0;
    }
        }
        else
            flag1 = 0;
    }
    void helper1()
    {
        flag1 = 0;
        v = {};
        s = "";
        flag100 = false;
    }
    void helper2(int m)
    {
        if(s!=""){
        if(flag100 == false)
        {
        v[0] -= '0';
        num[m] = v[0];
        cout << "PRENUM[m] = " << num[m] << " " << m << endl;
        for(int y = 1; y<v.size(); y++)
        {
            v[y] -= '0';
            num[m] *= 10;
            num[m] += v[y];
        }
        cout << "POSTNUM[m] = " << num[m] << endl;
        }
        else
        {
            v[0] -= '0';
            num[m] = v[0];
            for(int t = 2; t<v.size(); t++)
            {
                v[t] -= '0';
                temp = v[t];
                temp /= 10*(t-1);
                num[m] += temp;
                temp = 0;
            }
        }
        }
        else
            num[m] = 0;
    }
    void helper3()
    {
        for(int x = 0; x<4; x++)
        {
            num[x] = 0;
        }
        for(int x = 0; x<9; x++)
        {
            num[x] = 0;
        }
    }
    void helper4(int m)
    {
                if(s!=""){
        if(flag100 == false)
        {
        v[0] -= '0';
        num1[m] = v[0];
        cout << "PRENUM[m] = " << num1[m] << " " << m << endl;
        for(int y = 1; y<v.size(); y++)
        {
            v[y] -= '0';
            num1[m] *= 10;
            num1[m] += v[y];
        }
        cout << "POSTNUM[m] = " << num1[m] << endl;
        }
        else
        {
            v[0] -= '0';
            num1[m] = v[0];
            for(int t = 2; t<v.size(); t++)
            {
                v[t] -= '0';
                temp = v[t];
                temp /= 10*(t-1);
                num1[m] += temp;
                temp = 0;
            }
        }
        }
        else
            num1[m] = 0;
    }
    void OnButton1Clicked(wxCommandEvent &evt);
    void OnButton2Clicked(wxCommandEvent &evt);
    void OnButton3Clicked(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
};

#endif // CMAIN_H
