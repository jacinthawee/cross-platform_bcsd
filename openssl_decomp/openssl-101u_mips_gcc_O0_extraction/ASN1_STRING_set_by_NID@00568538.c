
/* WARNING: Restarted to delay deadcode elimination for space: ram */

ASN1_STRING * ASN1_STRING_set_by_NID(ASN1_STRING **out,uchar *in,int inlen,int inform,int nid)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  ASN1_STRING *pAVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined *unaff_s6;
  int aiStack_f8 [5];
  int iStack_e4;
  ASN1_STRING *pAStack_dc;
  undefined *puStack_d8;
  int *piStack_d4;
  undefined *puStack_d0;
  int iStack_cc;
  int *piStack_c8;
  undefined *puStack_c4;
  int aiStack_98 [5];
  int iStack_84;
  ASN1_STRING **ppAStack_7c;
  undefined *puStack_78;
  uchar *puStack_74;
  int iStack_70;
  code *pcStack_6c;
  code *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_48;
  ASN1_STRING *local_3c;
  int local_38 [5];
  int local_24;
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  piStack_c8 = local_38;
  local_48 = &_gp;
  local_3c = (ASN1_STRING *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_58 = table_cmp_BSEARCH_CMP_FN;
  ppAStack_7c = &local_3c;
  if (out != (ASN1_STRING **)0x0) {
    ppAStack_7c = out;
  }
  local_38[0] = nid;
  iVar3 = (*(code *)PTR_OBJ_bsearch__006a8368)(piStack_c8,tbl_standard,0x13,0x14);
  if (iVar3 == 0) {
    unaff_s6 = &_gp_1;
    if (stable != 0) {
      iVar3 = (**(code **)(local_48 + -0x6d9c))(stable,piStack_c8);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(local_48 + -0x7fbc))(stable,iVar3);
        if (iVar3 != 0) goto LAB_005685c8;
      }
    }
    local_58 = (code *)(global_mask & 0x2806);
    iVar3 = (**(code **)(local_48 + -0x610c))(ppAStack_7c,in,inlen,inform);
  }
  else {
LAB_005685c8:
    local_58 = *(code **)(iVar3 + 0xc);
    if ((*(uint *)(iVar3 + 0x10) & 2) == 0) {
      local_58 = (code *)((uint)local_58 & global_mask);
    }
    local_50 = *(undefined4 *)(iVar3 + 8);
    local_54 = *(undefined4 *)(iVar3 + 4);
    iVar3 = (**(code **)(local_48 + -0x5ff4))(ppAStack_7c,in,inlen,inform);
  }
  pAVar4 = (ASN1_STRING *)0x0;
  if (0 < iVar3) {
    pAVar4 = *ppAStack_7c;
  }
  if (local_24 == *(int *)puStack_78) {
    return pAVar4;
  }
  pcStack_6c = ASN1_STRING_TABLE_get;
  aiStack_98[0] = local_24;
  (**(code **)(local_48 + -0x5330))();
  puStack_d8 = PTR___stack_chk_guard_006a9ae8;
  piStack_d4 = aiStack_98;
  iVar9 = 0x14;
  iVar3 = 0x13;
  puVar8 = tbl_standard;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_74 = in;
  iStack_70 = inlen;
  pAStack_dc = (ASN1_STRING *)(*(code *)PTR_OBJ_bsearch__006a8368)(piStack_d4);
  if (pAStack_dc == (ASN1_STRING *)0x0) {
    inlen = (int)&_gp_1;
    if (stable != 0) {
      puVar8 = (undefined1 *)piStack_d4;
      piVar5 = (int *)(*(code *)PTR_sk_find_006a8044)();
      if (-1 < (int)piVar5) {
        pAStack_dc = (ASN1_STRING *)(*(code *)PTR_sk_value_006a6e24)(stable);
        puVar8 = (undefined1 *)piVar5;
      }
    }
  }
  if (iStack_84 == *(int *)puStack_d8) {
    return pAStack_dc;
  }
  iVar7 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_d0 = (undefined *)inlen;
  iStack_cc = inform;
  puStack_c4 = unaff_s6;
  if (stable == 0) {
    stable = (*(code *)PTR_sk_new_006a806c)(sk_table_cmp);
    if (stable == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x81,0x41,"a_strnid.c",0xf2);
      pAVar4 = (ASN1_STRING *)0x0;
      goto LAB_00568888;
    }
  }
  aiStack_f8[0] = iVar7;
  piVar5 = (int *)(*(code *)PTR_OBJ_bsearch__006a8368)
                            (aiStack_f8,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (piVar5 == (int *)0x0) {
    if (stable != 0) {
      iVar6 = (*(code *)PTR_sk_find_006a8044)(stable,aiStack_f8);
      if (-1 < iVar6) {
        piVar5 = (int *)(*(code *)PTR_sk_value_006a6e24)(stable,iVar6);
        if (piVar5 != (int *)0x0) goto LAB_0056884c;
      }
    }
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_strnid.c",0xf6);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x81,0x41,"a_strnid.c",0xf8);
      pAVar4 = (ASN1_STRING *)0x0;
      goto LAB_00568888;
    }
    *piVar5 = iVar7;
    bVar1 = true;
    piVar5[4] = 0x568399;
  }
  else {
LAB_0056884c:
    bVar1 = false;
    piVar5[4] = piVar5[4] & 1U | 0x568398;
  }
  if ((int *)puVar8 != (int *)0xffffffff) {
    piVar5[1] = (int)puVar8;
  }
  if (iVar3 != -1) {
    piVar5[2] = iVar3;
  }
  piVar5[3] = iVar9;
  if (bVar1) {
    (*(code *)PTR_sk_push_006a6fa8)(stable,piVar5);
    pAVar4 = (ASN1_STRING *)0x1;
  }
  else {
    pAVar4 = (ASN1_STRING *)0x1;
  }
LAB_00568888:
  if (iStack_e4 == *(int *)puVar2) {
    return pAVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x005689ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar4 = (ASN1_STRING *)(*(code *)PTR_sk_pop_free_006a7058)(iVar3,st_free);
    return pAVar4;
  }
  return (ASN1_STRING *)&_gp_1;
}

