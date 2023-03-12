
int EVP_SignFinal(EVP_MD_CTX *ctx,uchar *md,uint *s,EVP_PKEY *pkey)

{
  EVP_MD *pEVar1;
  int iVar2;
  EVP_PKEY_CTX *ctx_00;
  int in_GS_OFFSET;
  int iVar3;
  uint local_80;
  uint local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  *s = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  iVar2 = EVP_MD_CTX_copy_ex(&local_78,ctx);
  if (iVar2 == 0) {
LAB_08130253:
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    iVar2 = 0;
  }
  else {
    iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_80);
    if (iVar2 == 0) goto LAB_08130253;
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
        iVar3 = 0x7f;
        iVar2 = 0x6e;
      }
      else {
        if (pEVar1->sign != (_func_1083 *)0x0) {
          iVar2 = (*pEVar1->sign)(pEVar1->type,local_60,local_80,md,s,(pkey->pkey).ptr);
          goto LAB_08130265;
        }
        iVar3 = 0x85;
        iVar2 = 0x68;
      }
      ERR_put_error(6,0x6b,iVar2,"p_sign.c",iVar3);
      iVar2 = 0;
      goto LAB_08130265;
    }
    local_7c = EVP_PKEY_size(pkey);
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_08130253;
    iVar2 = 0;
    iVar3 = EVP_PKEY_sign_init(ctx_00);
    if (0 < iVar3) {
      iVar3 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest);
      if (0 < iVar3) {
        iVar3 = EVP_PKEY_sign(ctx_00,md,&local_7c,local_60,local_80);
        if (0 < iVar3) {
          iVar2 = 1;
          *s = local_7c;
        }
      }
    }
  }
  EVP_PKEY_CTX_free(ctx_00);
LAB_08130265:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

