/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "include/common.h"
#include "tests.h"

#include <stdlib.h>
#include <time.h>

int
main(int argc, const char * argv[]) {
  test_entry_t *entry;
  test_status_t st;
  int32_t       i, count, passed, failed;
  double        start, end, elapsed;

  passed = failed = 0;
  count  = sizeof(tests) / sizeof(tests[0]);
 
  fprintf(stderr, CYAN "\nWelcome to cglm tests\n\n" RESET);
  
  for (i = 0; i < count; i++) {
    entry   = tests + i;
    start   = clock();
    st      = entry->entry();
    end     = clock();
    elapsed = (end - start) / CLOCKS_PER_SEC;

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
      fprintf(stderr, GREEN  "  ✔︎" RESET " %s - " , entry->name);
      
      if (elapsed > 0.01)
        fprintf(stderr, YELLOW "%.2f", elapsed);
      else
        fprintf(stderr, "0");

      fprintf(stderr, "s\n" RESET);
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
          count,
          passed,
          passed > 1 ? "are" : "is",
          failed,
          failed > 1 ? "are" : "is");

  return failed;
}
