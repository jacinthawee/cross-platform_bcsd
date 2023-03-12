
int nbiof_read(BIO *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint len;
  int in_GS_OFFSET;
  byte local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (param_2 == (void *)0x0) {
    iVar1 = 0;
  }
  else if (param_1->next_bio != (bio_st *)0x0) {
    BIO_clear_flags(param_1,0xf);
    RAND_pseudo_bytes(&local_11,1);
    local_11 = local_11 & 7;
    len = (uint)local_11;
    if ((int)param_3 < (int)(uint)local_11) {
      len = param_3;
    }
    if (local_11 == 0) {
      BIO_set_flags(param_1,9);
      iVar1 = -1;
    }
    else {
      iVar1 = BIO_read(param_1->next_bio,param_2,len);
      if (iVar1 < 0) {
        BIO_copy_next_retry(param_1);
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

