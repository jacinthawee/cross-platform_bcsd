
void CRYPTO_gcm128_tag(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  
  iVar7 = param_1 + 0x40;
  uVar6 = *(uint *)(param_1 + 0x30);
  uVar5 = *(uint *)(param_1 + 0x38);
  uVar3 = *(int *)(param_1 + 0x34) << 3;
  uVar1 = *(int *)(param_1 + 0x3c) << 3;
  uVar4 = uVar3 | uVar6 >> 0x1d;
  uVar2 = uVar1 | uVar5 >> 0x1d;
  pcVar8 = *(code **)(param_1 + 0x160);
  if ((*(int *)(param_1 + 0x168) != 0) || (*(int *)(param_1 + 0x16c) != 0)) {
    (*pcVar8)(iVar7,param_1 + 0x60);
  }
  *(uint *)(param_1 + 0x34) = uVar4;
  *(uint *)(param_1 + 0x3c) = uVar2;
  *(uint *)(param_1 + 0x30) = uVar6 << 3;
  *(uint *)(param_1 + 0x38) = uVar5 << 3;
  *(uint *)(param_1 + 0x40) =
       *(uint *)(param_1 + 0x40) ^
       (((uVar4 << 0x10) >> 0x18) << 0x10 | uVar4 << 0x18 | uVar3 >> 0x18 |
       ((uVar4 << 8) >> 0x18) << 8);
  *(uint *)(param_1 + 0x44) =
       *(uint *)(param_1 + 0x44) ^
       (((uVar6 << 0x13) >> 0x18) << 0x10 | uVar6 << 0x1b | (uVar6 << 3) >> 0x18 |
       ((uVar6 << 0xb) >> 0x18) << 8);
  *(uint *)(param_1 + 0x48) =
       *(uint *)(param_1 + 0x48) ^
       (((uVar2 << 0x10) >> 0x18) << 0x10 | uVar2 << 0x18 | uVar1 >> 0x18 |
       ((uVar2 << 8) >> 0x18) << 8);
  *(uint *)(param_1 + 0x4c) =
       *(uint *)(param_1 + 0x4c) ^
       (((uVar5 << 0x13) >> 0x18) << 0x10 | uVar5 << 0x1b | (uVar5 << 3) >> 0x18 |
       ((uVar5 << 0xb) >> 0x18) << 8);
  (*pcVar8)(iVar7,param_1 + 0x60);
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  if (0xf < param_3) {
    param_3 = 0x10;
  }
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  (*(code *)PTR_memcpy_0018a054)(param_2,iVar7,param_3);
  return;
}

