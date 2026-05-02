#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/config.env"

# artifacts
mkdir -p ${ARTIFACTS_DIR}

# demos.zip
zip -j ${ARTIFACTS_DEMOS_ZIP} ${DEOM_FILES}

# src.zip
cd ${SRC_DIR} \
&& zip -r ${ARTIFACTS_SRC_ZIP} .
