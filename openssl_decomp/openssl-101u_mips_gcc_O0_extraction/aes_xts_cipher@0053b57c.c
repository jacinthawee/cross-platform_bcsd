
bool aes_xts_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x60);
  if ((((*(int *)(iVar2 + 0x1e8) != 0) && (*(int *)(iVar2 + 0x1ec) != 0)) && (param_2 != 0)) &&
     ((param_3 != 0 && (0xf < param_4)))) {
    if (*(code **)(iVar2 + 0x1f8) == (code *)0x0) {
      iVar2 = (*(code *)PTR_CRYPTO_xts128_encrypt_006a8a3c)
                        (iVar2 + 0x1e8,param_1 + 0x20,param_3,param_2,param_4,
                         *(undefined4 *)(param_1 + 8),&_gp);
      bVar1 = iVar2 == 0;
    }
    else {
      (**(code **)(iVar2 + 0x1f8))
                (param_3,param_2,param_4,*(int *)(iVar2 + 0x1e8),*(int *)(iVar2 + 0x1ec),
                 param_1 + 0x20);
      bVar1 = true;
    }
    return bVar1;
  }
  return false;
}

