#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/../env/config.env"

cd "$TESTS_DIR" || {
    echo "Error: Unable to access $TESTS_DIR"
    exit 1
}

ctest --test-dir build --rerun-failed --output-on-failure
