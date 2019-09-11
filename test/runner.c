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
 
  fprintf(stderr, CYAN "\nWelcome to cglm tests\n\n" RESET);
  
  for (i = 0; i < count; i++) {
    entry = tests + i;
    st    = entry->entry();

    if (!st.status) {
      fprintf(stderr,
              BOLDRED  "  𐄂" BOLDWHITE " %s " RESET,
              entry->name);
      if (st.msg) {
        fprintf(stderr,
                YELLOW "- %s" RESET,
                st.msg);
      }

      fprintf(stderr, "\n");

      failed++;
    } else {
      fprintf(stderr,
              GREEN  "  ✔︎" RESET " %s\n"
              ,
              entry->name);
      passed++;
    }
  }
  
  if (failed == 0) {
    fprintf(stderr, BOLDGREEN "\n  All tests are passed 🎉\n" RESET);
  }

  fprintf(stderr,
          CYAN "\ncglm test results:\n" RESET
          "------------------\n"
          
          MAGENTA "%d" RESET " tests are runned, "
          GREEN   "%d" RESET " %s passed, "
          RED     "%d" RESET " %s failed\n\n" RESET,
          passed + failed,
          passed,
          passed > 1 ? "are" : "is",
          failed,
          failed > 1 ? "are" : "is");

  return failed;
}
