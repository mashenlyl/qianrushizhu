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

//这里就是有头节点的好处了，这样就可以直接这样写了
//就好像那个数组一样的第0个元素，这里的头节点就是链表的第零个元素了
void bianli(struct node* PH)
{
	struct node* p = PH;
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		printf("p->data: %d\n", p->data);
	}
}

//删除节点的方法：就是把要删除的那个节点的指针放到它前一个节点处就可以了
//做法：首先肯定要根据删除的条件来找到那个节点，然后再删除那个节点
//这里的条件是：节点内的数据和data相同，就删除了它，如果有多个相同的就删除靠前的那一个，每次只能删除一个节点
int delete_node(struct node* PH, int data)
{
	struct node* p = PH;
	struct node* pRev;
	
	while(NULL != p->pNext)
	{
		pRev = p;
		p = p->pNext;
		
		if(data == p->data)
		{
			pRev->pNext = p->pNext;
			free(p);
			return 0;
		}
	}
	
	return -1;
}

//算法就是：把节点一个一个拿出来，然后头插进去就可以了
void nixu(struct node* PH)
{
	struct node* p = PH->pNext;
	struct node* pBack;
	
	
	//如果这里不判断，就会陷入死循环
	if((PH->pNext == NULL) || (p->pNext == NULL))
	{
		return;
	}
	
	while(NULL != p->pNext)
	{
		//还没插之前保存好它指向的节点
		pBack = p->pNext;
		//只有头节点和第一个节点的时候
		if(p == PH->pNext)
		{
			p->pNext = NULL;
		}
		else
		{
			p->pNext = PH->pNext;
			PH->pNext = p;
		}
		p = pBack;
	}
	//最后，由于NULL = p->pNext退出循环导致最后一个丧失了，所以，要把最后一个插到头部那里
	set_node_head(PH, p);
}

int main(void)
{
	//链表的头指针
	//这里是有头节点的
	struct node * pHead = set_node(0);
	
	set_new_node_tail(pHead, set_node(51));				//链接节点
	
	set_new_node_tail(pHead, set_node(61));				//链接节点
	
	set_new_node_tail(pHead, set_node(71));
	
	set_new_node_tail(pHead, set_node(81));
	
	bianli(pHead);
	
	nixu(pHead);
	printf("-------------------------逆序后------------------------------\n");
	bianli(pHead);
	
	return 0;
}




























