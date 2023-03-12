
int PEM_write_bio(BIO *bp,char *name,char *hdr,uchar *data,long len)

{
  size_t sVar1;
  int iVar2;
  size_t len_00;
  size_t sVar3;
  uchar *out;
  int iVar4;
  long inl;
  int iVar5;
  int *local_9c;
  int local_90;
  EVP_ENCODE_CTX EStack_8c;
  int local_2c;
  
  local_2c = __TMC_END__;
  EVP_EncodeInit(&EStack_8c);
  sVar1 = strlen(name);
  iVar2 = BIO_write(bp,"-----BEGIN ",0xb);
  if ((((iVar2 == 0xb) && (len_00 = BIO_write(bp,name,sVar1), len_00 == sVar1)) &&
      (iVar2 = BIO_write(bp,"-----\n",6), iVar2 == 6)) &&
     ((sVar1 = strlen(hdr), (int)sVar1 < 1 ||
      ((sVar3 = BIO_write(bp,hdr,sVar1), sVar3 == sVar1 &&
       (iVar2 = BIO_write(bp,"\n",1), iVar2 == 1)))))) {
    out = (uchar *)CRYPTO_malloc(0x2000,"pem_lib.c",0x26a);
    if (out == (uchar *)0x0) {
      iVar2 = 0x41;
    }
    else {
      if (len < 1) {
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
        iVar5 = 0;
        do {
          inl = len;
          if (0x13ff < len) {
            inl = 0x1400;
          }
          EVP_EncodeUpdate(&EStack_8c,out,&local_90,data + iVar5,inl);
          iVar4 = local_90;
          if ((local_90 != 0) && (iVar4 = BIO_write(bp,out,local_90), iVar4 != local_90))
          goto LAB_000c419e;
          iVar2 = iVar2 + iVar4;
          iVar5 = iVar5 + inl;
          len = len - inl;
        } while (0 < len);
      }
      local_9c = &local_90;
      EVP_EncodeFinal(&EStack_8c,out,local_9c);
      if ((local_90 < 1) || (iVar5 = BIO_write(bp,out,local_90), iVar5 == local_90)) {
        OPENSSL_cleanse(out,0x2000);
        CRYPTO_free(out);
        iVar5 = BIO_write(bp,"-----END ",9);
        if ((iVar5 == 9) &&
           ((sVar1 = BIO_write(bp,name,len_00), len_00 == sVar1 &&
            (iVar5 = BIO_write(bp,"-----\n",6), iVar5 == 6)))) {
          local_90 = local_90 + iVar2;
          goto LAB_000c40be;
        }
        goto LAB_000c40a4;
      }
LAB_000c419e:
      OPENSSL_cleanse(out,0x2000);
      CRYPTO_free(out);
      iVar2 = 7;
    }
  }
  else {
LAB_000c40a4:
    iVar2 = 7;
  }
  ERR_put_error(9,0x72,iVar2,"pem_lib.c",0x28b);
  local_90 = 0;
LAB_000c40be:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_90;
}

