# BPM – Basic Package Manager

**BPM** is a minimal, GitHub-backed package manager written in C. It allows you to easily install packages from a remote repository, ensuring that each package includes a valid `Makefile`. BPM handles building, installation, and cleanup automatically.

---

## Features

- Installs packages from a GitHub repository.
- Ensures each package contains a `Makefile`.
- Builds packages with `make`.
- Installs binaries to `/usr/local/bin` (or another configured `PREFIX`).
- Cleans up temporary build files automatically.
- Lightweight, written entirely in C.
- Easy to extend for custom OS or shell projects.

---

## Requirements

- POSIX-compatible system (Linux, BSD, macOS)
- `git`
- `make`
- `cc` (C compiler)
- `sudo` (for installation to `/usr/local/bin`)

---

## Installation

1. Clone the BPM repository:

```bash
git clone https://github.com/YOURNAME/bpm.git
cd bpm
```
Build BPM:
```bash
Copy code
make
```
Install BPM:
```bash
Copy code
sudo make install
```
Verify installation:
```bash
Copy code
bpm --help
Usage
```
Install a package
```bash
Copy code
bpm install <package_name>
```
Example:

```bash
Copy code
sudo bpm install hello
```
This will:

    Clone the repository into a temporary directory.
    Check the package exists.
    Verify the presence of a Makefile.
    Build the package using make.
    Install the binary to /usr/local/bin.
    Clean up temporary files.
    Package Requirements

Each package must contain a Makefile.
The Makefile must support:

```makefile
Copy code
all:
    $(CC) source.c -o mybinary

install:
    mkdir -p $(PREFIX)/bin
    cp mybinary $(PREFIX)/bin/
Optional: clean target for cleanup.
```
Development
Modify bpm.c for new features (remove, update, list).

Extend the repository structure to include package metadata.

Ensure new packages follow the Makefile convention.

License
BPM is licensed under the GNU Affero General Public License v3.0 (AGPL-3.0).
You are free to use, modify, and distribute BPM, but any modifications or derivative works must also be licensed under the AGPL.

For details, see the AGPL-3.0 License file provided in this repo.
