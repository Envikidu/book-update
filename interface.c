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








int add_user()                               //添加用户 
{
	Users *p;  //建立新节点 
	CreateUserNode(p);  //分配空间 
	
	if(User_Head.array==NULL) //如果用户头节点后面为空 
	{
		user_end=p;
		User_Head.array=user_end;  //把新节点直接加在头的后面 
		return 1;
	}
	
	user_end=User_Head.array; //指向用户头部后的第一个用户 
	while(user_end->next!=NULL) //遍历链表找到尾部 
	{
		user_end=user_end->next;
	}
	
	user_end->next=p; //把新节点接在链表最后面 
	user_end=user_end->next; //指向尾部 （新连接上的节点） 
	user_end->next=NULL;  //设置尾节点的下一个指空 
	return 1; 
}












int add_book()                            //添加图书 
{
	Users *k; //建立新节点 
	CreateBookNode(k);  //分配空间 
	
	
	if(Book_Head.array==NULL) //如果存书头节点后面为空 
	{
		book_end=k;  
		Book_Head.array=book_end;  //把新节点直接加在头部后面 
		return 1;
	}
	
	book_end=Book_Head.array;  //指向书籍头部后的第一个用户 
	while(book_end->next!=NULL)  //遍历链表找到尾部 
	{
		book_end=book_end->next;
	}
	
	book_end->next=k;  //把新节点接在链表最后面 
	book_end=book_end->next;  //指向尾部 （新连接上的节点） 
	book_end->next=NULL;  //设置尾节点的下一个指空 
	return 1; 
}













int store_books()                         //把图书链表储存在文件中 （覆盖） 
{
	puts("store_books called");
	FILE *fp;
	fp=fopen("Book_storage.txt","w");
	
	
	
	if(!fp)
	{
		printf("Fail to open book storage file.\n");
		return -1;
	}
	
	Book *x;  //用于遍历整个图书链表 
	x=Book_Head.array;   //指向书籍头部后的第一本书 
	fprintf(fp,"%d\n\n",Book_Head.length);  //txt第一行存储书的数量 
	//book_end->next=NULL; //链表尾部指空 
	
	while(x!=NULL)  //逐行写入txt文件 
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










int load_books()                  //从文件中取出图书链表 
{
	FILE *fp;
	fp=fopen("Book_storage.txt","r");
	Book *p; //连接新节点所用的指针 
	if(!fp)
	{
		printf("Fail to load book storage.\n");
		return -1;
	}
	
	
	char read[LEN];  //暂时存储每行内容 
	if(fgets(read,LEN,fp)==NULL) //第一行为空 
	{
		printf("(There is no book in storage now.)\n");
		return 1;
	}
	
	sscanf(read,"%d", &(Book_Head.length)); //获取第一行的图书数量
	fgets(read,LEN,fp);
	int i=0;
	for(i=0;i<Book_Head.length;i++)
	{
		Book *new_book;  //把文件中的信息复制到新节点来 
		CreateBookNode(new_book);  //分配空间 
		
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
		
		fgets(read,LEN,fp);  //读掉一个空行 
		
		if(i==0)  //在向头部连接第一个节点时 
		{
			Book_Head.array=new_book; //头部的下一个直接指向新节点 
			p=new_book; //p指向尾部 
			continue; 
		}
		
		p->next=new_book;  //连接新节点 
		p=new_book;
		
	} 
	
	
	if(Book_Head.length==0)  //若文件中节点数为0，头部后面直接指空 
	{
		Book_Head.array=NULL;
		fclose(fp); 
		return 1;
	}
		
	p->next=NULL;  //尾节点指空 
	fclose(fp);
	return 1;
	
}





int store_users()    //存储用户到文件 (覆盖)
{
	puts("store_users called"); 
	/*FILE *fp;
	fp=fopen("User_collection.txt","w"); 
	
	if(!fp)
	{
		printf("Fail to open user collection file.\n");
		return -1;
	}
	
	
	
	Users *z;  //用于遍历整个用户链表 
	z = User_Head.array;   //指向用户头部后面第一个用户 
	fprintf(fp,"%d\n\n",User_Head.number);  //存储用户数量 
	user_end->next=NULL;  //链表尾部指空 
	while(z!=NULL)  //逐行写入txt 
	{
		fprintf(fp,"Username:%s\n",z->name);
		fprintf(fp,"Password:%s\n",z->password);
		fprintf(fp,"The number of borrowed books:%d\n",z->borrow_number);
		fprintf(fp,"Books in possession:\n");
		
		int i=0;
		for(i=0;i<z->borrow_number;i++)  //列出目前在借的书的id，每行一个ID号 
		{
			if(z->borrow_number==0)  //若没有借过书 
			{
				break;
			}
			
			if(z->borrowed[i]==-1)  //这本书曾经被借过，但已经换了 
			{
				i++;
				continue;
			}
			
			fprintf(fp,"%d\n",z->borrowed[i]); //每行一个ID号 
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
	Users *p;  //连接节点所用的指针 
	
	char read[LEN];
	if(fgets(read,LEN,fp)==NULL) //如果第一行为空 
	{
		printf("(There is no user in system now.)\n");
		//User_Head.number=0;
		return 1;
	}
	
	//printf("get s: %s\n", read);
	sscanf(read,"%d",&(User_Head.number));  //获取第一行的用户数量值 
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
		Users *new_user;  //把文件中的信息复制到新节点来 
		CreateUserNode(new_user);  //分配空间 
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
		for(j;j<new_user->borrow_number;j++)  //获取该用户正在借的书 
		{
			fgets(read,LEN,fp);
			sscanf(read,"%d\n",new_user->borrowed[j]);
		}
		
		//printf("k");
		if(i==0)  //在向头部连接第一个节点时 
		{
			//printf("k");
			User_Head.array=new_user; //头部的下一个直接指向新节点 
			p=new_user; //p指向尾部 
			//printf("k");
			continue; 
		}
		
		p->next=new_user;  //连接新节点 
		p=new_user;
		
	} 
	//printf("1");
	
	if(User_Head.number==0)  //若文件中的节点数为0，头部后面直接指空 
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
		user_end=user_end->next;  //预设链表尾指针 
	}
	
	librian_account()
	book_end=Book_Head.array;
	while(book_end->next!=NULL)
	{
		book_end=book_end->next;  //预设链表尾指针 
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
