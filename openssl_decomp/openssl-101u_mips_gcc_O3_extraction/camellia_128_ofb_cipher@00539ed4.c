
undefined4 camellia_128_ofb_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_res8;
  
  local_res8 = param_3;
  if (0x3fffffff < param_4) {
    iVar1 = param_3;
    uVar2 = param_4;
    iVar3 = param_2;
    do {
      uVar2 = uVar2 + 0xc0000000;
      (*(code *)PTR_Camellia_ofb128_encrypt_006a89f0)
                (iVar1,iVar3,0x40000000,*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,
                 param_1 + 0x50);
      iVar1 = iVar1 + 0x40000000;
      iVar3 = iVar3 + 0x40000000;
    } while (0x3fffffff < uVar2);
    uVar2 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = ((uVar2 >> 0x1e) + 1) * 0x40000000;
    local_res8 = param_3 + iVar1;
    param_2 = param_2 + iVar1;
  }
  if (param_4 != 0) {
    (*(code *)PTR_Camellia_ofb128_encrypt_006a89f0)
              (local_res8,param_2,param_4,*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,
               param_1 + 0x50);
  }
  return 1;
}

