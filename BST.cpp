#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class tnode
{
	public:
		int data;
		tnode* lchild;
		tnode* rchild;
		
		tnode(int n,tnode* l=0,tnode* r=0)
		{
			data=n;
			lchild=l;
			rchild=r;
		}
};

class BST
{
	tnode* root;
	
	void preorder(tnode*);
	void postorder(tnode*);
	void inorder(tnode*);
	int height(tnode* p);
	int countNode(tnode* p);
	int countLeaf(tnode* p);
	int countNonLeaf(tnode* p);
	void mirror(tnode* p);
	
	public:
		BST()
		{
			root=0;
		}
		
		void insert(int x);                 //of the type '* &'
		void delete_by_copying(int x);
		void delete_by_merging(int x);
		void preorder();
		void postorder();
		void inorder();
		void preorder_iterative();
		void inorder_iterative();
		int minimum();
		int maximum();
		void height();
		void countNode();
		void countLeaf();
		void countNonLeaf();
		void mirror();
		int* search(int x);            //recursive approach is also there
		void level_by_level();            
};

//insert
void BST::insert(int x)
{
	tnode* p=new tnode(x);
	if(root == 0)
	{
		root=p;
		return;
	}
	
	tnode* q=root;
	tnode* fq=0;                //father node of 'q'
	
	while(q != 0  &&  q->data != x)
	{
		fq=q;
		if(x < q->data)
		{
			q=q->lchild;
		}
		else
		   q=q->rchild;
	}
	
	if(q != 0)
	   throw"Duplicate Value";
	   
	if( fq->data < x)
	   fq->rchild=p;
	   
	else
	  fq->lchild=p;      
}

//recursive preorder
void BST::preorder(tnode* r)
{
	if(r == 0)
      return;
    
	cout<<r->data<<" ";  
    preorder(r->lchild);
	preorder(r->rchild);  
}

//recursive indorder
void BST::inorder(tnode* r)
{
	if(r == 0)
	  return;
	  
	inorder(r->lchild);
	cout<<r->data<<" ";
	inorder(r->rchild);  
}

//recursive postorder
void BST::postorder(tnode* r)
{
	if(r == 0)
	  return;
	  
	postorder(r->lchild);
	postorder(r->rchild);
	cout<<r->data<<" ";  
}

void BST::preorder()
{
	preorder(root);
}

void BST::inorder()
{
	inorder(root);
}

void BST::postorder()
{
	postorder(root);
}

//finding the minimum element
int BST::minimum()
{
	if(root == 0)
	  throw"Empty Tree";
	  
	tnode* p=root;
	while(p->lchild != 0)
	   p=p->lchild;
	   
	return p->data;    
}

//finding the maximum element
int BST::maximum()
{
	if(root == 0)
	  throw"Empty Tree";
	  
	tnode* p=root;
	while(p->rchild != 0)
	  p=p->rchild;
	  
	return p->data;    
}

//Deletion by Copying
void BST::delete_by_copying(int x)
{
	if(root == 0)
	  throw"Empty Tree";
	  
	tnode* p=root;
	tnode* fp=0;
	
	while(p != 0  &&  p->data != x)
	{
		fp=p;
		if(x < p->data)
		  p=p->lchild;
		  
		else
		  p=p->rchild;  
	}  
	if(p == 0)
	  throw"Element not present";
	  
    bool lchild;
    
	if(fp != 0)
	  lchild=(x < fp->data)?true:false;
	  
	  
	//if deleted node is a leaf
	if( (p->lchild == 0) && (p->rchild == 0))
	{
		if(fp == 0)
		{
			root=0;
			return;
		}
		if(lchild)
		  fp->lchild=0;
		
		else
		  fp->rchild=0;  
	}  	  
	else if(p->rchild == 0)      //if deleted node has lchild only
	{
		if(fp == 0)
		{
			root=p->lchild;
			return;
		}
		if(lchild)
		  fp->lchild=p->lchild;
		  
		else
		  fp->rchild=p->lchild;  
	}
	else if(p->lchild == 0)     //if deleted node has rchild only
	{
		if(fp == 0)
		{
			root=p->rchild;
			return;
		}
		if(lchild)
		  fp->lchild=p->rchild;
		  
		else
		  fp->rchild=p->rchild;  
	}
	else                         //if both the children exists 
	{
		tnode* q=p->rchild;
		tnode* fq=p;
		while(q->lchild != 0)
		{
			fq=q;
			q=q->lchild;
		}
		p->data=q->data;
		if(q->data < fq->data)
		   fq->lchild=q->rchild;
		
		else
		  fq->rchild=q->rchild;
		  
		delete q;     
	}
}

