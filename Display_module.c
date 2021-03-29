#include "Display_module.h"
#include "book_management.h"
#include "Head_file.h"

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
	
	printf("\tID\t");
	printf("\tName\t");
	printf("\tAuthors\t");
	printf("\tYear\t");
	printf("\tCopies\t");
	printf("\tCopies now\t\n");
	
	while(show!=NULL)
	{
		printf("\t%d\t",show->id);
		printf("\t%s\t",show->title);
		printf("\t%s\t",show->authors);
		printf("\t%d\t",show->year);
		printf("\t%d\t",show->copies);
		printf("\t%d\t\n",show->now_copies);
		show=show->next;
	}
	
	return;
}
