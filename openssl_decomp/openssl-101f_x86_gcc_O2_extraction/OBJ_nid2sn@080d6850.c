
char * OBJ_nid2sn(int n)

{
  void *pvVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  int line;
  undefined4 local_30;
  undefined *local_2c;
  undefined local_28 [8];
  int local_20;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((uint)n < 0x398) {
    if ((n == 0) || (*(int *)(nid_objs + n * 0x18 + 8) != 0)) {
      pcVar2 = *(char **)(nid_objs + n * 0x18);
      goto LAB_080d68c8;
    }
    line = 0x14a;
  }
  else {
    if (added == (_LHASH *)0x0) {
      pcVar2 = (char *)0x0;
      goto LAB_080d68c8;
    }
    local_2c = local_28;
    local_30 = 3;
    local_20 = n;
    pvVar1 = lh_retrieve(added,&local_30);
    if (pvVar1 != (void *)0x0) {
      pcVar2 = **(char ***)((int)pvVar1 + 4);
      goto LAB_080d68c8;
    }
    line = 0x15b;
  }
  ERR_put_error(8,0x68,0x65,"obj_dat.c",line);
  pcVar2 = (char *)0x0;
LAB_080d68c8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pcVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

