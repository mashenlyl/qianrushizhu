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

int main(void)
{
	//�����ͷָ��
	struct node * pHead = set_node(1);
	
	pHead->pNext = set_node(2);					//���ӽڵ�
	
	pHead->pNext->pNext = set_node(3);					//���ӽڵ�
	
	//��ӡ��һ���ڵ��ֵ
	printf("node1 data: %d\n", pHead->data);
	
	//��ӡ�ڶ����ڵ��ֵ
	printf("node2 data: %d\n", pHead->pNext->data);
	
	//��ӡ�������ڵ��ֵ
	printf("node3 data: %d\n", pHead->pNext->pNext->data);
	
	return 0;
}




























