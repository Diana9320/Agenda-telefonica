#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
//#include <libcomdlg32.a>
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include "Persoana.h"
#include <fstream>
#include <bits/stdc++.h>
#define CLICK_ADAUGA 1
#define BUTTON_CLICK2 2
#define BUTTON_CLICK3 3
#define BUTTON_CLICK4 4
#define BUTTON_CLICK5 5
#define OPEN_FILE 1


using namespace std;
ofstream f;
Persoana p[10];
int nrPers=0;
HWND hEdit;
HWND LabelNume,LabelPrenume,LabelMail, LabelDNastere,LabelTel,TextNume;
HWND TextPrenume,TextMail,TextDNastere,TextTel;
HWND TxtAfisare[20];
const int y=17;
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void CreareControale(HWND);
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
int validareTel(wchar_t* s);

/*int main()
{
    int opt;
    wchar_t num[20],pren[20],mail[40],data[12],tel[10];
    Persoana pi;
    cout<<"***************************\n";
    cout<<"* 1.Cititi date despre persoana\n";
    int i=0;
    do
    {
        cout<<"Dati optiunea dorita \n";
        cin>>opt;
        switch(opt)
        {
        case 1:
            cin.get();
            cout<<"Dati numele persoanei:\n ";
            wcin.getline(num,20 );
            cout<<"Dati prenumele persoanei:\n ";
            wcin.getline(pren,20   );
            cout<<"Dati email\n";
            wcin.getline(mail,40   );
            cout<<"Dati data nastere\n";
            wcin.getline(data,12   );
            cout<<"Dati nr de tel: \n";
            wcin.getline(tel,10    );
          //  pi(i,getWC(num),getWC(pren),getWC(tel),getWC(data),getWC(mail);
            break;
        default:
            cout<<"Optiune gresita\n";
        }

    }while(opt!=0);

    return 0;

}*/
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               _T("Agenda"),       /* Title Text */
               WS_OVERLAPPEDWINDOW, /* default window */
               CW_USEDEFAULT,       /* Windows decides the position */
               CW_USEDEFAULT,       /* where the window ends up on the screen */
               800,                 /* The programs width */
               400,                 /* and height in pixels */
               HWND_DESKTOP,        /* The window is a child-window to desktop */
               NULL,                /* No menu */
               hThisInstance,       /* Program Instance handler */
               NULL                 /* No Window Creation data */
           );
    // CreareControale(hwnd);
    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

void display_file(char* path)
{
    FILE *file;
    file=fopen(path,"rb");
    fseek(file,0,SEEK_END);
    int _size=ftell(file);
    rewind(file);
    char *data=new char(_size+1);
    fread(data,_size,1,file);
    data[_size]='\0';
    SetWindowText(hEdit,data);

}

void open_file(wchar_t* Lab)
{
    ofstream f;
    f.open("file.txt");
    f<<"Nume este: "<<Lab<<endl;

    /* char file_name[100];
     OPENFILENAME ofn;
     ZeroMemory(&ofn,sizeof(OPENCARDNAME));
     ofn.lStructSize=sizeof(OPENCARDNAME);
     ofn.hwndOwner=hwnd;
     ofn.lpstrFile=file_name;
     ofn.lpstrFile[0]='\0';
     ofn.nMaxFile=100;
     ofn.lpstrFilter="All files\0*.*\0TextFiles\0*.TXT\0 ";
     ofn.nFilterIndex=1;
     GetOpenFileName(&ofn);
     display_file(ofn.lpstrFile);
    // MessageBox(NULL,ofn.lpstrFile,"",MB_OK);*/
}

