
#define FREEGLUT_STATIC
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>

// global variables
int windowWidth = 1010;
int windowHeight = 600;
float M_PI = 3.1415;
int buttonWidth = 25;
int buttonX = (windowWidth - buttonWidth) / 2;
int buttonY = -200;//(windowHeight - buttonHeight) / 2;
bool isButtonClicked = false;

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")



typedef struct { GLfloat x, y; } point; // define a 2D point
point p0 = { 1015,20 };  // Big char point
point p_Text = { 100, 800 };
point p_B = { buttonX ,buttonY }; // button
point p_Letter = { buttonX - 200 ,buttonY -75 };
point p_LetterCover = { buttonX - 200 ,buttonY - 75 };
point p_CB = { 0,-200 };
point p_tower = { 890, -200 };
point p_label = { 5, 700 };
point p_Balloon[5] = { {100,-100},{400,-100},{900,-100} };
point p_flag[3] = { {300,-100},{350,-100},{400,-100} };
GLfloat flagStep = 0;

GLfloat step = 1; // declare incremental step
int time_interval = 1; // declare refresh interval in ms

void when_in_mainloop()
{ // idle callback function
	glutPostRedisplay(); // force OpenGL to redraw the current window
}

// Timers
void OnTimerButtonCome(int value)
{
	p_B.y += step;
	if (p_B.y == windowHeight / 2) {
		// stop the timer
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		// continue
		glutTimerFunc(time_interval, OnTimerButtonCome, 1);
	}
}
void OnTimerLetterCome(int value)
{
	p_Letter.y += step;
	if (p_Letter.y == windowHeight / 2 - 80) {
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		glutTimerFunc(time_interval, OnTimerLetterCome, 1);
	}
}
void OnTimerLetterCoverCome(int value)
{
	p_LetterCover.y += step;
	if (p_LetterCover.y == windowHeight / 2 - 80) {
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		glutTimerFunc(time_interval, OnTimerLetterCoverCome, 1);
	}
}
void OnTimerDecorate1Come(int value)
{
	p_CB.y += step / 2;
	p_tower.y += step / 2;
	if (p_CB.y == 0 || p_tower.y == 0) {
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		glutTimerFunc(time_interval, OnTimerDecorate1Come, 1);
	}
}
void OnTimerButtonGo(int value)
{
	p_B.y += step;
	if (p_B.y == 1000) {
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		glutTimerFunc(time_interval, OnTimerButtonGo, 1);
	}

}
void OnTimerLetterCoverGo(int value)
{
	p_LetterCover.y += step;
	if (p_LetterCover.y == 1000) {
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		glutTimerFunc(time_interval, OnTimerLetterCoverGo, 1);
	}

}
void OnTimerLetterGo(int value)
{
	p_Letter.y -= step;
	if (p_Letter.y == -1000) {
		return;
	}
	else {
		glutTimerFunc(time_interval, OnTimerLetterGo, 1);
	}
}
void OnTimerFlagCome(int value) {
	p_flag[0].y++;
	p_flag[1].y++;
	p_flag[2].y++;

	if (p_flag[0].y == p_flag[1].y == p_flag[2].y >= 70) {
		return;
	}
	glutTimerFunc(time_interval, OnTimerFlagCome, 1);
}
void OnTimerFlag(int value)
{
	flagStep+=0.1;
	glutTimerFunc(time_interval, OnTimerFlag, 2);
}
void OnTimerBalloons(int value)
{
	p_Balloon[0].y += 0.3 * step;
	if (p_Balloon[0].y < 100 && p_Balloon[0].y > -100 || p_Balloon[0].y < 300 && p_Balloon[0].y > 200 || p_Balloon[0].y < 500 && p_Balloon[0].y > 400) {
		p_Balloon[0].x += -0.16* step * step;
	}
	else {
		p_Balloon[0].x += 0.16 * step * step;
	}

	if (p_Balloon[0].y > windowHeight+200) {
		p_Balloon[0].y = -100;
	}
	else if(p_Balloon[0].y < 0){
		p_Balloon[0].y += step;
	}
	glutTimerFunc(time_interval, OnTimerBalloons, 1);
}
void OnTimerBalloons1(int value)
{
	p_Balloon[1].y += 0.3 * step;
	if (p_Balloon[1].y < 100 && p_Balloon[1].y > -100 || p_Balloon[1].y < 300 && p_Balloon[1].y > 200 || p_Balloon[1].y < 500 && p_Balloon[1].y > 400) {
		p_Balloon[1].x += 0.14 * step;
	}
	else {
		p_Balloon[1].x += -0.14 * step;
	}

	if (p_Balloon[1].y > windowHeight + 200) {
		p_Balloon[1].y = -100;
	}
	else if (p_Balloon[1].y < 0) {
		p_Balloon[1].y += step;
	}
	glutTimerFunc(time_interval, OnTimerBalloons1, 1);
}
void OnTimerBalloons2(int value)
{
	p_Balloon[2].y += 0.2 * step;
	if (p_Balloon[2].y < 100 && p_Balloon[2].y > -100 || p_Balloon[2].y < 300 && p_Balloon[2].y > 200 || p_Balloon[2].y < 500 && p_Balloon[2].y > 400) {
		p_Balloon[2].x += -0.14 * step;
	}
	else {
		p_Balloon[2].x += 0.14 * step;
	}

	if (p_Balloon[2].y > windowHeight + 200) {
		p_Balloon[2].y = -100;
	}
	else if (p_Balloon[2].y < 0) {
		p_Balloon[2].y += step;
	}
	glutTimerFunc(time_interval, OnTimerBalloons2, 1);
}
void OnTimerLabel(int value)
{
	p_label.y -= step;
	if (p_label.y == 500) {
		return;
	}
	else {
		glutTimerFunc(time_interval, OnTimerLabel, 1);
	}
}
void OnTimerText(int value)
{
	p_Text.y -= step;
	if (p_Text.y == 400) {
		glutTimerFunc(-1, NULL, 0);
	}
	else {
		glutTimerFunc(time_interval, OnTimerText, 1);
	}
}
void OnTimerBigChar(int value)
{
	p0.x -= step;
	if (p0.x <= -3000) {
		glutTimerFunc(time_interval, OnTimerDecorate1Come, 1);
		glutTimerFunc(time_interval, OnTimerLabel, 1);
		glutTimerFunc(time_interval, OnTimerButtonCome, 1);
		glutTimerFunc(time_interval, OnTimerLetterCome, 1);
		glutTimerFunc(time_interval, OnTimerLetterCoverCome, 1);
		glutTimerFunc(time_interval, OnTimerFlagCome, 2);
		return;
	}
	glutTimerFunc(time_interval, OnTimerBigChar, 1);
}



