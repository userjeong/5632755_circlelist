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
		printf("==========메뉴==========\n\n");
		printf("(1)리스트 처음에 추가\n");
		printf("(2)리스트 마지막에 추가\n");
		printf("(3)리스트 처음 노드 삭제\n");
		printf("(4)리스트 마지막 노드 삭제\n");
		printf("(5)리스트 출력\n");
		printf("(0)종료\n\n");


		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &menu_num);

		switch (menu_num)
		{
		case 1:
			printf("숫자를 입력하세요: ");
			scanf_s("%d", &number);
			head = insert_first(head, number);
			break;

		case 2:
			printf("숫자를 입력하세요: ");
			scanf_s("%d", &number);
			head = insert_last(head, number);
			break;

		case 3:
			printf("리스트 처음 노드 삭제함수\n");
			break;

		case 4:
			printf("리스트 마지막 노드 삭제함수\n");
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
/*removed 포인터생성
removed가 첫번째 노드 가리키게 하기
첫번째노드를 가리키던 head값이 마지막 링크 가리키게 하기
마지막 노드의 링크값을 첫번째노드의 링크값(두번째노드)를 가리키게 하기
하나 남았을때는 head값을 NULL로 바꾸기
free해주기
*/

/*
removed 포인터 생성
removed가 마지막 노드 가리키게 하기
p라는 변수를 만들어서 먼저 마지막노드를 가리키게한후, p가 가리키는 링크가 head와
같을때까지 p가 가리키고 있는 것의 link값을 복사... p = p->link
마지막에서 2번째 노드 쫓아가게 만들기
head값과 같으면 내가 삭제할 노드의 앞 노드 찾음
찾은 노드의 링크값을 맨 앞노드 가리키게 만들기
free
*/
