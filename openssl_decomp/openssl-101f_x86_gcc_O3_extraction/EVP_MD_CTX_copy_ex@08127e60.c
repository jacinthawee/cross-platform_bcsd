
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  _func_1081 *UNRECOVERED_JUMPTABLE;
  int iVar1;
  size_t __n;
  EVP_PKEY_CTX *pEVar2;
  EVP_MD *pEVar3;
  void *__dest;
  int line;
  
  if ((in != (EVP_MD_CTX *)0x0) && (pEVar3 = in->digest, pEVar3 != (EVP_MD *)0x0)) {
    if (in->engine != (ENGINE *)0x0) {
      iVar1 = ENGINE_init(in->engine);
      if (iVar1 == 0) {
        ERR_put_error(6,0x6e,0x26,"digest.c",0x12f);
        return 0;
      }
      pEVar3 = in->digest;
    }
    __dest = (void *)0x0;
    if (out->digest == pEVar3) {
      __dest = out->md_data;
      EVP_MD_CTX_set_flags(out,4);
    }
    EVP_MD_CTX_cleanup(out);
    pEVar3 = in->digest;
    out->digest = pEVar3;
    out->engine = in->engine;
    out->flags = in->flags;
    out->md_data = in->md_data;
    out->pctx = in->pctx;
    out->update = in->update;
    if ((in->md_data != (void *)0x0) && (__n = pEVar3->ctx_size, __n != 0)) {
      if (__dest == (void *)0x0) {
        __dest = CRYPTO_malloc(__n,"digest.c",0x143);
        out->md_data = __dest;
        if (__dest == (void *)0x0) {
          line = 0x146;
          iVar1 = 0x41;
          goto LAB_08127f8f;
        }
        __n = out->digest->ctx_size;
      }
      else {
        out->md_data = __dest;
      }
      memcpy(__dest,in->md_data,__n);
    }
    out->update = in->update;
    if (in->pctx != (EVP_PKEY_CTX *)0x0) {
      pEVar2 = EVP_PKEY_CTX_dup(in->pctx);
      out->pctx = pEVar2;
      if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
        EVP_MD_CTX_cleanup(out);
        return 0;
      }
    }
    UNRECOVERED_JUMPTABLE = out->digest->copy;
    if (UNRECOVERED_JUMPTABLE == (_func_1081 *)0x0) {
      return 1;
    }
                    /* WARNING: Could not recover jumptable at 0x08127f39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(out,in);
    return iVar1;
  }
  line = 0x128;
  iVar1 = 0x6f;
LAB_08127f8f:
  ERR_put_error(6,0x6e,iVar1,"digest.c",line);
  return 0;
}

