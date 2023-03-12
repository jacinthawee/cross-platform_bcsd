
BIO * BIO_dup_chain(BIO *in)

{
  undefined *puVar1;
  bio_st *pbVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  bio_st *pbVar6;
  BIO *parg;
  int iVar7;
  int iVar8;
  char *pcVar9;
  bio_st *pbVar10;
  bio_st *pbVar11;
  BIO *bp;
  CRYPTO_EX_DATA *pCVar12;
  _func_600 *p_Var13;
  _func_601 *p_Var14;
  BIO_METHOD *pBVar15;
  
  if (in == (BIO *)0x0) {
    return (BIO *)0x0;
  }
  pbVar10 = (bio_st *)0x0;
  bp = (BIO *)0x0;
  while( true ) {
    pBVar15 = in->method;
    pbVar2 = (bio_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x40,"bio_lib.c",0x46);
    puVar1 = PTR_CRYPTO_new_ex_data_006a8314;
    if (pbVar2 == (bio_st *)0x0) {
      ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x48);
      goto joined_r0x0051fecc;
    }
    pCVar12 = &pbVar2->ex_data;
    pbVar2->method = pBVar15;
    pbVar2->callback = (_func_603 *)0x0;
    pbVar2->cb_arg = (char *)0x0;
    pbVar2->init = 0;
    pbVar2->shutdown = 1;
    pbVar2->flags = 0;
    pbVar2->retry_reason = 0;
    pbVar2->num = 0;
    pbVar2->ptr = (void *)0x0;
    pbVar2->prev_bio = (bio_st *)0x0;
    pbVar2->next_bio = (bio_st *)0x0;
    pbVar2->references = 1;
    pbVar2->num_read = 0;
    pbVar2->num_write = 0;
    (*(code *)puVar1)(0,pbVar2,pCVar12);
    p_Var13 = pBVar15->create;
    if ((p_Var13 != (_func_600 *)0x0) && (iVar3 = (*p_Var13)(pbVar2), iVar3 == 0)) break;
    pcVar9 = in->cb_arg;
    iVar8 = in->init;
    iVar7 = in->shutdown;
    iVar5 = in->flags;
    iVar3 = in->num;
    pbVar2->callback = in->callback;
    pbVar2->cb_arg = pcVar9;
    pbVar2->init = iVar8;
    pbVar2->shutdown = iVar7;
    pbVar2->flags = iVar5;
    pbVar2->num = iVar3;
    lVar4 = BIO_ctrl(in,0xc,0,pbVar2);
    if ((lVar4 == 0) ||
       (iVar3 = (*(code *)PTR_CRYPTO_dup_ex_data_006a8354)(0,pCVar12,&in->ex_data), iVar3 == 0)) {
      iVar3 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                        (&pbVar2->references,0xffffffff,0x15,"bio_lib.c",0x72);
      if ((iVar3 < 1) &&
         ((pbVar2->callback == (_func_603 *)0x0 ||
          (lVar4 = (*pbVar2->callback)(pbVar2,1,(char *)0x0,0,0,1), 0 < lVar4)))) {
        (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0,pbVar2,pCVar12);
        if ((pbVar2->method != (BIO_METHOD *)0x0) &&
           (p_Var14 = pbVar2->method->destroy, p_Var14 != (_func_601 *)0x0)) {
          (*p_Var14)(pbVar2);
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar2);
      }
      goto joined_r0x0051fecc;
    }
    pbVar11 = pbVar2;
    if ((pbVar10 != (bio_st *)0x0) && (pbVar11 = pbVar10, bp != (BIO *)0x0)) {
      pbVar10 = bp->next_bio;
      parg = bp;
      while (pbVar6 = pbVar10, pbVar6 != (bio_st *)0x0) {
        parg = pbVar6;
        pbVar10 = pbVar6->next_bio;
      }
      parg->next_bio = pbVar2;
      pbVar2->prev_bio = parg;
      BIO_ctrl(bp,6,0,parg);
    }
    in = in->next_bio;
    pbVar10 = pbVar11;
    bp = pbVar2;
    if (in == (bio_st *)0x0) {
      return pbVar11;
    }
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0,pbVar2,pCVar12);
  (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar2);
joined_r0x0051fecc:
  do {
    if (pbVar10 == (bio_st *)0x0) {
      return (BIO *)0x0;
    }
    iVar5 = pbVar10->references;
    pbVar2 = pbVar10->next_bio;
    iVar3 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                      (&pbVar10->references,0xffffffff,0x15,"bio_lib.c",0x72);
    if ((iVar3 < 1) &&
       ((pbVar10->callback == (_func_603 *)0x0 ||
        (lVar4 = (*pbVar10->callback)(pbVar10,1,(char *)0x0,0,0,1), 0 < lVar4)))) {
      (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0,pbVar10,&pbVar10->ex_data);
      if ((pbVar10->method != (BIO_METHOD *)0x0) &&
         (p_Var14 = pbVar10->method->destroy, p_Var14 != (_func_601 *)0x0)) {
        (*p_Var14)(pbVar10);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar10);
    }
    pbVar10 = pbVar2;
  } while (iVar5 < 2);
  return (BIO *)0x0;
}

