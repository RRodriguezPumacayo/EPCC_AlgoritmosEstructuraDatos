#include<iostream>
using namespace std;

template<class T>
class Nodo
{
    public:
        T m_Dato;
        Nodo * m_pAnt;
    public:
        Nodo(T d)
        {
            m_Dato = d;
            m_pAnt = 0;
        }
};

//Stack = Pila
template<class T>
class Stack
{
    private:
        Nodo<T> * m_pTope;
    public:
        Stack()
        {
            m_pTope = 0;
        }
        void push(T d)
        {
            if(IsEmpty())
            {
                m_pTope = new Nodo<T>(d);
            }
            else
            {
                Nodo<T> * pNuevo = new Nodo<T>(d);
                pNuevo->m_pAnt = m_pTope;
                m_pTope = pNuevo;
            }
        }
        void pop()
        {
            if(IsEmpty()) return;
            Nodo<T> * tmp = m_pTope;
            m_pTope = m_pTope->m_pAnt;
            delete tmp;
        }
        void print()
        {
            Nodo<T> * tmp = m_pTope;
            while(tmp!=NULL)
            {
                cout<<tmp->m_Dato<<" -> ";
                tmp = tmp->m_pAnt;
            }
            cout<<"\n";
        }
        bool IsEmpty()
        {
            return m_pTope==0;
        }
        T top()
        {
            try
            {
                if(m_pTope->m_Dato>0 || m_pTope->m_Dato<0)
                {
                    return m_pTope->m_Dato;
                }
            }
            catch(...){
                return m_pTope->m_Dato;
            }
            return m_pTope->m_Dato;
        }
};

int main()
{
    Stack<int> A;
    A.push(10);
    A.push(20);
    A.push(30);
    A.print();
    A.pop();
    A.push(40);
    A.push(50);
    A.push(60);
    A.print();

    return 0;
}
