
void generate_cookie_callback(SSL *param_1,void *param_2,size_t *param_3)

{
  int iVar1;
  BIO *bp;
  size_t n;
  undefined2 *d;
  EVP_MD *evp_md;
  size_t local_84;
  short local_80;
  undefined2 local_7e;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  uchar auStack_64 [64];
  int local_24;
  
  d = cookie_initialized;
  local_24 = __stack_chk_guard;
  if (cookie_initialized == (undefined2 *)0x0) {
    iVar1 = RAND_bytes(cookie_secret,0x10);
    if (iVar1 < 1) {
      BIO_printf(bio_err,"error setting random cookie secret\n");
      goto LAB_00036166;
    }
    cookie_initialized = (undefined2 *)0x1;
  }
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2e,0,&local_80);
  if (local_80 == 2) {
    n = 6;
  }
  else if (local_80 == 10) {
    n = 0x12;
  }
  else {
    OpenSSLDie("s_cb.c",0x307,"0");
    n = 0;
  }
  d = (undefined2 *)CRYPTO_malloc(n,"s_cb.c",0x30a);
  if (d == (undefined2 *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
  }
  else {
    if (local_80 == 2) {
      *d = local_7e;
      *(undefined4 *)(d + 1) = local_7c;
    }
    else if (local_80 == 10) {
      *d = local_7e;
      *(undefined4 *)(d + 1) = local_78;
      *(undefined4 *)(d + 3) = uStack_74;
      *(undefined4 *)(d + 5) = uStack_70;
      *(undefined4 *)(d + 7) = uStack_6c;
    }
    else {
      OpenSSLDie("s_cb.c",799,"0");
    }
    evp_md = EVP_sha1();
    HMAC(evp_md,cookie_secret,0x10,(uchar *)d,n,auStack_64,&local_84);
    CRYPTO_free(d);
    memcpy(param_2,auStack_64,local_84);
    d = (undefined2 *)0x1;
    *param_3 = local_84;
  }
LAB_00036166:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(d);
  }
  return;
}

