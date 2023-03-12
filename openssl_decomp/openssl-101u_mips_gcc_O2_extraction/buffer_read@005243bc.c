
int buffer_read(BIO *param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *data;
  int iVar4;
  
  if (((param_2 == (void *)0x0) || (piVar3 = (int *)param_1->ptr, piVar3 == (int *)0x0)) ||
     (param_1->next_bio == (bio_st *)0x0)) {
    return 0;
  }
  iVar4 = 0;
  BIO_clear_flags(param_1,0xf);
  iVar2 = piVar3[3];
  while( true ) {
    iVar1 = iVar2;
    if (param_3 <= iVar2) {
      iVar1 = param_3;
    }
    data = param_2;
    if (iVar2 != 0) {
      data = (void *)((int)param_2 + iVar1);
      iVar4 = iVar4 + iVar1;
      (*(code *)PTR_memcpy_006a9aec)(param_2,piVar3[2] + piVar3[4],iVar1);
      piVar3[4] = piVar3[4] + iVar1;
      piVar3[3] = piVar3[3] - iVar1;
      if (param_3 == iVar1) {
        return iVar4;
      }
      param_3 = param_3 - iVar1;
    }
    if (*piVar3 < param_3) goto LAB_00524508;
    iVar2 = BIO_read(param_1->next_bio,(void *)piVar3[2],*piVar3);
    if (iVar2 < 1) break;
    piVar3[4] = 0;
    piVar3[3] = iVar2;
    param_2 = data;
  }
LAB_005244b8:
  BIO_copy_next_retry(param_1);
  if ((iVar2 != 0) && (iVar4 < 1)) {
    iVar4 = iVar2;
  }
  return iVar4;
LAB_00524508:
  while (iVar2 = BIO_read(param_1->next_bio,data,param_3), 0 < iVar2) {
    iVar4 = iVar4 + iVar2;
    if (param_3 == iVar2) {
      return iVar4;
    }
    data = (void *)((int)data + iVar2);
    param_3 = param_3 - iVar2;
  }
  goto LAB_005244b8;
}

