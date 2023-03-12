
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  byte *pbVar1;
  bool bVar2;
  uchar *addr;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  char local_31;
  int local_30;
  uchar *local_2c;
  int local_28;
  
  bs->type = 2;
  iVar3 = BIO_gets(bp,buf,size);
  if (0 < iVar3) {
    local_31 = buf[iVar3 + -1];
    bVar2 = true;
    local_28 = 0;
    local_30 = 0;
    local_2c = (uchar *)0x0;
    iVar10 = local_28;
    addr = local_2c;
    do {
      if (local_31 == '\n') {
        iVar5 = iVar3 + -1;
        buf[iVar5] = '\0';
        if (iVar5 == 0) break;
        local_31 = buf[iVar3 + -2];
        iVar3 = iVar5;
      }
      iVar5 = iVar3;
      if (local_31 == '\r') {
        buf[iVar3 + -1] = '\0';
        iVar5 = iVar3 + -1;
        if (iVar5 == 0) break;
        local_31 = buf[iVar3 + -2];
      }
      iVar3 = 0;
      pbVar6 = (byte *)buf;
      do {
        if ((9 < (byte)(*pbVar6 - 0x30)) && (5 < (byte)((*pbVar6 & 0xdf) + 0xbf)))
        goto LAB_0814f568;
        iVar3 = iVar3 + 1;
        pbVar6 = pbVar6 + 1;
      } while (iVar3 < iVar5);
      pbVar6 = (byte *)(buf + iVar5);
      iVar3 = iVar5;
LAB_0814f568:
      *pbVar6 = 0;
      if (iVar3 < 2) break;
      pbVar6 = (byte *)buf;
      if (((bVar2) && (*buf == '0')) && (buf[1] == '0')) {
        pbVar6 = (byte *)(buf + 2);
        iVar3 = iVar3 + -2;
      }
      uVar4 = iVar3 - (uint)(local_31 == '\\');
      if ((uVar4 & 1) != 0) {
        iVar10 = 0xa2;
        iVar3 = 0x91;
        goto LAB_0814f722;
      }
      iVar3 = (int)uVar4 >> 1;
      iVar5 = local_30 + iVar3;
      local_2c = addr;
      local_28 = iVar10;
      if (iVar10 < iVar5) {
        local_28 = iVar3 + iVar5;
        if (addr == (uchar *)0x0) {
          local_2c = (uchar *)CRYPTO_malloc(local_28,"f_int.c",0xaa);
        }
        else {
          local_2c = (uchar *)CRYPTO_realloc_clean(addr,iVar10,local_28,"f_int.c",0xac);
        }
        if (local_2c == (uchar *)0x0) {
          ERR_put_error(0xd,0x66,0x41,"f_int.c",0xaf);
          if (addr == (uchar *)0x0) {
            return 0;
          }
          CRYPTO_free(addr);
          return 0;
        }
      }
      if (iVar3 != 0) {
        pbVar1 = pbVar6 + iVar3 * 2;
        pbVar9 = local_2c + local_30;
        do {
          uVar8 = (uint)*pbVar6;
          uVar4 = uVar8 - 0x30;
          if (9 < uVar4) {
            if (uVar8 - 0x61 < 6) {
              uVar4 = uVar8 - 0x57;
              goto LAB_0814f60f;
            }
            if (uVar8 - 0x41 < 6) {
              uVar4 = uVar8 - 0x37;
              goto LAB_0814f60f;
            }
LAB_0814f710:
            iVar10 = 0xc3;
            iVar3 = 0x8d;
            goto LAB_0814f722;
          }
LAB_0814f60f:
          uVar4 = uVar4 | (uint)*pbVar9 << 4;
          *pbVar9 = (byte)uVar4;
          uVar7 = (uint)pbVar6[1];
          uVar8 = uVar7 - 0x30;
          if (9 < uVar8) {
            if (uVar7 - 0x61 < 6) {
              uVar8 = uVar7 - 0x57;
            }
            else {
              if (5 < uVar7 - 0x41) goto LAB_0814f710;
              uVar8 = uVar7 - 0x37;
            }
          }
          pbVar6 = pbVar6 + 2;
          *pbVar9 = (byte)(uVar4 << 4) | (byte)uVar8;
          pbVar9 = pbVar9 + 1;
        } while (pbVar6 != pbVar1);
      }
      if (local_31 != '\\') {
        bs->length = iVar5;
        bs->data = local_2c;
        return 1;
      }
      iVar3 = BIO_gets(bp,buf,size);
      bVar2 = false;
      if (iVar3 < 1) break;
      local_31 = buf[iVar3 + -1];
      iVar10 = local_28;
      local_30 = iVar5;
      addr = local_2c;
    } while( true );
  }
  iVar10 = 0xd7;
  iVar3 = 0x96;
LAB_0814f722:
  ERR_put_error(0xd,0x66,iVar3,"f_int.c",iVar10);
  return 0;
}

