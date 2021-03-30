#include "book_management.h"
#include "interface.h"
#include "librian_account.h"
#include "display_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int add_new_book()
{
	Book *search_before_add; //在书库里遍历的指针，检查是否已经存在这本书 
	
	char *id_pointer; //指向ID数组的指针，用于转到int
	int id_number;  //用户所输入的ID （int） 
	char *time_pointer; //指向时间数组的指针，用于转到int 
	int time_number;  //用户所输入的时间 （int） 

	char add_book_id[99]; //要添加的书的ID
	char add_book_author[99];  //要添加的书的作者
	char add_book_name[99]; //要添加的书的名字
	char add_book_release_time[99];  //要添加的书的出版时间
	
	int old_book_flag=0;  //若书库里有这本书，则改为1 
	
	int new_add_number;  //要加入的书的数量 

	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
	while(1)
	{
		printf("Please enter ID of the book that you want to add:\n");
	    //printf("(An 3-digit sequence of numbers)\n");
	    gets(add_book_id);
	    gets(add_book_id);
	    
	    if (strspn(add_book_id,"0123456789")!=strlen(add_book_id))  //检查是否只含数字 
	    {
	    	printf("Only numbers are valid characters,please reenter\n");
	    	continue;
		}
		
		/*int i=0;
		for(i;add_book_id[i]!='\0';i++);  
		if(i>3)                        //检查ID数列是否过长 
		{
			printf("Book ID is too long,please reenter:\n");
			continue;
		}
		
		if(i<3)                        //检查ID数列是否过短 
		{
			printf("Book ID is too short,please reenter:\n");
			continue;
		}*/
		

		search_before_add=Book_Head.array;  //查找指针指向第一本书 
		id_pointer=add_book_id;
		id_number=atoi(id_pointer);  // 把ID转为int型用于搜索 
		
		while(search_before_add!=NULL)
		{	//printf("kk");
			if(id_number==search_before_add->id)  //书库里有这本书 
			{
				old_book_flag=1;  //改变旧书符号 
				printf("The book is already in library.\n");
				printf("Book ID\t");
				printf("Book title\t");
				printf("Authors\t");
				printf("Release year\t");
				printf("Copies\t");
				printf("Copies available\n");
				
				printf("%d\t",search_before_add->id);
				printf("%s\t",search_before_add->title);
				printf("%s\t",search_before_add->authors);
				printf("%d\t",search_before_add->year);
				printf("%d\t",search_before_add->copies);
				printf("%d\n",search_before_add->now_copies);
				printf("Please enter the number you want to add(an integer greater than 0):\n");
				scanf("%d",&new_add_number);     ////////////////////////////////////////////////////未考虑鲁棒性 
				if(new_add_number<0)   //若输入了一个负数 
				{
					printf("Invalid input!\n");
					return 1;
				}
				
				search_before_add->copies+=new_add_number;  //增加库存 
				search_before_add->now_copies+=new_add_number;
				//store_users();
				store_books();
				printf("Adding successfully.\n");
				return 1; 
			}
			
			if(search_before_add->next==NULL)
			{
				break;
			}
			
			search_before_add=search_before_add->next;
			if(search_before_add->next==NULL) //若当前指向的书已经是最后一本 
			{
				book_end=search_before_add;
			}
			
		}
		
		
		
		
		if(old_book_flag==0)  //是一本新书 
		{	
			
        	printf("Please enter book title:\n");
			gets(add_book_name);
			//gets(add_book_name);
			printf("Please enter autor name:\n");
			gets(add_book_author);
			//gets(add_book_author);
		
			while(1)
			{
				printf("Please enter release year:\n");
		    	gets(add_book_release_time);
		    	//gets(add_book_release_time); 
		    	if (strspn(add_book_release_time,"0123456789")!=strlen(add_book_release_time))  //检查是否只含数字 
	        	{
	    			printf("Only numbers are valid characters,please reenter/n");
	    			continue;
		    	}
		    
		    	time_pointer=add_book_release_time;
		    	time_number=atoi(time_pointer);  //int型出版时间 
		    	break;
		    
			}

			//while(1)
		//	{
				printf("Please enter the number you want to add(an integer greater than 0):\n");   //////////////////////未考虑鲁棒性 
				scanf("%d",&new_add_number);
				/*if(new_add_number<0)
				{
					continue;
				}
				break;*/ 
		//	}
			
			//add_book();
			//printf("1");
			add_book(); //在书的链表里创建新节点 
			Book_Head.length++;  
			
			char *name_pointer=add_book_name;
			char *author_pointer=add_book_author;
			
			book_end->id=id_number;
			strcpy(book_end->title,add_book_name);
			strcpy(book_end->authors,add_book_author);
			//printf("1");
			//book_end->title=add_book_name;
			//book_end->authors=add_book_author;
			book_end->year=time_number;
			book_end->copies=new_add_number;
			book_end->now_copies=new_add_number; 
			//printf("%d",Book_Head.array->id);
			//printf("%d",book_end->id);
			//printf("%s",book_end->authors);
			
			//printf("1");
			store_books();
			printf("Adding successfully.\n");
		}
		
		return 1;
		
	}

	
	
	
	
} 








