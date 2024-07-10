# =================================================
# * This file is part of the TTK WidgetTools project
# * Copyright (C) 2015 - 2018 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# =================================================

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TTKWidgetTools
TEMPLATE = app

UI_DIR = ./.build/ui
MOC_DIR = ./.build/moc
OBJECTS_DIR = ./.build/obj
RCC_DIR = ./.build/rcc

win32:msvc{
    CONFIG +=c++11
}else{
    QMAKE_CXXFLAGS += -std=c++11
}

SOURCES += \
    main.cpp\
    mainwindow.cpp

HEADERS  += \
    ttkglobaldefine.h \
    ttkwidgettools.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

INCLUDEPATH += $$PWD

include(Button/Button.pri)
include(Label/Label.pri)
include(Meter/Meter.pri)
include(Progress/Progress.pri)
include(Slider/Slider.pri)
include(Title/Title.pri)
include(Widget/Widget.pri)
include(Window/Window.pri)
