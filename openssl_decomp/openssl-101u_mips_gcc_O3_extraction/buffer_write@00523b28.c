
int buffer_write(BIO *param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  
  if ((((param_2 == (void *)0x0) || (param_3 < 1)) || (pvVar5 = param_1->ptr, pvVar5 == (void *)0x0)
      ) || (param_1->next_bio == (bio_st *)0x0)) {
    return 0;
  }
  iVar7 = 0;
  BIO_clear_flags(param_1,0xf);
  iVar1 = *(int *)((int)pvVar5 + 4);
  do {
    iVar4 = *(int *)((int)pvVar5 + 0x18);
    iVar3 = *(int *)((int)pvVar5 + 0x1c);
    iVar2 = iVar4 + iVar3;
    iVar8 = iVar1 - iVar2;
    if (param_3 <= iVar8) {
      (*(code *)PTR_memcpy_006a9aec)(*(int *)((int)pvVar5 + 0x14) + iVar2,param_2,param_3);
      *(int *)((int)pvVar5 + 0x18) = *(int *)((int)pvVar5 + 0x18) + param_3;
      return param_3 + iVar7;
    }
    if (iVar4 != 0) {
      pvVar6 = param_2;
      if (0 < iVar8) {
        pvVar6 = (void *)((int)param_2 + iVar8);
        param_3 = param_3 - iVar8;
        (*(code *)PTR_memcpy_006a9aec)(*(int *)((int)pvVar5 + 0x14) + iVar2,param_2,iVar8);
        iVar7 = iVar7 + iVar8;
        iVar3 = *(int *)((int)pvVar5 + 0x1c);
        iVar4 = iVar8 + *(int *)((int)pvVar5 + 0x18);
        *(int *)((int)pvVar5 + 0x18) = iVar4;
      }
      do {
        iVar4 = BIO_write(param_1->next_bio,(void *)(*(int *)((int)pvVar5 + 0x14) + iVar3),iVar4);
        if (iVar4 < 1) goto LAB_00523bf8;
        iVar3 = iVar4 + *(int *)((int)pvVar5 + 0x1c);
        iVar4 = *(int *)((int)pvVar5 + 0x18) - iVar4;
        *(int *)((int)pvVar5 + 0x1c) = iVar3;
        *(int *)((int)pvVar5 + 0x18) = iVar4;
      } while (iVar4 != 0);
      iVar1 = *(int *)((int)pvVar5 + 4);
      param_2 = pvVar6;
    }
    *(undefined4 *)((int)pvVar5 + 0x1c) = 0;
    while (iVar1 <= param_3) {
      iVar4 = BIO_write(param_1->next_bio,param_2,param_3);
      param_3 = param_3 - iVar4;
      if (iVar4 < 1) {
LAB_00523bf8:
        BIO_copy_next_retry(param_1);
        if (iVar4 == 0) {
          return iVar7;
        }
        if (iVar7 != 0) {
          return iVar7;
        }
        return iVar4;
      }
      iVar7 = iVar7 + iVar4;
      param_2 = (void *)((int)param_2 + iVar4);
      if (param_3 == 0) {
        return iVar7;
      }
      iVar1 = *(int *)((int)pvVar5 + 4);
    }
  } while( true );
}

