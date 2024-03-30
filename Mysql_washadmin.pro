#-------------------------------------------------
#
# Project created by QtCreator 2023-04-09T18:48:04
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mysql_washadmin
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    page_login.cpp \
    user_concall.cpp \
    design_user_rec.cpp \
    user_change_passwd.cpp \
    classroom_book.cpp \
    admin_mainwindow.cpp \
    admin_login.cpp \
    my_public.cpp \
    public_notice.cpp \
    reply_feedback.cpp

HEADERS += \
        mainwindow.h \
    page_login.h \
    user_concall.h \
    design_user_rec.h \
    user_change_passwd.h \
    classroom_book.h \
    admin_mainwindow.h \
    admin_login.h \
    my_public.h \
    public_notice.h \
    reply_feedback.h

FORMS += \
        mainwindow.ui \
    page_login.ui \
    user_concall.ui \
    design_user_rec.ui \
    user_change_passwd.ui \
    classroom_book.ui \
    admin_mainwindow.ui \
    admin_login.ui \
    my_public.ui \
    public_notice.ui \
    reply_feedback.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES +=

RESOURCES += \
    pp1.qrc \
    pp2.qrc \
    pp3.qrc \
    pp4.qrc \
    pp5.qrc \
    pp6.qrc \
    pp7.qrc \
    pp8.qrc \
    pp9.qrc \
    pp10.qrc \
    pp11.qrc \
    pp12.qrc \
    pp13.qrc \
    pp14.qrc \
    pp15.qrc



