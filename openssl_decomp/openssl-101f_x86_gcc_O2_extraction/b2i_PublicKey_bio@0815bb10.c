
EVP_PKEY * b2i_PublicKey_bio(BIO *in)

{
  bool bVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  void *data;
  int iVar4;
  int in_GS_OFFSET;
  char local_30;
  char local_2f;
  uint local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = BIO_read(in,&local_30,0x10);
  if (iVar2 == 0x10) {
    if (local_30 == '\x06') {
      if (local_2f == '\x02') {
        if (local_28 == 0x31535344) {
          bVar1 = true;
          iVar2 = (local_24 + 7U >> 3) * 3 + 0x2c;
LAB_0815bc0a:
          data = CRYPTO_malloc(iVar2,"pvkfmt.c",0x11f);
          if (data != (void *)0x0) {
            iVar4 = BIO_read(in,data,iVar2);
            if (iVar2 == iVar4) {
              if (bVar1) {
                pEVar3 = (EVP_PKEY *)b2i_dss_isra_0();
              }
              else {
                pEVar3 = (EVP_PKEY *)b2i_rsa_isra_1();
              }
            }
            else {
              pEVar3 = (EVP_PKEY *)0x0;
              ERR_put_error(9,0x85,0x7b,"pvkfmt.c",0x128);
            }
            CRYPTO_free(data);
            goto LAB_0815bb57;
          }
          iVar4 = 0x122;
          iVar2 = 0x41;
          goto LAB_0815bbd7;
        }
        if (local_28 < 0x31535345) {
          if (local_28 == 0x31415352) {
            bVar1 = false;
            iVar2 = (local_24 + 7U >> 3) + 4;
            goto LAB_0815bc0a;
          }
        }
        else if ((local_28 == 0x32415352) || (local_28 == 0x32535344)) {
          iVar2 = 0xc9;
          goto LAB_0815bbaa;
        }
        ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xcf);
      }
      else {
        ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xad);
      }
    }
    else if (local_30 == '\a') {
      iVar2 = 0xa2;
LAB_0815bbaa:
      ERR_put_error(9,0x86,0x78,"pvkfmt.c",iVar2);
    }
  }
  else {
    iVar4 = 0x117;
    iVar2 = 0x7b;
LAB_0815bbd7:
    ERR_put_error(9,0x85,iVar2,"pvkfmt.c",iVar4);
  }
  pEVar3 = (EVP_PKEY *)0x0;
LAB_0815bb57:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

