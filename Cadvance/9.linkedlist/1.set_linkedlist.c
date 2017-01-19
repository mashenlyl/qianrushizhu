#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct node
{
	int data;					//数据段，用来存取数据的地方
	struct node *pNext;			//指针，用来指向下一个节点
};

int main(void)
{
	//链表的头指针
	struct node * pHead = NULL;
	
	/********************************************/
	//创建第一个节点
	//用malloc申请内存，并且和节点绑定。
	struct node* p0 = (struct node *)malloc(sizeof(struct node));
	
	//检查是否申请到内存了
	if(NULL == p0)
	{
		printf("error.\n");
		return -1;
	}
	
	//清内存,两种方法
	bzero(p0, sizeof(struct node));
	//memset(p0, 0, sizeof(struct node));		//用0来填充内存
	
	//填充数据
	p0->data = 1;
	p0->pNext = NULL;
	
	pHead = p0;					//指明头指针
	/********************************************/
	
	/********************************************/
	//创建第二个节点
	//用malloc申请内存，并且和节点绑定。
	struct node* p1 = (struct node *)malloc(sizeof(struct node));
	
	//检查是否申请到内存了
	if(NULL == p1)
	{
		printf("error.\n");
		return -1;
	}
	
	//清内存,两种方法
	bzero(p1, sizeof(struct node));
	//memset(p1, 0, sizeof(struct node));		//用0来填充内存
	
	//填充数据
	p1->data = 2;
	p1->pNext = NULL;
	
	p0->pNext = p1;					//链接节点
	/********************************************/
	
	/********************************************/
	//创建第三个节点
	//用malloc申请内存，并且和节点绑定。
	struct node* p2 = (struct node *)malloc(sizeof(struct node));
	
	//检查是否申请到内存了
	if(NULL == p2)
	{
		printf("error.\n");
		return -1;
	}
	
	//清内存,两种方法
	bzero(p2, sizeof(struct node));
	//memset(p2, 0, sizeof(struct node));		//用0来填充内存
	
	//填充数据
	p2->data = 3;
	p2->pNext = NULL;
	
	p1->pNext = p2;					//链接节点
	/********************************************/
	//注意：链表的访问必须只通过pHead，不能通过p0,1,2来访问
	
	//打印第一个节点的值
	printf("node1 data: %d\n", pHead->data);
	printf("p0->data: %d\n", p0->data);
	
	//打印第二个节点的值
	printf("node2 data: %d\n", pHead->pNext->data);
	printf("p1->data: %d\n", p1->data);
	
	//打印第三个节点的值
	printf("node3 data: %d\n", pHead->pNext->pNext->data);
	printf("p2->data: %d\n", p2->data);
	
	return 0;
}

void * set_node(void)
{
	struct node* p = (struct node *)malloc(sizeof(struct node*));
}






























