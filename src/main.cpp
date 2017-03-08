
#include <QApplication>

#include "window.hpp"
#include "introwindow.hpp"


int main(int argc,char *argv[])
{
  QApplication app(argc,argv);
  /*window win;
  win.show();*/
  IntroWindow intro;
  intro.show();
  return app.exec();
}
