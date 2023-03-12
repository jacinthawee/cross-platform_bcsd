
undefined4 camellia_192_cbc_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (0x3fffffff < param_4) {
    iVar1 = param_3;
    iVar2 = param_2;
    uVar3 = param_4;
    do {
      uVar3 = uVar3 + 0xc0000000;
      (*(code *)PTR_Camellia_cbc_encrypt_006a7a48)
                (iVar1,iVar2,0x40000000,*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,
                 *(undefined4 *)(param_1 + 8));
      iVar1 = iVar1 + 0x40000000;
      iVar2 = iVar2 + 0x40000000;
    } while (0x3fffffff < uVar3);
    uVar3 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = ((uVar3 >> 0x1e) + 1) * 0x40000000;
    param_3 = param_3 + iVar1;
    param_2 = param_2 + iVar1;
  }
  if (param_4 != 0) {
    (*(code *)PTR_Camellia_cbc_encrypt_006a7a48)
              (param_3,param_2,param_4,*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,
               *(undefined4 *)(param_1 + 8));
  }
  return 1;
}

