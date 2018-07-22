#include "networkaccessmanager.h"
#include <QDebug>

NetworkAccessManager::NetworkAccessManager(QObject *parent) : QNetworkAccessManager(parent)
{

}


QNetworkReply *NetworkAccessManager::createRequest(Operation op, const QNetworkRequest &request, QIODevice *outgoingData)
{
  QUrl url = request.url();
  qDebug() << "op = " << op << " url = " << url;
  if(url.scheme() == "memory") {
    url.setScheme("qrc");
    QNetworkRequest &req = const_cast<QNetworkRequest &>(request);
    req.setUrl(url);
  }
  return QNetworkAccessManager::createRequest(op, request, outgoingData);
}
