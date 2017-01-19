#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

struct node
{
	int data;					//���ݶΣ�������ȡ���ݵĵط�
	struct node *pNext;			//ָ�룬����ָ����һ���ڵ�
};

int main(void)
{
	//�����ͷָ��
	struct node * pHead = NULL;
	
	/********************************************/
	//������һ���ڵ�
	//��malloc�����ڴ棬���Һͽڵ�󶨡�
	struct node* p0 = (struct node *)malloc(sizeof(struct node));
	
	//����Ƿ����뵽�ڴ���
	if(NULL == p0)
	{
		printf("error.\n");
		return -1;
	}
	
	//���ڴ�,���ַ���
	bzero(p0, sizeof(struct node));
	//memset(p0, 0, sizeof(struct node));		//��0������ڴ�
	
	//�������
	p0->data = 1;
	p0->pNext = NULL;
	
	pHead = p0;					//ָ��ͷָ��
	/********************************************/
	
	/********************************************/
	//�����ڶ����ڵ�
	//��malloc�����ڴ棬���Һͽڵ�󶨡�
	struct node* p1 = (struct node *)malloc(sizeof(struct node));
	
	//����Ƿ����뵽�ڴ���
	if(NULL == p1)
	{
		printf("error.\n");
		return -1;
	}
	
	//���ڴ�,���ַ���
	bzero(p1, sizeof(struct node));
	//memset(p1, 0, sizeof(struct node));		//��0������ڴ�
	
	//�������
	p1->data = 2;
	p1->pNext = NULL;
	
	p0->pNext = p1;					//���ӽڵ�
	/********************************************/
	
	/********************************************/
	//�����������ڵ�
	//��malloc�����ڴ棬���Һͽڵ�󶨡�
	struct node* p2 = (struct node *)malloc(sizeof(struct node));
	
	//����Ƿ����뵽�ڴ���
	if(NULL == p2)
	{
		printf("error.\n");
		return -1;
	}
	
	//���ڴ�,���ַ���
	bzero(p2, sizeof(struct node));
	//memset(p2, 0, sizeof(struct node));		//��0������ڴ�
	
	//�������
	p2->data = 3;
	p2->pNext = NULL;
	
	p1->pNext = p2;					//���ӽڵ�
	/********************************************/
	//ע�⣺����ķ��ʱ���ֻͨ��pHead������ͨ��p0,1,2������
	
	//��ӡ��һ���ڵ��ֵ
	printf("node1 data: %d\n", pHead->data);
	printf("p0->data: %d\n", p0->data);
	
	//��ӡ�ڶ����ڵ��ֵ
	printf("node2 data: %d\n", pHead->pNext->data);
	printf("p1->data: %d\n", p1->data);
	
	//��ӡ�������ڵ��ֵ
	printf("node3 data: %d\n", pHead->pNext->pNext->data);
	printf("p2->data: %d\n", p2->data);
	
	return 0;
}

void * set_node(void)
{
	struct node* p = (struct node *)malloc(sizeof(struct node*));
}






























