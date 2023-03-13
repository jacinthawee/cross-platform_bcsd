
undefined4 enc_new(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10e4,"bio_enc.c",0x73,param_4,&_gp)
  ;
  if (puVar1 != (undefined4 *)0x0) {
    EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)(puVar1 + 5));
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 1;
    puVar1[3] = 0;
    puVar1[4] = 1;
    *(undefined4 **)(param_1 + 0x20) = puVar1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