// Rendering func

// text
void renderBitmapString(float x, float y, void* font, const char* string) {
	glRasterPos2f(x, y);

	for (int i = 0; string[i] != '\0'; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

// basic shape
void drawCircle(int x, int y, int radius, int numSegments) {
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < numSegments; i++) {
		double theta = 2.0 * M_PI * i / numSegments;
		double cx = radius * cos(theta);
		double cy = radius * sin(theta);
		glVertex2d(x + cx, y + cy);
	}
	glEnd();

} 

void drawRectangle(int x, int y, int width, int height) {
	glBegin(GL_QUADS);
	glVertex2i(x, y);                 
	glVertex2i(x + width, y);         
	glVertex2i(x + width, y + height); 
	glVertex2i(x, y + height);         
	glEnd();
}

void drawEllipse(int x, int y, int a, int b, int numSegments) {
	glBegin(GL_TRIANGLE_FAN); 

	for (int i = 0; i < numSegments; i++) {
		float angle = 2.0 * M_PI * i / numSegments;
		float xOffset = a * cos(angle);
		float yOffset = b * sin(angle);
		glVertex2f(x + xOffset, y + yOffset);
	}

	glEnd();
}

void drawParallelogram(int x, int y, int width, int height, int topOffset) {
	glBegin(GL_QUADS);
	glVertex2i(x, y);                     
	glVertex2i(x + width, y);             
	glVertex2i(x + width + topOffset, y + height);
	glVertex2i(x + topOffset, y + height); 
	glEnd();
}

void drawRoundedRectangle(int x, int y, int width, int height) {
	
	if (width > height) {
		int radius = height / 2;
		drawCircle(x, y+height/2, radius, 100);
		drawCircle(x + width, y + height / 2, radius, 100);
		drawRectangle(x, y, width, height);
	}
	else {
		int radius = width / 2;
		drawCircle(x + radius, y, radius, 100);
		drawCircle(x + radius, y + height, radius, 100);
		drawRectangle(x, y, width, height);
	}
	
}

void drawCubicBezierCurve(int x,int y) {
	GLfloat controlPoints[4][2] = {
	{x, y }, 
	{x + 20, y - 70},   
	{x, y - 90},   
	{x - 10,y - 100}   
	};

	int numSegments = 100;
	glBegin(GL_LINE_STRIP);

	for (int i = 0; i <= numSegments; i++) {
		float t = static_cast<float>(i) / numSegments;

		float x = (1 - t) * (1 - t) * (1 - t) * controlPoints[0][0] +
			3 * (1 - t) * (1 - t) * t * controlPoints[1][0] +
			3 * (1 - t) * t * t * controlPoints[2][0] +
			t * t * t * controlPoints[3][0];

		float y = (1 - t) * (1 - t) * (1 - t) * controlPoints[0][1] +
			3 * (1 - t) * (1 - t) * t * controlPoints[1][1] +
			3 * (1 - t) * t * t * controlPoints[2][1] +
			t * t * t * controlPoints[3][1];

		glVertex2f(x, y);
	}

	glEnd();
}

//complex shape
void draw2(int x,int y){
	drawRoundedRectangle(x, y, 200, 50);
	drawRoundedRectangle(x-25 , y+50, 50, 200);
	drawRoundedRectangle(x, y+250, 200, 50);
	drawRoundedRectangle(x+175, y+275, 50, 200);
	drawRoundedRectangle(x, y+275+175, 200, 50);
}

void draw0(int x, int y) {
	drawRoundedRectangle(x, y, 200, 50);
	drawRoundedRectangle(x - 25, y + 50, 50, 400);
	drawRoundedRectangle(x, y + 275 + 175, 200, 50);
	drawRoundedRectangle(x + 175, y + 50, 50, 400);
}

void  draw4(int x, int y) {

	drawRoundedRectangle(x, y + 250, 200, 50);
	drawRoundedRectangle(x + 175, y + 25, 50, 450);
	drawRoundedRectangle(x- 25, y + 275, 50, 200);
}

void drawX(int x, int y, int width) {
	drawParallelogram(x, y, width, width*10, width * 6);
	drawParallelogram(x + width * 7, y, width, width*10, -width * 6);
}

void drawJ(int x, int y, int width) {
	drawRectangle(x, y, width, width*2);
    drawRectangle(x, y, width*4, width);
	drawRectangle(x+ width*3, y, width, width*10);
}

void drawT(int x, int y, int width) {
	drawRectangle(x, y+ width*9, width*5, width);
	drawRectangle(x+ width*2, y, width, width*10);
}

void drawL(int x, int y,int width) {
	drawRectangle(x, y, width, width*10);
	drawRectangle(x, y, width*6, width);
}

void drawU(int x, int y,int width){
	drawRectangle(x, y, width, width*10);
	drawRectangle(x, y, width*6, width);
	drawRectangle(x+ width*5, y, width, width*10);
}

void draw2024XJTLU(int x, int y) {
	draw2(x, y);
	draw0(x + 255, y);
	draw2(x + 510, y);
	draw4(x + 765, y);
	drawX(x + 1200, y,50);
	drawJ(x + 1200 + 420, y, 50);
	drawT(x + 1200 + 420 + 270,y, 50);
	drawL(x + 1200 + 420 + 270 + 270, y, 50);
	drawU(x + 1200 + 420 + 270 + 270 + 320, y, 50);
}

void drawCB(int x, int y) {
	//main body
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(x, y);
	glVertex2f(x, y + 75*2 +10 );
	glVertex2f(x+75 * 2,y+100 * 2);
	glVertex2f(x+75 * 2,y);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0); 
	glVertex2f(x+75 * 2, y);
	glVertex2f(x+75 * 2, y + 100 * 2);
	glVertex2f(x + 75 * 2 + 50 * 2, y + 75 * 2);
	glVertex2f(x + 75 * 2 + 50 * 2, y);
	glEnd();

	//Windows(line)
	glColor3f(0.78, 0.4, 0.7);
	for (int i = -40; i < 160; i += 10) {
		glBegin(GL_QUADS);
		glVertex2f(x, y+i);
		glVertex2f(x, y + i + 3);
		glVertex2f(x+150, y + i + 40);
		glVertex2f(x+ 150, y + i + 3+40);
		glEnd();
	}
	glColor3f(0.88, 0.49, 0.69);
	for (int i = 0; i < 200; i += 10) {
		glBegin(GL_QUADS);
		glVertex2f(x+150, y + i);
		glVertex2f(x+150, y + i + 3);
		glVertex2f(x + 150 +100, y + i - 41);
		glVertex2f(x + 150 +100, y + i + 3 - 41);
		glEnd();
	}
	
	//Used to implement irregular graphics
	glBegin(GL_QUADS);
	glColor3f(0.78,0.4,0.7);
	glVertex2f(x + 45, y+140);
	glVertex2f(x + 45, y + 172);
	glVertex2f(x + 75, y + 180);
	glVertex2f(x + 75 , y + 152);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.78, 0.4, 0.7);
	glVertex2f(x + 45, y + 100-30);
	glVertex2f(x + 45, y + 122 - 30);
	glVertex2f(x + 150, y + 142 - 30);
	glVertex2f(x + 150, y + 94 - 30);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.88, 0.49, 0.69);
	glVertex2f(x + 150, y + 94 - 30);
	glVertex2f(x + 150, y + 142 - 30);
	glVertex2f(x + 250, y + 142 - 30-40);
	glVertex2f(x + 250, y + 94 - 30-20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.88, 0.49, 0.69);
	glVertex2f(x + 200, y + 94-20);
	glVertex2f(x + 200, y + 172+5);
	glVertex2f(x + 220, y + 180 - 15);
	glVertex2f(x + 220, y + 94 - 20);
	glEnd();


	glColor3f(0.5, 0, 0.5);
	drawRectangle(x + 74 * 2 - 1, y, 3, 100 * 2);



}

