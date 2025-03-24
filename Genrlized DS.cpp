#include<iostream>
using namespace std;

template<class T>
struct nodeSL
{
    T data = 0;
    struct nodeSL *next;
};

template<class T>
class SinglyLL
{
    public:
        struct nodeSL<T> * head;
        int icount;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtpos(T no,int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

template<class T>
SinglyLL<T>:: SinglyLL()
{
    head = NULL;
    icount = 0;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeSL<T>  * newn = NULL;

    newn = new nodeSL<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    icount++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeSL<T>  * newn = NULL;
    struct nodeSL<T>  * temp = NULL;

    newn = new nodeSL<T> ;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next !=NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        
    }
    icount++;
}

template<class T>
void SinglyLL<T> :: InsertAtpos(T no,int ipos)
{
    int  i = 0;
    struct nodeSL<T>  * newn = NULL;
    struct nodeSL<T>  * temp = NULL;

    if((ipos<1) || (ipos > icount+1))
    {
        cout<<"Invalid Postion"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == icount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeSL<T>;

        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i=1;i<ipos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

    }
    icount++;
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct nodeSL<T>  * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        temp = head;

        head = head->next;
        delete(temp);
    }
    icount--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    
    struct nodeSL<T>  * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next !=NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next =NULL;
    }
    icount--;
}

template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    int  i = 0;
    struct nodeSL<T>  * target = NULL;
    struct nodeSL<T>  * temp = NULL;

    if((ipos<1) || (ipos > icount))
    {
        cout<<"Invalid Postion"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == icount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i=1;i<ipos-1;i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete(target);
        
    }
    icount--;

}

template<class T>
void SinglyLL<T> :: Display()
{
    struct nodeSL<T>  * temp = head;

    cout<<"Elements of LinkedList are: \n";

    while(temp !=NULL)
    {
        cout<<"| "<<temp->data<<" | ->";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template<class T>
int SinglyLL<T> :: Count()
{
    return icount;
}

template<class T>
struct nodeDL
{
    int data;
    struct nodeDL *next;
    struct nodeDL *prev;
};


template<class T>
class DoublyLL
{
    public:
        struct nodeDL<T>* head;
        int icnt;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);     
        void InsertAtPos(T no,int ipos);       
        void DeleteFirst();      
        void DeleteLast();       
        void DeleteAtpos(int ipos);       
        void Display();
        int Count();
        

};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    head = NULL;
    icnt = 0;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeDL<T>* newn = NULL;

    newn = new nodeDL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    icnt++;
}

template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeDL<T>* newn = NULL;
    struct nodeDL<T>* temp = NULL;

    newn = new nodeDL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
        
    }
    icnt++;
    
}

template<class T>
void DoublyLL<T> :: InsertAtPos(T no,int ipos)
{
    int i = 0;
    struct nodeDL<T>* newn = NULL;
    struct nodeDL<T>* temp = NULL;

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == icnt+1 )
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeDL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;

        for(i=1;i<ipos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
    icnt++;
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    struct nodeDL<T>* temp = NULL;

    temp = head;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        head = temp->next;
        head->prev = NULL;

        delete(temp);
    }
    icnt--;
}

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct nodeDL<T>* temp = NULL;


    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;

    }
    icnt--;
}

template<class T>
void DoublyLL<T> :: DeleteAtpos(int ipos)
{
    int i = 0;
    struct nodeDL<T>* temp = NULL;
    struct nodeDL<T>* target = NULL;

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == icnt)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i=1;i<ipos-1;i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev =temp;
        
        delete(target);
        
    }
    icnt--;
}

