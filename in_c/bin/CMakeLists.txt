add_executable(Driver Driver.c) 

target_include_directories(Driver
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/lib/dates/include)

target_link_libraries(Driver Dates)
