#include "qmlnetworkaccessmanagerfactory.h"
#include "networkaccessmanager.h"

QmlNetworkAccessManagerFactory::QmlNetworkAccessManagerFactory() :
  QQmlNetworkAccessManagerFactory()
{

}

QNetworkAccessManager *QmlNetworkAccessManagerFactory::create(QObject *parent)
{
  return new NetworkAccessManager(parent);
}
