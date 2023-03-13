
undefined2 * generate_cookie_callback(SSL *param_1,void *param_2,size_t *param_3)

{
  int iVar1;
  BIO *bp;
  undefined2 *d;
  EVP_MD *evp_md;
  size_t n;
  int in_GS_OFFSET;
  size_t local_80;
  short local_7c;
  undefined2 local_7a;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uchar local_60 [64];
  int local_20;
  
  d = cookie_initialized;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cookie_initialized == (undefined2 *)0x0) {
    iVar1 = RAND_bytes(cookie_secret,0x10);
    if (iVar1 < 1) {
      BIO_printf(bio_err,"error setting random cookie secret\n");
      goto LAB_0807ee6b;
    }
    cookie_initialized = (undefined2 *)0x1;
  }
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2e,0,&local_7c);
  if (local_7c == 2) {
    iVar1 = 6;
    n = 6;
  }
  else if (local_7c == 10) {
    iVar1 = 0x12;
    n = 0x12;
  }
  else {
    n = 0;
    OpenSSLDie("s_cb.c",0x307,"0");
    iVar1 = 0;
  }
  d = (undefined2 *)CRYPTO_malloc(iVar1,"s_cb.c",0x30a);
  if (d == (undefined2 *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
  }
  else {
    if (local_7c == 2) {
      *d = local_7a;
      *(undefined4 *)(d + 1) = local_78;
    }
    else if (local_7c == 10) {
      *d = local_7a;
      *(undefined4 *)(d + 3) = local_70;
      *(undefined4 *)(d + 5) = local_6c;
      *(undefined4 *)(d + 1) = local_74;
      *(undefined4 *)(d + 7) = local_68;
    }
    else {
      OpenSSLDie("s_cb.c",799,"0");
    }
    evp_md = EVP_sha1();
    HMAC(evp_md,cookie_secret,0x10,(uchar *)d,n,local_60,&local_80);
    CRYPTO_free(d);
    memcpy(param_2,local_60,local_80);
    *param_3 = local_80;
    d = (undefined2 *)0x1;
  }
LAB_0807ee6b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return d;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

