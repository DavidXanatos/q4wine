/***************************************************************************
 *   Copyright (C) 2008-2016 by Alexey S. Malakhov <brezerk@gmail.com>     *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 ***************************************************************************/

#pragma once

#include <QString>

#include "src/lib/defines.hpp"

namespace q4wine {
namespace lib {

/*! \class WineVersion wineversion.h <q4wine/src/lib/wineversion.h>
 * \brief Describes a wine version configuration.
 *
 * \par Wine Terms
 *
 * Wine allows user to set WINESERVER, WINELOADER and WINEDLLPATH env
 * variables to use different binaries. This allows user to have multiple
 * wine instances installed on the system.
 *
 * \par Q4Wine Terms
 *
 * \note It is possible to have multiple WinePrefix pointed to the single
 * directory. In combination with WineVersion: setups is possible to run a
 * number of truly independent wine processes.
 *
 * \author Alexey S. Malakhov <brezerk@gmail.com>
 */
class WineVersion {
 public:
    /*! Constructs an empty WineVersion object. */
    WineVersion();
    /*! Constructs an WineVersion object.
     *
     * \param binary general wine binary. Defaults to /usr/bin/wine if not
     * set and if this doesn't exist we will then look for a file named "wine"
     * in the path and in a few other likely locations.
     * See also: #setBinary #getBinary
     *
     * \param loader specifies the path and name of the wine binary to use to
     * launch new Windows processes. If not set, Wine will try to load
     * /usr/bin/wine, and if this doesn't exist it will then look for a file
     * named "wine" in the path and in a few other likely locations.
     * See also: #setLoader #getLoader
     *
     * \param server specifies the path and name of the wineserver binary.
     * If not set, Wine will try to load /usr/bin/wineserver, and if this
     * doesn't exist it will then look for a file named "wineserver" in the
     * path and in a few other likely locations.
     * See also: #setServer #getServer
     *
     * \param libs32 Specifies the path(s) in which to search for builtin
     * dlls and Winelib applications. This is a list of directories separated
     * by ":". In addition to any directory specified in WINEDLLPATH, Wine
     * will also look in /usr/lib32/wine.
     * See also: #setLibs32 #getLibs32 #getLibs
     *
     * \param libs64 Specifies the path(s) in which to search for builtin
     * dlls and Winelib applications. This is a list of directories separated
     * by ":". In addition to any directory specified in WINEDLLPATH, Wine
     * will also look in /usr/lib64/wine.
     * See also: #setLibs64 #getLibs64 #getLibs
    */
    WineVersion(
            QString binary,
            QString loader,
            QString server,
            QString libs32,
            QString libs64);
    ~WineVersion();
    void setBinary(QString binary);
    void setLoader(QString loader);
    void setServer(QString server);
    void setLibs32(QString libs32);
    void setLibs64(QString libs64);

    const QString getBinary(void) const;
    const QString getLoader(void) const;
    const QString getServer(void) const;
    const QString getLibs32(void) const;
    const QString getLibs64(void) const;
    /*! Return libs configured for provided version */
    const QString getLibs(q4wine::lib::WineArch arch) const;

 private:
    QString binary_;
    QString loader_;
    QString server_;
    QString libs32_;
    QString libs64_;
};
}  // namespace lib
}  // namespace q4wine