void drawLogo(int x, int y, int width, int height) {
	glColor3f(0.09, 0.36, 0.66);
	drawRectangle(x, y, width,height);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 100; i++) {
		double theta = -1.0 * M_PI * i / 100;
		double cx = width/2 * cos(theta);
		double cy = width / 2 * sin(theta);
		glVertex2d(x + width/2 + cx, y + cy);
	}
	glEnd();

	glColor3f(1, 1, 1);
	drawCircle(x + width / 2, y, width/7, 100);

	glBegin(GL_TRIANGLES);
	glVertex2f(x+0.1*width,y + 0.7 * height);
	glVertex2f(x + 0.3 * width, y + 0.7 * height);
	glVertex2f(x + 0.2 * width, y + 0.5 * height);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x + 0.7 * width, y + 0.7 * height);
	glVertex2f(x + 0.9 * width, y + 0.7 * height);
	glVertex2f(x + 0.8 * width, y + 0.5 * height);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x + 0.4 * width, y - 0.6 * height);
	glVertex2f(x + 0.6 * width, y - 0.6 * height);
	glVertex2f(x + 0.5 * width, y - 0.8 * height);
	glEnd();

}

void drawTower(int x, int y, int width, int height) {


	glColor3f(1.0, 1.0, 1.0);
	drawRectangle(x, y, width, height);
	drawRectangle(x, y, height, width);

	glBegin(GL_TRIANGLES);
	glVertex2f(x, y + width);
	glVertex2f(x + height, y + width);
	glVertex2f(x + height/2.0, y + width + height);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x+width-height + 1, y + height);
	glVertex2f(x + width +1, y + height);
	glVertex2f(x + width -height/ 2.0 +1, y + 2 * height);
	glEnd();

	glColor3f(0.89, 0.32, 0.5);
	drawCircle(x + 0.5 * height, y + width - 0.6 * height, 0.4 * height, 100);


}
void drawballoons(int x, int y ) {
	int a = 30;
	int b = 50;
	drawEllipse(x, y, a, b, 100);
	glColor3f(1, 1, 1);
	drawCircle(x + 0.7 * a, y + 0.7 * a, 3, 100);
	drawEllipse(x + 0.7 * a +3, y + 0.7 * a - 20, 3, 11, 100);
	drawCubicBezierCurve(x, y-b);
}

