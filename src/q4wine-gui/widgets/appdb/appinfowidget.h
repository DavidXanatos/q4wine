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

#ifndef APPINFOWIDGET_H
#define APPINFOWIDGET_H

#include <src/q4wine-gui/ui_AppInfoWidget.h>

//System
#include <memory>

//Global config
#include "config.h"

//Widgets
#include "lineitemwidget.h"

//Struct
#include "appdbstructs.h"

//Qt inicludes
#ifdef DEBUG
#include <QDebug>
#endif

/*!
 * \class AppInfoWidget
 * \ingroup widgets
 * \brief This class provide database functions for AppDB search widget.
 *
 */
class AppInfoWidget : public QWidget, public Ui::AppInfoWidget
{
Q_OBJECT
public:
    /*! \brief class constructor
    *
    * \param  name         General application name.
    * \param  desc  Short  Application description.
    * \param  versions     An QList of QStringList witch describes tested app versions.
    * \param  url	       Application url to open.
    */

    AppInfoWidget(QString name, QString desc, const int appid, QList<WineAppDBVersionInfo> versions, QWidget *parent = 0);

    //! \brief class destructor;
    ~AppInfoWidget();
signals:
     void itemTrigged(short int, QString, int, int, int);

private:
    /*! \brief sets general application Name
    *
    * \param  name         General application name.
    * \return Nothing.
    */
    void setAppName(QString name);

    /*! \brief sets general application description and trim it to 255 chars
    *
    * \param  desc  Short Application description.
    * \return Nothing.
    */
    void setAppDesc(QString desc);

    int appid;
protected:
    //! \brief Event filter.
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // APPINFOWIDGET_H
