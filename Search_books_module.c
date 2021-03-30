#include "book_management.h"
//#include "Head_file.h"
#include "Search_books_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_book_by_title(char titles[])
{
	int have_found_flag=0; 
	Book *check_book;  //在链表里用于搜索的指针 
	check_book=Book_Head.array;
	//printf("%s\n\n",titles);
	
	while(check_book!=NULL)
	{
		if(strstr(check_book->title,titles))  //输入的书名是该书书名的子串，即搜索到了 
		{
			have_found_flag=1;
			printf("%-10d",check_book->id);
			printf("%-30s",check_book->title);
			printf("%-30s",check_book->authors);
			printf("%-15d",check_book->year);
			printf("%-10d",check_book->copies);
			printf("%-10d\n",check_book->now_copies);
		}
		check_book=check_book->next;
		
	}
	
	if(have_found_flag==0)  //没有找到 
	{
		printf("No result.\n");
	}
	
	return;
	
}







void find_book_by_author(char author[])
{
	int have_found_flag=0;
	Book *check_book;    //在链表里用于搜索的指针 
	check_book=Book_Head.array;  
	
	while(check_book!=NULL)
	{
		if(strstr(check_book->authors,author))  //输入的作者名是该书作者名的子串，即搜索到了
		{
			have_found_flag=1;
			printf("%-10d",check_book->id);
			printf("%-30s",check_book->title);
			printf("%-15d",check_book->year);
			printf("%-30s",check_book->authors);
			printf("%-10d",check_book->copies);
			printf("%-10d\n",check_book->now_copies);
		}
		check_book=check_book->next;
		
	}
	
	if(have_found_flag==0)  //没有找到 
	{
		printf("No result.\n");
	}
	
	return;
}









void find_book_by_year(int years)
{
	int have_found_flag=0;
	Book *check_book;  //在链表里用于搜索的指针 
	check_book=Book_Head.array;
	
	while(check_book!=NULL)
	{	
		if(check_book->year==years)
		{	//printf("1");
			have_found_flag=1;
			printf("%-10d",check_book->id);
			printf("%-30s",check_book->title);
			printf("%-30s",check_book->authors);
			printf("%-15d",check_book->year);
			printf("%-30d",check_book->copies);
			printf("%-10d\n",check_book->now_copies);
		}
		check_book=check_book->next;
		
	}
	
	if(have_found_flag==0)  //没有找到 
	{
		printf("No result.\n");
	}
	
	return;
}







void Search_books_module()
{
	int search_by_x;  
	char check_title[99];  //输入的书名 
	char check_author[99];  //输入的作者名 
	char check_year[99];  //输入的出版时间 
	char *check_year_pointer;  //指向出版时间数组的指针 
	int check_year_number;  //出版时间（int） 
	
	
	
	//have_found_flag=0;
	while(1)
	{
	
		printf("Please select how to search:\n");
		printf("(1) Find by title.\n");
		printf("(2) Find by author.\n");
		printf("(3) Find by year.\n");
		printf("(4) Quit.\n");
		
		scanf("%d",&search_by_x);
		
		switch(search_by_x)
		{
			case 1:
				printf("Enter the book title:\n");
				gets(check_title);
				gets(check_title);
				find_book_by_title(check_title);
				continue;
			
			case 2:
				printf("Enter the author name:\n");
				gets(check_author);
				gets(check_author);
				if(strspn(check_author, "0123456789")!=0)
				{
					printf("Numbers can not be entered.\n");
					continue;
				}
				find_book_by_author(check_author);
				continue;
			
			case 3:
				printf("Enter the release time:\n"); 
				gets(check_year);
				gets(check_year);
			
				if (strspn(check_year,"0123456789")!=strlen(check_year))  //检查输入是否都为数字 
		    	{
	 		   		printf("Only numbers are valid characters,please reenter\n");
	 		   		continue;
				}
				
			
				check_year_pointer=check_year;
				check_year_number=atoi(check_year_pointer); //转为int 

				find_book_by_year(check_year_number);
				continue; 
				
			case 4:
				return;
				
			default:
				printf("Invalid option!\n");
				continue;
				
			
		}
	}
}
