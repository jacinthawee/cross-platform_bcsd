
BIO * BIO_dup_chain(BIO *in)

{
  BIO *pBVar1;
  bio_st *obj;
  int iVar2;
  long lVar3;
  _func_600 *p_Var4;
  bio_st *parg;
  _func_601 *p_Var5;
  CRYPTO_EX_DATA *ad;
  BIO_METHOD *pBVar6;
  _func_603 *p_Var7;
  int iVar8;
  BIO *bp;
  bio_st *obj_00;
  
  obj_00 = (bio_st *)0x0;
  bp = (BIO *)0x0;
  if (in != (BIO *)0x0) {
    while( true ) {
      pBVar6 = in->method;
      obj = (bio_st *)CRYPTO_malloc(0x40,"bio_lib.c",0x46);
      if (obj == (bio_st *)0x0) break;
      ad = &obj->ex_data;
      obj->method = pBVar6;
      obj->callback = (_func_603 *)0x0;
      obj->cb_arg = (char *)0x0;
      obj->init = 0;
      obj->shutdown = 1;
      obj->flags = 0;
      obj->retry_reason = 0;
      obj->num = 0;
      obj->ptr = (void *)0x0;
      obj->prev_bio = (bio_st *)0x0;
      obj->next_bio = (bio_st *)0x0;
      obj->references = 1;
      obj->num_read = 0;
      obj->num_write = 0;
      CRYPTO_new_ex_data(0,obj,ad);
      p_Var4 = pBVar6->create;
      if ((p_Var4 != (_func_600 *)0x0) && (iVar2 = (*p_Var4)(obj), iVar2 == 0)) {
        CRYPTO_free_ex_data(0,obj,ad);
        CRYPTO_free(obj);
        goto LAB_0009f00a;
      }
      p_Var7 = in->callback;
      obj->cb_arg = in->cb_arg;
      obj->init = in->init;
      obj->shutdown = in->shutdown;
      iVar2 = in->flags;
      obj->callback = p_Var7;
      iVar8 = in->num;
      obj->flags = iVar2;
      obj->num = iVar8;
      lVar3 = BIO_ctrl(in,0xc,0,obj);
      if (lVar3 == 0) {
        iVar2 = CRYPTO_add_lock(&obj->references,-1,0x15,"bio_lib.c",0x75);
        if ((iVar2 < 1) &&
           ((obj->callback == (_func_603 *)0x0 ||
            (lVar3 = (*obj->callback)(obj,1,(char *)0x0,0,0,1), 0 < lVar3)))) {
          CRYPTO_free_ex_data(0,obj,ad);
          if ((obj->method != (BIO_METHOD *)0x0) &&
             (p_Var5 = obj->method->destroy, p_Var5 != (_func_601 *)0x0)) {
            (*p_Var5)(obj);
            CRYPTO_free(obj);
          }
        }
        goto LAB_0009f00a;
      }
      iVar2 = CRYPTO_dup_ex_data(0,ad,&in->ex_data);
      if (iVar2 == 0) goto LAB_0009f00a;
      if (obj_00 == (bio_st *)0x0) {
        in = in->next_bio;
        obj_00 = obj;
      }
      else {
        pBVar1 = bp;
        if (bp != (BIO *)0x0) {
          do {
            parg = pBVar1;
            pBVar1 = parg->next_bio;
          } while (parg->next_bio != (bio_st *)0x0);
          parg->next_bio = obj;
          obj->prev_bio = parg;
          BIO_ctrl(bp,6,0,parg);
        }
        in = in->next_bio;
      }
      bp = obj;
      if (in == (bio_st *)0x0) {
        return obj_00;
      }
    }
    ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x49);
LAB_0009f00a:
    if (((obj_00 != (bio_st *)0x0) &&
        (iVar2 = CRYPTO_add_lock(&obj_00->references,-1,0x15,"bio_lib.c",0x75), iVar2 < 1)) &&
       ((obj_00->callback == (_func_603 *)0x0 ||
        (lVar3 = (*obj_00->callback)(obj_00,1,(char *)0x0,0,0,1), 0 < lVar3)))) {
      CRYPTO_free_ex_data(0,obj_00,&obj_00->ex_data);
      if ((obj_00->method != (BIO_METHOD *)0x0) &&
         (p_Var5 = obj_00->method->destroy, p_Var5 != (_func_601 *)0x0)) {
        (*p_Var5)(obj_00);
        CRYPTO_free(obj_00);
      }
    }
  }
  return (BIO *)0x0;
}

