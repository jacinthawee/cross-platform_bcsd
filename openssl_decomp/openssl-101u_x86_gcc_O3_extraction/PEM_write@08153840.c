
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
  int inl;
  int in_GS_OFFSET;
  int local_a0;
  int *local_98;
  int local_84;
  EVP_ENCODE_CTX local_80;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    local_a0 = 0;
    ERR_put_error(9,0x71,7,"pem_lib.c",0x248);
    goto LAB_081538fb;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  EVP_EncodeInit(&local_80);
  len_00 = strlen(name);
  iVar1 = BIO_write(bp,"-----BEGIN ",0xb);
  if ((((iVar1 == 0xb) && (sVar2 = BIO_write(bp,name,len_00), len_00 == sVar2)) &&
      (iVar1 = BIO_write(bp,"-----\n",6), iVar1 == 6)) &&
     ((sVar2 = strlen(hdr), (int)sVar2 < 1 ||
      ((sVar3 = BIO_write(bp,hdr,sVar2), sVar2 == sVar3 &&
       (iVar1 = BIO_write(bp,&DAT_081f15cb,1), iVar1 == 1)))))) {
    out = (uchar *)CRYPTO_malloc(0x2000,"pem_lib.c",0x268);
    if (out == (uchar *)0x0) {
      iVar1 = 0x41;
      goto LAB_081538d3;
    }
    if (len < 1) {
      local_a0 = 0;
    }
    else {
      iVar1 = 0;
      local_a0 = 0;
      do {
        inl = 0x1400;
        if (len < 0x1401) {
          inl = len;
        }
        EVP_EncodeUpdate(&local_80,out,&local_84,data + iVar1,inl);
        if ((local_84 != 0) && (iVar4 = BIO_write(bp,out,local_84), iVar4 != local_84))
        goto LAB_08153a6a;
        len = len - inl;
        local_a0 = local_a0 + local_84;
        iVar1 = iVar1 + inl;
      } while (0 < len);
    }
    local_98 = &local_84;
    EVP_EncodeFinal(&local_80,out,local_98);
    if ((0 < local_84) && (iVar1 = BIO_write(bp,out,local_84), iVar1 != local_84)) {
LAB_08153a6a:
      OPENSSL_cleanse(out,0x2000);
      CRYPTO_free(out);
      iVar1 = 7;
      goto LAB_081538d3;
    }
    OPENSSL_cleanse(out,0x2000);
    CRYPTO_free(out);
    iVar1 = BIO_write(bp,"-----END ",9);
    if (((iVar1 != 9) || (sVar2 = BIO_write(bp,name,len_00), len_00 != sVar2)) ||
       (iVar1 = BIO_write(bp,"-----\n",6), iVar1 != 6)) goto LAB_081538ce;
    local_a0 = local_a0 + local_84;
  }
  else {
LAB_081538ce:
    iVar1 = 7;
LAB_081538d3:
    local_a0 = 0;
    ERR_put_error(9,0x72,iVar1,"pem_lib.c",0x288);
  }
  BIO_free(bp);
LAB_081538fb:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_a0;
}

