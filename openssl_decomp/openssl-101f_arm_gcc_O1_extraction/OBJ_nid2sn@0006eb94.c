
char * OBJ_nid2sn(int n)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_28;
  undefined *local_24;
  undefined auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x398) {
    iVar1 = n;
    if (n != 0) {
      pcVar2 = *(char **)(&DAT_00140f90 + n * 0x18);
      iVar1 = n * 2;
      if (pcVar2 == (char *)0x0) {
        iVar1 = 0x14a;
        goto LAB_0006ebfe;
      }
    }
    pcVar2 = (&nid_objs)[(n + iVar1) * 2];
  }
  else {
    if (added == (_LHASH *)0x0) {
      return (char *)0x0;
    }
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    pcVar2 = (char *)lh_retrieve(added,&local_28);
    if (pcVar2 != (char *)0x0) {
      return **(char ***)(pcVar2 + 4);
    }
    iVar1 = 0x15b;
LAB_0006ebfe:
    ERR_put_error(8,0x68,0x65,"obj_dat.c",iVar1);
  }
  return pcVar2;
}

