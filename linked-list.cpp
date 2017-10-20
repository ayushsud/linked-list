#include <iostream>
using namespace std;
class node
{
    int data;
    int index;
    node *next;

public:
    node()
    {
        data = 0;
        next = 0;
    }

    void setdata(int data)
    {
        this->data = data;
    }

    int getdata()
    {
        return this->data;
    }

    void setindex(int a)
    {
        this->index = a;
    }

    int getindex()
    {
        return this->index;
    }

    node *getnext()
    {
        return this->next;
    }

    void setnext(node *ptr)
    {
        this->next = ptr;
    }
};

class linkedlist
{
    node *head;
    int totalnodes;

public:
    linkedlist()
    {
        head = 0;
        totalnodes = 0;
    }

    void add(int data)
    {
        totalnodes++;
        node *x = new node;
        x->setdata(data);
        x->setnext((node *)0);
        x->setindex(totalnodes);
        if (head == 0)
        {
            head = x;
            return;
        }
        node *ptr = head;
        while (ptr->getnext() != 0)
            ptr = ptr->getnext();
        ptr->setnext(x);
    }

    void clear()
    {
        if (head == 0)
            return;
        node *prev = head;
        node *ptr = head->getnext();
        while (ptr != 0)
        {
            delete prev;
            prev = ptr;
            ptr = ptr->getnext();
        }
        delete prev;
        head = 0;
    }

    int get(int index)
    {
        if (index > totalnodes)
            return -1;
        for (node *ptr = head; ptr != 0; ptr = ptr->getnext())
        {
            if (ptr->getindex() == index)
                return ptr->getdata();
        }
    }

    void insert(int data, int index)
    {
        if (index > totalnodes)
            return;
        totalnodes++;
        node *x = new node;
        x->setdata(data);
        x->setindex(totalnodes);
        if (index == 1)
        {
            x->setnext(head);
            if (head == 0)
            {
                head = x;
                return;
            }
            head->setnext(x);
            return;
        }
        if (head->getnext() == 0 && index == 2)
        {
            head->setnext(x);
            x->setnext((node *)0);
            return;
        }
        node *prev = head;
        node *ptr = head->getnext();
        while (ptr != 0)
        {
            if (ptr->getindex() == index)
            {
                x->setnext(prev->getnext());
                prev->setnext(x);
                return;
            }
            prev = ptr;
            ptr = ptr->getnext();
        }
    }

    bool isEmpty()
    {
        if (head == 0)
            return 1;
        return 0;
    }

    void remove(int index)
    {
        if (index > totalnodes)
            return;
        if (index == 1)
        {
            node *t = head;
            head = head->getnext();
            delete t;
            return;
        }
        node *ptr = head;
        node *prev = 0;
        while (ptr != 0)
        {
            if (ptr->getindex() == index)
            {
                node *t = ptr;
                prev->setnext(ptr->getnext());
                delete t;
                return;
            }
            prev = ptr;
            ptr = ptr->getnext();
        }
    }

    void set(int data, int index)
    {
        if (index > totalnodes)
            return;
        for (node *ptr = head; ptr != 0; ptr = ptr->getnext())
        {
            if (ptr->getindex() == index)
            {
                ptr->setdata(data);
                return;
            }
        }
    }

    void display()
    {
        node *ptr = head;
        while (ptr != 0)
        {
            cout << ptr->getdata() << endl;
            ptr = ptr->getnext();
        }
    }

    bool operator==(const linkedlist &x)
    {
        if (this->totalnodes != x.totalnodes)
            return 0;
        node *a = this->head;
        node *b = x.head;
        while (a != 0)
        {
            if (a->getdata() != b->getdata())
                return 0;
            a = a->getnext();
            b = b->getnext();
        }
        return 1;
    }

    bool operator!=(const linkedlist &x)
    {
        if (this->totalnodes != x.totalnodes)
            return 1;
        node *a = this->head;
        node *b = x.head;
        while (a != 0)
        {
            if (a->getdata() != b->getdata())
                return 1;
            a = a->getnext();
            b = b->getnext();
        }
        return 0;
    }

    void operator+(const linkedlist &x)
    {
        node *ptr = this->head;
        while (ptr->getnext() != 0)
            ptr = ptr->getnext();
        ptr->setnext(x.head);
    }

    void operator+=(const linkedlist &x)
    {
        node *ptr = this->head;
        while (ptr->getnext() != 0)
            ptr = ptr->getnext();
        ptr->setnext(x.head);
    }

    void operator+=(int x)
    {
        this->add(x);
    }

    int operator[](int x)
    {
        if (x > totalnodes)
            return -1;
        node *ptr = head;
        while (ptr != 0)
        {
            if (ptr->getindex() == x)
                return ptr->getdata();
            ptr = ptr->getnext();
        }
    }

    int size()
    {
        return totalnodes;
    }
};

int main()
{
    int n, t;
    linkedlist a, b;
    cout << "\tLinked List 1\n";
    cout << "Enter the number of elements\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << endl;
        cin >> t;
        a.add(t);
    }
    /*cout<<"\tLinked List 2\n";
cout<<"Enter the number of elements\n";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"Enter element "<<i+1<<endl;
cin>>t;
b.add(t);
}*/
    a.display();
}