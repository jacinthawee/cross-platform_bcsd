
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
  undefined1 *unaff_s6;
  int aiStack_f8 [5];
  int iStack_e4;
  ASN1_STRING *pAStack_dc;
  undefined *puStack_d8;
  int *piStack_d4;
  undefined1 *puStack_d0;
  int iStack_cc;
  int *piStack_c8;
  undefined1 *puStack_c4;
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
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  piStack_c8 = local_38;
  local_48 = &_gp;
  local_3c = (ASN1_STRING *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_58 = table_cmp_BSEARCH_CMP_FN;
  ppAStack_7c = &local_3c;
  if (out != (ASN1_STRING **)0x0) {
    ppAStack_7c = out;
  }
  local_38[0] = nid;
  iVar3 = (*(code *)PTR_OBJ_bsearch__006a9488)(piStack_c8,tbl_standard,0x13,0x14);
  if (iVar3 == 0) {
    unaff_s6 = &_ITM_registerTMCloneTable;
    if (stable != 0) {
      iVar3 = (**(code **)(local_48 + -0x6e74))(stable,piStack_c8);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(local_48 + -0x7fbc))(stable,iVar3);
        if (iVar3 != 0) goto LAB_0056bee8;
      }
    }
    local_58 = (code *)(global_mask & 0x2806);
    iVar3 = (**(code **)(local_48 + -0x60e8))(ppAStack_7c,in,inlen,inform);
  }
  else {
LAB_0056bee8:
    local_58 = *(code **)(iVar3 + 0xc);
    if ((*(uint *)(iVar3 + 0x10) & 2) == 0) {
      local_58 = (code *)((uint)local_58 & global_mask);
    }
    local_50 = *(undefined4 *)(iVar3 + 8);
    local_54 = *(undefined4 *)(iVar3 + 4);
    iVar3 = (**(code **)(local_48 + -0x5fd4))(ppAStack_7c,in,inlen,inform);
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
  (**(code **)(local_48 + -0x5328))();
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  piStack_d4 = aiStack_98;
  iVar9 = 0x14;
  iVar3 = 0x13;
  puVar8 = tbl_standard;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_74 = in;
  iStack_70 = inlen;
  pAStack_dc = (ASN1_STRING *)(*(code *)PTR_OBJ_bsearch__006a9488)(piStack_d4);
  if (pAStack_dc == (ASN1_STRING *)0x0) {
    inlen = (int)&_ITM_registerTMCloneTable;
    if (stable != 0) {
      puVar8 = (undefined1 *)piStack_d4;
      piVar5 = (int *)(*(code *)PTR_sk_find_006a906c)();
      if (-1 < (int)piVar5) {
        pAStack_dc = (ASN1_STRING *)(*(code *)PTR_sk_value_006a7f24)(stable);
        puVar8 = (undefined1 *)piVar5;
      }
    }
  }
  if (iStack_84 == *(int *)puStack_d8) {
    return pAStack_dc;
  }
  iVar7 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_d0 = (undefined1 *)inlen;
  iStack_cc = inform;
  puStack_c4 = unaff_s6;
  if (stable == 0) {
    stable = (*(code *)PTR_sk_new_006a91b4)(sk_table_cmp);
    if (stable == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x81,0x41,"a_strnid.c",0xdd);
      pAVar4 = (ASN1_STRING *)0x0;
      goto LAB_0056c1a8;
    }
  }
  aiStack_f8[0] = iVar7;
  piVar5 = (int *)(*(code *)PTR_OBJ_bsearch__006a9488)
                            (aiStack_f8,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (piVar5 == (int *)0x0) {
    if (stable != 0) {
      iVar6 = (*(code *)PTR_sk_find_006a906c)(stable,aiStack_f8);
      if (-1 < iVar6) {
        piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(stable,iVar6);
        if (piVar5 != (int *)0x0) goto LAB_0056c16c;
      }
    }
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_strnid.c",0xe1);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x81,0x41,"a_strnid.c",0xe4);
      pAVar4 = (ASN1_STRING *)0x0;
      goto LAB_0056c1a8;
    }
    *piVar5 = iVar7;
    bVar1 = true;
    piVar5[4] = 0x56bcb9;
  }
  else {
LAB_0056c16c:
    bVar1 = false;
    piVar5[4] = piVar5[4] & 1U | 0x56bcb8;
  }
  if ((int *)puVar8 != (int *)0xffffffff) {
    piVar5[1] = (int)puVar8;
  }
  if (iVar3 != -1) {
    piVar5[2] = iVar3;
  }
  piVar5[3] = iVar9;
  if (bVar1) {
    (*(code *)PTR_sk_push_006a80a8)(stable,piVar5);
    pAVar4 = (ASN1_STRING *)0x1;
  }
  else {
    pAVar4 = (ASN1_STRING *)0x1;
  }
LAB_0056c1a8:
  if (iStack_e4 == *(int *)puVar2) {
    return pAVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x0056c30c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar4 = (ASN1_STRING *)(*(code *)PTR_sk_pop_free_006a8158)(iVar3,st_free);
    return pAVar4;
  }
  return (ASN1_STRING *)&_ITM_registerTMCloneTable;
}

