
size_t buffer_read(BIO *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  size_t __n;
  size_t local_24;
  
  if ((param_2 == (void *)0x0) || (piVar1 = (int *)param_1->ptr, piVar1 == (int *)0x0)) {
    return 0;
  }
  __n = 0;
  if (param_1->next_bio != (bio_st *)0x0) {
    BIO_clear_flags(param_1,0xf);
    __n = piVar1[3];
    local_24 = 0;
    while( true ) {
      if (__n != 0) {
        if ((int)param_3 <= (int)__n) {
          __n = param_3;
        }
        memcpy(param_2,(void *)(piVar1[4] + piVar1[2]),__n);
        local_24 = local_24 + __n;
        piVar1[4] = piVar1[4] + __n;
        piVar1[3] = piVar1[3] - __n;
        if (param_3 == __n) goto LAB_08119e97;
        param_3 = param_3 - __n;
        param_2 = (void *)((int)param_2 + __n);
      }
      if (*piVar1 < (int)param_3) goto LAB_08119eb4;
      __n = BIO_read(param_1->next_bio,(void *)piVar1[2],*piVar1);
      if ((int)__n < 1) break;
      piVar1[4] = 0;
      piVar1[3] = __n;
    }
LAB_08119e74:
    BIO_copy_next_retry(param_1);
    if ((0 < (int)local_24) || (__n == 0)) {
LAB_08119e97:
      __n = local_24;
    }
  }
  return __n;
LAB_08119eb4:
  __n = BIO_read(param_1->next_bio,param_2,param_3);
  if ((int)__n < 1) goto LAB_08119e74;
  local_24 = local_24 + __n;
  if (param_3 == __n) goto LAB_08119e97;
  param_2 = (void *)((int)param_2 + __n);
  param_3 = param_3 - __n;
  goto LAB_08119eb4;
}

