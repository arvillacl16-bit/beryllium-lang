# Beryllium

This is a hobby programming language. It is WIP.

## Dependencies

For the compiler:

- C++20
- LLVM API
- Meson

For the package manager:

- Go
- Cobra

For the Beryllium runtime:

- C compiler

## Building

First, clone the repository:

```sh
git clone www.github.com/arvillacl16-bit/beryllium-lang.git
cd beryllium-lang
```

Compiler:

```sh
cd compiler
meson setup builddir --buildtype=release
meson compile -C builddir
```

The executable is at ./builddir/beryl. It does support install, so if you want to install, do:

```sh
meson install -C builddir
```

Package manager:

```sh
cd mineraloil
go build -o mineraloil main.go
```

The executable is at ./mineraloil.

Runtime:

The C file is at ./start/start.c. It is a single file that can be compiled directly with no issues. However, you do have to pass a flag to stop it from trying to link the file.
