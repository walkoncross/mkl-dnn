/*******************************************************************************
* Copyright 2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _INPUT_CONV_HPP
#define _INPUT_CONV_HPP

#include "conv/conv.hpp"

static conv::desc_t default_list[] = {
#if 0
    { 2, 2,  4,  1,  1, 16,  1,  1, 1, 1, 1, 1, 0, 0, "\"test\"" },
    { 2, 2,  4,  1,  1, 32,  1,  1, 1, 1, 1, 1, 0, 0, "\"test\"" },
    { 2, 2,  8,  1,  1, 16,  1,  1, 1, 1, 1, 1, 0, 0, "\"test\"" },

    /* +pad */
    { 1, 2, 16, 13, 13, 16, 13, 13, 1, 1, 1, 1, 0, 0, "\"test\"" },
    { 1, 2, 16, 13, 13, 64, 13, 13, 3, 3, 1, 1, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64, 13, 13, 3, 3, 1, 1, 1, 1, "\"test\"" },
    { 1, 2,  8, 13, 13, 64, 13, 13, 3, 3, 1, 1, 1, 1, "\"test\"" },
    { 1, 2, 32, 13, 13, 64, 13, 13, 3, 3, 1, 1, 1, 1, "\"test\"" },
    { 2, 2,  8,  1, 13, 32,  1, 13, 1, 1, 1, 1, 0, 0, "\"test\"" },
    { 2, 2, 64, 13, 13, 96, 13, 13, 3, 3, 1, 1, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64, 13, 13, 5, 5, 1, 1, 2, 2, "\"test\"" },

    /* -pad */
    { 1, 2, 16, 13, 13, 16, 11, 11, 3, 3, 1, 1, 0, 0, "\"test\"" },
    { 1, 2,  4, 13, 13, 64, 11, 11, 3, 3, 1, 1, 0, 0, "\"test\"" },
    { 1, 2,  8, 13, 13, 64, 11, 11, 3, 3, 1, 1, 0, 0, "\"test\"" },
    { 1, 2, 32, 13, 13, 64, 11, 11, 3, 3, 1, 1, 0, 0, "\"test\"" },
    { 2, 2, 64, 13, 13, 96, 11, 11, 3, 3, 1, 1, 0, 0, "\"test\"" },
    { 1, 2,  4, 13, 13, 64, 11, 11, 5, 5, 1, 1, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  9,  9, 5, 5, 1, 1, 0, 0, "\"test\"" },

    /* +strides, +pad */
    { 1, 2, 16, 13, 13, 16,  7,  7, 1, 1, 2, 2, 0, 0, "\"test\"" },
    { 1, 2, 16, 13, 13, 64,  7,  7, 3, 3, 2, 2, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  7,  7, 3, 3, 2, 2, 1, 1, "\"test\"" },
    { 1, 2,  8, 13, 13, 64,  7,  7, 3, 3, 2, 2, 1, 1, "\"test\"" },
    { 1, 2, 32, 13, 13, 64,  7,  7, 3, 3, 2, 2, 1, 1, "\"test\"" },
    { 2, 2,  8,  1, 13, 32,  1,  7, 1, 1, 2, 2, 0, 0, "\"test\"" },
    { 2, 2, 64, 13, 13, 96,  7,  7, 3, 3, 2, 2, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  6,  6, 5, 5, 2, 2, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  7,  7, 5, 5, 2, 2, 2, 2, "\"test\"" },

    /* +strides, -pad */
    { 1, 2, 16, 13, 13, 16,  6,  6, 3, 3, 2, 2, 0, 0, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  6,  6, 3, 3, 2, 2, 0, 0, "\"test\"" },
    { 1, 2,  8, 13, 13, 64,  6,  6, 3, 3, 2, 2, 0, 0, "\"test\"" },
    { 1, 2, 32, 13, 13, 64,  6,  6, 3, 3, 2, 2, 0, 0, "\"test\"" },
    { 2, 2, 64, 13, 13, 96,  6,  6, 3, 3, 2, 2, 0, 0, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  6,  6, 5, 5, 2, 2, 1, 1, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  5,  5, 5, 5, 2, 2, 0, 0, "\"test\"" },
    { 1, 2,  4, 13, 13, 64,  6,  6, 5, 5, 2, 2, 1, 1, "\"test\"" },
