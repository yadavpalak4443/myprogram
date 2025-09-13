//remove duplicate numbers in sl
#include<stdio.h>
#include<stdlib.h>
struct node{
	int item;
	struct node*next;
};
struct node*start=NULL;
void remove_duplicate(){
	if(start==NULL){
		printf("list is empty");
		return;
	}
	else{
		struct node*temp=start;
		while(temp!=NULL && temp->next!=NULL){
			if(temp->item==temp->next->item){
			struct node*dup=temp->next;
			temp->next=temp->next->next;
			free(dup);	
			}
			else{
			temp=temp->next;
		}
	}
	printf("the non duplicate elments are:\n");	
}
}
void insert_value(int value){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->item=value;
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
}
void display(){
	struct node*temp=start;
	while(temp!=NULL){
		printf("%d->",temp->item);
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
	remove_duplicate();
	display();
	return 0;
}
