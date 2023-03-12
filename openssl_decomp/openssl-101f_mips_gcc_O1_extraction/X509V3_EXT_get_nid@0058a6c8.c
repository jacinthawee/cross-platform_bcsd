
/* WARNING: Restarted to delay deadcode elimination for space: ram */

X509V3_EXT_METHOD * X509V3_EXT_get_nid(int nid)

{
  undefined *puVar1;
  X509V3_EXT_METHOD **ppXVar2;
  X509V3_EXT_METHOD *pXVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  undefined1 *unaff_s2;
  int *piStack_c0;
  int aiStack_bc [14];
  int *piStack_84;
  undefined *puStack_80;
  int *piStack_7c;
  undefined1 *puStack_78;
  code *pcStack_74;
  code *local_60;
  undefined *local_58;
  int *local_50;
  int local_4c [14];
  undefined4 *local_14;
  
  puStack_80 = PTR___stack_chk_guard_006aabf0;
  piStack_7c = local_4c;
  local_58 = &_gp;
  local_14 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  local_50 = piStack_7c;
  if (nid < 0) {
LAB_0058a798:
    pXVar3 = (X509V3_EXT_METHOD *)0x0;
  }
  else {
    local_60 = ext_cmp_BSEARCH_CMP_FN;
    local_4c[0] = nid;
    ppXVar2 = (X509V3_EXT_METHOD **)
              (*(code *)PTR_OBJ_bsearch__006a9488)(&local_50,standard_exts,0x28,4);
    if (ppXVar2 == (X509V3_EXT_METHOD **)0x0) {
      unaff_s2 = &_ITM_registerTMCloneTable;
      if ((ext_list == 0) ||
         (iVar4 = (**(code **)(local_58 + -0x6e74))(ext_list,piStack_7c), iVar4 == -1))
      goto LAB_0058a798;
      pXVar3 = (X509V3_EXT_METHOD *)(**(code **)(local_58 + -0x7fbc))(ext_list,iVar4);
    }
    else {
      pXVar3 = *ppXVar2;
    }
  }
  if (local_14 == *(undefined4 **)puStack_80) {
    return pXVar3;
  }
  pcStack_74 = X509V3_EXT_get;
  puVar6 = local_14;
  (**(code **)(local_58 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piStack_84 = *(int **)PTR___stack_chk_guard_006aabf0;
  puStack_78 = unaff_s2;
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar6);
  if ((iVar4 != 0) && (piStack_c0 = aiStack_bc, -1 < iVar4)) {
    aiStack_bc[0] = iVar4;
    ppXVar2 = (X509V3_EXT_METHOD **)
              (*(code *)PTR_OBJ_bsearch__006a9488)
                        (&piStack_c0,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
    if (ppXVar2 != (X509V3_EXT_METHOD **)0x0) {
      pXVar3 = *ppXVar2;
      goto LAB_0058a834;
    }
    if ((ext_list != 0) &&
       (iVar4 = (*(code *)PTR_sk_find_006a906c)(ext_list,aiStack_bc), iVar4 != -1)) {
      pXVar3 = (X509V3_EXT_METHOD *)(*(code *)PTR_sk_value_006a7f24)(ext_list,iVar4);
      goto LAB_0058a834;
    }
  }
  pXVar3 = (X509V3_EXT_METHOD *)0x0;
LAB_0058a834:
  if (piStack_84 == *(int **)puVar1) {
    return pXVar3;
  }
  piVar7 = piStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*piVar7 == -1) {
    return (X509V3_EXT_METHOD *)0x1;
  }
  while ((ext_list != 0 || (ext_list = (*(code *)PTR_sk_new_006a91b4)(ext_cmp), ext_list != 0))) {
    piVar8 = piVar7 + 0xe;
    iVar4 = (*(code *)PTR_sk_push_006a80a8)(ext_list,piVar7);
    if (iVar4 == 0) {
      uVar5 = 0x50;
      goto LAB_0058a93c;
    }
    piVar7 = piVar8;
    if (*piVar8 == -1) {
      return (X509V3_EXT_METHOD *)0x1;
    }
  }
  uVar5 = 0x4c;
LAB_0058a93c:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x68,0x41,"v3_lib.c",uVar5);
  return (X509V3_EXT_METHOD *)0x0;
}

