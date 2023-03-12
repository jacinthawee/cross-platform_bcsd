
BIO * nbiof_write(BIO *param_1,void *param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  BIO *pBVar3;
  undefined4 unaff_r7;
  void *pvVar4;
  bool bVar5;
  bool bVar6;
  byte local_20 [8];
  
  bVar5 = (int)param_2 < 0;
  bVar6 = param_2 == (void *)0x0;
  if (!bVar6) {
    bVar5 = (int)param_3 < 0;
  }
  bVar1 = param_3 == 0;
  if ((bVar6 || bVar1) || bVar5) {
    param_1 = (BIO *)0x0;
  }
  if ((bVar6 || bVar1) || bVar5) {
    unaff_r7 = 1;
  }
  if ((!bVar6 && !bVar1) && !bVar5) {
    unaff_r7 = 0;
  }
  pBVar3 = param_1;
  if ((!bVar6 && !bVar1) && !bVar5) {
    if (param_1->next_bio == (bio_st *)0x0) {
      return (BIO *)0x0;
    }
    pvVar4 = param_1->ptr;
    BIO_clear_flags(param_1,0xf);
    uVar2 = *(uint *)((int)pvVar4 + 4);
    if ((int)uVar2 < 1) {
      RAND_pseudo_bytes(local_20,1);
      uVar2 = local_20[0] & 7;
    }
    else {
      *(undefined4 *)((int)pvVar4 + 4) = unaff_r7;
    }
    if (((int)uVar2 < (int)param_3) && (param_3 = uVar2, uVar2 == 0)) {
      BIO_set_flags(param_1,10);
      pBVar3 = (BIO *)0xffffffff;
    }
    else {
      pBVar3 = (BIO *)BIO_write(param_1->next_bio,param_2,param_3);
      if ((int)pBVar3 < 0) {
        BIO_copy_next_retry(param_1);
        *(uint *)((int)pvVar4 + 4) = param_3;
      }
    }
  }
  return pBVar3;
}

