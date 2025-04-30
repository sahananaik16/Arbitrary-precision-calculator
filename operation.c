#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"apc_header.h"

/* Function to perform the specified arithmetic operation on two double linked lists */
int operation(Apc *apc, Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    /* Initialize pointers to the tails of the lists */
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    
    /* Initialize result list head and tail pointers to NULL */
    Dlist *reshead = NULL;
    Dlist *restail = NULL;
    
    /* Check if the operation is addition */
    if (strcmp(apc->oper, "+") == 0)
    {
        /* If both numbers are negative */
        if ((*head1)->data < 0 && (*head2)->data < 0)
        {
            /* Make both numbers positive for addition */
            (*head1)->data = -(*head1)->data;
            (*head2)->data = -(*head2)->data;
            
            /* Perform addition */
            addition(&t1, &t2, &reshead, &restail);
            
            /* Make the result negative */
            reshead->data = -reshead->data;
        }
        /* If only the first number is negative */
        else if ((*head1)->data < 0)
        {
            /*Make the first number positive*/
            (*head1)->data = -(*head1)->data;  
            
            /* Perform subtraction as (second number - first number) */
            subtraction(&t2, &t1, head2, head1, &reshead, &restail);
        }
        /* If only the second number is negative */
        else if ((*head2)->data < 0)
        {
            /*Make the second number positive*/
            (*head2)->data = -(*head2)->data; 
            
            /* Perform subtraction as (first number - second number) */
            subtraction(&t1, &t2, head1, head2, &reshead, &restail);
        }
        else
        {
            /* Both numbers are positive, perform addition */
            addition(&t1, &t2, &reshead, &restail);
        }
        
        /* Printing the addition result */
        printf("\033[1;32m");
        printf("Addition : %s + %s\n", apc->op1, apc->op2);
        printf("\033[0m");
    }
    /* Check if the operation is subtraction */
    else if (strcmp(apc->oper, "-") == 0)
    {
        /* If both numbers are negative */
        if ((*head1)->data < 0 && (*head2)->data < 0)
        {
            /* Make both numbers positive for subtraction */
            (*head1)->data = -(*head1)->data;  
            (*head2)->data = -(*head2)->data;  
            
            /* Perform subtraction as (first number - second number) */
            subtraction(&t1, &t2, head1, head2, &reshead, &restail);
            
            /* Make the result negative */
            reshead->data = -reshead->data;
        }
        /* If only the first number is negative */
        else if ((*head1)->data < 0)
        {
            /*Make the first number positive*/
            (*head1)->data = -(*head1)->data; 
            
            /* Perform addition and make the result negative */
            addition(&t1, &t2, &reshead, &restail);
            reshead->data = -reshead->data;
        }
        /* If only the second number is negative */
        else if ((*head2)->data < 0)
        {
            /*Make the second number positive*/
            (*head2)->data = -(*head2)->data; 
            
            /* Perform addition */
            addition(&t1, &t2, &reshead, &restail);
        }
        else
        {
            /* Both numbers are positive, perform subtraction */
            subtraction(&t1, &t2, head1, head2, &reshead, &restail);
        }
        
        /* Print the subtraction result */
        printf("\033[1;32m");
        printf("Subtraction : %s - %s\n", apc->op1, apc->op2);
        printf("\033[0m");
    }
    /* Check if the operation is division */
    else if (strcmp(apc->oper, "/") == 0)
    {
        /* checking is two operands are negative value */
        if((*head1)->data<0 && (*head2)->data<0)
        {
            /* making two operands value positive */
            (*head1)->data=-(*head1)->data;
            (*head2)->data=-(*head2)->data;
            /* calling division function to perform Division */
            division(head1,tail1,head2,tail2,&reshead,&restail);
        }
        /* checking is first operand is negative value */
        else if((*head1)->data<0)
        {
            (*head1)->data=-(*head1)->data;
            /* calling division function to perform Division */
            division(head1,tail1,head2,tail2,&reshead,&restail);
            /* making resultant value negative */
            reshead->data=-reshead->data;
        }
        /* checking is second operand is negative value */
        else if((*head2)->data<0)
        {
            /* making second operands value positive */
            (*head2)->data=-(*head2)->data;
            /* calling division function to perform Division */
            division(head1,tail1,head2,tail2,&reshead,&restail);
            /* making resultant value negative */
            reshead->data=-reshead->data;
        }
        else
        {
        /* calling division function to perform Division */
           division(head1,tail1,head2,tail2,&reshead,&reshead);
        }
        printf("\033[1;32m");
        printf("Division : %s / %s\n", apc->op1, apc->op2);
        printf("\033[0m");    
    }
    /* Check if the operation is multiplication */
    else if (strcmp(apc->oper, "x") == 0)
    {
        /* If both numbers are negative */
        if ((*head1)->data < 0 && (*head2)->data < 0)
        {
            /* Make both numbers positive for multiplication */
            (*head1)->data = -(*head1)->data;  
            (*head2)->data = -(*head2)->data;  
            
            /* Perform multiplication */
            multiplication(&t1, &t2, head1, head2, &reshead, &restail);
        }
        /* If only the first number is negative */
        else if ((*head1)->data < 0)
        {
            /*Make the first number positive*/
            (*head1)->data = -(*head1)->data; 
            
            /* Perform multiplication and make the result negative */
            multiplication(&t1, &t2, head1, head2, &reshead, &restail);
            reshead->data = -reshead->data;
        }
        /* If only the second number is negative */
        else if ((*head2)->data < 0)
        {
            /*Make the second number positive*/
            (*head2)->data = -(*head2)->data; 
            
            /* Perform multiplication and make the result negative */
            multiplication(&t1, &t2, head1, head2, &reshead, &restail);
            reshead->data = -reshead->data;
        }
        else
        {
            /* Both numbers are positive, perform multiplication */
            multiplication(&t1, &t2, head1, head2, &reshead, &restail);
        }
        
        /* Print the multiplication result */
        printf("\033[1;32m");
        printf("Multiplication : %s x %s\n", apc->op1, apc->op2);
        printf("\033[0m");
    }

    printf("Result:");
    /* Print the resulting list */
    print_list(reshead);
}


