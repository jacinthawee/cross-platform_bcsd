
char * OBJ_nid2ln(int n)

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
      pcVar2 = *(char **)(&DAT_0013fb48 + n * 0x18);
      iVar1 = n * 2;
      if (pcVar2 == (char *)0x0) {
        iVar1 = 0x176;
        goto LAB_0006c7e4;
      }
    }
    pcVar2 = (&PTR_s_undefined_0013fb44)[(n + iVar1) * 2];
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
      return *(char **)(*(int *)(pcVar2 + 4) + 4);
    }
    iVar1 = 0x184;
LAB_0006c7e4:
    ERR_put_error(8,0x66,0x65,"obj_dat.c",iVar1);
  }
  return pcVar2;
}

