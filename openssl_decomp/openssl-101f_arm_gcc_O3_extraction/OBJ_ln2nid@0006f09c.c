
int OBJ_ln2nid(char *s)

{
  char *__s1;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_48;
  undefined *puStack_44;
  undefined auStack_40 [4];
  char *local_3c;
  
  local_3c = s;
  if (added != (_LHASH *)0x0) {
    puStack_44 = auStack_40;
    local_48 = 2;
    pvVar1 = lh_retrieve(added,&local_48);
    if (pvVar1 != (void *)0x0) {
      return *(int *)(*(int *)((int)pvVar1 + 4) + 8);
    }
  }
  __s1 = local_3c;
  iVar5 = 0;
  iVar6 = 0x391;
  do {
    while( true ) {
      iVar4 = iVar5 + iVar6 >> 1;
      iVar3 = *(int *)(ln_objs + iVar4 * 4);
      iVar2 = strcmp(__s1,(&PTR_s_undefined_00140f90)[iVar3 * 6]);
      if (-1 < iVar2) break;
      iVar6 = iVar4;
      if (iVar4 <= iVar5) goto LAB_0006f11c;
    }
    if (iVar2 == 0) goto LAB_0006f126;
    iVar5 = iVar4 + 1;
  } while (iVar5 < iVar6);
LAB_0006f11c:
  if (iVar2 != 0) {
    return 0;
  }
LAB_0006f126:
  return *(int *)(&DAT_00140f94 + iVar3 * 0x18);
}

