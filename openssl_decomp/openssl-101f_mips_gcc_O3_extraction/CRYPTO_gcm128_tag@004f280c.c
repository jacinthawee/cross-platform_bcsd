
void CRYPTO_gcm128_tag(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1 + 0x40;
  uVar2 = *(uint *)(param_1 + 0x34);
  uVar1 = *(uint *)(param_1 + 0x3c);
  iVar4 = *(int *)(param_1 + 0x30);
  iVar3 = *(int *)(param_1 + 0x38);
  if ((*(int *)(param_1 + 0x168) != 0) || (*(int *)(param_1 + 0x16c) != 0)) {
    gcm_gmult_4bit(iVar5,param_1 + 0x60);
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ (uVar2 >> 0x1d | iVar4 << 3);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ (uVar1 >> 0x1d | iVar3 << 3);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar2 << 3;
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ uVar1 << 3;
  gcm_gmult_4bit(iVar5,param_1 + 0x60);
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  uVar1 = 0x10;
  if (param_3 < 0x11) {
    uVar1 = param_3;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
                    /* WARNING: Could not recover jumptable at 0x004f2968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_memcpy_006aabf4)(param_2,iVar5,uVar1);
  return;
}

