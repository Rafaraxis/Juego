// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>

using namespace std;

//Declaracion de ventana 
GLFWwindow *window;
GLfloat red, green, blue;
GLfloat ty = -0.9f;
GLfloat tx = 0.0f;

double tiempoAnterior = 0.0;
double velocidad = 0.4;

//Carros de enfrente
GLfloat enemigoX = 0.0f;
GLfloat enemigoY = 0.7f;
GLfloat direccionEnemigo = 90; 

GLfloat enemigoX_dos = 0.7f;
GLfloat enemigoY_dos = 0.6f;
GLfloat direccionEnemigo_dos = 90;

GLfloat enemigoX_tres = 0.7f;
GLfloat enemigoY_tres = 0.4f;
GLfloat direccionEnemigo_tres = 270;

GLfloat enemigoX_cuatro = 0.0f;
GLfloat enemigoY_cuatro = 0.2f;
GLfloat direccionEnemigo_cuatro = 270;

//huecos
GLfloat enemigoX_cinco = 0.0f;
GLfloat enemigoY_cinco = 0.0f;
GLfloat direccionEnemigo_cinco = 270;

GLfloat enemigoX_seis = 0.5f;
GLfloat enemigoY_seis = 0.0f;
GLfloat direccionEnemigo_seis = 270;

GLfloat enemigoX_siete = -0.5f;
GLfloat enemigoY_siete = 0.0f;
GLfloat direccionEnemigo_siete = 270;

//Carros de abajo
GLfloat enemigoX_ocho= 0.0f;
GLfloat enemigoY_ocho = -0.2f;
GLfloat direccionEnemigo_ocho = 90;

GLfloat enemigoX_nueve = 0.7f;
GLfloat enemigoY_nueve = -0.4f;
GLfloat direccionEnemigo_nueve = 90;

GLfloat enemigoX_diez = 0.7f;
GLfloat enemigoY_diez = -0.6f;
GLfloat direccionEnemigo_diez = 270;

GLfloat enemigoX_once = 0.0f;
GLfloat enemigoY_once = -0.7f;
GLfloat direccionEnemigo_once = 270;


GLfloat ganar = 0.9f;
GLfloat direccionEnemigo_ganar = 270;



GLfloat angulo = 0.0f;
GLfloat velocidadAngular = 180.0f;

