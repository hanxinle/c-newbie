#include <gl/glut.h>
#include <math.h>

#define PI 3.14159
#define RzArgu -90*PI/180     


//initial points 
const static float point[4][3] = { 
	{ 0.125 , -0.125 ,0.25 },
	{ 0.25  , 0.25   , 0   },
	{ 0.25  , -0.25  , 0   },
	{ -0.25 , -0.25  , 0   } 
};
//Afer Rotate,points
static float pointR[4][3] = { 0 };
//acaculate mat
typedef float Mat4x4[4][4];       

const static Mat4x4 Rzdata = { 
	{cos(RzArgu) ,-sin(RzArgu),0,0} ,
	{sin(RzArgu ),cos(RzArgu ),0,0} ,
	{0,0,1,0}                       ,
	{0,0,0,1}
};

//axis X -90°== Front 
void Rx(const float temp[4][3])  {                       
	for (int i = 0; i < 4; i++)  {
		pointR[i][1] = Rzdata[0][0] * temp[i][1] + Rzdata[0][1] * temp[i][2];
		pointR[i][2] = Rzdata[1][0] * temp[i][1] + Rzdata[1][1] * temp[i][2];
		pointR[i][0] = temp[i][0];
	}
}

//Rx + axis Y -90 == Right
void Ry(const float temp[4][3])  {
	for (int i = 0; i < 4; i++)  {
		pointR[i][2] = Rzdata[0][0] * temp[i][2] + Rzdata[0][1] * temp[i][0];
		pointR[i][0] = Rzdata[1][0] * temp[i][2] + Rzdata[1][1] * temp[i][0];
		pointR[i][1] = temp[i][1];
	}
}

//axis Z -90°-- in fact i used -45°
void Rz(const float temp[4][3])  {
	for (int i = 0; i < 4; i++)  {
		pointR[i][0] = Rzdata[0][0] * temp[i][0] + Rzdata[0][1] * temp[i][1];
		pointR[i][1] = Rzdata[1][0] * temp[i][0] + Rzdata[1][1] * temp[i][1];
		pointR[i][2] = temp[i][2];
	}
}

void Topview()  {                                         
	glClear(GL_COLOR_BUFFER_BIT);                            
	glBegin(GL_LINE_LOOP);                                     
	glColor3f(1, 0, 0);                                    
	glVertex3fv(point[0]);
	glVertex3fv(point[1]);
	glVertex3fv(point[2]);
	glVertex3fv(point[3]);
	glVertex3fv(point[1]);
	glVertex3fv(point[2]);
	glVertex3fv(point[0]);
	glVertex3fv(point[3]);

	glEnd(); 
	glutSwapBuffers();                                      
}

void ChangeView()                                           
{
	glClear(GL_COLOR_BUFFER_BIT);                           
	glBegin(GL_LINE_LOOP);                                     
	glColor3f(1, 1, 0);                                     
	glVertex3fv(pointR[0]);
	glVertex3fv(pointR[1]);
	glVertex3fv(pointR[2]);
	glVertex3fv(pointR[3]);
	glVertex3fv(pointR[1]);
	glVertex3fv(pointR[2]);
	glVertex3fv(pointR[0]);
	glVertex3fv(pointR[3]);
	glEnd(); 
	glutSwapBuffers();                                      
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);                              
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);       
												        
	int windowHandle0 = glutCreateWindow("顶视图");              
	glutDisplayFunc(Topview);


	
	Rx(point);                                                   //FrontV with -90°
	int windowHandle2 = glutCreateWindow("前视图");
	glutDisplayFunc(ChangeView);
	
	
	
	/*
	Rx(point);                                                    //RightV with -90°
	Ry(pointR);
	int windowHandle1 = glutCreateWindow("右视图");
	glutDisplayFunc(ChangeView);
	*/


	/*
    Rx(point);                                                  //StereoV with -45°
    Ry(pointR);
	int windowHandle3 = glutCreateWindow("立体视图");
    glutDisplayFunc(ChangeView);
	*/
	glutMainLoop();                                     
	return 0;
}
