
uchar * PKCS12_pbe_crypt(X509_ALGOR *algor,char *pass,int passlen,uchar *in,int inlen,uchar **data,
                        int *datalen,int en_de)

{
  int iVar1;
  uchar *out;
  int iVar2;
  int in_GS_OFFSET;
  int local_b0;
  EVP_CIPHER_CTX local_ac;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_CIPHER_CTX_init(&local_ac);
  iVar1 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&local_ac,en_de);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x77,0x73,"p12_decr.c",0x53);
    out = (uchar *)0x0;
    goto LAB_081831cb;
  }
  iVar1 = EVP_CIPHER_CTX_block_size(&local_ac);
  out = (uchar *)CRYPTO_malloc(iVar1 + inlen,"p12_decr.c",0x57);
  if (out == (uchar *)0x0) {
    ERR_put_error(0x23,0x77,0x41,"p12_decr.c",0x58);
  }
  else {
    iVar2 = EVP_CipherUpdate(&local_ac,out,&local_b0,in,inlen);
    iVar1 = local_b0;
    if (iVar2 == 0) {
      CRYPTO_free(out);
      iVar2 = 0x60;
      iVar1 = 6;
    }
    else {
      iVar2 = EVP_CipherFinal_ex(&local_ac,out + local_b0,&local_b0);
      if (iVar2 != 0) {
        if (datalen != (int *)0x0) {
          *datalen = iVar1 + local_b0;
        }
        if (data != (uchar **)0x0) {
          *data = out;
        }
        goto LAB_081831bd;
      }
      CRYPTO_free(out);
      iVar2 = 0x68;
      iVar1 = 0x74;
    }
    out = (uchar *)0x0;
    ERR_put_error(0x23,0x77,iVar1,"p12_decr.c",iVar2);
  }
LAB_081831bd:
  EVP_CIPHER_CTX_cleanup(&local_ac);
LAB_081831cb:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return out;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

