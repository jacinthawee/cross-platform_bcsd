
undefined4 hash_block(uint *param_1,void *param_2,uint param_3)

{
  int iVar1;
  size_t __n;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  uint __n_00;
  void *__src;
  void *pvVar5;
  
  uVar2 = param_1[3];
  __src = param_2;
  if (uVar2 != 0) {
    __n_00 = 0x20 - uVar2;
    if (param_3 <= 0x20 - uVar2) {
      __n_00 = param_3;
    }
    memcpy((void *)(uVar2 + 0x50 + (int)param_1),param_2,__n_00);
    uVar2 = param_1[3];
    param_1[3] = uVar2 + __n_00;
    if ((int)(uVar2 + __n_00) < 0x20) {
      return 1;
    }
    hash_step(param_1[2],param_1 + 4,param_1 + 0x14);
    iVar1 = 0;
    iVar3 = 0;
    do {
      iVar1 = iVar1 + (uint)*(byte *)((int)param_1 + iVar3 + 0x30) +
                      (uint)*(byte *)((int)(param_1 + 0x14) + iVar3);
      *(char *)((int)param_1 + iVar3 + 0x30) = (char)iVar1;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 >> 8;
    } while (iVar3 != 0x20);
    uVar2 = *param_1;
    param_1[3] = 0;
    *param_1 = uVar2 + 0x20;
    param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
    __src = (void *)(__n_00 + (int)param_2);
  }
  pvVar4 = (void *)((param_3 - 0x20) + (int)param_2);
  if (__src <= pvVar4) {
    pvVar5 = __src;
    do {
      hash_step(param_1[2],param_1 + 4,pvVar5);
      iVar1 = 0;
      iVar3 = 0;
      do {
        iVar1 = iVar1 + (uint)*(byte *)((int)pvVar5 + iVar3) +
                        (uint)*(byte *)((int)param_1 + iVar3 + 0x30);
        *(char *)((int)param_1 + iVar3 + 0x30) = (char)iVar1;
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 >> 8;
      } while (iVar3 != 0x20);
      uVar2 = *param_1;
      pvVar5 = (void *)((int)pvVar5 + 0x20);
      *param_1 = uVar2 + 0x20;
      param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
    } while (pvVar5 <= pvVar4);
    __src = (void *)((int)__src + ((int)pvVar4 - (int)__src & 0xffffffe0U) + 0x20);
  }
  if ((void *)(param_3 + (int)param_2) == __src) {
    return 1;
  }
  __n = (int)(void *)(param_3 + (int)param_2) - (int)__src;
  param_1[3] = __n;
  memcpy(param_1 + 0x14,__src,__n);
  return 1;
}

