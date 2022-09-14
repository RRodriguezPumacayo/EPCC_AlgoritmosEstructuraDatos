#include<iostream>
using namespace std;
template<class T>
class Nodo
{
   public:
     T    m_Dato;
     Nodo * m_pSig;
   public:
     Nodo(T d)
     {
        m_Dato = d;
        m_pSig =0;
     }
};


template<class T>
class Lista
{
   private:
     Nodo<T> * m_pHead;
   public:
      Lista()
      {
        m_pHead =0;
      }

      ~Lista()
      {

      }
      void Add(T d)
      {
        Nodo<T>  * pNew = new Nodo<T>(d);
        if(!m_pHead)
          m_pHead = pNew;
        else
        {
            pNew->m_pSig = m_pHead;
            m_pHead = pNew;
        }
      }
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
      void findIterativa(T d)
      {
          Nodo<T> *pTmp = m_pHead;
          while(pTmp->m_Dato!=d)
          {
              pTmp = pTmp->m_pSig;
              //Por ejemplo, tenemos que el puntero siguiente del nodo con elemento 4 es 0
              //Sin embargo, si queremos encontrar el elemento 4, perderiamos el dato, por ello indico que si el puntero siguiente es 0
              //y el dato no es el que buscamos, entonces imprima, elemento no encontrado
              if(pTmp->m_pSig==0 && pTmp->m_Dato!=d)
              {
                cout<<" Element "<<d<<" not found\n";
                break;
              }
          }
          if(pTmp->m_Dato==d)
            cout<<" Element "<<d<<" found\n";
      }

      int findRecursiva(T d)
      {
          Nodo<T> *pTmp = m_pHead;
          if(pTmp->m_Dato != d){
            pTmp = pTmp->m_pSig;
            return findRecursiva(pTmp->m_Dato);
          }
          else
            return d;
      }
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
      void deleteFrom()
      {
          Nodo<T> * pTmp = m_pHead;
          Nodo<T> * pNew = new Nodo<T>(0);

          pNew = pTmp->m_pSig;
          pTmp->m_Dato = pNew->m_Dato;
          pTmp->m_pSig = pNew->m_pSig;
      }
      void deleteLast()
      {
          Nodo<T> * pTmp = m_pHead;
          Nodo<T> * pAux = new Nodo<T>(0);
          while(pTmp->m_pSig!=NULL)
          {
              pTmp = pTmp->m_pSig;
              if(pTmp->m_pSig==NULL){
                    pTmp->m_Dato = NULL;
                    delete pTmp->m_pSig;
              }
          }
      }
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
      void reversaIter()
      {
          Nodo<T> * pTmp = m_pHead;
          Nodo<T> * pNew = pTmp;
          while(pTmp!=NULL)
          {

          }
      }
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
    void maximo()
    {
        Nodo<T> * pTmp = m_pHead;
        Nodo<T> * pNew = new Nodo<T>(0);
        pNew->m_Dato = pTmp->m_Dato;
        while(pTmp->m_pSig!=NULL)
        {
            pTmp = pTmp->m_pSig;
            if(pNew->m_Dato < pTmp->m_Dato)
                pNew->m_Dato = pTmp->m_Dato;
        }
        cout<<" El maximo elemento es: "<<pNew->m_Dato<<endl;
    }

      void print()
      {
         Nodo<T> * pTmp = m_pHead;
         while(pTmp)
         {
            cout<<pTmp->m_Dato<<"::"<<pTmp->m_pSig<<" --> ";
            pTmp = pTmp->m_pSig;
         }
         cout<<"\n";
      }

};
int main()
{

  Lista<int> A;
  A.Add(524);
  A.Add(14);
  A.Add(24);
  A.Add(54);
  A.Add(34);
  A.Add(84);
  int opc{0};
  do{
      cout<<"||||||||||||||||||||||||||||||||||||||||||\n";
      cout<<"1.- Agregar Numero\n";
      cout<<"2.- Numero a buscar, metodo Iterativo\n";
      cout<<"3.- Borrar el numero del inicio\n";
      cout<<"4.- Borrar ultimo numero\n";
      cout<<"5.- Hallar el numero mayor\n";
      cout<<"6.- Terminar\n";
      cout<<"INGRESE OPCION: ";cin>>opc;
      int num{0};
      if(opc==1)
      {
          cout<<"- Ingrese numero: ";cin>>num;
          A.Add(num);
          A.print();
      }
      if(opc==2)
      {
          //Find
          cout<<"- Numero a buscar: ";cin>>num;
          A.findIterativa(num);
          A.print();
      }
      if(opc==3)
      {
          //Delete
          A.deleteFrom();
          A.print();
      }
      if(opc==4)
      {
          A.deleteLast();
          A.print();
      }
      if(opc==5)
      {
          A.maximo();
          A.print();
      }
  }
  while(opc!=6);

  //PrintReversa
  //A.reversaIter();
  //Maximo

  /*Nodo<int> A(4);
  cout<<"Donde vives?" <<&A<<endl;
   cout<<"Donde vives el dato del nodo?" <<&(A.m_Dato)<<endl;
  cout<<"Tamaño "<<sizeof(Nodo<int>)<<endl;
  cout<<"suma de variables "<<sizeof(int) + sizeof(Nodo<int>*)<<endl;*/


  return 1;
}
