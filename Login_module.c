#include "book_management.h"
#include "Login_module.h"
//#include "Head_file.h"
#include "librian_account.h"
//#include "Vistor_account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Login_module()
{
	
	char login_user[99]; //用户所输入的用户名
	char login_password[99]; //用户所输入的密码
	char manager[20]="librarian"; //管理员的用户名
	char manager_password[20]="43426606"; //管理员密码 
	//int login_flag;  //记录是否当前有用户登录，1为有用户登录状态，2为管理员登录状态 
	Users *search_user_login;  //在用户文件中检查是否有输入的这个用户  
	int exist=0; //检查是否有这个用户的标志，1为有这个用户 
	
	
	
	
	while(1)
	{
		printf("Please enter your username:\n");
	    gets(login_user);
	    gets(login_user); 
	    search_user_login=User_Head.array; //从User_Head的后一位开始找有没有这个用户 
	    
		if(strcmp(manager,login_user)==0)  //管理员登录 
		{
			exist=1;
			break; 
		}
	
	
	    while(search_user_login!=NULL)  //在用户链表的用户名中找，是否有这个用户 
	    {
	    	if(strcmp(search_user_login->name,login_user)==0)  //找到了这个用户 
	    	{
	    		exist=1; //把标志改为1 
	    		break;
			}
			search_user_login=search_user_login->next; //找下一个用户 
		}
		
		
		
		if(exist==0)  //链表里没有这个用户 
		{
			printf("This account not exist, please try again.\n");
			continue;
		}
		
		if(exist==1)
		{
			break;
		}
		
	}
	
	
		
		


		
		printf("Please enter password:\n");
		gets(login_password);
		//gets(login_password);

		
		 //检查密码是否正确 
			
		if((strcmp(login_user, manager) == 0)&&(strcmp(login_password, manager_password)==0)) //管理员登录 
		{
			//login_flag=2;
			//printf("Login as librarian.\n");
			librian_account();  //进入管理员模块 
			return;
		}
			
			
			
		if(strcmp(search_user_login->password,login_password)==0)  //密码正确 
		{
		   	printf("Login successfully.\n");
		   	Visitor_account(login_user,search_user_login);  //进入用户模块 
		   	return;
		}
			
		else
		{
			printf("Wrong password,please try again!\n");  //密码不正确 
			return;
		}

		
		
		
		
		
		/*else
		{
			//printf("1");
			//login_flag=1;
			//printf("1");
			
		}*/
		
		return;
	
}

	
