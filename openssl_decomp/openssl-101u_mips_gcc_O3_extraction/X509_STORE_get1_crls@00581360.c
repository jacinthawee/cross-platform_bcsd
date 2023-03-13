
stack_st_X509_CRL * X509_STORE_get1_crls(X509_STORE_CTX *st,X509_NAME *nm)

{
  undefined *puVar1;
  stack_st_X509_CRL *psVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_38;
  X509_OBJECT local_34;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar2 = (stack_st_X509_CRL *)(*(code *)PTR_sk_new_null_006a6fa4)();
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"x509_lu.c",0x20d);
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x212);
  piVar5 = (int *)&SUB_00000002;
  iVar3 = X509_STORE_get_by_subject(st,2,nm,&local_34);
  if (iVar3 == 0) {
    (*(code *)PTR_sk_free_006a6e80)(psVar2);
    psVar2 = (stack_st_X509_CRL *)0x0;
  }
  else {
    if (local_34.type == 1) {
      (*(code *)PTR_X509_free_006a6e90)(local_34.data.ptr);
    }
    else if (local_34.type == 2) {
      (*(code *)PTR_X509_CRL_free_006a7060)(local_34.data.ptr);
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"x509_lu.c",0x218);
    iVar3 = x509_object_idx_cnt(st->ctx->objs,2,nm,&local_38);
    if (iVar3 < 0) {
      piVar5 = (int *)&DAT_0000000b;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x21b);
      (*(code *)PTR_sk_free_006a6e80)(psVar2);
      psVar2 = (stack_st_X509_CRL *)0x0;
    }
    else {
      iVar6 = 0;
      if (0 < local_38) {
        do {
          iVar4 = (*(code *)PTR_sk_value_006a6e24)(st->ctx->objs,iVar6 + iVar3);
          iVar7 = *(int *)(iVar4 + 4);
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar7 + 0xc,1,6,"x509_lu.c",0x223);
          iVar4 = (*(code *)PTR_sk_push_006a6fa8)(psVar2,iVar7);
          if (iVar4 == 0) {
            (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x225);
            (*(code *)PTR_X509_CRL_free_006a7060)(iVar7);
            piVar5 = (int *)PTR_X509_CRL_free_006a7060;
            (*(code *)PTR_sk_pop_free_006a7058)(psVar2);
            psVar2 = (stack_st_X509_CRL *)0x0;
            goto LAB_0058152c;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_38);
      }
      piVar5 = (int *)&DAT_0000000b;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x22b);
    }
  }
LAB_0058152c:
  if (local_2c == *(int *)puVar1) {
    return psVar2;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = (*(code *)PTR_sk_find_006a8044)();
  if (iVar6 != -1) {
    if (1 < *piVar5 - 1U) {
                    /* WARNING: Could not recover jumptable at 0x005817b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      psVar2 = (stack_st_X509_CRL *)(*(code *)PTR_sk_value_006a6e24)(iVar3,iVar6);
      return psVar2;
    }
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
    if (iVar6 < iVar4) {
      do {
        psVar2 = (stack_st_X509_CRL *)(*(code *)PTR_sk_value_006a6e24)(iVar3,iVar6);
        iVar4 = (psVar2->stack).num;
        if (iVar4 != *piVar5) {
          return (stack_st_X509_CRL *)0x0;
        }
        if (iVar4 == 1) {
          iVar4 = X509_subject_name_cmp((X509 *)(psVar2->stack).data,(X509 *)piVar5[1]);
LAB_005816cc:
          if (iVar4 != 0) {
            return (stack_st_X509_CRL *)0x0;
          }
          iVar4 = *piVar5;
        }
        else if (iVar4 == 2) {
          iVar4 = X509_CRL_cmp((X509_CRL *)(psVar2->stack).data,(X509_CRL *)piVar5[1]);
          goto LAB_005816cc;
        }
        if (iVar4 == 1) {
          iVar4 = X509_cmp((X509 *)(psVar2->stack).data,(X509 *)piVar5[1]);
        }
        else {
          if (iVar4 != 2) {
            return psVar2;
          }
          iVar4 = X509_CRL_match((X509_CRL *)(psVar2->stack).data,(X509_CRL *)piVar5[1]);
        }
        if (iVar4 == 0) {
          return psVar2;
        }
        iVar6 = iVar6 + 1;
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
      } while (iVar6 < iVar4);
    }
  }
  return (stack_st_X509_CRL *)0x0;
}

