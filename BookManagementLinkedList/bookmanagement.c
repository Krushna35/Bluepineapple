#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char name[20];
	int ISBN;
	char author[20];
	float price;
}node;
typedef struct book
{
	node data;
	struct book *next,*prev;
}book;
book *curr,*head=NULL;

int insert()
{
	book *temp,*nn;
	int code;
	nn=(book*)malloc(sizeof(book));
	printf("\nEnter book name : ");
	scanf("%s",nn->data.name);
	printf("\nEnter book author : ");
	scanf("%s",nn->data.author);
	printf("\nEnter book ISBN : ");
	scanf("%d",&nn->data.ISBN);
	printf("\nEnter price for book : ");
	scanf("%f",&nn->data.price);
	nn->next=NULL;
	nn->prev=curr;
	curr->next=nn;
	curr=curr->next;
	head->data.ISBN++;
	return 1;
}	


void display()
{
	book *temp;

	for(temp=head->next;temp!=NULL;temp=temp->next)
		printf("\n\nBook Name = %s\n Author Name = %s\n ISBN=%d\n Price= %f Rs.",temp->data.name,temp->data.author,temp->data.ISBN,temp->data.price);
	printf("\nTotal Number of books are : %d",head->data.ISBN);
}
int delete()
{
	int flag=0;
	int code;
	book *temp;
	printf("\nEnter Book ISBN code which you want to delete : ");
	scanf("%d",&code);
	for(temp=head->next;temp!=NULL;temp=temp->next)
	{
		if(temp->data.ISBN==code)
		{
			flag=1;
			if(temp->next==NULL)
			{	(temp->prev)->next=NULL;
				free(temp);
				 head->data.ISBN--;
				 curr=head;
				return 1;
			}
			(temp->prev)->next=temp->next;
			(temp->next)->prev=temp->prev;
			free(temp);
			head->data.ISBN--;
		}
	}
	if(flag==0)
		printf("\nFor entered ISBN book is not available");

}
void search()
{
	int ch,code,flag=0;
	book *temp;
	char bname[20];
	printf("\n1.Seach by ISBN\t\t2.Search by Book Name\nEnter your choice : ");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("\nEnter Book ISBN code which you want to search : ");
		scanf("%d",&code);
		for(temp=head->next;temp!=NULL;temp=temp->next)
		{
			if(temp->data.ISBN==code)
			{
				printf("\n\nBook Name = %s\n Author Name = %s\n ISBN=%d\n Price= %f Rs.\nBook is available",temp->data.name,temp->data.author,temp->data.ISBN,temp->data.price);
				flag=1;
			}

		}
		if(flag==0)
			printf("\nFor entered ISBN book is not available");
	}
	else if(ch==2)
	{
		printf("\nEnter Book name which you want to search : ");
		scanf("%s",bname);
		for(temp=head->next;temp!=NULL;temp=temp->next)
		{
			if(strcmp(temp->data.name,bname)==0)
			{
				printf("\n\nBook Name = %s\n Author Name = %s\n ISBN=%d\n Price= %f Rs.\nBook is available",temp->data.name,temp->data.author,temp->data.ISBN,temp->data.price);
				flag=1;
			}
		}
		if(flag==0)
			printf("\nBook is not available");
	}
	else
		printf("\nWrong Choice");
}
void main()
{
	int ch,i;
	head=(book*)malloc(sizeof(book));
	head->data.ISBN=0;
	curr=head;
	do{
		printf("\n\t1.Insert\n\t2.Delete\n\t3.Search\n\t4.Display\n\tEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:i=insert(head);
			       break;
			case 2:i=delete();
			       break;
			case 3:search();
			       break;
			case 4:if(head->data.ISBN==0)
			           printf("\nNo Books");
			       else
				       display();
			       break;
		}
	}while(ch<5);
}
