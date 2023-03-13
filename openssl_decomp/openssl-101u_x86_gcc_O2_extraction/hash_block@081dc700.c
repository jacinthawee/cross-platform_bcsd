
undefined4 hash_block(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint local_24;
  
  uVar2 = param_1[3];
  if (uVar2 != 0) {
    uVar3 = 0x20 - uVar2;
    if (param_3 <= 0x20 - uVar2) {
      uVar3 = param_3;
    }
    memcpy((void *)((int)param_1 + uVar2 + 0x50),param_2,uVar3);
    uVar2 = param_1[3];
    param_1[3] = uVar2 + uVar3;
    if ((int)(uVar2 + uVar3) < 0x20) {
      return 1;
    }
    param_2 = (uint *)((int)param_2 + uVar3);
    param_3 = param_3 - uVar3;
    hash_step();
    iVar1 = 0;
    iVar4 = 0;
    do {
      iVar1 = iVar1 + (uint)*(byte *)((int)param_1 + iVar4 + 0x50) +
                      (uint)*(byte *)((int)param_1 + iVar4 + 0x30);
      *(char *)((int)param_1 + iVar4 + 0x30) = (char)iVar1;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 >> 8;
    } while (iVar4 != 0x20);
    uVar2 = *param_1;
    *param_1 = *param_1 + 0x20;
    param_1[3] = 0;
    param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
  }
  if (0x1f < param_3) {
    local_24 = param_3;
    puVar5 = param_2;
    do {
      iVar4 = 0;
      hash_step();
      iVar1 = 0;
      do {
        iVar1 = iVar1 + (uint)*(byte *)((int)puVar5 + iVar4) +
                        (uint)*(byte *)((int)param_1 + iVar4 + 0x30);
        *(char *)((int)param_1 + iVar4 + 0x30) = (char)iVar1;
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 >> 8;
      } while (iVar4 != 0x20);
      uVar2 = *param_1;
      *param_1 = *param_1 + 0x20;
      param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar2);
      puVar5 = puVar5 + 8;
      local_24 = local_24 - 0x20;
    } while (0x1f < local_24);
    param_2 = (uint *)((int)param_2 + (param_3 - 0x20 & 0xffffffe0) + 0x20);
    param_3 = param_3 & 0x1f;
  }
  if (param_3 != 0) {
    param_1[3] = param_3;
    if (param_3 < 4) {
      if ((param_3 != 0) &&
         (*(undefined *)(param_1 + 0x14) = *(undefined *)param_2, (param_3 & 2) != 0)) {
        *(undefined2 *)((int)param_1 + param_3 + 0x4e) =
             *(undefined2 *)((int)param_2 + (param_3 - 2));
      }
    }
    else {
      param_1[0x14] = *param_2;
      *(undefined4 *)((int)param_1 + param_3 + 0x4c) = *(undefined4 *)((int)param_2 + (param_3 - 4))
      ;
      iVar1 = (int)param_1 + (0x50 - ((uint)(param_1 + 0x15) & 0xfffffffc));
      uVar2 = iVar1 + param_3 & 0xfffffffc;
      if (3 < uVar2) {
        uVar3 = 0;
        do {
          *(undefined4 *)(((uint)(param_1 + 0x15) & 0xfffffffc) + uVar3) =
               *(undefined4 *)((int)param_2 + (uVar3 - iVar1));
          uVar3 = uVar3 + 4;
        } while (uVar3 < uVar2);
      }
    }
  }
  return 1;
}

