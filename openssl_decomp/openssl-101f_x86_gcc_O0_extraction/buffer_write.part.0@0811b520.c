
int __regparm3 buffer_write_part_0(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void *pvVar2;
  int len;
  int iVar3;
  int iVar4;
  size_t __n;
  int local_24;
  
  pvVar2 = param_1->ptr;
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  local_24 = 0;
  if (param_1->next_bio != (bio_st *)0x0) {
    BIO_clear_flags(param_1,0xf);
    iVar4 = *(int *)((int)pvVar2 + 4);
    local_24 = 0;
    while( true ) {
      len = *(int *)((int)pvVar2 + 0x18);
      iVar3 = *(int *)((int)pvVar2 + 0x1c);
      iVar1 = len + iVar3;
      __n = iVar4 - iVar1;
      if ((int)param_3 <= (int)__n) break;
      if (len != 0) {
        if (0 < (int)__n) {
          param_3 = param_3 - __n;
          memcpy((void *)(iVar1 + *(int *)((int)pvVar2 + 0x14)),param_2,__n);
          local_24 = local_24 + __n;
          iVar3 = *(int *)((int)pvVar2 + 0x1c);
          len = *(int *)((int)pvVar2 + 0x18) + __n;
          *(int *)((int)pvVar2 + 0x18) = len;
          param_2 = (void *)((int)param_2 + __n);
        }
        do {
          iVar3 = BIO_write(param_1->next_bio,(void *)(iVar3 + *(int *)((int)pvVar2 + 0x14)),len);
          if (iVar3 < 1) {
            BIO_copy_next_retry(param_1);
            if (0 < local_24) {
              return local_24;
            }
            if (iVar3 == 0) {
              return local_24;
            }
            return iVar3;
          }
          len = *(int *)((int)pvVar2 + 0x18) - iVar3;
          iVar3 = *(int *)((int)pvVar2 + 0x1c) + iVar3;
          *(int *)((int)pvVar2 + 0x1c) = iVar3;
          *(int *)((int)pvVar2 + 0x18) = len;
        } while (len != 0);
        iVar4 = *(int *)((int)pvVar2 + 4);
      }
      *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
      while (iVar4 <= (int)param_3) {
        iVar4 = BIO_write(param_1->next_bio,param_2,param_3);
        if (iVar4 < 1) {
          BIO_copy_next_retry(param_1);
          if ((iVar4 != 0) && (local_24 < 1)) {
            return iVar4;
          }
          return local_24;
        }
        local_24 = local_24 + iVar4;
        param_2 = (void *)((int)param_2 + iVar4);
        param_3 = param_3 - iVar4;
        if (param_3 == 0) {
          return local_24;
        }
        iVar4 = *(int *)((int)pvVar2 + 4);
      }
    }
    memcpy((void *)(iVar1 + *(int *)((int)pvVar2 + 0x14)),param_2,param_3);
    *(int *)((int)pvVar2 + 0x18) = *(int *)((int)pvVar2 + 0x18) + param_3;
    local_24 = local_24 + param_3;
  }
  return local_24;
}

