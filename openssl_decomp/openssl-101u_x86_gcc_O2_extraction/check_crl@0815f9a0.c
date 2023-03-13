
bool check_crl(X509_STORE_CTX *param_1,X509_CRL *param_2)

{
  ASN1_TIME *s;
  X509_VERIFY_PARAM *pXVar1;
  _STACK *p_Var2;
  _STACK *p_Var3;
  int iVar4;
  time_t *ptVar5;
  int iVar6;
  EVP_PKEY *r;
  X509 *x;
  uint uVar7;
  X509 *a;
  X509 *b;
  time_t *t;
  int in_GS_OFFSET;
  bool bVar8;
  uint local_b4;
  X509_STORE_CTX local_a8;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = param_1->error_depth;
  iVar4 = sk_num((_STACK *)param_1->chain);
  x = param_1->current_issuer;
  if (x == (X509 *)0x0) {
    if (iVar6 < iVar4 + -1) {
      x = (X509 *)sk_value((_STACK *)param_1->chain,iVar6 + 1);
LAB_0815fb7f:
      r = (EVP_PKEY *)0x0;
      bVar8 = true;
      if (x == (X509 *)0x0) goto LAB_0815faaf;
      goto LAB_0815f9e0;
    }
    x = (X509 *)sk_value((_STACK *)param_1->chain,iVar4 + -1);
    iVar6 = (*param_1->check_issued)(param_1,x,x);
    if (iVar6 != 0) goto LAB_0815fb7f;
    param_1->error = 0x21;
    iVar6 = (*param_1->verify_cb)(0,param_1);
    if (iVar6 != 0) goto LAB_0815fb7f;
LAB_0815fb10:
    bVar8 = false;
    r = (EVP_PKEY *)0x0;
  }
  else {
LAB_0815f9e0:
    if (param_2->base_crl_number == (ASN1_INTEGER *)0x0) {
      if (((*(byte *)&x->ex_flags & 2) != 0) && ((*(byte *)&x->ex_kusage & 2) == 0)) {
        param_1->error = 0x23;
        iVar6 = (*param_1->verify_cb)(0,param_1);
        if (iVar6 == 0) goto LAB_0815fb10;
      }
      uVar7 = param_1->current_crl_score;
      if ((uVar7 & 0x80) == 0) {
        param_1->error = (int)&DAT_0000002c;
        iVar6 = (*param_1->verify_cb)(0,param_1);
        if (iVar6 == 0) goto LAB_0815fb10;
        uVar7 = param_1->current_crl_score;
      }
      if ((uVar7 & 8) == 0) {
        if (param_1->parent == (X509_STORE_CTX *)0x0) {
          iVar6 = X509_STORE_CTX_init(&local_a8,param_1->ctx,param_1->current_issuer,
                                      param_1->untrusted);
          if (iVar6 != 0) {
            local_a8.crls = param_1->crls;
            pXVar1 = param_1->param;
            if (local_a8.param != (X509_VERIFY_PARAM *)0x0) {
              X509_VERIFY_PARAM_free(local_a8.param);
            }
            local_a8.verify_cb = param_1->verify_cb;
            local_a8.parent = param_1;
            local_a8.param = pXVar1;
            local_b4 = X509_verify_cert(&local_a8);
            p_Var3 = &(local_a8.chain)->stack;
            if (0 < (int)local_b4) {
              p_Var2 = (_STACK *)param_1->chain;
              iVar6 = sk_num(p_Var2);
              a = (X509 *)sk_value(p_Var2,iVar6 + -1);
              iVar6 = sk_num(p_Var3);
              b = (X509 *)sk_value(p_Var3,iVar6 + -1);
              iVar6 = X509_cmp(a,b);
              local_b4 = (uint)(iVar6 == 0);
            }
            if (local_a8.cleanup != (_func_1866 *)0x0) {
              (*local_a8.cleanup)(&local_a8);
              local_a8.cleanup = (_func_1866 *)0x0;
            }
            if (local_a8.param != (X509_VERIFY_PARAM *)0x0) {
              if (local_a8.parent == (X509_STORE_CTX *)0x0) {
                X509_VERIFY_PARAM_free(local_a8.param);
              }
              local_a8.param = (X509_VERIFY_PARAM *)0x0;
            }
            if (local_a8.tree != (X509_POLICY_TREE *)0x0) {
              X509_policy_tree_free(local_a8.tree);
              local_a8.tree = (X509_POLICY_TREE *)0x0;
            }
            if (&(local_a8.chain)->stack != (_STACK *)0x0) {
              sk_pop_free(&(local_a8.chain)->stack,X509_free);
              local_a8.chain = (stack_st_X509 *)0x0;
            }
            CRYPTO_free_ex_data(5,&local_a8,&local_a8.ex_data);
            if (local_b4 == 1) goto LAB_0815fbc3;
          }
        }
        param_1->error = 0x36;
        iVar6 = (*param_1->verify_cb)(0,param_1);
        if (iVar6 == 0) goto LAB_0815fb10;
      }
LAB_0815fbc3:
      if ((*(byte *)&param_2->idp_flags & 2) != 0) {
        param_1->error = 0x29;
        iVar6 = (*param_1->verify_cb)(0,param_1);
        if (iVar6 == 0) goto LAB_0815fb10;
      }
    }
    ptVar5 = (time_t *)(param_1->current_crl_score & 0x40);
    if (ptVar5 == (time_t *)0x0) {
      param_1->current_crl = param_2;
      t = &param_1->param->check_time;
      if ((*(byte *)&param_1->param->flags & 2) == 0) {
        t = ptVar5;
      }
      iVar6 = X509_cmp_time(param_2->crl->lastUpdate,t);
      if (iVar6 == 0) {
        param_1->error = (int)&DAT_0000000f;
LAB_0815fa28:
        iVar6 = (*param_1->verify_cb)(0,param_1);
        if (iVar6 == 0) goto LAB_0815fb10;
      }
      else if (0 < iVar6) {
        param_1->error = 0xb;
        goto LAB_0815fa28;
      }
      s = param_2->crl->nextUpdate;
      if (s != (ASN1_TIME *)0x0) {
        iVar6 = X509_cmp_time(s,t);
        if (iVar6 == 0) {
          param_1->error = (int)&DAT_00000010;
        }
        else {
          if ((-1 < iVar6) || ((*(byte *)&param_1->current_crl_score & 2) != 0)) goto LAB_0815fa75;
          param_1->error = (int)&DAT_0000000c;
        }
        iVar6 = (*param_1->verify_cb)(0,param_1);
        if (iVar6 == 0) goto LAB_0815fb10;
      }
LAB_0815fa75:
      param_1->current_crl = (X509_CRL *)0x0;
    }
    r = X509_get_pubkey(x);
    if (r == (EVP_PKEY *)0x0) {
      param_1->error = 6;
    }
    else {
      iVar6 = X509_CRL_verify(param_2,r);
      bVar8 = true;
      if (0 < iVar6) goto LAB_0815faaf;
      param_1->error = (int)&DAT_00000008;
    }
    iVar6 = (*param_1->verify_cb)(0,param_1);
    bVar8 = iVar6 != 0;
  }
LAB_0815faaf:
  EVP_PKEY_free(r);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar8;
}

