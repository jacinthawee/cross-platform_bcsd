
SXNET * sxnet_v2i(undefined4 param_1,ASN1_INTEGER *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  SXNET *pSVar3;
  ASN1_INTEGER *pAVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char *user;
  SXNET *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_20 = (SXNET *)0x0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  for (iVar7 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(param_3), pSVar3 = local_20, iVar7 < iVar2;
      iVar7 = iVar7 + 1) {
    iVar2 = (*(code *)PTR_sk_value_006a6e24)(param_3,iVar7);
    user = *(char **)(iVar2 + 8);
    param_2 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*(char **)(iVar2 + 4));
    if (param_2 == (ASN1_INTEGER *)0x0) {
      param_2 = (ASN1_INTEGER *)0x7d;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7d,0x83,"v3_sxnet.c",0x9d);
      pSVar3 = (SXNET *)0x0;
      break;
    }
    iVar2 = SXNET_add_id_INTEGER(&local_20,param_2,user,-1);
    if (iVar2 == 0) {
      pSVar3 = (SXNET *)0x0;
      break;
    }
  }
  if (local_1c == *(int *)puVar1) {
    return pSVar3;
  }
  iVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pAVar4 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(char *)param_2);
  if (pAVar4 == (ASN1_INTEGER *)0x0) {
    uVar8 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x80,0x83,"v3_sxnet.c",0xed);
  }
  else {
    iVar2 = 0;
    do {
      iVar6 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar7 + 4));
      if (iVar6 <= iVar2) {
        uVar8 = 0;
        goto LAB_00590d2c;
      }
      puVar5 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar7 + 4),iVar2);
      iVar6 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)(*puVar5,pAVar4);
      iVar2 = iVar2 + 1;
    } while (iVar6 != 0);
    uVar8 = puVar5[1];
LAB_00590d2c:
    (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar4);
  }
  return (SXNET *)uVar8;
}

