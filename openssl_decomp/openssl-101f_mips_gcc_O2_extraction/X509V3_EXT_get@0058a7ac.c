
X509V3_EXT_METHOD * X509V3_EXT_get(X509_EXTENSION *ext)

{
  undefined *puVar1;
  int iVar2;
  X509V3_EXT_METHOD **ppXVar3;
  X509V3_EXT_METHOD *pXVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *local_50;
  int local_4c [14];
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ext->object);
  if ((iVar2 != 0) && (local_50 = local_4c, -1 < iVar2)) {
    local_4c[0] = iVar2;
    ppXVar3 = (X509V3_EXT_METHOD **)
              (*(code *)PTR_OBJ_bsearch__006a9488)
                        (&local_50,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
    if (ppXVar3 != (X509V3_EXT_METHOD **)0x0) {
      pXVar4 = *ppXVar3;
      goto LAB_0058a834;
    }
    if ((ext_list != 0) && (iVar2 = (*(code *)PTR_sk_find_006a906c)(ext_list,local_4c), iVar2 != -1)
       ) {
      pXVar4 = (X509V3_EXT_METHOD *)(*(code *)PTR_sk_value_006a7f24)(ext_list,iVar2);
      goto LAB_0058a834;
    }
  }
  pXVar4 = (X509V3_EXT_METHOD *)0x0;
LAB_0058a834:
  if (local_14 == *(int **)puVar1) {
    return pXVar4;
  }
  piVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*piVar6 == -1) {
    return (X509V3_EXT_METHOD *)0x1;
  }
  while ((ext_list != 0 || (ext_list = (*(code *)PTR_sk_new_006a91b4)(ext_cmp), ext_list != 0))) {
    piVar7 = piVar6 + 0xe;
    iVar2 = (*(code *)PTR_sk_push_006a80a8)(ext_list,piVar6);
    if (iVar2 == 0) {
      uVar5 = 0x50;
      goto LAB_0058a93c;
    }
    piVar6 = piVar7;
    if (*piVar7 == -1) {
      return (X509V3_EXT_METHOD *)0x1;
    }
  }
  uVar5 = 0x4c;
LAB_0058a93c:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x68,0x41,"v3_lib.c",uVar5);
  return (X509V3_EXT_METHOD *)0x0;
}

