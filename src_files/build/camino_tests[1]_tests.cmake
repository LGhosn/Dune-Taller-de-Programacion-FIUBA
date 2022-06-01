add_test( CaminoTest.creaUnCamino [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.creaUnCamino]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.creaUnCamino PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoTrivial [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoTrivial]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoTrivial PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoConPrecipicio [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoConPrecipicio]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoConPrecipicio PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoConZigZag [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoConZigZag]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoConZigZag PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoImposible [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoImposible]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoImposible PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoConDunas [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoConDunas]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoConDunas PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoConCoordenadasNoValidas [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoConCoordenadasNoValidas]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoConCoordenadasNoValidas PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
add_test( CaminoTest.caminoConCoordenadasEnTerrenoNoAccesible [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests]==] [==[--gtest_filter=CaminoTest.caminoConCoordenadasEnTerrenoNoAccesible]==] --gtest_also_run_disabled_tests)
set_tests_properties( CaminoTest.caminoConCoordenadasEnTerrenoNoAccesible PROPERTIES WORKING_DIRECTORY [==[/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build]==])
set( camino_tests_TESTS CaminoTest.creaUnCamino CaminoTest.caminoTrivial CaminoTest.caminoConPrecipicio CaminoTest.caminoConZigZag CaminoTest.caminoImposible CaminoTest.caminoConDunas CaminoTest.caminoConCoordenadasNoValidas CaminoTest.caminoConCoordenadasEnTerrenoNoAccesible)
