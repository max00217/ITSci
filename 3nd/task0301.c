/* 과제 안내 - stack
위의 메인 함수와 같이 스택을 실행하려고 합니다.
이때 필요한 기능은 아래와 같습니다.

void init_stack(StackType *s)		// 스택 생성 함수
int is_empty(StackType *s)		// 공백 상태 검출 함수
int is_full(StackType *s)			// 포화 상태 검출 함수
void push(StackType *s, element item)	// push 함수
element pop(StackType *s)		// 삭제함수

각 함수의 비어있는 부분을 채워서 프로그램을 완성하세요.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element *data;		// data 포인터 
	int capacity;		// 현재 크기
	int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 100;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType *s) {
  return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s) {
  return (s->top == (s->capacity - 1));
}

// push 함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
  else return s->data[(s->top)--];
}

int main(void)
{
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	free(s.data);
	return 0;
}
