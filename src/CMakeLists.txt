add_library("LibParts" INTERFACE)
target_include_directories("LibParts" INTERFACE .)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "LibParts"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        "LibParts"
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("LibParts")
endif()
