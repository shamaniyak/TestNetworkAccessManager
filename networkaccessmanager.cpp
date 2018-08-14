#include "networkaccessmanager.h"
#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QNetworkReply>

class NetworkReply : public QNetworkReply
{
public:
    NetworkReply(NetworkAccessManager *manager, const QNetworkRequest &req, const QNetworkAccessManager::Operation op)
        : QNetworkReply(manager)
    {
        setRequest(req);
        setUrl(req.url());
        setOperation(op);
        setFinished(true);
    }

    qint64 bytesAvailable() {

    }

    qint64 size() const override
    {
        return m_data.size();
    }

    QByteArray m_data;
    int m_bytesAvailable = 1;

    // QIODevice interface
protected:
    qint64 readData(char *data, qint64 maxlen) override {
        if(m_bytesAvailable > 0)
            m_bytesAvailable = 0;
        else
            return -1;
        QBuffer buf(&m_data);
        buf.open(QIODevice::ReadOnly);
        return buf.read(data, maxlen);
    }

    // QNetworkReply interface
public slots:
    void abort() override { }

};

NetworkAccessManager::NetworkAccessManager(QObject *parent) : QNetworkAccessManager(parent)
{

}


QNetworkReply *NetworkAccessManager::createRequest(Operation op, const QNetworkRequest &request, QIODevice *outgoingData)
{
  QUrl url = request.url();
  qDebug() << "op = " << op << " url = " << url;
  if(url.scheme() == "memory") {
      QString filePath = QLatin1Char(':') + url.path();
      qDebug() << filePath;
      QFile file(filePath);
      if(file.open(QIODevice::ReadOnly)) {
          NetworkReply *rep = new NetworkReply(this, request, op);
          rep->open(QIODevice::ReadWrite);
          rep->m_data = file.readAll();
          return rep;
      }
      else {
          qDebug() << file.errorString();
      }
    url.setScheme("qrc");
    QNetworkRequest &req = const_cast<QNetworkRequest &>(request);
    req.setUrl(url);
  }
  return QNetworkAccessManager::createRequest(op, request, outgoingData);
}
