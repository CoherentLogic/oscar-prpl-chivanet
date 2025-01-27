cmake_minimum_required(VERSION 3.18) # see purple-config.cmake

project("oscarprpl")

# include purple-cmake config file path
set(CMAKE_PREFIX_PATH "..")
find_package(Purple REQUIRED)

# have some debug output
message(STATUS "PURPLE_INCLUDE_DIRS: ${PURPLE_INCLUDE_DIRS}")
message(STATUS "PURPLE_LIBRARY_DIRS: ${PURPLE_LIBRARY_DIRS}")
message(STATUS "PURPLE_LIBRARIES: ${PURPLE_LIBRARIES}")
message(STATUS "PURPLE_PLUGIN_DIR: ${PURPLE_PLUGIN_DIR}")
message(STATUS "PURPLE_DATA_DIR: ${PURPLE_DATA_DIR}")

link_directories(${PURPLE_LIBRARY_DIRS})

# define our target
set(TARGET_NAME "oscarprpl")
add_library(${TARGET_NAME} SHARED 
    "src/c/libaim.c"
    "src/c/authorization.c"
    "src/c/bstream.c"
    "src/c/clientlogin.c"
    "src/c/encoding.c"
    "src/c/family_admin.c"
    "src/c/family_alert.c"
    "src/c/family_auth.c"
    "src/c/family_bart.c"
    "src/c/family_bos.c"
    "src/c/family_buddy.c"
    "src/c/family_chat.c"
    "src/c/family_chatnav.c"
    "src/c/family_feedbag.c"
    "src/c/family_icbm.c"
    "src/c/family_icq.c"
    "src/c/family_locate.c"
    "src/c/family_oservice.c"
    "src/c/family_popup.c"
    "src/c/family_stats.c"
    "src/c/family_userlookup.c"
    "src/c/flap_connection.c"
    "src/c/kerberos.c"
    "src/c/misc.c"
    "src/c/msgcookie.c"
    "src/c/odc.c"
    "src/c/oft.c"
    "src/c/oscar_data.c"
    "src/c/oscar.c"
    "src/c/peer_proxy.c"
    "src/c/peer.c"
    "src/c/rxhandlers.c"
    "src/c/snac.c"
    "src/c/tlv.c"
    "src/c/util.c"
    "src/c/userinfo.c"
    "src/c/visibility.c"
)

file(READ "${CMAKE_SOURCE_DIR}/VERSION" PLUGIN_VERSION)
target_compile_definitions(${TARGET_NAME} PRIVATE PLUGIN_VERSION=${PLUGIN_VERSION})
target_include_directories(${TARGET_NAME} PRIVATE ${PURPLE_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} PRIVATE ${PURPLE_LIBRARIES}) # TODO: switch to PkgConfig::Purple
set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "lib")

# declare destinations
if (WIN32)
    install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION "${PURPLE_PLUGIN_DIR}")
else()
    install(TARGETS ${TARGET_NAME} DESTINATION "${PURPLE_PLUGIN_DIR}")
endif()
install(DIRECTORY "pixmaps" DESTINATION "${PURPLE_DATA_DIR}" FILES_MATCHING PATTERN "*.png")
