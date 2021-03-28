#include "interface.h"
#include "Registration_module.h"
#include "Head_file.h" 
#include "Login_module.h"
//#include "Search_books_module.h"
#include "Display_module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CreateBookNode(B) B=(Book*)malloc(sizeof(Book))
#define DeleteBookNode(B) free(B)
#define CreateUserNode(U) U=(Users*)malloc(sizeof(Users))
#define DeleteUserNode(U) free(U)
#define LEN 999








int add_user()                               //����û� 
{
	Users *p;  //�����½ڵ� 
	CreateUserNode(p);  //����ռ� 
	
	if(User_Head.array==NULL) //����û�ͷ�ڵ����Ϊ�� 
	{
		user_end=p;
		User_Head.array=user_end;  //���½ڵ�ֱ�Ӽ���ͷ�ĺ��� 
		return 1;
	}
	
	user_end=User_Head.array; //ָ���û�ͷ����ĵ�һ���û� 
	while(user_end->next!=NULL) //���������ҵ�β�� 
	{
		user_end=user_end->next;
	}
	
	user_end->next=p; //���½ڵ������������� 
	user_end=user_end->next; //ָ��β�� ���������ϵĽڵ㣩 
	user_end->next=NULL;  //����β�ڵ����һ��ָ�� 
	return 1; 
}












int add_book()                            //���ͼ�� 
{
	Users *k; //�����½ڵ� 
	CreateBookNode(k);  //����ռ� 
	
	
	if(Book_Head.array==NULL) //�������ͷ�ڵ����Ϊ�� 
	{
		book_end=k;  
		Book_Head.array=book_end;  //���½ڵ�ֱ�Ӽ���ͷ������ 
		return 1;
	}
	
	book_end=Book_Head.array;  //ָ���鼮ͷ����ĵ�һ���û� 
	while(book_end->next!=NULL)  //���������ҵ�β�� 
	{
		book_end=book_end->next;
	}
	
	book_end->next=k;  //���½ڵ������������� 
	book_end=book_end->next;  //ָ��β�� ���������ϵĽڵ㣩 
	book_end->next=NULL;  //����β�ڵ����һ��ָ�� 
	return 1; 
}













int store_books()                         //��ͼ�����������ļ��� �����ǣ� 
{
	puts("store_books called");
	FILE *fp;
	fp=fopen("Book_storage.txt","w");
	
	
	
	if(!fp)
	{
		printf("Fail to open book storage file.\n");
		return -1;
	}
	
	Book *x;  //���ڱ�������ͼ������ 
	x=Book_Head.array;   //ָ���鼮ͷ����ĵ�һ���� 
	fprintf(fp,"%d\n\n",Book_Head.length);  //txt��һ�д洢������� 
	//book_end->next=NULL; //����β��ָ�� 
	
	while(x!=NULL)  //����д��txt�ļ� 
	{
		puts("looping");
		printf("ID:%d\n",x->id);
		fprintf(fp,"ID:%d\n",x->id);
		printf("Title:%s\n",x->title);
		fprintf(fp,"Title:%s\n",x->title);
		printf("Authors:%s\n",x->authors);
		fprintf(fp,"Authors:%s\n",x->authors);
		printf("Release year:%d\n",x->year);
		fprintf(fp,"Release year:%d\n",x->year);
		printf("The total storage number:%d\n",x->copies);
		fprintf(fp,"The total storage number:%d\n",x->copies);
		printf("Available storage number:%d\n\n",x->now_copies);
		fprintf(fp,"Available storage number:%d\n\n",x->now_copies);
		
		x=x->next;
	}
	
	
	fclose(fp);
	return 1;
}










