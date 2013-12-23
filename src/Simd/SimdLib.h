/*
* Simd Library.
*
* Copyright (c) 2011-2013 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

/** \file SimdLib.h
* This file contains a Simd Library API functions.
*/

#ifndef __SimdLib_h__
#define __SimdLib_h__

#include "Simd/SimdTypes.h"

#if defined(WIN32) && !defined(SIMD_STATIC)
#  ifdef SIMD_EXPORTS
#    define SIMD_API __declspec(dllexport)
#  else//SIMD_EXPORTS
#    define SIMD_API __declspec(dllimport)
#  endif//SIMD_EXPORTS
#else //WIN32
#    define SIMD_API
#endif//WIN32

#ifdef __cplusplus
extern "C"
{
#endif//__cplusplus

    /**
    * \fn const char * SimdVersion();
    *
    * \short Gets version of Simd Library.
    *
    * \return string with version of Simd Library (major version number, minor version number, release number, number of SVN's commits).
    */
    SIMD_API const char * SimdVersion();

    /**
    * \fn uint32_t SimdCrc32c(const void * src, size_t size);
    *
    * \short Gets 32-bit cyclic redundancy check (CRC32c) for current data.
    *
    * Calculation is performed for for polynomial 0x1EDC6F41 (Castagnoli-crc).
    *
    * \param [in] src - a pointer to data.
    * \param [in] size - a size of the data.
    * \return 32-bit cyclic redundancy check (CRC32c).
    */
    SIMD_API uint32_t SimdCrc32c(const void * src, size_t size);

    /**
    * \fn void SimdAbsDifferenceSum(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride, size_t width, size_t height, uint64_t * sum);
    *
    * \short Gets sum of absolute difference of two gray 8-bit images. 
    *
    * Both images must have the same width and height.
    *
    * \param [in] a - a pointer to pixels data of first image.
    * \param [in] aStride - a row size of first image.
    * \param [in] b - a pointer to pixels data of second image.
    * \param [in] bStride - a row size of second image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] sum - the result sum of absolute difference of two images.
    */
    SIMD_API void SimdAbsDifferenceSum(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride,
        size_t width, size_t height, uint64_t * sum);

    /**
    * \fn void SimdAbsDifferenceSumMasked(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride, const uint8_t * mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum);
    *
    * \short Gets sum of absolute difference of two gray 8-bit images based on gray 8-bit mask. 
    *
    * Gets the absolute difference sum for all points when mask[i] == index.
    * Both images and mask must have the same width and height.
    *
    * \param [in] a - a pointer to pixels data of first image.
    * \param [in] aStride - a row size of first image.
    * \param [in] b - a pointer to pixels data of second image.
    * \param [in] bStride - a row size of second image.
    * \param [in] mask - a pointer to pixels data of mask image.
    * \param [in] maskStride - a row size of mask image.
    * \param [in] index - a mask index.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] sum - the result sum of absolute difference of two images.
    */
    SIMD_API void SimdAbsDifferenceSumMasked(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride,
        const uint8_t * mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum);

    /**
    * \fn void SimdAbsDifferenceSums3x3(const uint8_t * current, size_t currentStride, const uint8_t * background, size_t backgroundStride, size_t width, size_t height, uint64_t * sums);
    *
    * \short Gets 9 sums of absolute difference of two gray 8-bit images with various relative shifts in neighborhood 3x3. 
    *
    * Both images must have the same width and height. The image height and width must be equal or greater 3.
    * The sums are calculated with central part (indent width = 1) of current image and with part of background image with corresponding shift.
    * The shifts are lain in the range [-1, 1] for axis x and y.
    *
    * \param [in] current - a pointer to pixels data of current image.
    * \param [in] currentStride - a row size of the current image.
    * \param [in] background - a pointer to pixels data of the background image.
    * \param [in] backgroundStride - a row size of the background image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] sums - the pointer to buffer with result sums. Buffer size must be equal or greater 9.
    */
    SIMD_API void SimdAbsDifferenceSums3x3(const uint8_t * current, size_t currentStride, const uint8_t * background, size_t backgroundStride,
        size_t width, size_t height, uint64_t * sums);

    /**
    * \fn void SimdAbsDifferenceSums3x3Masked(const uint8_t *current, size_t currentStride, const uint8_t *background, size_t backgroundStride, const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sums);
    *
    * \short Gets 9 sums of absolute difference of two gray 8-bit images with various relative shifts in neighborhood 3x3 based on gray 8-bit mask. 
    *
    * Gets the absolute difference sums for all points when mask[i] == index.
    * Both images and mask must have the same width and height. The image height and width must be equal or greater 3.
    * The sums are calculated with central part (indent width = 1) of current image and with part of background image with corresponding shift.
    * The shifts are lain in the range [-1, 1] for axis x and y.
    *
    * \param [in] current - a pointer to pixels data of current image.
    * \param [in] currentStride - a row size of the current image.
    * \param [in] background - a pointer to pixels data of the background image.
    * \param [in] backgroundStride - a row size of the background image.
    * \param [in] mask - a pointer to pixels data of mask image.
    * \param [in] maskStride - a row size of mask image.
    * \param [in] index - a mask index.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] sums - the pointer to buffer with result sums. Buffer size must be equal or greater 9.
    */
    SIMD_API void SimdAbsDifferenceSums3x3Masked(const uint8_t *current, size_t currentStride, const uint8_t *background, size_t backgroundStride,
        const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sums);

    /**
    * \fn void SimdAbsGradientSaturatedSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride);
    *
    * \short Puts to destination 8-bit gray image saturated sum of absolute gradient for every point of source 8-bit gray image. 
    *
    * Both images must have the same width and height.
    *
    * For border pixels dst[x, y] = 0, for other pixels: 
    * \n dst[x, y] = min(dx[x, y] + dy[x, y], 255), where 
    * \n dx[x, y] = abs(src[x + 1, y] - src[x - 1, y]), 
    * \n dy[x, y] = abs(src[x, y + 1] - src[x, y - 1]).
    *
    * \param [in] src - a pointer to pixels data of source 8-bit gray image.
    * \param [in] srcStride - a row size of source image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] dst - a pointer to pixels data of destination 8-bit gray image.
    * \param [in] dstStride - a row size of destination image.
    */
    SIMD_API void SimdAbsGradientSaturatedSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdAddFeatureDifference(const uint8_t * value, size_t valueStride, size_t width, size_t height, const uint8_t * lo, size_t loStride, const uint8_t * hi, size_t hiStride, uint16_t weight, uint8_t * difference, size_t differenceStride);
    *
    * \short Adds feature difference to common difference sum. 
    *
    * All images must have the same width, height and format (8-bit gray).
    *
    * For every point: 
    * \n difference[i] += (weight * excess[i]*excess[i]) >> 16, 
    * \n where 
    * \n excess[i] = max(lo[i] - value[i], 0) + max(value[i] - hi[i], 0).
    *
    * This function is used for difference estimation in algorithm of motion detection.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] lo - a pointer to pixels data of feature lower bound of dynamic background.
    * \param [in] loStride - a row size of the lo image.
    * \param [in] hi - a pointer to pixels data of feature upper bound of dynamic background.
    * \param [in] hiStride - a row size of the hi image.
    * \param [in] weight - a current feature weight (unsigned 16-bit value).
    * \param [in, out] difference - a pointer to pixels data of image with total difference.
    * \param [in] differenceStride - a row size of difference image.
    */
    SIMD_API void SimdAddFeatureDifference(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        const uint8_t * lo, size_t loStride, const uint8_t * hi, size_t hiStride,
        uint16_t weight, uint8_t * difference, size_t differenceStride);

    /**
    * \fn void SimdAlphaBlending(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, const uint8_t * alpha, size_t alphaStride, uint8_t * dst, size_t dstStride);
    *
    * \short Performs alpha blending operation. 
    *
    * All images must have the same width and height. Source and destination images must have the same format (8 bit per channel, for example GRAY8, BGR24 or BGRA32). Alpha must be 8-bit gray image.
    *
    * For every point: 
    * \n dst[i] = (src[i]*alpha[i] + dst[i]*(255 - alpha[i]))/255.
    *
    * This function is used for image drawing.
    *
    * \param [in] src - a pointer to pixels data of foreground image.
    * \param [in] srcStride - a row size of the foreground image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count for foreground and background images (1 <= channelCount <= 4).
    * \param [in] alpha - a pointer to pixels data of image with alpha channel.
    * \param [in] alphaStride - a row size of the alpha image.
    * \param [in, out] dst - a pointer to pixels data of background image.
    * \param [in] dstStride - a row size of the background image.
    */
    SIMD_API void SimdAlphaBlending(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount,
        const uint8_t * alpha, size_t alphaStride, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdBackgroundGrowRangeSlow(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride);
    *
    * \short Performs background update (initial grow, slow mode). 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point: 
    * \n lo[i] -= value[i] < lo[i] ? 1 : 0; 
    * \n hi[i] += value[i] > hi[i] ? 1 : 0.
    *
    * This function is used for background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] lo - a pointer to pixels data of feature lower bound of dynamic background.
    * \param [in] loStride - a row size of the lo image.
    * \param [in] hi - a pointer to pixels data of feature upper bound of dynamic background.
    * \param [in, out] hiStride - a row size of the hi image.
    */
    SIMD_API void SimdBackgroundGrowRangeSlow(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride);

    /**
    * \fn void SimdBackgroundGrowRangeFast(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride);
    *
    * \short Performs background update (initial grow, fast mode). 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point: 
    * \n lo[i] = value[i] < lo[i] ? value[i] : lo[i]; 
    * \n hi[i] = value[i] > hi[i] ? value[i] : hi[i].
    *
    * This function is used for background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] lo - a pointer to pixels data of feature lower bound of dynamic background.
    * \param [in] loStride - a row size of the lo image.
    * \param [in] hi - a pointer to pixels data of feature upper bound of dynamic background.
    * \param [in, out] hiStride - a row size of the hi image.
    */
    SIMD_API void SimdBackgroundGrowRangeFast(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride);

    /**
    * \fn void SimdBackgroundIncrementCount(const uint8_t * value, size_t valueStride, size_t width, size_t height, const uint8_t * loValue, size_t loValueStride, const uint8_t * hiValue, size_t hiValueStride, uint8_t * loCount, size_t loCountStride, uint8_t * hiCount, size_t hiCountStride);
    *
    * \short Performs collection of background statistic. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * Updates background statistic counters for every point: 
    * \n loCount[i] += (value[i] < loValue[i] && loCount[i] < 255) ? 1 : 0; 
    * \n hiCount[i] += (value[i] > hiValue[i] && hiCount[i] < 255) ? 1 : 0;
    *
    * This function is used for background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] loValue - a pointer to pixels data of value of feature lower bound of dynamic background.
    * \param [in] loValueStride - a row size of the loValue image.
    * \param [in] hiValue - a pointer to pixels data of value of feature upper bound of dynamic background.
    * \param [in] hiValueStride - a row size of the hiValue image.
    * \param [in, out] loCount - a pointer to pixels data of count of feature lower bound of dynamic background.
    * \param [in] loCountStride - a row size of the loCount image.
    * \param [in, out] hiCount - a pointer to pixels data of count of feature upper bound of dynamic background.
    * \param [in] hiCountStride - a row size of the hiCount image.
    */
    SIMD_API void SimdBackgroundIncrementCount(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        const uint8_t * loValue, size_t loValueStride, const uint8_t * hiValue, size_t hiValueStride,
        uint8_t * loCount, size_t loCountStride, uint8_t * hiCount, size_t hiCountStride);

    /**
    * \fn void SimdBackgroundAdjustRange(uint8_t * loCount, size_t loCountStride, size_t width, size_t height, uint8_t * loValue, size_t loValueStride, uint8_t * hiCount, size_t hiCountStride, uint8_t * hiValue, size_t hiValueStride, uint8_t threshold);
    *
    * \short Performs adjustment of background range. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * Adjusts background range for every point: 
    * \n loValue[i] -= (loCount[i] > threshold && loValue[i] > 0) ? 1 : 0;
    * \n loValue[i] += (loCount[i] < threshold && loValue[i] < 255) ? 1 : 0; 
    * \n loCount[i] = 0;
    * \n hiValue[i] += (hiCount[i] > threshold && hiValue[i] < 255) ? 1 : 0;
    * \n hiValue[i] -= (hiCount[i] < threshold && hiValue[i] > 0) ? 1 : 0; 
    * \n hiCount[i] = 0;
    *
    * This function is used for background updating in motion detection algorithm.
    *
    * \param [in, out] loCount - a pointer to pixels data of count of feature lower bound of dynamic background.
    * \param [in] loCountStride - a row size of the loCount image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] hiCount - a pointer to pixels data of count of feature upper bound of dynamic background.
    * \param [in] hiCountStride - a row size of the hiCount image.
    * \param [in, out] loValue - a pointer to pixels data of value of feature lower bound of dynamic background.
    * \param [in] loValueStride - a row size of the loValue image.
    * \param [in, out] hiValue - a pointer to pixels data of value of feature upper bound of dynamic background.
    * \param [in] hiValueStride - a row size of the hiValue image.
    * \param [in] threshold - a count threshold.
    */
    SIMD_API void SimdBackgroundAdjustRange(uint8_t * loCount, size_t loCountStride, size_t width, size_t height,
        uint8_t * loValue, size_t loValueStride, uint8_t * hiCount, size_t hiCountStride,
        uint8_t * hiValue, size_t hiValueStride, uint8_t threshold);

    /**
    * \fn void SimdBackgroundAdjustRangeMasked(uint8_t * loCount, size_t loCountStride, size_t width, size_t height, uint8_t * loValue, size_t loValueStride, uint8_t * hiCount, size_t hiCountStride, uint8_t * hiValue, size_t hiValueStride, uint8_t threshold, const uint8_t * mask, size_t maskStride);
    *
    * \short Performs adjustment of background range with using adjust range mask. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * Adjusts background range for every point when mask[i] != 0 : 
    * \n loValue[i] -= (loCount[i] > threshold && loValue[i] > 0) ? 1 : 0;
    * \n loValue[i] += (loCount[i] < threshold && loValue[i] < 255) ? 1 : 0; 
    * \n loCount[i] = 0;
    * \n hiValue[i] += (hiCount[i] > threshold && hiValue[i] < 255) ? 1 : 0;
    * \n hiValue[i] -= (hiCount[i] < threshold && hiValue[i] > 0) ? 1 : 0; 
    * \n hiCount[i] = 0;
    *
    * This function is used for background updating in motion detection algorithm.
    *
    * \param [in] loCount - a pointer to pixels data of count of feature lower bound of dynamic background.
    * \param [in, out] loCountStride - a row size of the loCount image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] hiCount - a pointer to pixels data of count of feature upper bound of dynamic background.
    * \param [in] hiCountStride - a row size of the hiCount image.
    * \param [in, out] loValue - a pointer to pixels data of value of feature lower bound of dynamic background.
    * \param [in] loValueStride - a row size of the loValue image.
    * \param [in, out] hiValue - a pointer to pixels data of value of feature upper bound of dynamic background.
    * \param [in] hiValueStride - a row size of the hiValue image.
    * \param [in] threshold - a count threshold.
    * \param [in] mask - a pointer to pixels data of adjust range mask.
    * \param [in] maskStride - a row size of the mask image.
    */
    SIMD_API void SimdBackgroundAdjustRangeMasked(uint8_t * loCount, size_t loCountStride, size_t width, size_t height,
        uint8_t * loValue, size_t loValueStride, uint8_t * hiCount, size_t hiCountStride,
        uint8_t * hiValue, size_t hiValueStride, uint8_t threshold, const uint8_t * mask, size_t maskStride);

    /**
    * \fn void SimdBackgroundShiftRange(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride);
    *
    * \short Shifts background range. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point: 
    \verbatim
    if (value[i] > hi[i])
    {
        lo[i] = min(lo[i] + value[i] - hi[i], 0xFF);
        hi[i] = value[i];
    }
    if (lo[i] > value[i])
    {
        lo[i] = value[i];
        hi[i] = max(hi[i] - lo[i] + value[i], 0);
    }
    \endverbatim
    *
    * This function is used for fast background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] lo - a pointer to pixels data of feature lower bound of dynamic background.
    * \param [in] loStride - a row size of the lo image.
    * \param [in] hi - a pointer to pixels data of feature upper bound of dynamic background.
    * \param [in, out] hiStride - a row size of the hi image.
    */
    SIMD_API void SimdBackgroundShiftRange(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride);

    /**
    * \fn void SimdBackgroundShiftRangeMasked(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride, const uint8_t * mask, size_t maskStride);
    *
    * \short Shifts background range with using shift range mask. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point when mask[i] != 0 : 
    \verbatim
    if (value[i] > hi[i])
    {
        lo[i] = min(lo[i] + value[i] - hi[i], 0xFF);
        hi[i] = value[i];
    }
    if (lo[i] > value[i])
    {
        lo[i] = value[i];
        hi[i] = max(hi[i] - lo[i] + value[i], 0);
    }
    \endverbatim
    *
    * This function is used for fast background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] lo - a pointer to pixels data of feature lower bound of dynamic background.
    * \param [in] loStride - a row size of the lo image.
    * \param [in] hi - a pointer to pixels data of feature upper bound of dynamic background.
    * \param [in, out] hiStride - a row size of the hi image.
    * \param [in] mask - a pointer to pixels data of shift range mask.
    * \param [in] maskStride - a row size of the mask image.
    */
    SIMD_API void SimdBackgroundShiftRangeMasked(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride, const uint8_t * mask, size_t maskStride);

    SIMD_API void SimdBackgroundInitMask(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        uint8_t index, uint8_t value, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdBgraToBgr(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * bgr, size_t bgrStride);
    *
    * \short Converts 32-bit BGRA image to 24-bit BGR image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] bgra - a pointer to pixels data of input 32-bit BGRA image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] bgraStride - a row size of the bgra image.
    * \param [out] bgr - a pointer to pixels data of output 24-bit BGR image.
    * \param [in] bgrStride - a row size of the bgr image.
    */
    SIMD_API void SimdBgraToBgr(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * bgr, size_t bgrStride);

    /**
    * \fn void SimdBgraToGray(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * gray, size_t grayStride);
    *
    * \short Converts 32-bit BGRA image to 8-bit gray image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] bgra - a pointer to pixels data of input 32-bit BGRA image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] bgraStride - a row size of the bgra image.
    * \param [out] gray - a pointer to pixels data of output 8-bit gray image.
    * \param [in] grayStride - a row size of the gray image.
    */
    SIMD_API void SimdBgraToGray(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * gray, size_t grayStride);

    /**
    * \fn void SimdBgrToBgra(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * bgra, size_t bgraStride, uint8_t alpha);
    *
    * \short Converts 24-bit BGR image to 32-bit BGRA image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] bgr - a pointer to pixels data of input 24-bit BGR image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] bgrStride - a row size of the bgr image.
    * \param [out] bgra - a pointer to pixels data of output 32-bit BGRA image.
    * \param [in] bgraStride - a row size of the bgra image.
    * \param [in] alpha - a value of alpha channel.
    */
    SIMD_API void SimdBgrToBgra(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * bgra, size_t bgraStride, uint8_t alpha);

    /**
    * \fn void SimdBgr48pToBgra32(const uint8_t * blue, size_t blueStride, size_t width, size_t height, const uint8_t * green, size_t greenStride, const uint8_t * red, size_t redStride, uint8_t * bgra, size_t bgraStride, uint8_t alpha);
    *
    * \short Converts 48-bit planar BGR image to 32-bit BGRA image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] blue - a pointer to pixels data of input 16-bit image with blue color plane.
    * \param [in] blueStride - a row size of the blue image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] green - a pointer to pixels data of input 16-bit image with green color plane.
    * \param [in] greenStride - a row size of the blue image.
    * \param [in] red - a pointer to pixels data of input 16-bit image with red color plane.
    * \param [in] redStride - a row size of the red image.
    * \param [out] bgra - a pointer to pixels data of output 32-bit BGRA image.
    * \param [in] bgraStride - a row size of the bgra image.
    * \param [in] alpha - a value of alpha channel.
    */
    SIMD_API void SimdBgr48pToBgra32(const uint8_t * blue, size_t blueStride, size_t width, size_t height,
        const uint8_t * green, size_t greenStride, const uint8_t * red, size_t redStride, uint8_t * bgra, size_t bgraStride, uint8_t alpha);

    /**
    * \fn void SimdBgrToGray(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * gray, size_t grayStride);
    *
    * \short Converts 24-bit BGR image to 8-bit gray image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] bgr - a pointer to pixels data of input 24-bit BGR image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] bgrStride - a row size of the bgr image.
    * \param [out] gray - a pointer to pixels data of output 8-bit gray image.
    * \param [in] grayStride - a row size of the gray image.
    */
    SIMD_API void SimdBgrToGray(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * gray, size_t grayStride);

    /**
    * \fn void SimdBinarization(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t value, uint8_t positive, uint8_t negative, uint8_t * dst, size_t dstStride, SimdCompareType compareType);
    *
    * \short Performs binarization of 8-bit gray image. 
    *
    * All images must have 8-bit gray format and must have the same width and height.
    *
    * For every point:
    * \n dst[i] = compare(src[i], value) ? positive : negative,
    * \n compare(a, b) depends from compareType (see ::SimdCompareType).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image (first value for compare operation).
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] value - a second value for compare operation.
    * \param [in] positive - a destination value if comparison operation has a positive result.
    * \param [in] negative - a destination value if comparison operation has a negative result.
    * \param [out] dst - a pointer to pixels data of output 8-bit gray binarized image.
    * \param [in] dstStride - a row size of the dst image.
    * \param [in] compareType - a compare operation type (see ::SimdCompareType).
    */
    SIMD_API void SimdBinarization(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        uint8_t value, uint8_t positive, uint8_t negative, uint8_t * dst, size_t dstStride, SimdCompareType compareType);

    /**
    * \fn void SimdAveragingBinarization(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t value, size_t neighborhood, uint8_t threshold, uint8_t positive, uint8_t negative, uint8_t * dst, size_t dstStride, SimdCompareType compareType);
    *
    * \short Performs averaging binarization of 8-bit gray image. 
    *
    * All images must have 8-bit gray format and must have the same width and height.
    *
    * For every point:
    * \n dst[i] = sum[i]*255 > area[i]*threshold ? positive : negative,
    * \n where sum[i] is a sum of positive compare(src[i], value) operation (see ::SimdCompareType) in the point neighborhood (from -neighborhood to neighborhood for x and y),
    * \n area[i] - an area of the point neighborhood ( (2*neighborhood + 1)^2 for central part of the image).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image (first value for compare operation).
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] value - a second value for compare operation.
    * \param [in] neighborhood - an averaging neighborhood.
    * \param [in] threshold - a threshold value for binarization. It can range from 0 to 255.
    * \param [in] positive - a destination value if for neighborhood of this point number of positive comparison is greater then threshold.
    * \param [in] negative - a destination value if for neighborhood of this point number of positive comparison is lesser or equal then threshold.
    * \param [out] dst - a pointer to pixels data of output 8-bit gray binarized image.
    * \param [in] dstStride - a row size of the dst image.
    * \param [in] compareType - a compare operation type (see ::SimdCompareType).
    */
    SIMD_API void SimdAveragingBinarization(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        uint8_t value, size_t neighborhood, uint8_t threshold, uint8_t positive, uint8_t negative,
        uint8_t * dst, size_t dstStride, SimdCompareType compareType);

    /**
    * \fn void SimdConditionalCount(const uint8_t * src, size_t stride, size_t width, size_t height, uint8_t value, SimdCompareType compareType, uint32_t * count);
    *
    * \short Calculates number of points satisfying certain condition for 8-bit gray image. 
    *
    * For every point:
    * \n count += compare(src[i], value) ? 1 : 0,
    * \n compare(a, b) depends from compareType (see ::SimdCompareType).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image (first value for compare operation).
    * \param [in] stride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] value - a second value for compare operation.
    * \param [in] compareType - a compare operation type (see ::SimdCompareType).
    * \param [out] count - a pointer to result unsigned 32-bit value.
    */
    SIMD_API void SimdConditionalCount(const uint8_t * src, size_t stride, size_t width, size_t height, 
        uint8_t value, SimdCompareType compareType, uint32_t * count);

    /**
    * \fn void SimdConditionalSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum);
    *
    * \short Calculates sum of image points when mask points satisfying certain condition. 
    *
    * All images must have 8-bit gray format and must have the same width and height.
    *
    * For every point:
    * \n sum += compare(mask[i], value) ? src[i] : 0,
    * \n compare(a, b) depends from compareType (see ::SimdCompareType).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] mask - a pointer to pixels data of 8-bit gray mask (first value for compare operation).
    * \param [in] maskStride - a row size of the mask image.
    * \param [in] value - a second value for compare operation.
    * \param [in] compareType - a compare operation type (see ::SimdCompareType).
    * \param [out] sum - a pointer to result unsigned 64-bit value.
    */
    SIMD_API void SimdConditionalSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
        const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum);

    /**
    * \fn void SimdConditionalSquareSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum);
    *
    * \short Calculates sum of squared image points when mask points satisfying certain condition. 
    *
    * All images must have 8-bit gray format and must have the same width and height.
    *
    * For every point:
    * \n sum += compare(mask[i], value) ? src[i]*src[i] : 0,
    * \n compare(a, b) depends from compareType (see ::SimdCompareType).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] mask - a pointer to pixels data of 8-bit gray mask (first value for compare operation).
    * \param [in] maskStride - a row size of the mask image.
    * \param [in] value - a second value for compare operation.
    * \param [in] compareType - a compare operation type (see ::SimdCompareType).
    * \param [out] sum - a pointer to result unsigned 64-bit value.
    */
    SIMD_API void SimdConditionalSquareSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
        const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum);

    /**
    * \fn void SimdConditionalSquareGradientSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum);
    *
    * \short Calculates sum of squared gradient of image points when mask points satisfying certain condition. 
    *
    * All images must have 8-bit gray format and must have the same width and height. The image height and width must be equal or greater 3.
    *
    * For every point:
    * \n sum += compare(mask[x, y], value) ? dx[x, y]*dx[x, y] + dy[x, y]*dy[x, y] : 0, 
    * \n where for border pixels dx[x, y] = 0 and dy[x, y] = 0, for other pixels: 
    * \n dx[x, y] = src[x + 1, y] - src[x - 1, y], 
    * \n dy[x, y] = src[x, y + 1] - src[x, y - 1];
    * \n compare(a, b) depends from compareType (see ::SimdCompareType).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] mask - a pointer to pixels data of 8-bit gray mask (first value for compare operation).
    * \param [in] maskStride - a row size of the mask image.
    * \param [in] value - a second value for compare operation.
    * \param [in] compareType - a compare operation type (see ::SimdCompareType).
    * \param [out] sum - a pointer to result unsigned 64-bit value.
    */
    SIMD_API void SimdConditionalSquareGradientSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
        const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum);

    /**
    * \fn void SimdCopy(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t pixelSize, uint8_t * dst, size_t dstStride);
    *
    * \short Copies pixels data of image from source to destination. 
    *
    * All images must have the same width, height and format.
    *
    * \param [in] src - a pointer to pixels data of source image.
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] pixelSize - a size of the image pixel.
    * \param [out] dst - a pointer to pixels data of destination image.
    * \param [in] dstStride - a row size of the dst image.
    */
    SIMD_API void SimdCopy(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t pixelSize, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdCopyFrame(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t pixelSize, size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t * dst, size_t dstStride);
    *
    * \short Copies pixels data of image from source to destination except for the portion bounded frame. 
    *
    * All images must have the same width, height and format.
    *
    * \param [in] src - a pointer to pixels data of source image.
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] pixelSize - a size of the image pixel.
    * \param [in] frameLeft - a frame left side.
    * \param [in] frameTop - a frame top side.
    * \param [in] frameRight - a frame right side.
    * \param [in] frameBottom - a frame bottom side.
    * \param [out] dst - a pointer to pixels data of destination image.
    * \param [in] dstStride - a row size of the dst image.
    */
    SIMD_API void SimdCopyFrame(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t pixelSize,
        size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdDeinterleaveUv(const uint8_t * uv, size_t uvStride, size_t width, size_t height, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride);
    *
    * \short Deinterleaves 16-bit UV interleaved image into separated 8-bit U and V planar images. 
    *
    * All images must have the same width and height.
    * This function used for NV12 to YUV420P conversion.
    *
    * \param [in] uv - a pointer to pixels data of input 16-bit UV interleaved image.
    * \param [in] uvStride - a row size of the uv image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] u - a pointer to pixels data of 8-bit U planar image.
    * \param [in] uStride - a row size of the u image.
    * \param [out] v - a pointer to pixels data of 8-bit V planar image.
    * \param [in] uStride - a row size of the v image.
    */
    SIMD_API void SimdDeinterleaveUv(const uint8_t * uv, size_t uvStride, size_t width, size_t height,
        uint8_t * u, size_t uStride, uint8_t * v, size_t vStride);

    /**
    * \fn void SimdEdgeBackgroundGrowRangeSlow(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * background, size_t backgroundStride);
    *
    * \short Performs edge background update (initial grow, slow mode). 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point: 
    * \n background[i] += value[i] > background[i] ? 1 : 0; 
    *
    * This function is used for edge background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] background - a pointer to pixels data of feature value of edge dynamic background.
    * \param [in] backgroundStride - a row size of the background image.
    */
    SIMD_API void SimdEdgeBackgroundGrowRangeSlow(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * background, size_t backgroundStride);

    /**
    * \fn void SimdEdgeBackgroundGrowRangeFast(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * background, size_t backgroundStride);
    *
    * \short Performs edge background update (initial grow, fast mode). 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point: 
    * \n background[i] = value[i] > background[i] ? value[i] : background[i]; 
    *
    * This function is used for edge background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] background - a pointer to pixels data of feature value of edge dynamic background.
    * \param [in] backgroundStride - a row size of the background image.
    */
    SIMD_API void SimdEdgeBackgroundGrowRangeFast(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * background, size_t backgroundStride);

    /**
    * \fn void SimdEdgeBackgroundIncrementCount(const uint8_t * value, size_t valueStride, size_t width, size_t height, const uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t * backgroundCount, size_t backgroundCountStride);
    *
    * \short Performs collection of edge background statistic. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * Updates background statistic counters for every point: 
    * \n backgroundCount[i] += (value[i] > backgroundValue[i] && backgroundCount[i] < 255) ? 1 : 0;
    *
    * This function is used for edge background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] backgroundValue - a pointer to pixels data of value of feature of edge dynamic background.
    * \param [in] backgroundValueStride - a row size of the backgroundValue image.
    * \param [in, out] backgroundCount - a pointer to pixels data of count of feature of edge dynamic background.
    * \param [in] backgroundCountStride - a row size of the backgroundCount image.
    */
    SIMD_API void SimdEdgeBackgroundIncrementCount(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        const uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t * backgroundCount, size_t backgroundCountStride);

    /**
    * \fn void SimdEdgeBackgroundAdjustRange(uint8_t * backgroundCount, size_t backgroundCountStride, size_t width, size_t height, uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t threshold);
    *
    * \short Performs adjustment of edge background range. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * Adjusts edge background range for every point: 
    * \n backgroundValue[i] += (backgroundCount[i] > threshold && backgroundValue[i] < 255) ? 1 : 0;
    * \n backgroundValue[i] -= (backgroundCount[i] < threshold && backgroundValue[i] > 0) ? 1 : 0; 
    * \n backgroundCount[i] = 0;
    *
    * This function is used for edge background updating in motion detection algorithm.
    *
    * \param [in, out] backgroundCount - a pointer to pixels data of count of feature of edge dynamic background.
    * \param [in] backgroundCountStride - a row size of the backgroundCount image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] backgroundValue - a pointer to pixels data of value of feature of edge dynamic background.
    * \param [in] backgroundValueStride - a row size of the backgroundValue image.
    * \param [in] threshold - a count threshold.
    */
    SIMD_API void SimdEdgeBackgroundAdjustRange(uint8_t * backgroundCount, size_t backgroundCountStride, size_t width, size_t height,
        uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t threshold);

    /**
    * \fn void SimdEdgeBackgroundAdjustRangeMasked(uint8_t * backgroundCount, size_t backgroundCountStride, size_t width, size_t height, uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t threshold, const uint8_t * mask, size_t maskStride);
    *
    * \short Performs adjustment of edge background range with using adjust range mask. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * Adjusts edge background range for every point when mask[i] != 0: 
    * \n backgroundValue[i] += (backgroundCount[i] > threshold && backgroundValue[i] < 255) ? 1 : 0;
    * \n backgroundValue[i] -= (backgroundCount[i] < threshold && backgroundValue[i] > 0) ? 1 : 0; 
    * \n backgroundCount[i] = 0;
    *
    * This function is used for edge background updating in motion detection algorithm.
    *
    * \param [in, out] backgroundCount - a pointer to pixels data of count of feature of edge dynamic background.
    * \param [in] backgroundCountStride - a row size of the backgroundCount image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] backgroundValue - a pointer to pixels data of value of feature of edge dynamic background.
    * \param [in] backgroundValueStride - a row size of the backgroundValue image.
    * \param [in] threshold - a count threshold.
    * \param [in] mask - a pointer to pixels data of adjust range mask.
    * \param [in] maskStride - a row size of the mask image.
    */
    SIMD_API void SimdEdgeBackgroundAdjustRangeMasked(uint8_t * backgroundCount, size_t backgroundCountStride, size_t width, size_t height,
        uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t threshold, const uint8_t * mask, size_t maskStride);

    /**
    * \fn void SimdEdgeBackgroundShiftRange(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * background, size_t backgroundStride);
    *
    * \short Shifts edge background range. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point: 
    * \n background[i] = value[i];
    *
    * This function is used for fast edge background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] background - a pointer to pixels data of feature of edge dynamic background.
    * \param [in] backgroundStride - a row size of the background image.
    */
    SIMD_API void SimdEdgeBackgroundShiftRange(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * background, size_t backgroundStride);

    /**
    * \fn void SimdEdgeBackgroundShiftRangeMasked(const uint8_t * value, size_t valueStride, size_t width, size_t height, uint8_t * background, size_t backgroundStride, const uint8_t * mask, size_t maskStride);
    *
    * \short Shifts edge background range with using shift range mask. 
    *
    * All images must have the same width, height and format (8-bit gray). 
    *
    * For every point when mask[i] != 0 : 
    * \n background[i] = value[i];
    *
    * This function is used for fast edge background updating in motion detection algorithm.
    *
    * \param [in] value - a pointer to pixels data of current feature value.
    * \param [in] valueStride - a row size of the value image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in, out] background - a pointer to pixels data of feature of edge dynamic background.
    * \param [in] backgroundStride - a row size of the background image.
    * \param [in] mask - a pointer to pixels data of shift range mask.
    * \param [in] maskStride - a row size of the mask image.
    */
    SIMD_API void SimdEdgeBackgroundShiftRangeMasked(const uint8_t * value, size_t valueStride, size_t width, size_t height,
        uint8_t * background, size_t backgroundStride, const uint8_t * mask, size_t maskStride);

    /**
    * \fn void SimdFill(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uint8_t value);
    *
    * \short Fills pixels data of image by given value. 
    *
    * \param [out] dst - a pointer to pixels data of destination image.
    * \param [in] stride - a row size of the dst image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] pixelSize - a size of the image pixel.
    * \param [in] value - a value to fill image.
    */
    SIMD_API void SimdFill(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uint8_t value);

    /**
    * \fn void SimdFillFrame(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize, size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t value);
    *
    * \short Fills pixels data of image except for the portion bounded frame by given value. 
    *
    * \param [out] dst - a pointer to pixels data of destination image.
    * \param [in] stride - a row size of the dst image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] pixelSize - a size of the image pixel.
    * \param [in] frameLeft - a frame left side.
    * \param [in] frameTop - a frame top side.
    * \param [in] frameRight - a frame right side.
    * \param [in] frameBottom - a frame bottom side.
    * \param [in] value - a value to fill image.
    */
    SIMD_API void SimdFillFrame(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize,
        size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t value);

    /**
    * \fn void SimdFillBgra(uint8_t * dst, size_t stride, size_t width, size_t height, uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha);
    *
    * \short Fills pixels data of 32-bit BGRA image by given color(blue, green, red, alpha). 
    *
    * \param [out] dst - a pointer to pixels data of destination image.
    * \param [in] stride - a row size of the dst image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] blue - a blue channel of BGRA to fill image.
    * \param [in] green - a green channel of BGRA to fill image.
    * \param [in] red - a red channel of BGRA to fill image.
    * \param [in] alpha - a alpha channel of BGRA to fill image.
    */
    SIMD_API void SimdFillBgra(uint8_t * dst, size_t stride, size_t width, size_t height,
        uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha);

    /**
    * \fn void SimdGaussianBlur3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride);
    *
    * \short Performs Gaussian blur filtration with window 3x3. 
    *
    * For every point:
    * \n dst[x, y] = (src[x-1, y-1] + 2*src[x, y-1] + src[x+1, y-1] + 
    * \n 2*(src[x-1, y] + 2*src[x, y] + src[x+1, y]) +
    * \n src[x-1, y+1] + 2*src[x, y+1] + src[x+1, y+1] + 8) / 16; 
    *
    * All images must have the same width, height and format (8-bit gray, 24-bit BGR or 32-bit BGRA).
    *
    * \param [in] src - a pointer to pixels data of source image.
    * \param [in] srcStride - a row size of the src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count.
    * \param [out] dst - a pointer to pixels data of destination image.
    * \param [in] dstStride - a row size of the dst image.
    */
    SIMD_API void SimdGaussianBlur3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        size_t channelCount, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdGrayToBgra(const uint8_t * gray, size_t width, size_t height, size_t grayStride, uint8_t * bgra, size_t bgraStride);
    *
    * \short Converts 8-bit gray image to 32-bit BGRA image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] gray - a pointer to pixels data of input 8-bit gray image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] grayStride - a row size of the gray image.
    * \param [out] bgra - a pointer to pixels data of output 32-bit BGRA image.
    * \param [in] bgraStride - a row size of the bgra image.
    */
    SIMD_API void SimdGrayToBgra(const uint8_t *gray, size_t width, size_t height, size_t grayStride,
        uint8_t *bgra, size_t bgraStride, uint8_t alpha);

    /**
    * \fn void SimdAbsSecondDerivativeHistogram(const uint8_t * src, size_t width, size_t height, size_t stride, size_t step, size_t indent, uint32_t * histogram);
    *
    * \short Calculates histogram of second derivative for 8-bit gray image. 
    *
    * For all points except the boundary (defined by parameter indent): 
    * \n histogram[max(dx, dy)]++, where
    * \n dx = abs(src[x, y] - average(src[x+step, y], src[x-step, y])),
    * \n dy = abs(src[x, y] - average(src[x, y+step], src[x, y-step])).
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] stride - a row size of the image.
    * \param [in] step - a step for second derivative calculation.
    * \param [in] indent - a indent from image boundary.
    * \param [out] histogram - a pointer to histogram (array of 256 unsigned 32-bit values).
    */
    SIMD_API void SimdAbsSecondDerivativeHistogram(const uint8_t * src, size_t width, size_t height, size_t stride,
        size_t step, size_t indent, uint32_t * histogram);

    /**
    * \fn void SimdHistogram(const uint8_t * src, size_t width, size_t height, size_t stride, uint32_t * histogram);
    *
    * \short Calculates histogram for 8-bit gray image. 
    *
    * For all points: 
    * \n histogram[src(i)]++.
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] stride - a row size of the image.
    * \param [out] histogram - a pointer to histogram (array of 256 unsigned 32-bit values).
    */
    SIMD_API void SimdHistogram(const uint8_t * src, size_t width, size_t height, size_t stride, uint32_t * histogram);

    /**
    * \fn void SimdIntegralSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * sum, size_t sumStride);
    *
    * \short Calculates integral sum image for 8-bit gray image. 
    *
    * A sum image must has width and height per unit greater than that of the input image. 
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] sum - a pointer to pixels data of sum 32-bit unsigned int image.
    * \param [in] sumStride - a row size of sum image (in bytes).
    */
    SIMD_API void SimdIntegralSum(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * sum, size_t sumStride);

    /**
    * \fn void SimdLbpEstimate(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride);
    *
    * \short Calculates LBP (Local Binary Patterns) for 8-bit gray image. 
    *
    * All images must have the same width and height. 
    *
    * \param [in] src - a pointer to pixels data of input 8-bit gray image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [out] dst - a pointer to pixels data of output 8-bit gray image with LBP.
    * \param [in] dstStride - a row size of dst image.
    */
    SIMD_API void SimdLbpEstimate(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdMedianFilterRhomb3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride);
    *
    * \short Performs median filtration of input image (filter window is a rhomb 3x3). 
    *
    * All images must have the same width, height and format (8-bit gray, 24-bit BGR or 32-bit BGRA). 
    *
    * \param [in] src - a pointer to pixels data of original input image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count.
    * \param [out] dst - a pointer to pixels data of filtered output image.
    * \param [in] dstStride - a row size of dst image.
    */
    SIMD_API void SimdMedianFilterRhomb3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        size_t channelCount, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdMedianFilterRhomb5x5(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride);
    *
    * \short Performs median filtration of input image (filter window is a rhomb 5x5). 
    *
    * All images must have the same width, height and format (8-bit gray, 24-bit BGR or 32-bit BGRA). 
    *
    * \param [in] src - a pointer to pixels data of original input image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count.
    * \param [out] dst - a pointer to pixels data of filtered output image.
    * \param [in] dstStride - a row size of dst image.
    */
    SIMD_API void SimdMedianFilterRhomb5x5(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        size_t channelCount, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdMedianFilterSquare3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride);
    *
    * \short Performs median filtration of input image (filter window is a square 3x3). 
    *
    * All images must have the same width, height and format (8-bit gray, 24-bit BGR or 32-bit BGRA). 
    *
    * \param [in] src - a pointer to pixels data of original input image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count.
    * \param [out] dst - a pointer to pixels data of filtered output image.
    * \param [in] dstStride - a row size of dst image.
    */
    SIMD_API void SimdMedianFilterSquare3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        size_t channelCount, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdMedianFilterSquare5x5(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride);
    *
    * \short Performs median filtration of input image (filter window is a square 5x5). 
    *
    * All images must have the same width, height and format (8-bit gray, 24-bit BGR or 32-bit BGRA). 
    *
    * \param [in] src - a pointer to pixels data of original input image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count.
    * \param [out] dst - a pointer to pixels data of filtered output image.
    * \param [in] dstStride - a row size of dst image.
    */
    SIMD_API void SimdMedianFilterSquare5x5(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        size_t channelCount, uint8_t * dst, size_t dstStride);

    /**
    * \fn void SimdOperation(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride, SimdOperationType type);
    *
    * \short Performs given operation between two images. 
    *
    * All images must have the same width, height and format (8-bit gray, 24-bit BGR or 32-bit BGRA). 
    *
    * \param [in] src - a pointer to pixels data of original input image.
    * \param [in] srcStride - a row size of src image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    * \param [in] channelCount - a channel count.
    * \param [out] dst - a pointer to pixels data of filtered output image.
    * \param [in] dstStride - a row size of dst image.
    * \param [in] type - a type of operation (see ::SimdOperationType).
    */
    SIMD_API void SimdOperation(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride,
        size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride, SimdOperationType type);

    /**
    * \fn void SimdVectorProduct(const uint8_t * vertical, const uint8_t * horizontal, uint8_t * dst, size_t stride, size_t width, size_t height);
    *
    * \short Calculates result 8-bit gray image as product of two vectors. 
    *
    * For all points: 
    * \n dst[x, y] = horizontal[x]*vertical[y]/255.
    *
    * \param [in] vertical - a pointer to pixels data of vertical vector. It length is equal to result image height.
    * \param [in] horizontal - a pointer to pixels data of horizontal vector. It length is equal to result image width.
    * \param [out] dst - a pointer to pixels data of result image.
    * \param [in] stride - a row size of dst image.
    * \param [in] width - an image width.
    * \param [in] height - an image height.
    */
    SIMD_API void SimdVectorProduct(const uint8_t * vertical, const uint8_t * horizontal,
        uint8_t * dst, size_t stride, size_t width, size_t height);

    /**
    * \fn void SimdReduceGray2x2(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride, uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride);
    *
    * \short Performs reducing and Gaussian blurring (in two time) a 8-bit gray image with using window 2x2. 
    *
    * For input and output image must be performed: dstWidth = (srcWidth + 1)/2,  dstHeight = (srcHeight + 1)/2.
    *
    * For all points: 
    * \n dst[x, y] = (src[2*x, 2*y] + src[2*x, 2*y + 1] + src[2*x + 1, 2*y] + src[2*x + 1, 2*y + 1] + 2)/4.
    *
    * \param [in] src - a pointer to pixels data of the original input image.
    * \param [in] srcWidth - a width of the input image.
    * \param [in] srcHeight - a height of the input image.
    * \param [in] srcStride - a row size of the input image.
    * \param [out] dst - a pointer to pixels data of the reduced output image.
    * \param [in] dstWidth - a width of the output image.
    * \param [in] dstHeight - a height of the output image.
    * \param [in] dstStride - a row size of the output image.
    */
    SIMD_API void SimdReduceGray2x2(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride,
        uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride);

    /**
    * \fn void SimdReduceGray3x3(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride, uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride, bool compensation);
    *
    * \short Performs reducing and Gaussian blurring (in two time) a 8-bit gray image with using window 3x3. 
    *
    * For input and output image must be performed: dstWidth = (srcWidth + 1)/2,  dstHeight = (srcHeight + 1)/2.
    *
    * For every point:
    * \n dst[x, y] = (src[2*x-1, 2*y-1] + 2*src[2*x, 2*y-1] + src[2*x+1, 2*y-1] + 
    * \n 2*(src[2*x-1, 2*y] + 2*src[2*x, 2*y] + src[2*x+1, 2*y]) +
    * \n src[2*x-1, 2*y+1] + 2*src[2*x, 2*y+1] + src[2*x+1, 2*y+1] + compensation ? 8 : 0) / 16; 
    *
    * \param [in] src - a pointer to pixels data of the original input image.
    * \param [in] srcWidth - a width of the input image.
    * \param [in] srcHeight - a height of the input image.
    * \param [in] srcStride - a row size of the input image.
    * \param [out] dst - a pointer to pixels data of the reduced output image.
    * \param [in] dstWidth - a width of the output image.
    * \param [in] dstHeight - a height of the output image.
    * \param [in] dstStride - a row size of the output image.
    * \param [in] compensation - a flag of compensation of rounding.
    */
    SIMD_API void SimdReduceGray3x3(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride,
        uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride, bool compensation);

    /**
    * \fn void SimdReduceGray4x4(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride, uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride);
    *
    * \short Performs reducing and Gaussian blurring (in two time) a 8-bit gray image with using window 4x4. 
    *
    * For input and output image must be performed: dstWidth = (srcWidth + 1)/2,  dstHeight = (srcHeight + 1)/2.
    *
    * For every point:
    * \n dst[x, y] = (src[2*x-1, 2*y-1] + 3*src[2*x, 2*y-1] + 3*src[2*x+1, 2*y-1] + src[2*x+2, 2*y-1]
    * \n 3*(src[2*x-1, 2*y] + 3*src[2*x, 2*y] + 3*src[2*x+1, 2*y] + src[2*x+2, 2*y]) +
    * \n 3*(src[2*x-1, 2*y+1] + 3*src[2*x, 2*y+1] + 3*src[2*x+1, 2*y+1] + src[2*x+2, 2*y+1]) +
    * \n src[2*x-1, 2*y+2] + 3*src[2*x, 2*y+2] + 3*src[2*x+1, 2*y+2] + src[2*x+2, 2*y+2] + 32) / 64; 
    *
    * \param [in] src - a pointer to pixels data of the original input image.
    * \param [in] srcWidth - a width of the input image.
    * \param [in] srcHeight - a height of the input image.
    * \param [in] srcStride - a row size of the input image.
    * \param [out] dst - a pointer to pixels data of the reduced output image.
    * \param [in] dstWidth - a width of the output image.
    * \param [in] dstHeight - a height of the output image.
    * \param [in] dstStride - a row size of the output image.
    */
    SIMD_API void SimdReduceGray4x4(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride,
        uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride);

    /**
    * \fn void SimdReduceGray5x5(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride, uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride, bool compensation);
    *
    * \short Performs reducing and Gaussian blurring (in two time) a 8-bit gray image with using window 5x5. 
    *
    * For input and output image must be performed: dstWidth = (srcWidth + 1)/2,  dstHeight = (srcHeight + 1)/2.
    *
    * For every point:
    * \n dst[x, y] = (src[2*x-2, 2*y-2] + 4*src[2*x-1, 2*y-2] + 6*src[2*x, 2*y-2] + 4*src[2*x+1, 2*y-2] + src[2*x+2, 2*y-2] +
    * \n 4*(src[2*x-2, 2*y-1] + 4*src[2*x-1, 2*y-1] + 6*src[2*x, 2*y-1] + 4*src[2*x+1, 2*y-1] + src[2*x+2, 2*y-1]) +
    * \n 6*(src[2*x-2, 2*y] + 4*src[2*x-1, 2*y] + 6*src[2*x, 2*y] + 4*src[2*x+1, 2*y] + src[2*x+2, 2*y]) +
    * \n 4*(src[2*x-2, 2*y+1] + 4*src[2*x-1, 2*y+1] + 6*src[2*x, 2*y+1] + 4*src[2*x+1, 2*y+1] + src[2*x+2, 2*y+1]) +
    * \n src[2*x-2, 2*y+2] + 4*src[2*x-1, 2*y+2] + 6*src[2*x, 2*y+2] + 4*src[2*x+1, 2*y+2] + src[2*x+2, 2*y+2] + compensation ? 128 : 0) / 256; 
    *
    * \param [in] src - a pointer to pixels data of the original input image.
    * \param [in] srcWidth - a width of the input image.
    * \param [in] srcHeight - a height of the input image.
    * \param [in] srcStride - a row size of the input image.
    * \param [out] dst - a pointer to pixels data of the reduced output image.
    * \param [in] dstWidth - a width of the output image.
    * \param [in] dstHeight - a height of the output image.
    * \param [in] dstStride - a row size of the output image.
    * \param [in] compensation - a flag of compensation of rounding.
    */
    SIMD_API void SimdReduceGray5x5(const uint8_t * src, size_t srcWidth, size_t srcHeight, size_t srcStride,
        uint8_t * dst, size_t dstWidth, size_t dstHeight, size_t dstStride, bool compensation);

    /**
    * \fn void SimdResizeBilinear(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride, uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride, size_t channelCount);
    *
    * \short Performs resizing of input image with using bilinear interpolation. 
    *
    * All images must have the same format (8-bit gray, 24-bit BGR or 32-bit BGRA). 
    *
    * \param [in] src - a pointer to pixels data of the original input image.
    * \param [in] srcWidth - a width of the input image.
    * \param [in] srcHeight - a height of the input image.
    * \param [in] srcStride - a row size of the input image.
    * \param [out] dst - a pointer to pixels data of the reduced output image.
    * \param [in] dstWidth - a width of the output image.
    * \param [in] dstHeight - a height of the output image.
    * \param [in] dstStride - a row size of the output image.
    * \param [in] channelCount - a channel count.
    */
    SIMD_API void SimdResizeBilinear(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
        uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride, size_t channelCount);

    SIMD_API void SimdShiftBilinear(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount,
        const uint8_t * bkg, size_t bkgStride, double shiftX, double shiftY,
        size_t cropLeft, size_t cropTop, size_t cropRight, size_t cropBottom, uint8_t * dst, size_t dstStride);

    SIMD_API void SimdSobelDx(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride);

    SIMD_API void SimdSobelDy(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride);

    SIMD_API void SimdSquaredDifferenceSum(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
        size_t width, size_t height, uint64_t * sum);

    SIMD_API void SimdSquaredDifferenceSumMasked(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
        const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum);

    SIMD_API void SimdGetStatistic(const uint8_t * src, size_t stride, size_t width, size_t height,
        uint8_t * min, uint8_t * max, uint8_t * average);

    SIMD_API void SimdGetMoments(const uint8_t * mask, size_t stride, size_t width, size_t height, uint8_t index,
        uint64_t * area, uint64_t * x, uint64_t * y, uint64_t * xx, uint64_t * xy, uint64_t * yy);

    SIMD_API void SimdGetRowSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums);

    SIMD_API void SimdGetColSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums);

    SIMD_API void SimdGetAbsDyRowSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums);

    SIMD_API void SimdGetAbsDxColSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums);

    SIMD_API void SimdStretchGray2x2(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
        uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride);

    SIMD_API void SimdTextureBoostedSaturatedGradient(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        uint8_t saturation, uint8_t boost, uint8_t * dx, size_t dxStride, uint8_t * dy, size_t dyStride);

    SIMD_API void SimdTextureBoostedUv(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        uint8_t boost, uint8_t * dst, size_t dstStride);

    SIMD_API void SimdTextureGetDifferenceSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        const uint8_t * lo, size_t loStride, const uint8_t * hi, size_t hiStride, int64_t * sum);

    SIMD_API void SimdTexturePerformCompensation(const uint8_t * src, size_t srcStride, size_t width, size_t height,
        int32_t shift, uint8_t * dst, size_t dstStride);

    SIMD_API void SimdYuv420ToBgr(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
        size_t width, size_t height, uint8_t * bgr, size_t bgrStride);

    SIMD_API void SimdYuv444ToBgr(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
        size_t width, size_t height, uint8_t * bgr, size_t bgrStride);

    SIMD_API void SimdYuv420ToBgra(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
        size_t width, size_t height, uint8_t * bgra, size_t bgraStride, uint8_t alpha);

    SIMD_API void SimdYuv444ToBgra(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
        size_t width, size_t height, uint8_t * bgra, size_t bgraStride, uint8_t alpha);

    SIMD_API void SimdYuv420ToHue(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
        size_t width, size_t height, uint8_t * hue, size_t hueStride);

    SIMD_API void SimdYuv444ToHue(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
        size_t width, size_t height, uint8_t * hue, size_t hueStride);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif//__SimdLib_h__