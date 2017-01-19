#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct node
{
	int data;					//数据段，用来存取数据的地方
	struct node *pPrev;			//指针，用来指向上一个节点
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
	p->pPrev = NULL;
	
	return p;
}

void set_tail(struct node *pH, struct node *new)
{
	struct node* p = pH;
	
	//先找到尾节点，然后就链接就可以了
	while(NULL != p->pNext)
	{
		p = p->pNext;
	}
	
	p->pNext = new;
	new->pPrev = p;
}

void set_head(struct node *pH, struct node *new)
{
	struct node* p = pH;
	
	//先来判断它是不是只有头节点
	if(NULL == p->pNext)
	{
		new->pPrev = p;
		p->pNext = new;
	}
	else
	{
		//一共是四个地方需要修改的
		p->pNext->pPrev = new;			//第一个节点的前指针，第一个节点指向新节点
		new->pPrev = p;					//新节点的前指针，新节点指向头结点
		new->pNext = p->pNext;			//新节点的后指针，新节点要连第一个节点
		p->pNext = new;					//头节点的后指针，头结点要连新节点
	}
}

int bianli(struct node *pH)
{
	struct node* p = pH;
	
	if(NULL == p->pNext)
	{
		printf("NULL.\n");
	}
	
	while(p->pNext != NULL)
	{
		p = p->pNext;
		printf("node data:%d.\n",p->data);
	}
}

//双链表删除节点
int delete_node(struct node* PH, int data)
{
	struct node* p = PH;
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		 
		//看是不是尾节点这一步还是要看的，在单链表的时候就没事，但是在双链表的情况就有事了
		if(NULL == p->pNext)
		{
			p->pPrev->pNext = NULL;
			
			free(p);
			return 0;
		}
		else
		{
			p->pNext->pPrev = p->pPrev;
			p->pPrev->pNext = p->pNext;
			
			free(p);
			
			return 0;
		}
	}
	
	printf("error.\n");
	return -1;
}

int main(void)
{
	//链表的头指针
	struct node * pHead = set_node(0);			//有一个头节点
	//struct node* p = pHead;
	
	set_tail(pHead, set_node(11));					//链接节点
	
	//set_tail(pHead, set_node(12));					//链接节点
	
	//set_tail(pHead, set_node(13));
	
	//set_head(pHead, set_node(21));
	
	//set_head(pHead, set_node(22));
	
	//set_head(pHead, set_node(23));
	
	bianli(pHead);
	
	printf("---------------------------------------------------------\n");

	delete_node(pHead, 11);
	bianli(pHead);
	
	return 0;
}






