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
	
	char login_user[99]; //�û���������û���
	char login_password[99]; //�û������������
	char manager[20]="librarian"; //����Ա���û���
	char manager_password[20]="43426606"; //����Ա���� 
	//int login_flag;  //��¼�Ƿ�ǰ���û���¼��1Ϊ���û���¼״̬��2Ϊ����Ա��¼״̬ 
	Users *search_user_login;  //���û��ļ��м���Ƿ������������û�  
	int exist=0; //����Ƿ�������û��ı�־��1Ϊ������û� 
	
	
	
	
	while(1)
	{
		printf("Please enter your username:\n");
	    gets(login_user);
	    gets(login_user); 
	    search_user_login=User_Head.array; //��User_Head�ĺ�һλ��ʼ����û������û� 
	    
		if(strcmp(manager,login_user)==0)  //����Ա��¼ 
		{
			exist=1;
			break; 
		}
	
	
	    while(search_user_login!=NULL)  //���û�������û������ң��Ƿ�������û� 
	    {
	    	if(strcmp(search_user_login->name,login_user)==0)  //�ҵ�������û� 
	    	{
	    		exist=1; //�ѱ�־��Ϊ1 
	    		break;
			}
			search_user_login=search_user_login->next; //����һ���û� 
		}
		
		
		
		if(exist==0)  //������û������û� 
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

		
		 //��������Ƿ���ȷ 
			
		if((strcmp(login_user, manager) == 0)&&(strcmp(login_password, manager_password)==0)) //����Ա��¼ 
		{
			//login_flag=2;
			//printf("Login as librarian.\n");
			librian_account();  //�������Աģ�� 
			return;
		}
			
			
			
		if(strcmp(search_user_login->password,login_password)==0)  //������ȷ 
		{
		   	printf("Login successfully.\n");
		   	Visitor_account(login_user,search_user_login);  //�����û�ģ�� 
		   	return;
		}
			
		else
		{
			printf("Wrong password,please try again!\n");  //���벻��ȷ 
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

	
