
int added_obj_LHASH_COMP(int *param_1,int *param_2)

{
  char **ppcVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  iVar4 = iVar3 - *param_2;
  if (iVar4 == 0) {
    ppcVar1 = (char **)param_1[1];
    ppcVar2 = (char **)param_2[1];
    if (iVar3 == 1) {
      if (*ppcVar1 != (char *)0x0) {
        if (*ppcVar2 == (char *)0x0) {
          return 1;
        }
        iVar3 = strcmp(*ppcVar1,*ppcVar2);
        return iVar3;
      }
    }
    else {
      if (iVar3 < 2) {
        if (iVar3 != 0) {
          return 0;
        }
        iVar3 = (int)ppcVar1[3] - (int)ppcVar2[3];
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = memcmp(ppcVar1[4],ppcVar2[4],(size_t)ppcVar1[3]);
        return iVar3;
      }
      if (iVar3 != 2) {
        if (iVar3 != 3) {
          return 0;
        }
        return (int)ppcVar1[2] - (int)ppcVar2[2];
      }
      if (ppcVar1[1] != (char *)0x0) {
        if (ppcVar2[1] == (char *)0x0) {
          return 1;
        }
        iVar3 = strcmp(ppcVar1[1],ppcVar2[1]);
        return iVar3;
      }
    }
    iVar4 = -1;
  }
  return iVar4;
}

