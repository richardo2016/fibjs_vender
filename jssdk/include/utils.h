/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-05 01:13:31
 * @modify date 2020-05-05 01:13:31
 * @desc jssdk's fiber runtime for fibjs
 */

#ifndef _jssdk_utils_h__
#define _jssdk_utils_h__

#ifndef EXTERN_C_START
#if __cplusplus
#define EXTERN_C_START extern "C" {
#else
#define EXTERN_C_START
#endif
#endif // EXTERN_C_START

#ifndef EXTERN_C_END
#if __cplusplus
#define EXTERN_C_END }
#else
#define EXTERN_C_END
#endif
#endif // EXTERN_C_START

#if defined(_WIN32) || defined(WIN32)
#define FAPI_IMPORT __declspec(dllimport)
#define FAPI_EXPORT __declspec(dllexport)
#else
#define FAPI_IMPORT __attribute__((visibility("default")))
#define FAPI_EXPORT __attribute__((visibility("default")))
#endif

// By default, FAPI_EXTERN means "export symbol" for jssdk-<engine>, any engine which implemented jssdk must
// give implementation of those APIs exported by `FAPI_EXTERN`. You can also specify FAPI_EXTERN as `FAPI_EXPORT`
// explicitly in jssdk-<engine.h>, as this file did so for you already.
//
// For Addon developer, FAPI_EXTERN means "import symbol" from jssdk-<engine>.
#ifndef FAPI_EXTERN
#define FAPI_EXTERN FAPI_EXPORT
#endif // FAPI_EXTERN

#endif // _jssdk_utils_h__