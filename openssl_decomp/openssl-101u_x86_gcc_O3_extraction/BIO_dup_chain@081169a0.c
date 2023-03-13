
BIO * BIO_dup_chain(BIO *in)

{
  CRYPTO_EX_DATA *ad;
  BIO_METHOD *pBVar1;
  _func_600 *p_Var2;
  _func_601 *p_Var3;
  bio_st *pbVar4;
  bio_st *pbVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  bio_st *pbVar9;
  bio_st *pbVar10;
  bio_st *local_20;
  
  pbVar9 = (bio_st *)0x0;
  local_20 = (BIO *)0x0;
  if (in != (BIO *)0x0) {
    while( true ) {
      pBVar1 = in->method;
      pbVar5 = (bio_st *)CRYPTO_malloc(0x40,"bio_lib.c",0x46);
      if (pbVar5 == (bio_st *)0x0) {
        ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x48);
        goto LAB_08116b4b;
      }
      ad = &pbVar5->ex_data;
      pbVar5->callback = (_func_603 *)0x0;
      pbVar5->cb_arg = (char *)0x0;
      pbVar5->init = 0;
      pbVar5->shutdown = 1;
      pbVar5->method = pBVar1;
      pbVar5->flags = 0;
      pbVar5->retry_reason = 0;
      pbVar5->num = 0;
      pbVar5->ptr = (void *)0x0;
      pbVar5->prev_bio = (bio_st *)0x0;
      pbVar5->next_bio = (bio_st *)0x0;
      pbVar5->references = 1;
      pbVar5->num_read = 0;
      pbVar5->num_write = 0;
      CRYPTO_new_ex_data(0,pbVar5,ad);
      p_Var2 = pBVar1->create;
      if ((p_Var2 != (_func_600 *)0x0) && (iVar6 = (*p_Var2)(pbVar5), iVar6 == 0)) break;
      pbVar5->callback = in->callback;
      pbVar5->cb_arg = in->cb_arg;
      pbVar5->init = in->init;
      pbVar5->shutdown = in->shutdown;
      pbVar5->flags = in->flags;
      pbVar5->num = in->num;
      lVar7 = BIO_ctrl(in,0xc,0,pbVar5);
      if ((lVar7 == 0) || (iVar6 = CRYPTO_dup_ex_data(0,ad,&in->ex_data), iVar6 == 0)) {
        iVar6 = CRYPTO_add_lock(&pbVar5->references,-1,0x15,"bio_lib.c",0x72);
        if ((iVar6 < 1) &&
           ((pbVar5->callback == (_func_603 *)0x0 ||
            (lVar7 = (*pbVar5->callback)(pbVar5,1,(char *)0x0,0,0,1), 0 < lVar7)))) {
          CRYPTO_free_ex_data(0,pbVar5,ad);
          if ((pbVar5->method != (BIO_METHOD *)0x0) &&
             (p_Var3 = pbVar5->method->destroy, p_Var3 != (_func_601 *)0x0)) {
            (*p_Var3)(pbVar5);
          }
          CRYPTO_free(pbVar5);
        }
        goto LAB_08116b4b;
      }
      pbVar10 = pbVar5;
      if ((pbVar9 != (bio_st *)0x0) && (pbVar4 = local_20, pbVar10 = pbVar9, local_20 != (BIO *)0x0)
         ) {
        do {
          pbVar9 = pbVar4;
          pbVar4 = pbVar9->next_bio;
        } while (pbVar9->next_bio != (bio_st *)0x0);
        pbVar9->next_bio = pbVar5;
        pbVar5->prev_bio = pbVar9;
        BIO_ctrl(local_20,6,0,pbVar9);
      }
      in = in->next_bio;
      pbVar9 = pbVar10;
      local_20 = pbVar5;
      if (in == (bio_st *)0x0) {
        return pbVar10;
      }
    }
    CRYPTO_free_ex_data(0,pbVar5,ad);
    CRYPTO_free(pbVar5);
LAB_08116b4b:
    do {
      if (pbVar9 == (bio_st *)0x0) {
        return (BIO *)0x0;
      }
      iVar6 = pbVar9->references;
      pbVar5 = pbVar9->next_bio;
      iVar8 = CRYPTO_add_lock(&pbVar9->references,-1,0x15,"bio_lib.c",0x72);
      if ((iVar8 < 1) &&
         ((pbVar9->callback == (_func_603 *)0x0 ||
          (lVar7 = (*pbVar9->callback)(pbVar9,1,(char *)0x0,0,0,1), 0 < lVar7)))) {
        CRYPTO_free_ex_data(0,pbVar9,&pbVar9->ex_data);
        if ((pbVar9->method != (BIO_METHOD *)0x0) &&
           (p_Var3 = pbVar9->method->destroy, p_Var3 != (_func_601 *)0x0)) {
          (*p_Var3)(pbVar9);
        }
        CRYPTO_free(pbVar9);
      }
      pbVar9 = pbVar5;
    } while (iVar6 < 2);
  }
  return (BIO *)0x0;
}

