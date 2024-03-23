# Build Kernel

## Steps 
```bash
#clone the repo 
git clone --depth=1 git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
make ARCH=arm vexpress_defconfig

#export the compiler
export CROSS_COMPILE=PathToCompiler/arm-linux-cortexa9Compiler
#export the architecture used
export ARCH=arm

# configure the kernel with the configuration discuss above

# Enable devtmpfs and auto-mount devtmpfs
# Change your kernel local version to your name and append on it -v1.0
# Change kernel compression to XZ

make menuconfig

#build the kernel and dtb
make -j4 zImage modules dtbs
# path of the zImage module
# linux/arch/arm/boot/zImage
# path of the dtb 
# linux/arch/arm/boot/dts/arm/vexpress-v2p-ca9.dts
```