if(EXISTS "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino/camino_tests[1]_tests.cmake")
  include("/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino/camino_tests[1]_tests.cmake")
else()
  add_test(camino_tests_NOT_BUILT camino_tests_NOT_BUILT)
endif()
