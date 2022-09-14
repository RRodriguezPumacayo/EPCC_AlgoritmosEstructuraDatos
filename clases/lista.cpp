#include<iostream>
using namespace std;

template<class T>
class Nodo
{

public:
	 T    m_Dato;
	 Nodo<T> * m_pSig;
	 Nodo<T> * m_pAnt;
  public:
	 Nodo(T d)
	 {
		 m_Dato = d;
		 m_pSig = 0;
		 m_pAnt = 0;
	 }
};

template<class T>
class ListaD
{

public:
	 Nodo<T> * m_pHead;
	 Nodo<T> * m_pLast;
   public:
	 ListaD()
	 {
		 m_pHead = m_pLast =0;
	 }

	 void Add_Last(T d)
	 {
		 //1. Crear un nodo}
		 Nodo<T> * pNuevo = new Nodo<T>(d);
		 // 2. si la lista está vacia
		 if (!m_pHead)
		   m_pHead = m_pLast = pNuevo;
		 else
		 {
			 m_pLast->m_pSig =pNuevo;
			 pNuevo->m_pAnt = m_pLast;
			 m_pLast = pNuevo;
		 }


	 }

	 void PrintR(Nodo<T> * p)
	 {
		 if(p==0) return;
		 cout<<p->m_Dato<<" ";
		 PrintR(p->m_pSig);
	 }

	 void Print()
	 {
		 Nodo<T> * tmp = m_pHead;
		 while(tmp!=0)
		 {
			 cout<<tmp->m_Dato<<endl;
			 tmp = tmp->m_pSig;
		 }
	 }

	 void RPrint()
		 {
			 Nodo<T> * tmp = m_pLast;
			 while(tmp!=0)
			 {
				 cout<<tmp->m_Dato<<endl;
				 tmp = tmp->m_pAnt;
			 }
		 }


	 void Add(T d, Nodo<T> * p)
	 {
		 // 1. caso base: Cuando no hay nodos
		 if(p==0)
		 {
			 m_pHead = m_pLast = new Nodo<T>(d);
			 return;
		 }
		 // Cuando hay nodos y estoy en el ultimo
		 if(p->m_pSig ==0)
		 {
			 Nodo<T> * nuevo  = new Nodo<T>(d);
			 p->m_pSig  = nuevo;
			 nuevo->m_pAnt = p;
			 m_pLast = nuevo;
			 return;
		 }
         // Si hay nodos trata de insertar en el siguiente
		 Add(d, p->m_pSig);
	 }

	 bool findR(T d, Nodo<T> * r)
	 {
		 if(r == 0){ return false;}
		 if(r->m_Dato == d){ return true;}
		 findR(d,r->m_pSig);
	 }


	 bool find(T d)
	 {
		 Nodo<T> * r = m_pHead;
		 while(r!=0)
		 {
			 if(r->m_Dato == d) return true;
			 r = r->m_pSig;
		 }
		 return false;
	 }

};


int main()
{
 ListaD<int> A;
 A.Add_Last(13);
 A.Add_Last(33);
 A.Add_Last(43);
 A.Add_Last(63);
 A.Add_Last(73);
 A.Add_Last(83);
 A.RPrint();
 
 
 
 
 
 
 return 1;
}