/* Function to add two numbers represented as double linked lists */
int addition(Dlist **t1, Dlist **t2, Dlist **reshead, Dlist **restail)
{
    /*Initialize carry to 0*/
    int carry = 0;  

    /* Loop until both lists are fully traversed */
    while ((*t1) != NULL || (*t2) != NULL)
    {
        /* Retrieve the data from each list node, or 0 if the node is NULL */
        int data1 = ((*t1) != NULL) ? (*t1)->data : 0;  
        int data2 = ((*t2) != NULL) ? (*t2)->data : 0;

        /* Calculate the sum of the two nodes' data plus any carry */
        int sum = data1 + data2 + carry;
        
        /* Calculate new carry for next iteration ,if sum exceeds 4 digits*/
        carry = sum / 10000;
        
        /* Get the last 4 digits of the sum to store in the result list */
        int digit = sum % 10000;

        /* Insert the computed digit at the beginning of the result list */
        int ret = insert_first(reshead, restail, digit);

        /* Move to the previous node in the first list, if it exists */
        if (*t1 != NULL) 
            *t1 = (*t1)->prev;
        
        /* Move to the previous node in the second list, if it exists */
        if (*t2 != NULL) 
            *t2 = (*t2)->prev;
    } 
    
    /* If there is a carry left after the final addition, add it to the result list */
    if (carry > 0)
    {
        insert_first(reshead, restail, carry);
    }

    /*Return SUCCESS upon completing the addition*/
    return SUCCESS;  
}


/* Function to subtract two numbers represented as double linked lists */
int subtraction(Dlist **t1, Dlist **t2, Dlist **head1, Dlist **head2, Dlist **reshead, Dlist **restail)
{
    /* Create temporary pointers to count the number of nodes in each list */
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int c1 = 0, c2 = 0;
    /*initialize borrow*/
    int borrow = 0, sum;

    /* Count the number of nodes in the first list */
    while (temp1 != NULL)
    {
        c1++;
        temp1 = temp1->next;
    }
    
    /* Count the number of nodes in the second list */
    while (temp2 != NULL)
    {
        c2++;
        temp2 = temp2->next;
    }

    /* If the second list is larger, swap the lists to ensure positive result */
    if (c2 > c1)
    {
        Dlist *t = *t1;
        *t1 = *t2;
        *t2 = t;
    }
    /* If both lists have the same length, compare the head node data to determine larger number */
    else if (c1 == c2)
    {
        if ((*head1)->data < (*head2)->data)
        {
            Dlist *t = *t1;
            *t1 = *t2;
            *t2 = t;
        }
    }

    /* Traverse both lists from the tail nodes */
    while (*t1 != NULL || *t2 != NULL)
    {
        /* Get the data from each node, or 0 if the node is NULL */
        int data1 = (*t1 != NULL) ? (*t1)->data : 0;  
        int data2 = (*t2 != NULL) ? (*t2)->data : 0;

        /* Calculate the difference between nodes, adjusting for any borrow */
        sum = data1 - data2 - borrow;
        
        /* If the result is negative, borrow from the next higher place value */
        if (sum < 0)
        {
            /*Adjust the sum by adding 10000 (to simulate borrowing)*/
            sum += 10000; 
            /*Set borrow for the next iteration*/
            borrow = 1;   
        }
        else
        {
            /*Reset borrow if no borrowing is needed*/
            borrow = 0;   
        }

        /* Insert the computed difference at the beginning of the result list */
        int ret = insert_first(reshead, restail, sum);

        /* Move to the previous node in each list, if it exists */
        if (*t1 != NULL) 
            *t1 = (*t1)->prev;
        if (*t2 != NULL) 
            *t2 = (*t2)->prev;
    }
    
    /* If there is a borrow left, add it to the result list (handles negative results) */
    if (borrow > 0)
    {
        insert_first(reshead, restail, -sum);
    }

    /*Return SUCCESS upon completing the subtraction*/
    return SUCCESS;  
}

