
EVP_PKEY * b2i_PublicKey_bio(BIO *in)

{
  bool bVar1;
  int iVar2;
  EVP_PKEY *data;
  uint uVar3;
  uint uVar4;
  EVP_PKEY *pEVar5;
  uint uVar6;
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
  iVar2 = BIO_read(in,&local_38,0x10);
  if (iVar2 != 0x10) {
    ERR_put_error(9,0x85,0x7b,"pvkfmt.c",0x10e);
    data = (EVP_PKEY *)0x0;
    goto LAB_000c5900;
  }
  local_3c = (EVP_PKEY *)&local_38;
  if (local_38 == '\x06') {
    if (local_37 == '\x02') {
      uVar4 = (uint)local_2e << 0x10 | (uint)local_2f << 8 | (uint)local_30 | (uint)local_2d << 0x18
      ;
      uVar6 = (uint)local_2a << 0x10 | (uint)local_2b << 8 | (uint)local_2c | (uint)local_29 << 0x18
      ;
      if (uVar4 == 0x31535344) {
        bVar1 = true;
        uVar4 = (uVar6 + 7 >> 3) * 3 + 0x2c;
LAB_000c59de:
        local_3c = (EVP_PKEY *)&stack0xffffffd8;
        if (uVar4 < 0x19001) {
          data = (EVP_PKEY *)CRYPTO_malloc(uVar4,"pvkfmt.c",0x11a);
          if (data == (EVP_PKEY *)0x0) {
            ERR_put_error(9,0x85,0x41,"pvkfmt.c",0x11c);
          }
          else {
            local_3c = data;
            uVar3 = BIO_read(in,data,uVar4);
            if (uVar4 == uVar3) {
              if (bVar1) {
                pEVar5 = (EVP_PKEY *)b2i_dss_isra_0();
              }
              else {
                pEVar5 = (EVP_PKEY *)b2i_rsa_isra_1(&local_3c,uVar6,1);
              }
            }
            else {
              pEVar5 = (EVP_PKEY *)0x0;
              ERR_put_error(9,0x85,0x7b,"pvkfmt.c",0x121);
            }
            CRYPTO_free(data);
            data = pEVar5;
          }
        }
        else {
          ERR_put_error(9,0x85,0x80,"pvkfmt.c",0x117);
          data = (EVP_PKEY *)0x0;
        }
        goto LAB_000c5900;
      }
      if (uVar4 < 0x31535345) {
        if (uVar4 == 0x31415352) {
          bVar1 = false;
          uVar4 = (uVar6 + 7 >> 3) + 4;
          goto LAB_000c59de;
        }
      }
      else if ((uVar4 == 0x32415352) || (uVar4 == 0x32535344)) {
        iVar2 = 0xc3;
        goto LAB_000c5980;
      }
      ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xc9);
    }
    else {
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xac);
    }
  }
  else if (local_38 == '\a') {
    iVar2 = 0xa3;
LAB_000c5980:
    ERR_put_error(9,0x86,0x78,"pvkfmt.c",iVar2);
  }
  data = (EVP_PKEY *)0x0;
LAB_000c5900:
  if (local_24.ptr != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return data;
}
