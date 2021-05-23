cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME Lab_Plex) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(TBaseLib TBaseLib) #Переменная с именем библиотеки
set(TCanvasLib TCanvasLib) #Переменная с именем библиотеки
set(TLineLib TLineLib) #Переменная с именем библиотеки
set(TPlexLib TPlexLib) #Переменная с именем библиотеки
set(TPointLib TPointLib) #Переменная с именем библиотеки
set(TSquareLib TSquareLib) #Переменная с именем библиотеки
set(StackLib StackLib) #Переменная с именем библиотеки
set(main main)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TBaseLib) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TCanvasLib) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TLineLib) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TPlexLib) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TPointLib) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TSquareLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)

#Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(TBaseLib)
add_subdirectory(TCanvasLib)
add_subdirectory(TLineLib)
add_subdirectory(TPlexLib)
add_subdirectory(TPointLib)
add_subdirectory(TSquareLib)
add_subdirectory(StackLib)
add_subdirectory(main)

add_subdirectory(gtest)
add_subdirectory(test)