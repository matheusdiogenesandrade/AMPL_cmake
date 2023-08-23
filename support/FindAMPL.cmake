# - Try to find AMPL
# Once done this will define
#  AMPL_FOUND - System has AMPL
#  AMPL_LIBRARY - The directory needed to use AMPL


# in cache already
if (AMPL_LIBRARY)
    SET(AMPL_FIND_QUIETLY TRUE)
endif (AMPL_LIBRARY)


IF ( UNIX )
    # target not already created
    if (NOT TARGET ampl)

        # ampl dir
        find_path(AMPL_DIR NAMES "ampl"
            PATHS 
            "/opt/ampl/"
            "/opt/AMPL/"
            "~/ampl/"
            "~/AMPL/"
            )

        # edge case
        IF( NOT AMPL_FIND_QUIETLY AND NOT AMPL_DIR)
            message ( "AMPL_DIR not found ")
        ENDIF()

        # amplapi
        set(AMPL_API_DIR "${AMPL_DIR}/amplapi")

        # runpath
        set(CMAKE_INSTALL_RPATH "${AMPL_API_DIR}/lib")
        set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

        # lib
        set(AMPL_LIBRARY_NAME "ampl")
        add_library(ampl STATIC IMPORTED)
        find_library(AMPL_LIBRARY ${AMPL_LIBRARY_NAME} PATHS ${CMAKE_INSTALL_RPATH})

        # edge case
        if(NOT(AMPL_LIBRARY))
            message(FATAL_ERROR "AMPL library \"${AMPL_LIBRARY_NAME}\" could not be found")
        endif()

        set_target_properties(ampl PROPERTIES
            IMPORTED_LOCATION ${AMPL_LIBRARY}
            INTERFACE_INCLUDE_DIRECTORIES ${AMPL_API_DIR}/include)

    endif ()


    include(FindPackageHandleStandardArgs)
    # handle the QUIETLY and REQUIRED arguments and set LIBAMPL_FOUND to TRUE
    # if all listed variables are TRUE
    find_package_handle_standard_args(AMPL  DEFAULT_MSG AMPL_LIBRARY)

    mark_as_advanced(AMPL_LIBRARY)

ENDIF()






