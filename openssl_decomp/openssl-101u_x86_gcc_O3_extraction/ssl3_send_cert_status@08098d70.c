
undefined4 ssl3_send_cert_status(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) == 0x2200) {
    iVar3 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),*(int *)(param_1 + 0x13c) + 8);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 5;
      return 0xffffffff;
    }
    puVar1 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
    *puVar1 = 0x16;
    puVar1[1] = (char)((uint)(*(int *)(param_1 + 0x13c) + 4) >> 0x10);
    puVar1[2] = (char)((uint)(*(int *)(param_1 + 0x13c) + 4) >> 8);
    puVar1[3] = *(char *)(param_1 + 0x13c) + '\x04';
    puVar1[4] = (char)*(undefined4 *)(param_1 + 0x128);
    puVar1[5] = (char)*(undefined2 *)(param_1 + 0x13e);
    puVar1[6] = (char)((uint)*(undefined4 *)(param_1 + 0x13c) >> 8);
    puVar1[7] = (char)*(undefined4 *)(param_1 + 0x13c);
    memcpy(puVar1 + 8,*(void **)(param_1 + 0x138),*(size_t *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x34) = 0x2201;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x13c) + 8;
  }
  uVar2 = ssl3_do_write(param_1,0x16);
  return uVar2;
}

