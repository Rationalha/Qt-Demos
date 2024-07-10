#ifndef TTKFUNCTIONLISTVWIDGET_H
#define TTKFUNCTIONLISTVWIDGET_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "ttkfunctionlisthwidget.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKFunctionListVWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKFunctionListVWidget(QWidget *parent = 0);
    ~TTKFunctionListVWidget();

    void resizeMode(bool mode);

Q_SIGNALS:
    void currentIndexChanged(int index);

public Q_SLOTS:
    void selectedChanged(TTKFunctionItemWidget *item);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

    QList<TTKFunctionItemWidget*> m_items;

};

#endif // TTKFUNCTIONLISTVWIDGET_H
