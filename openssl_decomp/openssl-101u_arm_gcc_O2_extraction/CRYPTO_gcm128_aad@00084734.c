
undefined4 CRYPTO_gcm128_aad(int param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  
  pcVar2 = *(code **)(param_1 + 0x160);
  pcVar6 = *(code **)(param_1 + 0x164);
  if ((*(uint *)(param_1 + 0x38) | *(uint *)(param_1 + 0x3c)) != 0) {
    return 0xfffffffe;
  }
  iVar3 = *(uint *)(param_1 + 0x30) + param_3;
  uVar4 = *(int *)(param_1 + 0x34) + (uint)CARRY4(*(uint *)(param_1 + 0x30),param_3);
  bVar7 = 0x1fffffff < uVar4;
  if (uVar4 == 0x20000000) {
    bVar7 = iVar3 != 0;
  }
  if (bVar7) {
    return 0xffffffff;
  }
  uVar1 = *(uint *)(param_1 + 0x16c);
  *(int *)(param_1 + 0x30) = iVar3;
  *(uint *)(param_1 + 0x34) = uVar4;
  if (uVar1 != 0) {
    puVar5 = param_2;
    if (param_3 != 0) {
      do {
        iVar3 = param_1 + uVar1;
        uVar4 = uVar1 + 1 & 0xf;
        param_2 = (uint *)((int)puVar5 + 1);
        uVar1 = uVar1 + 1 & 0xf;
        if (uVar4 != 0) {
          uVar4 = 1;
        }
        param_3 = param_3 - 1;
        uVar4 = uVar4 & 1;
        if (param_3 == 0) {
          uVar4 = 0;
        }
        *(byte *)(iVar3 + 0x40) = *(byte *)(iVar3 + 0x40) ^ *(byte *)puVar5;
        puVar5 = param_2;
      } while (uVar4 != 0);
      if (uVar1 == 0) {
        (*pcVar2)(param_1 + 0x40,param_1 + 0x60);
        goto LAB_000847ba;
      }
    }
    *(uint *)(param_1 + 0x16c) = uVar1;
    return 0;
  }
LAB_000847ba:
  uVar4 = param_3 & 0xfffffff0;
  if (uVar4 != 0) {
    param_3 = param_3 - uVar4;
    param_2 = (uint *)((int)param_2 + uVar4);
    (*pcVar6)(param_1 + 0x40,param_1 + 0x60);
  }
  if (param_3 != 0) {
    bVar8 = param_2 <= (uint *)(param_1 + 0x44);
    bVar7 = (uint *)(param_1 + 0x44) == param_2;
    if (bVar8 && !bVar7) {
      bVar8 = (uint *)(param_1 + 0x40) <= param_2 + 1;
      bVar7 = param_2 + 1 == (uint *)(param_1 + 0x40);
    }
    if (5 >= param_3 || (((uint)param_2 & 3) != 0 || bVar8 && !bVar7)) {
      *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ *(byte *)param_2;
      if ((((((((1 < param_3) &&
               (*(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ *(byte *)((int)param_2 + 1),
               2 < param_3)) &&
              (*(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ *(byte *)((int)param_2 + 2),
              3 < param_3)) &&
             ((*(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ *(byte *)((int)param_2 + 3),
              4 < param_3 &&
              (*(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ *(byte *)(param_2 + 1),
              5 < param_3)))) &&
            ((*(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) ^ *(byte *)((int)param_2 + 5),
             6 < param_3 &&
             ((*(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) ^ *(byte *)((int)param_2 + 6),
              7 < param_3 &&
              (*(byte *)(param_1 + 0x47) = *(byte *)(param_1 + 0x47) ^ *(byte *)((int)param_2 + 7),
              8 < param_3)))))) &&
           (*(byte *)(param_1 + 0x48) = *(byte *)(param_1 + 0x48) ^ *(byte *)(param_2 + 2),
           9 < param_3)) &&
          (((*(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) ^ *(byte *)((int)param_2 + 9),
            10 < param_3 &&
            (*(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) ^ *(byte *)((int)param_2 + 10),
            0xb < param_3)) &&
           (*(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) ^ *(byte *)((int)param_2 + 0xb),
           0xc < param_3)))) &&
         (((*(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_2 + 3),
           0xd < param_3 &&
           (*(byte *)(param_1 + 0x4d) = *(byte *)(param_1 + 0x4d) ^ *(byte *)((int)param_2 + 0xd),
           0xe < param_3)) &&
          (*(byte *)(param_1 + 0x4e) = *(byte *)(param_1 + 0x4e) ^ *(byte *)((int)param_2 + 0xe),
          0xf < param_3)))) {
        *(byte *)(param_1 + 0x4f) = *(byte *)(param_1 + 0x4f) ^ *(byte *)((int)param_2 + 0xf);
      }
    }
    else {
      uVar1 = param_3 >> 2;
      uVar4 = param_3 & 0xfffffffc;
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *param_2;
      if (((1 < uVar1) &&
          (*(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ param_2[1], 2 < uVar1)) &&
         (*(uint *)(param_1 + 0x48) = param_2[2] ^ *(uint *)(param_1 + 0x48), 3 < uVar1)) {
        *(uint *)(param_1 + 0x4c) = param_2[3] ^ *(uint *)(param_1 + 0x4c);
      }
      if (param_3 != uVar4) {
        uVar1 = uVar4 + 1;
        *(byte *)(param_1 + uVar4 + 0x40) =
             *(byte *)(param_1 + uVar4 + 0x40) ^ *(byte *)((int)param_2 + (param_3 & 0xfffffffc));
        if (uVar1 < param_3) {
          uVar4 = uVar4 + 2;
          *(byte *)(param_1 + uVar1 + 0x40) =
               *(byte *)(param_1 + uVar1 + 0x40) ^ *(byte *)((int)param_2 + uVar1);
          if (uVar4 < param_3) {
            *(byte *)(param_1 + uVar4 + 0x40) =
                 *(byte *)(param_1 + uVar4 + 0x40) ^ *(byte *)((int)param_2 + uVar4);
          }
        }
      }
    }
  }
  *(uint *)(param_1 + 0x16c) = param_3;
  return 0;
}

