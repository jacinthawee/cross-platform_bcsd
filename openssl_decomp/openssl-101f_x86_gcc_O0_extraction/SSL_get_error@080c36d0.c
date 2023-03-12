
int SSL_get_error(SSL *s,int ret_code)

{
  ulong uVar1;
  int iVar2;
  BIO *b;
  
  if (0 < ret_code) {
    return 0;
  }
  uVar1 = ERR_peek_error();
  if (uVar1 != 0) {
    if (uVar1 >> 0x18 != 2) {
      return 1;
    }
    return 5;
  }
  if (ret_code == 0) {
    if (s->version == 2) {
      return 6;
    }
    if ((*(byte *)&s->shutdown & 2) == 0) {
      return 5;
    }
    if (s->s3->warn_alert != 0) {
      return 5;
    }
    return 6;
  }
  iVar2 = s->rwstate;
  if (iVar2 == 3) {
    b = s->rbio;
    iVar2 = BIO_test_flags(b,1);
    if (iVar2 != 0) {
      return 2;
    }
    iVar2 = BIO_test_flags(b,2);
    if (iVar2 == 0) {
      iVar2 = BIO_test_flags(b,4);
      if (iVar2 != 0) goto LAB_080c37e9;
      iVar2 = s->rwstate;
      goto LAB_080c370c;
    }
LAB_080c3783:
    iVar2 = 3;
  }
  else {
LAB_080c370c:
    if (iVar2 == 2) {
      b = s->wbio;
      iVar2 = BIO_test_flags(b,2);
      if (iVar2 != 0) goto LAB_080c3783;
      iVar2 = BIO_test_flags(b,1);
      if (iVar2 != 0) {
        return 2;
      }
      iVar2 = BIO_test_flags(b,4);
      if (iVar2 != 0) {
LAB_080c37e9:
        iVar2 = BIO_get_retry_reason(b);
        if (iVar2 == 2) {
          return 7;
        }
        if (iVar2 == 3) {
          return 8;
        }
        return 5;
      }
      iVar2 = s->rwstate;
    }
    if (iVar2 != 4) {
      return 5;
    }
  }
  return iVar2;
}

