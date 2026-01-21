#include "utils/error.hpp"
#include "utils/parse_json_params.hpp"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <optional>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  std::cout << std::boolalpha;
  std::vector<fs::path> paths_to_by_file;
  std::vector<std::string> includes;
  std::optional<fs::path> exec{};
  bool link = true;
  bool force_module_recompile = false;
  for (size_t i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (fs::path(arg).extension() == ".by") paths_to_by_file.emplace_back(arg);
    else if (arg == "--no-link") link = false;
    else if (arg == "--force-module-recompile") force_module_recompile = true;
    else if (arg.rfind("-includes=", 0) == 0) includes = beryl::get_includes(arg.substr(10));
    else if (arg.rfind("-out=", 0) == 0) exec = arg.substr(6);
    else beryl::throw_arg_read_warning("Unknown compiler argument: " + arg);
  }

  if (paths_to_by_file.size() == 0) beryl::throw_arg_read_error("There is no .by file to compile");
  if (paths_to_by_file.size() > 1 && exec.has_value())
    beryl::throw_arg_read_error("Cannot redirect output for multiple files");

  llvm::LLVMContext context;

  for (const std::filesystem::path& path : paths_to_by_file) {
    llvm::Module mod("BerylliumModule", context);
    llvm::IRBuilder<> builder(context);
  }
  return 0;
}
