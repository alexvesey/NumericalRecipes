add_library(nrutils STATIC src/nrutil.c)

install(TARGETS nrutils DESTINATION lib)
install(FILES include/nrutil.h DESTINATION include) 
