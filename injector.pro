TEMPLATE    = app

SOURCES     = jack_engine.cpp \
injector.cpp \
main.cpp

HEADERS     = jack_engine.h \
injector.h

INCLUDEPATH += /usr/include/
INCLUDEPATH += /usr/local/include/

LIBS += -ljack -lqjack

QT += xml

pics.path = /usr/share/pixmaps/
pics.files = ./pics/injector.png
INSTALLS += pics

target.path += /usr/bin/
INSTALLS += target


CONFIG += release

DESTDIR=bin
MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

RESOURCES= application.qrc

