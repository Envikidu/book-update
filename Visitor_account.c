#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "Borrow.h"
#include "Visitor_account.h"
#include "Head_file.h"
#include "Display_module.h"
#include "Search_books_module.h"

void Return(Users *returner)
{
	char return_id[99];
	char *return_id_pointer;
	int return_id_number;
	Book *return_position=User_Head.array;
	//if(return_position==NULL)
	
	//Book *return_search=Book_Head.array;
	printf("Enter the ID of book you want to return:/n");
	gets(return_id);
	
	if (strspn(return_id,"0123456789")!=strlen(return_id))  //检查是否只含数字 
	{
	    printf("Only numbers are valid characters,please reenter/n");
	    return;
	}
		    
	return_id_pointer=return_id;
	return_id_number=atoi(return_id_pointer);  //转换成int型id
	
	int mi=0;
	for(mi;mi<returner->borrow_number;mi++)
	{
		if(returner->borrowed[mi]==-1)  //这个位置的书已经还了，跳过这里继续找 
		{
			mi--;
			continue;
		}
		
		if(returner->borrowed[mi]==return_id_number)  //在借阅书单里找到了用户要还的书 
		{
			returner->borrow_number--;
			returner->borrowed[mi]=-1;
			while(1)
			{
				if(return_position->id==return_id_number)  //在书库里找到了对应的书 
				{
					return_position->now_copies++;
					printf("Return successfully.\n");
					return;
				}
				
				return_position=return_position->next;
				if(return_position==NULL)
				{
					printf("Error.\n");
					break;
				}
			}
		}
		
	} 
	
	printf("You never borrow this book\n");
	return;
	
	
} 


void Borrow(Users *borrower)
{
	char borrow_id[99];
	char *borrow_id_pointer;
	int borrow_id_number;
	Book *borrow_search=Book_Head.array;
	
	if(borrow_search==NULL)
	{
		printf("No book in library now.\n");
		return;
	}
	
	printf("Enter the book ID:\n");
	scanf("%s",&borrow_id);
	
	if (strspn(borrow_id,"0123456789")!=strlen(borrow_id))  //检查是否只含数字 
	{
	    printf("Only numbers are valid characters,please reenter/n");
	    return;
	}
		    
	borrow_id_pointer=borrow_id;
	borrow_id_number=atoi(borrow_id_pointer);  //转换成int型id
	
	int o=0; 
	for(o;o<99;o++)   //检查是否已经借过这本书 
	{
		if(borrow_id_number==borrower->borrowed[o])
		{
			printf("You have borrowed this already.\n");
			return;
		}
	}
	
	while(1)
	{
		if(borrow_search->id==borrow_id_number)  //找到了这本书 
		{
			printf("%d\t",borrow_search->id);
			printf("%s\t",borrow_search->title);
			printf("%s\t",borrow_search->authors);
			printf("%d\t",borrow_search->year);
			printf("%d\t",borrow_search->copies);
			printf("%d\n",borrow_search->now_copies);
			if(borrow_search->now_copies==0)  //但全部被借出了 
			{
				printf("Sorry, the book are borrowed out in full now\n");
				return;
			}
			
			else  //可以借 
			{
				int po=0;
				while(1)
				{
					//printf("%d",borrower->borrowed[0]);
					if(borrower->borrowed[po]==-1) //把书放在这个空位置 
					{
						borrower->borrowed[po]=borrow_id_number;
						borrow_search->now_copies--;
						borrower->borrow_number++;
						printf("Borrow successfully.\n");
						return;
					}
					po++;
				}
				
			}
		}
		
		borrow_search=borrow_search->next;
		if(borrow_search==NULL)  //找到结尾依然没有找到 
		{
			printf("This book is not available in the library.\n");
			return;
			
		}
		
		return;
	}
	
}

void Visitor_account(char account[],Users *user_online)
{
	int visitor_choice; 
	while(1)
	{
		printf("Login as %s\n",account);
		printf("Please enter next your next action:\n");
		printf("(1) Borrow books:\n");
		printf("(2) Return books:\n");
		printf("(3) Search books:\n");
		printf("(4) Display all books:\n");
		printf("(5) Logout:\n");
	
		scanf("%d",&visitor_choice);
		switch(visitor_choice)
		{
			case 1:
				Borrow(user_online);
				continue;
			
			case 2:
				Return(user_online);
				continue;
			
			case 3:
				Search_books_module();
				continue;
				
			case 4:
				Display_module();
				continue;
				
			case 5:
				printf("Logout.\n");
				return;
				
			default:
				printf("Sorry,that do not seem to be an option\n");
				continue;
	 	}
		  
	}

}
