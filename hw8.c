#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	char color;
	struct node* A;
	struct node* B;
	struct node* C;
	struct node* D;
};
struct node;
typedef struct node Node;
typedef Node* Nodeptr;
Nodeptr create(char name);
void insert(Nodeptr *head);
void merge(Nodeptr *h1,Nodeptr *h2);
void printlist(Nodeptr *head);
void plus(Nodeptr *head,int num);
void delete(Nodeptr *head);
int time=0,count=0,total=0,number=1024;
char word,trash;
int main(){
	scanf("%d\n",&time);
	for(int q=0;q<time;q++){
		Nodeptr map1=NULL;
		Nodeptr map2=NULL;
		Nodeptr head=NULL;
		scanf("%c",&word);
		map1=create(word);
		if(word=='p'){
			insert(&map1);	
		}
		//printlist(&map1);
		//printf("\n");
		scanf("%c%c",&trash,&word);
		map2=create(word);
		if(word=='p'){
			insert(&map2);
		}
		//printlist(&map2);
		//printf("\n");
		scanf("%c",&trash);
		if(map1->color=='p'&&map2->color=='p'){
			merge(&map1,&map2);
			head=map1;
		}
		else if(map1->color=='f')
			head=map1;
		else if(map2->color=='f')
			head=map2;
		//printlist(&map1);
		//printf("\n");
		if(map1->color=='f'){
			total=1024;
		}
		else if(map1->color=='p'){
			plus(&map1,number/4);
		}
		printf("There are %d black pixels.\n",total);
		total=0;
		delete(&map1);
		delete(&map2);
	}
	return 0;
}
void insert(Nodeptr *head){
	Nodeptr temp=NULL;
	scanf("%c",&word);
	temp=create(word);
	(*head)->A=temp;
	//printf("A %c\n",(*head)->A->color);
	if(word=='p'){
		//printf("1\n");
		insert(&temp);
	}
	scanf("%c",&word);
	temp=create(word);
	(*head)->B=temp;
	//printf("B %c\n",(*head)->B->color);
	if(word=='p'){
		//printf("2\n");
		insert(&temp);
	}
	scanf("%c",&word);
	temp=create(word);
	(*head)->C=temp;
	//printf("C %c\n",(*head)->C->color);
	if(word=='p'){
		//printf("3\n");
		insert(&temp);
	}
	scanf("%c",&word);
	temp=create(word);
	(*head)->D=temp;
	//printf("D %c\n",(*head)->D->color);
	if(word=='p'){
		//printf("4\n");
		insert(&temp);
	}
	return ;
}
void merge(Nodeptr *h1,Nodeptr *h2){
	//printf("%c %c\n",(*h1)->A->color,(*h2)->A->color);
	//printf("%c %c\n",(*h1)->B->color,(*h2)->B->color);
	//printf("%c %c\n",(*h1)->C->color,(*h2)->C->color);
	if((*h1)->A->color=='p'&&(*h2)->A->color=='p')
		merge(&((*h1)->A),&((*h2)->A));
	if((*h1)->A->color=='e'&&(*h2)->A->color=='p')
		(*h1)->A=(*h2)->A;
	if((*h1)->A->color=='e'&&(*h2)->A->color=='f')
		(*h1)->A=(*h2)->A;
	if((*h1)->A->color=='p'&&(*h2)->A->color=='f')
		(*h1)->A=(*h2)->A;
	
	if((*h1)->B->color=='p'&&(*h2)->B->color=='p')
		merge(&((*h1)->B),&((*h2)->B));
	if((*h1)->B->color=='e'&&(*h2)->B->color=='p')
		(*h1)->B=(*h2)->B;
	if((*h1)->B->color=='e'&&(*h2)->B->color=='f')
		(*h1)->B=(*h2)->B;
	if((*h1)->B->color=='p'&&(*h2)->B->color=='f')
		(*h1)->B=(*h2)->B;

	if((*h1)->C->color=='p'&&(*h2)->C->color=='p')
		merge(&((*h1)->C),&((*h2)->C));
	if((*h1)->C->color=='e'&&(*h2)->C->color=='p')
		(*h1)->C=(*h2)->C;
	if((*h1)->C->color=='e'&&(*h2)->C->color=='f')
		(*h1)->C=(*h2)->C;
	if((*h1)->C->color=='p'&&(*h2)->C->color=='f')
		(*h1)->C=(*h2)->C;

	if((*h1)->D->color=='p'&&(*h2)->D->color=='p')
		merge(&((*h1)->D),&((*h2)->D));
	if((*h1)->D->color=='e'&&(*h2)->D->color=='p')
		(*h1)->D=(*h2)->D;
	if((*h1)->D->color=='e'&&(*h2)->D->color=='f')
		(*h1)->D=(*h2)->D;
	if((*h1)->D->color=='p'&&(*h2)->D->color=='f')
		(*h1)->D=(*h2)->D;

	return;
}
void plus(Nodeptr *head,int num){
	if((*head)->A->color=='f')
		total+=num;
	if((*head)->A->color=='p')
		plus(&((*head)->A),num/4);
	
	if((*head)->B->color=='f')
		total+=num;
	if((*head)->B->color=='p')
		plus(&((*head)->B),num/4);
	
	if((*head)->C->color=='f')
		total+=num;
	if((*head)->C->color=='p')
		plus(&((*head)->C),num/4);
	
	if((*head)->D->color=='f')
		total+=num;
	if((*head)->D->color=='p')
		plus(&((*head)->D),num/4);

	return;
}
Nodeptr create(char name){
	Nodeptr ptr = malloc(sizeof(Node));
	ptr->color=name;
	ptr->A=NULL;
	ptr->B=NULL;
	ptr->C=NULL;
	ptr->D=NULL;
	return ptr;
}
void printlist(Nodeptr *head){
	if(*head!=NULL){
		printf("%c",(*head)->color);
		printlist(&((*head)->A));
		printlist(&((*head)->B));
		printlist(&((*head)->C));
		printlist(&((*head)->D));
	}
	return;
}
void delete(Nodeptr *head){
	(*head)->A=NULL;
	(*head)->B=NULL;
	(*head)->C=NULL;
	(*head)->D=NULL;
	return;
}
	/*	if(*head!=NULL){
		delete(&((*head)->A));
		delete(&((*head)->B));
		delete(&((*head)->C));
		delete(&((*head)->D));
		printf("%c",(*head)->color);
		free(*head);
		}*/
