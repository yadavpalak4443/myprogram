//deletion at last in dll
#include<stdio.h>
#include<malloc.h>
struct node{
	int item;
	struct node*prev;
	struct node*next;
};
struct node*start=NULL;
void deletion_at_last(){
	if(start==NULL){
		printf("List is empty");
		return;
	}
	else{
		struct node*temp=start;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	printf("The deletion value is: %d \n",temp->item);
	free(temp);
}
}
void insert_value(int value){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->item=value;
	newnode->prev=NULL;
	newnode->next=NULL;
	
	if(start==NULL){
		start=newnode;
		return;
	}
	struct node*temp=start;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
    newnode->prev=temp;
}
void display(){
	struct node*temp=start;
	while(temp!=NULL){
		printf("%d<->",temp->item);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main(){
	int n,value;
	printf("enter the length of node:");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		printf("enter the value of node %d:",i+1);
		scanf("%d",&value);
		insert_value(value);
	}
	display();
	deletion_at_last();
	display();
	return 0;
}
