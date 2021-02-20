set -e

echo "MUSL_DIR=$(pwd)/.." >> config.mak_no_simd
echo "MUSL_DIR=$(pwd)/.." >> config.mak_simd
