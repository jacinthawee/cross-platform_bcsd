
int CMS_add_smimecap(CMS_SignerInfo *si,stack_st_X509_ALGOR *algs)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_a2;
  undefined4 uVar7;
  undefined4 local_18;
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar6 = &local_18;
  local_18 = 0;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_i2d_X509_ALGORS_006aa4b0)(algs,puVar6);
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    in_a2 = 0x10;
    puVar6 = (undefined4 *)0xa7;
    iVar2 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006aa49c)(si,0xa7,0x10,local_18,iVar2);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_18);
  }
  if (local_14 == *(int **)puVar1) {
    return iVar2;
  }
  piVar5 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (in_a2 < 1) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = 0;
    uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(puVar6);
    uVar7 = 0xffffffff;
  }
  else {
    iVar3 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
    if (iVar3 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar3,in_a2);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
    if (iVar2 == 0) {
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar3);
      return 0;
    }
    uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(puVar6);
    uVar7 = 2;
  }
  (*(code *)PTR_X509_ALGOR_set0_006a9e04)(iVar2,uVar4,uVar7,iVar3);
  iVar3 = *piVar5;
  if (iVar3 == 0) {
    iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar5 = iVar3;
    if (iVar3 == 0) goto LAB_005bceac;
  }
  iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar3,iVar2);
  if (iVar3 != 0) {
    return 1;
  }
LAB_005bceac:
  (*(code *)PTR_X509_ALGOR_free_006a8f94)(iVar2);
  return 0;
}

