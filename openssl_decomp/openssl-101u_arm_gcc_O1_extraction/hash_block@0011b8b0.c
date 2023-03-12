
undefined4 hash_block(uint *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  void *local_2c;
  
  uVar2 = param_1[3];
  local_2c = param_2;
  if (uVar2 != 0) {
    uVar4 = 0x20 - uVar2;
    if (param_3 <= 0x20 - uVar2) {
      uVar4 = param_3;
    }
    memcpy((void *)(uVar2 + 0x50 + (int)param_1),param_2,uVar4);
    uVar2 = param_1[3];
    param_1[3] = uVar2 + uVar4;
    if ((int)(uVar2 + uVar4) < 0x20) {
      return 1;
    }
    local_2c = (void *)((int)param_2 + uVar4);
    param_3 = param_3 - uVar4;
    hash_step(param_1[2],param_1 + 4,param_1 + 0x14);
    iVar1 = 0;
    iVar3 = 0;
    do {
      iVar1 = iVar1 + (uint)*(byte *)((int)(param_1 + 0x14) + iVar3) +
                      (uint)*(byte *)((int)param_1 + iVar3 + 0x30);
      *(char *)((int)param_1 + iVar3 + 0x30) = (char)iVar1;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 >> 8;
    } while (iVar3 != 0x20);
    uVar2 = *param_1;
    param_1[3] = 0;
    *param_1 = uVar2 + 0x20;
    param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
  }
  if (0x1f < param_3) {
    pvVar5 = local_2c;
    uVar2 = param_3;
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
      uVar4 = *param_1;
      uVar2 = uVar2 - 0x20;
      pvVar5 = (void *)((int)pvVar5 + 0x20);
      *param_1 = uVar4 + 0x20;
      param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar4);
    } while (0x1f < uVar2);
    uVar2 = param_3 - 0x20;
    param_3 = param_3 & 0x1f;
    local_2c = (void *)((int)local_2c + (uVar2 & 0xffffffe0) + 0x20);
  }
  if (param_3 == 0) {
    return 1;
  }
  param_1[3] = param_3;
  memcpy(param_1 + 0x14,local_2c,param_3);
  return 1;
}

