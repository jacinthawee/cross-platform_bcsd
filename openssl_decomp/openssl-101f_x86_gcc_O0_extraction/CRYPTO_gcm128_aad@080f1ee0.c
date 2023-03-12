
undefined4 CRYPTO_gcm128_aad(int param_1,uint *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  if ((*(uint *)(param_1 + 0x3c) | *(uint *)(param_1 + 0x38)) != 0) {
    return 0xfffffffe;
  }
  iVar2 = *(uint *)(param_1 + 0x30) + param_3;
  uVar5 = *(int *)(param_1 + 0x34) + (uint)CARRY4(*(uint *)(param_1 + 0x30),param_3);
  if ((0x20000000 < uVar5) || ((0x1fffffff < uVar5 && (iVar2 != 0)))) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x30) = iVar2;
  uVar3 = *(uint *)(param_1 + 0x16c);
  *(uint *)(param_1 + 0x34) = uVar5;
  if (uVar3 != 0) {
    puVar6 = param_2;
    if (param_3 == 0) {
LAB_080f1f66:
      *(uint *)(param_1 + 0x16c) = uVar3;
      return 0;
    }
    do {
      param_2 = (uint *)((int)puVar6 + 1);
      param_3 = param_3 - 1;
      pbVar1 = (byte *)(param_1 + 0x40 + uVar3);
      *pbVar1 = *pbVar1 ^ *(byte *)puVar6;
      uVar3 = uVar3 + 1 & 0xf;
      if (uVar3 == 0) break;
      puVar6 = param_2;
    } while (param_3 != 0);
    if (uVar3 != 0) goto LAB_080f1f66;
    gcm_gmult_4bit();
  }
  uVar5 = param_3 & 0xfffffff0;
  if (uVar5 == 0) {
    if (param_3 == 0) {
LAB_080f2050:
      param_3 = 0;
      goto LAB_080f2052;
    }
  }
  else {
    gcm_ghash_4bit(uVar5);
    param_3 = param_3 - uVar5;
    if (param_3 == 0) goto LAB_080f2050;
    param_2 = (uint *)((int)param_2 + uVar5);
  }
  if ((param_2 < (uint *)(param_1 + 0x44U) && (uint *)(param_1 + 0x40) < param_2 + 1 || param_3 < 6)
     || (((uint)param_2 & 3) != 0)) {
    *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ *(byte *)param_2;
    if (((param_3 != 1) &&
        ((((*(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ *(byte *)((int)param_2 + 1),
           param_3 != 2 &&
           (*(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ *(byte *)((int)param_2 + 2),
           param_3 != 3)) &&
          (*(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ *(byte *)((int)param_2 + 3),
          param_3 != 4)) &&
         ((*(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ *(byte *)(param_2 + 1),
          5 < param_3 &&
          (*(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) ^ *(byte *)((int)param_2 + 5),
          6 < param_3)))))) &&
       ((*(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) ^ *(byte *)((int)param_2 + 6),
        param_3 != 7 &&
        ((((*(byte *)(param_1 + 0x47) = *(byte *)(param_1 + 0x47) ^ *(byte *)((int)param_2 + 7),
           param_3 != 8 &&
           (*(byte *)(param_1 + 0x48) = *(byte *)(param_1 + 0x48) ^ *(byte *)(param_2 + 2),
           param_3 != 9)) &&
          ((*(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) ^ *(byte *)((int)param_2 + 9),
           param_3 != 10 &&
           (((*(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) ^ *(byte *)((int)param_2 + 10),
             param_3 != 0xb &&
             (*(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) ^ *(byte *)((int)param_2 + 0xb),
             param_3 != 0xc)) &&
            (*(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_2 + 3),
            param_3 != 0xd)))))) &&
         ((*(byte *)(param_1 + 0x4d) = *(byte *)(param_1 + 0x4d) ^ *(byte *)((int)param_2 + 0xd),
          param_3 != 0xe &&
          (*(byte *)(param_1 + 0x4e) = *(byte *)(param_1 + 0x4e) ^ *(byte *)((int)param_2 + 0xe),
          param_3 != 0xf)))))))) {
      *(byte *)(param_1 + 0x4f) = *(byte *)(param_1 + 0x4f) ^ *(byte *)((int)param_2 + 0xf);
    }
  }
  else {
    uVar5 = 1;
    if (param_3 != 0) {
      uVar5 = param_3;
    }
    iVar4 = (uVar5 - 4 >> 2) + 1;
    iVar2 = iVar4 * 4;
    if (param_3 < 4) {
      iVar2 = 0;
    }
    else {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *param_2;
      if (((iVar4 != 1) &&
          (*(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ param_2[1], iVar4 != 2)) &&
         (*(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ param_2[2], iVar4 != 3)) {
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ param_2[3];
      }
      if (iVar2 - uVar5 == 0) goto LAB_080f2052;
    }
    pbVar1 = (byte *)(param_1 + 0x40 + iVar2);
    *pbVar1 = *pbVar1 ^ *(byte *)((int)param_2 + iVar2);
    if (iVar2 + 1U < param_3) {
      pbVar1 = (byte *)(param_1 + 0x40 + iVar2 + 1U);
      *pbVar1 = *pbVar1 ^ *(byte *)((int)param_2 + iVar2 + 1);
      if (iVar2 + 2U < param_3) {
        pbVar1 = (byte *)(param_1 + 0x40 + iVar2 + 2U);
        *pbVar1 = *pbVar1 ^ *(byte *)((int)param_2 + iVar2 + 2);
      }
    }
  }
LAB_080f2052:
  *(uint *)(param_1 + 0x16c) = param_3;
  return 0;
}

