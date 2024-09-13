/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_4.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 21/7/2024
 *  version    : v1.0
 *  require    : Small Triangles,Large Triangles.
 */
#include <stdio.h>
#include <math.h>
typedef struct
{
    int a, b, c;
    double area;
} Triangle;
double calculate_area(int a, int b, int c);
void swap(Triangle *t1, Triangle *t2);
void bubble_sort(Triangle triangles[], int n);
int main()
{
    int n;
    scanf("%d", &n);
    Triangle triangles[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &triangles[i].a, &triangles[i].b, &triangles[i].c);
        triangles[i].area = calculate_area(triangles[i].a, triangles[i].b, triangles[i].c);
    }
    bubble_sort(triangles, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", triangles[i].a, triangles[i].b, triangles[i].c);
    }
    return 0;
}
double calculate_area(int a, int b, int c)
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
void swap(Triangle *t1, Triangle *t2)
{
    Triangle temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}
void bubble_sort(Triangle triangles[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (triangles[j].area > triangles[j + 1].area)
            {
                swap(&triangles[j], &triangles[j + 1]);
            }
        }
    }
}
