
undefined4 gost_cipher_init_cpa(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x60);
  gost_init(iVar2 + 0xc,PTR_Gost28147_CryptoProParamSetA_006aa9b0);
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 1;
  if (param_2 != 0) {
    gost_key(iVar2 + 0xc,param_2);
  }
  if (param_3 != 0) {
    uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1);
    (*(code *)PTR_memcpy_006aabf4)(param_1 + 0x10,param_3,uVar1);
  }
  uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1);
  (*(code *)PTR_memcpy_006aabf4)(param_1 + 0x20,param_1 + 0x10,uVar1);
  return 1;
}

