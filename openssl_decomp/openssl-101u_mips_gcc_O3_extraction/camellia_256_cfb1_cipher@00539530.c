
undefined4 camellia_256_cfb1_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_4 < 0x8000000) {
    uVar2 = param_4;
    if (param_4 == 0) {
      return 1;
    }
  }
  else {
    uVar2 = 0x8000000;
  }
  do {
    uVar1 = param_4;
    if ((*(uint *)(param_1 + 0x5c) & 0x2000) == 0) {
      uVar1 = param_4 << 3;
    }
    param_4 = param_4 - uVar2;
    iVar4 = param_3 + uVar2;
    iVar3 = param_2 + uVar2;
    (*(code *)PTR_Camellia_cfb1_encrypt_006a89f8)
              (param_3,param_2,uVar1,*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x50,
               *(undefined4 *)(param_1 + 8));
    if (param_4 < uVar2) {
      uVar2 = param_4;
    }
  } while ((param_4 != 0) && (param_2 = iVar3, param_3 = iVar4, uVar2 <= param_4));
  return 1;
}

