#include "Display_module.h"
#include "book_management.h"
//#include "Head_file.h"

void Display_module()
{
	Book *show; //用于遍历图书链表 
	show=Book_Head.array;
	
	//printf("%s",show->next->title);
	
	if(Book_Head.length==0) //如果书籍链表没有书 
	{
		printf("No data\n");
		return;
	}
	
	printf("%-10s","ID");
	printf("%-30s","Name");
	printf("%-30s","Authors");
	printf("%-15s","Year");
	printf("%-10s","Copies");
	printf("%-10s\n","Copies now");
	
	int count=0;
	while(show!=NULL)
	{
		//show->title=(char*)malloc(sizeof(char));
		//show->title=(char*)malloc(sizeof(char));
		printf("%-10d",show->id);
		printf("%-30s",show->title);
		printf("%-30s",show->authors);
		printf("%-15d",show->year);
		printf("%-10d",show->copies);
		printf("%-10d\n",show->now_copies);
		//printf("%d",Book_Head.length);
		show=show->next;
		count++;
		if(count==Book_Head.length)
		{
			break;
		}
	}
	
	return;
}