int load_books()                  //���ļ���ȡ��ͼ������ 
{
	FILE *fp;
	fp=fopen("Book_storage.txt","r");
	Book *p; //�����½ڵ����õ�ָ�� 
	if(!fp)
	{
		printf("Fail to load book storage.\n");
		return -1;
	}
	
	
	char read[LEN];  //��ʱ�洢ÿ������ 
	if(fgets(read,LEN,fp)==NULL) //��һ��Ϊ�� 
	{
		printf("(There is no book in storage now.)\n");
		return 1;
	}
	
	sscanf(read,"%d", &(Book_Head.length)); //��ȡ��һ�е�ͼ������
	fgets(read,LEN,fp);
	int i=0;
	for(i=0;i<Book_Head.length;i++)
	{
		Book *new_book;  //���ļ��е���Ϣ���Ƶ��½ڵ��� 
		CreateBookNode(new_book);  //����ռ� 
		
		fgets(read,LEN,fp);
		sscanf(read,"ID:%d\n",&(new_book->id));
		
		char read2[LEN];
		fgets(read,LEN,fp);
		sscanf(read,"Title:\%[^\n]",read2);
		strcpy(new_book->title,read2);
		
		fgets(read,LEN,fp);
		sscanf(read,"Authors:\%[^\n]",read2);
		strcpy(new_book->authors,read2);
		
		fgets(read,LEN,fp);
		sscanf(read,"Release year:%d\n",&(new_book->year));
		
		fgets(read,LEN,fp);
		sscanf(read,"The total storage number:%d\n",&(new_book->copies));
		
		fgets(read,LEN,fp);
		sscanf(read,"Available storage number:%d\n",&(new_book->now_copies));
		
		fgets(read,LEN,fp);  //����һ������ 
		
		if(i==0)  //����ͷ�����ӵ�һ���ڵ�ʱ 
		{
			Book_Head.array=new_book; //ͷ������һ��ֱ��ָ���½ڵ� 
			p=new_book; //pָ��β�� 
			continue; 
		}
		
		p->next=new_book;  //�����½ڵ� 
		p=new_book;
		
	} 
	
	
	if(Book_Head.length==0)  //���ļ��нڵ���Ϊ0��ͷ������ֱ��ָ�� 
	{
		Book_Head.array=NULL;
		fclose(fp); 
		return 1;
	}
		
	p->next=NULL;  //β�ڵ�ָ�� 
	fclose(fp);
	return 1;
	
}





int store_users()    //�洢�û����ļ� (����)
{
	puts("store_users called"); 
	/*FILE *fp;
	fp=fopen("User_collection.txt","w"); 
	
	if(!fp)
	{
		printf("Fail to open user collection file.\n");
		return -1;
	}
	
	
	
	Users *z;  //���ڱ��������û����� 
	z = User_Head.array;   //ָ���û�ͷ�������һ���û� 
	fprintf(fp,"%d\n\n",User_Head.number);  //�洢�û����� 
	user_end->next=NULL;  //����β��ָ�� 
	while(z!=NULL)  //����д��txt 
	{
		fprintf(fp,"Username:%s\n",z->name);
		fprintf(fp,"Password:%s\n",z->password);
		fprintf(fp,"The number of borrowed books:%d\n",z->borrow_number);
		fprintf(fp,"Books in possession:\n");
		
		int i=0;
		for(i=0;i<z->borrow_number;i++)  //�г�Ŀǰ�ڽ�����id��ÿ��һ��ID�� 
		{
			if(z->borrow_number==0)  //��û�н���� 
			{
				break;
			}
			
			if(z->borrowed[i]==-1)  //�Ȿ����������������Ѿ����� 
			{
				i++;
				continue;
			}
			
			fprintf(fp,"%d\n",z->borrowed[i]); //ÿ��һ��ID�� 
		}
		
		
		
		fprintf(fp,"\n");
		z=z->next; 
		
	}
	
	fclose(fp);
	return 1;
	*/
	
}








