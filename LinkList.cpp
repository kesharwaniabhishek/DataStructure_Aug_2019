// LinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class List
{
private:
   struct node
   {
      int data;
      node* next;
   } *first;
public:
   List()
   {
      first = NULL;
   }
   ~List()
   {
      node* p, *q;
      p = first;
      if(first==NULL)
         return;
      while(p!=NULL)
      {
         q= p->next;
         delete p;
         p = NULL;
         p = q;
      }
   }
   void Add(int val)
   {
        if(first==NULL)
        {
           first = new node();
           first->data = val;
           first->next = NULL;
        }
        else
        {
          node* p;
          p = first;
          while(p->next!=NULL)
             p = p->next;
          node* q = new node();
          q->data = val;
          q->next = NULL;
          p->next = q;

        }
   }
   void Display()
   {
        node* p = first;
        while(p!=NULL)
        {
           printf("%d\n",p->data);        
           p = p->next;
        }
   }
   void Del(int val)
   {
       node* p,*q;

       p = first;
       if(p->data==val)
       {
          q= p->next;
          delete p;
          p = NULL;
          first = q;
          return;
       }
       while(p!=NULL)
       {
          
          if(p->data==val)
          {
             q->next=p->next;
             delete p;
             p= NULL;
             break;
          }
          q=p;
          p = p->next;
       }
   }
   void insertAfter(int after, int val)
   {
       node*p,*q;
       p = first;
       if(p->data == after)
       {
         q= new node();
         node* temp= p->next;
         p->next = q;
         q->next = temp;
         q->data = val;
         return;
       }

       while(p!=NULL)
       {
          if(p->data==after)
          {
             q  = new node();
             node* temp= p->next;
             p->next = q;
             q->next = temp;
             q->data = val;
          }
          p = p->next;
       }
   }
   void reverse()
   {
      /*node*  p = first;
      if(p!=NULL)
      {
         if(p->next!=NULL)
         {
            while(p->next!=NULL)
            {
               node * temp = new node();
               temp->data = p->data;
               p->data = p->next->data;
               p->next->data = temp->data;

               p = p->next;
            }
         }
      }
      return ;
   }*/

   node * prev = NULL;
   node * next;
   node * current = first;
   while(current!=NULL)
   {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;

   }
   first = prev;
   }

   int FindMiddle()
   {
     node *p1,*p2;

     p1=p2=first;

     while((p2!=NULL)&&(p1!=NULL))
     {
               
        p2= p2->next;
        if(p2!=NULL)
        {
           p2 = p2->next;
        }
        else
        {
            break;
        }
        p1 = p1->next;  
        
     }

     return p1->data;
   
   }

   int FindNthElementFromLast(int n)
   {   
      node *p1,*p2;
      p1= first;
      p2= first;
      for(int i=0;i<n;i++)
      {
         p2= p2->next;
         if(p2==NULL)
         {
            printf("Less number of elements");
            return -1;
         }
      }
      while(p2!=NULL)
      {
         p1=p1->next;
         p2=p2->next;      
      }

      return p1->data;
    
   }
   void Reverse2()
   {
      node* current= first;
	  node	*next = NULL;
      node  *prev = NULL;
	  while(current!=NULL)
	  {
		  next = current->next;
		  current->next = prev;
		  prev = current;
		  current = next;

	  }
	  first = prev;
   }
};


int _tmain(int argc, _TCHAR* argv[])
{
	
   List l;
   l.Add(1);
   l.Add(2);
   l.Add(3);
   l.Add(4);
   l.Add(5);
   l.Add(6);
   l.Add(7);
   printf("Mid of list %d\n",l.FindNthElementFromLast(7));
   
   //l.insertAfter(3,4);
   //l.Reverse2();
   //l.Display();
   getchar();
   return 0;
}

