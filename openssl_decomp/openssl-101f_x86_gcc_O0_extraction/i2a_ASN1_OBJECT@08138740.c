
int i2a_ASN1_OBJECT(BIO *bp,ASN1_OBJECT *a)

{
  int len;
  char *buf;
  int in_GS_OFFSET;
  char local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((a == (ASN1_OBJECT *)0x0) || (a->data == (uchar *)0x0)) {
    len = BIO_write(bp,"NULL",4);
  }
  else {
    len = OBJ_obj2txt(local_70,0x50,a,0);
    if (len < 0x50) {
      if (len < 1) {
        len = BIO_write(bp,"<INVALID>",9);
      }
      else {
        BIO_write(bp,local_70,len);
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
        if (buf != local_70) {
          CRYPTO_free(buf);
        }
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

