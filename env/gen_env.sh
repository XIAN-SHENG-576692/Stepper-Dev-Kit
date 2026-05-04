#!/bin/bash

SCRIPT_DIR=$(cd $(dirname $0); pwd)

CONFIG_ENV="${SCRIPT_DIR}/config.env"

cd "${SCRIPT_DIR}/.." \
    || {
        echo "Error: Unable to access $ROOT_DIR"
        exit 1
    } \
    && ROOT_DIR=${PWD}

cat <<EOF > "${CONFIG_ENV}"
ROOT_DIR="${ROOT_DIR}"

# Directories
ARTIFACTS_DIR="\${ROOT_DIR}/artifacts"
EXAMPLES_DIR="\${ROOT_DIR}/examples"
SRC_DIR="\${ROOT_DIR}/src"
TESTS_DIR="\${ROOT_DIR}/tests"

# Files
ARTIFACTS_EXAMPLES_ZIP="\${ARTIFACTS_DIR}/examples.zip"
EXAMPLE_DIST_BINS="\${EXAMPLES_DIR}/dist/bin/*"
EOF
