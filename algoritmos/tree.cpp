#include<iostream>
#include<fstream>

using namespace std;

template<class T>
class Nodo
{
   public:
     T m_Dato;
     Nodo<T> * m_pSon[2];

     Nodo(T d)
     {
        m_Dato=d;
        m_pSon[0]=0;
        m_pSon[1]=0;
     }

};

template<class T>
class Tree
{
   private:
      Nodo<T> * m_pRoot;
      Nodo<T> * m_pCurrent;
   public:
      Tree():m_pRoot(0){};

////////////////////////////////////////////////////////////////////////////////////
//  Add_Recursivo

      void Add_r(T d, Nodo<T> *  & p)
      {
        if(!p)
        {
           p = new Nodo<T>(d); return;
        }
        else
            Add_r(d,p->m_pSon[p->m_Dato < d]);
      }

      Tree<T> & operator<<(T d)
      {
            Add_r(d,m_pRoot);
            //Add(d);
            return *this;
      }

      friend ostream & operator<<(ostream & os , Tree<T> & arb)
      {
           arb.print(arb.m_pRoot,os);
           return os;
      }

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//  PRINT

      void print(Nodo<T> * r, ostream & os)
      {
         if(!r) return;
         os<<r->m_Dato<<"::";
         print(r->m_pSon[0],os);
         print(r->m_pSon[1],os);
      }

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


    bool find_r(T d, Nodo<T> * p)
    {
        if(!p) return false;
        return (p->m_Dato==d) ? true : find_r(d, p->m_pSon[p->m_Dato < d]);
    }

    bool finded(T d)
    {
        return find_r(d, m_pRoot);
    }

    bool find(T d)
    {
        Nodo<T> * pTmp = m_pRoot;
        if(!pTmp)
        {
            return false;
        }
        while(pTmp)
        {
            if(pTmp->m_Dato==d)
            {
                return true;
            }
            pTmp = pTmp->m_pSon[pTmp->m_Dato<d];
        }
        return false;
    }
      // Aprender delete

      void Delete_one_Son(T d)
      {
          Nodo<T> * p = m_pRoot;
          Nodo<T> * q = m_pRoot;
          while(p)
          {
              if(p->m_Dato == d)
              {
                  if(p->m_pSon[0]==0 && p->m_pSon[1]!=0)
                  {
                      q->m_pSon[0] = p->m_pSon[1];
                      delete p;
                      return;
                  }
                  if(p->m_pSon[0]!=0 && p->m_pSon[1]==0)
                  {
                      q->m_pSon[0] = p->m_pSon[1];
                      delete p;
                      return;
                  }
              }
          }
          q = p;
          p = p->m_pSon[p->m_Dato < d];
      }

      void Delete_Hoja(T d)
      {
          Nodo<T> * p = m_pRoot;
          Nodo<T> * q = m_pRoot;
          while(p)
          {
              if(p->m_Dato==d)
              {
                  //si ese no es una hoja. entonces destruyela
                  if(p->m_pSon[0]==0 && p->m_pSon[1]==0)
                  {
                      delete p;
                      q->m_pSon[q->m_Dato < d] = 0;
                      return;
                  }
              }
              q = p;
              p = p->m_pSon[p->m_Dato < d];
          }
      }
      void Delete_2_Son(T d)
      {
          Nodo<T> * p = m_pRoot;
          Nodo<T> * q = m_pRoot;
          while(p)
          {
              if(p->m_Dato==d)
              {
                  //si ese no es una hoja. entonces destruyela
                  if(p->m_pSon[0]!=0 && p->m_pSon[1]!=0)
                  {
                      //Si tengo 2 hijos, entonces:
                      //Buscar el mayor de los menores de p
                      Nodo<T> * tmp = p->m_pSon[0];
                      while(tmp->m_pSon[1])
                        tmp = tmp->m_pSon[1];
                      swap(p->m_Dato, tmp->m_Dato);
                      //Falta eliminar el nodo tmp, pero cuidado con eliminar a sus hijos
                  }
              }
              q = p;
              p = p->m_pSon[p->m_Dato < d];
          }

      }
/*
      void Delete(T d)
      {
          while(p)
          {
              if(p->m_Dato == d)
              {
                  // caso hoja
                  // caso un hijo
                  // caso 2 hijos
              }
              q = p;
              p = p->m_pSon[p->m_Dato <  d];
          }
      }
*/
      //  Print
      void pre_order(Nodo<T> * p){ //Aldo Raul Martinez Choque
            if(p)
            {
                cout<<p->m_Dato<<" ";
                pre_order(p->m_pSon[0]);
                pre_order(p->m_pSon[1]);
            }
      }
        void post_order(Nodo<T> * p){ //Paolo Daniel Benavente
            if(p)
            {
                post_orden(p->m_pSon[0]);
                post_orden(p->m_pSon[1]);
                cout << p->m_Dato << " ";
            }
        }
      void in_order(Nodo<T> * p) //Eduardo Ruiz
      {
        if (!p) return;
		in_order(p->m_pSon[0]);
		cout << p->m_Dato << " ";
		in_order(p->m_pSon[1]);
      }

      // Print (sin usar recursión)
      void Print_Iterativo(Nodo<T> * p);

     /*
      Nodo<T> *   Previus();
      */


      /*Nodo<T>*Max() //Sebastian Agenor Zamalloa Molina
      {
        m_pCurrent = m_pRoot;
        while(m_pCurrent->m_pSon[1])
            m_pCurrent = m_pCurrent->m_pSon[1];
        return m_pCurrent;
      }
      Nodo<T>*Min() //Sebastian Agenor Zamalloa Molina
      {
        m_pCurrent = m_pRoot;
        while(m_pCurrent->m_pSon[0])
            m_pCurrent = m_pCurrent->m_pSon[0];
        return m_pCurrent;
      }
      Nodo<T>*Next() //Sebastian Agenor Zamalloa Molina
      {
        if(!m_pCurrent) m_pCurrent = m_pRoot;

        Nodo<T>*tmpMax = m_Current;
        if(tmpMax == Max()) return Min();
        m_Current = tmpMax;

        T date = m_pCurrent->m_Dato;
        while(m_pCurrent)
        {
            if(m_pCurrent->m_Dato > date) break;
            m_pCurrent = m_pCurrent->m_pSon[date >= m_pCurrent->m_Dato];
            if(!m_Current) m_Current = m_pRoot;
        }
        while(m_Current->m_pSon[0] && m_Current->m_pSon[0] != m_Current && m_Current->m_pSon[0]->m_Dato > date)
            m_Current = m_Current->m_pSon[0];
        return m_pCurrent;
      }
      */

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
      // Add Normal
      void Add(T d)
      {
        Nodo<T> * pTmp = m_pRoot;
        if(!pTmp) {m_pRoot = new Nodo<T>(d); return;}
        while(!(pTmp->m_pSon[0]==0 && pTmp->m_pSon[1]==0))
           pTmp->m_pSon[pTmp->m_Dato < d];
        pTmp->m_pSon[pTmp->m_Dato < d]= new Nodo<T>(d);
      }

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



};

int main()
{
    Tree<int> A;
    A<<3<<7<<98<<34<<56<<88;
    //A<<60<<20<<30<<10<<50<<40;
    cout<<"Imprimir: \n";
    cout<<A<<endl;
    cout<<A.finded(30);
    cout<<A.finded(34);
    cout<<endl;
    A.Delete_Hoja(88);
    cout<<A;

    return 0;

};

