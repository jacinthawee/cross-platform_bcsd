
int nbiof_read(BIO *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint len;
  byte local_18 [8];
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  if (param_1->next_bio != (bio_st *)0x0) {
    BIO_clear_flags(param_1,0xf);
    RAND_pseudo_bytes(local_18,1);
    if ((local_18[0] & 7) == 0) {
      BIO_set_flags(param_1,9);
      iVar1 = -1;
    }
    else {
      len = local_18[0] & 7;
      if ((int)param_3 <= (int)(local_18[0] & 7)) {
        len = param_3;
      }
      iVar1 = BIO_read(param_1->next_bio,param_2,len);
      if (-1 < iVar1) {
        return iVar1;
      }
      BIO_copy_next_retry(param_1);
    }
    return iVar1;
  }
  return 0;
}