template<class T>
void DoublyLL<T> :: Display()
{
    struct nodeDL<T>* temp = head;

    cout<<"Elements of LinkedList are: \n";

    while(temp !=NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
    return icnt;
}

#include<iostream>
using namespace std;

template<class T>
struct nodeCL
{
    int data;
    struct nodeCL *next;
};

template<class T>
class SinglyCL
{
    public:
        struct nodeCL<T>* head;
        struct nodeCL<T>* tail;
        int icnt;

        SinglyCL(); 
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtpos(T no,int ipos);
        void DeleteAtpos(int ipos);

};

template<class T>
SinglyCL<T> :: SinglyCL()
{
    head = NULL;
    tail = NULL;
    icnt = 0;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{ 
    struct nodeCL<T>* newn = NULL;

    newn = new nodeCL<T>;

    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
        tail->next = head;
    }
    else
    {
        newn->next = head;
        head = newn;
        tail->next = head;
    }

    icnt++;
}

template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeCL<T>* newn = NULL;

    newn = new nodeCL<T>;

    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
        tail->next = head;
    }
    else
    {
        tail->next = newn;
        tail = newn;
        newn->next = head;
    }

    icnt++;
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((head == NULL) && (tail== NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail->next = head->next;
        delete(head);
        head = tail->next;
    }
    
    icnt--;
}

template<class T>
void SinglyCL<T> :: DeleteLast()
{ 
    struct nodeCL<T>* temp = NULL;

    if((head == NULL) && (tail== NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;

        while(temp->next !=tail)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = head;
        tail = temp;
    }
    
    icnt--;
}

template<class T>
void SinglyCL<T> :: Display()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"linkedlist is empty: "<<"\n";
    }

    cout<<"Elements of linkedlist are: "<<"\n";

    do
    {
        cout<<"|"<<head->data<<"|->";
        head = head->next;
    }while(head !=tail->next);

    cout<<"\n";
}

template<class T>
int SinglyCL<T>:: Count()
{ 
    return icnt;
}

template<class T>
void SinglyCL<T> :: InsertAtpos(T no,int ipos)
{
    int i = 0;
    int iCountnode = 0;
    iCountnode = Count();

    if((ipos<1) || (ipos>iCountnode+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    struct nodeCL<T>* temp = NULL;
    struct nodeCL<T>* newn = NULL;

    newn = new nodeCL<T>;
    newn->data = no;
    newn->next = NULL;

    temp = head;

    for(i=1;i<ipos-1;i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;

    icnt++;
}

template<class T>
void SinglyCL<T> :: DeleteAtpos(int ipos)
{ 
    int i = 0;
    int iCountnode = 0;
    iCountnode = Count();

    if((ipos<1) || (ipos>iCountnode))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    struct nodeCL<T>* temp = NULL;
    struct nodeCL<T>* target = NULL;

    temp = head;

    for(i=1;i<ipos-1;i++)
    {
        temp = temp->next;
    }

    target = temp->next;
    temp->next = target->next;
    delete(target);

    icnt--;
}

template<class T>
struct nodeDCL
{
    int data;
    struct nodeDCL* next;
    struct nodeDCL* prev;
};


template<class T>
class DoublyCL
{
    public:
        struct nodeDCL<T>* head;
        struct nodeDCL<T>* tail;
        int icnt;

        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);

};


template<class T>
DoublyCL<T> :: DoublyCL()
{
    head =  NULL;
    tail = NULL;
    icnt = 0;
}

template<class T>
void DoublyCL<T> ::  InsertFirst(T no)
{ 
    struct nodeDCL<T>* newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        tail->next = newn;
        newn->prev = tail;

        head = newn;
    }

    icnt++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{ 
    struct nodeDCL<T>* newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;
        newn->next = head;
        head->prev = newn;

        tail = newn;
    }

    icnt++;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{ 
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        
        tail->next = head->next;
        head->next->prev = tail;
        delete(head);
        head = tail->next;
    }
    icnt--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct nodeDCL<T>* temp = NULL;

        temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = head;
        head->prev = temp;

        tail = temp;
    }
    icnt--;
}

