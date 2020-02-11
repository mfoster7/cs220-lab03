#include <stdio.h>
#define BIT(n) (1 << (n))
#define BIT_SET(v, mask) (v |= (mask))
#define BIT_CLEAR(v, mask) (v &= ~(mask))
#define BIT_FLIP(v, mask) (v ^= (mask))
#define IS_SET_ANY(v, mask) (v & (mask))
#define IS_CLEAR_ANY(v, mask) (v & ~(mask))
#define BIT_MASK(len) (BIT(len)-1)
#define BF_MASK(start, len) ((BIT_MASK(len) << start -len))
#define BF_PREP(x, start, len) (BF_MASK(start, len) | x)

//char[] val = {'z','z','z','z','x','x','x','y','y','y','y','\0'};

struct bad_struct{
	short s1;
	long l1;
	short s2;
};

struct good_struct{
	short s1;
	short s2;
	long l1;
};

union unit{
	char c;
	int i;
	long l;
};

unsigned int foo(int array[]){
	return sizeof(array);
}

void print_in_binary(unsigned int x){
	unsigned i;
	for(i = 1 << 31; i > 0; i = i / 2){
		if(IS_SET_ANY(x, i)){
			printf("%d", 1);
		}else{
			printf("%d", 0);
		}
	}
	printf("\n");
}

int main(){
	int x[30];
	int v = 15;
	struct good_struct gs;
	struct bad_struct bs;
	union unit u;
	printf("%lu\n", sizeof(bs));
	printf("%lu\n", sizeof(gs));
	printf("%d\n", sizeof(u));
	printf("%p\n%p\n%p\n", (bs.s1), (bs.l1), (bs.s2));
	printf("%p\n%p\n%p\n", (gs.s1), (gs.s2), (gs.l1));
	printf("%p\n%p\n%p\n", (u.c), (u.i), (u.l));
	//scanf("%lu", &u.l);
	printf("%c\n%lu\n%d\n%s\n", u.c, u.l, u.i, &u.l);
	printf("%d\n", sizeof(x));
	printf("%d\n", foo(x));
	print_in_binary(BIT(10));
	print_in_binary(BIT_SET((v), BIT(10)));
	print_in_binary(BIT_CLEAR((v), BIT(10)));
	print_in_binary(BIT_FLIP((v), BIT(2)));
	print_in_binary(BF_MASK(31, 10));
	print_in_binary(BF_PREP(7, 31, 10));
	return 0;
}
