
undefined4 hash_block(uint *param_1,void *param_2,uint param_3)

{
  void *pvVar1;
  uint uVar2;
  size_t __n;
  int iVar3;
  uint __n_00;
  void *pvVar4;
  int iVar5;
  void *local_20;
  
  uVar2 = param_1[3];
  if (uVar2 == 0) {
    local_20 = param_2;
  }
  else {
    __n_00 = 0x20 - uVar2;
    if (param_3 <= 0x20 - uVar2) {
      __n_00 = param_3;
    }
    memcpy((void *)((int)param_1 + uVar2 + 0x50),param_2,__n_00);
    uVar2 = param_1[3];
    param_1[3] = uVar2 + __n_00;
    if ((int)(uVar2 + __n_00) < 0x20) {
      return 1;
    }
    local_20 = (void *)(__n_00 + (int)param_2);
    hash_step();
    iVar3 = 0;
    iVar5 = 0;
    do {
      iVar3 = iVar3 + (uint)*(byte *)((int)param_1 + iVar5 + 0x50) +
                      (uint)*(byte *)((int)param_1 + iVar5 + 0x30);
      *(char *)((int)param_1 + iVar5 + 0x30) = (char)iVar3;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 >> 8;
    } while (iVar5 != 0x20);
    uVar2 = *param_1;
    *param_1 = *param_1 + 0x20;
    param_1[3] = 0;
    param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
  }
  pvVar1 = (void *)((int)param_2 + (param_3 - 0x20));
  pvVar4 = local_20;
  if (local_20 <= pvVar1) {
    do {
      iVar5 = 0;
      hash_step();
      iVar3 = 0;
      do {
        iVar3 = iVar3 + (uint)*(byte *)((int)pvVar4 + iVar5) +
                        (uint)*(byte *)((int)param_1 + iVar5 + 0x30);
        *(char *)((int)param_1 + iVar5 + 0x30) = (char)iVar3;
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 >> 8;
      } while (iVar5 != 0x20);
      uVar2 = *param_1;
      *param_1 = *param_1 + 0x20;
      param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
      pvVar4 = (void *)((int)pvVar4 + 0x20);
    } while (pvVar4 <= pvVar1);
    local_20 = (void *)((int)local_20 + ((int)pvVar1 - (int)local_20 & 0xffffffe0U) + 0x20);
  }
  if ((void *)((int)param_2 + param_3) != local_20) {
    __n = (int)(void *)((int)param_2 + param_3) - (int)local_20;
    param_1[3] = __n;
    memcpy(param_1 + 0x14,local_20,__n);
    return 1;
  }
  return 1;
}

