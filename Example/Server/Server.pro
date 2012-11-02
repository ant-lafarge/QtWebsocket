QT       += core
QT       += gui
QT       += network
contains(QT_VERSION, ^5\\..*) {
QT       += widgets
}

TARGET = Server
CONFIG   -= console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += Log.cpp \
    Server.cpp \
    main.cpp

HEADERS += Log.h \
    QWsServer.h \
    QWsSocket.h \
    Server.h

win32:CONFIG(release, debug|release): LIBS += -L../../QtWebsocket/release/ -lQtWebsocket
else:win32:CONFIG(debug, debug|release): LIBS += -L../../QtWebsocket/debug/ -lQtWebsocket
else:unix:!symbian: LIBS += -L../../QtWebsocket/ -lQtWebsocket

INCLUDEPATH += ../../QtWebsocket
DEPENDPATH += ../../QtWebsocket

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += ../../QtWebsocket/release/QtWebsocket.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += ../../QtWebsocket/debug/QtWebsocket.lib
else:unix:!symbian: PRE_TARGETDEPS += ../../QtWebsocket/libQtWebsocket.a
