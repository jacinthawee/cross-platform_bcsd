
undefined4 gost_cipher_init_cpa(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  void *pvVar1;
  size_t sVar2;
  
  pvVar1 = param_1->cipher_data;
  gost_init((int)pvVar1 + 0xc,Gost28147_CryptoProParamSetA);
  *(undefined4 *)((int)pvVar1 + 8) = 1;
  *(undefined4 *)((int)pvVar1 + 4) = 0;
  if (param_2 != 0) {
    gost_key((int)pvVar1 + 0xc,param_2);
  }
  if (param_3 != (void *)0x0) {
    sVar2 = EVP_CIPHER_CTX_iv_length(param_1);
    memcpy(param_1->oiv,param_3,sVar2);
  }
  sVar2 = EVP_CIPHER_CTX_iv_length(param_1);
  memcpy(param_1->iv,param_1->oiv,sVar2);
  return 1;
}

