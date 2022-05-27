add_test( Mapa.un_mapa_comienza_sin_colisiones /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.un_mapa_comienza_sin_colisiones]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.un_mapa_comienza_sin_colisiones PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.no_se_puede_construir_sobre_arena /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.no_se_puede_construir_sobre_arena]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.no_se_puede_construir_sobre_arena PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.no_se_puede_construir_sobre_precipicios /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.no_se_puede_construir_sobre_precipicios]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.no_se_puede_construir_sobre_precipicios PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.no_se_puede_construir_sobre_duna /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.no_se_puede_construir_sobre_duna]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.no_se_puede_construir_sobre_duna PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.no_se_puede_construir_sobre_cimas /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.no_se_puede_construir_sobre_cimas]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.no_se_puede_construir_sobre_cimas PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.se_puede_construir_sobre_rocas /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.se_puede_construir_sobre_rocas]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.se_puede_construir_sobre_rocas PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.no_se_puede_construir_sobre_otros_edificios /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.no_se_puede_construir_sobre_otros_edificios]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.no_se_puede_construir_sobre_otros_edificios PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.no_se_puede_edificar_a_menos_de_5_bloques /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.no_se_puede_edificar_a_menos_de_5_bloques]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.no_se_puede_edificar_a_menos_de_5_bloques PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.se_puede_construir_a_mas_de_5_bloques /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.se_puede_construir_a_mas_de_5_bloques]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.se_puede_construir_a_mas_de_5_bloques PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
add_test( Mapa.se_puede_construir_despues_de_demoler /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build/pruebas_mapa [==[--gtest_filter=Mapa.se_puede_construir_despues_de_demoler]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mapa.se_puede_construir_despues_de_demoler PROPERTIES WORKING_DIRECTORY /home/lautaro/Programacion/Taller_de_Programacion/Dune-Taller-de-Programacion-FIUBA/pruebas_mapa/build)
set( pruebas_mapa_TESTS Mapa.un_mapa_comienza_sin_colisiones Mapa.no_se_puede_construir_sobre_arena Mapa.no_se_puede_construir_sobre_precipicios Mapa.no_se_puede_construir_sobre_duna Mapa.no_se_puede_construir_sobre_cimas Mapa.se_puede_construir_sobre_rocas Mapa.no_se_puede_construir_sobre_otros_edificios Mapa.no_se_puede_edificar_a_menos_de_5_bloques Mapa.se_puede_construir_a_mas_de_5_bloques Mapa.se_puede_construir_despues_de_demoler)