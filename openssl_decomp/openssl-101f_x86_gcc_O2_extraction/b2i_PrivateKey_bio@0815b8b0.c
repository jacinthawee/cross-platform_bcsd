
EVP_PKEY * b2i_PrivateKey_bio(BIO *in)

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
      iVar2 = 0x98;
LAB_0815ba13:
      ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar2);
    }
    else if (local_30 == '\a') {
      if (local_2f == '\x02') {
        if (local_28 != 0x31535344) {
          if (0x31535344 < local_28) {
            if (local_28 == 0x32415352) {
              bVar1 = false;
              iVar2 = (local_24 + 0xfU >> 4) * 5 + 4 + (local_24 + 7U >> 3) * 2;
            }
            else {
              if (local_28 != 0x32535344) goto LAB_0815bad0;
              bVar1 = true;
              iVar2 = (local_24 + 7U >> 3) * 2 + 0x40;
            }
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
              goto LAB_0815b8f7;
            }
            iVar4 = 0x122;
            iVar2 = 0x41;
            goto LAB_0815b9e7;
          }
          if (local_28 != 0x31415352) {
LAB_0815bad0:
            ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xcf);
            goto LAB_0815b8f5;
          }
        }
        iVar2 = 0xbe;
        goto LAB_0815ba13;
      }
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xad);
    }
  }
  else {
    iVar4 = 0x117;
    iVar2 = 0x7b;
LAB_0815b9e7:
    ERR_put_error(9,0x85,iVar2,"pvkfmt.c",iVar4);
  }
LAB_0815b8f5:
  pEVar3 = (EVP_PKEY *)0x0;
LAB_0815b8f7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

