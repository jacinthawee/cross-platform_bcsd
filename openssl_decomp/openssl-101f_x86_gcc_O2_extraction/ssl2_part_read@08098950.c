
int ssl2_part_read(int param_1,int param_2,int param_3)

{
  char *__dest;
  uint uVar1;
  size_t __n;
  int reason;
  
  if (-1 < param_3) {
    param_3 = param_3 + *(int *)(param_1 + 0x44);
    *(int *)(param_1 + 0x44) = param_3;
    if ((2 < param_3) && (__dest = *(char **)(*(int *)(param_1 + 0x3c) + 4), *__dest == '\0')) {
      reason = 0xfd;
      uVar1 = (ushort)(*(ushort *)(__dest + 1) << 8 | *(ushort *)(__dest + 1) >> 8) - 1;
      if (uVar1 < 6) {
        reason = *(int *)(CSWTCH_22 + uVar1 * 4);
      }
      ERR_put_error(0x14,param_2,reason,"s2_pkt.c",0x2a9);
      __n = *(int *)(param_1 + 0x44) - 3;
      *(size_t *)(param_1 + 0x44) = __n;
      if (0 < (int)__n) {
        memmove(__dest,__dest + 3,__n);
      }
    }
    param_3 = 0;
  }
  return param_3;
}

