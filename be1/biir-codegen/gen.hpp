#pragma once
#include "be1/parser/parse.hpp"
#include <string_view>

namespace beryl::be1 {
  void ast_to_biir(const ast::Program* const prog, std::string_view path);
}