void drawSmallXJTLU(int x, int y, int width, int size) {
	drawX(x , y, size);
	drawJ(x + 1.3 * width, y, size);
	drawT(x + 2*width, y, size);
	drawL(x + 3 * width, y, size);
	drawU(x + 4 * width, y,size);
	drawLogo(x + 5 * width, y + size * 5 - 4, size*10,size*6);

}

void drawButton() {
	glColor3f(0.4, 0.2, 0.4); 
	drawCircle(p_B.x - 5, p_B.y - 5, buttonWidth, 100);

	glColor3f(1,1,1); 
	drawCircle(p_B.x, p_B.y, buttonWidth, 100);

	glColor3f(0.09, 0.36, 0.66); 
	drawCircle(p_B.x, p_B.y, buttonWidth-4, 100);
	
	renderBitmapString(p_B.x - buttonWidth, p_B.y - buttonWidth - 30, GLUT_BITMAP_HELVETICA_18, "OPEN");

}

void drawLetter() {
	glColor3f(0.4, 0.2, 0.4);
	drawRectangle(p_Letter.x - 5, p_Letter.y - 8, 400, 160);
	glColor3f(1, 0.98, 0.9);
	drawRectangle(p_Letter.x, p_Letter.y, 400, 160);
}

void  drawLetterCover(){
	glColor3f(0.4, 0.2, 0.4);

	glBegin(GL_TRIANGLES);
	glVertex2f(p_LetterCover.x, p_LetterCover.y + 160);
	glVertex2f(p_LetterCover.x + 400, p_LetterCover.y + 160);
	glVertex2f(p_LetterCover.x + 200, p_LetterCover.y + 80-5);
	glEnd();

	glColor3f(1, 0.98, 0.9);

	glBegin(GL_TRIANGLES);
	glVertex2f(p_LetterCover.x, p_LetterCover.y+160);
	glVertex2f(p_LetterCover.x+400, p_LetterCover.y + 160);
	glVertex2f(p_LetterCover.x + 200 , p_LetterCover.y + 80);
	glEnd();


}

