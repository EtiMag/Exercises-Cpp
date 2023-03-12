#!bin/sh
cd ~/work
wget https://github.com/Kitware/CMake/releases/download/v3.26.0-rc6/cmake-3.26.0-rc6-linux-x86_64.tar.gz
tar -zxvf cmake-3.26.0-rc6-linux-x86_64.tar.gz
export PATH=$PATH:~/work/cmake-3.26.0-rc6-linux-x86_64/bin/
cmake --help
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
mkdir build
cd build
cmake -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../llvm
make
