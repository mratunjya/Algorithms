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
		friend class CLL;
};

class CLL
{
	node* tail;
	public:
		CLL();
		~CLL();
		void addtohead(int x);
		void addtotail(int x);
		int delfromhead();
		int delfromtail();
		void del(int x);
		void reverse();
		void search(int x);
		void display();
};

CLL::CLL()
{
	tail=NULL;
}

CLL:: ~CLL()
{
	node* p=tail->next;
	tail->next=NULL;          //we make this Singly Linked List 
	while(p != NULL)
	{
		node* temp=p;
		p=p->next;
		delete temp;
	}
} 

void CLL::addtohead(int x)
{
	node* p=new node(x);
	if(tail == 0)
    {
    	tail=p;
    	tail->next=tail;
	}
	else
	{
		p->next=tail->next;
		tail->next=p;
	}
}

void CLL::addtotail(int x)
{
	node*p=new node(x);
	if(tail == 0)
	{
		tail=p;
		tail->next=tail;
	}
	else
	{
		p->next=tail->next;
		tail->next=p;
		tail=p;
	}
}

int CLL::delfromhead()
{
	if(tail == 0)
	  throw "Exception Thrown";
	  
	node* p=tail->next;
	int x=p->info;
	if(tail == p)
	  tail=NULL;
	  
	else
	  tail->next=p->next;
	  
	delete p;
	return x;  
}

int CLL::delfromtail()
{
	if(tail == 0)
	  throw "Exception Thrown";
	 
    node* p=tail->next; 
    int x;
	if(tail == p)
	{
	   x=tail->info;
	   tail=NULL;	
	}  
	  
	  
	else
	{
		while(p->next != tail)
		  p=p->next;
		  
		tail=p;
		  p=p->next;             //pointing 'p' to the tail , as we always Delete 'p'
		tail->next=p->next;
		
		
//		node* p1=tail->next;
//		while(p1->next != tail)
//		{
//			p1=p1->next;
//	    }  
//	    
//	    p1->next=p->next;
//	    tail=p1;
	    
	}  
	
	x=p->info;
	delete p;
	return x;
}

void CLL::del(int x)
{
	node* p=tail;
	node* prev=NULL;
	
	if(p->info == x)
	{
		delfromtail();
		return ;
	}
	
	prev=p;                  //tail
	p=p->next;               //head
	while(p!= tail && p->info!= x)
	{
		prev=p;
		p=p->next;
	}  
	  
	if(p != tail)
	  prev->next=p->next;
	  
	else
	  throw "Element not in the list";
	  
	delete p;      
}

void CLL::reverse()
{
    node* head=tail->next;
    
    node* current=head;
    node* nex=NULL;
    node*  prev=NULL;
    do
    {
    	nex=current->next;
    	current->next=prev;
    	prev=current;
    	current=nex;
    	
	}while(current != head);
	
	head->next=prev;
	head=prev;
	tail=current;
}

void CLL::search(int x)
{
	if(tail == 0)
	  throw "Exception Thrown";
	  
	int count=1;
	node* p=tail->next;
	
	while(p != tail  &&  p->info != x) 
	{
		p=p->next;
		count++;
	} 
	
	if(p != tail)
	{
		cout<<"\nElement found at node "<<count<<endl;
	}
	else
	{
		if(p->info == x)
		{
			cout<<"\nElement found at node "<<count<<endl;
		}
		else
		{
			cout<<"\nELEMENT NOT PRESENT IN THE LIST\n";
		}
	}
}


void CLL::display()
{
	if(tail == NULL)
	  throw"Exception Thrown";
	  
	cout<<"\nElements of the Linked List are : \n";
	node* p=tail->next;
	while(p != tail)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
	cout<<tail->info;
}

int main()
{
	char ans='y';
	CLL c1;
	do
	{
	cout<<"---CIRCULAR LINKED LISTS---";
	cout<<"\n1. addtohead()";
	cout<<"\n2. addtotail()";
	cout<<"\n3. delfromhead()";
	cout<<"\n4. delfromtail()";
	cout<<"\n5. del()";
	cout<<"\n6. reversal()";
	cout<<"\n7. search()";
	cout<<"\n8. display()";
	cout<<"\nEnter the Choice : ";
	int ch;
	int num;
	cin>>ch;
	
	    switch(ch)
		{
			
			case 1:cout<<"\nEnter the no. of elements\n";
			       cin>>num; 
			       cout<<"\nEnter the elements :\n";
	                for(int i=1;i<=num;i++)
	               {
		              int x;
		              cin>>x;
	                  c1.addtohead(x);
	               }
	               break;
	               
	         case 2:cout<<"\nEnter the no. of elements\n";
			       cin>>num; 
				    cout<<"\nEnter the elements :\n";
	                for(int i=1;i<=num;i++)
	               {
		              int x;
		              cin>>x;
	                  c1.addtotail(x);
	               }
	               break;
				 	   
			case 3: c1.delfromhead();
			       cout<<"\nElement deleted  :\n";
	                c1.display();
	               break;	
				   
				   
			case 4:	c1.delfromtail();
			        cout<<"\nElement deleted :\n";
	                c1.display();
	               break;
				   
				   
			case 5:	int y;
	                cout<<"\nEnter the element to be deleted  :\n";
	                cin>>y;
	                c1.del(y);
	                cout<<"\nElement Deleted \n";
	                c1.display();
	               break;
				   
				   
			case 6:	c1.reverse();
	                cout<<"\nLinked List Reversed :\n";
	                c1.display();
	               break;
	               
	               
	       	case 7:	int x;
			        cout<<"\nEnter the element to be searched\n";
			        cin>>x;
			        c1.search(x);
	               break;       
				   
			case 8:	c1.display();
	               break;	   	   	   	      	   
				   	         
		}
		
	cout<<"\nDo you want to enter more ? (y/n) ";
	cin>>ans;
		
	}while(ans == 'y' ||  ans == 'Y');
	
	return 0;
}

