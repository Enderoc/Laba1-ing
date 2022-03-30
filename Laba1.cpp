#include <GL/freeglut.h>

static void RenderSceneCB() //Функция рендера
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

static void GlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB); //отрисовка glut'ом 1 кадра с окном
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //инициализируем glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // настраиваем некоторые опции glut

	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 01"); //Параметры окна

	glutDisplayFunc(RenderSceneCB); //присоединяем функцию RenderSceneCB к glut

	glClearColor(0.0f, 0.0f, 1.0f, 0.0f); //цвет фона окна, который будет использован во время очистки буфера кадра
	glutMainLoop(); //передаём контроль GLUT'у

	glClear(GL_COLOR_BUFFER_BIT); //очистка буфер кадра
	glutSwapBuffers(); //меняем фоновый буфер и буфер кадра местами

	return 0;
}
