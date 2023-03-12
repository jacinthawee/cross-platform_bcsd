
int check_crl(X509_STORE_CTX *param_1,X509_CRL *param_2)

{
  _STACK *p_Var1;
  int iVar2;
  X509 *a;
  X509 *b;
  uint uVar3;
  X509 *x;
  int iVar4;
  X509_VERIFY_PARAM *pXVar5;
  _STACK *p_Var6;
  X509_STORE_CTX XStack_a0;
  
  iVar4 = param_1->error_depth;
  iVar2 = sk_num((_STACK *)param_1->chain);
  x = param_1->current_issuer;
  if (x == (X509 *)0x0) {
    if (iVar4 < iVar2 + -1) {
      x = (X509 *)sk_value((_STACK *)param_1->chain,iVar4 + 1);
    }
    else {
      x = (X509 *)sk_value((_STACK *)param_1->chain,iVar2 + -1);
      iVar2 = (*param_1->check_issued)(param_1,x,x);
      if (iVar2 == 0) {
        param_1->error = 0x21;
        iVar2 = (*param_1->verify_cb)(0,param_1);
        if (iVar2 == 0) goto LAB_000cb7ca;
      }
    }
    if (x == (X509 *)0x0) goto LAB_000cb7ac;
  }
  if (param_2->base_crl_number == (ASN1_INTEGER *)0x0) {
    if (((int)(x->ex_flags << 0x1e) < 0) && ((x->ex_kusage & 2) == 0)) {
      param_1->error = 0x23;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 == 0) goto LAB_000cb7ca;
    }
    uVar3 = param_1->current_crl_score;
    if ((uVar3 & 0x80) == 0) {
      param_1->error = 0x2c;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 == 0) goto LAB_000cb7ca;
      uVar3 = param_1->current_crl_score;
    }
    if (-1 < (int)(uVar3 << 0x1c)) {
      if ((param_1->parent == (X509_STORE_CTX *)0x0) &&
         (iVar2 = X509_STORE_CTX_init(&XStack_a0,param_1->ctx,param_1->current_issuer,
                                      param_1->untrusted), iVar2 != 0)) {
        XStack_a0.crls = param_1->crls;
        pXVar5 = param_1->param;
        if (XStack_a0.param != (X509_VERIFY_PARAM *)0x0) {
          X509_VERIFY_PARAM_free(XStack_a0.param);
        }
        XStack_a0.verify_cb = param_1->verify_cb;
        XStack_a0.param = pXVar5;
        XStack_a0.parent = param_1;
        uVar3 = X509_verify_cert(&XStack_a0);
        p_Var1 = &(XStack_a0.chain)->stack;
        if (0 < (int)uVar3) {
          p_Var6 = (_STACK *)param_1->chain;
          iVar2 = sk_num(p_Var6);
          a = (X509 *)sk_value(p_Var6,iVar2 + -1);
          iVar2 = sk_num(p_Var1);
          b = (X509 *)sk_value(p_Var1,iVar2 + -1);
          iVar2 = X509_cmp(a,b);
          uVar3 = count_leading_zeroes(iVar2);
          uVar3 = uVar3 >> 5;
        }
        if (XStack_a0.cleanup != (_func_1866 *)0x0) {
          (*XStack_a0.cleanup)(&XStack_a0);
        }
        if (XStack_a0.param != (X509_VERIFY_PARAM *)0x0) {
          if (XStack_a0.parent == (X509_STORE_CTX *)0x0) {
            X509_VERIFY_PARAM_free(XStack_a0.param);
          }
          XStack_a0.param = (X509_VERIFY_PARAM *)0x0;
        }
        if (XStack_a0.tree != (X509_POLICY_TREE *)0x0) {
          X509_policy_tree_free(XStack_a0.tree);
          XStack_a0.tree = (X509_POLICY_TREE *)0x0;
        }
        if (&(XStack_a0.chain)->stack != (_STACK *)0x0) {
          sk_pop_free(&(XStack_a0.chain)->stack,X509_free + 1);
          XStack_a0.chain = (stack_st_X509 *)0x0;
        }
        CRYPTO_free_ex_data(5,&XStack_a0,&XStack_a0.ex_data);
        XStack_a0.ex_data.dummy = 0;
        XStack_a0.ex_data.sk = (stack_st_void *)0x0;
        if (uVar3 == 1) goto LAB_000cb82c;
      }
      param_1->error = 0x36;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 == 0) goto LAB_000cb7ca;
    }
LAB_000cb82c:
    if (param_2->idp_flags << 0x1e < 0) {
      param_1->error = 0x29;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 == 0) goto LAB_000cb7ca;
    }
  }
  if ((param_1->current_crl_score << 0x19 < 0) ||
     (iVar2 = check_crl_time(param_1,param_2,1), iVar2 != 0)) {
    x = (X509 *)X509_get_pubkey(x);
    if (x == (X509 *)0x0) {
      param_1->error = 6;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      EVP_PKEY_free((EVP_PKEY *)0x0);
      return iVar2;
    }
    iVar2 = X509_CRL_verify(param_2,(EVP_PKEY *)x);
    if (iVar2 < 1) {
      param_1->error = (int)&DAT_00000008;
      iVar2 = (*param_1->verify_cb)(0,param_1);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      EVP_PKEY_free((EVP_PKEY *)x);
      return iVar2;
    }
LAB_000cb7ac:
    EVP_PKEY_free((EVP_PKEY *)x);
    return 1;
  }
LAB_000cb7ca:
  EVP_PKEY_free((EVP_PKEY *)0x0);
  return 0;
}

