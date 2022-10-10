/*
Si la Resta de las alturas de las raices de los arboles es <= 1, entonces esta equilibrado
*/
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
class Nodo
{
    public:
        T m_Dato;
        Nodo * m_pSon[2];

        Nodo(T d)
        {
            m_Dato = d;
            m_pSon[0] = 0;
            m_pSon[1] = 0;
        }
};

template<typename T>
class Tree
{
    private:
        Nodo<T> * m_pRoot;
        Nodo<T> * m_pCurrent;
    public:
        Tree(){
            m_pRoot = 0;
        }
        void add(T d, Nodo<T> *& p)
        {
            if(!p)
            {
                p = new Nodo<T> (d);
                return;
            }
            add(d, p->m_pSon[p->m_Dato < d]);
        }

        Tree<T> & operator>>(T d)
        {
            add(d, m_pRoot);
            return *this;
        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////
        void print(Nodo<T> * r, ostream & os)
        {
            if(!r)
                return;
            os<<r->m_Dato<<" :: ";
            print(r->m_pSon[0], os);
            print(r->m_pSon[1], os);
        }

        friend ostream & operator <<(ostream & os, Tree<T> & arb)
        {
            arb.print(arb.m_pRoot, os);
            return os;
        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

        void printRDD()
        {
            Nodo<T> * pTmp = m_pRoot;
            while(pTmp->m_pSon[0]!=0 && pTmp->m_pSon[1]!=0)//Mientras el nodo izquierdo y el nodo derecho no sean igual a 0
            {
                cout<<pTmp->m_Dato<<"::"<<endl;
                pTmp->m_pSon[pTmp->m_Dato < 1];
            }
        }

        void RDD(Nodo<T> * & p)
        {
            Nodo<T> * q = p->m_pSon[1];
            p->m_pSon[1] = q->m_pSon[0];
            q->m_pSon[0] = p;
            p->FE = q->FE = 0;
            p = q;
        }

        void RII(Nodo<T> * & p)
        {
            Nodo<T> * q = p->m_pSon[0];
            p->m_pSon[0] = q->m_pSon[1];
            q->m_pSon[1] = p;
            p->FE = q->FE = 0;
            p = q;
        }

        void RS(Nodo<T> *& p, bool d)
        {
            Nodo<T> *q = p->m_pSon[d];
            p->m_pSon[d] = q->m_pSon[!d];
            q->m_pSon[!d] = p;
            p->FE = q->FE = 0;
            p = q;
        }

        void RID(Nodo<T> *& p)
        {
            Nodo<T> * q = p->m_pSon[0];
            Nodo<T> * r = q->m_pSon[1];

            q->m_pSon[1] = r->m_pSon[0];
            p->m_pSon[0] = r->m_pSon[1];

            r->m_pSon[0] = q;
            r->m_pSon[1] = p;

            switch(r->FE)
            {
                case 0:
                    r->FE = p->FE = q->FE=0;
                    break;
                case -1:
                    break;
                case 1:
                    break;
            }
        }
        void RDI(Nodo<T> *& p)
        {
            Nodo<T> * q = p->m_pSon[1];
            Nodo<T> * r = q->m_pSon[0];

            q->m_pSon[0] = r->m_pSon[1];
            p->m_pSon[1] = r->m_pSon[0];

            r->m_pSon[1] = q;
            r->m_pSon[0] = p;

            switch(r->FE)
            {
                case 0:
                    r->FE = p->FE = q->FE=0;
                    break;
                case -1:
                    break;
                case 1:
                    break;
            }
            p = r;
        }
        // 10 50 3 70 90 85 62 5 1
        // 4 13 11 73 91 84 61

};

int main()
{
    Tree<int> A;
    A>>2>>3>>5>>6>>7;
    cout<<A;
    A.printRDD();
    return 1;
}