int remove_books()
{
	char remove_id[99];  //输入的id数组
	char *remove_id_pointer; //指向id数组的指针，用于转换成int 
	char remove_id_number;  //int型的id 
	Book *search_remove;  //查找需要移除的书的指针
	Book *vice_search_remove;  //查找需要移除的书的另一个指针 
	
	
	printf("Enter the ID of book you want to remove.\n");
	gets(remove_id);
	gets(remove_id); 
	if (strspn(remove_id,"0123456789")!=strlen(remove_id))  //检查是否只含数字 
	{
	    printf("Only numbers are valid characters,please reenter/n");
	    return 1;
	}
		    
	remove_id_pointer=remove_id;
	remove_id_number=atoi(remove_id_pointer);  //转换成int型id
	search_remove=Book_Head.array;  //指向第一本书 
	vice_search_remove=search_remove->next;
	
	//printf("1");
	if(search_remove==NULL)  //如果书头后面没有书 
	{
		printf("No this book.\n");
		return 1;
	} 
	
	
	if(search_remove->id==remove_id_number)  //第一本书就是要找的
	{
		if(search_remove->now_copies<search_remove->copies)
		{
			printf("This book borrowed by some users now, you can not remove it.\n");
			return;
		}
		Book_Head.array=search_remove->next;
		printf("Remove successfully.\n");
		Book_Head.length--;
		//store_users();
		store_books();
		return 1; 
	} 
	
	//if((search_remove->id==remove_id_number))
	/*
	
	if(search_remove->next->id==remove_id_number && search_remove->next->next==NULL)  //第二本书是要找的书且链表里只有两本书
	{
		search_remove->next==NULL;
		printf("Remove successfully.\n");
		return 1;
	} 
	
	
	while(search_remove->next!=NULL)
	{
		if(search_remove->next->id==remove_id_number)
		{
			search_remove->next=search_remove->next->next; //删去节点
			printf("Remove successfully.\n");
			return 1; 
		}
	} */
	
	while(search_remove->next!=NULL)
	{
		if(search_remove->next->id==remove_id_number)
		{
			if(search_remove->now_copies<search_remove->copies)
			{
				printf("This book borrowed by some users now, you can not remove it.\n");
				return;
			}
			
			search_remove->next=search_remove->next->next;
			printf("Remove successfully.\n");
			Book_Head.length--;
			//store_users();
			store_books();
			return 1;
		}
		
		search_remove=search_remove->next;
	}
	
	printf("No this book.\n");
	return 1;
	
}


void librian_account()
{
	//printf("------------------------------------\n");
	printf("Login as librian\n");
	
	int librian_choice;
	
	while(1)
	{
	    printf("Please enter next your next action.\n");
	    printf("(1) Add books into library.\n");
	    printf("(2) Remove books from libary.\n");
	    printf("(3) Search for books.\n");
	    printf("(4) Display all books.\n");
	    printf("(5) Logout.\n");
	
	    scanf("%d",&librian_choice);
	    switch (librian_choice)
	    {
		case 1:
			add_new_book();
			continue;
			
		case 2:
			remove_books();
			continue;
			
		case 3:
			Search_books_module();
			continue;
			
		case 4:
			Display_module();
			continue;
			
		case 5:
			printf("Logout.\n");
			//login_flag=0;
			return;
			
		default:
			printf("Sorry,that do not seem to be an option\n");
		}
	}
}
