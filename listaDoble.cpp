#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Nodo
{
    public:
        T m_Dato;
        Nodo * m_pSig;
        Nodo * m_pAnt;
    public:
        Nodo(T d)
        {
            m_Dato = d;
            m_pSig = m_pAnt = 0;
        }
};

template<class T>
class Lista
{
    private:
        Nodo<T> * m_pHead;
        Nodo<T> * m_pLast;
        Nodo<T> * m_pCurrent;
    public:
        Lista()
        {
            m_pHead = m_pLast = 0;
        }
        void push_front(T d)
        {
            if(!m_pHead)
                m_pHead = m_pLast = new Nodo<T>(d);
            else
            {
                Nodo<T> * pNew = new Nodo<T>(d);
                pNew->m_pSig = m_pHead;
                m_pHead->m_pAnt = pNew;
                m_pHead = pNew;
            }
        }
        void push_back(T d)
        {
            if(!m_pHead)
                m_pHead = m_pLast = new Nodo<T>(d);
            else
            {
                Nodo<T> * pNew = new Nodo<T>(d);//pNew;
                m_pLast->m_pSig = pNew; //pNew;
                pNew->m_pAnt = m_pLast;
                m_pLast = pNew;
            }
        }
        void push(int p, T d);
        /*
        {
            if(!m_pHead)
                m_pHead = m_pLast = new Nodo<T>(d);
            else
            {
                Nodo<T> * pNew = new Nodo<T>(d);//pNew;
                m_pLast->m_pSig = pNew; //pNew;
                pNew->m_pAnt = m_pLast;
                m_pLast = pNew;
            }
        }
        */
        void pop_front()
        {
            if(!m_pHead) return;
            if(!m_pHead->m_pSig)
            {
                delete m_pHead;
                m_pHead = m_pLast = 0;
                return;
            }
            m_pHead = m_pHead->m_pSig;
            delete m_pHead->m_pAnt;
            m_pHead->m_pAnt = 0;
        }
        void pop_back();
        void pop(int p, T d);
        bool find(T d, Nodo<T> * &p)
        {
            for(p = m_pHead; p; p=p->m_pSig)
                if(p->m_Dato == d) return true;
            return false;
        }

        bool find_r(T d, Nodo<T> * &p)
        {
            for(p = m_pLast; p; p=p->m_pAnt)
                if(p->m_Dato == d) return true;
            return false;
        }
        void print(ostream & os)
        {
            for(p = m_pHead; p; p=p->m_pSig)
                os<<p->m_Dato<<"-->"<<endl;
            os<<endl;

        }

        //****************************//
        //          ITERATOR          //
        void begin(m_pCurrent = m_pHead);
        void end(m_pCurrent = m_pLast);
        void operator++()
        {
            if(m_pCurrent->m_pSig)
                m_pCurrent = m_pCurrent->m_pSig;
        }

        bool terminate()
        {

        }

        void operator--()
        {
            if(m_pCurrent->m_pAnt)
                m_pCurrent = m_pCurrent->m_pAnt;
        }
        T GetData()
        {
            try
            {
                return m_pCurrent->m_Dato;
                throw exception;
            }
            catch()
            {
                cout<<"Tu puntero current es null";
            }
        }
        //****************************//

};

int main()
{
    ofstream("File.txt");
    Lista<int> A;
    A.push_front(20);
    A.push_front(30);
    A.push_front(40);
    A.push_front(50);
    A.print(cout);

    for(A.begin(); A.Terminate(); A++)
    {
        cout<<A.GetData();
    }

    return 0;
}
