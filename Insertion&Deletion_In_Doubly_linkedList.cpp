#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;

void insertion_beginning();
void insertion_last();
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void search();  
int main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insertion_beginning();  
            	break;  
            case 2:  
                    insertion_last();  
            	break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  

void insertion_beginning(){
	struct node *ptr;
	int item;
	ptr=(struct  node*)malloc(sizeof(struct node));
	
	if (ptr==NULL){
	printf("\nOVERFLOW \n");
	}
	else{
			printf("\nEnter the item to insert \n");
			scanf("\n%d",&item);
			
			if(head==NULL){
				ptr->next=NULL;
				ptr->prev=NULL;
				ptr->data=item;
				head=ptr;
			}
			else{
				ptr->data=item;
				ptr->prev=NULL;
				ptr->next=head;
				
				head->prev=ptr;
				head=ptr;
			}
			
				printf("\n Node inserted\n");
	}
}

void insertion_last(){
	struct node*ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
			printf("\nOVERFLOW \n");
	}
	else{
		printf("\nEnter item to insert \n");
		scanf("\n%d",&item);	
		if(head==NULL){
			ptr->next=NULL;
			ptr->prev=NULL;
			ptr->data=item;
			head=ptr;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
			
		}
	}
		printf("\nNode inseted at last  \n");
}

void insertion_specified(){
	struct node *ptr,*temp;
	int loc,item,i;
	ptr=(struct node *)malloc(sizeof(struct node));
	
	if(ptr==NULL){
			printf("\n OVERFLOW\n");
	}
	else{
			printf("\nEnter item to insert \n");
			scanf("\n%d",&item);
			printf("\n Enter location after which you want  to insert\n");
			scanf("\n%d",&loc);
			ptr->data=item;
			temp=head;
			for(i=0;i<loc;i++){
				temp=temp->next;
				if(temp==NULL){
						printf("\nList is small then location %d \n",loc);
						return;
				}
			}
			ptr->next=temp->next;
			temp->next->prev=ptr;
			temp->next=ptr;
			ptr->prev=temp;
			
				printf("\n Node inserted\n");
	}
}


void deletion_beginning(){
	struct node *ptr;
	if(head==NULL){
			printf("\n UNDERFLOW\n");
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
			printf("\n only node deleted \n");
	}
	else{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
			printf("\nNode deleted \n");
	}
}

void deletion_last(){
	struct node *ptr;
	if(head==NULL){
			printf("\n UNDERFLOW\n");
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
			printf("\nNode deleted \n");
	}
	else{
		ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		free(ptr);
		
			printf("\n Node deleted\n");
	}
}

void deletion_specified(){
	struct node *ptr,*temp;
	int val;
		printf("\nEnter value after which you want perforn deletion \n");
		scanf("\n%d",&val);
		ptr=head;
		while(ptr->data!=val){
			ptr=ptr->next;
		}
			if(ptr->next==NULL){
					printf("\n Cant delete \n");
			}
			else if(ptr->next->next==NULL){
				ptr->next=NULL;
			}
			else{
				temp=ptr->next;
				ptr->next=temp->next;
				temp->next->prev=ptr;
				free(temp);
					printf("\nNode Deleted \n");
			}
		}

void display(){
	struct node *ptr;
	printf("\nprinting values \n");
	ptr=head;
	while(ptr->next!=NULL){
			printf("%d\n",ptr->data);
			ptr=ptr->next;
	}
}

void search(){
	struct node *ptr;
	int item,i=0,flag;
	ptr=head;
	if(ptr==NULL){
			printf("\nEmpty list \n");
	}
	else{
			printf("\nEnter value to search \n");
			scanf("\n%d",&item);
			while(ptr->next!=NULL){
				if(ptr->data==item){
						printf("\n Item found at location %d\n",i+1);
						flag=0;
						break;
				}
				else{
					flag=1;
				}
				i++;
				ptr=ptr->next;
			}
			if(flag==1){
					printf("\nItem not Found \n");
			}
	}
	
}
		

