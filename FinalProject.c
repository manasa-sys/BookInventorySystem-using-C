/***********************************
* Manasa Manohara Shetty
*book management system
* Date:29/04/2022
* final project
* *********************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct book{
    char isbn[50];
    char title[100];
    char authorname[50];
    char publisher[100];
    char genre[50];
    int year_of_pub;
    int amount_of_stock;
    float s_price;
}Book;

Book Books_array[500];
int k=0;
int j;

void enter_book(int i)
{
    printf("Enter a ISBN\n");
    scanf("%s",Books_array[i].isbn);
    fflush(stdin);

    printf("Enter a Title\n");
    fgets(Books_array[i].title,99,stdin);
    fflush(stdin);

    printf("Enter a Authorname\n");
    fgets(Books_array[i].authorname,49,stdin);
    fflush(stdin);

    printf("Enter the name of the publisher\n");
    fgets(Books_array[i].publisher,99,stdin);
    fflush(stdin);

    printf("Enter the type of Genre\n");
    fgets(Books_array[i].genre,49,stdin);
    fflush(stdin);

    printf("Enter the year of Publication\n");
    scanf("%d",&Books_array[i].year_of_pub);
    fflush(stdin);
    
    
    printf("Enter the amount of stock\n");  
    scanf("%d",&Books_array[i].amount_of_stock);
    fflush(stdin);
 
   
    printf("Enter the selling price\n"); 
    scanf("%f",&Books_array[i].s_price);
    fflush(stdin);
   
}
  
void prepulate_inventory()
{

    Book b1,b2,b3,b4,b5;
    
    strcpy(b1.isbn,"0063040883"); 
    strcpy(b1.title,"Women On Fire"); 
    strcpy(b1.authorname,"Lisa Barr" ); 
    strcpy(b1.publisher,"Harper Paperbacks"); 
    strcpy(b1.genre,"Art"); 
    b1.year_of_pub= 2022; 
    b1.amount_of_stock=20;
    b1.s_price=12.99;
    Books_array[0]=b1;
    k++;
   
    strcpy(b2.isbn,"0399180516"); 
    strcpy(b2.title,"Comedy Comedy Comedy Drama" ); 
    strcpy(b2.authorname,"Bob Odenkirk" ); 
    strcpy(b2.publisher,"Random House " ); 
    strcpy(b2.genre,"comedy"); 
    b2.year_of_pub= 2022;; 
    b2.amount_of_stock=10;
    b2.s_price=15.99;
    Books_array[1]=b2;
    k++;

    strcpy(b3.isbn,"0747532699");
    strcpy(b3.title,"Harry Potter" ); 
    strcpy(b3.authorname,"J.K.Rowling" ); 
    strcpy(b3.publisher,"Bloomsbury" ); 
    strcpy(b3.genre,"Fantasy" ); 
    b3.year_of_pub= 1997;
    b3.amount_of_stock=15;
    b3.s_price=20.00;
    Books_array[2]=b3;
    k++;

    strcpy(b4.isbn,"0-676-97376-0"); 
    strcpy(b4.title,"Life of Pi" ); 
    strcpy(b4.authorname,"Yann Martel" ); 
    strcpy(b4.publisher,"Knopf Canada" ); 
    strcpy(b4.genre,"Fiction" ); 
    b4.year_of_pub= 2009;
    b4.amount_of_stock=15;
    b4.s_price=12.50;
    Books_array[3]=b4;
    k++;

    strcpy(b5.isbn,"06-440055-7"); 
    strcpy(b5.title,"Charlotte's Web"); 
    strcpy(b5.authorname,"E.B.White"); 
    strcpy(b5.publisher,"Harper Collins"); 
    strcpy(b5.genre,"Children's Literature"); 
    b5.year_of_pub= 2012;
    b5.amount_of_stock=5;
    b5.s_price=13.50;
    Books_array[4]=b5;
    k++;  
}

void populate_inventory()
{
    int num;
    printf("enter the number of books you want to enter\n");
    scanf("%d", &num);
    for(int i=0; i<num; i++) 
    { 
        enter_book(k); 
        k++;
    }
}

void print_book(int index)
{ 
    
    printf("________________________________________________\n");

    printf("ISBN------------->%s\n", Books_array[index].isbn); 
    printf("TITLE------------>%s\n", Books_array[index].title); 
    printf("AUTHORNAME------->%s\n", Books_array[index].authorname); 
    printf("PUBLISHER-------->%s\n", Books_array[index].publisher); 
    printf("GENRE------------>%s\n", Books_array[index].genre); 
    printf("YEAROFPUB-------->%d\n", Books_array[index].year_of_pub); 
    printf("AMOUNT OF STOCK-->%d\n", Books_array[index].amount_of_stock); 
    printf("PRICE------------>%f\n", Books_array[index].s_price);

    printf("________________________________________________\n");

}

void search_record()
{
    char search_id[100];
    fflush(stdin);
    printf("Enter the keyword to search ----title or author name or genre or publisher\n");
    scanf("%[^\n]%*c", &search_id);
    printf("%s is the string",search_id);
    for(int i=0;i<k;i++)
    {
        if(strstr(Books_array[i].title,search_id)!=NULL || strstr(Books_array[i].authorname,search_id)!=NULL || strstr(Books_array[i].genre,search_id)!=NULL || strstr(Books_array[i].publisher,search_id)!=NULL){ 
            printf("book found\n");
            print_book(i);
            j=i;
            break;
        }
        else
        {
        printf("No match has been found,search by another keyword\n");
        }
    }
}
void returnbook()
{
    Books_array[j].amount_of_stock++;
    printf("The new stock amount is: %d\n",Books_array[j].amount_of_stock);
}

void purchasebook()
{
    if(Books_array[j].amount_of_stock >0)
    {
        Books_array[j].amount_of_stock--;
        printf("The number of books in stock are =%d\n",Books_array[j].amount_of_stock);
    }
}

void process_transaction()
{   
    bool isfound=1;
    int result;
    printf("Enter you choice(1-2):\n");
    printf("Enter 1-Return,2-purchase\n"); 
    scanf("%d",&result);
    search_record();
    if(isfound)
    {
        printf("You can process the transaction\n");
        switch(result)
        {
            case 1:
               {
                   returnbook();
                }
                break;
                
            case 2:
                {
                    purchasebook();
                }
                break;       
        }
    }
}

void delete_record()
{
    char isbn[30];
    printf("enter the isbn you want to search\n");
    fflush(stdin);
    scanf("%s", isbn);
    if(strstr(Books_array[j].isbn,isbn)!=NULL)
    {
        printf("Book is found at %d\n",j);
        for(int i=j;i<k;i++)
        {
            Books_array[i]=Books_array[i+1];
        }
        strcpy(Books_array[k-1].isbn," ");
        strcpy(Books_array[k-1].title," ");
        strcpy(Books_array[k-1].authorname," ");
        strcpy(Books_array[k-1].publisher," ");
        strcpy(Books_array[k-1].genre," ");
        Books_array[k-1].year_of_pub=0;
        Books_array[k-1].amount_of_stock=0;
        Books_array[k-1].s_price=0;
        k--;

    }
    printf("the book is removed from the stock:\n");
}

void display_books()
{
    for(int i=0;i<k;i++)
    {
        print_book(i);
    }
}

void exit_record()
{
    printf("Good Bye\n");
}

int main(){
    int choice;
    char ans; 
    prepulate_inventory();
    do{
        printf("  1:To populate a inventory\n"); 
        printf("  2:To search a book\n"); 
        printf("  3.To process a transaction\n"); 
        printf("  4.delete a record\n");
        printf("  5.display a record\n"); 
        printf("  6.Exit\n\n\n");
        do{
            printf("Enter your choice(1-6)\n: ");
            scanf("%d",&choice);
            if(choice<1 || choice>6)
            printf("Invalid option. Please try again.\n\n"); 
        }while(choice<1 || choice>6);
        switch(choice)
        {
        case 1:
        {
            populate_inventory();
            break;
        }
        case 2:
        {
            search_record();
            break;
        } 
        case 3:
        {
            process_transaction();
            break;
        }
        case 4:
        {
            delete_record();
            break;
        }
        case 5:
        {
            display_books();
            break;
        }
        case 6:
        {
            exit_record();
            break;
        }
        }
        printf("do you want perform any action again(y/n)?:\n");
        scanf("%s", &ans);
    }while(ans=='Y' || ans=='y');
return 0;  
}

