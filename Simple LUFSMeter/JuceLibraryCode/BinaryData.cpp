/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#include <cstring>

namespace BinaryData
{

//================== CMakeLists.txt ==================
static const unsigned char temp_binary_data_0[] =
"set(BUILD_STATIC_LIBS       ON  CACHE BOOL \"Build static library\")\n"
"set(WITH_STATIC_PIC         OFF CACHE BOOL \"Compile static library with -fPIC flag\")\n"
"\n"
"#### queue.h\n"
"file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/queuetest.c\n"
"\"#include <sys/queue.h>\\nLIST_HEAD(listhead, entry) head;\\nint main() { return 0; }\")\n"
"try_compile(HAS_QUEUE ${CMAKE_CURRENT_BINARY_DIR}\n"
"                      ${CMAKE_CURRENT_BINARY_DIR}/queuetest.c)\n"
"\n"
"set(SUMMARY_HAS_QUEUE ${HAS_QUEUE} CACHE INTERNAL \"\")\n"
"\n"
"include(CMakeDependentOption)\n"
"cmake_dependent_option(ENABLE_INTERNAL_QUEUE_H \"Use own queue.h\" OFF \"HAS_QUEUE\" ON)\n"
"# PARENT_SCOPE set necessary due to status print in parent CMakeLists.txt\n"
"set(ENABLE_INTERNAL_QUEUE_H ${ENABLE_INTERNAL_QUEUE_H} PARENT_SCOPE)\n"
"\n"
"if(ENABLE_INTERNAL_QUEUE_H)\n"
"  include_directories(SYSTEM queue)\n"
"endif()\n"
"\n"
"\n"
"if(MSVC)\n"
"  add_definitions(-D_USE_MATH_DEFINES)\n"
"  if(CMAKE_SIZEOF_VOID_P LESS 8)\n"
"    add_definitions(/arch:SSE2)\n"
"  endif()\n"
"endif()\n"
"\n"
"\n"
"set(EBUR128_VERSION_MAJOR 1)\n"
"set(EBUR128_VERSION 1.2.6)\n"
"\n"
"add_library(ebur128 ebur128.c)\n"
"set_target_properties(ebur128 PROPERTIES\n"
"  SOVERSION ${EBUR128_VERSION_MAJOR}\n"
"  VERSION ${EBUR128_VERSION}\n"
")\n"
"\n"
"if(BUILD_SHARED_LIBS)\n"
"  if(MSVC)\n"
"    target_sources(ebur128 PRIVATE ebur128.def)\n"
"  endif()\n"
"else()\n"
"  if(WITH_STATIC_PIC)\n"
"    set_property(TARGET ebur128 PROPERTY POSITION_INDEPENDENT_CODE ON)\n"
"  endif()\n"
"endif()\n"
"\n"
"# Link with Math library if available\n"
"find_library(MATH_LIBRARY m)\n"
"if(MATH_LIBRARY)\n"
"  target_link_libraries(ebur128 ${MATH_LIBRARY})\n"
"endif()\n"
"\n"
"if(ENABLE_FUZZER)\n"
"  target_compile_options(ebur128 PUBLIC \"${FUZZER_FLAGS}\")\n"
"  target_compile_definitions(ebur128 PRIVATE malloc=my_malloc calloc=my_calloc)\n"
"  target_link_libraries(ebur128 \"${SANITIZER_FLAGS}\")\n"
"endif()\n"
"\n"
"set(EBUR128_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL \"\")\n"
"\n"
"install(FILES ebur128.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})\n"
"install(TARGETS ebur128\n"
"  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}\n"
"  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}\n"
"  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})\n"
"\n"
"#### pkg-config\n"
"configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libebur128.pc.cmake\n"
"               ${CMAKE_CURRENT_BINARY_DIR}/libebur128.pc @ONLY)\n"
"install(FILES \"${CMAKE_CURRENT_BINARY_DIR}/libebur128.pc\"\n"
"        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)\n";

const char* CMakeLists_txt = (const char*) temp_binary_data_0;

//================== ebur128.def ==================
static const unsigned char temp_binary_data_1[] =
"LIBRARY EBUR128\n"
"\n"
"EXPORTS\n"
"\tebur128_get_version\n"
"\tebur128_init\n"
"\tebur128_destroy\n"
"\tebur128_set_channel\n"
"\tebur128_change_parameters\n"
"\tebur128_set_max_window\n"
"\tebur128_set_max_history\n"
"\tebur128_add_frames_short\n"
"\tebur128_add_frames_int\n"
"\tebur128_add_frames_float\n"
"\tebur128_add_frames_double\n"
"\tebur128_loudness_global\n"
"\tebur128_loudness_global_multiple\n"
"\tebur128_loudness_momentary\n"
"\tebur128_loudness_shortterm\n"
"\tebur128_loudness_window\n"
"\tebur128_loudness_range\n"
"\tebur128_loudness_range_multiple\n"
"\tebur128_sample_peak\n"
"\tebur128_prev_sample_peak\n"
"\tebur128_true_peak\n"
"\tebur128_prev_true_peak\n"
"\tebur128_relative_threshold\n";

const char* ebur128_def = (const char*) temp_binary_data_1;

//================== libebur128.pc.cmake ==================
static const unsigned char temp_binary_data_2[] =
"prefix=@CMAKE_INSTALL_PREFIX@\n"
"includedir=${prefix}/include\n"
"libdir=${prefix}/@CMAKE_INSTALL_LIBDIR@\n"
"\n"
"Name: libebur128\n"
"Description: EBU R 128 standard for loudness normalisation\n"
"Version: @EBUR128_VERSION@\n"
"URL: https://github.com/jiixyj/libebur128\n"
"Libs: -L${libdir} -lebur128\n"
"Libs.private: -lm\n"
"Cflags: -I${includedir}\n";

const char* libebur128_pc_cmake = (const char*) temp_binary_data_2;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x90e15cf5:  numBytes = 2265; return CMakeLists_txt;
        case 0xc08a08c3:  numBytes = 592; return ebur128_def;
        case 0xac6fc60c:  numBytes = 315; return libebur128_pc_cmake;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "CMakeLists_txt",
    "ebur128_def",
    "libebur128_pc_cmake"
};

const char* originalFilenames[] =
{
    "CMakeLists.txt",
    "ebur128.def",
    "libebur128.pc.cmake"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
        if (strcmp (namedResourceList[i], resourceNameUTF8) == 0)
            return originalFilenames[i];

    return nullptr;
}

}
