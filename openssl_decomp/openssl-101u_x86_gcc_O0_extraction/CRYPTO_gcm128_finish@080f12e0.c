
int CRYPTO_gcm128_finish(int param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = *(uint *)(param_1 + 0x30);
  uVar3 = *(int *)(param_1 + 0x34) << 3;
  uVar5 = uVar1 << 3;
  uVar2 = *(uint *)(param_1 + 0x38);
  uVar4 = *(int *)(param_1 + 0x3c) << 3;
  uVar6 = uVar2 << 3;
  if ((*(int *)(param_1 + 0x168) != 0) || (*(int *)(param_1 + 0x16c) != 0)) {
    gcm_gmult_4bit();
  }
  *(uint *)(param_1 + 0x40) =
       *(uint *)(param_1 + 0x40) ^
       (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
       (uVar3 | uVar1 >> 0x1d) << 0x18);
  *(uint *)(param_1 + 0x44) =
       *(uint *)(param_1 + 0x44) ^
       (uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar1 << 0x1b);
  *(uint *)(param_1 + 0x48) =
       *(uint *)(param_1 + 0x48) ^
       (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
       (uVar4 | uVar2 >> 0x1d) << 0x18);
  *(uint *)(param_1 + 0x4c) =
       *(uint *)(param_1 + 0x4c) ^
       (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar2 << 0x1b);
  gcm_gmult_4bit();
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  if ((param_2 != (void *)0x0) && (param_3 < 0x11)) {
    iVar7 = CRYPTO_memcmp((void *)(param_1 + 0x40),param_2,param_3);
    return iVar7;
  }
  return -1;
}

