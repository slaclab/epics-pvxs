/**
 * Copyright - See the COPYRIGHT that is included with this distribution.
 * pvAccessCPP is distributed subject to a Software License Agreement found
 * in file LICENSE that is included with this distribution.
 */
#ifndef PVXS_VERSION_H
#define PVXS_VERSION_H

#if defined(_WIN32) || defined(__CYGWIN__)

#  if defined(PVXS_API_BUILDING) && defined(EPICS_BUILD_DLL)
/* building library as dll */
#    define PVXS_API __declspec(dllexport)
#  elif !defined(PVXS_API_BUILDING) && defined(EPICS_CALL_DLL)
/* calling library in dll form */
#    define PVXS_API __declspec(dllimport)
#  endif

#elif __GNUC__ >= 4
#  define PVXS_API __attribute__ ((visibility("default")))
#endif

#ifndef PVXS_API
#  define PVXS_API
#endif

#include <pvxs/versionNum.h>

#ifndef VERSION_INT
#  define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif

#define PVXS_VERSION VERSION_INT(PVXS_MAJOR_VERSION, PVXS_MINOR_VERSION, PVXS_MAINTENANCE_VERSION, 0)

namespace pvxs {
}

#endif // PVXS_VERSION_H