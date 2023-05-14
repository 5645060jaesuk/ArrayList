#define MAX_LIST_SIZE 100 // 리스트의 최대크기
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{
	int cnt = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {

		for (int i = (L->size - 1); i >= pos; i--)
		{

			L->array[i + 1] = L->array[i];
			cnt++;
		}

		L->array[pos] = item;
		L->size++;
		printf("Move : %d\n", cnt);
	}


}

element delete(ArrayListType* L, int pos)
{
	element item;
	int cnt = 0;

	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
		cnt++;

	}

	L->size--;
	printf("Move %d\n", cnt);
	return item;
}

int main(void)
{
	ArrayListType list;
	init(&list);

	while (1)
	{
		int n;
		int num;
		int pos;
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the Menu : ");
		scanf_s("%d", &n);
		if (n == 1)
		{
			printf("Enter the number and position : ");
			scanf_s("%d %d", &num, &pos);
			insert(&list, pos, num);

			if (is_full(&list) || (pos < 0) || (pos > list.size))
			{
				printf("List size is zero. Please enter again(number position) :");
				scanf_s("%d %d", &num, &pos);
				insert(&list, pos, num);
			}


		}
		else if (n == 2)
		{
			if (is_empty(&list))
			{
				printf("List is empty\n");
			}
			else
			{
				printf("Enter the position : ");
				scanf_s("%d", &pos);
				printf("Delete : %d\n", delete(&list, pos));
			}

		}
		else if (n == 3)
		{
			print_list(&list);
		}
		else if (n == 0)
		{
			printf("Exit the program");
			break;
		}
		else
		{
			printf("Invalid Menu. Please select again..\n");
		}
	}
}