#!/bin/bash

set -ev

case "${TARGET_ARCH}" in
  i386)
    DIST_ARCH=x86
      ;;
  amd64)
    DIST_ARCH=x64
      ;;
  *)
    DIST_ARCH=$TARGET_ARCH
    ;;
esac

echo "RELEASE_TAG is $RELEASE_TAG";
mkdir -p ${RELEASE_TAG};

if [[ $RELEASE_OS_NAME == 'linux' ]]; then # linux
  # file "Linux_${TARGET_ARCH}_$BUILD_TYPE" existed .dist/bin
  export DIST_FILE=vender-linux-${DIST_ARCH}-$BUILD_TYPE.zip
else # darwin
  # file "Darwin_${TARGET_ARCH}_$BUILD_TYPE" existed .dist/bin
  export DIST_FILE=vender-darwin-${DIST_ARCH}-$BUILD_TYPE.zip
fi

CUR=`pwd`
cd ./.dist/bin
echo "archiving file: $DIST_FILE"
zip -r ${CUR}/${RELEASE_TAG}/${DIST_FILE} ./*
echo "finish archiving!"
cd $CUR

# if [[ ($RELEASE_OS_NAME == 'linux']) && ($DIST_ARCH == 'x64') ]]; then
#   echo "zip fullsrc..."
#   sudo rm -rf .git
#   sudo sh build clean
#   zip -r ./${RELEASE_TAG}/fullsrc.zip ./ -x ${RELEASE_TAG}/*
# fi

exit 0;
