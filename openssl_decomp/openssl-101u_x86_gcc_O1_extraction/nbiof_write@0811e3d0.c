
int nbiof_write(BIO *param_1,void *param_2,uint param_3)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int in_GS_OFFSET;
  byte local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = 0;
  if ((param_2 == (void *)0x0) || ((int)param_3 < 1)) {
    iVar3 = 0;
  }
  else if (param_1->next_bio != (bio_st *)0x0) {
    pvVar1 = param_1->ptr;
    BIO_clear_flags(param_1,0xf);
    uVar2 = *(uint *)((int)pvVar1 + 4);
    if ((int)uVar2 < 1) {
      iVar3 = RAND_bytes(&local_21,1);
      if (iVar3 < 1) {
        iVar3 = -1;
        goto LAB_0811e436;
      }
      if (((int)(local_21 & 7) < (int)param_3) && (param_3 = local_21 & 7, (local_21 & 7) == 0)) {
        BIO_set_flags(param_1,10);
        iVar3 = -1;
        goto LAB_0811e436;
      }
    }
    else {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      if ((int)uVar2 < (int)param_3) {
        param_3 = uVar2;
      }
    }
    iVar3 = BIO_write(param_1->next_bio,param_2,param_3);
    if (iVar3 < 0) {
      BIO_copy_next_retry(param_1);
      *(uint *)((int)pvVar1 + 4) = param_3;
    }
  }
LAB_0811e436:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

