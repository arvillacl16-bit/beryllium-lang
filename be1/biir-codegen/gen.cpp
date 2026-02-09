#include "gen.hpp"
#include "utils/error.hpp"
#include <sstream>

namespace beryl::be1 {
  namespace {
    template <class... Ts> struct Overloaded : Ts... {
      using Ts::operator()...;
    };
    template <class... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;

    void class_visitor(const ast::ClassDecl* const class_, std::ostringstream& out) {
      //
    }

    void var_visitor(const ast::VarDecl* const var, std::ostringstream& out) {
      //
    }

    void func_visitor(const ast::FunctionDecl* const func, std::ostringstream& out) {
      //
    }

    void nsp_visitor(const ast::NamespaceDecl* const nsp, std::ostringstream& out) {
      //
    }

    void import_visitor(const ast::ImportDecl* const import, std::ostringstream& out) {
      //
    }
  } // namespace

  std::string ast_to_biir(const ast::Program* const prog) {
    std::ostringstream out;
    for (auto el : prog->body) {
      std::visit(
          Overloaded{
              [&](const ast::ClassDecl* const class_) { class_visitor(class_, out); },
              [&](const ast::VarDecl* const var) { var_visitor(var, out); },
              [&](const ast::FunctionDecl* const func) { func_visitor(func, out); },
              [&](const ast::NamespaceDecl* const nsp) { nsp_visitor(nsp, out); },
              [&](const ast::ImportDecl* const import) { import_visitor(import, out); }},
          el);
    }
    return out.str();
  }
} // namespace beryl::be1