int load_users()
{
	FILE *fp;
	fp=fopen("User_collection.txt","r");
	if(!fp)
	{
		printf("Fail to load user collection.\n");
		return -1;
	}
	Users *p;  //���ӽڵ����õ�ָ�� 
	
	char read[LEN];
	if(fgets(read,LEN,fp)==NULL) //�����һ��Ϊ�� 
	{
		printf("(There is no user in system now.)\n");
		//User_Head.number=0;
		return 1;
	}
	
	//printf("get s: %s\n", read);
	sscanf(read,"%d",&(User_Head.number));  //��ȡ��һ�е��û�����ֵ 
	//printf("get num: %d\n",User_Head.number);
	//rewind(fp);
	//fgets(read,LEN,fp);
	//fscanf(fp,"%d",User_Head.number); 
	//printf("%d",User_Head.number);
	
	//fgets(read,LEN,fp);
	int i=0;
	for(i=0;i<User_Head.number;i++)
	{
		//printf("%d ",i);
		Users *new_user;  //���ļ��е���Ϣ���Ƶ��½ڵ��� 
		CreateUserNode(new_user);  //����ռ� 
		//printf("1 ");
		char read2[LEN];
		fgets(read,LEN,fp);
		
		fgets(read,LEN,fp);
		sscanf(read,"Username:\%[^\n]",read2);
		strcpy(new_user->name,read2);
		//printf("%s",new_user->name);
		
		fgets(read,LEN,fp);
		sscanf(read,"Password:\%[^\n]",read2);
		strcpy(new_user->password,read2);
		//printf("%s",new_user->password);
		
		fgets(read,LEN,fp);
		sscanf(read,"The number of borrowed books:%d\n",&(new_user->borrow_number));
		//printf("%d",new_user->borrow_number);
		
		fgets(read,LEN,fp);
		
		//printf("k");
		int j=0;
		for(j;j<new_user->borrow_number;j++)  //��ȡ���û����ڽ���� 
		{
			fgets(read,LEN,fp);
			sscanf(read,"%d\n",new_user->borrowed[j]);
		}
		
		//printf("k");
		if(i==0)  //����ͷ�����ӵ�һ���ڵ�ʱ 
		{
			//printf("k");
			User_Head.array=new_user; //ͷ������һ��ֱ��ָ���½ڵ� 
			p=new_user; //pָ��β�� 
			//printf("k");
			continue; 
		}
		
		p->next=new_user;  //�����½ڵ� 
		p=new_user;
		
	} 
	//printf("1");
	
	if(User_Head.number==0)  //���ļ��еĽڵ���Ϊ0��ͷ������ֱ��ָ�� 
	{
		User_Head.array=NULL;
		fclose(fp); 
		return 1;
	}
	
	p->next=NULL;
	fclose(fp);
	return 1;
	
	
}










static void main_menu()
{

	int choice;
	load_users();
	//prinft("%d",User_Head.number);
	load_books();
	//printf("1");
	//printf("%s",User_Head.array->name);
	/*user_end=User_Head.array;
	while(user_end->next!=NULL)
	{
		user_end=user_end->next;  //Ԥ������βָ�� 
	}
	
	librian_account()
	book_end=Book_Head.array;
	while(book_end->next!=NULL)
	{
		book_end=book_end->next;  //Ԥ������βָ�� 
	}
	*/
	//librian_account();
	while(1)
	{
		 
		//printf("%d\n",User_Head.number);
		printf("Welcome to local library.\n\n");
	    printf("Please enter next your next action.\n");
	    printf("(1) Register an account.\n");
	    printf("(2) Login.\n");
	    printf("(3) Search for books.\n");
	    printf("(4) Display all books.\n");
	    printf("(5) Quit.\n");
	
	    scanf("%d",&choice);
	    switch (choice)
	    {
		case 1:
			Registration_module();
			continue;
			
		case 2:
			Login_module();
			continue;
			
		case 3:
			Search_books_module();
			continue;
			
		case 4:
			Display_module();
			continue;
			
		case 5:
			printf("See you next time.\n");
			store_users();	
			printf("1");
			store_books();
		
			exit(0);
			
		default:
			printf("Sorry,that do not seem to be an option\n");
	    }
	    
	}
	return;
	
}

void run_interface()
{
	main_menu();
}
