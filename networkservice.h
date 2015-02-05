//
// Copyright 2010-2015 Jacob Dawid <jacob@omg-it.works>
//
// This file is part of QtWebServer.
//
// QtWebServer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QtWebServer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QtWebServer.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

// Own includes
#include "responder.h"
#include "logger.h"

// Qt includes
#include <QTcpServer>
#include <QVector>

namespace WebServer {

class NetworkServiceThread;

/**
 * @brief The WebService class
 * @author Jacob Dawid
 * @date 23.11.2013
 */
class NetworkService : public QTcpServer, public Logger {
    Q_OBJECT
public:
    /**
     * @brief WebService
     */
    NetworkService();

    /**
     * @brief ~WebService
     */
    virtual ~NetworkService();

    /**
     * @brief initialize
     */
    void initialize();

    /**
     * @brief httpResponder
     * @return
     */
    Http::Responder *httpResponder();

    /**
     * @brief setHttpResponder
     * @param httpResponder
     */
    void setHttpResponder(Http::Responder *httpResponder);

protected:
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
    /**
     * @brief incomingConnection
     * @param handle
     */
    void incomingConnection(int handle);
#else
    /**
     * @brief incomingConnection
     * @param handle
     */
    void incomingConnection(qintptr handle);
#endif

private:
    Http::Responder *_httpResponder;
    int _port;
    int _threads;

    int _nextRequestDelegatedTo;
    QVector<NetworkServiceThread*> _NetworkServiceThreads;
};

} // namespace WebServer

