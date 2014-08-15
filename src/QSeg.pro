
QT += widgets

SOURCES += \
    main.cpp \
    snake.cpp \
    canny.cpp \
    histograms.cpp \
    gradients.cpp \
    dct.cpp \
    extrafilters.cpp \
    image_interface.cpp \
    segmentationgraph.cpp \
    segmentationlevelset.cpp \
    bisegmentationgraph.cpp \
    myqlineedit.cpp

HEADERS += \
    canny.h \
    snake.h \
    histograms.h \
    gradients.h \
    dct.h \
    extrafilters.h \
    image_interface.h \
    segmentationgraph.h \
    segmentationlevelset.h \
    bisegmentationgraph.h \
    myqlineedit.h \
    my_user_types.h

QMAKE_CXXFLAGS += -std=c++11
