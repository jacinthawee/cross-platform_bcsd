
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  char cVar1;
  uchar *addr;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  int local_2c;
  uchar *local_28;
  int local_24;
  int local_20;
  
  iVar2 = BIO_gets(bp,buf,size);
  if (iVar2 < 1) {
    local_24 = 0;
    local_28 = (uchar *)0x0;
LAB_081ce43f:
    bs->length = local_24;
    bs->data = local_28;
    return 1;
  }
  cVar1 = buf[iVar2 + -1];
  local_20 = 0;
  local_28 = (uchar *)0x0;
  local_2c = 0;
  addr = local_28;
  do {
    if (cVar1 == '\n') {
      iVar5 = iVar2 + -1;
      buf[iVar5] = '\0';
      if (iVar5 == 0) {
LAB_081ce3e8:
        iVar5 = 0xd0;
        iVar2 = 0x96;
LAB_081ce3d2:
        ERR_put_error(0xd,0x67,iVar2,"f_string.c",iVar5);
        return 0;
      }
      cVar1 = buf[iVar2 + -2];
      iVar2 = iVar5;
    }
    iVar5 = iVar2;
    if (cVar1 == '\r') {
      iVar5 = iVar2 + -1;
      buf[iVar5] = '\0';
      if (iVar5 == 0) goto LAB_081ce3e8;
      cVar1 = buf[iVar2 + -2];
    }
    iVar2 = iVar5;
    do {
      iVar2 = iVar2 + -1;
      iVar3 = iVar5;
      if (iVar2 == 0) break;
    } while (((byte)(buf[iVar2] - 0x30U) < 10) ||
            (iVar3 = iVar2, (byte)((buf[iVar2] & 0xdfU) + 0xbf) < 6));
    buf[iVar3] = '\0';
    if (iVar3 == 1) goto LAB_081ce3e8;
    uVar4 = iVar3 - (uint)(cVar1 == '\\');
    if ((uVar4 & 1) != 0) {
      iVar5 = 0x9a;
      iVar2 = 0x91;
      goto LAB_081ce3d2;
    }
    iVar2 = (int)uVar4 >> 1;
    local_24 = local_2c + iVar2;
    local_28 = addr;
    if (local_20 < local_24) {
      local_20 = iVar2 + local_24;
      if (addr == (uchar *)0x0) {
        local_28 = (uchar *)CRYPTO_malloc(local_20,"f_string.c",0xa2);
      }
      else {
        local_28 = (uchar *)CRYPTO_realloc(addr,local_20,"f_string.c",0xa5);
      }
      if (local_28 == (uchar *)0x0) {
        ERR_put_error(0xd,0x67,0x41,"f_string.c",0xa8);
        if (addr == (uchar *)0x0) {
          return 0;
        }
        CRYPTO_free(addr);
        return 0;
      }
    }
    if (iVar2 != 0) {
      pbVar8 = (byte *)buf;
      pbVar9 = local_28 + local_2c;
      do {
        uVar7 = (uint)*pbVar8;
        uVar4 = uVar7 - 0x30;
        if (9 < uVar4) {
          if (uVar7 - 0x61 < 6) {
            uVar4 = uVar7 - 0x57;
            goto LAB_081ce2cf;
          }
          if (uVar7 - 0x41 < 6) {
            uVar4 = uVar7 - 0x37;
            goto LAB_081ce2cf;
          }
LAB_081ce3c0:
          iVar5 = 0xbc;
          iVar2 = 0x8d;
          goto LAB_081ce3d2;
        }
LAB_081ce2cf:
        uVar4 = uVar4 | (uint)*pbVar9 << 4;
        *pbVar9 = (byte)uVar4;
        uVar6 = (uint)pbVar8[1];
        uVar7 = uVar6 - 0x30;
        if (9 < uVar7) {
          if (uVar6 - 0x61 < 6) {
            uVar7 = uVar6 - 0x57;
          }
          else {
            if (5 < uVar6 - 0x41) goto LAB_081ce3c0;
            uVar7 = uVar6 - 0x37;
          }
        }
        pbVar8 = pbVar8 + 2;
        *pbVar9 = (byte)(uVar4 << 4) | (byte)uVar7;
        pbVar9 = pbVar9 + 1;
      } while (pbVar8 != (byte *)(buf + iVar2 * 2));
    }
    if (cVar1 != '\\') goto LAB_081ce43f;
    iVar2 = BIO_gets(bp,buf,size);
    if (iVar2 < 1) goto LAB_081ce3e8;
    cVar1 = buf[iVar2 + -1];
    addr = local_28;
    local_2c = local_24;
  } while( true );
}

