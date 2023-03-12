
int added_obj_LHASH_COMP(int *param_1,int *param_2)

{
  char **ppcVar1;
  char *__s1;
  char **ppcVar2;
  char *__s2;
  int iVar3;
  
  iVar3 = *param_1;
  if (iVar3 - *param_2 != 0) {
    return iVar3 - *param_2;
  }
  ppcVar1 = (char **)param_1[1];
  ppcVar2 = (char **)param_2[1];
  switch(iVar3) {
  case 0:
    if ((int)ppcVar1[3] - (int)ppcVar2[3] != 0) {
      return (int)ppcVar1[3] - (int)ppcVar2[3];
    }
    iVar3 = (*(code *)PTR_memcmp_0018a06c)(ppcVar1[4],ppcVar2[4]);
    return iVar3;
  case 1:
    __s1 = *ppcVar1;
    if (__s1 != (char *)0x0) {
      __s2 = *ppcVar2;
      if (__s2 == (char *)0x0) {
        return iVar3;
      }
LAB_0006e862:
      iVar3 = strcmp(__s1,__s2);
      return iVar3;
    }
    break;
  case 2:
    __s1 = ppcVar1[1];
    if (__s1 != (char *)0x0) {
      __s2 = ppcVar2[1];
      if (__s2 == (char *)0x0) {
        return 1;
      }
      goto LAB_0006e862;
    }
    break;
  case 3:
    return (int)ppcVar1[2] - (int)ppcVar2[2];
  default:
    return 0;
  }
  return -1;
}

