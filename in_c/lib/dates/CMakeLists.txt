add_library(Dates
            STATIC)

set(INC include/flmoon.h
        include/julday.h) 

set(SRC src/julday.c
        src/flmoon.c)

target_sources(Dates
               PUBLIC ${SRC})

include_directories(include)

target_include_directories(Dates
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/lib/utilities/include)

target_link_libraries(Dates PUBLIC nrutils m)

install(TARGETS Dates DESTINATION lib)
install(FILES ${INC} DESTINATION include)
