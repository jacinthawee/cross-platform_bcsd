
EVP_PKEY * b2i_PrivateKey(uchar **in,long length)

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
  if ((uint)length < 0x10) goto LAB_0815b595;
  if (*puVar2 == '\x06') {
    iVar5 = 0x98;
LAB_0815b6a0:
    ERR_put_error(9,0x86,0x77,"pvkfmt.c",iVar5);
LAB_0815b595:
    line = 0xff;
    iVar5 = 0x7a;
  }
  else {
    if (*puVar2 != '\a') goto LAB_0815b595;
    if (puVar2[1] != '\x02') {
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xad);
      goto LAB_0815b595;
    }
    iVar5 = *(int *)(puVar2 + 0xc);
    uVar3 = *(uint *)(puVar2 + 8);
    if (uVar3 == 0x31535344) {
LAB_0815b698:
      iVar5 = 0xbe;
      goto LAB_0815b6a0;
    }
    if (uVar3 < 0x31535345) {
      if (uVar3 != 0x31415352) {
LAB_0815b6d0:
        ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xcf);
        goto LAB_0815b595;
      }
      goto LAB_0815b698;
    }
    if (uVar3 == 0x32415352) {
      if ((iVar5 + 0xfU >> 4) * 5 + 4 + (iVar5 + 7U >> 3) * 2 <= length - 0x10U) {
        pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1();
        goto LAB_0815b5b5;
      }
    }
    else {
      if (uVar3 != 0x32535344) goto LAB_0815b6d0;
      if ((iVar5 + 7U >> 3) * 2 + 0x40 <= length - 0x10U) {
        pEVar4 = (EVP_PKEY *)b2i_dss_isra_0();
        goto LAB_0815b5b5;
      }
    }
    line = 0x105;
    iVar5 = 0x7b;
  }
  ERR_put_error(9,0x84,iVar5,"pvkfmt.c",line);
  pEVar4 = (EVP_PKEY *)0x0;
LAB_0815b5b5:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

