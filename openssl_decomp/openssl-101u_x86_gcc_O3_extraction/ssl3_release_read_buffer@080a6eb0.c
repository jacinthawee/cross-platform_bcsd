
undefined4 ssl3_release_read_buffer(int param_1)

{
  int mode;
  uint *ptr;
  int iVar1;
  uint uVar2;
  uint *mode_00;
  uint uVar3;
  
  mode = *(int *)(param_1 + 0x58);
  ptr = *(uint **)(mode + 0xec);
  if (ptr != (uint *)0x0) {
    iVar1 = *(int *)(param_1 + 0xe4);
    uVar2 = *(uint *)(mode + 0xf0);
    CRYPTO_lock(mode,9,&DAT_0000000c,(int)"s3_both.c");
    mode_00 = *(uint **)(iVar1 + 0x160);
    if (((mode_00 == (uint *)0x0) ||
        (((uVar2 != *mode_00 && (*mode_00 != 0)) ||
         (uVar3 = mode_00[1], *(uint *)(iVar1 + 0x158) <= uVar3)))) || (uVar2 < 4)) {
      CRYPTO_lock((int)mode_00,10,&DAT_0000000c,(int)"s3_both.c");
      CRYPTO_free(ptr);
    }
    else {
      *mode_00 = uVar2;
      *ptr = mode_00[2];
      mode_00[2] = (uint)ptr;
      mode_00[1] = uVar3 + 1;
      CRYPTO_lock((int)mode_00,10,&DAT_0000000c,(int)"s3_both.c");
    }
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xec) = 0;
  }
  return 1;
}

