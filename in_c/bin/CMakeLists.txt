add_executable(TestDriver TestDriver.c) 

target_include_directories(TestDriver
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/lib/dates/include)

target_link_libraries(TestDriver Dates)

add_executable(BadLuck badluk.c)
 
target_include_directories(BadLuck
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/lib/dates/include)

target_link_libraries(BadLuck Dates)
