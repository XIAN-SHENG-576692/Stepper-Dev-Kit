#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/config.env"

cd "$EXAMPLES_DIR" || {
    echo "Error: Unable to access $EXAMPLES_DIR"
    exit 1
}

cmake --preset build
cmake --build build
