TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    documentparser.cpp

HEADERS += \
    documentparser.h \
    rapidxml.hpp \
    rapidxml_utils.hpp \
    rapidxml_print.hpp \
    rapidxml_iterators.hpp

