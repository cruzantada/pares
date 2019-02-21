#include "pares.cpp"

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(650, 675);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Pares");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(getKeyboardInput);
  glutTimerFunc(ANIMATION_MSEC, animate, 0);
  glutMainLoop();

  return 0;
}
