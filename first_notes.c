#includelist
<stdlib.h>     // malloc, calloc, realloc, free
    <string.h> // strcpy
    <stdio.h>  // printf
    <
    Declaring int * = NULL;
char ** = NULL;
float * = NULL;
Allocating Dynamic Memory

    Ptr = (datatype *)malloc(size);
example int *p;
p = (int *)malloc(20)
    p = (int *)malloc(n * size(int))

        malloc({count} * sizeof({data_type}));

calloc({count}, sizeof({data_type}));
(this one works better than malloc but is slower)
    realloc((void *){old_block}, {count} * sizeof({data_type}));
(might need to cast{old_block} to(void *))
    free()

        malloc EXAMPLE
    Void main()
{
    int *p, n;
    printf("Enter a value: ");
    scanf("%d", &n);
    p = (int *)malloc(n * 2);
    printf("Entering integers: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", p + i);
    }
    free(p);
}

int a;
a = 5 at 204 int * p;
p = a location at 204 at 64 p = &a;
&a = address of a
    print p = 204 print & a = 204 print & p = 64 print * p = 5 >> derefrencing{change pointer to p to 8 * p = 8} print a = 8

                                                                                                                           & returns address of variable;