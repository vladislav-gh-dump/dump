#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>



// �������
int matrix[6][6];
// ���-�� ����� � �������� �������
int n = 6;

void set_rand_nums(int a, int b);
void show_matrix(void);
void num_column(void);
void try_num_column(int num);

int main()
{
    setlocale(LC_ALL, "Rus");

    // ���������� ������� ���������� �������
    set_rand_nums(-9, 9);

    // ����� ������� � �������
    show_matrix();

    // ����� ������� � ���������� �� ������������� ��������� �������� ������������
    num_column();
 
    return 0;
}


// ���������� ������� ���������� �������
void set_rand_nums(int a, int b)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = a + rand() % (b - a);
        }
    }

    return;
}


// ����� ������� � �������
void show_matrix()
{
    // �����
    HANDLE hStd;

    // ����� ��� ���������� �����
    hStd = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                // ��������� ����� (�����, ���� | �������� �����)
                SetConsoleTextAttribute(hStd, 3); // ������� ����
            }
            else if (i < j)
            {
                SetConsoleTextAttribute(hStd, 4); // ������� ����
            }
            else
            {
                SetConsoleTextAttribute(hStd, 2); // ������� ����
            }

            // ����� ����� �������
            printf("| %3d ", matrix[i][j]);
        }
        printf("|\n");

        SetConsoleTextAttribute(hStd, 8); // ����� ����
        // ���������� �����������
        printf("--------------------------------------\n");
    }
    printf("\n");

    return;
}


// ����� ������� � ���������� �� ������������� ��������� �������� ������������
void num_column()
{
    // ���������� �����, �������
    int min_num = 100, column = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // �������� �������� ������������
            if (i < j)
            {
                // ������������� �������� ������ ������������ �����
                if (matrix[i][j] > 0 && matrix[i][j] < min_num)
                {
                    min_num = matrix[i][j];
                    column = j + 1; // �� 1 ������, ��� ��� ������ ������ 0
                }
            }

        }
    }

    printf("����� ������� � ���������� �� ������������� ��������� �������� ������������: %d\n", column);

    // �������� ������ ������� 
    try_num_column(column);

    return;
}


// �������� ������ �������
void try_num_column(int num)
{
    int result = 0;
    // ��� ������� �����
    if (num % 2 == 0)
    {
        // ����� ��������� �������
        for (int i = 0; i < n; i++)
        {
            if (i < num - 1)
                result += matrix[i][num - 1];
        }

        printf("����� ������� ������, ����� ���������: %d\n", result);
    }
    else
    {
        // ��� ��������� �����
        result = 1;

        // ������������ ��������� �������
        for (int i = 0; i < n; i++)
        {
            if (i < num - 1)
                result *= matrix[i][num - 1];
        }

        printf("����� ������� ��������, ������������ ���������: %d\n", result);
    }


    return;
}