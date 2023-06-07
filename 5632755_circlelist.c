#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data);
ListNode* insert_last(ListNode* head, element data);
void print_list(ListNode* head);

int main(void)
{
	ListNode* head = NULL;
	int menu_num = 0;
	int number = 0;

	while (1)
	{
		printf("==========�޴�==========\n\n");
		printf("(1)����Ʈ ó���� �߰�\n");
		printf("(2)����Ʈ �������� �߰�\n");
		printf("(3)����Ʈ ó�� ��� ����\n");
		printf("(4)����Ʈ ������ ��� ����\n");
		printf("(5)����Ʈ ���\n");
		printf("(0)����\n\n");


		printf("�޴��� �����ϼ���: ");
		scanf_s("%d", &menu_num);

		switch (menu_num)
		{
		case 1:
			printf("���ڸ� �Է��ϼ���: ");
			scanf_s("%d", &number);
			head = insert_first(head, number);
			break;

		case 2:
			printf("���ڸ� �Է��ϼ���: ");
			scanf_s("%d", &number);
			head = insert_last(head, number);
			break;

		case 3:
			printf("����Ʈ ó�� ��� �����Լ�\n");
			break;

		case 4:
			printf("����Ʈ ������ ��� �����Լ�\n");
			break;
		case 5:
			print_list(head);
			printf("\n");
			break;
		case 0:
			exit(0);
		}
	}
}


ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = node;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}
/*ListNode* removed_first(ListNode* head)
{
	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
	removed = head;
	head = 
}*/
/*removed �����ͻ���
removed�� ù��° ��� ����Ű�� �ϱ�
ù��°��带 ����Ű�� head���� ������ ��ũ ����Ű�� �ϱ�
������ ����� ��ũ���� ù��°����� ��ũ��(�ι�°���)�� ����Ű�� �ϱ�
�ϳ� ���������� head���� NULL�� �ٲٱ�
free���ֱ�
*/

/*
removed ������ ����
removed�� ������ ��� ����Ű�� �ϱ�
p��� ������ ���� ���� ��������带 ����Ű������, p�� ����Ű�� ��ũ�� head��
���������� p�� ����Ű�� �ִ� ���� link���� ����... p = p->link
���������� 2��° ��� �Ѿư��� �����
head���� ������ ���� ������ ����� �� ��� ã��
ã�� ����� ��ũ���� �� �ճ�� ����Ű�� �����
free
*/
