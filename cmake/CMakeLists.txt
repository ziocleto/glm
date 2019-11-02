##################################
# CMake install / uninstall script
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(GLM_INSTALL_CONFIGDIR "${CMAKE_INSTALL_LIBDIR}/cmake/glm")
install(DIRECTORY glm DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# CMake automatically adds an architecture compatibility check to make sure
# 32 and 64 bit code is not accidentally mixed. For a header-only library this
# is not required. The check can be disabled by temporarily unsetting
# CMAKE_SIZEOF_VOID_P. In CMake 3.14 and later this can be achieved more cleanly
# with write_basic_package_version_file(ARCH_INDEPENDENT).
# TODO: Use this once a newer CMake can be required.
set(GLM_SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
unset(CMAKE_SIZEOF_VOID_P)
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake" VERSION ${GLM_VERSION} COMPATIBILITY AnyNewerVersion)
set(CMAKE_SIZEOF_VOID_P ${GLM_SIZEOF_VOID_P})

# build tree package config
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/glmBuildConfig.cmake.in glmConfig.cmake @ONLY)

# install tree package config
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/glmConfig.cmake.in
	${GLM_INSTALL_CONFIGDIR}/glmConfig.cmake
	INSTALL_DESTINATION ${GLM_INSTALL_CONFIGDIR}
	PATH_VARS CMAKE_INSTALL_INCLUDEDIR
	NO_CHECK_REQUIRED_COMPONENTS_MACRO)

install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/${GLM_INSTALL_CONFIGDIR}/glmConfig.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
	DESTINATION ${GLM_INSTALL_CONFIGDIR})

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
install(TARGETS glm EXPORT glmTargets)

export(EXPORT glmTargets FILE "${CMAKE_CURRENT_BINARY_DIR}/glmTargets.cmake")

install(EXPORT glmTargets FILE glmTargets.cmake DESTINATION ${GLM_INSTALL_CONFIGDIR})

# build pkg-config file
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/glm.pc.in" "glm.pc" @ONLY)

# install pkg-config file
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/glm.pc" DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")

export(PACKAGE glm)

if(NOT TARGET uninstall)
	configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in
		${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
		IMMEDIATE @ONLY)

	add_custom_target(uninstall
		COMMAND ${CMAKE_COMMAND} -P
		${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

