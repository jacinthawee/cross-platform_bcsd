
undefined4 CRYPTO_gcm128_aad(int param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((*(uint *)(param_1 + 0x38) | *(uint *)(param_1 + 0x3c)) != 0) {
    return 0xfffffffe;
  }
  uVar4 = param_3 + *(int *)(param_1 + 0x34);
  uVar2 = (uint)(uVar4 < param_3) + *(int *)(param_1 + 0x30);
  if ((0x20000000 < uVar2) || ((uVar2 == 0x20000000 && (uVar4 != 0)))) {
    return 0xffffffff;
  }
  uVar1 = *(uint *)(param_1 + 0x16c);
  *(uint *)(param_1 + 0x30) = uVar2;
  *(uint *)(param_1 + 0x34) = uVar4;
  if (uVar1 != 0) {
    if (param_3 == 0) {
LAB_004ed638:
      *(uint *)(param_1 + 0x16c) = uVar1;
      return 0;
    }
    param_3 = param_3 - 1;
    *(byte *)(param_1 + uVar1 + 0x40) = *(byte *)(param_1 + uVar1 + 0x40) ^ *(byte *)param_2;
    param_2 = (uint *)((int)param_2 + 1);
    while (uVar1 = uVar1 + 1 & 0xf, uVar1 != 0) {
      if (param_3 == 0) goto LAB_004ed638;
      param_3 = param_3 - 1;
      *(byte *)(param_1 + uVar1 + 0x40) = *(byte *)param_2 ^ *(byte *)(param_1 + uVar1 + 0x40);
      param_2 = (uint *)((int)param_2 + 1);
    }
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar2 = param_3 & 0xfffffff0;
  if (uVar2 != 0) {
    param_3 = param_3 - uVar2;
    gcm_ghash_4bit((uint *)(param_1 + 0x40),param_1 + 0x60,param_2,uVar2);
    param_2 = (uint *)((int)param_2 + uVar2);
  }
  if (param_3 == 0) {
    param_3 = 0;
  }
  else if ((param_3 < 6 ||
            (uint *)(param_1 + 0x40) < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44)) ||
          (((uint)param_2 & 3) != 0)) {
    *(byte *)(param_1 + 0x40) = *(byte *)param_2 ^ *(byte *)(param_1 + 0x40);
    if (((param_3 != 1) &&
        ((((*(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ *(byte *)((int)param_2 + 1),
           param_3 != 2 &&
           (*(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ *(byte *)((int)param_2 + 2),
           param_3 != 3)) &&
          (*(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ *(byte *)((int)param_2 + 3),
          param_3 != 4)) &&
         ((*(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ *(byte *)(param_2 + 1),
          param_3 >= 6 &&
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
    uVar2 = 1;
    if (param_3 != 0) {
      uVar2 = param_3;
    }
    iVar3 = (uVar2 - 4 >> 2) + 1;
    uVar4 = iVar3 * 4;
    if (param_3 < 4) {
      uVar4 = 0;
    }
    else {
      *(uint *)(param_1 + 0x40) = *param_2 ^ *(uint *)(param_1 + 0x40);
      if (((iVar3 != 1) &&
          (*(uint *)(param_1 + 0x44) = param_2[1] ^ *(uint *)(param_1 + 0x44), iVar3 != 2)) &&
         (*(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ param_2[2], iVar3 != 3)) {
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ param_2[3];
      }
      if (uVar2 == uVar4) goto LAB_004ed608;
    }
    uVar2 = uVar4 + 1;
    *(byte *)(param_1 + uVar4 + 0x40) =
         *(byte *)((int)param_2 + uVar4) ^ *(byte *)(param_1 + uVar4 + 0x40);
    if (uVar2 < param_3) {
      uVar4 = uVar4 + 2;
      *(byte *)(param_1 + uVar2 + 0x40) =
           *(byte *)((int)param_2 + uVar2) ^ *(byte *)(param_1 + uVar2 + 0x40);
      if (uVar4 < param_3) {
        *(byte *)(param_1 + uVar4 + 0x40) =
             *(byte *)((int)param_2 + uVar4) ^ *(byte *)(param_1 + uVar4 + 0x40);
      }
    }
  }
LAB_004ed608:
  *(uint *)(param_1 + 0x16c) = param_3;
  return 0;
}

