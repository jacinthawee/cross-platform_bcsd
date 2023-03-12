
BIO * nbiof_write(BIO *param_1,void *param_2,uint param_3)

{
  bool bVar1;
  BIO *pBVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r7;
  void *pvVar5;
  bool bVar6;
  bool bVar7;
  byte local_20 [8];
  
  bVar6 = (int)param_2 < 0;
  bVar7 = param_2 == (void *)0x0;
  if (!bVar7) {
    bVar6 = (int)param_3 < 0;
  }
  bVar1 = param_3 == 0;
  if ((bVar7 || bVar1) || bVar6) {
    param_1 = (BIO *)0x0;
  }
  if ((bVar7 || bVar1) || bVar6) {
    unaff_r7 = 1;
  }
  if ((!bVar7 && !bVar1) && !bVar6) {
    unaff_r7 = 0;
  }
  pBVar2 = param_1;
  if ((!bVar7 && !bVar1) && !bVar6) {
    if (param_1->next_bio == (bio_st *)0x0) {
      return (BIO *)0x0;
    }
    pvVar5 = param_1->ptr;
    BIO_clear_flags(param_1,0xf);
    uVar4 = *(uint *)((int)pvVar5 + 4);
    if ((int)uVar4 < 1) {
      iVar3 = RAND_bytes(local_20,1);
      if (iVar3 < 1) {
        return (BIO *)0xffffffff;
      }
      uVar4 = local_20[0] & 7;
    }
    else {
      *(undefined4 *)((int)pvVar5 + 4) = unaff_r7;
    }
    if (((int)uVar4 < (int)param_3) && (param_3 = uVar4, uVar4 == 0)) {
      BIO_set_flags(param_1,10);
      pBVar2 = (BIO *)0xffffffff;
    }
    else {
      pBVar2 = (BIO *)BIO_write(param_1->next_bio,param_2,param_3);
      if ((int)pBVar2 < 0) {
        BIO_copy_next_retry(param_1);
        *(uint *)((int)pvVar5 + 4) = param_3;
      }
    }
  }
  return pBVar2;
}

