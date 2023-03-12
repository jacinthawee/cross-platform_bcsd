
int obj_cmp_BSEARCH_CMP_FN(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0xc);
  iVar1 = iVar2 - *(int *)(&DAT_0013fb4c + *param_2 * 0x18);
  if ((iVar1 == 0) && (iVar1 = iVar2, iVar2 != 0)) {
    iVar1 = (*(code *)PTR_memcmp_0018906c)
                      (*(undefined4 *)(*param_1 + 0x10),
                       *(undefined4 *)(&DAT_0013fb50 + *param_2 * 0x18));
    return iVar1;
  }
  return iVar1;
}

