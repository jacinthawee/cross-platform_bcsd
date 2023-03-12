
int EVP_VerifyFinal(EVP_MD_CTX *ctx,uchar *sigbuf,uint siglen,EVP_PKEY *pkey)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD *pEVar3;
  EVP_PKEY_CTX *ctx_00;
  code *UNRECOVERED_JUMPTABLE;
  uint local_80;
  EVP_MD_CTX EStack_7c;
  uchar auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  EVP_MD_CTX_init(&EStack_7c);
  iVar2 = EVP_MD_CTX_copy_ex(&EStack_7c,ctx);
  if (iVar2 == 0) {
LAB_005407fc:
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    iVar2 = 0;
  }
  else {
    iVar2 = EVP_DigestFinal_ex(&EStack_7c,auStack_64,&local_80);
    if (iVar2 == 0) goto LAB_005407fc;
    EVP_MD_CTX_cleanup(&EStack_7c);
    pEVar3 = ctx->digest;
    if ((pEVar3->flags & 4) == 0) {
      if ((pEVar3->required_pkey_type[0] == 0) ||
         ((iVar2 = pkey->type, pEVar3->required_pkey_type[0] != iVar2 &&
          ((pEVar3->required_pkey_type[1] == 0 ||
           ((iVar2 != pEVar3->required_pkey_type[1] &&
            ((pEVar3->required_pkey_type[2] == 0 ||
             ((iVar2 != pEVar3->required_pkey_type[2] &&
              ((pEVar3->required_pkey_type[3] == 0 || (pEVar3->required_pkey_type[3] != iVar2)))))))
            ))))))) {
        ERR_put_error(6,0x6c,0x6e,"p_verify.c",0x6d);
        iVar2 = -1;
      }
      else if (pEVar3->verify == (_func_1084 *)0x0) {
        ERR_put_error(6,0x6c,0x69,"p_verify.c",0x72);
        iVar2 = 0;
      }
      else {
        iVar2 = (*pEVar3->verify)(pEVar3->type,auStack_64,local_80,sigbuf,siglen,(pkey->pkey).ptr);
      }
      goto LAB_00540818;
    }
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if ((ctx_00 == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_verify_init(ctx_00), iVar2 < 1)) {
LAB_005409a8:
      iVar2 = -1;
    }
    else {
      iVar2 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest);
      if (iVar2 < 1) goto LAB_005409a8;
      iVar2 = EVP_PKEY_verify(ctx_00,sigbuf,siglen,auStack_64,local_80);
    }
  }
  EVP_PKEY_CTX_free(ctx_00);
LAB_00540818:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar2 + 0xc) + 0x34),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00540a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*UNRECOVERED_JUMPTABLE)();
    return iVar2;
  }
  return 0;
}

