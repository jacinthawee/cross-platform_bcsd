
bio_st * asn1_bio_write(BIO *param_1,void *param_2,uint param_3)

{
  int iVar1;
  bio_st *pbVar2;
  BIO_METHOD *pBVar3;
  bio_st *pbVar4;
  uint len;
  ulong len_00;
  stack_st_void *psVar5;
  bio_st *pbVar6;
  bio_st *pbVar7;
  _func_603 *local_2c [2];
  
  pbVar4 = (bio_st *)(param_3 >> 0x1f);
  if (param_2 == (void *)0x0) {
    pbVar4 = (bio_st *)0x1;
  }
  pbVar6 = (bio_st *)0x0;
  if (((pbVar4 != (bio_st *)0x0) || (pbVar6 = param_1->next_bio, pbVar6 == (bio_st *)0x0)) ||
     (pbVar6 = (bio_st *)param_1->ptr, pbVar6 == (bio_st *)0x0)) {
    return pbVar6;
  }
  pBVar3 = pbVar6->method;
  do {
    switch(pBVar3) {
    case (BIO_METHOD *)0x0:
      if (((code *)pbVar6->ptr != (code *)0x0) &&
         (iVar1 = (*(code *)pbVar6->ptr)
                            (param_1,&pbVar6->num_read,&pbVar6->num_write,&(pbVar6->ex_data).dummy),
         iVar1 == 0)) {
        BIO_clear_flags(param_1,0xf);
        return (bio_st *)0x0;
      }
      if ((int)pbVar6->num_write < 1) {
        pBVar3 = (BIO_METHOD *)0x2;
      }
      else {
        pBVar3 = (BIO_METHOD *)0x1;
      }
      pbVar6->method = pBVar3;
      break;
    case (BIO_METHOD *)0x1:
      len_00 = pbVar6->num_write;
      pbVar7 = pbVar6->next_bio;
      if (0 < (int)len_00) {
        psVar5 = (pbVar6->ex_data).sk;
        while( true ) {
          pbVar2 = (bio_st *)
                   BIO_write(param_1->next_bio,
                             (void *)((int)&(psVar5->stack).num + pbVar6->num_read),len_00);
          if ((int)pbVar2 < 1) goto LAB_001210ec;
          len_00 = pbVar6->num_write - (int)pbVar2;
          pbVar6->num_write = len_00;
          if ((int)len_00 < 1) break;
          psVar5 = (stack_st_void *)((int)&pbVar2->method + (int)(pbVar6->ex_data).sk);
          (pbVar6->ex_data).sk = psVar5;
        }
        if (pbVar7 != (bio_st *)0x0) {
          (*(code *)pbVar7)(param_1,&pbVar6->num_read,&pbVar6->num_write,&(pbVar6->ex_data).dummy);
        }
        pbVar6->method = (BIO_METHOD *)0x2;
        pBVar3 = (BIO_METHOD *)0x2;
        (pbVar6->ex_data).sk = (stack_st_void *)0x0;
      }
      break;
    case (BIO_METHOD *)0x2:
      iVar1 = ASN1_object_size(0,param_3,pbVar6->num);
      pbVar6->shutdown = iVar1 - param_3;
      if ((int)pbVar6->cb_arg < (int)(iVar1 - param_3)) {
        OpenSSLDie("bio_asn1.c",0xe8,"ctx->buflen <= ctx->bufsize");
      }
      local_2c[0] = pbVar6->callback;
      ASN1_put_object((uchar **)local_2c,0,param_3,pbVar6->num,pbVar6->retry_reason);
      pBVar3 = (BIO_METHOD *)0x3;
      pbVar6->flags = param_3;
      pbVar6->method = (BIO_METHOD *)0x3;
      break;
    case (BIO_METHOD *)0x3:
      pbVar2 = (bio_st *)
               BIO_write(param_1->next_bio,pbVar6->callback + pbVar6->init,pbVar6->shutdown);
      if ((int)pbVar2 < 1) {
LAB_001210ec:
        BIO_clear_flags(param_1,0xf);
        BIO_copy_next_retry(param_1);
        if (pbVar4 == (bio_st *)0x0) {
          return pbVar2;
        }
        return pbVar4;
      }
      iVar1 = pbVar6->shutdown - (int)pbVar2;
      pbVar6->shutdown = iVar1;
      if (iVar1 == 0) {
        pbVar6->init = 0;
        pBVar3 = (BIO_METHOD *)0x4;
        pbVar6->method = (BIO_METHOD *)0x4;
      }
      else {
        pBVar3 = pbVar6->method;
        pbVar6->init = (int)&pbVar2->method + pbVar6->init;
      }
      break;
    case (BIO_METHOD *)0x4:
      len = pbVar6->flags;
      if ((int)param_3 <= pbVar6->flags) {
        len = param_3;
      }
      iVar1 = BIO_write(param_1->next_bio,param_2,len);
      if (0 < iVar1) {
        pbVar4 = (bio_st *)((int)&pbVar4->method + iVar1);
        param_2 = (void *)((int)param_2 + iVar1);
        param_3 = param_3 - iVar1;
        iVar1 = pbVar6->flags - iVar1;
        pbVar6->flags = iVar1;
        if (iVar1 == 0) {
          pbVar6->method = (BIO_METHOD *)0x2;
        }
        if (param_3 == 0) {
          BIO_clear_flags(param_1,0xf);
          BIO_copy_next_retry(param_1);
          return pbVar4;
        }
      }
      pBVar3 = pbVar6->method;
      break;
    default:
      BIO_clear_flags(param_1,0xf);
      return (bio_st *)0x0;
    }
  } while( true );
}

