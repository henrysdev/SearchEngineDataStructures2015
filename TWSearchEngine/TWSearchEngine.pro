TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    documentparser.cpp \
    avl_tree.cpp \
    stemandstopremoval.cpp \
    index.cpp \
    porter2_stemmer.cpp \
    hashtable.cpp \
    queryprocessor.cpp \
    userinterface.cpp

HEADERS += \
    documentparser.h \
    rapidxml.hpp \
    rapidxml_utils.hpp \
    rapidxml_print.hpp \
    rapidxml_iterators.hpp \
    avl_tree.h \
    stemandstopremoval.h \
    index.h \
    porter2_stemmer.h \
    hash.h \
    string_view.h \
    hashtable.h \
    queryprocessor.h \
    userinterface.h

