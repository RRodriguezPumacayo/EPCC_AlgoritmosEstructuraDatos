#include <string>
#include <iostream>

using namespace std;

template<class T>
class Nodo
{
  public:
     T          m_Dato;
     Nodo<T>  * m_pSig;
     Nodo<T>  * m_pAnt;
  public:
     Nodo(T d)
     {
       m_Dato = d;
       m_pSig = 0;
       m_pAnt = 0;
     }

};

template<class T>
class Cola
{
    private:
     Nodo<T> * m_pFirst;
     Nodo<T> * m_pLast;

    public:
       Cola()
       {
            m_pFirst = 0;
            m_pLast = 0;
       }
       bool IsEmpty()
       {
            return m_pFirst==0;
       }
       void Desencolar()
       {
            Nodo<T> * pNuevo;
            pNuevo = m_pFirst->m_pSig;
            m_pFirst = pNuevo;

       }

       void Encolar(T d)
       {
           Nodo<T> * pNuevo = new Nodo<T>(d);
           cout<<pNuevo->m_Dato<<"::"<<pNuevo->m_pSig<<endl;
           if(!m_pFirst)
           {
               m_pFirst = pNuevo;
               cout<<m_pFirst->m_Dato<<"::"<<m_pFirst->m_pSig<<endl;
               m_pLast = m_pFirst;
           }
            else
           {
                m_pLast->m_pSig =pNuevo;
                pNuevo->m_pAnt = m_pLast;
                m_pLast = pNuevo;
           }

       }

       void print()
       {
           Nodo<T> * pTmp = m_pFirst;
           while(pTmp!=NULL)
           {
               cout<<pTmp->m_Dato<<"::"<<pTmp->m_pSig<<" -> ";
               pTmp = pTmp->m_pSig;
           }
           cout<<"\n";

       }

       T *  From()
       {
            if(!IsEmpty())
                return &(m_pFirst->m_Dato);
            return;
       }

};

int main()
{
    Cola<int> A;
    A.Encolar(20);
    A.Encolar(30);
    A.Encolar(40);
    A.print();
    A.Desencolar();
    A.print();





  return 0;



}

