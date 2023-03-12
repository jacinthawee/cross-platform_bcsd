
long md_ctrl(BIO *param_1,int param_2,long param_3,EVP_MD *param_4)

{
  long lVar1;
  int iVar2;
  EVP_MD_CTX *ctx;
  BIO *pBVar3;
  _func_603 *p_Var4;
  _func_599 *UNRECOVERED_JUMPTABLE;
  
  ctx = (EVP_MD_CTX *)param_1->ptr;
  if (param_2 == 0x6f) {
    iVar2 = EVP_DigestInit_ex(ctx,param_4,(ENGINE *)0x0);
    if (iVar2 < 1) {
      return iVar2;
    }
    param_1->init = 1;
    return iVar2;
  }
  if (param_2 < 0x70) {
    if (param_2 == 0xc) {
      iVar2 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)param_4->cleanup,ctx);
      if (iVar2 == 0) {
        return 0;
      }
      param_1->init = 1;
      return 1;
    }
    if (param_2 == 0x65) {
      (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf,param_3,param_4,&_gp);
      lVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar1;
    }
    if (param_2 == 1) {
      if (param_1->init == 0) {
        return 0;
      }
      iVar2 = EVP_DigestInit_ex(ctx,ctx->digest,(ENGINE *)0x0);
      if (iVar2 < 1) {
        return iVar2;
      }
      pBVar3 = param_1->next_bio;
      param_2 = 1;
      goto code_r0x0051f3d0;
    }
  }
  else {
    if (param_2 == 0x78) {
      param_4->type = (int)ctx;
      param_1->init = 1;
      return 1;
    }
    if (param_2 == 0x94) {
      if (param_1->init != 0) {
        param_1->ptr = param_4;
        return 1;
      }
      return 0;
    }
    if (param_2 == 0x70) {
      if (param_1->init != 0) {
        param_4->type = (int)ctx->digest;
        return 1;
      }
      return 0;
    }
  }
  pBVar3 = param_1->next_bio;
code_r0x0051f3d0:
  if (pBVar3 == (BIO *)0x0) {
    return 0;
  }
  if ((pBVar3->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = pBVar3->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
    lVar1 = -2;
  }
  else {
    p_Var4 = pBVar3->callback;
    if (p_Var4 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0051f4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar1 = (*UNRECOVERED_JUMPTABLE)(pBVar3,param_2,param_3,param_4);
      return lVar1;
    }
    lVar1 = (*p_Var4)(pBVar3,6,(char *)param_4,param_2,param_3,1);
    if (0 < lVar1) {
      lVar1 = (*pBVar3->method->ctrl)(pBVar3,param_2,param_3,param_4);
      lVar1 = (*p_Var4)(pBVar3,0x86,(char *)param_4,param_2,param_3,lVar1);
    }
  }
  return lVar1;
}

