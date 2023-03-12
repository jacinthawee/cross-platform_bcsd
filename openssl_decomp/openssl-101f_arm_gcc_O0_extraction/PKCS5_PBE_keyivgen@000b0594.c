
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER *cipher,EVP_MD *md,int en_de)

{
  PBEPARAM *a;
  int iVar1;
  char *cnt;
  int iVar2;
  uchar *d;
  ASN1_STRING *pAVar3;
  size_t sVar4;
  long lVar5;
  uchar *local_d8;
  EVP_MD_CTX EStack_d4;
  uchar auStack_bc [16];
  uchar auStack_ac [16];
  undefined auStack_9c [48];
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __TMC_END__;
  EVP_MD_CTX_init(&EStack_d4);
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar3 = (param->value).asn1_string, pAVar3 == (ASN1_STRING *)0x0)) {
    ERR_put_error(6,0x75,0x72,"p5_crpt.c",0x5b);
    a = (PBEPARAM *)0x0;
    goto LAB_000b05e0;
  }
  local_d8 = pAVar3->data;
  a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_d8,pAVar3->length);
  if (a == (PBEPARAM *)0x0) {
    ERR_put_error(6,0x75,0x72,"p5_crpt.c",0x61);
    goto LAB_000b05e0;
  }
  lVar5 = 1;
  if (a->iter != (ASN1_INTEGER *)0x0) {
    lVar5 = ASN1_INTEGER_get(a->iter);
  }
  d = a->salt->data;
  sVar4 = a->salt->length;
  cnt = pass;
  if ((pass != (char *)0x0) && (cnt = (char *)passlen, passlen == -1)) {
    cnt = (char *)strlen(pass);
  }
  iVar1 = EVP_DigestInit_ex(&EStack_d4,md,(ENGINE *)0x0);
  if (((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(&EStack_d4,pass,(size_t)cnt), iVar1 == 0)) ||
     (iVar1 = EVP_DigestUpdate(&EStack_d4,d,sVar4), iVar1 == 0)) {
LAB_000b063e:
    a = (PBEPARAM *)0x0;
  }
  else {
    PBEPARAM_free(a);
    iVar1 = EVP_DigestFinal_ex(&EStack_d4,auStack_ac,(uint *)0x0);
    if (iVar1 == 0) goto LAB_000b063e;
    sVar4 = EVP_MD_size(md);
    if ((int)sVar4 < 0) {
      a = (PBEPARAM *)0x0;
      goto LAB_000b05e0;
    }
    if (1 < lVar5) {
      iVar1 = 1;
      do {
        iVar2 = EVP_DigestInit_ex(&EStack_d4,md,(ENGINE *)0x0);
        if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_d4,auStack_ac,sVar4), iVar2 == 0)) ||
           (iVar2 = EVP_DigestFinal_ex(&EStack_d4,auStack_ac,(uint *)0x0), iVar2 == 0))
        goto LAB_000b063e;
        iVar1 = iVar1 + 1;
      } while (iVar1 != lVar5);
    }
    iVar1 = EVP_CIPHER_key_length(cipher);
    if (0x40 < iVar1) {
      OpenSSLDie("p5_crpt.c",0x81,"EVP_CIPHER_key_length(cipher) <= (int)sizeof(md_tmp)");
    }
    iVar1 = EVP_CIPHER_key_length(cipher);
    __memcpy_chk(auStack_6c,auStack_ac,iVar1,0x40);
    iVar1 = EVP_CIPHER_iv_length(cipher);
    if (0x10 < iVar1) {
      OpenSSLDie("p5_crpt.c",0x83,"EVP_CIPHER_iv_length(cipher) <= 16");
    }
    iVar1 = EVP_CIPHER_iv_length(cipher);
    iVar2 = EVP_CIPHER_iv_length(cipher);
    __memcpy_chk(auStack_bc,auStack_9c + -iVar1,iVar2,0x10);
    iVar1 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_6c,auStack_bc,en_de);
    if (iVar1 == 0) goto LAB_000b063e;
    OPENSSL_cleanse(auStack_ac,0x40);
    a = (PBEPARAM *)0x1;
    OPENSSL_cleanse(auStack_6c,0x40);
    OPENSSL_cleanse(auStack_bc,0x10);
  }
  EVP_MD_CTX_cleanup(&EStack_d4);
LAB_000b05e0:
  if (local_2c == __TMC_END__) {
    return (int)a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

