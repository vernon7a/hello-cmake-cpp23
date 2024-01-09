set shell := ["pwsh.exe", "-c"]

cmake:
    cmake -B build -S .

clean:
    coreutils.exe rm -rf out build

example1:
    cmake --build build --config Debug
    build/bin/Debug/example1.exe
