
undefined4 rc2_cfb64_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_4 < 0x40000000) {
    uVar2 = param_4;
    if (param_4 == 0) {
      return 1;
    }
  }
  else {
    uVar2 = 0x40000000;
  }
  do {
    uVar1 = param_4 - uVar2;
    iVar3 = param_3 + uVar2;
    (*(code *)PTR_RC2_cfb64_encrypt_006a9bb0)
              (param_3,param_2,param_4,*(int *)(param_1 + 0x60) + 4,param_1 + 0x20,param_1 + 0x50,
               *(undefined4 *)(param_1 + 8));
    param_2 = param_2 + uVar2;
    if (uVar1 < uVar2) {
      uVar2 = uVar1;
    }
  } while ((uVar1 != 0) && (param_4 = uVar1, param_3 = iVar3, uVar2 <= uVar1));
  return 1;
}

