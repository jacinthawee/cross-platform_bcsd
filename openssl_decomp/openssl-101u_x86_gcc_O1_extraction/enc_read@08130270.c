
size_t enc_read(BIO *param_1,void *param_2,size_t param_3)

{
  size_t *outm;
  size_t *outl;
  size_t sVar1;
  int iVar2;
  size_t __n;
  size_t local_24;
  
  if (((param_2 == (void *)0x0) || (outl = (size_t *)param_1->ptr, outl == (size_t *)0x0)) ||
     (param_1->next_bio == (bio_st *)0x0)) {
    return 0;
  }
  if ((int)*outl < 1) {
    if ((0 < (int)param_3) && (0 < (int)outl[2])) {
      local_24 = 0;
      goto LAB_081302fc;
    }
    BIO_clear_flags(param_1,0xf);
    BIO_copy_next_retry(param_1);
  }
  else {
    local_24 = *outl - outl[1];
    if ((int)param_3 <= (int)local_24) {
      local_24 = param_3;
    }
    param_3 = param_3 - local_24;
    memcpy(param_2,(void *)((int)outl + outl[1] + 0xa0),local_24);
    sVar1 = outl[1];
    param_2 = (void *)((int)param_2 + local_24);
    outl[1] = local_24 + sVar1;
    if (local_24 + sVar1 == *outl) {
      *outl = 0;
      outl[1] = 0;
    }
    sVar1 = local_24;
    if ((0 < (int)param_3) && (0 < (int)outl[2])) {
LAB_081302fc:
      outm = outl + 0x28;
LAB_08130310:
      do {
        sVar1 = BIO_read(param_1->next_bio,outl + 0x38,0x1000);
        if ((int)sVar1 < 1) {
          iVar2 = BIO_test_flags(param_1->next_bio,8);
          if (iVar2 != 0) {
            if (local_24 != 0) {
              BIO_clear_flags(param_1,0xf);
              BIO_copy_next_retry(param_1);
              return local_24;
            }
            break;
          }
          outl[2] = sVar1;
          sVar1 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)(outl + 5),(uchar *)outm,(int *)outl);
          outl[1] = 0;
          outl[4] = sVar1;
          __n = *outl;
        }
        else {
          EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)outm,(int *)outl,
                           (uchar *)(outl + 0x38),sVar1);
          __n = *outl;
          outl[2] = 1;
          if (__n == 0) goto LAB_08130310;
        }
        if ((int)param_3 < (int)__n) {
          memcpy(param_2,outm,param_3);
          outl[1] = param_3;
          sVar1 = local_24 + param_3;
          break;
        }
        sVar1 = local_24;
        if ((int)__n < 1) break;
        param_3 = param_3 - __n;
        memcpy(param_2,outm,__n);
        local_24 = local_24 + __n;
        param_2 = (void *)((int)param_2 + __n);
        outl[1] = __n;
        sVar1 = local_24;
        if (((int)param_3 < 1) || ((int)outl[2] < 1)) break;
      } while( true );
    }
    local_24 = sVar1;
    BIO_clear_flags(param_1,0xf);
    BIO_copy_next_retry(param_1);
    if (local_24 != 0) {
      return local_24;
    }
  }
  return outl[2];
}

