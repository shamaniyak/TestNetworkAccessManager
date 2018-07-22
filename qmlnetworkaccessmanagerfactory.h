#ifndef QMLNETWORKACCESSMANAGERFACTORY_H
#define QMLNETWORKACCESSMANAGERFACTORY_H

#include <QObject>
#include <QQmlNetworkAccessManagerFactory>

class QmlNetworkAccessManagerFactory : public QQmlNetworkAccessManagerFactory
{
public:
  explicit QmlNetworkAccessManagerFactory();

  // QQmlNetworkAccessManagerFactory interface
  QNetworkAccessManager *create(QObject *parent) override;

signals:

public slots:

};

#endif // QMLNETWORKACCESSMANAGERFACTORY_H
