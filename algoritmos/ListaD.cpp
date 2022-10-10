#include<iostream>
#include<fstream>


using namespace std;

template<class T>
class Nodo
{
    public:
       T         m_Dato;
       Nodo<T> * m_pSig;
       Nodo<T> * m_pAnt;
    public:
       Nodo(T d)
       {
          m_Dato=d;
          m_pSig=m_pAnt=0;
       }

};


template<class T>
class Lista
{
    private:
       Nodo<T> *    m_pHead;
       Nodo<T> *    m_pLast;

       Nodo<T> *    m_pCurrent;

    public:
      Lista()
      {
        m_pHead=m_pLast=m_pCurrent=0;
      }

      void push_front(T d)
      {
           // precondition
           if(!m_pHead)
           {
              m_pHead = m_pLast = new Nodo<T>(d);
           }
           else
           {
              Nodo<T> * pNuevo=new Nodo<T>(d);
              pNuevo->m_pSig = m_pHead;
              m_pHead->m_pAnt = pNuevo;
              m_pHead = pNuevo;
           }

      }
      void push_back(T d)
      {
           if(!m_pHead)
           {
              m_pHead = m_pLast = new Nodo<T>(d);
           }
           else
           {
              Nodo<T> *pNuevo=new Nodo<T>(d);
              m_pLast->m_pSig = pNuevo;
              pNuevo->m_pAnt = m_pLast;
              m_pLast =pNuevo;
           }
      }
      void push(int p, T d){}

      void pop_front()
      {
          if(!m_pHead) return;
          if(!m_pHead->m_pSig)
          {
              delete m_pHead;
              m_pHead = m_pLast =0;
              return;
          }
          m_pHead=m_pHead->m_pSig;
          delete m_pHead->m_pAnt;
          m_pHead->m_pAnt =0;


      }

      void pop_back(){}
      void pop(int p, T d){}

      bool find(T d, Nodo<T> * & p)
      {
           for(p = m_pHead;p; p=p->m_pSig)
              if(p->m_Dato == d) return true;
           return false;
      }


      bool find_r(T d, Nodo<T> * & p)
      {
           for(p = m_pLast;p; p=p->m_pAnt)
              if(p->m_Dato == d) return true;
           return false;
      }

      void print(ostream  & os)
      {
           for(Nodo<T> * p = m_pHead;p; p=p->m_pSig)
              os<<p->m_Dato<<"--->";
           os<<endl;
      }

      //*****************************//
      // Iterator //
      void begin() {m_pCurrent = m_pHead;}

      void end(){m_pCurrent = m_pLast;}
      void operator++()
      {
         if(m_pCurrent->m_pSig)
           m_pCurrent=m_pCurrent->m_pSig;

      }

      void operator--()
      {
         if(m_pCurrent->m_pAnt)
             m_pCurrent=m_pCurrent->m_pAnt;
      }
      T GetData()
      {
             return m_pCurrent->m_Dato;
      }
      //******************************//

};





int main()
{
  ofstream File("salida.txt");
  Lista<string> A;
  A.push_front("hola");
  A.push_front("soy");
  A.push_front("Ricardo");
  A.push_back("Carajo");
  A.push_back("Happy");
  A.push_front("Ricardo");

  A.print(cout);
  A.print(File);


  return 1;
}










