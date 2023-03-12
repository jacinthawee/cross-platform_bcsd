
int SSL_use_PrivateKey_ASN1(int pk,SSL *ssl,uchar *d,long len)

{
  EVP_PKEY *pkey;
  int iVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = d;
  pkey = d2i_PrivateKey(pk,(EVP_PKEY **)0x0,&local_14,len);
  if (pkey == (EVP_PKEY *)0x0) {
    iVar1 = 0;
    ERR_put_error(0x14,0xca,0xd,"ssl_rsa.c",0x172);
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xc9,0x41,"ssl_rsa.c",0x132);
    }
    else {
      iVar1 = ssl_set_pkey();
    }
    EVP_PKEY_free(pkey);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

