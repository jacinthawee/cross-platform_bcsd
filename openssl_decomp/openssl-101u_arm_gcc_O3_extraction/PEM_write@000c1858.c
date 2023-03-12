
int PEM_write(FILE *fp,char *name,char *hdr,uchar *data,long len)

{
  BIO_METHOD *type;
  BIO *bp;
  size_t len_00;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  uchar *out;
  int iVar4;
  long inl;
  int iVar5;
  BIO *pBVar6;
  int *local_9c;
  int local_90;
  EVP_ENCODE_CTX EStack_8c;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x71,7,"pem_lib.c",0x248);
    goto LAB_000c18d0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  EVP_EncodeInit(&EStack_8c);
  len_00 = strlen(name);
  iVar1 = BIO_write(bp,"-----BEGIN ",0xb);
  if ((((iVar1 == 0xb) && (sVar2 = BIO_write(bp,name,len_00), len_00 == sVar2)) &&
      (iVar1 = BIO_write(bp,"-----\n",6), iVar1 == 6)) &&
     ((sVar2 = strlen(hdr), (int)sVar2 < 1 ||
      ((sVar3 = BIO_write(bp,hdr,sVar2), sVar2 == sVar3 &&
       (iVar1 = BIO_write(bp,"\n",1), iVar1 == 1)))))) {
    out = (uchar *)CRYPTO_malloc(0x2000,"pem_lib.c",0x268);
    if (out == (uchar *)0x0) {
      iVar1 = 0x41;
      goto LAB_000c18b0;
    }
    if (len < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      iVar5 = 0;
      do {
        inl = len;
        if (0x13ff < len) {
          inl = 0x1400;
        }
        EVP_EncodeUpdate(&EStack_8c,out,&local_90,data + iVar5,inl);
        iVar4 = local_90;
        if ((local_90 != 0) && (iVar4 = BIO_write(bp,out,local_90), iVar4 != local_90))
        goto LAB_000c19b0;
        iVar1 = iVar1 + iVar4;
        iVar5 = iVar5 + inl;
        len = len - inl;
      } while (0 < len);
    }
    local_9c = &local_90;
    EVP_EncodeFinal(&EStack_8c,out,local_9c);
    if ((0 < local_90) && (iVar5 = BIO_write(bp,out,local_90), iVar5 != local_90)) {
LAB_000c19b0:
      OPENSSL_cleanse(out,0x2000);
      CRYPTO_free(out);
      iVar1 = 7;
      goto LAB_000c18b0;
    }
    OPENSSL_cleanse(out,0x2000);
    CRYPTO_free(out);
    iVar5 = BIO_write(bp,"-----END ",9);
    if (((iVar5 != 9) || (sVar2 = BIO_write(bp,name,len_00), len_00 != sVar2)) ||
       (iVar5 = BIO_write(bp,"-----\n",6), iVar5 != 6)) goto LAB_000c18ae;
    pBVar6 = (BIO *)(iVar1 + local_90);
  }
  else {
LAB_000c18ae:
    iVar1 = 7;
LAB_000c18b0:
    pBVar6 = (BIO *)0x0;
    ERR_put_error(9,0x72,iVar1,"pem_lib.c",0x288);
  }
  BIO_free(bp);
  bp = pBVar6;
LAB_000c18d0:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)bp;
}

