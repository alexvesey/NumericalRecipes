cmake_minimum_required(VERSION 3.16)

project( NumericalRecipesInC
	 VERSION 0.0.1
	 LANGUAGES C )

 add_subdirectory(lib)
 add_subdirectory(bin)
 add_subdirectory(tests)

 install(TARGETS TestDriver)
 install(TARGETS BadLuck)

 enable_testing()
 add_test(NAME TestDriver COMMAND TestDriver)
