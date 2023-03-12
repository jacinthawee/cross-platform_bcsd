
int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out,EVP_CIPHER_CTX *in)

{
  _func_1091 *p_Var1;
  int iVar2;
  void *__dest;
  uint uVar3;
  EVP_CIPHER *pEVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte bVar7;
  int line;
  
  bVar7 = 0;
  if ((in == (EVP_CIPHER_CTX *)0x0) || (in->cipher == (EVP_CIPHER *)0x0)) {
    line = 0x28b;
    iVar2 = 0x6f;
    goto LAB_0812ba3f;
  }
  if (in->engine != (ENGINE *)0x0) {
    iVar2 = ENGINE_init(in->engine);
    if (iVar2 == 0) {
      ERR_put_error(6,0xa3,0x26,"evp_enc.c",0x292);
      return 0;
    }
  }
  if (out->cipher == (EVP_CIPHER *)0x0) {
LAB_0812b912:
    if (out->cipher_data != (void *)0x0) {
      CRYPTO_free(out->cipher_data);
    }
LAB_0812b925:
    if (out->engine != (ENGINE *)0x0) {
      ENGINE_finish(out->engine);
    }
    out->cipher = (EVP_CIPHER *)0x0;
    *(undefined4 *)(out->final + 0x1c) = 0;
    puVar5 = (undefined4 *)((uint)&out->engine & 0xfffffffc);
    uVar3 = (uint)((int)out + (0x8c - (int)puVar5)) >> 2;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
    }
  }
  else {
    p_Var1 = out->cipher->cleanup;
    if (p_Var1 == (_func_1091 *)0x0) {
LAB_0812b8fa:
      if (out->cipher_data != (void *)0x0) {
        OPENSSL_cleanse(out->cipher_data,out->cipher->ctx_size);
        goto LAB_0812b912;
      }
      goto LAB_0812b925;
    }
    iVar2 = (*p_Var1)(out);
    if (iVar2 != 0) goto LAB_0812b8fa;
  }
  puVar6 = (undefined4 *)((uint)&out->engine & 0xfffffffc);
  iVar2 = (int)out - (int)puVar6;
  out->cipher = in->cipher;
  *(undefined4 *)(out->final + 0x1c) = *(undefined4 *)(in->final + 0x1c);
  puVar5 = (undefined4 *)((int)in - iVar2);
  for (uVar3 = iVar2 + 0x8cU >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
    puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
  }
  pEVar4 = in->cipher;
  if ((in->cipher_data != (void *)0x0) && (pEVar4->ctx_size != 0)) {
    __dest = CRYPTO_malloc(pEVar4->ctx_size,"evp_enc.c",0x29c);
    out->cipher_data = __dest;
    if (__dest == (void *)0x0) {
      line = 0x29f;
      iVar2 = 0x41;
LAB_0812ba3f:
      ERR_put_error(6,0xa3,iVar2,"evp_enc.c",line);
      return 0;
    }
    memcpy(__dest,in->cipher_data,in->cipher->ctx_size);
    pEVar4 = in->cipher;
  }
  iVar2 = 1;
  if ((*(byte *)((int)&pEVar4->flags + 1) & 4) != 0) {
    iVar2 = (*pEVar4->ctrl)(in,8,0,out);
  }
  return iVar2;
}

