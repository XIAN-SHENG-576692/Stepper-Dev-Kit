#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/config.env"

# artifacts
mkdir -p ${ARTIFACTS_DIR}

# examples.zip
zip -j ${ARTIFACTS_EXAMPLES_ZIP} ${EXAMPLE_FILES}

# src.zip
cd ${SRC_DIR} \
&& zip -r ${ARTIFACTS_SRC_ZIP} .
