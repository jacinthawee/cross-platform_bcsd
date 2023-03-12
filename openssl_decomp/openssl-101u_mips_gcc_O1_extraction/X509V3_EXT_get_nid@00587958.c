
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
  undefined *unaff_s2;
  int *piStack_c0;
  int aiStack_bc [14];
  int *piStack_84;
  undefined *puStack_80;
  int *piStack_7c;
  undefined *puStack_78;
  code *pcStack_74;
  code *local_60;
  undefined *local_58;
  int *local_50;
  int local_4c [14];
  undefined4 *local_14;
  
  puStack_80 = PTR___stack_chk_guard_006a9ae8;
  piStack_7c = local_4c;
  local_58 = &_gp;
  local_14 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  local_50 = piStack_7c;
  if (nid < 0) {
LAB_00587a28:
    pXVar3 = (X509V3_EXT_METHOD *)0x0;
  }
  else {
    local_60 = ext_cmp_BSEARCH_CMP_FN;
    local_4c[0] = nid;
    ppXVar2 = (X509V3_EXT_METHOD **)
              (*(code *)PTR_OBJ_bsearch__006a8368)(&local_50,standard_exts,0x28,4);
    if (ppXVar2 == (X509V3_EXT_METHOD **)0x0) {
      unaff_s2 = &_gp_1;
      if ((ext_list == 0) ||
         (iVar4 = (**(code **)(local_58 + -0x6d9c))(ext_list,piStack_7c), iVar4 == -1))
      goto LAB_00587a28;
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
  (**(code **)(local_58 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piStack_84 = *(int **)PTR___stack_chk_guard_006a9ae8;
  puStack_78 = unaff_s2;
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar6);
  if ((iVar4 != 0) && (piStack_c0 = aiStack_bc, -1 < iVar4)) {
    aiStack_bc[0] = iVar4;
    ppXVar2 = (X509V3_EXT_METHOD **)
              (*(code *)PTR_OBJ_bsearch__006a8368)
                        (&piStack_c0,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
    if (ppXVar2 != (X509V3_EXT_METHOD **)0x0) {
      pXVar3 = *ppXVar2;
      goto LAB_00587ac4;
    }
    if ((ext_list != 0) &&
       (iVar4 = (*(code *)PTR_sk_find_006a8044)(ext_list,aiStack_bc), iVar4 != -1)) {
      pXVar3 = (X509V3_EXT_METHOD *)(*(code *)PTR_sk_value_006a6e24)(ext_list,iVar4);
      goto LAB_00587ac4;
    }
  }
  pXVar3 = (X509V3_EXT_METHOD *)0x0;
LAB_00587ac4:
  if (piStack_84 == *(int **)puVar1) {
    return pXVar3;
  }
  piVar7 = piStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*piVar7 == -1) {
    return (X509V3_EXT_METHOD *)0x1;
  }
  while ((ext_list != 0 || (ext_list = (*(code *)PTR_sk_new_006a806c)(ext_cmp), ext_list != 0))) {
    piVar8 = piVar7 + 0xe;
    iVar4 = (*(code *)PTR_sk_push_006a6fa8)(ext_list,piVar7);
    if (iVar4 == 0) {
      uVar5 = 0x51;
      goto LAB_00587bcc;
    }
    piVar7 = piVar8;
    if (*piVar8 == -1) {
      return (X509V3_EXT_METHOD *)0x1;
    }
  }
  uVar5 = 0x4d;
LAB_00587bcc:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x68,0x41,"v3_lib.c",uVar5);
  return (X509V3_EXT_METHOD *)0x0;
}

