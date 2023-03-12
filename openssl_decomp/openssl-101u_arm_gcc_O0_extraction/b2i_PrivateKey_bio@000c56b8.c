
EVP_PKEY * b2i_PrivateKey_bio(BIO *in)

{
  int iVar1;
  EVP_PKEY *data;
  uint uVar2;
  uint uVar3;
  EVP_PKEY *pEVar4;
  uint uVar5;
  bool bVar6;
  EVP_PKEY *local_3c;
  char local_38;
  char local_37;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  _union_271 local_24;
  
  local_24.ptr = __stack_chk_guard;
  iVar1 = BIO_read(in,&local_38,0x10);
  if (iVar1 != 0x10) {
    ERR_put_error(9,0x85,0x7b,"pvkfmt.c",0x10e);
    data = (EVP_PKEY *)0x0;
    goto LAB_000c56f6;
  }
  local_3c = (EVP_PKEY *)&local_38;
  if (local_38 == '\x06') {
    iVar1 = 0x9d;
LAB_000c5804:
    ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar1);
  }
  else if (local_38 == '\a') {
    if (local_37 == '\x02') {
      uVar3 = (uint)local_2e << 0x10 | (uint)local_2f << 8 | (uint)local_30 | (uint)local_2d << 0x18
      ;
      uVar5 = (uint)local_2a << 0x10 | (uint)local_2b << 8 | (uint)local_2c | (uint)local_29 << 0x18
      ;
      if (uVar3 != 0x31535344) {
        if (0x31535344 < uVar3) {
          if (uVar3 == 0x32415352) {
            bVar6 = false;
            uVar3 = (uVar5 + 0xf >> 4) * 5 + ((uVar5 + 7 >> 3) + 2) * 2;
          }
          else {
            if (uVar3 != 0x32535344) goto LAB_000c582e;
            bVar6 = true;
            uVar3 = ((uVar5 + 7 >> 3) + 0x20) * 2;
          }
          local_3c = (EVP_PKEY *)&stack0xffffffd8;
          if (uVar3 < 0x19001) {
            data = (EVP_PKEY *)CRYPTO_malloc(uVar3,"pvkfmt.c",0x11a);
            if (data == (EVP_PKEY *)0x0) {
              ERR_put_error(9,0x85,0x41,"pvkfmt.c",0x11c);
            }
            else {
              local_3c = data;
              uVar2 = BIO_read(in,data,uVar3);
              if (uVar3 == uVar2) {
                if (bVar6) {
                  pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&local_3c,uVar5,0);
                }
                else {
                  pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&local_3c,uVar5,0);
                }
              }
              else {
                pEVar4 = (EVP_PKEY *)0x0;
                ERR_put_error(9,0x85,0x7b,"pvkfmt.c",0x121);
              }
              CRYPTO_free(data);
              data = pEVar4;
            }
          }
          else {
            ERR_put_error(9,0x85,0x80,"pvkfmt.c",0x117);
            data = (EVP_PKEY *)0x0;
          }
          goto LAB_000c56f6;
        }
        if (uVar3 != 0x31415352) {
LAB_000c582e:
          ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xc9);
          goto LAB_000c56f4;
        }
      }
      iVar1 = 0xba;
      goto LAB_000c5804;
    }
    ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xac);
  }
LAB_000c56f4:
  data = (EVP_PKEY *)0x0;
LAB_000c56f6:
  if (local_24.ptr != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return data;
}

