#include "Registration_module.h"
#include "book_management.h"
//#include "Head_file.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free(B)
#define CreateUserNode(U) U=(Users*)malloc(sizeof(Users))
#define DeleteUserNode(U) free(U)


void Registration_module(){
	Users *new_user; //添加的新用户 
	char realname[99]; //真实姓名 
	char username[99]; //新建的用户名
	char user_password[99]; //新建用户的密码
	Users *search_user; // 在用户文件中寻找是否有重名用户 
	
	
	while(1)
	{
		printf("Please enter your real name (English letters and blanks only):\n");
		gets(realname);
		gets(realname);
		
		if (strspn(realname,"abcdefghigklmnopqrstuvwxyz ABCDEFGHIGKLMNOPQRSTUVWXYZ")!=strlen(realname))  //检查是否只含字母 
	    {
	    	printf("Only English letters are valid characters, please reenter\n");
	    	return;
		}
		
		
		
		search_user=User_Head.array;
		while(search_user!=NULL)            //查看该真实名是否已被占用 
	    {
	   		if(strcmp(search_user->real_name,realname)==0)  //找到同名用户 
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
		printf("Please enter your username here:\n");
	    gets(username);
	    //gets(username);
	    
	   
	   
	   
	   search_user=User_Head.array;
	   while(search_user!=NULL)            //查看该用户名是否已被占用 
	   {
	   		if(strcmp(search_user->name,username)==0)  //找到同名用户 
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
	
	    printf("Please enter your password here:\n");
	    gets(user_password);

	   /*int i=0;
	   for(i=0;i;i++)   //获取密码的长度 
	   {
		   if(user_password[i]='\0')
		   {
			   break;
		   }
	   }
	   
	   if(i>10)       //检查长度是否合法 
	   {
	   	    printf("Password is too long! Please reenter.\n");
	   	    break;
	   }*/
	   

	   
	   add_user();
	   User_Head.number++; 
	   user_end->borrow_number=0;
	   strcpy(user_end->name,username);
	   strcpy(user_end->password,user_password);
	   strcpy(user_end->real_name,realname);
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
