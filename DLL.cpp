#include<iostream>
using namespace std;

class dllnode
{
	public:
		
    int info;
    dllnode* next;
	dllnode* prev;
	
		dllnode(int x, dllnode* n=NULL, dllnode* p=NULL)
		{
			info=x;
			next=n;
			prev=p;
		}
		friend class DLL;
};

class DLL
{
	dllnode* head;
	dllnode* tail;
	
	public:
		DLL();
		~DLL();
		
		void addtohead(int x);
		void addtotail(int x);
		void add(int x,int pos);
		int delfromhead();
		int delfromtail();
		void del(int x);
		void display();
		void reverse();
		void search(int x);
};

DLL::DLL()
{
	head=NULL;
	tail=NULL;
}

DLL:: ~DLL()
{
	while(head!= NULL)
	{
		dllnode* temp=head;
		head=head->next;
		delete temp;
	}
}

void DLL::addtohead(int x) 
{
	dllnode* p=new dllnode(x,head,0);
	
	if(head == NULL)
	  head=tail=p;
	  
	else
	{
		head->prev=p;
		head=p;
	}  
}

void DLL::addtotail(int x)
{
	dllnode* p=new dllnode(x,0,tail);
	
	if(head == NULL)
	  head=tail=p;
	  
	else
	{
		tail->next=p;
		tail=p;
	}  
}

void DLL::add(int x,int pos)
{
	dllnode* p=new dllnode(x);
	
	if(pos == 1)
	{
		addtohead(x);
		return;
	}
	
	dllnode* p1=head;
	for(int i=1;i<pos-1 && p1!=NULL;i++)
	{
		p1=p1->next;
	}
	
	if(p1 != NULL)
	{
		p->next=p1->next;
		p->prev=p1;
		p1->next=p;
		//dllnode* nex=p1->next;
		//nex->prev=p;
		if(p->next == NULL)
		{
			tail=p;
		}
	}
	else
	{
		addtotail(x);
	}
}

int DLL::delfromhead() 
{
	if(head == NULL)
	 throw "Exception Thrown";
	 
	dllnode* p=head;
	int x=p->info;
	
	if(head == tail)
	  head=tail=NULL;
	  
	else
	{
		head=head->next;
		head->prev=NULL;
	}   
	
	delete p;
	return x;
}

int DLL::delfromtail()
{
	if(head == NULL)
	  throw "Exception Thrown";
	  
	dllnode* p=tail;
	int x=p->info;
	
	if(head == tail)
	  head=tail=NULL;
	  
	else
	{
		tail=p->prev;
		tail->next=NULL;
	}    
	
	delete p;
	return x;
}

void DLL::del(int x)
{
	dllnode* p=head;
	
	while(p!=NULL && p->info!=x)
	  p=p->next;                    //use prev as well 
	                                //so we have     prev , p , p1  
	if(p == NULL)
	  throw "Element is not present in the list";
	  
	if(p == head)
	  delfromhead();
	  
	else if(p == tail)
	  delfromtail();
	  
	else
	{
		dllnode* pre=p->prev;
		dllnode* nex=p->next;
		pre->next=nex;
		nex->prev=pre;
	}       
	delete p;
}

void DLL::display()
{
	if(head == NULL)
	  throw"Exception Thrown";
	  
	cout<<"\nElements of the Linked List are : \n";
	dllnode* p=head;
	while(p != NULL)
	{
		cout<<p->info<<" ";
		p=p->next;
	}
}

void swap(int & a,int & b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void DLL::reverse()
{
	dllnode* p1=head;
	dllnode* p2=tail;
	while(p1!=p2 && p2->next!=p1)
	{
		swap(p1->info,p2->info);
		p1=p1->next;
		p2=p2->prev;
	}
}


void DLL::search(int x)
{
	if(head == NULL)
	  throw"Exception Thrown";
	  
	int count=1;
	dllnode* p = head;
	
	while(p != NULL  &&  p->info != x)
	{
		p=p->next;
		count++;
	}
	
	if(p != NULL)
	{
		cout<<"\nElement found at node "<<count<<endl;
	} 
	else
	{
		cout<<"\nELEMENT NOT PRESENT IN THE LIST\n";
	}
}


int main()
{
	char ans='y';
	DLL d1;
	do
	{
	cout<<"---DOUBLY LINKED LISTS---";
	cout<<"\n1. addtohead()";
	cout<<"\n2. addtotail()";
	cout<<"\n3. add()";
	cout<<"\n4. delfromhead()";
	cout<<"\n5. delfromtail()";
	cout<<"\n6. del()";
	cout<<"\n7. reversal()";
	cout<<"\n8. search()";
	cout<<"\n9. display()";
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
	                  d1.addtohead(x);
	               }
	               break;
	               
	         case 2:cout<<"\nEnter the no. of elements\n";
			       cin>>num; 
				    cout<<"\nEnter the elements :\n";
	                for(int i=1;i<=num;i++)
	               {
		              int x;
		              cin>>x;
	                  d1.addtotail(x);
	               }
	               break;
				   
				   
			case 3:	int x,pos;
			        cout<<"\nEnter the element and the position \n";
			        cin>>x;
			        cin>>pos;
			        d1.add(x,pos);
	               break;
				   
				   
			case 4: d1.delfromhead();
			       cout<<"\nElement deleted  :\n";
	                d1.display();
	               break;	
				   
				   
			case 5:	d1.delfromtail();
			        cout<<"\nElement deleted :\n";
	                d1.display();
	               break;
				   
				   
			case 6:	int y;
	                cout<<"\nEnter the element to be deleted  :\n";
	                cin>>y;
	                d1.del(y);
	                cout<<"\nElement Deleted \n";
	                d1.display();
	               break;
				   
				   
			case 7:	d1.reverse();
	                cout<<"\nLinked List Reversed :\n";
	                d1.display();
	               break;
	               
	        case 8: int z;
			       cout<<"\nEnter the element to be searched : ";
				   cin>>z;
				   d1.search(z);
				   break;        
				   
			case 9:	d1.display();
	               break;	   	   	   	      	   
				   	         
		}
		
	cout<<"\nDo you want to enter more ? ";
	cin>>ans;
		
	}while(ans == 'y' ||  ans == 'Y');
	
	return 0;
}
