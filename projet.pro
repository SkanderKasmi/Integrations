QT       += core gui printsupport network sql serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuil.cpp \
    arduino.cpp \
    client.cpp \
    client_c.cpp \
    commande.cpp \
    commande_c.cpp \
    compte.cpp \
    compte_c.cpp \
    connection.cpp \
    depense.cpp \
    depense_c.cpp \
    employe.cpp \
    inscrit.cpp \
    main.cpp \
    mainwindow.cpp \
    mdp_oubli.cpp \
    menu.cpp \
    menu_c.cpp \
    modif_profil.cpp \
    notificatin.cpp \
    salaire.cpp \
    salaire_c.cpp \
    statis.cpp \
    stock.cpp \
    stock_c.cpp

HEADERS += \
    arduino.h \
    commande_c.h \
    connection.h \
    acceuil.h \
    client.h \
    client_c.h \
    commande.h \
    compte.h \
    compte_c.h \
    connection.h \
    depense.h \
    depense_c.h \
    employe.h \
    inscrit.h \
    mainwindow.h \
    mdp_oubli.h \
    menu.h \
    menu_c.h \
    modif_profil.h \
    notificatin.h \
    salaire.h \
    salaire_c.h \
    statis.h \
    stock.h \
    stock_c.h

FORMS += \
    acceuil.ui \
    client.ui \
    commande.ui \
    compte.ui \
    depense.ui \
    inscrit.ui \
    mainwindow.ui \
    mdp_oubli.ui \
    menu.ui \
    modif_profil.ui \
    notificatin.ui \
    salaire.ui \
    statis.ui \
    stock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    img/img.qrc
