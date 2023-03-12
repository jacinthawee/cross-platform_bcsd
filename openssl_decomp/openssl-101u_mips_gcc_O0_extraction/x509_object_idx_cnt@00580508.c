
undefined4 * x509_object_idx_cnt(undefined4 param_1,int param_2,X509_ALGOR *param_3,int *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  int local_13c;
  X509 *local_138;
  undefined auStack_134 [60];
  X509_ALGOR *local_f8;
  X509 local_d8;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_13c = param_2;
  if (param_2 == 1) {
    local_138 = (X509 *)&local_d8.nc;
    local_d8.nc = (NAME_CONSTRAINTS *)(auStack_134 + 0x28);
    local_f8 = param_3;
  }
  else {
    puVar3 = (undefined4 *)0xffffffff;
    if (param_2 != 2) goto LAB_00580638;
    local_138 = &local_d8;
    local_d8.cert_info = (X509_CINF *)auStack_134;
    auStack_134._8_4_ = param_3;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_sk_find_006a8044)(param_1,&local_13c);
  puVar1 = PTR_sk_num_006a6e2c;
  if ((-1 < (int)puVar3) && (param_4 != (int *)0x0)) {
    iVar6 = (int)puVar3 + 1;
    *param_4 = 1;
    iVar4 = (*(code *)puVar1)(param_1);
    if (iVar6 < iVar4) {
      do {
        piVar5 = (int *)(*(code *)PTR_sk_value_006a6e24)(param_1,iVar6);
        iVar4 = *piVar5;
        if (iVar4 != local_13c) break;
        if (iVar4 == 1) {
          iVar4 = X509_subject_name_cmp((X509 *)piVar5[1],local_138);
LAB_00580604:
          if (iVar4 != 0) break;
        }
        else if (iVar4 == 2) {
          iVar4 = X509_CRL_cmp((X509_CRL *)piVar5[1],(X509_CRL *)local_138);
          goto LAB_00580604;
        }
        puVar1 = PTR_sk_num_006a6e2c;
        iVar6 = iVar6 + 1;
        *param_4 = *param_4 + 1;
        iVar4 = (*(code *)puVar1)(param_1);
      } while (iVar6 < iVar4);
    }
  }
LAB_00580638:
  if (local_24 != *(int *)puVar2) {
    iVar4 = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"x509_lu.c",0x45);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      pcVar7 = *(code **)(iVar4 + 4);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = iVar4;
      puVar3[3] = 0;
      puVar3[4] = 0;
      if ((pcVar7 != (code *)0x0) && (iVar4 = (*pcVar7)(), iVar4 == 0)) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        puVar3 = (undefined4 *)0x0;
      }
    }
    return puVar3;
  }
  return puVar3;
}

