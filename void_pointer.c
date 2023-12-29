int arr[] = {1, 2, 3, 4, 5};
void *ptr = arr;
int *int_ptr = (int *)ptr;
printf("%d\n", *(int_ptr + 2));
