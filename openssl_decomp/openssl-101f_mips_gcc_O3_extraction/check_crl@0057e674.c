
code * check_crl(X509_STORE_CTX *param_1,X509_CRL *param_2)

{
  undefined *puVar1;
  stack_st_X509 *psVar2;
  int iVar3;
  uint uVar4;
  X509 *a;
  X509 *b;
  ASN1_TIME *s;
  X509_STORE_CTX *pXVar5;
  code *pcVar6;
  X509_STORE_CTX *pXVar7;
  int iVar8;
  time_t *t;
  X509_VERIFY_PARAM *pXVar9;
  stack_st_X509 *psVar10;
  undefined auStack_ac [136];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar8 = param_1->error_depth;
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_1->chain);
  pXVar7 = (X509_STORE_CTX *)param_1->current_issuer;
  if (pXVar7 == (X509_STORE_CTX *)0x0) {
    if (iVar8 < iVar3 + -1) {
      pXVar5 = (X509_STORE_CTX *)(iVar8 + 1);
      pXVar7 = (X509_STORE_CTX *)(*(code *)PTR_sk_value_006a7f24)(param_1->chain);
    }
    else {
      pXVar7 = (X509_STORE_CTX *)(*(code *)PTR_sk_value_006a7f24)(param_1->chain);
      pXVar5 = pXVar7;
      iVar3 = (*param_1->check_issued)(param_1,(X509 *)pXVar7,(X509 *)pXVar7);
      if (iVar3 == 0) {
        param_1->error = 0x21;
        pXVar5 = param_1;
        iVar3 = (*param_1->verify_cb)(0,param_1);
        if (iVar3 == 0) {
          pcVar6 = (code *)0x0;
          pXVar7 = (X509_STORE_CTX *)0x0;
          goto LAB_0057e7c0;
        }
      }
    }
    if (pXVar7 == (X509_STORE_CTX *)0x0) {
      pcVar6 = (code *)0x1;
      pXVar7 = (X509_STORE_CTX *)0x0;
      goto LAB_0057e7c0;
    }
  }
  if (param_2->base_crl_number == (ASN1_INTEGER *)0x0) {
    if ((((uint)pXVar7->check_issued & 2) != 0) && (((uint)pXVar7->check_revocation & 2) == 0)) {
      param_1->error = 0x23;
      pXVar5 = param_1;
      iVar3 = (*param_1->verify_cb)(0,param_1);
      if (iVar3 == 0) {
        pcVar6 = (code *)0x0;
        pXVar7 = (X509_STORE_CTX *)0x0;
        goto LAB_0057e7c0;
      }
    }
    uVar4 = param_1->current_crl_score;
    if ((uVar4 & 0x80) != 0) {
LAB_0057e8c4:
      if ((uVar4 & 8) == 0) {
        if ((param_1->parent == (X509_STORE_CTX *)0x0) &&
           (iVar3 = X509_STORE_CTX_init((X509_STORE_CTX *)auStack_ac,param_1->ctx,
                                        param_1->current_issuer,param_1->untrusted), iVar3 != 0)) {
          auStack_ac._16_4_ = param_1->crls;
          pXVar9 = param_1->param;
          if (auStack_ac._20_4_ != (X509_VERIFY_PARAM *)0x0) {
            X509_VERIFY_PARAM_free(auStack_ac._20_4_);
          }
          auStack_ac._32_4_ = param_1->verify_cb;
          auStack_ac._20_4_ = pXVar9;
          auStack_ac._124_4_ = param_1;
          uVar4 = X509_verify_cert((X509_STORE_CTX *)auStack_ac);
          psVar2 = auStack_ac._84_4_;
          if (0 < (int)uVar4) {
            psVar10 = param_1->chain;
            iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar10);
            a = (X509 *)(*(code *)PTR_sk_value_006a7f24)(psVar10,iVar3 + -1);
            iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
            b = (X509 *)(*(code *)PTR_sk_value_006a7f24)(psVar2,iVar3 + -1);
            iVar3 = X509_cmp(a,b);
            uVar4 = (uint)(iVar3 == 0);
          }
          if (auStack_ac._72_4_ != (_func_1866 *)0x0) {
            (*auStack_ac._72_4_)((X509_STORE_CTX *)auStack_ac);
          }
          if (auStack_ac._20_4_ != (X509_VERIFY_PARAM *)0x0) {
            if (auStack_ac._124_4_ == (X509_STORE_CTX *)0x0) {
              X509_VERIFY_PARAM_free(auStack_ac._20_4_);
            }
            auStack_ac._20_4_ = (X509_VERIFY_PARAM *)0x0;
          }
          if (auStack_ac._88_4_ != (X509_POLICY_TREE *)0x0) {
            X509_policy_tree_free(auStack_ac._88_4_);
            auStack_ac._88_4_ = (X509_POLICY_TREE *)0x0;
          }
          if (auStack_ac._84_4_ != (stack_st_X509 *)0x0) {
            (*(code *)PTR_sk_pop_free_006a8158)(auStack_ac._84_4_,PTR_X509_free_006a7f90);
            auStack_ac._84_4_ = (stack_st_X509 *)0x0;
          }
          (*(code *)PTR_CRYPTO_free_ex_data_006a9414)
                    (5,(X509_STORE_CTX *)auStack_ac,auStack_ac + 0x80);
          if (uVar4 == 1) goto LAB_0057e8d0;
        }
        param_1->error = 0x36;
        pXVar5 = param_1;
        iVar3 = (*param_1->verify_cb)(0,param_1);
        if (iVar3 == 0) {
          pcVar6 = (code *)0x0;
          pXVar7 = (X509_STORE_CTX *)0x0;
          goto LAB_0057e7c0;
        }
      }
LAB_0057e8d0:
      if ((param_2->idp_flags & 2U) != 0) {
        param_1->error = 0x29;
        pXVar5 = param_1;
        iVar3 = (*param_1->verify_cb)(0,param_1);
        if (iVar3 == 0) {
          pcVar6 = (code *)0x0;
          pXVar7 = (X509_STORE_CTX *)0x0;
          goto LAB_0057e7c0;
        }
      }
      goto LAB_0057e6e4;
    }
    param_1->error = 0x2c;
    pXVar5 = param_1;
    iVar3 = (*param_1->verify_cb)(0,param_1);
    if (iVar3 != 0) {
      uVar4 = param_1->current_crl_score;
      goto LAB_0057e8c4;
    }
    goto LAB_0057e82c;
  }
