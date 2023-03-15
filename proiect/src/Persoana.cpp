#include "Persoana.h"

Persoana::Persoana()
{
    //ctor
    idPers=0;
    wcscpy(nume,L"-");
    wcscpy(prenume,L"-");
    wcscpy(nrTel,L"-");
    wcscpy(dataN,L"-");
    wcscpy(email,L"-");


}
Persoana:: Persoana(int _idPers, wchar_t _nume[],wchar_t _prenume[],wchar_t _nrTel[10],wchar_t _dataN[],wchar_t _mail[])
{
    idPers=_idPers;
    wcscpy(nrTel,_nrTel);
    wcscpy(nume,_nume);
    wcscpy(prenume,_prenume);
    wcscpy(dataN,_dataN);
    wcscpy(email,_mail);

}
/*istream& operator >>(istream &c,Persoana &p)
{
    cout<<"Introduceti nume:"<<"\n";
    c>>p.nume;
    cout<<"Introduceti prenume:"<<"\n";
    c>>p.prenume;
    cout<<"Introduceti data nasterii: \n";
    c>>p.dataN;
    cout<<"Introduceti email: \n";
    c>>p.email;
    return c;
}*/
wchar_t* Persoana::RetnumeComp(void)
{

    wcscpy(sir,nume);
    wcscat(sir,L" ");
    wcscat(sir,prenume);
    wcscat(sir,L" ");
    wcscat(sir,nrTel);
    wcscat(sir,L" ");
    wcscat(sir,dataN);
    wcscat(sir,L" ");
    wcscat(sir,email);
    return sir;
}
void Persoana:: Afisare()
{
    cout<<nume<<"\n";
    cout<<prenume<<"\n";
    cout<<nrTel;
}

wchar_t*  Persoana::GetNume(void)
{
    return nume;
}
wchar_t* Persoana::GetPrenume(void)
{
    return prenume;
}
wchar_t* Persoana::GetMail(void)
{
    return email;
}
wchar_t* Persoana::GetDNastere(void)
{
    return dataN;
}
wchar_t* Persoana::GetNrTel(void)
{
    return nrTel;
}
int Persoana::GetId()
{
    return idPers;
}
void Persoana::SetPrenume(wchar_t s[])
{
    wcscpy(prenume,s);
}
void Persoana::SetMail(wchar_t s[])
{
    wcscpy(email,s);
}
void Persoana::SetDNastere(wchar_t s[])
{
    wcscpy(dataN,s);
}
void Persoana::SetNume(wchar_t s[])
{
    wcscpy(nume,s);
}
void Persoana::SetTel(wchar_t s[])
{
    wcscpy(nrTel,s);
}
void Persoana::SetId(int id)
{
    idPers=id;
}
const wchar_t * Persoana::GetWC(const char *c)
{
    const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);

    return wc;
}