void checarGanar()
{
	if (tx >= ganar - 0.08
		&& tx <= ganar + 0.08
		&& ty >= ganar - 0.08
		&& ty <= ganar + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_once()
{
	if (tx >= enemigoX_once - 0.08
		&& tx <= enemigoX_once + 0.08
		&& ty >= enemigoY_once - 0.08
		&& ty <= enemigoY_once + 0.08)
	{
		exit(0);
	}
}
void checarColisiones_diez()
{
	if (tx >= enemigoX_diez - 0.08
		&& tx <= enemigoX_diez + 0.08
		&& ty >= enemigoY_diez - 0.08
		&& ty <= enemigoY_diez + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_nueve()
{
	if (tx >= enemigoX_nueve - 0.08
		&& tx <= enemigoX_nueve + 0.08
		&& ty >= enemigoY_nueve - 0.08
		&& ty <= enemigoY_nueve + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_ocho()
{
	if (tx >= enemigoX_ocho - 0.08
		&& tx <= enemigoX_ocho + 0.08
		&& ty >= enemigoY_ocho - 0.08
		&& ty <= enemigoY_ocho + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_siete()
{
	if (tx >= enemigoX_siete - 0.08
		&& tx <= enemigoX_siete + 0.08
		&& ty >= enemigoY_siete - 0.08
		&& ty <= enemigoY_siete + 0.08)
	{
		exit(0);
	}
}


void checarColisiones_seis()
{
	if (tx >= enemigoX_seis - 0.08
		&& tx <= enemigoX_seis + 0.08
		&& ty >= enemigoY_seis - 0.08
		&& ty <= enemigoY_seis + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_cinco()
{
	if (tx >= enemigoX_cinco - 0.08
		&& tx <= enemigoX_cinco + 0.08
		&& ty >= enemigoY_cinco - 0.08
		&& ty <= enemigoY_cinco + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_cuatro()
{
	if (tx >= enemigoX_cuatro - 0.08
		&& tx <= enemigoX_cuatro + 0.08
		&& ty >= enemigoY_cuatro - 0.08
		&& ty <= enemigoY_cuatro + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_tres()
{
	if (tx >= enemigoX_tres - 0.08
		&& tx <= enemigoX_tres + 0.08
		&& ty >= enemigoY_tres - 0.08
		&& ty <= enemigoY_tres + 0.08)
	{
		exit(0);
	}
}

void checarColisiones_dos()
{
	if (tx >= enemigoX_dos - 0.08 
		&& tx <= enemigoX_dos + 0.08 
		&& ty >= enemigoY_dos - 0.08 
		&& ty <= enemigoY_dos + 0.08)
	{
		exit(0);
	}
}

void checarColisiones()
{
	if (tx >= enemigoX - 0.08
		&& tx <= enemigoX + 0.08
		&& ty >= enemigoY - 0.08
		&& ty <= enemigoY + 0.08)
	{
		exit(0);
	}
}


void actualizarEnemigo(double tiempoTranscurrido)
{
		enemigoX += cos((direccionEnemigo + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
		enemigoY += sin((direccionEnemigo + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
		if (enemigoY >= 1.1)
		{
			enemigoY = -1;
		}
		else if 
			(enemigoY <= -1.1)
		{
			enemigoY = 1;
		}
		if (enemigoX >= 1.1)
		{
			enemigoX = -1;
		}
		else if
			(enemigoX <= -1.1)
		{
			enemigoX = 1;
		}
}

void actualizarEnemigo_dos(double tiempoTranscurrido)
{
	enemigoX_dos += cos((direccionEnemigo_dos + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_dos += sin((direccionEnemigo_dos + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_dos >= 1.1)
	{
		enemigoY_dos = -1;
	}
	else if
		(enemigoY_dos <= -1.1)
	{
		enemigoY_dos = 1;
	}
	if (enemigoX_dos >= 1.1)
	{
		enemigoX_dos = -1;
	}
	else if
		(enemigoX_dos <= -1.1)
	{
		enemigoX_dos = 1;
	}
}

void actualizarEnemigo_tres(double tiempoTranscurrido)
{
	enemigoX_tres += cos((direccionEnemigo_tres + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_tres += sin((direccionEnemigo_tres + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_tres >= 1.1)
	{
		enemigoY_tres = -1;
	}
	else if
		(enemigoY_tres <= -1.1)
	{
		enemigoY_tres = 1;
	}
	if (enemigoX_tres >= 1.1)
	{
		enemigoX_tres = -1;
	}
	else if
		(enemigoX_tres <= -1.1)
	{
		enemigoX_tres = 1;
	}
}

void actualizarEnemigo_cuatro(double tiempoTranscurrido)
{
	enemigoX_cuatro += cos((direccionEnemigo_cuatro + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_cuatro += sin((direccionEnemigo_cuatro + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_cuatro >= 1.1)
	{
		enemigoY_cuatro = -1;
	}
	else if
		(enemigoY_cuatro <= -1.1)
	{
		enemigoY_cuatro = 1;
	}
	if (enemigoX_cuatro >= 1.1)
	{
		enemigoX_cuatro = -1;
	}
	else if
		(enemigoX_cuatro <= -1.1)
	{
		enemigoX_cuatro = 1;
	}
}

void actualizarEnemigo_cinco(double tiempoTranscurrido)
{
	enemigoX += cos((direccionEnemigo_cinco + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY += sin((direccionEnemigo_cinco + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_cinco >= 1.1)
	{
		enemigoY_cinco = -1;
	}
	else if
		(enemigoY_cinco <= -1.1)
	{
		enemigoY_cinco = 1;
	}
	if (enemigoX_cinco >= 1.1)
	{
		enemigoX_cinco = -1;
	}
	else if
		(enemigoX_cinco <= -1.1)
	{
		enemigoX = 1;
	}
}

void actualizarEnemigo_seis(double tiempoTranscurrido)
{
	enemigoX += cos((direccionEnemigo_seis + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY += sin((direccionEnemigo_seis + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_seis >= 1.1)
	{
		enemigoY_seis = -1;
	}
	else if
		(enemigoY_seis <= -1.1)
	{
		enemigoY_seis = 1;
	}
	if (enemigoX_seis >= 1.1)
	{
		enemigoX_seis= -1;
	}
	else if
		(enemigoX_seis <= -1.1)
	{
		enemigoX_seis = 1;
	}
}

void actualizarEnemigo_siete(double tiempoTranscurrido)
{
	enemigoX += cos((direccionEnemigo_siete + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY += sin((direccionEnemigo_siete + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_siete >= 1.1)
	{
		enemigoY_siete = -1;
	}
	else if
		(enemigoY_siete <= -1.1)
	{
		enemigoY_siete = 1;
	}
	if (enemigoX_siete >= 1.1)
	{
		enemigoX_siete = -1;
	}
	else if
		(enemigoX_siete <= -1.1)
	{
		enemigoX_siete = 1;
	}
}

void actualizarEnemigo_ocho(double tiempoTranscurrido)
{
	enemigoX_ocho += cos((direccionEnemigo_ocho + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_ocho += sin((direccionEnemigo_ocho + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_ocho >= 1.1)
	{
		enemigoY_ocho = -1;
	}
	else if
		(enemigoY_ocho <= -1.1)
	{
		enemigoY_ocho = 1;
	}
	if (enemigoX_ocho >= 1.1)
	{
		enemigoX_ocho = -1;
	}
	else if
		(enemigoX_ocho <= -1.1)
	{
		enemigoX_ocho = 1;
	}
}

void actualizarEnemigo_nueve(double tiempoTranscurrido)
{
	enemigoX_nueve += cos((direccionEnemigo_nueve + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_nueve += sin((direccionEnemigo_nueve + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_nueve >= 1.1)
	{
		enemigoY_nueve = -1;
	}
	else if
		(enemigoY_nueve <= -1.1)
	{
		enemigoY_nueve = 1;
	}
	if (enemigoX_nueve >= 1.1)
	{
		enemigoX_nueve = -1;
	}
	else if
		(enemigoX_nueve <= -1.1)
	{
		enemigoX_nueve = 1;
	}
}

void actualizarEnemigo_diez(double tiempoTranscurrido)
{
	enemigoX_diez += cos((direccionEnemigo_diez + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_diez += sin((direccionEnemigo_diez + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_diez >= 1.1)
	{
		enemigoY_diez = -1;
	}
	else if
		(enemigoY_diez <= -1.1)
	{
		enemigoY_diez = 1;
	}
	if (enemigoX_diez >= 1.1)
	{
		enemigoX_diez = -1;
	}
	else if
		(enemigoX_diez <= -1.1)
	{
		enemigoX_diez = 1;
	}
}
 
void actualizarEnemigo_once(double tiempoTranscurrido)
{
	enemigoX_once += cos((direccionEnemigo_once + 90) * (3.14159f / 180.0f)) * velocidad * 3 * tiempoTranscurrido;
	enemigoY_once += sin((direccionEnemigo_once + 90) * (3.14159f / 180.0f)) * velocidad * tiempoTranscurrido;
	if (enemigoY_once >= 1.1)
	{
		enemigoY_once = -1;
	}
	else if
		(enemigoY_once <= -1.1)
	{
		enemigoY_once = 1;
	}
	if (enemigoX_once >= 1.1)
	{
		enemigoX_once = -1;
	}
	else if
		(enemigoX_once <= -1.1)
	{
		enemigoX_once = 1;
	}
}



void actualizar() {
	//Aqui esta bien para cambiar los valores de las variables de mi programa
	/*
	red += 0.001;
	green += 0.002;
	blue += 0.003;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;*/
	double tiempoActual = glfwGetTime();
	double tiempoTranscurrido = tiempoActual - tiempoAnterior;
	//
	//ARRIBA
	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS)
	{
		/*if (ty < 1)
			ty += velocidad * tiempoTranscurrido;*/
		tx += cos((angulo + 90) * (3.14159 / 180.0f)) * velocidad * tiempoTranscurrido;
		ty += sin((angulo + 90) * (3.14159 / 180.0f)) * velocidad * tiempoTranscurrido;
		
	}


	//ABAJO
	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS)
	{
		/*if (ty > -1)
			ty -= velocidad * tiempoTranscurrido;*/
		
	}

	//Izquierda
	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		angulo += velocidadAngular * tiempoTranscurrido;
		if (angulo > 360) {
			angulo -= 360.0f;
		}
	}

	//Derecha
	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		angulo -= velocidadAngular * tiempoTranscurrido;
		if (angulo < 0)
		{
			angulo += 360.0f;
		}
	}

	int estadoJump = glfwGetKey(window, GLFW_KEY_SPACE);
	if (estadoJump == GLFW_PRESS) {
		ty = ty + 0.03f;
	}

	actualizarEnemigo(tiempoTranscurrido);
	actualizarEnemigo_dos(tiempoTranscurrido);
	actualizarEnemigo_tres(tiempoTranscurrido);
	actualizarEnemigo_cuatro(tiempoTranscurrido);
	actualizarEnemigo_ocho(tiempoTranscurrido);
	actualizarEnemigo_nueve(tiempoTranscurrido);
	actualizarEnemigo_diez(tiempoTranscurrido);
	actualizarEnemigo_once(tiempoTranscurrido);
	
	checarGanar();
	checarColisiones();
	checarColisiones_dos();
	checarColisiones_tres();
	checarColisiones_cuatro();
	checarColisiones_cinco();
	checarColisiones_seis();
	checarColisiones_siete();
	checarColisiones_ocho();
	checarColisiones_nueve();
	checarColisiones_diez();
	checarColisiones_once();
	tiempoAnterior = tiempoActual;

}
// -------------------------------------------------------------Inicia Dibujo de Banquetas --------------------------------------------------------------------
void dibujarFondo()
{
	// Inicio
	glBegin(GL_LINE_LOOP);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(-1.0f, -0.8f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(1.0f, -0.8f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd(); 

	// Final
	/*glBegin(GL_LINE_LOOP);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(-1.0f, 0.8f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(1.0f, 0.8f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();*/
}

void dibujarGanar()
{
	glBegin(GL_LINE_LOOP);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(-1.0f, 0.8f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(1.0f, 0.8f, 0.0f);

	glColor3f(195.0f / 255.0f, 195.0f / 255.0f, 195.0f / 255.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
}

// -------------------------------------------------------------Finaliza Dibujo de Banquetas --------------------------------------------------------------------

// -------------------------------------------------------------Inicia Dibujo de Frogger --------------------------------------------------------------------
void dibujarHeroe() {
	glPushMatrix();
	glTranslatef(tx, ty, 0.0f);
	glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo
	//Color de frogger
	glColor3f(0.0f, 1.0f, 0.0f);
	//Vertice 1
	glVertex3f(-0.2f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(-0.2f, -0.2f, 0.0f);
	//Vertice 3
	glVertex3f(-0.3f, -0.2f, 0.0f);
	//Vertice 4
	glVertex3f(-0.3f, -0.1f, 0.0f);
	//Vertice 5
	glVertex3f(-0.4f, -0.1f, 0.0f);
	//Vertice 6
	glVertex3f(-0.4f, -0.5f, 0.0f);
	//Vertice 7
	glVertex3f(-0.5f, -0.5f, 0.0f);
	//Vertice 8
	glVertex3f(-0.5f, -0.4f, 0.0f);
	//Vertice 9
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 10
	glVertex3f(-0.6f, -0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.5f, -0.3f, 0.0f);
	//Vertice 12
	glVertex3f(-0.5f, 0.0f, 0.0f);
	//Vertice 13
	glVertex3f(-0.3f, 0.0f, 0.0f);
	//Vertice 14
	glVertex3f(-0.3f, 0.1f, 0.0f);
	//Vertice 15
	glVertex3f(-0.5f, 0.1f, 0.0f);
	//Vertice 16
	glVertex3f(-0.5f, 0.3f, 0.0f);
	//Vertice 17
	glVertex3f(-0.6f, 0.3f, 0.0f);
	//Vertice 18
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 19
	glVertex3f(-0.5f, 0.4f, 0.0f);
	//Vertice 20
	glVertex3f(-0.5f, 0.5f, 0.0f);
	//Vertice 21
	glVertex3f(-0.4f, 0.5f, 0.0f);
	//Vertice 22
	glVertex3f(-0.4f, 0.2f, 0.0f);
	//Vertice 23
	glVertex3f(-0.3f, 0.2f, 0.0f);
	//Vertice 24
	glVertex3f(-0.3f, 0.4f, 0.0f);
	//Vertice 25
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(-0.2f, 0.5f, 0.0f);
	//Vertice 27
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 28
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 29
	glVertex3f(0.3f, 0.4f, 0.0f);
	//Vertice 30
	glVertex3f(0.3f, 0.2f, 0.0f);
	//Vertice 31
	glVertex3f(0.4f, 0.2f, 0.0f);
	//Vertice 32
	glVertex3f(0.4f, 0.5f, 0.0f);
	//Vertice 33
	glVertex3f(0.5f, 0.5f, 0.0f);
	//Vertice 34
	glVertex3f(0.5f, 0.4f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.6f, 0.3f, 0.0f);
	//Vertice 37
	glVertex3f(0.5f, 0.3f, 0.0f);
	//Vertice 38
	glVertex3f(0.5f, 0.1f, 0.0f);
	//Vertice 39
	glVertex3f(0.3f, 0.1f, 0.0f);
	//Vertice 40
	glVertex3f(0.3f, 0.0f, 0.0f);
	//Vertice 41
	glVertex3f(0.5f, 0.0f, 0.0f);
	//Vertice 42
	glVertex3f(0.5f, -0.3f, 0.0f);
	//Vertice 43
	glVertex3f(0.6f, -0.3f, 0.0f);
	//Vertice 44
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 45
	glVertex3f(0.5f, -0.4f, 0.0f);
	//Vertice 46
	glVertex3f(0.5f, -0.5f, 0.0f);
	//Vertice 47
	glVertex3f(0.4f, -0.5f, 0.0f);
	//Vertice 48
	glVertex3f(0.4f, -0.1f, 0.0f);
	//Vertice 49
	glVertex3f(0.3f, -0.1f, 0.0f);
	//Vertice 50
	glVertex3f(0.3f, -0.2f, 0.0f);
	//Vertice 51
	glVertex3f(0.2f, -0.2f, 0.0f);
	//Vertice 52
	glVertex3f(0.2f, -0.3f, 0.0f);
	glEnd();//finaliza rutina
	glPopMatrix();
}
// -------------------------------------------------------------Finaliza Dibujo de Frogger --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro --------------------------------------------------------------------
void dibujarEnemigo() {
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

	//Color del carro
	glColor3f(1.0f, 0.0f, 0.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(0.0f, -0.4f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.2f, -0.5f, 0.0f);
	//Vertice 5
	glVertex3f(-0.4f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.4f, -0.4f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.6f, -0.3f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.6f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 13
	glVertex3f(-0.4f, 0.4f, 0.0f);
	//Vertice 14
	glVertex3f(-0.4f, 0.5f, 0.0f);
	//Vertice 15
	glVertex3f(-0.2f, 0.5f, 0.0f);
	//Vertice 16
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 17
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 19
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 20
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 21
	glVertex3f(0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(0.3f, 0.5f, 0.0f);
	//Vertice 23
	glVertex3f(0.6f, 0.5f, 0.0f);
	//Vertice 24
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 25
	glVertex3f(0.7f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 27
	glVertex3f(0.8f, 0.3f, 0.0f);
	//Vertice 28
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 29
	glVertex3f(0.7f, 0.2f, 0.0f);
	//Vertice 30
	glVertex3f(0.7f, -0.2f, 0.0f);
	//Vertice 31
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 32
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.7f, -0.4f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.6f, -0.5f, 0.0f);
	//Vertice 37
	glVertex3f(0.3f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.3f, -0.4f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.2f, -0.3f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}
// -------------------------------------------------------------Finaliza Dibujo de Carro --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 2 --------------------------------------------------------------------
void dibujarEnemigo_dos() {
	glPushMatrix();
	glTranslatef(enemigoX_dos, enemigoY_dos, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 1.0f, 1.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(0.0f, -0.4f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.2f, -0.5f, 0.0f);
	//Vertice 5
	glVertex3f(-0.4f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.4f, -0.4f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.6f, -0.3f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.6f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 13
	glVertex3f(-0.4f, 0.4f, 0.0f);
	//Vertice 14
	glVertex3f(-0.4f, 0.5f, 0.0f);
	//Vertice 15
	glVertex3f(-0.2f, 0.5f, 0.0f);
	//Vertice 16
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 17
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 19
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 20
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 21
	glVertex3f(0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(0.3f, 0.5f, 0.0f);
	//Vertice 23
	glVertex3f(0.6f, 0.5f, 0.0f);
	//Vertice 24
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 25
	glVertex3f(0.7f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 27
	glVertex3f(0.8f, 0.3f, 0.0f);
	//Vertice 28
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 29
	glVertex3f(0.7f, 0.2f, 0.0f);
	//Vertice 30
	glVertex3f(0.7f, -0.2f, 0.0f);
	//Vertice 31
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 32
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.7f, -0.4f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.6f, -0.5f, 0.0f);
	//Vertice 37
	glVertex3f(0.3f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.3f, -0.4f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.2f, -0.3f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}

// -------------------------------------------------------------Finaliza Dibujo de Carro 2 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 3 --------------------------------------------------------------------
void dibujarEnemigo_tres() {
	glPushMatrix();
	glTranslatef(enemigoX_tres, enemigoY_tres, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 0.0f, 0.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(-0.2f, -0.3f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.3f, -0.4f, 0.0f);
	//Vertice 5
	glVertex3f(-0.3f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.6f, -0.5f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.7f, -0.4f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.8f, -0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.8f, -0.2f, 0.0f);
	//Vertice 12
	glVertex3f(-0.7f, 0.2f, 0.0f);
	//Vertice 13
	glVertex3f(-0.7f, -0.2f, 0.0f);
	//Vertice 14
	glVertex3f(-0.8f, 0.2f, 0.0f);
	//Vertice 15
	glVertex3f(-0.8f, 0.3f, 0.0f);
	//Vertice 16
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 17
	glVertex3f(-0.7f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 19
	glVertex3f(-0.6f, 0.5f, 0.0f);
	//Vertice 20
	glVertex3f(-0.3f, 0.5f, 0.0f);
	//Vertice 21
	glVertex3f(-0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 23
	glVertex3f(-0.2f, 0.3f, 0.0f);
	//Vertice 24
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 25
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 27
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 28
	glVertex3f(0.4f, 0.5f, 0.0f);
	//Vertice 29
	glVertex3f(0.4f, 0.4f, 0.0f);
	//Vertice 30
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 31
	glVertex3f(0.6f, 0.3f, 0.0f);
	//Vertice 32
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.6f, -0.3f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.4f, -0.4f, 0.0f);
	//Vertice 37
	glVertex3f(0.4f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.0f, -0.4f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}

// -------------------------------------------------------------Finaliza Dibujo de Carro 3 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 4 --------------------------------------------------------------------
void dibujarEnemigo_cuatro() {
	glPushMatrix();
	glTranslatef(enemigoX_cuatro, enemigoY_cuatro, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 1.0f, 1.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(-0.2f, -0.3f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.3f, -0.4f, 0.0f);
	//Vertice 5
	glVertex3f(-0.3f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.6f, -0.5f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.7f, -0.4f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.8f, -0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.8f, -0.2f, 0.0f);
	//Vertice 12
	glVertex3f(-0.7f, 0.2f, 0.0f);
	//Vertice 13
	glVertex3f(-0.7f, -0.2f, 0.0f);
	//Vertice 14
	glVertex3f(-0.8f, 0.2f, 0.0f);
	//Vertice 15
	glVertex3f(-0.8f, 0.3f, 0.0f);
	//Vertice 16
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 17
	glVertex3f(-0.7f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 19
	glVertex3f(-0.6f, 0.5f, 0.0f);
	//Vertice 20
	glVertex3f(-0.3f, 0.5f, 0.0f);
	//Vertice 21
	glVertex3f(-0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 23
	glVertex3f(-0.2f, 0.3f, 0.0f);
	//Vertice 24
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 25
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 27
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 28
	glVertex3f(0.4f, 0.5f, 0.0f);
	//Vertice 29
	glVertex3f(0.4f, 0.4f, 0.0f);
	//Vertice 30
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 31
	glVertex3f(0.6f, 0.3f, 0.0f);
	//Vertice 32
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.6f, -0.3f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.4f, -0.4f, 0.0f);
	//Vertice 37
	glVertex3f(0.4f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.0f, -0.4f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}

// -------------------------------------------------------------Finaliza Dibujo de Carro 4 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de agujero 1--------------------------------------------------------------------
void dibujarEnemigo_cinco() {
	glPushMatrix();
	glTranslatef(enemigoX_cinco, enemigoY_cinco, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 1.0f, 1.0f);


	//Vertice 1
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 2
	glVertex3f(0.9f, 0.2f, 0.0f);
	//Vertice 3
	glVertex3f(0.9f, -0.2f, 0.0f);
	//Vertice 4
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 5
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 6
	glVertex3f(0.2f, -0.3f, 0.0f);
	//Vertice 7
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 8
	glVertex3f(1.9f, -0.5f, 0.0f);
	//Vertice 9
	glVertex3f(1.9f, 0.5f, 0.0f);
	//Vertice 10
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 11
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(0.8f, 0.3f, 0.0f);
	


	glEnd();//finaliza rutina
	glPopMatrix();
}

// -------------------------------------------------------------Finaliza Dibujo de agujero 1 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de agujero 2 --------------------------------------------------------------------
void dibujarEnemigo_seis() {
	glPushMatrix();
	glTranslatef(enemigoX_seis, enemigoY_seis, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 1.0f, 1.0f);


	//Vertice 1
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 2
	glVertex3f(0.9f, 0.2f, 0.0f);
	//Vertice 3
	glVertex3f(0.9f, -0.2f, 0.0f);
	//Vertice 4
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 5
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 6
	glVertex3f(0.2f, -0.3f, 0.0f);
	//Vertice 7
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 8
	glVertex3f(1.9f, -0.5f, 0.0f);
	//Vertice 9
	glVertex3f(1.9f, 0.5f, 0.0f);
	//Vertice 10
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 11
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(0.8f, 0.3f, 0.0f);



	glEnd();//finaliza rutina
	glPopMatrix();
}

// -------------------------------------------------------------Finaliza Dibujo de agujero 2 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de agujero 3 --------------------------------------------------------------------
void dibujarEnemigo_siete() {
	glPushMatrix();
	glTranslatef(enemigoX_siete, enemigoY_siete, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 1.0f, 1.0f);


	//Vertice 1
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 2
	glVertex3f(0.9f, 0.2f, 0.0f);
	//Vertice 3
	glVertex3f(0.9f, -0.2f, 0.0f);
	//Vertice 4
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 5
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 6
	glVertex3f(0.2f, -0.3f, 0.0f);
	//Vertice 7
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 8
	glVertex3f(1.9f, -0.5f, 0.0f);
	//Vertice 9
	glVertex3f(1.9f, 0.5f, 0.0f);
	//Vertice 10
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 11
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(0.8f, 0.3f, 0.0f);



	glEnd();//finaliza rutina
	glPopMatrix();
}

// -------------------------------------------------------------Finaliza Dibujo de agujero 3 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 5--------------------------------------------------------------------
void dibujarEnemigo_ocho() {
	glPushMatrix();
	glTranslatef(enemigoX_ocho, enemigoY_ocho, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 0.0f, 0.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(0.0f, -0.4f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.2f, -0.5f, 0.0f);
	//Vertice 5
	glVertex3f(-0.4f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.4f, -0.4f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.6f, -0.3f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.6f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 13
	glVertex3f(-0.4f, 0.4f, 0.0f);
	//Vertice 14
	glVertex3f(-0.4f, 0.5f, 0.0f);
	//Vertice 15
	glVertex3f(-0.2f, 0.5f, 0.0f);
	//Vertice 16
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 17
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 19
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 20
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 21
	glVertex3f(0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(0.3f, 0.5f, 0.0f);
	//Vertice 23
	glVertex3f(0.6f, 0.5f, 0.0f);
	//Vertice 24
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 25
	glVertex3f(0.7f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 27
	glVertex3f(0.8f, 0.3f, 0.0f);
	//Vertice 28
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 29
	glVertex3f(0.7f, 0.2f, 0.0f);
	//Vertice 30
	glVertex3f(0.7f, -0.2f, 0.0f);
	//Vertice 31
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 32
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.7f, -0.4f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.6f, -0.5f, 0.0f);
	//Vertice 37
	glVertex3f(0.3f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.3f, -0.4f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.2f, -0.3f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}
// -------------------------------------------------------------Finaliza Dibujo de Carro 5--------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 6 --------------------------------------------------------------------
void dibujarEnemigo_nueve() {
	glPushMatrix();
	glTranslatef(enemigoX_nueve, enemigoY_nueve, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 1.0f, 1.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(0.0f, -0.4f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.2f, -0.5f, 0.0f);
	//Vertice 5
	glVertex3f(-0.4f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.4f, -0.4f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.6f, -0.3f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.6f, 0.3f, 0.0f);
	//Vertice 12
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 13
	glVertex3f(-0.4f, 0.4f, 0.0f);
	//Vertice 14
	glVertex3f(-0.4f, 0.5f, 0.0f);
	//Vertice 15
	glVertex3f(-0.2f, 0.5f, 0.0f);
	//Vertice 16
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 17
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 19
	glVertex3f(0.2f, 0.3f, 0.0f);
	//Vertice 20
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 21
	glVertex3f(0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(0.3f, 0.5f, 0.0f);
	//Vertice 23
	glVertex3f(0.6f, 0.5f, 0.0f);
	//Vertice 24
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 25
	glVertex3f(0.7f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 27
	glVertex3f(0.8f, 0.3f, 0.0f);
	//Vertice 28
	glVertex3f(0.8f, 0.2f, 0.0f);
	//Vertice 29
	glVertex3f(0.7f, 0.2f, 0.0f);
	//Vertice 30
	glVertex3f(0.7f, -0.2f, 0.0f);
	//Vertice 31
	glVertex3f(0.8f, -0.2f, 0.0f);
	//Vertice 32
	glVertex3f(0.8f, -0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.7f, -0.4f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.6f, -0.5f, 0.0f);
	//Vertice 37
	glVertex3f(0.3f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.3f, -0.4f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.2f, -0.3f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}
// -------------------------------------------------------------Finaliza Dibujo de Carro 6 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 7--------------------------------------------------------------------
void dibujarEnemigo_diez() {
	glPushMatrix();
	glTranslatef(enemigoX_diez, enemigoY_diez, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	glColor3f(1.0f, 0.0f, 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);


	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(-0.2f, -0.3f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.3f, -0.4f, 0.0f);
	//Vertice 5
	glVertex3f(-0.3f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.6f, -0.5f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.7f, -0.4f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.8f, -0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.8f, -0.2f, 0.0f);
	//Vertice 12
	glVertex3f(-0.7f, 0.2f, 0.0f);
	//Vertice 13
	glVertex3f(-0.7f, -0.2f, 0.0f);
	//Vertice 14
	glVertex3f(-0.8f, 0.2f, 0.0f);
	//Vertice 15
	glVertex3f(-0.8f, 0.3f, 0.0f);
	//Vertice 16
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 17
	glVertex3f(-0.7f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 19
	glVertex3f(-0.6f, 0.5f, 0.0f);
	//Vertice 20
	glVertex3f(-0.3f, 0.5f, 0.0f);
	//Vertice 21
	glVertex3f(-0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 23
	glVertex3f(-0.2f, 0.3f, 0.0f);
	//Vertice 24
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 25
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 27
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 28
	glVertex3f(0.4f, 0.5f, 0.0f);
	//Vertice 29
	glVertex3f(0.4f, 0.4f, 0.0f);
	//Vertice 30
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 31
	glVertex3f(0.6f, 0.3f, 0.0f);
	//Vertice 32
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.6f, -0.3f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.4f, -0.4f, 0.0f);
	//Vertice 37
	glVertex3f(0.4f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.0f, -0.4f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}
// -------------------------------------------------------------Finaliza Dibujo de Carro 7 --------------------------------------------------------------------

// -------------------------------------------------------------Inicializa Dibujo de Carro 8 --------------------------------------------------------------------
void dibujarEnemigo_once() {
	glPushMatrix();
	glTranslatef(enemigoX_once, enemigoY_once, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_LINE_LOOP);//Inicia la rutina con un modo de dibujo

						  //Color del carro
	
	glColor3f(1.0f, 1.0f, 1.0f);
	//Vertice 1
	glVertex3f(0.0f, -0.3f, 0.0f);
	//Vertice 2
	glVertex3f(-0.2f, -0.3f, 0.0f);
	//Vertice 3
	glVertex3f(-0.2f, -0.4f, 0.0f);
	//Vertice 4
	glVertex3f(-0.3f, -0.4f, 0.0f);
	//Vertice 5
	glVertex3f(-0.3f, -0.5f, 0.0f);
	//Vertice 6
	glVertex3f(-0.6f, -0.5f, 0.0f);
	//Vertice 7
	glVertex3f(-0.6f, -0.4f, 0.0f);
	//Vertice 8
	glVertex3f(-0.7f, -0.4f, 0.0f);
	//Vertice 9
	glVertex3f(-0.7f, -0.3f, 0.0f);
	//Vertice 10
	glVertex3f(-0.8f, -0.3f, 0.0f);
	//Vertice 11
	glVertex3f(-0.8f, -0.2f, 0.0f);
	//Vertice 12
	glVertex3f(-0.7f, 0.2f, 0.0f);
	//Vertice 13
	glVertex3f(-0.7f, -0.2f, 0.0f);
	//Vertice 14
	glVertex3f(-0.8f, 0.2f, 0.0f);
	//Vertice 15
	glVertex3f(-0.8f, 0.3f, 0.0f);
	//Vertice 16
	glVertex3f(-0.7f, 0.3f, 0.0f);
	//Vertice 17
	glVertex3f(-0.7f, 0.4f, 0.0f);
	//Vertice 18
	glVertex3f(-0.6f, 0.4f, 0.0f);
	//Vertice 19
	glVertex3f(-0.6f, 0.5f, 0.0f);
	//Vertice 20
	glVertex3f(-0.3f, 0.5f, 0.0f);
	//Vertice 21
	glVertex3f(-0.3f, 0.4f, 0.0f);
	//Vertice 22
	glVertex3f(-0.2f, 0.4f, 0.0f);
	//Vertice 23
	glVertex3f(-0.2f, 0.3f, 0.0f);
	//Vertice 24
	glVertex3f(0.0f, 0.3f, 0.0f);
	//Vertice 25
	glVertex3f(0.0f, 0.4f, 0.0f);
	//Vertice 26
	glVertex3f(0.2f, 0.4f, 0.0f);
	//Vertice 27
	glVertex3f(0.2f, 0.5f, 0.0f);
	//Vertice 28
	glVertex3f(0.4f, 0.5f, 0.0f);
	//Vertice 29
	glVertex3f(0.4f, 0.4f, 0.0f);
	//Vertice 30
	glVertex3f(0.6f, 0.4f, 0.0f);
	//Vertice 31
	glVertex3f(0.6f, 0.3f, 0.0f);
	//Vertice 32
	glVertex3f(0.7f, 0.3f, 0.0f);
	//Vertice 33
	glVertex3f(0.7f, -0.3f, 0.0f);
	//Vertice 34
	glVertex3f(0.6f, -0.3f, 0.0f);
	//Vertice 35
	glVertex3f(0.6f, -0.4f, 0.0f);
	//Vertice 36
	glVertex3f(0.4f, -0.4f, 0.0f);
	//Vertice 37
	glVertex3f(0.4f, -0.5f, 0.0f);
	//Vertice 38
	glVertex3f(0.2f, -0.5f, 0.0f);
	//Vertice 39
	glVertex3f(0.2f, -0.4f, 0.0f);
	//Vertice 40
	glVertex3f(0.0f, -0.4f, 0.0f);

	glEnd();//finaliza rutina
	glPopMatrix();
}
// -------------------------------------------------------------Finaliza Dibujo de carro  8 --------------------------------------------------------------------




void dibujar() {
	dibujarGanar();
	dibujarFondo();
	dibujarHeroe();
	dibujarEnemigo();
	dibujarEnemigo_dos();
	dibujarEnemigo_tres();
	dibujarEnemigo_cuatro();
	dibujarEnemigo_cinco();
	dibujarEnemigo_seis();
	dibujarEnemigo_siete();
	dibujarEnemigo_ocho();
	dibujarEnemigo_nueve();
	dibujarEnemigo_diez();
	dibujarEnemigo_once();
	
	
}
void key_callback(GLFWwindow* window, int key,
	int scancode, int action, int mods)
{
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (ty  < 0.9)
			ty += 0.05;
	}

	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (ty > -0.9)
			ty -= 0.05f;
	}

	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (tx  < 0.9)
			tx += 0.05;
	}

	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (tx > -0.9)
			tx -= 0.05f;
	}
	if (key == GLFW_KEY_SPACE )
	{
		if (ty  < 0.9)
			ty += 0.05;
	}
}

int main()
{

	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicializacion de GLFW
	if (!glfwInit()) {
		//Si no se inicio bien, terminar la ejecucion
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verificar si se creo bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializo bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.0f;

	//glfwSetKeyCallback(window, key_callback);

	tiempoAnterior = glfwGetTime();

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render(Vewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla


		glClearColor(red, green, blue, 1);

		//Limpiar pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