LAB_0057e6e4:
  if ((param_1->current_crl_score & 0x40U) == 0) {
    param_1->current_crl = param_2;
    t = (time_t *)0x0;
    if ((param_1->param->flags & 2) != 0) {
      t = &param_1->param->check_time;
    }
    iVar3 = X509_cmp_time(param_2->crl->lastUpdate,t);
    if (iVar3 == 0) {
      param_1->error = 0xf;
      pXVar5 = param_1;
      iVar3 = (*param_1->verify_cb)(0,param_1);
joined_r0x0057e824:
      if (iVar3 == 0) goto LAB_0057e82c;
    }
    else if (0 < iVar3) {
      param_1->error = 0xb;
      pXVar5 = param_1;
      iVar3 = (*param_1->verify_cb)(0,param_1);
      goto joined_r0x0057e824;
    }
    s = param_2->crl->nextUpdate;
    if (s != (ASN1_TIME *)0x0) {
      iVar3 = X509_cmp_time(s,t);
      if (iVar3 == 0) {
        param_1->error = 0x10;
        pXVar5 = param_1;
        iVar3 = (*param_1->verify_cb)(0,param_1);
        if (iVar3 != 0) goto LAB_0057e788;
      }
      else {
        if ((-1 < iVar3) || ((param_1->current_crl_score & 2U) != 0)) goto LAB_0057e788;
        param_1->error = 0xc;
        pXVar5 = param_1;
        iVar3 = (*param_1->verify_cb)(0,param_1);
        if (iVar3 != 0) {
          param_1->current_crl = (X509_CRL *)0x0;
          goto LAB_0057e790;
        }
      }
LAB_0057e82c:
      pcVar6 = (code *)0x0;
      pXVar7 = (X509_STORE_CTX *)0x0;
      goto LAB_0057e7c0;
    }
LAB_0057e788:
    param_1->current_crl = (X509_CRL *)0x0;
  }
LAB_0057e790:
  pXVar7 = (X509_STORE_CTX *)X509_get_pubkey((X509 *)pXVar7);
  if (pXVar7 == (X509_STORE_CTX *)0x0) {
    param_1->error = 6;
    iVar3 = (*param_1->verify_cb)(0,param_1);
    pcVar6 = (code *)(uint)(iVar3 != 0);
    pXVar5 = param_1;
  }
  else {
    pXVar5 = pXVar7;
    iVar3 = (*(code *)PTR_X509_CRL_verify_006a86d8)(param_2);
    if (iVar3 < 1) {
      param_1->error = 8;
      iVar3 = (*param_1->verify_cb)(0,param_1);
      pcVar6 = (code *)(uint)(iVar3 != 0);
      pXVar5 = param_1;
    }
    else {
      pcVar6 = (code *)0x1;
    }
  }
LAB_0057e7c0:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(pXVar7);
  if (local_24 == *(int *)puVar1) {
    return pcVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *(X509_STORE_CTX **)(local_24 + 0x18) = pXVar5;
  *(code **)(local_24 + 0x24) = get_issuer_sk;
  return get_issuer_sk;
}

