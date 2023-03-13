
long md_ctrl(BIO *param_1,int param_2,long param_3,EVP_MD *param_4)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  EVP_MD_CTX *ctx;
  bio_st *pbVar2;
  long lVar3;
  int iVar4;
  
  ctx = (EVP_MD_CTX *)param_1->ptr;
  if (param_2 == 0x6f) {
    lVar3 = EVP_DigestInit_ex(ctx,param_4,(ENGINE *)0x0);
    if (0 < lVar3) {
      param_1->init = 1;
    }
  }
  else if (param_2 < 0x70) {
    if (param_2 != 0xc) {
      if (param_2 == 0x65) {
        BIO_clear_flags(param_1,0xf);
        lVar3 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return lVar3;
      }
      if (param_2 == 1) {
        if (param_1->init == 0) {
          return 0;
        }
        iVar4 = EVP_DigestInit_ex(ctx,ctx->digest,(ENGINE *)0x0);
        if (iVar4 < 1) {
          return iVar4;
        }
        param_2 = 1;
      }
code_r0x081163e0:
      pbVar2 = param_1->next_bio;
      if (pbVar2 == (bio_st *)0x0) {
        return 0;
      }
      if ((pbVar2->method == (BIO_METHOD *)0x0) ||
         (UNRECOVERED_JUMPTABLE = pbVar2->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0))
      {
        ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
        lVar3 = -2;
      }
      else {
        p_Var1 = pbVar2->callback;
        if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08116477. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          lVar3 = (*UNRECOVERED_JUMPTABLE)(pbVar2,param_2,param_3,param_4);
          return lVar3;
        }
        lVar3 = (*p_Var1)(pbVar2,6,(char *)param_4,param_2,param_3,1);
        if (0 < lVar3) {
          lVar3 = (*pbVar2->method->ctrl)(pbVar2,param_2,param_3,param_4);
          lVar3 = (*p_Var1)(pbVar2,0x86,(char *)param_4,param_2,param_3,lVar3);
        }
      }
      return lVar3;
    }
    iVar4 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)param_4->cleanup,ctx);
    if (iVar4 == 0) {
      return 0;
    }
    param_1->init = 1;
    lVar3 = 1;
  }
  else {
    if (param_2 == 0x78) {
      param_4->type = (int)ctx;
      param_1->init = 1;
      return 1;
    }
    if (param_2 == 0x94) {
      if (param_1->init == 0) {
        return 0;
      }
      param_1->ptr = param_4;
      lVar3 = 1;
    }
    else {
      if (param_2 != 0x70) goto code_r0x081163e0;
      if (param_1->init == 0) {
        return 0;
      }
      param_4->type = (int)ctx->digest;
      lVar3 = 1;
    }
  }
  return lVar3;
}

