#!/bin/sh

SCRIPT_DIR=$(cd $(dirname $0); pwd)
ROOT_DIR="$SCRIPT_DIR/.."

cd "$ROOT_DIR" || {
    echo "Error: Unable to access $ROOT_DIR"
    exit 1
}

find . -type d -name "build*" -prune -o -name "*.[ch]" -print \
    | xargs clang-format -style=file -i -verbose
