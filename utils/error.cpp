#include "error.hpp"
#include <iostream>

namespace beryl {
  void throw_lex_error(std::string_view msg, int line_num, int col_num) {
    std::cerr << "Error: " << msg << " at line " << line_num << " and column " << col_num << '\n';
    fail();
  }

  void throw_lex_warning(std::string_view msg, int line_num, int col_num) {
    std::cerr << "Warning: " << msg << " at line " << line_num << " and column " << col_num << '\n';
  }

  void throw_arg_read_error(std::string_view msg) {
    std::cerr << "Error: " << msg << '\n';
    fail();
  }

  void throw_arg_read_warning(std::string_view msg) {
    std::cerr << "Warning: " << msg << '\n';
  }
} // namespace beryl