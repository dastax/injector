#include <QtCore>
#include "injector.h"

void usage(QString appname, QString error="") {
  QTextStream out(stdout);
  
  if (!error.isEmpty())
    out << "error: " << error << "\n";
  out << "Usage: " << appname << " [options]\n";
  out << "\t options:\n";
  out << "\t\t-n name (set the client name to name)\n";
  out << "\t\t-h (show this help!)\n";
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Q_INIT_RESOURCE(resources_qjack);

  QFile qss(":/qss");
  qss.open(QFile::ReadOnly);
  QString st=qss.readAll();
  //qDebug()<<st;
  a.setStyleSheet(st);
  qss.close();

  QString name="";
  QString arg;
  QTextStream out(stdout); 
      
  for (int i=1; i < argc; i++) {
    arg=argv[i];
    if (arg == "-n") {
      if (i+1 < argc) {
	i++;
	name=argv[i];
      }
      else {
	usage(argv[0], "error: client name missing!");
	exit(1);
      }
    }
    if (arg == "-h") {
      usage(argv[0]);
      exit(0);
    }
  }


  Injector dlg(name);
  //dlg.show();
  return a.exec();
}
