cmake_minimum_required(VERSION 4.2)
project(proyecto_programacion_ll)

set(CMAKE_CXX_STANDARD 26)

add_executable(proyecto_programacion_ll main.cpp
        Equipo.cpp
        Equipo.h
        EquipoCritico.cpp
        EquipoCritico.h
        EquipoNormal.cpp
        EquipoNormal.h
        Incidencia.cpp
        Incidencia.h
        Mantenimiento.h
        MantenimientoBase.cpp
        MantenimientoBase.h
        MantenimientoDecorator.cpp
        MantenimientoDecorator.h)
