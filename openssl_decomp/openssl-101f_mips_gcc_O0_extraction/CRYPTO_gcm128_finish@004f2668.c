
undefined4 CRYPTO_gcm128_finish(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = param_1 + 0x40;
  uVar3 = *(uint *)(param_1 + 0x34);
  uVar1 = *(uint *)(param_1 + 0x3c);
  iVar6 = *(int *)(param_1 + 0x30);
  iVar5 = *(int *)(param_1 + 0x38);
  if ((*(int *)(param_1 + 0x168) == 0) && (*(int *)(param_1 + 0x16c) == 0)) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  else {
    gcm_gmult_4bit(iVar7,param_1 + 0x60);
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  *(uint *)(param_1 + 0x40) = uVar4 ^ (uVar3 >> 0x1d | iVar6 << 3);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ (uVar1 >> 0x1d | iVar5 << 3);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar3 << 3;
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ uVar1 << 3;
  gcm_gmult_4bit(iVar7,param_1 + 0x60);
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  if ((param_2 != 0) && (param_3 < 0x11)) {
                    /* WARNING: Could not recover jumptable at 0x004f27bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_memcmp_006aabd8)(iVar7,param_2,param_3);
    return uVar2;
  }
  return 0xffffffff;
}

