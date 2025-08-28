add_executable(s9slicer-gui
    main.cpp
    MainWindow.cpp
    MainWindow.h
    GLViewport.cpp
    GLViewport.h
)
target_link_libraries(s9slicer-gui PRIVATE Qt6::Widgets Qt6::OpenGLWidgets)
