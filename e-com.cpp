#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct Product
{
 int id;
 string name;
 double price;

 Product*next;
 Product*hashNext;
};

Product*head=NULL;
const int SIZE=10;
Product*hashTable[SIZE]={NULL};

int hashFunction(int id)
{
 return id%SIZE;
}

void addProduct()
{
 Product*p=new Product;
 cout<<"enter product id:";
 cin>>p->id;


 int index=hashFunction(p->id);
 
 Product*temp=hashTable[index];

 while(temp!=NULL)
 {
  if(temp->id==p->id)
  {
   cout<<"Product  id already exits\n:";
   delete p;
   return;
  }
  temp=temp->hashNext;
 }
 cin.ignore(numeric_limits<streamsize>::max(),'\n');
 
 cout<<"enter product name:";

 getline(cin,p->name);

 cout<<"enter price";

 cin>>p->price;

 p->next=head;

 head=p;

 p->hashNext=hashTable[index];

 hashTable[index]=p;

 cout<<"new product added succesfully!!";
}


void displayProduct
}
{
 Product*temp=head;
 
 if(temp==NULL)
 {
  cout<<"product is out of stock!!\n";
  return;
 }

 cout<<"---all prouct records---";
 while(temp!=NULL)
 {
  cout<<"Product id:"<<temp->id<<endl;
  cout<<"name:"<<temp->name<<endl;
  temp=temp->next;
 }
}


Product*searchProduct(int id)
{
 int index=hashFUNCTION(id);

 Product*temp=hashTable[imdex];
 
 while(temp!=NULL)
}
 {
  if(temp->==id)
    return temp;

  temp=temp->next;
 }
 return NULL;
}

//update product
void updateProduct()
{
 int id;

 cout<<"enter product id to update";
 cin>>id;

 Product*p=searchProduct(id);

 if(p==NULL)
 {
  cout<<"Product Not Found!\n";
  return;
 }

 cout<<"enter new product";
 cin>>ws;
 getline(cin,p->name);

 cout<<"enter new price";
 cin>>p->price;

 cout<<"product updated succesfully!";
}

int main()
{
 int choice;

 do
 {
}
   cout<<"\n====E-COMMERCE INVENTORY SYSTEM====\n";
   cout<<"1.ADD PRODUCT\n";
   cout<<"2.UPDATE PRODUCT\n";
   cout<<"3.SEARCH PRODUCT\n";
   cout<<"4.DISPLAY ALL PRODUCTS\n";
   cout<<"5.EXIT\n";

   cout<<"enter your choice:";
   cin>>choice;


   switch(choice)
   {
    case 1:
      addProduct();
      break;

    case 2:
      updateProduct;
      break;

    case 3:
    {
     int id;
     cout<<"enter Product id:";
     cin>>id;
    
     Product*p=searchProduct(id);
    
     if(p!=NULL)
     {
      cout<<"PRODUCT FOUND!\n";
      cout<<"name"<<p->name<<endl;
      cout<<"price"<<p->price<<endl;
     }
     else
      cout<<"Product not Found!\n";
    
    break;
    }

   case 4:
     displayProduct();
     break;
 
  default:
     cout<<"Invalid choice!\n";
   }
 }while(choice!=6);

  for(int i=0;i<SIZE;i++)
  {
   Product*temp=hashTable[i];
   
   while(temp!=NULL)
   {
    Product*del=temp;
    temp=temp->next;
    delete del;
   }
  }
 
 return 0;
}
