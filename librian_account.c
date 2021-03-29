#include "book_management.h"
#include "interface.h"
#include "librian_account.h"
#include "display_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int add_new_book()
{
	Book *search_before_add; //������������ָ�룬����Ƿ��Ѿ������Ȿ�� 
	
	char *id_pointer; //ָ��ID�����ָ�룬����ת��int
	int id_number;  //�û��������ID ��int�� 
	char *time_pointer; //ָ��ʱ�������ָ�룬����ת��int 
	int time_number;  //�û��������ʱ�� ��int�� 

	char add_book_id[99]; //Ҫ��ӵ����ID
	char add_book_author[99];  //Ҫ��ӵ��������
	char add_book_name[99]; //Ҫ��ӵ��������
	char add_book_release_time[99];  //Ҫ��ӵ���ĳ���ʱ��
	
	int old_book_flag=0;  //����������Ȿ�飬���Ϊ1 
	
	int new_add_number;  //Ҫ������������ 

	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
	while(1)
	{
		printf("Please enter ID of the book that you want to add:\n");
	    //printf("(An 3-digit sequence of numbers)\n");
	    gets(add_book_id);
	    gets(add_book_id);
	    
	    if (strspn(add_book_id,"0123456789")!=strlen(add_book_id))  //����Ƿ�ֻ������ 
	    {
	    	printf("Only numbers are valid characters,please reenter\n");
	    	continue;
		}
		
		/*int i=0;
		for(i;add_book_id[i]!='\0';i++);  
		if(i>3)                        //���ID�����Ƿ���� 
		{
			printf("Book ID is too long,please reenter:\n");
			continue;
		}
		
		if(i<3)                        //���ID�����Ƿ���� 
		{
			printf("Book ID is too short,please reenter:\n");
			continue;
		}*/
		

		search_before_add=Book_Head.array;  //����ָ��ָ���һ���� 
		id_pointer=add_book_id;
		id_number=atoi(id_pointer);  // ��IDתΪint���������� 
		
		while(search_before_add!=NULL)
		{	//printf("kk");
			if(id_number==search_before_add->id)  //��������Ȿ�� 
			{
				old_book_flag=1;  //�ı������� 
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
				scanf("%d",&new_add_number);     ////////////////////////////////////////////////////δ����³���� 
				if(new_add_number<0)   //��������һ������ 
				{
					printf("Invalid input!\n");
					return 1;
				}
				
				search_before_add->copies+=new_add_number;  //���ӿ�� 
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
			if(search_before_add->next==NULL) //����ǰָ������Ѿ������һ�� 
			{
				book_end=search_before_add;
			}
			
		}
		
		
		
		
		if(old_book_flag==0)  //��һ������ 
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
		    	if (strspn(add_book_release_time,"0123456789")!=strlen(add_book_release_time))  //����Ƿ�ֻ������ 
	        	{
	    			printf("Only numbers are valid characters,please reenter/n");
	    			continue;
		    	}
		    
		    	time_pointer=add_book_release_time;
		    	time_number=atoi(time_pointer);  //int�ͳ���ʱ�� 
		    	break;
		    
			}

			//while(1)
		//	{
				printf("Please enter the number you want to add(an integer greater than 0):\n");   //////////////////////δ����³���� 
				scanf("%d",&new_add_number);
				/*if(new_add_number<0)
				{
					continue;
				}
				break;*/ 
		//	}
			
			//add_book();
			//printf("1");
			add_book(); //����������ﴴ���½ڵ� 
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
	char remove_id[99];  //�����id����
	char *remove_id_pointer; //ָ��id�����ָ�룬����ת����int 
	char remove_id_number;  //int�͵�id 
	Book *search_remove;  //������Ҫ�Ƴ������ָ��
	Book *vice_search_remove;  //������Ҫ�Ƴ��������һ��ָ�� 
	
	
	printf("Enter the ID of book you want to remove.\n");
	gets(remove_id);
	gets(remove_id); 
	if (strspn(remove_id,"0123456789")!=strlen(remove_id))  //����Ƿ�ֻ������ 
	{
	    printf("Only numbers are valid characters,please reenter/n");
	    return 1;
	}
		    
	remove_id_pointer=remove_id;
	remove_id_number=atoi(remove_id_pointer);  //ת����int��id
	search_remove=Book_Head.array;  //ָ���һ���� 
	vice_search_remove=search_remove->next;
	
	//printf("1");
	if(search_remove==NULL)  //�����ͷ����û���� 
	{
		printf("No this book.\n");
		return 1;
	} 
	
	
	if(search_remove->id==remove_id_number)  //��һ�������Ҫ�ҵ�
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
	
	if(search_remove->next->id==remove_id_number && search_remove->next->next==NULL)  //�ڶ�������Ҫ�ҵ�����������ֻ��������
	{
		search_remove->next==NULL;
		printf("Remove successfully.\n");
		return 1;
	} 
	
	
	while(search_remove->next!=NULL)
	{
		if(search_remove->next->id==remove_id_number)
		{
			search_remove->next=search_remove->next->next; //ɾȥ�ڵ�
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
