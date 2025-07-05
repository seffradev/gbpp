# GameBoy++

A toy GameBoy emulator, written in modern C++. The project uses
[`raylib`](https://www.raylib.com/) for graphics, input and audio.

This project is a very early draft.

## Features

- [ ] Graphics
- [ ] Input
  - [ ] Customisable via Lua scripting
- [ ] Audio playback
- [ ] ROM loading
- [ ] Lua scripting

## Building

If you're using NixOS, see below.

The project uses `xmake` as a build system. If you don't already
have it, go and install it via [this link](https://xmake.io).

To build and run the project, just enter the following from the
project root:

```sh
xmake run
```

### NixOS

There is a `flake.nix` in the repo, so set up your environment
with `nix develop` in the repository root. Then run the shell
command in the previous section and you're done.

## Contributing

This project uses [`pre-commit`](https://pre-commit.com/) to
validate code and enforce a common formatting. Install `pre-commit`
and set it up by running the following command in the project
root:

```sh
pre-commit install
```

This enables `pre-commit` to run the lint checks and autoformats
your code on every commit.
