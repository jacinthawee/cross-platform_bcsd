
int SetBlobCmp(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  iVar2 = param_2[1];
  iVar1 = iVar3;
  if (iVar2 <= iVar3) {
    iVar1 = iVar2;
  }
  iVar1 = (*(code *)PTR_memcmp_006a9ad0)(*param_1,*param_2,iVar1,param_4,&_gp);
  if (iVar1 == 0) {
    iVar1 = iVar3 - iVar2;
  }
  return iVar1;
}

