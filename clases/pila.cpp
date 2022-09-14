#include <string>
#include <iostream>

using namespace std;



template<class T>
class Nodo
{
  public:
     T          m_Dato;
     Nodo<T>  * m_pAnt;
  public:
     Nodo(T d)
     {
       m_Dato = d;
       m_pAnt = 0;
     }

};

template<class T>
class Pila
{
    private:
     Nodo<T> * m_pTope;
    public:
       Pila()
       {
         m_pTope =0;
       }
       bool IsEmpty()
       {
           return m_pTope==0;
       }
       void Pop()
       {
          if(!m_pTope) return;

          Nodo<T> * tmp = m_pTope;
          m_pTope = m_pTope->m_pAnt;
          delete tmp;

       }
       void Push(T d)
       {
        Nodo<T> * pNuevo = new Nodo<T>(d);
        if(!m_pTope)
            m_pTope =  pNuevo;
        else
        {
         pNuevo->m_pAnt = m_pTope;
         m_pTope = pNuevo;
        }
       }


       T *  Top()
       {
          if(!IsEmpty())
             return &(m_pTope->m_Dato);
          return 0;
       }

};

int main()
{

  Pila<string>  A;
  A.Push("Hernan");
  A.Push("Cristian");
  A.Push("Martha");

  cout<<*(A.Top())<<" ";
  A.Pop();
  cout<<*(A.Top())<<" ";
  A.Pop();
  cout<<*(A.Top())<<" ";
  A.Pop();

  A.Push("carlos");
  cout<<*(A.Top())<<" ";




  return 0;



}

