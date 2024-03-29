#ifndef UNTITLED2_GLOBAL_H
#define UNTITLED2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UNTITLED2_LIBRARY)
#  define UNTITLED2_EXPORT Q_DECL_EXPORT
#else
#  define UNTITLED2_EXPORT Q_DECL_IMPORT
#endif

#endif // UNTITLED2_GLOBAL_H
