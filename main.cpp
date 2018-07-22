#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "qmlnetworkaccessmanagerfactory.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.setNetworkAccessManagerFactory(new QmlNetworkAccessManagerFactory());
  engine.load(QUrl(QStringLiteral("memory:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
