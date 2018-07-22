#ifndef NETWORKACCESSMANAGER_H
#define NETWORKACCESSMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>

class NetworkAccessManager : public QNetworkAccessManager
{
  Q_OBJECT
public:
  explicit NetworkAccessManager(QObject *parent = nullptr);

signals:

public slots:

  // QNetworkAccessManager interface
protected:
  QNetworkReply *createRequest(Operation op, const QNetworkRequest &request,
                               QIODevice *outgoingData) override;
};

#endif // NETWORKACCESSMANAGER_H
