#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct node
{
	int data;					//���ݶΣ�������ȡ���ݵĵط�
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
	
	return p;
}

//������β����������ȥ
void set_new_node_tail(struct node* ph, struct node* new)
{
	struct node* p = ph;
	
	//��һ������pHeadָ����Ѱ������Ǹ��ڵ��ָ��
	while(NULL != p->pNext)
		p = p->pNext;
	
	//�ڶ�����������ͷ��ַ���ӵ�����Ǹ��ڵ��ָ����
	p->pNext = new;
}

void set_new_node_head(struct node** ph, struct node* new)
{
	struct node** p = ph;
		
	//��һ�����µĽڵ��ָ��ָ��ԭ����һ���ڵ��ָ��
	new->pNext = *p;
	
	//�ڶ�������pHeadָ��ָ���½��Ľڵ�
	*p = new;
}

int main(void)
{
	//�����ͷָ��
	struct node * pHead = set_node(1);
	
	set_new_node_tail(pHead, set_node(5));				//���ӽڵ�
	
	set_new_node_tail(pHead, set_node(3));				//���ӽڵ�
	
	set_new_node_head(&pHead, set_node(55555));
	
	//��ӡ��һ���ڵ��ֵ
	printf("node1 data: %d\n", pHead->data);
	
	//��ӡ�ڶ����ڵ��ֵ
	printf("node2 data: %d\n", pHead->pNext->data);
	
	//��ӡ�������ڵ��ֵ
	printf("node3 data: %d\n", pHead->pNext->pNext->data);
	
	printf("node4 data: %d\n", pHead->pNext->pNext->pNext->data);
	
	return 0;
}




























