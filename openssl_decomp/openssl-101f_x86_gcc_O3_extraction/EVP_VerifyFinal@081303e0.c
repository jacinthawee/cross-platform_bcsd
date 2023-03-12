
int EVP_VerifyFinal(EVP_MD_CTX *ctx,uchar *sigbuf,uint siglen,EVP_PKEY *pkey)

{
  EVP_MD *pEVar1;
  int iVar2;
  int iVar3;
  EVP_PKEY_CTX *ctx_00;
  int in_GS_OFFSET;
  uint local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  iVar2 = EVP_MD_CTX_copy_ex(&local_78,ctx);
  if (iVar2 == 0) {
LAB_08130443:
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    iVar2 = 0;
  }
  else {
    iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
    if (iVar2 == 0) goto LAB_08130443;
    EVP_MD_CTX_cleanup(&local_78);
    pEVar1 = ctx->digest;
    if ((*(byte *)&pEVar1->flags & 4) == 0) {
      if ((pEVar1->required_pkey_type[0] == 0) ||
         ((iVar2 = pkey->type, pEVar1->required_pkey_type[0] != iVar2 &&
          ((pEVar1->required_pkey_type[1] == 0 ||
           ((iVar2 != pEVar1->required_pkey_type[1] &&
            ((pEVar1->required_pkey_type[2] == 0 ||
             ((iVar2 != pEVar1->required_pkey_type[2] &&
              ((pEVar1->required_pkey_type[3] == 0 || (pEVar1->required_pkey_type[3] != iVar2)))))))
            ))))))) {
        ERR_put_error(6,0x6c,0x6e,"p_verify.c",0x6d);
        iVar2 = -1;
      }
      else if (pEVar1->verify == (_func_1084 *)0x0) {
        ERR_put_error(6,0x6c,0x69,"p_verify.c",0x72);
        iVar2 = 0;
      }
      else {
        iVar2 = (*pEVar1->verify)(pEVar1->type,local_60,local_7c,sigbuf,siglen,(pkey->pkey).ptr);
      }
      goto LAB_08130455;
    }
    iVar2 = -1;
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) {
      iVar3 = EVP_PKEY_verify_init(ctx_00);
      if (0 < iVar3) {
        iVar3 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest);
        if (0 < iVar3) {
          iVar2 = EVP_PKEY_verify(ctx_00,sigbuf,siglen,local_60,local_7c);
        }
      }
    }
  }
  EVP_PKEY_CTX_free(ctx_00);
LAB_08130455:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

