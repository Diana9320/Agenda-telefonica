#ifndef PERSOANA_H
#define PERSOANA_H
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Persoana
{
    wchar_t nume[20],prenume[20],email[40],dataN[12],nrTel[10];
    int idPers;
    wchar_t s[30],sir[90];
public:
    Persoana();
    Persoana(int _idPers,wchar_t _nume[],wchar_t _prenume[],wchar_t nrTel[],wchar_t _dataN[],wchar_t _mail[]);
   // friend istream& operator>>(istream &c, Persoana &p);

   //get
    wchar_t* RetnumeComp(void);
    wchar_t* GetNrTel(void );
    wchar_t* GetNume(void);
    wchar_t* GetPrenume(void);
    wchar_t* GetDNastere(void);
    wchar_t* GetMail(void);
    int GetId(void);

    //set
    void SetNume(wchar_t s[]);
    void SetPrenume(wchar_t s[]);
    void SetDNastere(wchar_t s[]);
    void SetMail(wchar_t s[]);
    void SetTel(wchar_t s[]);
    void SetId(int id);

    void Afisare();
    const wchar_t* GetWC(const char *c);

};

#endif // PERSOANA_H
