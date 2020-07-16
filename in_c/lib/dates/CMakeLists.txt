add_library(Dates
            STATIC)

target_sources(Dates
               PUBLIC src/flmoon.c)

include_directories(include)

target_include_directories(Dates
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/lib/utilities/include)

target_link_libraries(Dates PUBLIC nrutils m)

install(TARGETS Dates DESTINATION lib)
install(FILES include/flmoon.h DESTINATION include)
