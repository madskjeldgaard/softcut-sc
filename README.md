> [!NOTE]
> This project is a work in progress. It currently doesn't work. If you want to help out, please feel free to submit a PR.

# Softcut

Author: Mads Kjeldgaard

Supercollider version of the [monome Softcut](https://github.com/monome/softcut-lib) software.

### Requirements

- CMake >= 3.5
- SuperCollider source code

### Building

Clone the project:

    git clone https://github.com/madskjeldgaard/softcut-sc
    cd softcut-sc
    mkdir build
    cd build

Then, use CMake to configure and build it:

    cmake .. -DCMAKE_BUILD_TYPE=Release
    cmake --build . --config Release
    cmake --build . --config Release --target install

You may want to manually specify the install location in the first step to point it at your
SuperCollider extensions directory: add the option `-DCMAKE_INSTALL_PREFIX=/path/to/extensions`.


CMake will automatically download the supercollider source code if you do not define it.

It's expected that the SuperCollider repo is cloned at `../supercollider` relative to this repo. If
it's not: add the option `-DSC_PATH=/path/to/sc/source`.

