
bool aes_xts_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if ((((*(int *)(iVar1 + 0x1e8) == 0) || (*(int *)(iVar1 + 0x1ec) == 0)) ||
      (param_2 == 0 || param_3 == 0)) || (param_4 < 0x10)) {
    bVar2 = false;
  }
  else {
    if (*(code **)(iVar1 + 0x1f8) != (code *)0x0) {
      (**(code **)(iVar1 + 0x1f8))
                (param_3,param_2,param_4,*(int *)(iVar1 + 0x1e8),*(int *)(iVar1 + 0x1ec),
                 param_1 + 0x20);
      return true;
    }
    iVar1 = CRYPTO_xts128_encrypt
                      (iVar1 + 0x1e8,param_1 + 0x20,param_3,param_2,param_4,
                       *(undefined4 *)(param_1 + 8));
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

