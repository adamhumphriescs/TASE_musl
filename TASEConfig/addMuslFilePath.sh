set -e

echo "MUSL_PATH=$(pwd)/.." >> config.mak_no_simd
echo "MUSL_PATH=$(pwd)/.." >> config.mak_simd
