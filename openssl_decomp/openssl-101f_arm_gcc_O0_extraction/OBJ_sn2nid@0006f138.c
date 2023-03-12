
int OBJ_sn2nid(char *s)

{
  char *__s1;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_48;
  char **ppcStack_44;
  char *local_40 [7];
  
  local_40[0] = s;
  if (added != (_LHASH *)0x0) {
    ppcStack_44 = local_40;
    local_48 = 1;
    pvVar1 = lh_retrieve(added,&local_48);
    if (pvVar1 != (void *)0x0) {
      return *(int *)(*(int *)((int)pvVar1 + 4) + 8);
    }
  }
  __s1 = local_40[0];
  iVar5 = 0;
  iVar6 = 0x391;
  do {
    while( true ) {
      iVar4 = iVar5 + iVar6 >> 1;
      iVar3 = *(int *)(sn_objs + iVar4 * 4);
      iVar2 = strcmp(__s1,(&nid_objs)[iVar3 * 6]);
      if (-1 < iVar2) break;
      iVar6 = iVar4;
      if (iVar4 <= iVar5) goto LAB_0006f1b6;
    }
    if (iVar2 == 0) goto LAB_0006f1c0;
    iVar5 = iVar4 + 1;
  } while (iVar5 < iVar6);
LAB_0006f1b6:
  if (iVar2 != 0) {
    return 0;
  }
LAB_0006f1c0:
  return *(int *)(&DAT_00140f94 + iVar3 * 0x18);
}

