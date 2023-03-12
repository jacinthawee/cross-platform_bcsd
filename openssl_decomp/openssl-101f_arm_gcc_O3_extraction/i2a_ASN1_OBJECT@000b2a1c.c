
int i2a_ASN1_OBJECT(BIO *bp,ASN1_OBJECT *a)

{
  int len;
  char *buf;
  char acStack_74 [80];
  int local_24;
  
  local_24 = __TMC_END__;
  if ((a == (ASN1_OBJECT *)0x0) || (a->data == (uchar *)0x0)) {
    len = BIO_write(bp,"NULL",4);
  }
  else {
    len = OBJ_obj2txt(acStack_74,0x50,a,0);
    if (len < 0x50) {
      if (len < 1) {
        len = BIO_write(bp,"<INVALID>",9);
      }
      else {
        BIO_write(bp,acStack_74,len);
      }
    }
    else {
      buf = (char *)CRYPTO_malloc(len + 1,"a_object.c",0xf5);
      if (buf == (char *)0x0) {
        len = -1;
      }
      else {
        OBJ_obj2txt(buf,len + 1,a,0);
        BIO_write(bp,buf,len);
        if (buf != acStack_74) {
          CRYPTO_free(buf);
        }
      }
    }
  }
  if (local_24 == __TMC_END__) {
    return len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

