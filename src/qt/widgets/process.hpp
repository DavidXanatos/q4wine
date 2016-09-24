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

#include <QWidget>
#include <QSplitter>
#include <QTreeWidget>
#include <QLabel>
#include <QIcon>
#include <QSplitter>
#include <QGridLayout>

#include <memory>

#include "src/qt/widgets/process/processlist.hpp"

class ProcessWidget : public QWidget
{
    Q_OBJECT

 public:
    explicit ProcessWidget(QWidget *parent = 0);
    ~ProcessWidget();

 private:
    void createWidgets();
    const QIcon getIcon(QString name) const;

    std::shared_ptr<ProcessListWidget> w_ProcessList;

    std::shared_ptr<QLabel> lbl_ProcessCount,
                            lbl_PrefixCount;
};