
int EVP_MD_CTX_copy(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  _func_1081 *UNRECOVERED_JUMPTABLE;
  int iVar1;
  size_t __n;
  EVP_PKEY_CTX *pEVar2;
  uint uVar3;
  uint uVar4;
  EVP_MD *pEVar5;
  void *__dest;
  int line;
  
  uVar4 = 0;
  out->digest = (EVP_MD *)0x0;
  out->update = (_func_1088 *)0x0;
  uVar3 = (uint)&out->engine & 0xfffffffc;
  do {
    *(undefined4 *)(uVar3 + uVar4) = 0;
    uVar4 = uVar4 + 4;
  } while (uVar4 < ((int)out + (0x18 - uVar3) & 0xfffffffc));
  if ((in != (EVP_MD_CTX *)0x0) && (pEVar5 = in->digest, pEVar5 != (EVP_MD *)0x0)) {
    if (in->engine != (ENGINE *)0x0) {
      iVar1 = ENGINE_init(in->engine);
      if (iVar1 == 0) {
        ERR_put_error(6,0x6e,0x26,"digest.c",0x128);
        return 0;
      }
      pEVar5 = in->digest;
    }
    __dest = (void *)0x0;
    if (out->digest == pEVar5) {
      __dest = out->md_data;
      EVP_MD_CTX_set_flags(out,4);
    }
    EVP_MD_CTX_cleanup(out);
    pEVar5 = in->digest;
    out->digest = pEVar5;
    out->engine = in->engine;
    out->flags = in->flags;
    out->md_data = in->md_data;
    out->pctx = in->pctx;
    out->update = in->update;
    if ((in->md_data != (void *)0x0) && (__n = pEVar5->ctx_size, __n != 0)) {
      if (__dest == (void *)0x0) {
        __dest = CRYPTO_malloc(__n,"digest.c",0x139);
        out->md_data = __dest;
        if (__dest == (void *)0x0) {
          line = 0x13b;
          iVar1 = 0x41;
          goto LAB_0812585f;
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
                    /* WARNING: Could not recover jumptable at 0x08125836. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(out,in);
    return iVar1;
  }
  line = 0x122;
  iVar1 = 0x6f;
LAB_0812585f:
  ERR_put_error(6,0x6e,iVar1,"digest.c",line);
  return 0;
}

