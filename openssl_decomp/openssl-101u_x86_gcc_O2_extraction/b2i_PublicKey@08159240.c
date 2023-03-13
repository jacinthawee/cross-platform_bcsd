
EVP_PKEY * b2i_PublicKey(uchar **in,long length)

{
  int iVar1;
  uchar *puVar2;
  uint uVar3;
  EVP_PKEY *pEVar4;
  int in_GS_OFFSET;
  int iVar5;
  int line;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  puVar2 = *in;
  if ((uint)length < 0x10) {
LAB_08159275:
    line = 0xf8;
    iVar5 = 0x7a;
  }
  else {
    if (*puVar2 != '\x06') {
      if (*puVar2 == '\a') {
        iVar5 = 0xa3;
LAB_081592e9:
        ERR_put_error(9,0x86,0x78,"pvkfmt.c",iVar5);
      }
      goto LAB_08159275;
    }
    if (puVar2[1] != '\x02') {
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xac);
      goto LAB_08159275;
    }
    uVar3 = *(uint *)(puVar2 + 8);
    if (uVar3 != 0x31535344) {
      if (uVar3 < 0x31535345) {
        if (uVar3 == 0x31415352) {
          if ((*(int *)(puVar2 + 0xc) + 7U >> 3) + 4 <= length - 0x10U) {
            pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1();
            goto LAB_08159295;
          }
          goto LAB_081593c3;
        }
      }
      else if ((uVar3 == 0x32415352) || (uVar3 == 0x32535344)) {
        iVar5 = 0xc3;
        goto LAB_081592e9;
      }
      ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xc9);
      goto LAB_08159275;
    }
    if ((*(int *)(puVar2 + 0xc) + 7U >> 3) * 3 + 0x2c <= length - 0x10U) {
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0();
      goto LAB_08159295;
    }
LAB_081593c3:
    line = 0xfd;
    iVar5 = 0x7b;
  }
  ERR_put_error(9,0x84,iVar5,"pvkfmt.c",line);
  pEVar4 = (EVP_PKEY *)0x0;
LAB_08159295:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

