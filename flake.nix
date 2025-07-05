{
  description = "GameBoy++";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
  in {
    devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
            xmake
            ninja
            gcc15
            stdenv.cc.cc
            mold
            gdb
            llvm
            llvmPackages_20.clang-tools
            python314
            pkg-config
            libGL
            xorg.libX11
            pre-commit
        ];
    };
  };
}
