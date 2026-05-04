#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "${SCRIPT_DIR}/../env/config.env"

cd "$EXAMPLES_DIR" || {
    echo "Error: Unable to access $EXAMPLES_DIR"
    exit 1
}

cmake --preset release-dist
cmake --build --preset dist
