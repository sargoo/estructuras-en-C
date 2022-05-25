#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define DIM 30
typedef struct
{
    int matricula;
    char nombre[DIM];
    char genero[DIM];
} stAlumno;

stAlumno cargarUnAlumno();
void mostrarUnAlumno(stAlumno a);
int cargarListado (stAlumno a[], int dim);
void mostrarListado (stAlumno a[], int v);

int main()
{
    int validos = 0;
    stAlumno alumno[DIM];

    validos = cargarListado(alumno, DIM);
    mostrarListado(alumno, validos);
    getch();
    return 0;
}

// Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.

stAlumno cargarUnAlumno()
{
    stAlumno a;

    printf("Ingrese matricula del alumno: ");
    fflush(stdin);
    scanf("%i", &a.matricula);
    printf("\n Ingrese nombre del alumno: ");
    fflush(stdin);
    gets(a.nombre);
    printf("\n Ingrese M o F para el genero del alumno: ");
    fflush(stdin);
    gets(a.genero);

    return a;
}

void mostrarUnAlumno(stAlumno a)
{
    printf("Matricula: %i \n", a.matricula);
    printf("Nombre: %s \n", a.nombre);
    printf("Genero: %s \n", a.genero);
    printf("------------------------------------ \n");
}

int cargarListado (stAlumno a[], int dim)
{
    int i = 0;
    char opcion;
    while (i < dim && opcion != ESC)
    {
        a[i] = cargarUnAlumno();
        i++;

        printf("\n Seguir cargando alumnos? CUALQ. TECLA: SI / ESC: NO");
        opcion = getch();
        system("cls");
    }

    return i;
}

void mostrarListado (stAlumno a[], int v)
{

    for(int i = 0; i < v; i ++)
    {

        mostrarUnAlumno(a[i]);
    }
}
