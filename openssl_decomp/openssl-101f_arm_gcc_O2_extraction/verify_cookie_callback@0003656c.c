
void verify_cookie_callback(SSL *param_1,void *param_2,size_t param_3)

{
  BIO *bp;
  size_t n;
  undefined2 *d;
  EVP_MD *evp_md;
  int iVar1;
  size_t local_7c;
  short local_78;
  undefined2 local_76;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __TMC_END__;
  if (cookie_initialized != 0) {
    bp = SSL_get_rbio(param_1);
    BIO_ctrl(bp,0x2e,0,&local_78);
    if (local_78 == 2) {
      n = 6;
    }
    else if (local_78 == 10) {
      n = 0x12;
    }
    else {
      OpenSSLDie("s_cb.c",0x375,"0");
      n = 0;
    }
    d = (undefined2 *)CRYPTO_malloc(n,"s_cb.c",0x378);
    if (d == (undefined2 *)0x0) {
      BIO_printf(bio_err,"out of memory\n");
    }
    else {
      if (local_78 == 2) {
        *d = local_76;
        *(undefined4 *)(d + 1) = local_74;
      }
      else if (local_78 == 10) {
        *d = local_76;
        *(undefined4 *)(d + 1) = local_70;
        *(undefined4 *)(d + 3) = uStack_6c;
        *(undefined4 *)(d + 5) = uStack_68;
        *(undefined4 *)(d + 7) = uStack_64;
      }
      else {
        OpenSSLDie("s_cb.c",0x395,"0");
      }
      evp_md = EVP_sha1();
      HMAC(evp_md,cookie_secret,0x10,(uchar *)d,n,auStack_5c,&local_7c);
      CRYPTO_free(d);
      if (param_3 == local_7c) {
        iVar1 = memcmp(auStack_5c,param_2,param_3);
        count_leading_zeroes(iVar1);
      }
    }
  }
  if (local_1c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

