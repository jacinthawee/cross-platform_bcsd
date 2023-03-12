
int OBJ_find_sigid_by_algs(int *psignid,int dig_nid,int pkey_nid)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int **ppiVar5;
  int *ptr;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *local_24;
  int iStack_20;
  int local_1c;
  int local_18;
  int local_14;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_sigx_app_006a95d4;
  local_24 = &iStack_20;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_1c = dig_nid;
  local_18 = pkey_nid;
  if ((*(int *)PTR_sigx_app_006a95d4 == 0) ||
     (iVar4 = (*(code *)PTR_sk_find_006a906c)(*(int *)PTR_sigx_app_006a95d4,local_24), iVar4 < 0)) {
    pkey_nid = 0x1e;
    ppiVar5 = (int **)OBJ_bsearch_(&local_24,sigoid_srt_xref,0x1e,4,sigx_cmp_BSEARCH_CMP_FN);
    iVar4 = 0;
    if (ppiVar5 == (int **)0x0) goto LAB_004c778c;
  }
  else {
    local_24 = (int *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)puVar2,iVar4);
    ppiVar5 = &local_24;
  }
  iVar4 = 1;
  if (psignid != (int *)0x0) {
    *psignid = **ppiVar5;
  }
LAB_004c778c:
  if (local_14 == *(int *)puVar3) {
    return iVar4;
  }
  iVar8 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR_sig_app_006a95d0;
  if (*(int *)PTR_sig_app_006a95d0 == 0) {
    iVar6 = (*(code *)PTR_sk_new_006a91b4)(sig_sk_cmp);
    *(int *)puVar2 = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
  }
  puVar3 = PTR_sigx_app_006a95d4;
  if (*(int *)PTR_sigx_app_006a95d4 == 0) {
    iVar6 = (*(code *)PTR_sk_new_006a91b4)(sigx_cmp);
    *(int *)puVar3 = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
  }
  ptr = (int *)CRYPTO_malloc(0xc,"obj_xref.c",0xa5);
  puVar1 = PTR_sk_push_006a80a8;
  if (ptr != (int *)0x0) {
    uVar7 = *(undefined4 *)puVar2;
    ptr[1] = iVar8;
    *ptr = iVar4;
    ptr[2] = pkey_nid;
    iVar4 = (*(code *)puVar1)(uVar7,ptr);
    if (iVar4 == 0) {
      CRYPTO_free(ptr);
      return 0;
    }
    iVar4 = (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)puVar3,ptr);
    if (iVar4 != 0) {
      (*(code *)PTR_sk_sort_006a94d8)(*(undefined4 *)PTR_sig_app_006a95d0);
      (*(code *)PTR_sk_sort_006a94d8)(*(undefined4 *)PTR_sigx_app_006a95d4);
      return 1;
    }
  }
  return 0;
}

