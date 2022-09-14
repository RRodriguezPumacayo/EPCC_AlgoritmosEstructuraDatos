#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int exp{0},digito;
    double binario, decimal{0};
   cout << "Introduce numero: ";
   cin >> binario;
   while((binario/10)!=0)
   {
           digito = (int)binario % 10;
           decimal = decimal + digito * pow(2.0,exp);
           exp++;
           binario=(int)(binario/10);
   }
   decimal=decimal + binario * pow(2.0,exp);
   cout << "\nDecimal: " << decimal << endl;
   return 0;
}
