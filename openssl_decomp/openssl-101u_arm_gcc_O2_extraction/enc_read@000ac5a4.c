
/* WARNING: Type propagation algorithm not settling */

bio_st * enc_read(BIO *param_1,_func_603 *param_2,bio_st *param_3)

{
  bio_st *inl;
  int iVar1;
  BIO_METHOD *pBVar2;
  bio_st *__n;
  _func_603 *__dest;
  _func_603 *p_Var3;
  bio_st *__n_00;
  void **outm;
  bio_st *outl;
  bool bVar4;
  
  if (param_2 == (_func_603 *)0x0) {
    return (bio_st *)0x0;
  }
  outl = (bio_st *)param_1->ptr;
  inl = outl;
  if ((outl != (bio_st *)0x0) && (inl = param_1->next_bio, param_1->next_bio != (bio_st *)0x0)) {
    if ((int)outl->method < 1) {
      __n_00 = (bio_st *)0x0;
      __dest = param_2;
    }
    else {
      __n_00 = (bio_st *)((int)outl->method - (int)outl->callback);
      if ((int)param_3 <= (int)__n_00) {
        __n_00 = param_3;
      }
      param_3 = (bio_st *)((int)param_3 - (int)__n_00);
      __dest = param_2 + (int)__n_00;
      memcpy(param_2,outl->callback + 0xa0 + (int)outl,(size_t)__n_00);
      pBVar2 = (BIO_METHOD *)(outl->callback + (int)__n_00);
      outl->callback = (_func_603 *)pBVar2;
      bVar4 = pBVar2 == outl->method;
      if (bVar4) {
        pBVar2 = (BIO_METHOD *)0x0;
        outl->method = (BIO_METHOD *)0x0;
      }
      if (bVar4) {
        outl->callback = (_func_603 *)pBVar2;
      }
    }
    inl = __n_00;
    if ((0 < (int)param_3) && (0 < (int)outl->cb_arg)) {
      outm = &outl[2].ptr;
      do {
        inl = (bio_st *)BIO_read(param_1->next_bio,&outl[3].ptr,0x1000);
        if ((int)inl < 1) {
          iVar1 = BIO_test_flags(param_1->next_bio,8);
          if (iVar1 != 0) {
            if (__n_00 != (bio_st *)0x0) {
              BIO_clear_flags(param_1,0xf);
              BIO_copy_next_retry(param_1);
              return __n_00;
            }
            break;
          }
          outl->cb_arg = (char *)inl;
          iVar1 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)&outl->flags,(uchar *)outm,(int *)outl);
          outl->callback = (_func_603 *)0x0;
          __n = (bio_st *)outl->method;
          outl->shutdown = iVar1;
LAB_000ac680:
          if ((int)param_3 < (int)__n) {
            __n = param_3;
            param_3 = (bio_st *)0x0;
          }
          else {
            inl = __n_00;
            if ((int)__n < 1) break;
            param_3 = (bio_st *)((int)param_3 - (int)__n);
          }
          __n_00 = (bio_st *)((int)&__n->method + (int)&__n_00->method);
          p_Var3 = __dest + (int)__n;
          memcpy(__dest,outm,(size_t)__n);
          outl->callback = (_func_603 *)__n;
        }
        else {
          EVP_CipherUpdate((EVP_CIPHER_CTX *)&outl->flags,(uchar *)outm,(int *)outl,
                           (uchar *)&outl[3].ptr,(int)inl);
          __n = (bio_st *)outl->method;
          outl->cb_arg = (char *)0x1;
          p_Var3 = __dest;
          if (__n != (bio_st *)0x0) goto LAB_000ac680;
        }
        inl = __n_00;
        if (((int)param_3 < 1) || (__dest = p_Var3, (int)outl->cb_arg < 1)) break;
      } while( true );
    }
    BIO_clear_flags(param_1,0xf);
    BIO_copy_next_retry(param_1);
    if (inl == (bio_st *)0x0) {
      return (bio_st *)outl->cb_arg;
    }
  }
  return inl;
}

