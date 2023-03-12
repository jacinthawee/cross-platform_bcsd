
int EVP_VerifyFinal(EVP_MD_CTX *ctx,uchar *sigbuf,uint siglen,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_MD *pEVar2;
  EVP_PKEY_CTX *ctx_00;
  _func_1084 *p_Var3;
  uint local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  local_24 = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_7c);
  iVar1 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
  if ((iVar1 == 0) || (iVar1 = EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80), iVar1 == 0)) {
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    p_Var3 = (_func_1084 *)0x0;
  }
  else {
    EVP_MD_CTX_cleanup(&EStack_7c);
    pEVar2 = ctx->digest;
    if (-1 < (int)(pEVar2->flags << 0x1d)) {
      if ((pEVar2->required_pkey_type[0] == 0) ||
         ((iVar1 = pkey->type, iVar1 != pEVar2->required_pkey_type[0] &&
          ((pEVar2->required_pkey_type[1] == 0 ||
           ((iVar1 != pEVar2->required_pkey_type[1] &&
            ((pEVar2->required_pkey_type[2] == 0 ||
             ((iVar1 != pEVar2->required_pkey_type[2] &&
              ((pEVar2->required_pkey_type[3] == 0 || (pEVar2->required_pkey_type[3] != iVar1)))))))
            ))))))) {
        ERR_put_error(6,0x6c,0x6e,"p_verify.c",0x6a);
        p_Var3 = (_func_1084 *)0xffffffff;
      }
      else {
        p_Var3 = pEVar2->verify;
        if (p_Var3 == (_func_1084 *)0x0) {
          ERR_put_error(6,0x6c,0x69,"p_verify.c",0x6e);
        }
        else {
          p_Var3 = (_func_1084 *)
                   (*p_Var3)(pEVar2->type,auStack_64,local_80,sigbuf,siglen,(pkey->pkey).ptr);
        }
      }
      goto LAB_000aaf1e;
    }
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if ((ctx_00 != (EVP_PKEY_CTX *)0x0) && (iVar1 = EVP_PKEY_verify_init(ctx_00), 0 < iVar1)) {
      iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest);
      if (0 < iVar1) {
        p_Var3 = (_func_1084 *)EVP_PKEY_verify(ctx_00,sigbuf,siglen,auStack_64,local_80);
        goto LAB_000aaf16;
      }
    }
    p_Var3 = (_func_1084 *)0xffffffff;
  }
LAB_000aaf16:
  EVP_PKEY_CTX_free(ctx_00);
LAB_000aaf1e:
  if (local_24 == __stack_chk_guard) {
    return (int)p_Var3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