//Deletion by Merging
void BST::delete_by_merging(int x)
{
	if(root == 0)
	  throw"Empty tree";
	  
	tnode* p=root;
	tnode* fp=0;
	
	while(p !=0  &&  p->data != x)
	{
		fp=p;
		if(x < p->data)
		  p=p->lchild;
		  
	    else
		  p=p->rchild;	  	
	}  
	
	if(p == 0)
	   throw "Element not present";
	   
	bool lchild;
    
	if(fp != 0)
	  lchild=(x < fp->data)?true:false;
	  
	  
	//if deleted node is a leaf
	if( (p->lchild == 0) && (p->rchild == 0))
	{
		if(fp == 0)
		{
			root=0;
			return;
		}
		if(lchild)
		  fp->lchild=0;
		
		else
		  fp->rchild=0;  
	}  	  
	else if(p->rchild == 0)      //if deleted node has lchild only
	{
		if(fp == 0)
		{
			root=p->lchild;
			return;
		}
		if(lchild)
		  fp->lchild=p->lchild;
		  
		else
		  fp->rchild=p->lchild;  
	}
	else if(p->lchild == 0)     //if deleted node has rchild only
	{
		if(fp == 0)
		{
			root=p->rchild;
			return;
		}
		if(lchild)
		  fp->lchild=p->rchild;
		  
		else
		  fp->rchild=p->rchild;  
	} 
	else                       //if both the children exists
	{
		tnode* q=p->lchild;
		tnode* rc=p->rchild;           //right child of 'p'
		
		while(q->rchild != 0)
		{
			q=q->rchild;
		}
		q->rchild=rc;
		
		if(fp == 0)
		  root=p->lchild;
		 
	    else
		{
			if(p->data < fp->data)
			  fp->lchild=p->lchild;
			  
			else
			 fp->rchild=p->lchild;  
		}
		
		delete p;	  
	} 
}

//height of the binary search tree
int BST::height(tnode* p)
{
	if(p == 0)
	  return -1;
	  
	else if(p->lchild == 0  &&  p->rchild == 0)
	  return 0;
	  
	else
	{
		int hl=height(p->lchild);
		int hr=height(p->rchild);
		int max=hl>hr?hl:hr;
		return(max+1);
	}    
}

void BST::height()
{
	int h=height(root);
	cout<<"Height of Tree = "<<h;
}

//total nodes in the tree
int BST::countNode(tnode* p)
{
	if(p==0) 
	  return 0;
	  
	return(( 1+countNode(p->lchild)+countNode(p->rchild) ) );   
}

void BST::countNode()
{
	int count=countNode(root);
	cout<<"Total Nodes = "<<count;
}

//number of leaf nodes
int BST::countLeaf(tnode* p)
{
	if(p == 0) 
	   return 0;
	   
	if(p->lchild == 0  &&  p->rchild == 0)
	   return 1;
	   
	return( countLeaf(p->lchild)+countLeaf(p->rchild) );  
}

void BST::countLeaf()
{
	int count=countLeaf(root);
	cout<<"Leaf Nodes = "<<count;
}

//number of Non Leaf nodes
int BST::countNonLeaf(tnode* p)
{
	if(p == 0) 
	  return 0;
	  
	if(p->lchild == 0  &&  p->rchild == 0)
	  return 0;
	  
	return( 1+countNonLeaf(p->lchild)+countNonLeaf(p->rchild) );  
}

void BST::countNonLeaf()
{
	int count=countNonLeaf(root);
	cout<<"Non Leaf Nodes = "<<count;
}

//creating mirror image of the tree
void BST::mirror(tnode* node)
{
	if(node==0)
	   return;
	else
	{
	 tnode* temp;
	 mirror(node->lchild);
	 mirror(node->rchild);
	 temp=node->lchild;
	 node->lchild=node->rchild;
	 node->rchild=temp;	
	}   
}

void BST::mirror()
{
	mirror(root);
}

//searching a particular element
int* BST::search(int x)
{
	
      tnode* p=root;
	  while(p != 0)
	  {   
	     if(x == p->data)
	         return &p->data;
	         
		 else if(x < p->data)
		    p=p->lchild;
		    
		 else
		    p=p->rchild;		
	  }
	  return 0;	
}

//level by level traversal
void BST::level_by_level()
{
	queue<tnode*> q;
	tnode *p=root;
	if(p!=0)
	{
		q.push(p);                             //push=enQueue
		while(!q.empty())
		{
			p=q.front();                      //front=returns the front element
			q.pop();                          // pop=deQueue  , but here deQueue returns void
			cout<<p->data<<" ";
			
			if(p->lchild != 0)
			   q.push(p->lchild);
			   
			if(p->rchild != 0)
			   q.push(p->rchild);   
			   
		}
	}
}

//iterative preorder
void BST::preorder_iterative()
{
	stack<tnode*> s;
	tnode* p=root;
	do
	{
		while(p!=0)
		{
			s.push(p);
			cout<<p->data<<" ";
			p=p->lchild;
		}
		
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			p=p->rchild;	
		}
		
	}while(p!=0  ||  !s.empty() );
}

//iterative inorder
void BST::inorder_iterative()
{
	stack<tnode*> s;
	tnode* p=root;
    do
	{
	    while(p!=0)
	    {
	    	s.push(p);
	    	p=p->lchild;
		}
		
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			cout<<p->data<<" ";
			
			p=p->rchild;
		}
		
	}while(p!=0  ||  !s.empty() );
}


int main()
{
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(30);	
	b.insert(4);
	b.insert(7);	
	b.insert(20);
	b.insert(40);
	
	b.preorder();
	int max=b.maximum();
	int min=b.minimum();
	cout<<endl<<max<<" "<<min;
	cout<<endl;
	
	b.height();
	cout<<endl;
	b.countNode();
	cout<<endl;
	b.countLeaf();
	cout<<endl;
	b.countNonLeaf();
	
	cout<<endl;
	b.level_by_level();
	cout<<endl;
	int* a=b.search(5);
	cout<<*a<<endl;
	
//	b.mirror();
//	b.preorder();
//	b.mirror();

    b.preorder_iterative();
    cout<<endl;
    b.inorder_iterative();
	
	return 0;
}

