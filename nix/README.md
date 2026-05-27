# NITINDYT CLIENT LAUNCHER Nix Packaging

## Installing a development release (flake)

We use [cachix](https://cachix.org/) to cache our development and release builds.
If you want to avoid rebuilds you may add the Cachix bucket to your substitutors, or use `--accept-flake-config`
to temporarily enable it when using `nix` commands.

Example (NixOS):

```nix
{
  nix.settings = {
    trusted-substituters = [ "https://nitindytclient.cachix.org" ];

    trusted-public-keys = [
      "nitindytclient.cachix.org-1:...="
    ];
  };
}
```

### Installing the package directly

After adding `github:NitindytClient/NitindytClient` to your flake inputs, you can access the flake's `packages` output.

Example:

```nix
{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

    nitindytclient = {
      url = "github:NitindytClient/NitindytClient";
    };
  };

  outputs =
    { nixpkgs, nitindytclient, ... }:
    {
      nixosConfigurations.foo = nixpkgs.lib.nixosSystem {
        modules = [
          ./configuration.nix

          (
            { pkgs, ... }:
            {
              environment.systemPackages = [ nitindytclient.packages.${pkgs.system}.nitindytclient ];
            }
          )
        ];
      };
    };
}
```

### Using the overlay

Alternatively, if you don't want to use our `packages` output, you can add our overlay to your nixpkgs instance.
This will ensure the package is built with your system's libraries.

Example:

```nix
{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

    nitindytclient = {
      url = "github:NitindytClient/NitindytClient";
    };
  };

  outputs =
    { nixpkgs, nitindytclient, ... }:
    {
      nixosConfigurations.foo = nixpkgs.lib.nixosSystem {
        modules = [
          ./configuration.nix

          (
            { pkgs, ... }:
            {
              nixpkgs.overlays = [ nitindytclient.overlays.default ];
              environment.systemPackages = [ pkgs.nitindytclient ];
            }
          )
        ];
      };
    };
}
```

### Installing the package ad-hoc (`nix shell`, `nix run`, etc.)

You can simply call the default package of this flake.

Example:

```shell
nix run github:NitindytClient/NitindytClient

nix shell github:NitindytClient/NitindytClient

nix profile install github:NitindytClient/NitindytClient
```

## Package variants

This repository offers the following packages:

- `nitindytclient` - The preferred build, wrapped with everything necessary to run the launcher and Minecraft
- `nitindytclient-unwrapped` - A minimal build that allows for advanced customization of the launcher's runtime environment
