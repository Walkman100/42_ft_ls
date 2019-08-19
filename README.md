# ft_ls

Reimplementation of the macOS (BSD) ls command, compiles & works on Linux (glibc).

### Compiling

On a Debian-based system (e.g. Ubuntu, Mint), install:
- `attr-dev` (specify `libattr1-dev` if the virtual package `attr-dev` doesn't exist)
- `acl-dev` (specify `libacl1-dev` if the virtual package `acl-dev` doesn't exist)

Make sure you have the [`libft`](https://github.com/Walkman100/42_libft) submodule initialised:
- either clone this repo with the `--recursive` flag or run `git submodule init` afterwards

Then `make` should compile `libft` and this project.
