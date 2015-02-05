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
#include <QString>

namespace WebServer {

class Engine;

/**
 * @brief The Application class
 */
class Application : public Logger, public Http::Responder {
public:
    Application(QString rootDirectory);

    /**
     * @brief respond
     * @param request
     * @param response
     */
    void respond(NetworkRequest& request, NetworkResponse& response);

protected:
    QString _rootDirectory;
};

} // namespace WebServer