int validare(wchar_t* s,wchar_t* s1,wchar_t* s2,wchar_t* s3,wchar_t* s4)
{
    int ok=1;
    if(!wcscmp(s,L"")&& !wcscmp(s1,L"") && !wcscmp(s4,L""))
    {
        MessageBoxW(NULL,L"nu este introdus nume,prenume si numar de telefon",L"eroare",MB_OK);
        ok=0;
    }
    else if(!wcscmp(s,L"")&& !wcscmp(s1,L""))
    {
        MessageBoxW(NULL,L"nu este introdus nume si prenume",L"eroare",MB_OK);
        ok=0;
    }
    else if(!wcscmp(s,L"")&&!wcscmp(s4,L""))
    {
        MessageBoxW(NULL,L"nu este introdus nume si numarul de telefon",L"eroare",MB_OK);
        ok=0;
    }
    else if(!wcscmp(s1,L"") && !wcscmp(s4,L""))
    {
        MessageBoxW(NULL,L"nu este introdus prenumele si numarul de telefon",L"eroare",MB_OK);
        ok=0;
    }
    else if(!wcscmp(s,L""))
    {
        MessageBoxW(NULL,L"nu este introdus numele",L"eroare",MB_OK);
        ok=0;
    }
    else if(!wcscmp(s1,L""))
    {
        MessageBoxW(NULL,L"nu este introdus prenumele",L"eroare",MB_OK);
        ok=0;
    }
    else if(!wcscmp(s4,L"") )//|| validareTel(p[nrPers-1].GetNrTel())==0)
    {
        MessageBoxW(NULL,L"nu este introdus numarul de telefon sau caracter invalid",L"eroare",MB_OK);
        ok=0;
    }
    if(ok==0)
        return 0;
    return 1;
}
int validareTel(wchar_t* s)
{
    for(int i=0;i<=wcslen(s);i++)
    if(isdigit(s[i])==0)
        return 0;
    return 1;

}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    wchar_t s[20],s1[20],s2[40],s3[12],s4[10];
    wchar_t sir[90];

    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        CreareControale(hwnd);
        break;

    case WM_COMMAND:
    {

        switch(wParam)
        {
        case CLICK_ADAUGA://adauga si afiseaza persoane in lista
        {
            int ok=1;
            GetWindowTextW(TextNume,s,20);
            GetWindowTextW(TextPrenume,s1,20);
            GetWindowTextW(TextMail,s2,40);
            GetWindowTextW(TextDNastere,s3,12);
            GetWindowTextW(TextTel,s4,10);
            if(validare(s,s1,s2,s3,s4)==1 )
            {

                p[nrPers].SetNume(s);
                p[nrPers].SetPrenume(s1);
                p[nrPers].SetMail(s2);
                p[nrPers].SetDNastere(s3);
                p[nrPers].SetTel(s4);

                MessageBoxW(NULL,p[nrPers].RetnumeComp(),L"date Complete",MB_OK);
                SetWindowTextW(TextNume,L"");
                SetWindowTextW(TextPrenume,L"");
                SetWindowTextW(TextMail,L"");
                SetWindowTextW(TextDNastere,L"");
                SetWindowTextW(TextTel,L"");
                nrPers++;

            }
            break;
        }
        case BUTTON_CLICK2:// Afisare nume
            if(!wcscmp(p[nrPers-1].GetNume(),L"-"))
                MessageBoxW(NULL,L"nu este introdus niciun  nume",L"eroare",MB_OK);
            else
                MessageBoxW(NULL,p[nrPers-1].GetNume(),L"Nume: ",MB_OK);
            break;
        case BUTTON_CLICK3://afisare numar de telefon
            if(!wcscmp(p[nrPers-1].GetNrTel(),L"-") )
                MessageBoxW(NULL,L"nu este introdus niciun  numar",L"eroare",MB_OK);
            else
                MessageBoxW(NULL,p[nrPers-1].GetNrTel(),L"numat telefon: ",MB_OK);
            break;
        case BUTTON_CLICK4: //numarul de persoane
            wchar_t buffer[256];
            wsprintfW(buffer, L"%d", nrPers);
            MessageBoxW(NULL,buffer,L"Nr Persoane din agenda",MB_OK);

            break;
        case BUTTON_CLICK5://Afisare persoane din lista
            for(int i=0;i<nrPers;i++)
                {
                    TxtAfisare[i]=CreateWindowW(L"Edit",L"",WS_VISIBLE| WS_CHILD | WS_BORDER,250,i*y,520,18,hwnd,NULL,NULL,NULL);
                    SetWindowTextW(TxtAfisare[i],p[i].RetnumeComp());

                }
            break;
        }
    }
    break;
    case WM_DESTROY:
        PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
        break;
    default:                      /* for messages that we don't deal with */
        return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
