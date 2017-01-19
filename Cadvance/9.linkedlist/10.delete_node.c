#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct node
{
	int data;					//���ݶΣ�������ȡ���ݵĵط�
	struct node *pPrev;			//ָ�룬����ָ����һ���ڵ�
	struct node *pNext;			//ָ�룬����ָ����һ���ڵ�
};

struct node* set_node(int data)
{
	//������һ���ڵ�
	//��malloc�����ڴ棬���Һͽڵ�󶨡�
	struct node* p = (struct node *)malloc(sizeof(struct node));
	
	//����Ƿ����뵽�ڴ���
	if(NULL == p)
	{
		printf("error.\n");
		return NULL;
	}
	
	//���ڴ�,���ַ���
	bzero(p, sizeof(struct node));
	//memset(p, 0, sizeof(struct node));		//��0������ڴ�
	
	//�������
	p->data = data;
	p->pNext = NULL;
	p->pPrev = NULL;
	
	return p;
}

void set_tail(struct node *pH, struct node *new)
{
	struct node* p = pH;
	
	//���ҵ�β�ڵ㣬Ȼ������ӾͿ�����
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
	
	//�����ж����ǲ���ֻ��ͷ�ڵ�
	if(NULL == p->pNext)
	{
		new->pPrev = p;
		p->pNext = new;
	}
	else
	{
		//һ�����ĸ��ط���Ҫ�޸ĵ�
		p->pNext->pPrev = new;			//��һ���ڵ��ǰָ�룬��һ���ڵ�ָ���½ڵ�
		new->pPrev = p;					//�½ڵ��ǰָ�룬�½ڵ�ָ��ͷ���
		new->pNext = p->pNext;			//�½ڵ�ĺ�ָ�룬�½ڵ�Ҫ����һ���ڵ�
		p->pNext = new;					//ͷ�ڵ�ĺ�ָ�룬ͷ���Ҫ���½ڵ�
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

//˫����ɾ���ڵ�
int delete_node(struct node* PH, int data)
{
	struct node* p = PH;
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		 
		//���ǲ���β�ڵ���һ������Ҫ���ģ��ڵ������ʱ���û�£�������˫����������������
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
	//�����ͷָ��
	struct node * pHead = set_node(0);			//��һ��ͷ�ڵ�
	//struct node* p = pHead;
	
	set_tail(pHead, set_node(11));					//���ӽڵ�
	
	//set_tail(pHead, set_node(12));					//���ӽڵ�
	
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






