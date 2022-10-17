 #include <iostream>
 
using namespace std;
struct node{
    int data;
    node *link;
};
class linkedlist     
{
    node*start;
    public:
    linkedlist()
    {
        start=NULL;
    }
    void append(int num);
    void addatbeg(int);
    int count();
    void addafter(int , int);
    void display();
    void del(int);
    void addat(int,int);
    void deletelele(int);
    int search(int);
    ~linkedlist();
};
int linkedlist ::search(int num)
{   
    int counte=1,flag=0;
    if(start==NULL)
        cout<<"linked list is empty";
    else{
        node*t=start;
        while(t!=NULL)
        {
            if(t->data==num)
            {
                cout<<"element found at "<<counte<<" position"<<endl;
                return 1;
            }
            counte++;
            t=t->link;
        }
        cout<<"element not found"<<endl;
}
}
linkedlist:: ~linkedlist()
{
    node *temp;
    while(start!=NULL)
    {
        temp=start;
        start=start->link;
        delete temp;
    }
}
void linkedlist::addat(int l,int num)
{
    node * temp=new node;
    node *t;
    temp->data=num;
    temp->link=NULL;
    t=start;
    if(start==NULL && l>0)
        cout<<"list has no elements";
    else if(l<=0 )
        cout<<"enter valid location";
    else
    {   
        if (l==1)
        {
            temp->link=start;
            start=temp;
        }
        else
        {
            for(int i=1;i<l-1;i++)
            {
                t=t->link;
                if(t==NULL)
                {
                    cout<<"there are less elements";return;}

            }
            temp->link=t->link;
            t->link=temp;
        }
    }
}
void linkedlist :: del(int num)
{
    node *t;
    t=start;int flag=0;
    if(t==NULL)
    {
        cout<<"linked list is empty"<<endl;
        return;
    }
    if(t->data==num)
    {
        cout<<"deleted element = "<<t->data<<endl;
        start=start->link;
        delete t;
        return;
    }
    while(t!=NULL)
    {
        if(t->link->data==num)
        {
            node *todel;
            todel=t->link;
            t->link=t->link->link;
            cout<<"deleted element = "<<todel->data<<endl;
            delete todel;
            flag=1;
            break;
        }
        t=t->link;
    }
    if(flag==0)
        cout<<"element not found"<<endl;

    
    // while(t!=NULL)
    // {
    //     if(t->data==num)
    //     {
    //         if(t==start)
    //         {
    //             start=t->link;
    //         }
    //         else
    //         {
    //             prev->link=t->link;
    //         }
    //         cout<<"deleted element is "<<t->data<<endl;
    //         delete t;
    //         flag=1;
    //         break;
    //     }
    //     else{
    //         prev=t;
    //         t=t->link;
    //     }
    // }
}
void linkedlist::append(int num)
{
    node*temp=new node;
    temp->data=num;
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }  
    else
    {
        node*t; 
        t=start;
        while(t->link!=NULL)
        t=t->link;
        t->link=temp;
    }
}
void linkedlist :: addafter(int loc,int num)
{
    node *temp=new node;
    temp->data=num;
    temp->link=NULL;
    node *t;
    t=start;
    for (int i=1;i<loc;i++)
    {
        t=t->link;
        if(t==NULL)
        {
            cout<<"there are less elements"<<endl;
            return;
        }
    }
    temp->link=t->link;
    t->link=temp;
    
}
void linkedlist :: addatbeg(int num)
{
    node*temp=new node;
    temp->data=num;
    temp->link=start;
    start=temp;
}
int linkedlist::count()
{   
    int counter=0;
    if(start==NULL)
        return counter;
    else{
        node*t=start;
        while(t!=NULL)
        {
            counter++;
            t=t->link;
        }
}
return counter;
}

void linkedlist::display()
{
    if(start==NULL)
    cout<<"linked list is empty";
    else{
        node*t=start;
        while(t!=NULL)
        {
            cout<<t->data<<endl ;
            t=t->link;
        }
}
}
void linkedlist ::deletelele(int loc)
{
    node*t,*temp;
    t=start;
    if(start==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    if(loc==1){
        cout<<"deleted element ="<<start->data<<endl;
        start=start->link;
        return;
    }
    for(int i=1;i<loc-1;i++)
    {
        t=t->link;
        if(t==NULL)
        {
            cout<<"location exceeds"<<endl;
            return;
        }
    }
    temp=t->link;
    cout<<"deleted element ="<<temp->data<<endl;
    t->link=temp->link;
    delete temp;

}

//example of functions output for different conditions

int main()
{
    linkedlist l; 
    l.append(1);
    l.addatbeg(7);
    l.addafter(2 ,100);
    l.display();
    l.append(3);
    l.addat(2,88);
    cout<<"no of elements = "<<l.count();
    cout<<endl<<endl<<endl;
    l.del(100);
    l.display();
    l.del(1);
    l.display();
    l.search(3);
    l.deletelele(3);
    l.display();
    // l.del(888);
    // l.display();
    // cout<<"no of elements = "<<l.count()<<endl;
    // l.addat(2,5);
    // l.display();
    // cout<<"no of elements = "<<l.count()<<endl;

}

