
BIO * BIO_dup_chain(BIO *in)

{
  BIO *pBVar1;
  bio_st *pbVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  _func_600 *p_Var6;
  bio_st *parg;
  _func_601 *p_Var7;
  BIO *bp;
  BIO_METHOD *pBVar8;
  _func_603 *p_Var9;
  int iVar10;
  CRYPTO_EX_DATA *ad;
  bio_st *obj;
  
  obj = (bio_st *)0x0;
  bp = (BIO *)0x0;
  if (in != (BIO *)0x0) {
    while( true ) {
      pBVar8 = in->method;
      pbVar2 = (bio_st *)CRYPTO_malloc(0x40,"bio_lib.c",0x46);
      if (pbVar2 == (bio_st *)0x0) {
        ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x48);
        goto joined_r0x0009d7ec;
      }
      ad = &pbVar2->ex_data;
      pbVar2->method = pBVar8;
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
      CRYPTO_new_ex_data(0,pbVar2,ad);
      p_Var6 = pBVar8->create;
      if ((p_Var6 != (_func_600 *)0x0) && (iVar3 = (*p_Var6)(pbVar2), iVar3 == 0)) break;
      p_Var9 = in->callback;
      pbVar2->cb_arg = in->cb_arg;
      pbVar2->init = in->init;
      pbVar2->shutdown = in->shutdown;
      iVar3 = in->flags;
      pbVar2->callback = p_Var9;
      iVar10 = in->num;
      pbVar2->flags = iVar3;
      pbVar2->num = iVar10;
      pcVar4 = (char *)BIO_ctrl(in,0xc,0,pbVar2);
      if ((pcVar4 == (char *)0x0) ||
         (pcVar4 = (char *)CRYPTO_dup_ex_data(0,ad,&in->ex_data), pcVar4 == (char *)0x0)) {
        iVar3 = CRYPTO_add_lock(&pbVar2->references,-1,0x15,"bio_lib.c",0x72);
        if ((iVar3 < 1) &&
           ((pbVar2->callback == (_func_603 *)0x0 ||
            (lVar5 = (*pbVar2->callback)(pbVar2,1,pcVar4,(int)pcVar4,(long)pcVar4,1), 0 < lVar5))))
        {
          CRYPTO_free_ex_data(0,pbVar2,ad);
          if ((pbVar2->method != (BIO_METHOD *)0x0) &&
             (p_Var7 = pbVar2->method->destroy, p_Var7 != (_func_601 *)0x0)) {
            (*p_Var7)(pbVar2);
          }
          CRYPTO_free(pbVar2);
        }
        goto joined_r0x0009d7ec;
      }
      if (obj == (bio_st *)0x0) {
        in = in->next_bio;
        obj = pbVar2;
      }
      else {
        pBVar1 = bp;
        if (bp != (BIO *)0x0) {
          do {
            parg = pBVar1;
            pBVar1 = parg->next_bio;
          } while (parg->next_bio != (bio_st *)0x0);
          parg->next_bio = pbVar2;
          pbVar2->prev_bio = parg;
          BIO_ctrl(bp,6,0,parg);
        }
        in = in->next_bio;
      }
      bp = pbVar2;
      if (in == (bio_st *)0x0) {
        return obj;
      }
    }
    CRYPTO_free_ex_data(0,pbVar2,ad);
    CRYPTO_free(pbVar2);
joined_r0x0009d7ec:
    do {
      if (obj == (bio_st *)0x0) {
        return (BIO *)0x0;
      }
      iVar10 = obj->references;
      pbVar2 = obj->next_bio;
      iVar3 = CRYPTO_add_lock(&obj->references,-1,0x15,"bio_lib.c",0x72);
      if ((iVar3 < 1) &&
         ((obj->callback == (_func_603 *)0x0 ||
          (lVar5 = (*obj->callback)(obj,1,(char *)0x0,0,0,1), 0 < lVar5)))) {
        CRYPTO_free_ex_data(0,obj,&obj->ex_data);
        if ((obj->method != (BIO_METHOD *)0x0) &&
           (p_Var7 = obj->method->destroy, p_Var7 != (_func_601 *)0x0)) {
          (*p_Var7)(obj);
        }
        CRYPTO_free(obj);
      }
      obj = pbVar2;
    } while (iVar10 < 2);
  }
  return (BIO *)0x0;
}

