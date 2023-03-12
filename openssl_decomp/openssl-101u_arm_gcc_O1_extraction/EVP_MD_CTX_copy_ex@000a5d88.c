
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  int iVar1;
  ulong uVar2;
  size_t __n;
  void *pvVar3;
  EVP_PKEY_CTX *pEVar4;
  EVP_MD *pEVar5;
  ENGINE *pEVar6;
  _func_1081 *UNRECOVERED_JUMPTABLE;
  void *__dest;
  
  if ((in == (EVP_MD_CTX *)0x0) || (pEVar5 = in->digest, pEVar5 == (EVP_MD *)0x0)) {
    ERR_put_error(6,0x6e,0x6f,"digest.c",0x122);
    return 0;
  }
  if (in->engine != (ENGINE *)0x0) {
    iVar1 = ENGINE_init(in->engine);
    if (iVar1 == 0) {
      ERR_put_error(6,0x6e,0x26,"digest.c",0x128);
      return 0;
    }
    pEVar5 = in->digest;
  }
  if (out->digest == pEVar5) {
    __dest = out->md_data;
    EVP_MD_CTX_set_flags(out,4);
  }
  else {
    __dest = (void *)0x0;
  }
  EVP_MD_CTX_cleanup(out);
  pEVar6 = in->engine;
  uVar2 = in->flags;
  pvVar3 = in->md_data;
  out->digest = in->digest;
  out->engine = pEVar6;
  out->flags = uVar2;
  out->md_data = pvVar3;
  pEVar4 = in->pctx;
  out->update = in->update;
  out->pctx = pEVar4;
  if ((in->md_data != (void *)0x0) && (__n = out->digest->ctx_size, __n != 0)) {
    if (__dest == (void *)0x0) {
      __dest = CRYPTO_malloc(__n,"digest.c",0x139);
      out->md_data = __dest;
      if (__dest == (void *)0x0) {
        ERR_put_error(6,0x6e,0x41,"digest.c",0x13b);
        return 0;
      }
      __n = out->digest->ctx_size;
    }
    else {
      out->md_data = __dest;
    }
    memcpy(__dest,in->md_data,__n);
  }
  pEVar4 = in->pctx;
  out->update = in->update;
  if (pEVar4 != (EVP_PKEY_CTX *)0x0) {
    pEVar4 = EVP_PKEY_CTX_dup(pEVar4);
    out->pctx = pEVar4;
    if (pEVar4 == (EVP_PKEY_CTX *)0x0) {
      EVP_MD_CTX_cleanup(out);
      return 0;
    }
  }
  UNRECOVERED_JUMPTABLE = out->digest->copy;
  if (UNRECOVERED_JUMPTABLE != (_func_1081 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000a5e0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(out,in);
    return iVar1;
  }
  return 1;
}

