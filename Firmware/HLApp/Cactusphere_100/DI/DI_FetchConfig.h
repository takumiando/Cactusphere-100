/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Atmark Techno, Inc.
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _DI_FETCH_CONFIG_H_
#define _DI_FETCH_CONFIG_H_

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef CONTAINERS_VECTOR_H
#include <vector.h>
#endif

typedef struct DI_FetchConfig	DI_FetchConfig;
typedef struct _json_value	json_value;

#ifndef NUM_DI
#define NUM_DI 4
#endif

// Initialization and cleanup
extern DI_FetchConfig*	DI_FetchConfig_New(void);
extern void	DI_FetchConfig_Destroy(DI_FetchConfig* me);

// Load DI pulse conter configuration from JSON
extern bool	DI_FetchConfig_LoadFromJSON(DI_FetchConfig* me,
    const json_value* json, bool desire, vector propertyItem, const char* version);

// Get configuration of DI pulse conters
extern vector	DI_FetchConfig_GetFetchItems(DI_FetchConfig* me);
extern vector	DI_FetchConfig_GetFetchItemPtrs(DI_FetchConfig* me);

// Get enable port number of DI pulse counter
extern int DI_FetchConfig_GetFetchEnablePorts(DI_FetchConfig* me,
    bool* counterStatus, bool* pollingStatus);

#endif  // _DI_FETCH_CONFIG_H_
