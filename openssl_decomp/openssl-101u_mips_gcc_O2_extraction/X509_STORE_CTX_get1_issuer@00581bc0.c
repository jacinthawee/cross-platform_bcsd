
int X509_STORE_CTX_get1_issuer(X509 **issuer,X509_STORE_CTX *ctx,X509 *x)

{
  undefined *puVar1;
  X509_NAME *name;
  int iVar2;
  int iVar3;
  int *piVar4;
  X509_NAME *b;
  X509 *flags;
  X509_OBJECT local_34;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  name = X509_get_issuer_name(x);
  flags = (X509 *)0x1;
  iVar2 = X509_STORE_get_by_subject(ctx,1,name,&local_34);
  if (iVar2 == 1) {
    flags = x;
    iVar2 = (*ctx->check_issued)(ctx,x,(X509 *)local_34.data.ptr);
    if (iVar2 == 0) {
      if (local_34.type == 1) {
        (*(code *)PTR_X509_free_006a6e90)(local_34.data.ptr);
      }
      else if (local_34.type == 2) {
        (*(code *)PTR_X509_CRL_free_006a7060)(local_34.data.ptr);
      }
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"x509_lu.c",0x272);
      iVar2 = x509_object_idx_cnt_constprop_1(ctx->ctx->objs,1,name);
      if (iVar2 != -1) {
        while ((iVar3 = (*(code *)PTR_sk_num_006a6e2c)(ctx->ctx->objs), iVar2 < iVar3 &&
               (piVar4 = (int *)(*(code *)PTR_sk_value_006a6e24)(ctx->ctx->objs,iVar2), *piVar4 == 1
               ))) {
          b = X509_get_subject_name((X509 *)piVar4[1]);
          iVar3 = X509_NAME_cmp(name,b);
          if (iVar3 != 0) break;
          iVar3 = (*ctx->check_issued)(ctx,x,(X509 *)piVar4[1]);
          if (iVar3 != 0) {
            iVar2 = *piVar4;
            *issuer = (X509 *)piVar4[1];
            if (iVar2 == 1) {
              iVar3 = 1;
              (*(code *)PTR_CRYPTO_add_lock_006a805c)(piVar4[1] + 0x10,1,3,"x509_lu.c",0x18a);
            }
            else if (iVar2 == 2) {
              iVar3 = 1;
              (*(code *)PTR_CRYPTO_add_lock_006a805c)(piVar4[1] + 0xc,1,6,"x509_lu.c",0x18d);
            }
            else {
              iVar3 = 1;
            }
            goto LAB_00581dbc;
          }
          iVar2 = iVar2 + 1;
        }
      }
      iVar3 = 0;
LAB_00581dbc:
      flags = (X509 *)&DAT_0000000b;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x286);
    }
    else {
      iVar3 = 1;
      *issuer = (X509 *)local_34.data;
    }
  }
  else if (iVar2 == -1) {
    if (local_34.type == 1) {
      (*(code *)PTR_X509_free_006a6e90)(local_34.data.ptr);
    }
    else if (local_34.type == 2) {
      (*(code *)PTR_X509_CRL_free_006a7060)(local_34.data.ptr);
    }
    flags = (X509 *)&DAT_00000092;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x92,0x6a,"x509_lu.c",0x260);
    iVar3 = -1;
  }
  else {
    iVar3 = 0;
    if (iVar2 != 0) {
      if (local_34.type == 1) {
        (*(code *)PTR_X509_free_006a6e90)(local_34.data.ptr);
        iVar3 = -1;
      }
      else if (local_34.type == 2) {
        (*(code *)PTR_X509_CRL_free_006a7060)(local_34.data.ptr);
        iVar3 = -1;
      }
      else {
        iVar3 = -1;
      }
    }
  }
  if (local_2c != *(int *)puVar1) {
    iVar2 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar2 = X509_VERIFY_PARAM_set_flags(*(X509_VERIFY_PARAM **)(iVar2 + 0xc),(ulong)flags);
    return iVar2;
  }
  return iVar3;
}

