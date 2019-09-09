/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "include/common.h"
#include "tests.h"

#include <stdlib.h>

int
main(int argc, const char * argv[]) {
  test_entry_t *entry;
  test_status_t st;
  int32_t       i, count, passed, failed;

  passed = failed = 0;
  count  = sizeof(tests) / sizeof(tests[0]);

  for (i = 0; i < count; i++) {
    entry = tests + i;
    st    = entry->entry();

    if (!st.status) {
      if (st.msg) {
        fprintf(stderr, "TEST FAIL (%s): %s\n", entry->name, st.msg);
      }

      failed++;
    } else {
      passed++;
    }
  }

  fprintf(stderr,
          "\nCGLM TEST RESULTS:\n"
          "------------------\n"
          "TOTAL\t: %d\n"
          "PASSED\t: %d\n"
          "FAILED\t: %d\n\n",
          passed + failed,
          passed,
          failed);

  return failed;
}
