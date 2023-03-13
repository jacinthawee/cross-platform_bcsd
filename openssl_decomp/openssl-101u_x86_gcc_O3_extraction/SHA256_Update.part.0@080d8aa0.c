
void __regparm3 SHA256_Update_part_0(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  void *__src;
  size_t __n;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  uVar2 = *(uint *)(param_1 + 0x20) + param_3 * 8;
  iVar1 = *(int *)(param_1 + 0x24);
  if (uVar2 < *(uint *)(param_1 + 0x20)) {
    iVar1 = iVar1 + 1;
  }
  *(uint *)(param_1 + 0x20) = uVar2;
  *(uint *)(param_1 + 0x24) = iVar1 + (param_3 >> 0x1d);
  iVar1 = *(int *)(param_1 + 0x68);
  __src = param_2;
  if (iVar1 != 0) {
    if ((param_3 < 0x40) && (param_3 + iVar1 < 0x40)) {
      memcpy((void *)(iVar1 + param_1 + 0x28),param_2,param_3);
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + param_3;
      return;
    }
    __n = 0x40 - iVar1;
    param_3 = param_3 - __n;
    __src = (void *)((int)param_2 + __n);
    puVar3 = (undefined4 *)(param_1 + 0x2cU & 0xfffffffc);
    memcpy((void *)(iVar1 + param_1 + 0x28),param_2,__n);
    sha256_block_data_order();
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    uVar2 = (param_1 - (int)puVar3) + 0x68U >> 2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  if (param_3 >> 6 != 0) {
    __src = (void *)((int)__src + (param_3 & 0xffffffc0));
    param_3 = param_3 - (param_3 & 0xffffffc0);
    sha256_block_data_order();
  }
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x68) = param_3;
    memcpy((void *)(param_1 + 0x28),__src,param_3);
  }
  return;
}

