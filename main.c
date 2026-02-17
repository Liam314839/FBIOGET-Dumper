#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("/dev/fb0", O_RDONLY);
    if (fd < 0) {
        perror("open fb0");
        return 1;
    }

    struct fb_fix_screeninfo fix;
    struct fb_var_screeninfo var;

    if (ioctl(fd, FBIOGET_FSCREENINFO, &fix) < 0) {
        perror("FBIOGET_FSCREENINFO");
        return 1;
    }

    if (ioctl(fd, FBIOGET_VSCREENINFO, &var) < 0) {
        perror("FBIOGET_VSCREENINFO");
        return 1;
    }

    printf("=== FIX ===\n");
    printf("id            = '%s'\n", fix.id);
    printf("smem_start    = 0x%08lx\n", fix.smem_start);
    printf("smem_len      = %u\n", fix.smem_len);
    printf("type          = %u\n", fix.type);
    printf("type_aux      = %u\n", fix.type_aux);
    printf("visual        = %u\n", fix.visual);
    printf("xpanstep      = %u\n", fix.xpanstep);
    printf("ypanstep      = %u\n", fix.ypanstep);
    printf("ywrapstep     = %u\n", fix.ywrapstep);
    printf("line_length   = %u\n", fix.line_length);
    printf("accel         = %u\n", fix.accel);

    printf("\n=== VAR ===\n");
    printf("xres          = %u\n", var.xres);
    printf("yres          = %u\n", var.yres);
    printf("xres_virtual  = %u\n", var.xres_virtual);
    printf("yres_virtual  = %u\n", var.yres_virtual);
    printf("xoffset       = %u\n", var.xoffset);
    printf("yoffset       = %u\n", var.yoffset);

    printf("bits_per_pixel= %u\n", var.bits_per_pixel);
    printf("grayscale     = %u\n", var.grayscale);
    printf("nonstd        = 0x%08x\n", var.nonstd);

    printf("red:   off=%u len=%u msb=%u\n", var.red.offset, var.red.length, var.red.msb_right);
    printf("green: off=%u len=%u msb=%u\n", var.green.offset, var.green.length, var.green.msb_right);
    printf("blue:  off=%u len=%u msb=%u\n", var.blue.offset, var.blue.length, var.blue.msb_right);
    printf("transp:off=%u len=%u msb=%u\n", var.transp.offset, var.transp.length, var.transp.msb_right);

    printf("activate      = 0x%x\n", var.activate);
    printf("height        = %u\n", var.height);
    printf("width         = %u\n", var.width);
    printf("accel_flags   = 0x%x\n", var.accel_flags);
    printf("pixclock      = %u\n", var.pixclock);
    printf("left_margin   = %u\n", var.left_margin);
    printf("right_margin  = %u\n", var.right_margin);
    printf("upper_margin  = %u\n", var.upper_margin);
    printf("lower_margin  = %u\n", var.lower_margin);
    printf("hsync_len     = %u\n", var.hsync_len);
    printf("vsync_len     = %u\n", var.vsync_len);
    printf("sync          = 0x%x\n", var.sync);
    printf("vmode         = 0x%x\n", var.vmode);

    close(fd);
    return 0;
}
