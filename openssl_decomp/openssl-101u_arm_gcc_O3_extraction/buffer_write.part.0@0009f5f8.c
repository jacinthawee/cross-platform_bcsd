
int buffer_write_part_0(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  int len;
  int iVar3;
  void *pvVar4;
  size_t __n;
  int iVar5;
  
  pvVar4 = param_1->ptr;
  if (pvVar4 == (void *)0x0) {
    return 0;
  }
  if (param_1->next_bio == (bio_st *)0x0) {
    return 0;
  }
  BIO_clear_flags(param_1,0xf);
  iVar3 = *(int *)((int)pvVar4 + 4);
  iVar5 = 0;
  do {
    len = *(int *)((int)pvVar4 + 0x18);
    iVar2 = *(int *)((int)pvVar4 + 0x1c);
    iVar1 = len + iVar2;
    __n = iVar3 - iVar1;
    if ((int)param_3 <= (int)__n) {
      memcpy((void *)(iVar1 + *(int *)((int)pvVar4 + 0x14)),param_2,param_3);
      *(size_t *)((int)pvVar4 + 0x18) = *(int *)((int)pvVar4 + 0x18) + param_3;
      return param_3 + iVar5;
    }
    if (len != 0) {
      if (0 < (int)__n) {
        param_3 = param_3 - __n;
        iVar5 = iVar5 + __n;
        memcpy((void *)(iVar1 + *(int *)((int)pvVar4 + 0x14)),param_2,__n);
        iVar2 = *(int *)((int)pvVar4 + 0x1c);
        param_2 = (void *)((int)param_2 + __n);
        len = *(int *)((int)pvVar4 + 0x18) + __n;
        *(int *)((int)pvVar4 + 0x18) = len;
      }
      do {
        iVar2 = BIO_write(param_1->next_bio,(void *)(iVar2 + *(int *)((int)pvVar4 + 0x14)),len);
        if (iVar2 < 1) {
          BIO_copy_next_retry(param_1);
          goto joined_r0x0009f66e;
        }
        len = *(int *)((int)pvVar4 + 0x18) - iVar2;
        *(int *)((int)pvVar4 + 0x18) = len;
        iVar2 = *(int *)((int)pvVar4 + 0x1c) + iVar2;
        *(int *)((int)pvVar4 + 0x1c) = iVar2;
      } while (len != 0);
      iVar3 = *(int *)((int)pvVar4 + 4);
    }
    *(undefined4 *)((int)pvVar4 + 0x1c) = 0;
    while (iVar3 <= (int)param_3) {
      iVar2 = BIO_write(param_1->next_bio,param_2,param_3);
      param_2 = (void *)((int)param_2 + iVar2);
      if (iVar2 < 1) {
        BIO_copy_next_retry(param_1);
joined_r0x0009f66e:
        if (iVar2 == 0) {
          return iVar5;
        }
        if (iVar5 == 0) {
          iVar5 = iVar2;
        }
        return iVar5;
      }
      param_3 = param_3 - iVar2;
      iVar5 = iVar5 + iVar2;
      if (param_3 == 0) {
        return iVar5;
      }
      iVar3 = *(int *)((int)pvVar4 + 4);
    }
  } while( true );
}

