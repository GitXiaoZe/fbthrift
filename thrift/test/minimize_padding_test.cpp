/*
 * Copyright 2018-present Facebook, Inc.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <cstddef>

#include <thrift/test/gen-cpp2/minimize_padding_types.h>

#include <gtest/gtest.h>

using namespace apache::thrift::test;

TEST(minimize_padding_test, empty) {
  EXPECT_EQ(1, sizeof(empty));
}

struct optimal {
  std::string i;
  std::vector<int8_t> k;
  std::set<int8_t> m;
  std::map<int8_t, int8_t> o;
  double g;
  int64_t e;
  float h;
  int32_t c;
  int32_t q;
  test_enum f;
  int16_t a;
  int8_t d;
  int8_t j;
  int8_t l;
  int8_t n;
  int8_t p;
  bool b;
};

TEST(minimize_padding_test, reorder_nonoptimal) {
  EXPECT_EQ(sizeof(optimal), sizeof(nonoptimal));
  EXPECT_EQ(sizeof(nonoptimal_struct), 12);
  EXPECT_EQ(offsetof(nonoptimal_struct, big), 0);
}

TEST(minimize_padding_test, preserve_order_if_same_sizes) {
  EXPECT_LT(offsetof(same_sizes, a), offsetof(same_sizes, b));
  EXPECT_LT(offsetof(same_sizes, b), offsetof(same_sizes, c));
  EXPECT_LT(offsetof(same_sizes, c), offsetof(same_sizes, d));
}

struct reordered_ref_type {
  std::unique_ptr<int8_t> b;
  std::unique_ptr<int8_t> d;
  int8_t a;
  int8_t c;
};

TEST(minimize_padding_test, reorder_ref_type) {
  EXPECT_EQ(sizeof(reordered_ref_type), sizeof(ref_type));
}
