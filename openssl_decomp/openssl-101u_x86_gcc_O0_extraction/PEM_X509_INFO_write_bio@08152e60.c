
int PEM_X509_INFO_write_bio
              (BIO *bp,X509_INFO *xi,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cd,void *u)

{
  uchar *data;
  int iVar1;
  char *pcVar2;
  int n;
  size_t sVar3;
  int in_GS_OFFSET;
  undefined local_4ac [140];
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (enc == (EVP_CIPHER *)0x0) {
LAB_08152eca:
    if (xi->x_pkey != (X509_PKEY *)0x0) {
      data = (uchar *)xi->enc_data;
      if ((data == (uchar *)0x0) || (iVar1 = xi->enc_len, iVar1 < 1)) {
        iVar1 = PEM_write_bio_RSAPrivateKey(bp,(xi->x_pkey->dec_pkey->pkey).rsa,enc,kstr,klen,cd,u);
      }
      else {
        if (enc == (EVP_CIPHER *)0x0) {
          ERR_put_error(9,0x75,0x7f,"pem_info.c",0x14e);
          goto LAB_08152fb0;
        }
        n = EVP_CIPHER_nid((xi->enc_cipher).cipher);
        pcVar2 = OBJ_nid2sn(n);
        if (pcVar2 == (char *)0x0) {
          iVar1 = 0x15f;
          goto LAB_08153098;
        }
        sVar3 = strlen(pcVar2);
        if (0x400 < sVar3 + 0x24 + enc->iv_len * 2) {
          OpenSSLDie("pem_info.c",0x165,"strlen(objstr) + 23 + 2 * enc->iv_len + 13 <= sizeof buf");
        }
        local_420[0] = '\0';
        PEM_proc_type(local_420,10);
        PEM_dek_info(local_420,pcVar2,enc->iv_len,(char *)(xi->enc_cipher).iv);
        iVar1 = PEM_write_bio(bp,"RSA PRIVATE KEY",local_420,data,iVar1);
      }
      if (iVar1 < 1) {
        enc = (EVP_CIPHER *)0x0;
        goto LAB_08152fb0;
      }
    }
    enc = (EVP_CIPHER *)0x1;
    if (xi->x509 != (X509 *)0x0) {
      iVar1 = PEM_write_bio_X509(bp,xi->x509);
      enc = (EVP_CIPHER *)(uint)(0 < iVar1);
    }
  }
  else {
    iVar1 = EVP_CIPHER_nid(enc);
    pcVar2 = OBJ_nid2sn(iVar1);
    if (pcVar2 != (char *)0x0) goto LAB_08152eca;
    iVar1 = 0x141;
LAB_08153098:
    enc = (EVP_CIPHER *)0x0;
    ERR_put_error(9,0x75,0x71,"pem_info.c",iVar1);
  }
LAB_08152fb0:
  OPENSSL_cleanse(local_4ac,0x8c);
  OPENSSL_cleanse(local_420,0x400);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)enc;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

