/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWAYLANDSCREEN_H
#define QWAYLANDSCREEN_H

#include <QtGui/QPlatformScreen>

class QWaylandDisplay;
class QWaylandCursor;
struct wl_visual;

class QWaylandScreen : public QPlatformScreen
{
public:
    QWaylandScreen(QWaylandDisplay *waylandDisplay, struct wl_output *output, QRect geometry);
    ~QWaylandScreen();

    QWaylandDisplay *display() const;

    QRect geometry() const;
    int depth() const;
    QImage::Format format() const;

    Qt::ScreenOrientation currentOrientation() const;
    void setOrientation(const Qt::ScreenOrientation orientation);

    wl_visual *visual() const;
    wl_output *output() const { return mOutput; }

    static QWaylandScreen *waylandScreenFromWindow(QWindow *window);

private:
    QWaylandDisplay *mWaylandDisplay;
    struct wl_output *mOutput;
    QRect mGeometry;
    int mDepth;
    QImage::Format mFormat;
    QSize mPhysicalSize;
    Qt::ScreenOrientation mOrientation;
    QWaylandCursor *mWaylandCursor;
};

#endif // QWAYLANDSCREEN_H