
int OBJ_ln2nid(char *s)

{
  int iVar1;
  char *__s1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  undefined4 local_40;
  undefined *local_3c;
  undefined local_38 [4];
  char *local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_34 = s;
  if (added != (_LHASH *)0x0) {
    local_3c = local_38;
    local_40 = 2;
    pvVar2 = lh_retrieve(added,&local_40);
    if (pvVar2 != (void *)0x0) {
      iVar6 = *(int *)(*(int *)((int)pvVar2 + 4) + 8);
      goto LAB_080d4a73;
    }
  }
  __s1 = local_34;
  iVar6 = 0;
  iVar5 = 0x391;
  do {
    while( true ) {
      iVar4 = iVar5 + iVar6 >> 1;
      iVar1 = *(int *)(ln_objs + iVar4 * 4);
      iVar3 = strcmp(__s1,*(char **)(nid_objs + iVar1 * 0x18 + 4));
      if (-1 < iVar3) break;
      iVar5 = iVar4;
      if (iVar4 <= iVar6) goto LAB_080d4ae1;
    }
    if (iVar3 == 0) goto LAB_080d4af0;
    iVar6 = iVar4 + 1;
  } while (iVar6 < iVar5);
LAB_080d4ae1:
  iVar6 = 0;
  if (iVar3 == 0) {
LAB_080d4af0:
    iVar6 = *(int *)(nid_objs + iVar1 * 0x18 + 8);
  }
LAB_080d4a73:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}
