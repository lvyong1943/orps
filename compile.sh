#! /usr/bin/env bash
# compile.sh

if [ -z "$WEBRTC_ROOT" ]; then
  echo "You should source envsetup.sh first."
  exit 1
fi

bash contrib/compile-contrib.sh

[ ! -d build ] && mkdir build
cd build && cmake .. && make VERBOSE=1

$CONTRIB_LINUX_INSTALL_DIR/bin/omxregister-bellagio $CONTRIB_LINUX_INSTALL_DIR/lib/bellagio:$TARGET_OUT