void CreareControale(HWND hwnd)
{
    //Label
    LabelNume=CreateWindowW(L"static",L"Nume:",WS_VISIBLE | WS_CHILD | SS_CENTER,0,0,100,18,hwnd,NULL,NULL,NULL);
    LabelPrenume=CreateWindowW(L"static",L"Prenume:",WS_VISIBLE | WS_CHILD | SS_CENTER,0,19,100,18,hwnd,NULL,NULL,NULL);
    LabelDNastere=CreateWindowW(L"static",L"Data nasterii:",WS_VISIBLE | WS_CHILD | SS_CENTER,0,38,100,18,hwnd,NULL,NULL,NULL);
    LabelTel=CreateWindowW(L"static",L"Numar de\n telefon:",WS_VISIBLE | WS_CHILD | SS_CENTER,0,57,100,36,hwnd,NULL,NULL,NULL);
    LabelMail=CreateWindowW(L"static",L"Mail:",WS_VISIBLE | WS_CHILD | SS_CENTER,0,95,100,18,hwnd,NULL,NULL,NULL);

    //textbox
    TextNume=CreateWindowW(L"Edit",L"",WS_VISIBLE| WS_CHILD | WS_BORDER,105,1,130,18,hwnd,NULL,NULL,NULL);
    TextPrenume=CreateWindowW(L"Edit",L"",WS_VISIBLE| WS_CHILD | WS_BORDER,105,20,130,18,hwnd,NULL,NULL,NULL);
    TextDNastere=CreateWindowW(L"Edit",L"",WS_VISIBLE| WS_CHILD | WS_BORDER,105,39,130,18,hwnd,NULL,NULL,NULL);
    TextTel=CreateWindowW(L"Edit",L"",WS_VISIBLE| WS_CHILD | WS_BORDER| ES_MULTILINE,105,58,130,36,hwnd,NULL,NULL,NULL);
    TextMail=CreateWindowW(L"Edit",L"",WS_VISIBLE| WS_CHILD | WS_BORDER,105,96,130,18,hwnd,NULL,NULL,NULL);

    //buttons
    CreateWindowW(L"button",L"Afisare Persoane din lista",WS_VISIBLE | WS_CHILD | SS_CENTER,0,120,235,30,hwnd,(HMENU)BUTTON_CLICK5,NULL,NULL);
    CreateWindowW(L"button",L"Adauga si afisare date\n complete",WS_VISIBLE | WS_CHILD | SS_CENTER,0,155,235,60,hwnd,(HMENU)CLICK_ADAUGA,NULL,NULL);
    CreateWindowW(L"button",L"Nr Persoane",WS_VISIBLE | WS_CHILD | SS_CENTER,0,220,235,40,hwnd,(HMENU)BUTTON_CLICK4,NULL,NULL);
    CreateWindowW(L"button",L"Afisare nume",WS_VISIBLE | WS_CHILD | SS_CENTER,0,261,235,36,hwnd,(HMENU)BUTTON_CLICK2,NULL,NULL);
    CreateWindowW(L"button",L"Afisare numar de telefon",WS_VISIBLE | WS_CHILD | SS_CENTER,0,301,235,60,hwnd,(HMENU)BUTTON_CLICK3,NULL,NULL);


}