void draw1Flag(int x0, int y0, int length)
{ 
	int x1, y1;
	glBegin(GL_QUAD_STRIP);
	for (int i = x0; i <= x0 + length; i = i + 1)
	{
		x1 = i;
		y1 = 10.0 * sin((i + flagStep) / (10.0)) + y0;
		glColor3f(0.0 / 255, 94.0 / 255, 255.0 / 255);
		glVertex2f(x1, y1 - 20);
		glColor3f(44.0 / 255, 228.0 / 255, 214.0 / 255);
		glVertex2f(x1, y1 + 10);
	}
	glEnd();
}

void drawWholeFlag() {
	draw1Flag(p_flag[0].x, p_flag[0].y, 35);
	glColor3f(1, 1, 1);
	drawRectangle(p_flag[0].x, p_flag[0].y - 70, 4, 70);
	draw1Flag(p_flag[1].x, p_flag[1].y, 35);
	glColor3f(1, 1, 1);
	drawRectangle(p_flag[1].x , p_flag[1].y - 70, 4, 70);
	draw1Flag(p_flag[2].x, p_flag[2].y, 35);
	glColor3f(1, 1, 1);
	drawRectangle(p_flag[2].x , p_flag[2].y - 70, 4, 70);
}


//interaction
void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (x >= p_B.x - buttonWidth && x <= p_B.x + buttonWidth && y >= p_B.y - buttonWidth && y <= p_B.y + buttonWidth) {
			isButtonClicked = true;
			
			
			glutTimerFunc(time_interval+100, OnTimerBalloons, 1);
			glutTimerFunc(time_interval + 500, OnTimerText, 1);
			glutTimerFunc(time_interval, OnTimerButtonGo, 1);
			glutTimerFunc(time_interval, OnTimerLetterGo, 1);
			glutTimerFunc(time_interval, OnTimerLetterCoverGo, 1);
			glutTimerFunc(time_interval + 100, OnTimerBalloons1, 1);
			glutTimerFunc(time_interval + 100, OnTimerBalloons2, 1);
			glutTimerFunc(time_interval + 100, OnTimerFlag, 1);

			return;
		}
	}
}
void keyboard_input(unsigned char key, int x, int y) // keyboard interactions
{
	if (key == 'q' || key == 'Q')
		exit(0);

}

