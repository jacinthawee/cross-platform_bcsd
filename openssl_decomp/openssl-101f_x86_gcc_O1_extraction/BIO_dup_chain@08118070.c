
BIO * BIO_dup_chain(BIO *in)

{
  CRYPTO_EX_DATA *ad;
  BIO_METHOD *pBVar1;
  _func_600 *p_Var2;
  _func_601 *p_Var3;
  bio_st *pbVar4;
  bio_st *pbVar5;
  bio_st *obj;
  int iVar6;
  long lVar7;
  bio_st *parg;
  bio_st *local_24;
  bio_st *local_20;
  
  local_24 = (BIO *)0x0;
  local_20 = (bio_st *)0x0;
  if (in != (BIO *)0x0) {
    while( true ) {
      pBVar1 = in->method;
      obj = (bio_st *)CRYPTO_malloc(0x40,"bio_lib.c",0x46);
      if (obj == (bio_st *)0x0) break;
      ad = &obj->ex_data;
      obj->method = pBVar1;
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
      p_Var2 = pBVar1->create;
      if ((p_Var2 != (_func_600 *)0x0) && (iVar6 = (*p_Var2)(obj), iVar6 == 0)) {
        CRYPTO_free_ex_data(0,obj,ad);
        CRYPTO_free(obj);
        goto LAB_081181ff;
      }
      obj->callback = in->callback;
      obj->cb_arg = in->cb_arg;
      obj->init = in->init;
      obj->shutdown = in->shutdown;
      obj->flags = in->flags;
      obj->num = in->num;
      lVar7 = BIO_ctrl(in,0xc,0,obj);
      if (lVar7 == 0) {
        iVar6 = CRYPTO_add_lock(&obj->references,-1,0x15,"bio_lib.c",0x75);
        if ((iVar6 < 1) &&
           ((obj->callback == (_func_603 *)0x0 ||
            (lVar7 = (*obj->callback)(obj,1,(char *)0x0,0,0,1), 0 < lVar7)))) {
          CRYPTO_free_ex_data(0,obj,ad);
          if ((obj->method != (BIO_METHOD *)0x0) &&
             (p_Var3 = obj->method->destroy, p_Var3 != (_func_601 *)0x0)) {
            (*p_Var3)(obj);
            CRYPTO_free(obj);
          }
        }
        goto LAB_081181ff;
      }
      iVar6 = CRYPTO_dup_ex_data(0,ad,&in->ex_data);
      if (iVar6 == 0) goto LAB_081181ff;
      pbVar5 = obj;
      if ((local_20 != (bio_st *)0x0) &&
         (pbVar4 = local_24, pbVar5 = local_20, local_24 != (BIO *)0x0)) {
        do {
          parg = pbVar4;
          pbVar4 = parg->next_bio;
        } while (parg->next_bio != (bio_st *)0x0);
        parg->next_bio = obj;
        obj->prev_bio = parg;
        BIO_ctrl(local_24,6,0,parg);
      }
      local_20 = pbVar5;
      in = in->next_bio;
      local_24 = obj;
      if (in == (bio_st *)0x0) {
        return local_20;
      }
    }
    ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x49);
LAB_081181ff:
    if (((local_20 != (bio_st *)0x0) &&
        (iVar6 = CRYPTO_add_lock(&local_20->references,-1,0x15,"bio_lib.c",0x75), iVar6 < 1)) &&
       ((local_20->callback == (_func_603 *)0x0 ||
        (lVar7 = (*local_20->callback)(local_20,1,(char *)0x0,0,0,1), 0 < lVar7)))) {
      CRYPTO_free_ex_data(0,local_20,&local_20->ex_data);
      if ((local_20->method != (BIO_METHOD *)0x0) &&
         (p_Var3 = local_20->method->destroy, p_Var3 != (_func_601 *)0x0)) {
        (*p_Var3)(local_20);
        CRYPTO_free(local_20);
      }
    }
  }
  return (BIO *)0x0;
}

