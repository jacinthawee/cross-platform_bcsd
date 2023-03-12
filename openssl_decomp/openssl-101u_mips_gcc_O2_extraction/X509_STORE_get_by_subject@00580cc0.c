
int X509_STORE_get_by_subject(X509_STORE_CTX *vs,int type,X509_NAME *name,X509_OBJECT *ret)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  stack_st_X509_OBJECT *psVar4;
  int iVar5;
  X509_STORE *pXVar6;
  code *pcVar7;
  int local_34;
  X509 *local_30;
  int *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pXVar6 = vs->ctx;
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xb,"x509_lu.c",0x124);
  psVar4 = pXVar6->objs;
  iVar2 = x509_object_idx_cnt_constprop_1(psVar4,type,name);
  if (iVar2 == -1) {
    piVar3 = (int *)0x0;
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x126);
LAB_00580e54:
    iVar5 = vs->current_method;
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(pXVar6->get_cert_methods);
    if (iVar5 < iVar2) {
      do {
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(pXVar6->get_cert_methods,iVar5);
        if (((*(int *)(iVar2 + 8) != 0) &&
            (pcVar7 = *(code **)(*(int *)(iVar2 + 8) + 0x18), pcVar7 != (code *)0x0)) &&
           (*(int *)(iVar2 + 4) == 0)) {
          iVar2 = (*pcVar7)(iVar2,type,name,&local_34);
          if (iVar2 < 0) {
            vs->current_method = iVar2;
            goto LAB_00580dc8;
          }
          if (iVar2 != 0) {
            vs->current_method = 0;
            ret->type = local_34;
            (ret->data).x509 = local_30;
            iVar2 = local_34;
            goto joined_r0x00580f10;
          }
        }
        iVar5 = iVar5 + 1;
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(pXVar6->get_cert_methods);
      } while (iVar5 < iVar2);
    }
    vs->current_method = 0;
    if (piVar3 == (int *)0x0) {
      iVar2 = 0;
      goto LAB_00580dc8;
    }
  }
  else {
    piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(psVar4,iVar2);
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x126);
    if ((piVar3 == (int *)0x0) || (type == 2)) goto LAB_00580e54;
  }
  iVar2 = *piVar3;
  ret->type = iVar2;
  local_30 = (X509 *)piVar3[1];
  (ret->data).x509 = local_30;
joined_r0x00580f10:
  if (iVar2 == 1) {
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(&local_30->references,1,3,"x509_lu.c",0x18a);
  }
  else if (iVar2 == 2) {
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(&local_30->valid,1,6,"x509_lu.c",0x18d);
    iVar2 = 1;
  }
  else {
    iVar2 = 1;
  }
LAB_00580dc8:
  if (local_2c == *(int **)puVar1) {
    return iVar2;
  }
  piVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = *piVar3;
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(piVar3[1] + 0xc,1,6,"x509_lu.c",0x18d);
    }
    return iVar2;
  }
  iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(piVar3[1] + 0x10,1,3,"x509_lu.c",0x18a);
  return iVar2;
}

