#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct node
{
	int data;					//数据段，用来存取数据的地方
	struct node *pNext;			//指针，用来指向下一个节点
};

struct node* set_node(int data)
{
	//创建第一个节点
	//用malloc申请内存，并且和节点绑定。
	struct node* p = (struct node *)malloc(sizeof(struct node));
	
	//检查是否申请到内存了
	if(NULL == p)
	{
		printf("error.\n");
		return NULL;
	}
	
	//清内存,两种方法
	bzero(p, sizeof(struct node));
	//memset(p, 0, sizeof(struct node));		//用0来填充内存
	
	//填充数据
	p->data = data;
	p->pNext = NULL;
	
	return p;
}

int main(void)
{
	//链表的头指针
	struct node * pHead = set_node(1);
	
	pHead->pNext = set_node(2);					//链接节点
	
	pHead->pNext->pNext = set_node(3);					//链接节点
	
	//打印第一个节点的值
	printf("node1 data: %d\n", pHead->data);
	
	//打印第二个节点的值
	printf("node2 data: %d\n", pHead->pNext->data);
	
	//打印第三个节点的值
	printf("node3 data: %d\n", pHead->pNext->pNext->data);
	
	return 0;
}




























