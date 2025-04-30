#ifndef TYPES_H
#define TYPES_H

#define SUCCESS 0
#define FAILURE -1

/*structure having variables used for storing operand and operator*/
typedef struct AP_calc
{
   char op1[100];
   int op1_len;

   char op2[100];
   int op2_len;

   char oper[10]; 
   int oper_len;
}Apc;

/*Linked list node structure*/
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

/*read and validate function for validating command line arguments*/
int read_validate(int argc,char *argv[], Apc *apc);

/*function to create the node*/
int create_node(Dlist **new,int data);

/*function to store the string in the linked list*/
int str_to_node(int len,char *operand,Dlist **head,Dlist **tail);

/*inserting the node to the linked list using insert at first*/
int insert_first(Dlist **head, Dlist **tail, int data);

/*function to print the list*/
void print_list(Dlist *head);

/*Operation function*/
int operation(Apc *apc,Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2);

/*function to perform addition*/
int addition(Dlist **t1,Dlist **t2,Dlist **reshead,Dlist **restail);

/*function to perform subtraction*/
int subtraction(Dlist **t1,Dlist **t2,Dlist **head1,Dlist **head2,Dlist **reshead,Dlist **restail);

/*function to perform multiplication*/
int multiplication(Dlist **t1, Dlist **t2, Dlist **head1, Dlist **head2,Dlist **head3,Dlist **tail3);

/*function to perform division*/
void division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **reshead,Dlist **restail);
#endif