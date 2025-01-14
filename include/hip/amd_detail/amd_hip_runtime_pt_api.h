/*
Copyright (c) 2022 - Present Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#ifndef HIP_INCLUDE_HIP_HIP_RUNTIME_PT_API_H
#define HIP_INCLUDE_HIP_HIP_RUNTIME_PT_API_H

/// hipStreamPerThread implementation
#if defined(HIP_API_PER_THREAD_DEFAULT_STREAM)
    #define __HIP_STREAM_PER_THREAD
    #define __HIP_API_SPT(api) api ## _spt
#else
    #define __HIP_API_SPT(api) api
#endif

#if defined(__HIP_STREAM_PER_THREAD)
    #define hipMemcpy                     __HIP_API_SPT(hipMemcpy)
    #define hipMemcpyToSymbol             __HIP_API_SPT(hipMemcpyToSymbol)
    #define hipMemcpyFromSymbol           __HIP_API_SPT(hipMemcpyFromSymbol)
    #define hipMemcpy2D                   __HIP_API_SPT(hipMemcpy2D)
    #define hipMemcpy2DToArray            __HIP_API_SPT(hipMemcpy2DToArray)
    #define hipMemcpy2DFromArray          __HIP_API_SPT(hipMemcpy2DFromArray)
    #define hipMemcpy3D                   __HIP_API_SPT(hipMemcpy3D)
    #define hipMemset                     __HIP_API_SPT(hipMemset)
    #define hipMemset2D                   __HIP_API_SPT(hipMemset2D)
    #define hipMemset3D                   __HIP_API_SPT(hipMemset3D)

    #define hipMemcpyAsync              __HIP_API_SPT(hipMemcpyAsync)
    #define hipLaunchKernel             __HIP_API_SPT(hipLaunchKernel)
    #define hipStreamSynchronize        __HIP_API_SPT(hipStreamSynchronize)
#endif

hipError_t hipMemcpy_spt(void* dst, const void* src, size_t sizeBytes, hipMemcpyKind kind);

hipError_t hipMemcpyToSymbol_spt(const void* symbol, const void* src, size_t sizeBytes,
                             size_t offset, hipMemcpyKind kind);

hipError_t hipMemcpyFromSymbol_spt(void* dst, const void* symbol,size_t sizeBytes,
                               size_t offset, hipMemcpyKind kind);

hipError_t hipMemcpy2D_spt(void* dst, size_t dpitch, const void* src, size_t spitch, size_t width,
                        size_t height, hipMemcpyKind kind);

hipError_t hipMemcpy2DToArray_spt(hipArray* dst, size_t wOffset, size_t hOffset, const void* src,
                              size_t spitch, size_t width, size_t height, hipMemcpyKind kind);

hipError_t hipMemcpy2DFromArray_spt( void* dst, size_t dpitch, hipArray_const_t src, size_t wOffset,
                        size_t hOffset, size_t width, size_t height, hipMemcpyKind kind);

hipError_t hipMemcpy3D_spt(const struct hipMemcpy3DParms* p);

hipError_t hipMemset_spt(void* dst, int value, size_t sizeBytes);

hipError_t hipMemset2D_spt(void* dst, size_t pitch, int value, size_t width, size_t height);

hipError_t hipMemset3D_spt(hipPitchedPtr pitchedDevPtr, int  value, hipExtent extent );

hipError_t hipMemcpyAsync_spt(void* dst, const void* src, size_t sizeBytes, hipMemcpyKind kind,
                          hipStream_t stream);
hipError_t hipStreamSynchronize_spt(hipStream_t stream);
hipError_t hipLaunchKernel_spt(const void* function_address,
                           dim3 numBlocks,
                           dim3 dimBlocks,
                           void** args,
                           size_t sharedMemBytes, hipStream_t stream);
#endif //HIP_INCLUDE_HIP_HIP_RUNTIME_PT_API_H