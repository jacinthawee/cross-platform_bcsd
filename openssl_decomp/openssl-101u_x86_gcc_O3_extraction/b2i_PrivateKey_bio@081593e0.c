
EVP_PKEY * b2i_PrivateKey_bio(BIO *in)

{
  bool bVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  void *data;
  uint uVar4;
  uint num;
  int in_GS_OFFSET;
  int line;
  char local_30;
  char local_2f;
  uint local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = BIO_read(in,&local_30,0x10);
  if (iVar2 == 0x10) {
    if (local_30 == '\x06') {
      iVar2 = 0x9d;
LAB_0815954b:
      ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar2);
    }
    else if (local_30 == '\a') {
      if (local_2f == '\x02') {
        if (local_28 != 0x31535344) {
          if (0x31535344 < local_28) {
            if (local_28 == 0x32415352) {
              bVar1 = false;
              num = (local_24 + 0xfU >> 4) * 5 + 4 + (local_24 + 7U >> 3) * 2;
            }
            else {
              if (local_28 != 0x32535344) goto LAB_08159630;
              bVar1 = true;
              num = (local_24 + 7U >> 3) * 2 + 0x40;
            }
            if (num < 0x19001) {
              data = CRYPTO_malloc(num,"pvkfmt.c",0x11a);
              if (data != (void *)0x0) {
                uVar4 = BIO_read(in,data,num);
                if (num == uVar4) {
                  if (bVar1) {
                    pEVar3 = (EVP_PKEY *)b2i_dss_isra_0();
                  }
                  else {
                    pEVar3 = (EVP_PKEY *)b2i_rsa_isra_1();
                  }
                }
                else {
                  pEVar3 = (EVP_PKEY *)0x0;
                  ERR_put_error(9,0x85,0x7b,"pvkfmt.c",0x121);
                }
                CRYPTO_free(data);
                goto LAB_08159427;
              }
              line = 0x11c;
              iVar2 = 0x41;
            }
            else {
              line = 0x117;
              iVar2 = 0x80;
            }
            goto LAB_0815951f;
          }
          if (local_28 != 0x31415352) {
LAB_08159630:
            ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xc9);
            goto LAB_08159425;
          }
        }
        iVar2 = 0xba;
        goto LAB_0815954b;
      }
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xac);
    }
  }
  else {
    line = 0x10e;
    iVar2 = 0x7b;
LAB_0815951f:
    ERR_put_error(9,0x85,iVar2,"pvkfmt.c",line);
  }
LAB_08159425:
  pEVar3 = (EVP_PKEY *)0x0;
LAB_08159427:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

