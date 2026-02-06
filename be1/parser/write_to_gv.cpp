#include "parse.hpp"
#include "utils/error.hpp"
#include <fstream>

namespace beryl::be1 {
  namespace {
    //
  }

  void write_ast_to_gv_file(const ast::Program* const prog, std::string_view path) {
    if (!prog) return;
    std::ofstream out(std::string{path});
    if (!out) beryl::throw_arg_read_error("Could not open file");
    out << "digraph BerylliumAST {";
    out << "}";
  }
} // namespace beryl::be1