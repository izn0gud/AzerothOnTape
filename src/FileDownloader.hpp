#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>

enum RequestType {
    GET,
    POST
};

class FileDownloader : public QObject {
Q_OBJECT
public:
    explicit FileDownloader(RequestType type, QUrl url, QJsonObject json, QObject *parent = nullptr);

    virtual ~FileDownloader();

    QByteArray downloadedData() const;

signals:

    void downloaded();

private slots:

    void fileDownloaded(QNetworkReply *pReply);

private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
};

#endif // FILEDOWNLOADER_H