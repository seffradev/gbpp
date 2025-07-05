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

This project adheres to [*conventional
commits*](https://conventionalcommits.org/). This is because
- **versioning, as *conventional commits*** interface well with
[*semantic versioning*](https://semver.org/)
- **automated tooling supports** the commit
  structure for changelog generation
- **it enforces a way to think** about your changes, leading to
  better commit messages

There is no silver bullet, so [here is an article with
tips](https://cbea.ms/git-commit/) on improving your commit
messages. Keep your commits
[*atomic*](https://www.freshconsulting.com/insights/blog/atomic-commits/).

### Project scopes

The project defines the following three scopes, to be used in
commits:

- `gameboy` – for emulator-specific functionality. The code living
  here should be able to run a ROM (in a headless way) from start
  to finish. This module is therefore runtime-agnostic and
  pluggable into any framework that provides graphics and audio.
- `utility` – for graphics abstractions and non-emulator specific
  functionality. This is closely intertwined with the `runtime`
  module below, but is used as an abstraction layer for the
  `gameboy` module to wrap it into graphics and audio frameworks.
  Specifically [`raylib`](https://www.raylib.com/).
- `runtime` – this is the executable binary for running the emulator as
  intended, though not the only way since `gameboy` is
  runtime-agnostic.

Keep commits small (*atomic*) and specific to these scopes.
Exceptions are made for refactors and API changes in the libraries
(`gameboy` and `utility`) that affect the library consumers.

### `pre-commit`

This project uses [`pre-commit`](https://pre-commit.com/) to
validate code and enforce a common formatting. Install `pre-commit`
and set it up by running the following command in the project
root:

```sh
pre-commit install
```

This enables `pre-commit` to run the lint checks and autoformats
your code on every commit.
