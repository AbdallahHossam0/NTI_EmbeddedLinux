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

# Enable devtmpfs
# Change your kernel local version to your name and append on it -v1.0
# Change kernel compression to XZ

make menuconfig

#build the kernel
make -j4 zImage modules dtbs
```