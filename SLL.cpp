#include<iostream>
using namespace std;

class node
{
	public:
		
    int info;
	node* next;
	
		node(int n, node* p=0)
		{
			info=n;
			next=p;
		}
	//	friend class SLL;
};

class SLL
{
	node* head;
	node* tail;
	
	public:
		SLL();
		~SLL();
		
		void addtohead(int x);
		void addtotail(int x);
		void add(int x,int pos);
	    int delfromhead();
		int delfromtail();
		void del(int n);   //a particular element with value 'n' is to be deleted
		void display();
		
		void reversal();
		void concat(const SLL& l1);
		SLL operator+(const SLL& l1);
		void search(int x);
		void splitting(); 
		friend bool same(SLL l1,SLL l2);
};


SLL::SLL()
{
	head=NULL;
	tail=NULL;
}

SLL:: ~SLL()
{
	while(head!= NULL)
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
}

void SLL:: addtohead(int x)
{
	node* p=new node(x);;
	
	if(head == NULL)
	{
		head=tail=p;
	}
	else
	{
		p->next=head;
		head=p;
	}
}

void SLL::addtotail(int x)
{
	node* p=new node(x);
	
	if(head == NULL)
	{
		head=tail=p;
	}
	else
	{
		tail->next=p;
		tail=p;
	}
}

void SLL::add(int x,int pos)
{
	node* p=new node(x);
	
	if(pos == 1)
	{
//		p->next=head;
//		head=p;
//		if(tail == NULL)
//		{
//			tail=head;
//		}
       addtohead(x);
       return;
	}
	
	node* p1=head;
	for(int i=1;i<pos-1 && p1!=NULL;i++)
	{
		p1=p1->next;
	}
	
	if(p1 != NULL)
	{
		p->next=p1->next;
		p1->next=p;
		if(p->next == NULL)
		{
			tail=p;
		}
	}
	else
	{
//		tail->next=p;
//		tail=p;
        addtotail(x);
	}
}


int SLL::delfromhead()
{
	if(head == NULL)
	  throw "Exception Thrown";
	 
	node* p=head; 
	int x=p->info;
	if(head == tail)
	{
		head=tail=NULL;
		delete p;
	}  
	else
	{
		head=head->next;
		delete p;
	}
	
	return x;
}

int SLL::delfromtail()
{
	if(head == NULL)
	  throw "Exception Thrown";
	  
	if(head == tail)
	{
		node* p=head;            //p=tail;
		int x=p->info;
		head=tail=NULL;
		delete p;
		return x;
	} 
	else
	{
		node* p1=head;
		while( p1->next != tail) 
            p1=p1->next;
            
        node* p=tail;
		int x=p->info;
		p1->next=NULL;
		tail=p1;
		delete p;
		return x;    
  	} 
}

void SLL::del(int n)
{
	node* p=head;
	node* prev=NULL;
	
	while(p != NULL  && p->info != n)
	{
		prev=p;
		p=p->next;
	}
	
	if(p != NULL)
	{
		if(prev == NULL)
		  delfromhead();
		  
		else if(p->next == NULL)
		   delfromtail();
		   
		else
		{
		 	prev->next=p->next;
		 	delete p;
		}  
	}
	else
	  throw "Element Not Found";
}

void SLL::display()
{
	if(head == NULL)
	  throw"Exception Thrown";
	  
	cout<<"\nElements of the Linked List are : \n";
	node* p=head;
	while(p != NULL)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
}

void SLL::reversal()
{
	node* current=head;            //works with both (*this).head and head              //*this.head  dosen't works         
	node* prev=NULL;
	node* nex=NULL;
	
	while(current != NULL)
	{
		nex=current->next;
		current->next=prev;
		prev=current;
		current=nex;
	}
	head=prev;
}

void SLL::splitting()
{
	SLL le,lo;
	node* p=head;
	while(p != NULL)
	{
		if( (p->info)%2 == 0 )
		   le.addtotail(p->info);
		   
		else
		   lo.addtotail(p->info);
		       
		p=p->next;       
	}
	
	cout<<"\nList of Even Numbers : ";
	le.display();
	cout<<"\nList of Odd Numbers : ";
	lo.display();
}


bool same(SLL l1,SLL l2)
{
	node* p1=l1.head;
	node* p2=l2.head;
	bool flag=true;
	
	while(p1!=NULL  &&  p2!=NULL)
	{
		if(p1->info != p2->info)
		{
			flag=false;
			break;
		}
		  
     	p1=p1->next;
		p2=p2->next;  
	}
	 if( (p1==NULL && p2!=NULL)  ||   (p2==NULL && p1!=NULL) ) 
		   flag=false;
		   
	return flag;	   
}


void SLL::concat(const SLL& l1)
{
	node* p1=(*this).head;
	node* p2=l1.head;
	
	while(p1->next != 0)
	{
		p1=p1->next;
	}
	
	p1->next=p2;
}


SLL SLL::operator+(const SLL& l1)
{
	node* p1=head;              //(*this).head also works
	node* p2=l1.head;
	
	while(p1->next != 0)
	{
		p1=p1->next;
	}
	
	p1->next=p2;
	
	return (*this);
}


void SLL::search(int x)
{
	if(head == 0)
	  throw"\nEMPTY LIST\n";
	
	int count=1;  
	node* p=head;
	
	while(p != 0  &&  p->info != x)  
	{
		p=p->next;
		count++;
	}
	
	if(p != 0)
	  cout<<"\nElement found at node "<<count<<endl;
	  
    else
      cout<<"\nELEMENT NOT PRESENT IN THE LIST\n";
}

int main()
{
	int num;
	cout<<"Enter the number of elements : ";
	cin>>num;
	
	SLL l1;
	cout<<"\nEnter the elements :\n";
	for(int i=1;i<=num;i++)
	{
		int x;
		cin>>x;
		l1.addtotail(x);
	}
	l1.display();
	
//	int x;
//	cout<<"\nEnter the element to be searched : ";
//	cin>>x;
//	l1.search(x);
	
//	int x=l1.delfromtail();
//	l1.display();
	
//	cout<<"\nEnter the number of elements : ";
//	cin>>num;
//	
//	SLL l2;
//	cout<<"\nEnter the elements :\n";
//	for(int i=1;i<=num;i++)
//	{
//		int x;
//		cin>>x;
//		l2.addtotail(x);
//	}
	
//	l2.display();
//	
////	l1.concat(l2);
////	l1.display();
//
//    SLL l3=l1+l2;
//    l3.display();
	
//	bool ans=same(l1,l2);
//	if(ans == true)
//       cout<<"\nLists are Same ";
//    else
//	   cout<<"\nlists are Not Same ";   
	
//	int x,pos;
//	cout<<"\nEnter the element and the position : \n";
//	cin>>x;
//	cin>>pos;
//	l1.add(x,pos);

//   int x;
//   cout<<"\nEnter the element to be deleted : ";
//   cin>>x;
//   l1.del(x);
//   l1.display();

	l1.reversal();
	l1.display();

//    cout<<"\n\nSplitting of the Linked List : ";
//    l1.splitting();
//   
	
	return 0;
}

