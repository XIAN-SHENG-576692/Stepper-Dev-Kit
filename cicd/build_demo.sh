#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/config.env"

cmake --preset demo
cmake --build ${BUILD_DIR}
