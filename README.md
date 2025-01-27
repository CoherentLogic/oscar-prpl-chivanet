# OSCAR AIM PRPL for Pidgin

This prpl (OSCAR AOL Instant Messenger Protocol Plugin for Pidgin, that's a mouthful) takes the Pidgin 2.13.0 AIM prpl so you can build it and use on modern(-ish) Pidgin versions.

Default server is [NINA](https://nina.chat), but you can change it in the account settings.

The original authors of the protocol are in the `AUTHORS` file. As per the original license, this code is licensed under the GNU Lesser General Public License version 2.1.

# Building with CMake

This script uses CMake to build a Pidgin 2 (libpurple 2) protocol plug-in in a way that does not suck.  
Because having one Makefile for each toolchain is annoying. (thanks https://github.com/hoehermann/purple-cmake-template)

On Windows, this script will automatically setup a development environment. These compilers are known to work:

* [MSYS2](https://www.msys2.org/) with [gcc 13.2.1](https://packages.msys2.org/package/mingw-w64-i686-gcc).
* Microsoft Visual Studio 2022 with MSVC 14.

These compilers are noteworthy:

* [MinGW](https://osdn.net/projects/mingw/) with gcc 9.2.0 was used in the past.
* [MinGW](https://sourceforge.net/projects/mingw/files/MinGW/Base/gcc/Version4/gcc-4.7.2-1/) with gcc 4.7.2 is recommended by Pidgin developers, but never used with this script.

Note: Any binary produced by at least gcc 7.1.0 or newer may need static linkage of `libgcc` for proper distribution. This script does *not* take care of this setting.

### Linux:

1. Configure project. Specify the path to this script:

        cmake -DPurple_DIR=…/purple-cmake ..

2. Build project:

        cmake --build .

3. Install binaries system-wide:

        sudo cmake --install .

Note: During the configuration step, you can override `PURPLE_DATA_DIR` and `PURPLE_PLUGIN_DIR` request preparing a user-based installation:

    cmake -DPurple_DIR=…/purple-cmake -DPURPLE_DATA_DIR:PATH=~/.local/share -DPURPLE_PLUGIN_DIR:PATH=~/.purple/plugins ..

You can then execute `cmake --install .` without `sudo`.

### Windows

1. Configure:

    This will set-up a development environment including a pidgin installation in your build directory.

        cmake -DCMAKE_BUILD_TYPE=Debug ..

    `-G "MSYS Makefiles"` is recommended for MSYS/MinGW. When omitting the generator, CMake may default to MSBuild and you may need to specify `-DCMAKE_GENERATOR_PLATFORM=WIN32` for MSVC x86.

    Note: You can use vcpkg-managed packages by adding the path like this: 

        -DCMAKE_TOOLCHAIN_FILE="…/vcpkg/scripts/buildsystems/vcpkg.cmake" -DVCPKG_TARGET_TRIPLET=x86-mingw-static -DVCPKG_MANIFEST_MODE=OFF

    Use `x86-mingw-static` for MinGW builds. Use `x86-windows-static` for MSVC builds.

2. Build:

        cmake --build .

3. Install:

    This will install into the pidgin installation in your build directory.

        cmake --install .

4. Execute:

    This will execute the Pidgin installation.

        cmake --build . --target run

    Note: You can specify the purple user configuration directory to be used by the run target:

        -DPurple_CONFIG_DIR=…/.purple

Note: Building on Windows is most reliable when there are no existing installations of Pidgin, GTK+ and/or libgcc in your PATH.