/* Function to multiply two numbers represented as double linked lists */
int multiplication(Dlist **t1, Dlist **t2, Dlist **head1, Dlist **head2, Dlist **head3, Dlist **tail3)
{
    /*declaring temporary pointer and initializing with head1*/
    Dlist *temp = *head1;
    long long num = 0;

    /* Convert the first linked list to an integer value */
    while (temp != NULL) 
    {
        num = num * 10000 + temp->data;
        temp = temp->next;
    }

    /* Initialize result list pointers */
    Dlist *reshead1 = NULL;
    Dlist *reshead2 = NULL;
    Dlist *reshead3 = NULL;
    Dlist *restail1 = NULL;
    Dlist *restail2 = NULL;
    Dlist *restail3 = NULL;

    /* Start from the second list's tail for multiplication */
    temp = *t2;
    long long int res;
    long long int num1 = temp->data;
    
    /* Multiply the integer from the first list with each node of the second list */
    res = num * num1;
    for (int i = 0; res > 0; i++)
    {
        /* Extract 4-digit segments to store in the result list */
        int rem = res % 10000;
        insert_first(&reshead1, &restail1, rem);
        res = res / 10000;
    }
    temp = temp->prev;
    int j = 1;

    /* Continue multiplying each remaining node of the second list */
    while (temp != NULL)
    {
        /* Shift result by inserting zeroes as place holders */
        for (int i = 0; i < j; i++)
        {
            insert_first(&reshead2, &restail2, 0);
        }

        num1 = temp->data;
        res = num * num1;

        /* Extract 4-digit segments for the partial result */
        for (int i = 0; res > 0; i++)
        {
            int rem = res % 10000;
            insert_first(&reshead2, &restail2, rem);
            res = res / 10000;
        }

        /* Add current partial result to the cumulative result */
        addition(&restail1, &restail2, &reshead3, &restail3);

        /* Update cumulative result lists for the next iteration */
        reshead1 = reshead3;
        restail1 = restail3;

        /* Reset intermediate result lists */
        reshead2 = NULL;
        restail2 = NULL;
        reshead3 = NULL;
        restail3 = NULL;

        /* Move to the previous node and increment the place value position */
        temp = temp->prev;
        j++;
    }

    /* Update the head and tail pointers of the result list */
    *head3 = reshead1;
    *tail3 = restail3;

    /*Return SUCCESS upon completing the multiplication*/
    return SUCCESS; 
}

void division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **reshead,Dlist **restail)
{
    /* temp1 pointer initialised to point head1 */
    Dlist *temp1=*head1;
    /* temp2 pointer initialised to point head2 */
    Dlist *temp2=*head2;
    /* res variable declared and c variable initialised to zero*/
    int res,c=0;
    /* num1 and num2 variable initialised */
    long long int num1=0,num2=0;
    /* run the loop till temp1 reachs NULL */
    while(temp1!=NULL)
    {
        /* extracting first operand value and storing in num */
        num1=num1*10000+temp1->data;
        /* updating temp1 */
        temp1=temp1->next;
    }
    /* run the loop till temp1 reachs NULL */
    while(temp2!=NULL)
    {
        /* extracting first operand value and storing in num */
        num2=num2*10000+temp2->data;
        /* updating temp1 */
        temp2=temp2->next;
    }
    /* check is first operand is zero */
    if(num2==0)
    {
        /* prinitng error message */
        printf("\033[1;31m");
        printf("Division by zero is not permitted\n");
        printf("\033[0m");
        return;
    }
    /* run the loop till num1 is greater equal to num2*/
    while(num1>=num2)
    {
        /* performing subtraction operation */
        num1=num1-num2;
        /* incrementing c */
        c++;
    }
    /* calling inser_first function to store resultant in double list */
    insert_first(reshead,restail,c);
}