#endif

    // Topology: alexnet
    {1, 256,    3,  227,  227,   96,   55,   55,  11,  11,   4,   4,   0,   0, "\"alexnet:conv1\""},
    {2, 256,   96,   27,   27,  256,   27,   27,   5,   5,   1,   1,   2,   2, "\"alexnet:conv2\""},
    {1, 256,  256,   13,   13,  384,   13,   13,   3,   3,   1,   1,   1,   1, "\"alexnet:conv3\""},
    {2, 256,  384,   13,   13,  384,   13,   13,   3,   3,   1,   1,   1,   1, "\"alexnet:conv4\""},
    {2, 256,  384,   13,   13,  256,   13,   13,   3,   3,   1,   1,   1,   1, "\"alexnet:conv5\""},

    // Topology: vgg_19
    {1,  64,    3,  224,  224,   64,  224,  224,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv1_1\""},
    {1,  64,   64,  224,  224,   64,  224,  224,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv1_2\""},
    {1,  64,   64,  112,  112,  128,  112,  112,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv2_1\""},
    {1,  64,  128,  112,  112,  128,  112,  112,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv2_2\""},
    {1,  64,  128,   56,   56,  256,   56,   56,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv3_1\""},
    {1,  64,  256,   56,   56,  256,   56,   56,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv3_2\""},
    {1,  64,  256,   56,   56,  256,   56,   56,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv3_3\""},
    {1,  64,  256,   56,   56,  256,   56,   56,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv3_4\""},
    {1,  64,  256,   28,   28,  512,   28,   28,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv4_1\""},
    {1,  64,  512,   28,   28,  512,   28,   28,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv4_2\""},
    {1,  64,  512,   28,   28,  512,   28,   28,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv4_3\""},
    {1,  64,  512,   28,   28,  512,   28,   28,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv4_4\""},
    {1,  64,  512,   14,   14,  512,   14,   14,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv5_1\""},
    {1,  64,  512,   14,   14,  512,   14,   14,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv5_2\""},
    {1,  64,  512,   14,   14,  512,   14,   14,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv5_3\""},
    {1,  64,  512,   14,   14,  512,   14,   14,   3,   3,   1,   1,   1,   1, "\"vgg_19:conv5_4\""},

    // Topology: resnet_50
    {1,  50,    3,  224,  224,   64,  112,  112,   7,   7,   2,   2,   3,   3, "\"resnet_50:conv1\""},
    {1,  50,   64,   56,   56,  256,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2a_branch1\""},
    {1,  50,   64,   56,   56,   64,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2a_branch2a\""},
    {1,  50,   64,   56,   56,   64,   56,   56,   3,   3,   1,   1,   1,   1, "\"resnet_50:res2a_branch2b\""},
    {1,  50,   64,   56,   56,  256,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2a_branch2c\""},
    {1,  50,  256,   56,   56,   64,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2b_branch2a\""},
    {1,  50,   64,   56,   56,   64,   56,   56,   3,   3,   1,   1,   1,   1, "\"resnet_50:res2b_branch2b\""},
    {1,  50,   64,   56,   56,  256,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2b_branch2c\""},
    {1,  50,  256,   56,   56,   64,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2c_branch2a\""},
    {1,  50,   64,   56,   56,   64,   56,   56,   3,   3,   1,   1,   1,   1, "\"resnet_50:res2c_branch2b\""},
    {1,  50,   64,   56,   56,  256,   56,   56,   1,   1,   1,   1,   0,   0, "\"resnet_50:res2c_branch2c\""},
    {1,  50,  256,   56,   56,  512,   28,   28,   1,   1,   2,   2,   0,   0, "\"resnet_50:res3a_branch1\""},
    {1,  50,  256,   56,   56,  128,   28,   28,   1,   1,   2,   2,   0,   0, "\"resnet_50:res3a_branch2a\""},
    {1,  50,  128,   28,   28,  128,   28,   28,   3,   3,   1,   1,   1,   1, "\"resnet_50:res3a_branch2b\""},
    {1,  50,  128,   28,   28,  512,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3a_branch2c\""},
    {1,  50,  512,   28,   28,  128,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3b_branch2a\""},
    {1,  50,  128,   28,   28,  128,   28,   28,   3,   3,   1,   1,   1,   1, "\"resnet_50:res3b_branch2b\""},
    {1,  50,  128,   28,   28,  512,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3b_branch2c\""},
    {1,  50,  512,   28,   28,  128,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3c_branch2a\""},
    {1,  50,  128,   28,   28,  128,   28,   28,   3,   3,   1,   1,   1,   1, "\"resnet_50:res3c_branch2b\""},
    {1,  50,  128,   28,   28,  512,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3c_branch2c\""},
    {1,  50,  512,   28,   28,  128,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3d_branch2a\""},
    {1,  50,  128,   28,   28,  128,   28,   28,   3,   3,   1,   1,   1,   1, "\"resnet_50:res3d_branch2b\""},
    {1,  50,  128,   28,   28,  512,   28,   28,   1,   1,   1,   1,   0,   0, "\"resnet_50:res3d_branch2c\""},
    {1,  50,  512,   28,   28, 1024,   14,   14,   1,   1,   2,   2,   0,   0, "\"resnet_50:res4a_branch1\""},
    {1,  50,  512,   28,   28,  256,   14,   14,   1,   1,   2,   2,   0,   0, "\"resnet_50:res4a_branch2a\""},
    {1,  50,  256,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"resnet_50:res4a_branch2b\""},
    {1,  50,  256,   14,   14, 1024,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4a_branch2c\""},
    {1,  50, 1024,   14,   14,  256,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4b_branch2a\""},
    {1,  50,  256,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"resnet_50:res4b_branch2b\""},
    {1,  50,  256,   14,   14, 1024,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4b_branch2c\""},
    {1,  50, 1024,   14,   14,  256,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4c_branch2a\""},
    {1,  50,  256,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"resnet_50:res4c_branch2b\""},
    {1,  50,  256,   14,   14, 1024,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4c_branch2c\""},
    {1,  50, 1024,   14,   14,  256,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4d_branch2a\""},
    {1,  50,  256,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"resnet_50:res4d_branch2b\""},
    {1,  50,  256,   14,   14, 1024,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4d_branch2c\""},
    {1,  50, 1024,   14,   14,  256,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4e_branch2a\""},
    {1,  50,  256,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"resnet_50:res4e_branch2b\""},
    {1,  50,  256,   14,   14, 1024,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4e_branch2c\""},
    {1,  50, 1024,   14,   14,  256,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4f_branch2a\""},
    {1,  50,  256,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"resnet_50:res4f_branch2b\""},
    {1,  50,  256,   14,   14, 1024,   14,   14,   1,   1,   1,   1,   0,   0, "\"resnet_50:res4f_branch2c\""},
    {1,  50, 1024,   14,   14, 2048,    7,    7,   1,   1,   2,   2,   0,   0, "\"resnet_50:res5a_branch1\""},
    {1,  50, 1024,   14,   14,  512,    7,    7,   1,   1,   2,   2,   0,   0, "\"resnet_50:res5a_branch2a\""},
    {1,  50,  512,    7,    7,  512,    7,    7,   3,   3,   1,   1,   1,   1, "\"resnet_50:res5a_branch2b\""},
    {1,  50,  512,    7,    7, 2048,    7,    7,   1,   1,   1,   1,   0,   0, "\"resnet_50:res5a_branch2c\""},
    {1,  50, 2048,    7,    7,  512,    7,    7,   1,   1,   1,   1,   0,   0, "\"resnet_50:res5b_branch2a\""},
    {1,  50,  512,    7,    7,  512,    7,    7,   3,   3,   1,   1,   1,   1, "\"resnet_50:res5b_branch2b\""},
    {1,  50,  512,    7,    7, 2048,    7,    7,   1,   1,   1,   1,   0,   0, "\"resnet_50:res5b_branch2c\""},
    {1,  50, 2048,    7,    7,  512,    7,    7,   1,   1,   1,   1,   0,   0, "\"resnet_50:res5c_branch2a\""},
    {1,  50,  512,    7,    7,  512,    7,    7,   3,   3,   1,   1,   1,   1, "\"resnet_50:res5c_branch2b\""},
    {1,  50,  512,    7,    7, 2048,    7,    7,   1,   1,   1,   1,   0,   0, "\"resnet_50:res5c_branch2c\""},

    // Topology: googlenet_v1
    {1,  96,    3,  224,  224,   64,  112,  112,   7,   7,   2,   2,   3,   3, "\"googlenet_v1:conv1/7x7_s2\""},
    {1,  96,   64,   56,   56,   64,   56,   56,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:conv2/3x3_reduce\""},
    {1,  96,   64,   56,   56,  192,   56,   56,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:conv2/3x3\""},
    {1,  96,  192,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3a/1x1\""},
    {1,  96,  192,   28,   28,   96,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3a/3x3_reduce\""},
    {1,  96,   96,   28,   28,  128,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_3a/3x3\""},
    {1,  96,  192,   28,   28,   16,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3a/5x5_reduce\""},
    {1,  96,   16,   28,   28,   32,   28,   28,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_3a/5x5\""},
    {1,  96,  192,   28,   28,   32,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3a/pool_proj\""},
    {1,  96,  256,   28,   28,  128,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3b/1x1\""},
    {1,  96,  256,   28,   28,  128,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3b/3x3_reduce\""},
    {1,  96,  128,   28,   28,  192,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_3b/3x3\""},
    {1,  96,  256,   28,   28,   32,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3b/5x5_reduce\""},
    {1,  96,   32,   28,   28,   96,   28,   28,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_3b/5x5\""},
    {1,  96,  256,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_3b/pool_proj\""},
    {1,  96,  480,   14,   14,  192,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4a/1x1\""},
    {1,  96,  480,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4a/3x3_reduce\""},
    {1,  96,   96,   14,   14,  208,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_4a/3x3\""},
    {1,  96,  480,   14,   14,   16,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4a/5x5_reduce\""},
    {1,  96,   16,   14,   14,   48,   14,   14,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_4a/5x5\""},
    {1,  96,  480,   14,   14,   64,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4a/pool_proj\""},
    {1,  96,  512,    4,    4,  128,    4,    4,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:loss1/conv\""},
    {1,  96,  512,   14,   14,  160,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4b/1x1\""},
    {1,  96,  512,   14,   14,  112,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4b/3x3_reduce\""},
    {1,  96,  112,   14,   14,  224,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_4b/3x3\""},
    {1,  96,  512,   14,   14,   24,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4b/5x5_reduce\""},
    {1,  96,   24,   14,   14,   64,   14,   14,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_4b/5x5\""},
    {1,  96,  512,   14,   14,   64,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4b/pool_proj\""},
    {1,  96,  512,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4c/1x1\""},
    {1,  96,  512,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4c/3x3_reduce\""},
    {1,  96,  128,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_4c/3x3\""},
    {1,  96,  512,   14,   14,   24,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4c/5x5_reduce\""},
    {1,  96,   24,   14,   14,   64,   14,   14,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_4c/5x5\""},
    {1,  96,  512,   14,   14,   64,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4c/pool_proj\""},
    {1,  96,  512,   14,   14,  112,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4d/1x1\""},
    {1,  96,  512,   14,   14,  144,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4d/3x3_reduce\""},
    {1,  96,  144,   14,   14,  288,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_4d/3x3\""},
    {1,  96,  512,   14,   14,   32,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4d/5x5_reduce\""},
    {1,  96,   32,   14,   14,   64,   14,   14,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_4d/5x5\""},
    {1,  96,  512,   14,   14,   64,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4d/pool_proj\""},
    {1,  96,  528,    4,    4,  128,    4,    4,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:loss2/conv\""},
    {1,  96,  528,   14,   14,  256,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4e/1x1\""},
    {1,  96,  528,   14,   14,  160,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4e/3x3_reduce\""},
    {1,  96,  160,   14,   14,  320,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_4e/3x3\""},
    {1,  96,  528,   14,   14,   32,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4e/5x5_reduce\""},
    {1,  96,   32,   14,   14,  128,   14,   14,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_4e/5x5\""},
    {1,  96,  528,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_4e/pool_proj\""},
    {1,  96,  832,    7,    7,  256,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5a/1x1\""},
    {1,  96,  832,    7,    7,  160,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5a/3x3_reduce\""},
    {1,  96,  160,    7,    7,  320,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_5a/3x3\""},
    {1,  96,  832,    7,    7,   32,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5a/5x5_reduce\""},
    {1,  96,   32,    7,    7,  128,    7,    7,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_5a/5x5\""},
    {1,  96,  832,    7,    7,  128,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5a/pool_proj\""},
    {1,  96,  832,    7,    7,  384,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5b/1x1\""},
    {1,  96,  832,    7,    7,  192,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5b/3x3_reduce\""},
    {1,  96,  192,    7,    7,  384,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v1:inception_5b/3x3\""},
    {1,  96,  832,    7,    7,   48,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5b/5x5_reduce\""},
    {1,  96,   48,    7,    7,  128,    7,    7,   5,   5,   1,   1,   2,   2, "\"googlenet_v1:inception_5b/5x5\""},
    {1,  96,  832,    7,    7,  128,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v1:inception_5b/pool_proj\""},

    // Topology: googlenet_v2
    {1,  96,    3,  224,  224,   64,  112,  112,   7,   7,   2,   2,   3,   3, "\"googlenet_v2:conv1/7x7_s2\""},
    {1,  96,   64,   56,   56,   64,   56,   56,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:conv2/3x3_reduce\""},
    {1,  96,   64,   56,   56,  192,   56,   56,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:conv2/3x3\""},
    {1,  96,  192,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3a/1x1\""},
    {1,  96,  192,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3a/3x3_reduce\""},
    {1,  96,   64,   28,   28,   64,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3a/3x3\""},
    {1,  96,  192,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3a/double3x3_reduce\""},
    {1,  96,   64,   28,   28,   96,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3a/double3x3a\""},
    {1,  96,   96,   28,   28,   96,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3a/double3x3b\""},
    {1,  96,  192,   28,   28,   32,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3a/pool_proj\""},
    {1,  96,  256,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3b/1x1\""},
    {1,  96,  256,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3b/3x3_reduce\""},
    {1,  96,   64,   28,   28,   96,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3b/3x3\""},
    {1,  96,  256,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3b/double3x3_reduce\""},
    {1,  96,   64,   28,   28,   96,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3b/double3x3a\""},
    {1,  96,   96,   28,   28,   96,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3b/double3x3b\""},
    {1,  96,  256,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3b/pool_proj\""},
    {1,  96,  320,   28,   28,  128,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3c/3x3_reduce\""},
    {1,  96,  128,   28,   28,  160,   14,   14,   3,   3,   2,   2,   1,   1, "\"googlenet_v2:inception_3c/3x3\""},
    {1,  96,  320,   28,   28,   64,   28,   28,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_3c/double3x3_reduce\""},
    {1,  96,   64,   28,   28,   96,   28,   28,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_3c/double3x3a\""},
    {1,  96,   96,   28,   28,   96,   14,   14,   3,   3,   2,   2,   1,   1, "\"googlenet_v2:inception_3c/double3x3b\""},
    {1,  96,  576,    4,    4,  128,    4,    4,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:loss1/conv\""},
    {1,  96,  576,   14,   14,  224,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4a/1x1\""},
    {1,  96,  576,   14,   14,   64,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4a/3x3_reduce\""},
    {1,  96,   64,   14,   14,   96,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4a/3x3\""},
    {1,  96,  576,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4a/double3x3_reduce\""},
    {1,  96,   96,   14,   14,  128,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4a/double3x3a\""},
    {1,  96,  128,   14,   14,  128,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4a/double3x3b\""},
    {1,  96,  576,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4a/pool_proj\""},
    {1,  96,  576,   14,   14,  192,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4b/1x1\""},
    {1,  96,  576,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4b/3x3_reduce\""},
    {1,  96,   96,   14,   14,  128,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4b/3x3\""},
    {1,  96,  576,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4b/double3x3_reduce\""},
    {1,  96,   96,   14,   14,  128,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4b/double3x3a\""},
    {1,  96,  128,   14,   14,  128,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4b/double3x3b\""},
    {1,  96,  576,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4b/pool_proj\""},
    {1,  96,  576,   14,   14,  160,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4c/1x1\""},
    {1,  96,  576,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4c/3x3_reduce\""},
    {1,  96,  128,   14,   14,  160,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4c/3x3\""},
    {1,  96,  576,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4c/double3x3_reduce\""},
    {1,  96,  128,   14,   14,  160,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4c/double3x3a\""},
    {1,  96,  160,   14,   14,  160,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4c/double3x3b\""},
    {1,  96,  576,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4c/pool_proj\""},
    {1,  96,  576,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4d/1x1\""},
    {1,  96,  576,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4d/3x3_reduce\""},
    {1,  96,  128,   14,   14,  192,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4d/3x3\""},
    {1,  96,  576,   14,   14,  160,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4d/double3x3_reduce\""},
    {1,  96,  160,   14,   14,  192,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4d/double3x3a\""},
    {1,  96,  192,   14,   14,  192,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4d/double3x3b\""},
    {1,  96,  576,   14,   14,   96,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4d/pool_proj\""},
    {1,  96,  576,   14,   14,  128,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4e/3x3_reduce\""},
    {1,  96,  128,   14,   14,  192,    7,    7,   3,   3,   2,   2,   1,   1, "\"googlenet_v2:inception_4e/3x3\""},
    {1,  96,  576,   14,   14,  192,   14,   14,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_4e/double3x3_reduce\""},
    {1,  96,  192,   14,   14,  256,   14,   14,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_4e/double3x3a\""},
    {1,  96,  256,   14,   14,  256,    7,    7,   3,   3,   2,   2,   1,   1, "\"googlenet_v2:inception_4e/double3x3b\""},
    {1,  96, 1024,    2,    2,  128,    2,    2,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:loss2/conv\""},
    {1,  96, 1024,    7,    7,  352,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5a/1x1\""},
    {1,  96, 1024,    7,    7,  192,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5a/3x3_reduce\""},
    {1,  96,  192,    7,    7,  320,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_5a/3x3\""},
    {1,  96, 1024,    7,    7,  160,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5a/double3x3_reduce\""},
    {1,  96,  160,    7,    7,  224,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_5a/double3x3a\""},
    {1,  96,  224,    7,    7,  224,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_5a/double3x3b\""},
    {1,  96, 1024,    7,    7,  128,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5a/pool_proj\""},
    {1,  96, 1024,    7,    7,  352,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5b/1x1\""},
    {1,  96, 1024,    7,    7,  192,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5b/3x3_reduce\""},
    {1,  96,  192,    7,    7,  320,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_5b/3x3\""},
    {1,  96, 1024,    7,    7,  192,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5b/double3x3_reduce\""},
    {1,  96,  192,    7,    7,  224,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_5b/double3x3a\""},
    {1,  96,  224,    7,    7,  224,    7,    7,   3,   3,   1,   1,   1,   1, "\"googlenet_v2:inception_5b/double3x3b\""},
    {1,  96, 1024,    7,    7,  128,    7,    7,   1,   1,   1,   1,   0,   0, "\"googlenet_v2:inception_5b/pool_proj\""},
};

#endif
