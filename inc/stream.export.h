#ifndef STREAM_EXPORT_H
#define STREAM_EXPORT_H


#ifdef WIN
#ifdef  STREAM_EXPORTS
#define STREAM_EXPORT __declspec(dllexport)
#else
#define STREAM_EXPORT __declspec(dllimport)
#endif
#else
#define STREAM_EXPORT __attribute__((visibility("default")))
#endif
#endif