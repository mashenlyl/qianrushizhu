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

//这是在尾巴上面连上去
void set_new_node_tail(struct node* ph, struct node* new)
{
	struct node* p = ph;
	int cnt = 0;
	
	//第一步：用pHead指针来寻找最后那个节点的指针
	while(NULL != p->pNext)
	{
		p = p->pNext;
		cnt++;
	}
	
	//第二步：把它的头地址链接到最后那个节点的指针上
	p->pNext = new;
	
	ph->data = cnt + 1;
}

void set_new_node_head(struct node** ph, struct node* new)
{
	struct node** p = ph;
		
	//第一步：新的节点的指针指向原来第一个节点的指针
	new->pNext = *p;
	
	//第二步：用pHead指针指向新建的节点
	*p = new;
}

//有头节点的比没有头节点的头部插入更简单些
void set_node_head(struct node* ph, struct node* new)
{
	struct node* p = ph;
		
	//第一步：新的节点的指针指向原来第一个节点的指针
	new->pNext = p->pNext;
	
	//第二步：用pHead指针指向新建的节点
	p->pNext = new;
	
	p->data++;
}

int main(void)
{
	//链表的头指针
	//这里是有头节点的
	struct node * pHead = set_node(0);
	
	set_new_node_tail(pHead, set_node(1));				//链接节点
	
	set_new_node_tail(pHead, set_node(2));				//链接节点
	
	set_node_head(pHead, set_node(3));
	
	//打印头节点的值
	printf("node1 data: %d\n", pHead->data);
	
	//打印第一个节点的值
	printf("node2 data: %d\n", pHead->pNext->data);
	
	//打印第二个节点的值
	printf("node3 data: %d\n", pHead->pNext->pNext->data);
	
	//第三
	printf("node4 data: %d\n", pHead->pNext->pNext->pNext->data);
	
	return 0;
}




























