#include "Registration_module.h"
#include "book_management.h"
#include "Head_file.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free(B)
#define CreateUserNode(U) U=(Users*)malloc(sizeof(Users))
#define DeleteUserNode(U) free(U)


void Registration_module(){
	Users *new_user; //��ӵ����û� 
	char username[99]; //�½����û���
	char user_password[99]; //�½��û�������
	Users *search_user; // ���û��ļ���Ѱ���Ƿ��������û� 
	
	while(1)
	{
		printf("Please enter your username here:\n");
	    gets(username);
	    gets(username);
	    int i,j;
	    
	    for(i=0;i;i++)   //��ȡ�û������� 
	   {
		   if(username[i]='\0')
		   {
		   		//DeleteUserNode(search_user);
				break;
		   }
	   }
	   
	   if(i>10)       //����û��������Ƿ�Ϸ� 
	   {
	   	    printf("Username is too long! Please reenter.\n"); 
	   	    continue;
	   }
	   
	   
	   
	   
	   
	   //printf("%s",User_Head.array->name);
	   search_user=User_Head.array;
	   //printf("1");
	   while(search_user!=NULL)            //�鿴���û����Ƿ��ѱ�ռ�� 
	   {
	   		if(strcmp(search_user->name,username)==0)  //�ҵ�ͬ���û� 
	   		{
	   			printf("This name has been used.\n");
	   			return;
			}
			
			search_user=search_user->next;
	   }
	   
	   
	   
	   break;
	}
	
	
	
	
	
	
	
	while(1)
	{
	
	    printf("Please enter your password here(1-10 characters):\n");
	    gets(user_password);
	    //printf("%s",user_password);
	    //gets(user_password); 
	   int i=0;
	   for(i=0;i;i++)   //��ȡ����ĳ��� 
	   {
		   if(user_password[i]='\0')
		   {
			   break;
		   }
	   }
	   
	   if(i>10)       //��鳤���Ƿ�Ϸ� 
	   {
	   	    printf("Password is too long! Please reenter.\n");
	   	    continue;
	   }
	   
	   /*strcpy(new_user->password,user_password); //�Ϸ������� 
	   new_user->next=NULL;  //���û�����һλָNULL 
	   fwrite(&new_user,sizeof(new_user),1,Userlist);   //д�� 
	   printf("Your account has been created.\n");
	   DeleteUserNode(new_user);
	   DeleteUserNode(search_user);
	   fclose(Userlist);
	   break;*/
	   
	   //load_users();
	   
	   add_user();
	   User_Head.number++; 
	   user_end->borrow_number=0;
	   strcpy(user_end->name,username);
	   strcpy(user_end->password,user_password);
	   user_end->next==NULL;
	   //memset(&(user_end->borrowed),-1,99);
	   int cnt=0;
	   for(cnt;cnt<99;cnt++)
	   {
	   		user_end->borrowed[cnt]=-1;
	   }
	   
	   //user_end->borrowed[0]=-1;
	   //user_end->borrowed[1]=-1;
	   //printf("%s",User_Head.array->name); 
	   store_users();
	   
	   
	   
	   printf("Registration success.\n");
	   break;
	    
	}
	
	return;
	
}
