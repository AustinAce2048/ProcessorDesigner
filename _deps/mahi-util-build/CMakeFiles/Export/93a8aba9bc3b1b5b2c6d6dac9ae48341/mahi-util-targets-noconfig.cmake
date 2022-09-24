#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mahi::fmt" for configuration ""
set_property(TARGET mahi::fmt APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(mahi::fmt PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libfmt.a"
  )

list(APPEND _cmake_import_check_targets mahi::fmt )
list(APPEND _cmake_import_check_files_for_mahi::fmt "${_IMPORT_PREFIX}/lib/libfmt.a" )

# Import target "mahi::util" for configuration ""
set_property(TARGET mahi::util APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(mahi::util PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmahi-util.a"
  )

list(APPEND _cmake_import_check_targets mahi::util )
list(APPEND _cmake_import_check_files_for_mahi::util "${_IMPORT_PREFIX}/lib/libmahi-util.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
