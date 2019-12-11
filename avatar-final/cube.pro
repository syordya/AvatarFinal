QT       += core gui widgets sql opengl

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp \
    dialog.cpp \
    login.cpp \
    register.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    dialog.h \
    login.h \
    mainwidget.h \
    geometryengine.h \
    register.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target

FORMS += \
    dialog.ui \
    login.ui \
    register.ui
