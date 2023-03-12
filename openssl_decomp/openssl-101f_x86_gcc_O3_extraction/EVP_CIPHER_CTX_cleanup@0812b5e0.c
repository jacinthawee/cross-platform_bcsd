
int EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *a)

{
  _func_1091 *p_Var1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (a->cipher != (EVP_CIPHER *)0x0) {
    p_Var1 = a->cipher->cleanup;
    if ((p_Var1 != (_func_1091 *)0x0) && (iVar2 = (*p_Var1)(a), iVar2 == 0)) {
      return 0;
    }
    if (a->cipher_data == (void *)0x0) goto LAB_0812b62e;
    OPENSSL_cleanse(a->cipher_data,a->cipher->ctx_size);
  }
  if (a->cipher_data != (void *)0x0) {
    CRYPTO_free(a->cipher_data);
  }
LAB_0812b62e:
  if (a->engine != (ENGINE *)0x0) {
    ENGINE_finish(a->engine);
  }
  a->cipher = (EVP_CIPHER *)0x0;
  *(undefined4 *)(a->final + 0x1c) = 0;
  puVar4 = (undefined4 *)((uint)&a->engine & 0xfffffffc);
  uVar3 = (uint)((int)a + (0x8c - (int)puVar4)) >> 2;
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
  }
  return 1;
}

