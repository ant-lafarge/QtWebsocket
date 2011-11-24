#ifndef QWSSERVER_H
#define QWSSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QQueue>

#include "QWsSocket.h"

class QWsServer : public QObject
{
	Q_OBJECT

public:
	// ctor
	QWsServer(QObject * parent = 0);
	// dtor
	virtual ~QWsServer();

	// public methods
	bool listen(const QHostAddress & address = QHostAddress::Any, quint16 port = 0);
	void close();
	QAbstractSocket::SocketError serverError();
	QString errorString();
	bool hasPendingConnections();
	virtual QWsSocket * nextPendingConnection();
	int maxPendingConnections();

signals:
	void newConnection();

protected:
	// Protected methods
	void addPendingConnection( QWsSocket * socket );
	void incomingConnection( int socketDescriptor );

private:
	// private methods
	void treatSocketError();
	QString computeAcceptV8( QString key );

private slots:
	// private slots
	void newTcpConnection();
	void dataReceived();

private:
	// private attributes
	QTcpServer * tcpServer;
	QAbstractSocket::SocketError serverSocketError;
	QString serverSocketErrorString;
	QQueue<QWsSocket*> pendingConnections;

public:
	// public static vars
	static const QString regExpResourceNameStr;
	static const QString regExpHostStr;
	static const QString regExpKeyStr;
	static const QString regExpVersionStr;
	static const QString regExpOriginStr;
	static const QString regExpProtocolStr;
	static const QString regExpExtensionsStr;
};

#endif // QWSSERVER_H
