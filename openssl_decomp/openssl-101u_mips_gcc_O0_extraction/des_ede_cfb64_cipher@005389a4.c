
undefined4 des_ede_cfb64_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_res8;
  
  local_res8 = param_3;
  if (0x3fffffff < param_4) {
    iVar2 = param_2;
    iVar3 = param_3;
    uVar4 = param_4;
    do {
      iVar1 = *(int *)(param_1 + 0x60);
      uVar4 = uVar4 + 0xc0000000;
      (*(code *)PTR_DES_ede3_cfb64_encrypt_006a89dc)
                (iVar3,iVar2,0x40000000,iVar1,iVar1 + 0x80,iVar1 + 0x100,param_1 + 0x20,
                 param_1 + 0x50,*(undefined4 *)(param_1 + 8));
      iVar3 = iVar3 + 0x40000000;
      iVar2 = iVar2 + 0x40000000;
    } while (0x3fffffff < uVar4);
    uVar4 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar2 = ((uVar4 >> 0x1e) + 1) * 0x40000000;
    local_res8 = param_3 + iVar2;
    param_2 = param_2 + iVar2;
  }
  if (param_4 != 0) {
    iVar2 = *(int *)(param_1 + 0x60);
    (*(code *)PTR_DES_ede3_cfb64_encrypt_006a89dc)
              (local_res8,param_2,param_4,iVar2,iVar2 + 0x80,iVar2 + 0x100,param_1 + 0x20,
               param_1 + 0x50,*(undefined4 *)(param_1 + 8));
  }
  return 1;
}

