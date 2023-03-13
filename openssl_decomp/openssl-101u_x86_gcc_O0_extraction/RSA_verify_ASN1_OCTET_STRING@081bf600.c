
int RSA_verify_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  size_t len;
  uchar *to;
  ASN1_OCTET_STRING *a;
  int in_GS_OFFSET;
  int iVar1;
  int iVar2;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  len = RSA_size(rsa);
  if (len == siglen) {
    to = (uchar *)CRYPTO_malloc(len,"rsa_saos.c",0x78);
    if (to != (uchar *)0x0) {
      iVar1 = RSA_public_decrypt(len,sigbuf,to,rsa,1);
      if (iVar1 < 1) {
LAB_081bf710:
        iVar1 = 0;
      }
      else {
        local_24 = to;
        a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_24,iVar1);
        if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_081bf710;
        if (a->length == m_length) {
          iVar1 = 1;
          iVar2 = memcmp(m,a->data,a->length);
          if (iVar2 != 0) goto LAB_081bf6dd;
        }
        else {
LAB_081bf6dd:
          iVar1 = 0;
          ERR_put_error(4,0x78,0x68,"rsa_saos.c",0x89);
        }
        ASN1_STRING_free(a);
      }
      OPENSSL_cleanse(to,len);
      CRYPTO_free(to);
      goto LAB_081bf64c;
    }
    iVar2 = 0x7a;
    iVar1 = 0x41;
  }
  else {
    iVar2 = 0x74;
    iVar1 = 0x77;
  }
  ERR_put_error(4,0x78,iVar1,"rsa_saos.c",iVar2);
  iVar1 = 0;
LAB_081bf64c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

