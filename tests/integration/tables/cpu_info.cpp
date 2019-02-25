
/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed in accordance with the terms specified in
 *  the LICENSE file found in the root directory of this source tree.
 */

// Sanity check integration test for cpu_info
// Spec file: specs/windows/cpu_info.table

#include <osquery/tests/integration/tables/helper.h>

namespace osquery {
namespace table_tests {

class cpuInfo : public testing::Test {
 protected:
  void SetUp() override {
    setUpEnvironment();
  }
};

TEST_F(cpuInfo, test_sanity) {
  const QueryData data = execute_query("select * from cpu_info");
  ASSERT_EQ(data.size(), 1ul);
  ValidatatioMap row_map = {{"device_id", NormalType},
                            {"model", NormalType},
                            {"manufacturer", NormalType},
                            {"processor_type", NonNegativeOrErrorInt},
                            {"availability", NonNegativeOrErrorInt},
                            {"cpu_status", NonNegativeOrErrorInt},
                            {"number_of_cores", NonNegativeOrErrorInt},
                            {"logical_processors", NonNegativeOrErrorInt},
                            {"address_width", NonNegativeOrErrorInt},
                            {"current_clock_speed", NonNegativeOrErrorInt},
                            {"max_clock_speed", NonNegativeOrErrorInt},
                            {"socket_designation", NormalType}};
  validate_rows(data, row_map);
}

} // namespace table_tests
} // namespace osquery