
BIO * BIO_dup_chain(BIO *in)

{
  undefined *puVar1;
  bio_st *parg;
  int iVar2;
  long lVar3;
  int iVar4;
  bio_st *pbVar5;
  BIO *parg_00;
  int iVar6;
  int iVar7;
  char *pcVar8;
  BIO *bp;
  bio_st *pbVar9;
  bio_st *pbVar10;
  CRYPTO_EX_DATA *pCVar11;
  _func_600 *p_Var12;
  _func_601 *p_Var13;
  BIO_METHOD *pBVar14;
  
  if (in == (BIO *)0x0) {
    return (BIO *)0x0;
  }
  bp = (BIO *)0x0;
  pbVar9 = (bio_st *)0x0;
  while( true ) {
    pBVar14 = in->method;
    parg = (bio_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x40,"bio_lib.c",0x46);
    puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
    if (parg == (bio_st *)0x0) {
      ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x49);
      goto LAB_00521de8;
    }
    pCVar11 = &parg->ex_data;
    parg->method = pBVar14;
    parg->callback = (_func_603 *)0x0;
    parg->cb_arg = (char *)0x0;
    parg->init = 0;
    parg->shutdown = 1;
    parg->flags = 0;
    parg->retry_reason = 0;
    parg->num = 0;
    parg->ptr = (void *)0x0;
    parg->prev_bio = (bio_st *)0x0;
    parg->next_bio = (bio_st *)0x0;
    parg->references = 1;
    parg->num_read = 0;
    parg->num_write = 0;
    (*(code *)puVar1)(0,parg,pCVar11);
    p_Var12 = pBVar14->create;
    if ((p_Var12 != (_func_600 *)0x0) && (iVar2 = (*p_Var12)(parg), iVar2 == 0)) break;
    pcVar8 = in->cb_arg;
    iVar7 = in->init;
    iVar6 = in->shutdown;
    iVar4 = in->flags;
    iVar2 = in->num;
    parg->callback = in->callback;
    parg->cb_arg = pcVar8;
    parg->init = iVar7;
    parg->shutdown = iVar6;
    parg->flags = iVar4;
    parg->num = iVar2;
    lVar3 = BIO_ctrl(in,0xc,0,parg);
    if (lVar3 == 0) {
      iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a9080)
                        (&parg->references,0xffffffff,0x15,"bio_lib.c",0x75);
      if ((0 < iVar2) ||
         ((parg->callback != (_func_603 *)0x0 &&
          (lVar3 = (*parg->callback)(parg,1,(char *)0x0,0,0,1), lVar3 < 1)))) goto LAB_00521de8;
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0,parg,pCVar11);
      if ((parg->method == (BIO_METHOD *)0x0) ||
         (p_Var13 = parg->method->destroy, p_Var13 == (_func_601 *)0x0)) goto LAB_00521de8;
      (*p_Var13)(parg);
      goto LAB_00521dd8;
    }
    iVar2 = (*(code *)PTR_CRYPTO_dup_ex_data_006a9474)(0,pCVar11,&in->ex_data);
    if (iVar2 == 0) goto LAB_00521de8;
    pbVar10 = parg;
    if ((pbVar9 != (bio_st *)0x0) && (pbVar10 = pbVar9, bp != (BIO *)0x0)) {
      pbVar9 = bp->next_bio;
      parg_00 = bp;
      while (pbVar5 = pbVar9, pbVar5 != (bio_st *)0x0) {
        parg_00 = pbVar5;
        pbVar9 = pbVar5->next_bio;
      }
      parg_00->next_bio = parg;
      parg->prev_bio = parg_00;
      BIO_ctrl(bp,6,0,parg_00);
    }
    in = in->next_bio;
    bp = parg;
    pbVar9 = pbVar10;
    if (in == (bio_st *)0x0) {
      return pbVar10;
    }
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0,parg,pCVar11);
LAB_00521dd8:
  (*(code *)PTR_CRYPTO_free_006a7f88)(parg);
LAB_00521de8:
  if (((pbVar9 != (bio_st *)0x0) &&
      (iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a9080)
                         (&pbVar9->references,0xffffffff,0x15,"bio_lib.c",0x75), iVar2 < 1)) &&
     ((pbVar9->callback == (_func_603 *)0x0 ||
      (lVar3 = (*pbVar9->callback)(pbVar9,1,(char *)0x0,0,0,1), 0 < lVar3)))) {
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0,pbVar9,&pbVar9->ex_data);
    if ((pbVar9->method != (BIO_METHOD *)0x0) &&
       (p_Var13 = pbVar9->method->destroy, p_Var13 != (_func_601 *)0x0)) {
      (*p_Var13)(pbVar9);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar9);
    }
  }
  return (BIO *)0x0;
}

