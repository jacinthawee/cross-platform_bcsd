
undefined4 CRYPTO_gcm128_finish(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int local_30;
  
  uVar9 = *(uint *)(param_1 + 0x30);
  uVar7 = *(uint *)(param_1 + 0x38);
  uVar5 = *(int *)(param_1 + 0x34) << 3;
  pcVar2 = *(code **)(param_1 + 0x160);
  uVar3 = *(int *)(param_1 + 0x3c) << 3;
  uVar6 = uVar5 | uVar9 >> 0x1d;
  uVar4 = uVar3 | uVar7 >> 0x1d;
  iVar10 = param_1 + 0x40;
  if ((*(int *)(param_1 + 0x168) != 0) || (*(int *)(param_1 + 0x16c) != 0)) {
    (*pcVar2)(iVar10,param_1 + 0x60);
  }
  local_30 = param_1 + 0x60;
  *(uint *)(param_1 + 0x34) = uVar6;
  *(uint *)(param_1 + 0x30) = uVar9 << 3;
  *(uint *)(param_1 + 0x3c) = uVar4;
  *(uint *)(param_1 + 0x38) = uVar7 << 3;
  *(uint *)(param_1 + 0x40) =
       *(uint *)(param_1 + 0x40) ^
       (((uVar6 << 0x10) >> 0x18) << 0x10 | uVar6 << 0x18 | uVar5 >> 0x18 |
       ((uVar6 << 8) >> 0x18) << 8);
  *(uint *)(param_1 + 0x44) =
       *(uint *)(param_1 + 0x44) ^
       (((uVar9 << 0x13) >> 0x18) << 0x10 | uVar9 << 0x1b | (uVar9 << 3) >> 0x18 |
       ((uVar9 << 0xb) >> 0x18) << 8);
  *(uint *)(param_1 + 0x48) =
       *(uint *)(param_1 + 0x48) ^
       (((uVar4 << 0x10) >> 0x18) << 0x10 | uVar4 << 0x18 | uVar3 >> 0x18 |
       ((uVar4 << 8) >> 0x18) << 8);
  *(uint *)(param_1 + 0x4c) =
       *(uint *)(param_1 + 0x4c) ^
       (((uVar7 << 0x13) >> 0x18) << 0x10 | uVar7 << 0x1b | (uVar7 << 3) >> 0x18 |
       ((uVar7 << 0xb) >> 0x18) << 8);
  (*pcVar2)(iVar10,local_30);
  iVar8 = param_2;
  if (param_2 != 0) {
    iVar8 = 1;
  }
  if (0x10 < param_3) {
    iVar8 = 0;
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  if (iVar8 == 0) {
    return 0xffffffff;
  }
  uVar1 = (*(code *)PTR_memcmp_0018a06c)(iVar10,param_2,param_3);
  return uVar1;
}

