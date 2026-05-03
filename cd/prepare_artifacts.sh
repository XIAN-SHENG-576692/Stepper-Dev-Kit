#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)
. "$SCRIPT_DIR/../env/config.env"

# artifacts
mkdir -p ${ARTIFACTS_DIR}

# examples.zip
zip -j ${ARTIFACTS_EXAMPLES_ZIP} ${EXAMPLE_DIST_BINS}
