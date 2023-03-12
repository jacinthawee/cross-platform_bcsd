
int EVP_PBE_find(int type,int pbe_nid,int *pcnid,int *pmnid,undefined1 **pkeygen)

{
  undefined *puVar1;
  int iVar2;
  void *pvVar3;
  int local_38;
  int local_34;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pbe_nid == 0) {
    iVar2 = 0;
  }
  else {
    local_38 = type;
    local_34 = pbe_nid;
    if (((pbe_algs == (_STACK *)0x0) || (iVar2 = sk_find(pbe_algs,&local_38), iVar2 == -1)) ||
       (pvVar3 = sk_value(pbe_algs,iVar2), pvVar3 == (void *)0x0)) {
      pvVar3 = (void *)(*(code *)PTR_OBJ_bsearch__006a9488)
                                 (&local_38,builtin_pbe,0x15,0x14,pbe2_cmp_BSEARCH_CMP_FN);
      iVar2 = 0;
      if (pvVar3 == (void *)0x0) goto LAB_00546a34;
    }
    if (pcnid != (int *)0x0) {
      *pcnid = *(int *)((int)pvVar3 + 8);
    }
    if (pmnid != (int *)0x0) {
      *pmnid = *(int *)((int)pvVar3 + 0xc);
    }
    iVar2 = 1;
    if (pkeygen != (undefined1 **)0x0) {
      *pkeygen = *(undefined1 **)((int)pvVar3 + 0x10);
    }
  }
LAB_00546a34:
  if (local_24 != *(int *)puVar1) {
    iVar2 = (*(code *)PTR___stack_chk_fail_006aabb8)();
    sk_pop_free(pbe_algs,free_evp_pbe_ctl);
    pbe_algs = (_STACK *)0x0;
    return iVar2;
  }
  return iVar2;
}

