#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/config.env"

# artifacts
mkdir -p ${ARTIFACTS_DIR}

# demo
zip -j ${ARTIFACTS_DEMO_ZIP} ${DEOM_FILES}

# src
cd ${SRC_DIR} \
&& zip -r ${ARTIFACTS_SRC_ZIP} .