template<class T>
void DoublyCL<T> :: Display()
{
    cout<<"Element of linked list are: "<<"\n";

    do
    {
        cout<<"|"<<head->data<<"|->";
        head = head->next;
    }while(head != tail->next);

    cout<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
    return icnt;
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no,int ipos)
{

    struct nodeDCL<T>* temp = NULL;
    struct nodeDCL<T>* newn = NULL;
    int Countnode = 0;
    int i = 0;

    Countnode = Count();

    if ((ipos<1) || (ipos>Countnode+1))
    {
        cout<<"Invalid Position";
        return;
    }
    

    newn = new nodeDCL<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Countnode+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = head;

        for(i=1;i<ipos-1;i++)
        {
            temp = temp->next;
        }

        newn->next= temp->next;
        temp->next = newn;
        newn->next->prev = newn;
        newn->prev = temp; 
    }

    icnt++;
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    struct nodeDCL<T>* temp = NULL;
    struct nodeDCL<T>* target = NULL;
    int Countnode = 0;
    int i = 0;

    Countnode = Count();

    if ((ipos<1) || (ipos>Countnode))
    {
        cout<<"Invalid Position";
        return;
    }
    

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Countnode)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i=1;i<ipos-1;i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete(target);
    }

    icnt--;
    
}

#include<iostream>
using namespace std;

template<class T>
struct nodeST
{
    int data;
    struct nodeST *next;
};

template<class T>
class Stack
{
    public:
        struct nodeST<T>* head;
        int icnt;

        Stack();
        void push(T no);
        int pop();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    head = NULL;
    icnt = 0;
}

template<class T>
void Stack<T> :: push(T no)
{ 
    struct nodeST<T>* newn = NULL;

    newn = new nodeST<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head =newn;
    }

    icnt++;
}

template<class T>
int Stack<T>  :: pop()
{
    int ino = -1;
    struct nodeST<T>* temp = NULL;

    if(head == NULL)
    {
        cout<<"Stack is empty";
        return -1;
    }
    else if(head->next == NULL)
    {
        ino = head->data;
        delete(head);
        head = NULL;
    }
    else
    {
        ino = head->data;
        temp = head;
        head = head->next;
        delete(temp);
    }

    icnt--;
    return ino;
}

template<class T>
void Stack<T>  :: Display()
{
    cout<<"Elemnets of stack are: \n";

    struct nodeST<T>* temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp -> next;
    }

    cout<<"\n";
}

template<class T>
int Stack<T> :: Count()
{ 
    return icnt;
}     

#include<iostream>
using namespace std;

template<class T>
struct nodeQU
{
    int data;
    struct nodeQU *next;
};

template<class T>
class Queue
{
    public:
        struct nodeQU<T>* head;
        int icnt;

        Queue();
        void enqueue(T no);
        int dequeue();
        void Display();
        int Count();  
};

template<class T>
Queue<T> :: Queue()
{
    head = NULL;
    icnt = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)
{ 
    struct nodeQU<T>* newn = NULL;
    struct nodeQU<T>* temp = NULL;

    newn = new nodeQU<T>;

    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        
    }

    icnt++;
}

template<class T>
int Queue<T> :: dequeue()
{
    int ino = -1;
    struct nodeQU<T>* temp = NULL;

    if(head == NULL)
    {
        cout<<"queue is empty";
        return -1;
    }
    else if(head->next == NULL)
    {
        ino = head->data;
        delete(head);
        head = NULL;
    }
    else
    {
        ino = head->data;
        temp = head;
        head = head->next;
        delete(temp);
    }

    icnt--;
    return ino;
}

template<class T>
void Queue<T> :: Display()
{
    cout<<"Elemnets of queue are: \n";

    struct nodeQU<T>* temp = head;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp -> next;
    }

    cout<<"\n";
}

template<class T>
int Queue<T> :: Count()
{ 
    return icnt;
}  

int main()
{
    


    
    return 0;
}