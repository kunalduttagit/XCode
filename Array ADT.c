//
//  Array ADT.c
//  C++ course
//
//  Created by Kunal Dutta on 11/09/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Initialize(struct Array *arr)
{
    printf("Enter Size of Array ");
    scanf("%d", &arr->size);
 
    arr->A = (int *)malloc(arr->size * sizeof(int));
    
    arr->length =  0;  //initialize length, bc no elements
    
    printf("Enter How many numbers ");
    int n;
    scanf("%d", &n);
    
    printf("Enter Elements\n");
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr->A[i]);
    arr->length = n;
}

void Display(struct Array arr)
{
    printf("\nElements are\n");
    for(int i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Append (struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
    else printf("Array Overflow");
}

void Insert (struct Array *arr, int index, int x)
{
    //if(arr->length < arr->size)
    if(index >= 0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{
    if(index <= arr->length && index >= 0)
    {
        for(int i=index; i<arr->length-1; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}

int LinearSearch (struct Array arr, int key)
{
    for(int i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}
int TranspositionLinearSearch (struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}
int MoveToHeadLinearSearch (struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}


int main()
{
    struct Array arr;
    
    int opt=0;
    printf("Enter the operation you want to do");
    printf("\n1. Initialize an array");
    printf("\n2. Insert an element");
    printf("\n3. Remove an element");
    printf("\n4. Append element");
    printf("\n5. Printing the elements of array");
    printf("\n6. Searching");
    printf("\n11. Exit\n");
    
    while(opt !=11)
    {
        printf("\nEnter the sequence of operation\n");
        scanf("%d", &opt);
        
        switch(opt)
        {
            case 1:
            {
                Initialize(&arr);
                break;
            }
            case 2:
            {
                printf("Insert Index and the Element ");
                int val, index;
                scanf("%d %d", &index, &val);
                Insert(&arr, index, val);
                break;
            }
            case 3:
            {
                printf("Which Index should be deleted ");
                int index;
                scanf("%d", &index);
                Delete(&arr, index);
                break;
            }
            case 4:
            {
                printf("Value to be appended ");
                int val;
                scanf("%d", &val);
                Append(&arr, val);
                break;
            }
            case 5:
            {
                Display(arr);
                break;
            }
            case 6:
            {
                printf("Choose Search Type");
                printf("\n1. Linear Search\n2. Transposition LS\n3. Move to Head LS\n(Note: 2 and 3 will affect your array");
                int s; scanf("%d", &s);
                switch(s)
                {
                    case 1:
                    {
                        printf("Enter Key to be found");
                        int key; scanf("%d", &key);
                        int x = LinearSearch(arr, key);
                        x != -1 ? printf("Found at Index %d", x) : printf("Key Not Found");
                    }
                    case 2:
                    {
                        
                    }
                }
            }
            default:
                break;
        }
    }
    
    
    return 0;
}
