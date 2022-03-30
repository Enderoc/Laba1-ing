#include <cstdio>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO; //переменная для хранения указателя на буфер вершин

static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT); //очищаем буфер кадра

	glEnableVertexAttribArray(0); //индексируем атрибут вершины
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //обратно привязываем буфер, приготавливая его для отрисовки
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //говорим конвейеру как воспринимать данные внутри буфера

	glDrawArrays(GL_POINTS, 0, 1); //вызываем функцию для отрисовки

	glDisableVertexAttribArray(0); //отключаем атрибут вершины

	glutSwapBuffers(); //меняем фоновый буфер и буфер кадра местами
}

static void GlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //инициализируем GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // настраиваем некоторые опции GLUT

	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 02: Dot"); //Параметры окна

	GlutCallbacks(); //присоединяем функцию RenderSceneCB к GLUT

	/*Инициализируем GLEW и проверяем на ошибки*/
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //цвет фона окна, который будет использован во время очистки буфера кадра

	CreateVertexBuffer();

	glutMainLoop(); //передаём контроль GLUT'у

	return 0;
}