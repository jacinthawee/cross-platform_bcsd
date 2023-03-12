
undefined4 des_ede_ofb_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_res8;
  
  local_res8 = param_3;
  if (0x3fffffff < param_4) {
    uVar2 = param_4;
    iVar3 = param_2;
    iVar4 = param_3;
    do {
      iVar1 = *(int *)(param_1 + 0x60);
      uVar2 = uVar2 + 0xc0000000;
      (*(code *)PTR_DES_ede3_ofb64_encrypt_006a89e0)
                (iVar4,iVar3,0x40000000,iVar1,iVar1 + 0x80,iVar1 + 0x100,param_1 + 0x20,
                 param_1 + 0x50);
      iVar4 = iVar4 + 0x40000000;
      iVar3 = iVar3 + 0x40000000;
    } while (0x3fffffff < uVar2);
    uVar2 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar3 = ((uVar2 >> 0x1e) + 1) * 0x40000000;
    local_res8 = param_3 + iVar3;
    param_2 = param_2 + iVar3;
  }
  if (param_4 != 0) {
    iVar3 = *(int *)(param_1 + 0x60);
    (*(code *)PTR_DES_ede3_ofb64_encrypt_006a89e0)
              (local_res8,param_2,param_4,iVar3,iVar3 + 0x80,iVar3 + 0x100,param_1 + 0x20,
               param_1 + 0x50);
  }
  return 1;
}

