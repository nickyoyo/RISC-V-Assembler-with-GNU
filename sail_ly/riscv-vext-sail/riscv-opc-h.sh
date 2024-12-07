#!/bin/bash

# 指定包含 .sail 檔案的目錄，這裡假設是目前目錄
DIRECTORY="/root/sail-riscv/ocmaltest/sail_ly/riscv-vext-sail/sail-model"

# 找到所有 .sail 文件，並將它們的內容傳遞給 ./parser 程式
find "$DIRECTORY" -type f -name '*.sail' -exec cat {} + | ./vextparser