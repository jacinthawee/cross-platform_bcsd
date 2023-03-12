
stack_st_X509 * X509_STORE_get1_certs(X509_STORE_CTX *st,X509_NAME *nm)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  stack_st_X509 *psVar4;
  int iVar5;
  X509_STORE_CTX *vs;
  X509_NAME *name;
  int *piVar6;
  int unaff_s3;
  undefined4 unaff_s5;
  code *pcVar7;
  int unaff_s8;
  int iVar8;
  int iStack_90;
  X509_OBJECT XStack_8c;
  int iStack_84;
  X509_NAME *pXStack_80;
  stack_st_X509 *psStack_7c;
  X509_STORE_CTX *pXStack_78;
  int iStack_74;
  char *pcStack_70;
  undefined4 uStack_6c;
  char *pcStack_68;
  undefined *puStack_64;
  int iStack_60;
  code *pcStack_5c;
  undefined4 local_48;
  undefined *local_40;
  int local_38;
  X509_OBJECT local_34;
  X509_STORE_CTX *local_2c;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  pcStack_70 = (char *)&local_38;
  local_40 = &_gp;
  local_2c = *(X509_STORE_CTX **)PTR___stack_chk_guard_006aabf0;
  psStack_7c = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
  (**(code **)(local_40 + -0x6c74))(9,0xb,"x509_lu.c",0x1ef);
  iVar2 = x509_object_idx_cnt(st->ctx->objs,1,nm,pcStack_70);
  if (iVar2 < 0) {
    (**(code **)(local_40 + -0x6c74))(10,0xb,"x509_lu.c",0x1f7);
    name = (X509_NAME *)0x1;
    iVar2 = X509_STORE_get_by_subject(st,1,nm,&local_34);
    if (iVar2 == 0) {
      (**(code **)(local_40 + -0x7f60))(psStack_7c);
      psVar4 = (stack_st_X509 *)0x0;
      goto LAB_00583ff8;
    }
    if (local_34.type == 1) {
      (**(code **)(local_40 + -0x7f50))(local_34.data.ptr);
LAB_00584090:
      pcVar7 = *(code **)(local_40 + -0x6c74);
    }
    else {
      pcVar7 = *(code **)(local_40 + -0x6c74);
      if (local_34.type == 2) {
        (**(code **)(local_40 + -0x7d80))(local_34.data.ptr);
        goto LAB_00584090;
      }
    }
    (*pcVar7)(9,0xb,"x509_lu.c",0x1fe);
    iVar2 = x509_object_idx_cnt(st->ctx->objs,1,nm,pcStack_70);
    if (iVar2 < 0) {
      name = (X509_NAME *)&DAT_0000000b;
      (**(code **)(local_40 + -0x6c74))(10,0xb,"x509_lu.c",0x202);
      (**(code **)(local_40 + -0x7f60))(psStack_7c);
      psVar4 = (stack_st_X509 *)0x0;
      unaff_s3 = iVar2;
      goto LAB_00583ff8;
    }
  }
  nm = (X509_NAME *)0x0;
  unaff_s3 = iVar2;
  if (local_38 < 1) {
    pcVar7 = *(code **)(local_40 + -0x6c74);
  }
  else {
    unaff_s5 = 0x20b;
    pcStack_70 = "x509_lu.c";
    do {
      iVar3 = (**(code **)(local_40 + -0x7fbc))(st->ctx->objs,(int)&nm->entries + iVar2);
      unaff_s8 = *(int *)(iVar3 + 4);
      local_48 = 0x20b;
      (**(code **)(local_40 + -0x6e60))(unaff_s8 + 0x10,1,3,"x509_lu.c");
      iVar3 = (**(code **)(local_40 + -0x7e38))(psStack_7c,unaff_s8);
      if (iVar3 == 0) {
        (**(code **)(local_40 + -0x6c74))(10,0xb,"x509_lu.c",0x20e);
        (**(code **)(local_40 + -0x7f50))(unaff_s8);
        name = *(X509_NAME **)(local_40 + -0x7f50);
        (**(code **)(local_40 + -0x7d88))(psStack_7c);
        psVar4 = (stack_st_X509 *)0x0;
        goto LAB_00583ff8;
      }
      nm = (X509_NAME *)((int)&nm->entries + 1);
      pcVar7 = *(code **)(local_40 + -0x6c74);
    } while ((int)nm < local_38);
  }
  name = (X509_NAME *)&DAT_0000000b;
  (*pcVar7)(10,0xb,"x509_lu.c",0x214);
  psVar4 = psStack_7c;
