#include <stdio.h>

void update(int *a,int *b) {
    *a = *a + *b;
    *b = (*b+*a-3* *b)>0 ? (*b+*a-3* *b) : (-(*b+*a-3* *b));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}