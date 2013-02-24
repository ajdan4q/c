#include <stdio.h>

char* bsort(char arr[]);
void bsortp(char* arr);
void bsort3(char *arr);
void swap();
//char[] bsort(char arr[]); // ERROR 函数不能返回数组，只能返回数组首地址
// 不要返回局部变量的地址，因为在离开函数之后，该变量会被释放。返回值

main()
{
    char a[] = "dcba";
    printf("%s\n", a);
    //bsort(a);
    bsortp(a);
    //bsort3(a);
    printf("%s\n", a);
}

// 数组索引越界，会发生段错误
// 如下函数之前是判断arr[i]!='\0',但随后代码会使用a[i+1],引发数组越界
/*
 * 首先，设置一个状态值done，指示排序是否完成
 * 逐个访问数组里的元素，比较数组当前INDEX是否大于NEXT INDEX
 * 如是，则交换INDEX, INDEX+1的值（因是冒泡排序，小值会浮上来）
 * 并设置排序完成状态值
 * 判断是否排序完成，判断状态值是否有设置，即是否有交换
 * 否，则调用本身继续排序；然，则返回排序好的数组
 * 注意：迭代数组的元素时，是判断下个元素值是否为'\0'
 */
/* 冒泡排序的最好与最坏情况
 * 如数组元素值，按升序排序好，则只需迭代一次数组元素。
 * 如按降序排序，则需要把迭代多次，把小的值交换到数组前面。
 */
char* bsort(char arr[])
{
    short done=1, i;
    // for () 内不允许变量声明
    for (i=0; arr[i+1] != '\0'; i++)
    if ( arr[i] > arr[i+1])
    {
        /*
        int tmp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = tmp;
        */
        swap(&arr[i], &arr[i+1]);
        done=0;
    }
    if (done)
        return arr;
    bsort(arr);
}

/* 指针版本，嗯，要多练习指针的使用呀 */
/* 更改了输入参数值，是否设置另一个内部变量，保留输入参数值不变*/
void bsortp(char* arr)
{
    short flag;
    char *initp = arr; // 保存数组的首元素地址，下面会对地址进行算术加运行
    for (flag =0; *(arr+1) != '\0'; arr++ )
    {
        if ( *arr > *(arr+1)) // 比较元素 与 下个元素的大小
        {
            swap(arr, arr+1);
            flag = 1;
        }
    }
    if (! flag)
        return;
    bsortp(initp); //数组的初始地址，传给函数，以便从头开始比较
}

// 非递归版本
void bsort3(char *arr)
{
    char *ap; // 用于指针算法运算
    int flag; // 判断是否排序完成标志
    while (1)
    {
        for (flag = 0, ap = arr; *(ap+1) != '\0'; ap++)
        {
            if ( *ap > *(ap+1))
            {
                swap(ap, ap+1);
                flag = 1;
            }
        }
        if ( ! flag)
            return; // or break
    }
}

/* 交换值,不是交换指针
 * 因C是值传递，swap是更改形参的值，所以将参数的地址传给swap
 * */
void swap(char* a, char* b) // int* a will ERROR, why?
{
    printf("%c - %c TO ", *a, *b);
    //char tp = *a;
    int tp = *a;
    *a = *b;
    *b = tp;
    printf("%c - %c\n", *a, *b);
}