LAB_00583ff8:
  if (local_2c == *(X509_STORE_CTX **)puStack_64) {
    return psVar4;
  }
  pcStack_5c = X509_STORE_get1_crls;
  vs = local_2c;
  (**(code **)(local_40 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcStack_68 = "r";
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_80 = nm;
  pXStack_78 = st;
  iStack_74 = unaff_s3;
  uStack_6c = unaff_s5;
  iStack_60 = unaff_s8;
  psVar4 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0xb,"x509_lu.c",0x220);
  x509_object_idx_cnt(vs->ctx->objs,2,name,&iStack_90);
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xb,"x509_lu.c",0x226);
  piVar6 = (int *)&SUB_00000002;
  iVar2 = X509_STORE_get_by_subject(vs,2,name,&XStack_8c);
  if (iVar2 == 0) {
    (*(code *)PTR_sk_free_006a7f80)(psVar4);
    psVar4 = (stack_st_X509 *)0x0;
  }
  else {
    if (XStack_8c.type == 1) {
      (*(code *)PTR_X509_free_006a7f90)(XStack_8c.data.ptr);
    }
    else if (XStack_8c.type == 2) {
      (*(code *)PTR_X509_CRL_free_006a8160)(XStack_8c.data.ptr);
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0xb,"x509_lu.c",0x22d);
    iVar2 = x509_object_idx_cnt(vs->ctx->objs,2,name,&iStack_90);
    if (iVar2 < 0) {
      piVar6 = (int *)&DAT_0000000b;
      (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xb,"x509_lu.c",0x231);
      (*(code *)PTR_sk_free_006a7f80)(psVar4);
      psVar4 = (stack_st_X509 *)0x0;
    }
    else {
      iVar3 = 0;
      if (0 < iStack_90) {
        do {
          iVar5 = (*(code *)PTR_sk_value_006a7f24)(vs->ctx->objs,iVar3 + iVar2);
          iVar8 = *(int *)(iVar5 + 4);
          (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar8 + 0xc,1,6,"x509_lu.c",0x23a);
          iVar5 = (*(code *)PTR_sk_push_006a80a8)(psVar4,iVar8);
          if (iVar5 == 0) {
            (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xb,"x509_lu.c",0x23d);
            (*(code *)PTR_X509_CRL_free_006a8160)(iVar8);
            piVar6 = (int *)PTR_X509_CRL_free_006a8160;
            (*(code *)PTR_sk_pop_free_006a8158)(psVar4);
            psVar4 = (stack_st_X509 *)0x0;
            goto LAB_00584324;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iStack_90);
      }
      piVar6 = (int *)&DAT_0000000b;
      (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xb,"x509_lu.c",0x243);
    }
  }
LAB_00584324:
  if (iStack_84 == *(int *)puVar1) {
    return psVar4;
  }
  iVar2 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_sk_find_006a906c)();
  if (iVar3 != -1) {
    if (1 < *piVar6 - 1U) {
                    /* WARNING: Could not recover jumptable at 0x005845b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      psVar4 = (stack_st_X509 *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar3);
      return psVar4;
    }
    iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar2);
    if (iVar3 < iVar5) {
      do {
        psVar4 = (stack_st_X509 *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar3);
        iVar5 = (psVar4->stack).num;
        if (iVar5 != *piVar6) {
          return (stack_st_X509 *)0x0;
        }
        if (iVar5 == 1) {
          iVar5 = X509_subject_name_cmp((X509 *)(psVar4->stack).data,(X509 *)piVar6[1]);
LAB_005844c4:
          if (iVar5 != 0) {
            return (stack_st_X509 *)0x0;
          }
          iVar5 = *piVar6;
        }
        else if (iVar5 == 2) {
          iVar5 = X509_CRL_cmp((X509_CRL *)(psVar4->stack).data,(X509_CRL *)piVar6[1]);
          goto LAB_005844c4;
        }
        if (iVar5 == 1) {
          iVar5 = X509_cmp((X509 *)(psVar4->stack).data,(X509 *)piVar6[1]);
        }
        else {
          if (iVar5 != 2) {
            return psVar4;
          }
          iVar5 = X509_CRL_match((X509_CRL *)(psVar4->stack).data,(X509_CRL *)piVar6[1]);
        }
        if (iVar5 == 0) {
          return psVar4;
        }
        iVar3 = iVar3 + 1;
        iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar2);
      } while (iVar3 < iVar5);
    }
  }
  return (stack_st_X509 *)0x0;
}

