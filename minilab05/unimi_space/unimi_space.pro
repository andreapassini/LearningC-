TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        temp.cpp

HEADERS += \
    mat3.h \
    point3.h \
    quaternion.h \
    vector3.h \
    versor3.h
