#!/bin/bash

# 赋值目录到变量 DIR
#DIR=/root/riscv-tests/isa/rv64ui


#DIR=/root/riscv-tests/isa/rv32mi
DIR=/root/riscv-tests/isa/rv64uzfh
#DIR=/root/riscv-tests/isa/rv32uc
#DIR=/root/riscv-tests/isa/rv32ui

# 检查目录是否存在
if [ ! -d "$DIR" ]; then
    echo "Directory does not exist: $DIR"
    exit 1
fi

#遍历目录中的所有 .s 文件
for file in "$DIR"/*.S; do
    # 获取没有扩展名的文件名
    filename=$(basename -- "$file")
    filename="${filename%.*}"
    newfilename="New${filename}"

    gcc -E -D__riscv_xlen=64 -o "$DIR"/"$newfilename".S -I/root/riscv-tests/env/ -I/root/riscv-tests/isa/macros/scalar -I/root/riscv-tests/env/p "$file"
     #使用 riscv32-unknown-elf-as 編譯每個檔案
       ./riscv32-unknown-elf-as -march=rv64ifd_zfh_zicsr -I/root/riscv-tests/env/ -I/root/riscv-tests/isa/macros/scalar -I/root/riscv-tests/env/p -o "$DIR"/"$newfilename".o "$DIR"/"$newfilename".S
      riscv64-unknown-elf-ld -T/root/riscv-tests/env/p/link.ld -e _start -o "$DIR"/"$newfilename.elf" "$DIR"/"$newfilename".o
     echo "Compiled $file to "$DIR"/"$newfilename".S"
done

for file in "$DIR"/*.elf; do
    #获取没有扩展名的文件名
    filename=$(basename -- "$file")
    filename="${filename%.*}"
    newfilename="New${filename}"

     echo "$file"
     /root/riscv-gnu-toolchain/spike/build/spike --isa=RV64ifd_zfh_zicsr "$file" | tee rv64uzfh.txt
done

echo "Assembly complete."