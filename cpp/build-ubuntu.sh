#!/bin/sh

root_path=$(dirname $(readlink -f "$0"))
cd ${root_path}

# cmake (Debug/Release)
config=Debug
install_path=install/${config}
echo config: ${config}
echo install_path: ${install_path}
echo "cmake -B build -S . -DCMAKE_INSTALL_PREFIX=${install_path}"
cmake -B build -S . -DCMAKE_INSTALL_PREFIX=${install_path}
echo "cmake --build build --target install --config ${config}"
cmake --build build --target install --config ${config}

# run (main & test)
export LD_LIBRARY_PATH=${install_path}/bin
echo "${install_path}/bin/sample-main"
${install_path}/bin/sample-main