// draw
void display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, 0, windowHeight);
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// background
	glBegin(GL_QUADS);
	glColor3f(0.9,0.6,0.8);  //purple
	glVertex2f(0, 0);
	glColor3f(1,0.41,0.5);  //purple
	glVertex2f(windowWidth, 0);
	glColor3f(0.5, 0, 0.5);  //purple
	glVertex2f(windowWidth, windowHeight);
	glColor3f(0.5, 0, 0.5);  //pink
	glVertex2f(0, windowHeight);
	glEnd();

	

	//2024XJTLU
	//glColor3f(0.4,0.2,0.4);
	//draw2024XJTLU(p0.x - 5, p0.y - 5);
	glColor3f(0.9,0.9,0.9);
	draw2024XJTLU(p0.x,p0.y);
	drawSmallXJTLU(p_label.x, p_label.y, 25, 3);
	
	drawWholeFlag();
	
	glColor3f(1, 0.36, 0.66);
	drawballoons(p_Balloon[1].x, p_Balloon[1].y);
	// letter 
	drawLetter();
	drawLetterCover();
	// button
	drawButton();
	
	
	// text and decorate
	glColor3f(0.9, 1, 1);
	renderBitmapString(p_Text.x, p_Text.y, GLUT_BITMAP_TIMES_ROMAN_24, "Dear all:");
	renderBitmapString(p_Text.x + 15, p_Text.y - 30, GLUT_BITMAP_TIMES_ROMAN_24, "Congratulations on Your Graduation!");
	renderBitmapString(p_Text.x + 15, p_Text.y - 60, GLUT_BITMAP_TIMES_ROMAN_24, "We are thrilled to invite you and your parent to the 2024 XJTLU Graduation Ceremony.");
	renderBitmapString(p_Text.x + 15, p_Text.y - 90, GLUT_BITMAP_TIMES_ROMAN_24, "Join us as we celebrate our graduates' remarkable achievements.");
	renderBitmapString(p_Text.x + 600, p_Text.y - 160, GLUT_BITMAP_HELVETICA_18, "(Press Q to exit the program)");
	
	glColor3f(0.09, 0.36, 1);
	drawballoons(p_Balloon[2].x, p_Balloon[2].y);
	drawCB(p_CB.x,p_CB.y);
	glColor3f(0.09, 1, 0.66);
	drawballoons(p_Balloon[0].x, p_Balloon[0].y);
	drawTower(p_tower.x, p_tower.y,120,40);
	
	glutSwapBuffers();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(1010,600);
	glutCreateWindow("2024 XJTLU Graduation Ceremony");
	glutDisplayFunc(display);
	glutIdleFunc(when_in_mainloop);
	/* glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background
	processing tasks or continuous animation when window system events are not being received.
	If enabled, the idle callback is continuously called when events are not being received. The callback
	routine has no parameters. The current window and current menu will not be changed before the idle
	callback. Programs with multiple windows and/or menus should explicitly set the current window and/or
	current menu and not rely on its current setting. The amount of computation and rendering done in an idle
	callback should be minimized to avoid affecting the program's interactive response. In general, not more
	than a single frame of rendering should be done in an idle callback.
	Assigning NULL to glutIdleFunc disables the generation of the idle callback. */

	glutTimerFunc(time_interval, OnTimerBigChar, 1);
	glutMouseFunc(mouseClick);
	glutKeyboardFunc(keyboard_input);
	glutMainLoop();
}

