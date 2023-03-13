
undefined4 gost_cipher_do_cfb(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_2c;
  
  uVar6 = *(uint *)(param_1 + 0x50);
  if (uVar6 == 0) {
    uVar6 = 8;
    local_2c = 0;
  }
  else {
    if ((uVar6 < 8) && (param_4 != 0)) {
      iVar5 = *(int *)(param_1 + 8);
      pbVar4 = (byte *)(param_1 + 0x38 + uVar6);
      local_2c = 0;
      do {
        if (iVar5 == 0) {
          *pbVar4 = *(byte *)param_3;
        }
        bVar2 = pbVar4[-8];
        bVar1 = *(byte *)param_3;
        *(byte *)param_2 = bVar2 ^ bVar1;
        iVar5 = *(int *)(param_1 + 8);
        if (iVar5 != 0) {
          *pbVar4 = bVar2 ^ bVar1;
        }
        uVar6 = uVar6 + 1;
        local_2c = local_2c + 1;
        param_3 = (uint *)((int)param_3 + 1);
        param_2 = (uint *)((int)param_2 + 1);
        pbVar4 = pbVar4 + 1;
      } while ((uVar6 < 8) && (local_2c < param_4));
    }
    else {
      local_2c = 0;
    }
    if (uVar6 != 8) {
      *(uint *)(param_1 + 0x50) = uVar6;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x3c);
    uVar6 = local_2c + 8;
  }
  while (uVar7 = uVar6, uVar7 < param_4) {
    iVar5 = *(int *)(param_1 + 0x60);
    if ((*(int *)(iVar5 + 8) != 0) && (*(int *)(iVar5 + 4) == 0x400)) {
      cryptopro_key_meshing(iVar5 + 0xc,param_1 + 0x20);
    }
    gostcrypt(iVar5 + 0xc,param_1 + 0x20,param_1 + 0x30);
    iVar3 = *(int *)(param_1 + 8);
    *(uint *)(iVar5 + 4) = (*(uint *)(iVar5 + 4) & 0x3ff) + 8;
    if (iVar3 == 0) {
      uVar6 = param_3[1];
      *(uint *)(param_1 + 0x20) = *param_3;
      *(uint *)(param_1 + 0x24) = uVar6;
    }
    *(byte *)param_2 = *(byte *)(param_1 + 0x30) ^ *(byte *)param_3;
    *(byte *)((int)param_2 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)param_3 + 1);
    *(byte *)((int)param_2 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)param_3 + 2);
    *(byte *)((int)param_2 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)param_3 + 3);
    *(byte *)(param_2 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(param_3 + 1);
    *(byte *)((int)param_2 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)param_3 + 5);
    *(byte *)((int)param_2 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)param_3 + 6);
    *(byte *)((int)param_2 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)param_3 + 7);
    if (*(int *)(param_1 + 8) != 0) {
      uVar6 = param_2[1];
      *(uint *)(param_1 + 0x20) = *param_2;
      *(uint *)(param_1 + 0x24) = uVar6;
    }
    param_3 = param_3 + 2;
    param_2 = param_2 + 2;
    local_2c = uVar7;
    uVar6 = uVar7 + 8;
  }
  if (param_4 <= local_2c) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 1;
  }
  iVar5 = *(int *)(param_1 + 0x60);
  if ((*(int *)(iVar5 + 8) != 0) && (*(int *)(iVar5 + 4) == 0x400)) {
    cryptopro_key_meshing(iVar5 + 0xc,param_1 + 0x20);
  }
  gostcrypt(iVar5 + 0xc,param_1 + 0x20,(uint *)(param_1 + 0x30U));
  *(uint *)(iVar5 + 4) = (*(uint *)(iVar5 + 4) & 0x3ff) + 8;
  if (*(int *)(param_1 + 8) == 0) {
    memcpy((void *)(param_1 + 0x38),param_3,param_4 - local_2c);
  }
  uVar6 = param_4 - local_2c;
  if (((param_2 < param_3 + 1 && param_3 < param_2 + 1 ||
       (uint *)(param_1 + 0x30U) < param_2 + 1 && param_2 < (uint *)(param_1 + 0x34U)) || uVar6 < 7)
     || ((((uint)param_2 | (uint)param_3) & 3) != 0)) {
    *(byte *)param_2 = *(byte *)(param_1 + 0x30) ^ *(byte *)param_3;
    if ((((local_2c + 1 < param_4) &&
         ((((*(byte *)((int)param_2 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)param_3 + 1),
            local_2c + 2 < param_4 &&
            (*(byte *)((int)param_2 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)param_3 + 2),
            local_2c + 3 < param_4)) &&
           (*(byte *)((int)param_2 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)param_3 + 3),
           local_2c + 4 < param_4)) &&
          ((*(byte *)(param_2 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(param_3 + 1),
           local_2c + 5 < param_4 &&
           (*(byte *)((int)param_2 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)param_3 + 5),
           local_2c + 6 < param_4)))))) &&
        (*(byte *)((int)param_2 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)param_3 + 6),
        local_2c + 7 < param_4)) &&
       (*(byte *)((int)param_2 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)param_3 + 7),
       local_2c + 8 < param_4)) {
      *(byte *)(param_2 + 2) = *(byte *)(param_1 + 0x38) ^ *(byte *)(param_3 + 2);
    }
  }
  else {
    iVar5 = (uVar6 - 4 >> 2) + 1;
    uVar7 = iVar5 * 4;
    if ((param_4 - 1) - local_2c < 3) {
      uVar7 = 0;
    }
    else {
      *param_2 = *param_3 ^ *(uint *)(param_1 + 0x30);
      if ((iVar5 != 1) && (param_2[1] = *(uint *)(param_1 + 0x34) ^ param_3[1], iVar5 != 2)) {
        param_2[2] = *(uint *)(param_1 + 0x38) ^ param_3[2];
      }
      local_2c = local_2c + uVar7;
      if (uVar6 == uVar7) goto LAB_081dab60;
    }
    *(byte *)((int)param_2 + uVar7) =
         *(byte *)((int)param_3 + uVar7) ^ *(byte *)(param_1 + 0x30 + uVar7);
    if (local_2c + 1 < param_4) {
      *(byte *)((int)param_2 + uVar7 + 1) =
           *(byte *)((int)param_3 + uVar7 + 1) ^ *(byte *)(param_1 + 0x31 + uVar7);
      if (local_2c + 2 < param_4) {
        *(byte *)((int)param_2 + uVar7 + 2) =
             *(byte *)((int)param_3 + uVar7 + 2) ^ *(byte *)(param_1 + uVar7 + 0x32);
      }
    }
  }
LAB_081dab60:
  *(uint *)(param_1 + 0x50) = uVar6;
  if (*(int *)(param_1 + 8) != 0) {
    memcpy((void *)(param_1 + 0x38),param_2,uVar6);
  }
  return 1;
}

