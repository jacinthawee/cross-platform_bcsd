
/* WARNING: Restarted to delay deadcode elimination for space: ram */

ASN1_STRING_TABLE * ASN1_STRING_TABLE_get(int nid)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  ASN1_STRING_TABLE *pAVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  undefined *unaff_s3;
  int aiStack_90 [5];
  int iStack_7c;
  ASN1_STRING_TABLE *pAStack_74;
  undefined *puStack_70;
  int *piStack_6c;
  undefined *puStack_68;
  int local_30 [5];
  int local_1c;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  piStack_6c = local_30;
  iVar9 = 0x14;
  iVar8 = 0x13;
  puVar7 = tbl_standard;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_30[0] = nid;
  pAStack_74 = (ASN1_STRING_TABLE *)(*(code *)PTR_OBJ_bsearch__006a8368)(piStack_6c);
  if (pAStack_74 == (ASN1_STRING_TABLE *)0x0) {
    unaff_s3 = &_gp_1;
    if (stable != 0) {
      puVar7 = (undefined1 *)piStack_6c;
      piVar3 = (int *)(*(code *)PTR_sk_find_006a8044)();
      if (-1 < (int)piVar3) {
        pAStack_74 = (ASN1_STRING_TABLE *)(*(code *)PTR_sk_value_006a6e24)(stable);
        puVar7 = (undefined1 *)piVar3;
      }
    }
  }
  if (local_1c == *(int *)puStack_70) {
    return pAStack_74;
  }
  iVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_68 = unaff_s3;
  if (stable == 0) {
    stable = (*(code *)PTR_sk_new_006a806c)(sk_table_cmp);
    if (stable == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x81,0x41,"a_strnid.c",0xf2);
      pAVar4 = (ASN1_STRING_TABLE *)0x0;
      goto LAB_00568888;
    }
  }
  aiStack_90[0] = iVar6;
  piVar3 = (int *)(*(code *)PTR_OBJ_bsearch__006a8368)
                            (aiStack_90,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (piVar3 == (int *)0x0) {
    if (stable != 0) {
      iVar5 = (*(code *)PTR_sk_find_006a8044)(stable,aiStack_90);
      if (-1 < iVar5) {
        piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(stable,iVar5);
        if (piVar3 != (int *)0x0) goto LAB_0056884c;
      }
    }
    piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_strnid.c",0xf6);
    if (piVar3 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x81,0x41,"a_strnid.c",0xf8);
      pAVar4 = (ASN1_STRING_TABLE *)0x0;
      goto LAB_00568888;
    }
    *piVar3 = iVar6;
    bVar1 = true;
    piVar3[4] = 0x568399;
  }
  else {
LAB_0056884c:
    bVar1 = false;
    piVar3[4] = piVar3[4] & 1U | 0x568398;
  }
  if ((int *)puVar7 != (int *)0xffffffff) {
    piVar3[1] = (int)puVar7;
  }
  if (iVar8 != -1) {
    piVar3[2] = iVar8;
  }
  piVar3[3] = iVar9;
  if (bVar1) {
    (*(code *)PTR_sk_push_006a6fa8)(stable,piVar3);
    pAVar4 = (ASN1_STRING_TABLE *)0x1;
  }
  else {
    pAVar4 = (ASN1_STRING_TABLE *)0x1;
  }
LAB_00568888:
  if (iStack_7c == *(int *)puVar2) {
    return pAVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar8 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x005689ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar4 = (ASN1_STRING_TABLE *)(*(code *)PTR_sk_pop_free_006a7058)(iVar8,st_free);
    return pAVar4;
  }
  return (ASN1_STRING_TABLE *)&_gp_1;
}

