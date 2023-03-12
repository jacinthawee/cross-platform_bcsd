
int EVP_SignFinal(EVP_MD_CTX *ctx,uchar *md,uint *s,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_MD *pEVar2;
  uchar *tbs;
  EVP_PKEY_CTX *ctx_00;
  _func_1083 *p_Var3;
  uint local_84;
  uchar *local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  local_24 = __stack_chk_guard;
  p_Var3 = (_func_1083 *)0x0;
  *s = 0;
  EVP_MD_CTX_init(&EStack_7c);
  iVar1 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
  if ((iVar1 == 0) || (iVar1 = EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_84), iVar1 == 0)) {
LAB_000aadec:
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    p_Var3 = (_func_1083 *)0x0;
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
        ERR_put_error(6,0x6b,0x6e,"p_sign.c",0x7b);
        p_Var3 = (_func_1083 *)0x0;
      }
      else {
        p_Var3 = pEVar2->sign;
        if (p_Var3 == (_func_1083 *)0x0) {
          ERR_put_error(6,0x6b,0x68,"p_sign.c",0x80);
        }
        else {
          p_Var3 = (_func_1083 *)(*p_Var3)(pEVar2->type,auStack_64,local_84,md,s,(pkey->pkey).ptr);
        }
      }
      goto LAB_000aadf8;
    }
    local_80 = (uchar *)EVP_PKEY_size(pkey);
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_000aadec;
    iVar1 = EVP_PKEY_sign_init(ctx_00);
    if ((0 < iVar1) && (iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest), 0 < iVar1)) {
      tbs = auStack_64;
      iVar1 = EVP_PKEY_sign(ctx_00,md,(size_t *)&local_80,tbs,local_84);
      if (0 < iVar1) {
        tbs = local_80;
      }
      p_Var3 = (_func_1083 *)(uint)(0 < iVar1);
      if (0 < iVar1) {
        *s = (uint)tbs;
      }
    }
  }
  EVP_PKEY_CTX_free(ctx_00);
LAB_000aadf8:
  if (local_24 == __stack_chk_guard) {
    return (int)p_Var3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

