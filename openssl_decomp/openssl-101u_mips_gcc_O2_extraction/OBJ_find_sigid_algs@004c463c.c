
int OBJ_find_sigid_algs(int signid,int *pdig_nid,int *ppkey_nid)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  void *pvVar4;
  undefined **ppuVar5;
  int *ptr;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  undefined *puStack_6c;
  undefined auStack_68 [4];
  undefined1 *puStack_64;
  int *piStack_60;
  int iStack_5c;
  undefined *puStack_58;
  int *piStack_54;
  int *piStack_50;
  code *pcStack_4c;
  int local_28 [3];
  undefined4 *local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_sig_app_006a84b0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  local_28[0] = signid;
  if (((*(int *)PTR_sig_app_006a84b0 == 0) ||
      (piVar11 = ppkey_nid,
      puStack_64 = (undefined1 *)
                   (*(code *)PTR_sk_find_006a8044)(*(int *)PTR_sig_app_006a84b0,local_28),
      (int)puStack_64 < 0)) ||
     (pvVar4 = (void *)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)puVar2),
     pvVar4 == (void *)0x0)) {
    piVar11 = (int *)0x1e;
    puStack_64 = sigoid_srt;
    pvVar4 = OBJ_bsearch_(local_28,sigoid_srt,0x1e,0xc,sig_cmp_BSEARCH_CMP_FN);
    iVar7 = 0;
    if (pvVar4 != (void *)0x0) goto LAB_004c46b8;
  }
  else {
LAB_004c46b8:
    if (pdig_nid != (int *)0x0) {
      *pdig_nid = *(int *)((int)pvVar4 + 4);
    }
    if (ppkey_nid == (int *)0x0) {
      iVar7 = 1;
    }
    else {
      iVar7 = 1;
      *ppkey_nid = *(int *)((int)pvVar4 + 8);
    }
  }
  if (local_1c == *(undefined4 **)puStack_58) {
    return iVar7;
  }
  pcStack_4c = OBJ_find_sigid_by_algs;
  puVar8 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_sigx_app_006a84b4;
  puStack_6c = auStack_68;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_60 = piVar11;
  piStack_54 = ppkey_nid;
  piStack_50 = pdig_nid;
  if ((*(int *)PTR_sigx_app_006a84b4 == 0) ||
     (iVar7 = (*(code *)PTR_sk_find_006a8044)(*(int *)PTR_sigx_app_006a84b4,puStack_6c), iVar7 < 0))
  {
    piVar11 = (int *)&DAT_0000001b;
    ppuVar5 = (undefined **)OBJ_bsearch_(&puStack_6c,sigoid_srt_xref,0x1b,4,sigx_cmp_BSEARCH_CMP_FN)
    ;
    iVar7 = 0;
    if (ppuVar5 == (undefined **)0x0) goto LAB_004c47ec;
  }
  else {
    puStack_6c = (undefined *)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)puVar2,iVar7);
    ppuVar5 = &puStack_6c;
  }
  iVar7 = 1;
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = *(undefined4 *)*ppuVar5;
  }
LAB_004c47ec:
  if (iStack_5c == *(int *)puVar3) {
    return iVar7;
  }
  iVar10 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR_sig_app_006a84b0;
  if (*(int *)PTR_sig_app_006a84b0 == 0) {
    iVar6 = (*(code *)PTR_sk_new_006a806c)(sig_sk_cmp);
    *(int *)puVar2 = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
  }
  puVar3 = PTR_sigx_app_006a84b4;
  if (*(int *)PTR_sigx_app_006a84b4 == 0) {
    iVar6 = (*(code *)PTR_sk_new_006a806c)(sigx_cmp);
    *(int *)puVar3 = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
  }
  ptr = (int *)CRYPTO_malloc(0xc,"obj_xref.c",0x9f);
  puVar1 = PTR_sk_push_006a6fa8;
  if (ptr != (int *)0x0) {
    uVar9 = *(undefined4 *)puVar2;
    ptr[1] = iVar10;
    *ptr = iVar7;
    ptr[2] = (int)piVar11;
    iVar7 = (*(code *)puVar1)(uVar9,ptr);
    if (iVar7 == 0) {
      CRYPTO_free(ptr);
      return 0;
    }
    iVar7 = (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)puVar3,ptr);
    if (iVar7 != 0) {
      (*(code *)PTR_sk_sort_006a83bc)(*(undefined4 *)PTR_sig_app_006a84b0);
      (*(code *)PTR_sk_sort_006a83bc)(*(undefined4 *)PTR_sigx_app_006a84b4);
      return 1;
    }
  }
  return 0;
}

