#include<iostream>
using namespace std;

/*
Las cadenas string no son en si un tipo de dato, son en realidad una clase
Una cadena de caracteres es una sucesion de caracteres

*/

int longitud(string s)//Recibe una cadena y retorna la longitud
{
    int i{0};
    while(s[i]!='\0')
    {
        ++i;
    }
    return i;
}

void replace(string &s, char viejo, char nuevo)//Recibe una cadena de caracteres y dos caracteres, el carecter nuevo reemplazara al caracter viejo
{
    int i{0};
    for(int i{0};s[i]!='\0';++i)
    {
        if(s[i]==viejo)
            s[i] = nuevo;
    }

    return;
}

int main()
{
    string cadena = "space marines";
    cout<<longitud(cadena)<<"\n";
    replace(cadena, 'a', 'o');
    cout<<cadena;
    return 0;
}
