
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  char local_2d;
  uchar *local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  iVar1 = BIO_gets(bp,buf,size);
  if (iVar1 < 1) {
    local_24 = 0;
    local_2c = (uchar *)0x0;
LAB_081cd296:
    bs->length = local_24;
    bs->data = local_2c;
    return 1;
  }
  local_2d = buf[iVar1 + -1];
  local_20 = 0;
  local_2c = (uchar *)0x0;
  local_28 = 0;
  do {
    if (local_2d == '\n') {
      iVar5 = iVar1 + -1;
      buf[iVar5] = '\0';
      if (iVar5 == 0) {
LAB_081cd247:
        ERR_put_error(0xd,0x67,0x96,"f_string.c",0xcc);
LAB_081cd22e:
        CRYPTO_free(local_2c);
        return 0;
      }
      local_2d = buf[iVar1 + -2];
      iVar1 = iVar5;
    }
    iVar5 = iVar1;
    if (local_2d == '\r') {
      iVar5 = iVar1 + -1;
      buf[iVar5] = '\0';
      if (iVar5 == 0) goto LAB_081cd247;
      local_2d = buf[iVar1 + -2];
    }
    iVar1 = iVar5;
    do {
      iVar1 = iVar1 + -1;
      iVar2 = iVar5;
      if (iVar1 == 0) break;
    } while (((byte)(buf[iVar1] - 0x30U) < 10) ||
            (iVar2 = iVar1, (byte)((buf[iVar1] & 0xdfU) + 0xbf) < 6));
    buf[iVar2] = '\0';
    if (iVar2 == 1) goto LAB_081cd247;
    uVar3 = iVar2 - (uint)(local_2d == '\\');
    if ((uVar3 & 1) != 0) {
      ERR_put_error(0xd,0x67,0x91,"f_string.c",0x9b);
      goto LAB_081cd22e;
    }
    iVar1 = (int)uVar3 >> 1;
    local_24 = local_28 + iVar1;
    puVar4 = local_2c;
    if (local_20 < local_24) {
      local_20 = iVar1 + local_24;
      if (local_2c == (uchar *)0x0) {
        puVar4 = (uchar *)CRYPTO_malloc(local_20,"f_string.c",0xa2);
      }
      else {
        puVar4 = (uchar *)CRYPTO_realloc(local_2c,local_20,"f_string.c",0xa6);
      }
      if (puVar4 == (uchar *)0x0) {
        ERR_put_error(0xd,0x67,0x41,"f_string.c",0xa8);
        goto LAB_081cd22e;
      }
    }
    local_2c = puVar4;
    if (iVar1 != 0) {
      pbVar8 = (byte *)buf;
      pbVar9 = local_2c + local_28;
      do {
        uVar7 = (uint)*pbVar8;
        uVar3 = uVar7 - 0x30;
        if (9 < uVar3) {
          if (uVar7 - 0x61 < 6) {
            uVar3 = uVar7 - 0x57;
            goto LAB_081cd11f;
          }
          if (uVar7 - 0x41 < 6) {
            uVar3 = uVar7 - 0x37;
            goto LAB_081cd11f;
          }
LAB_081cd210:
          ERR_put_error(0xd,0x67,0x8d,"f_string.c",0xb9);
          goto LAB_081cd22e;
        }
LAB_081cd11f:
        uVar3 = uVar3 | (uint)*pbVar9 << 4;
        *pbVar9 = (byte)uVar3;
        uVar6 = (uint)pbVar8[1];
        uVar7 = uVar6 - 0x30;
        if (9 < uVar7) {
          if (uVar6 - 0x61 < 6) {
            uVar7 = uVar6 - 0x57;
          }
          else {
            if (5 < uVar6 - 0x41) goto LAB_081cd210;
            uVar7 = uVar6 - 0x37;
          }
        }
        pbVar8 = pbVar8 + 2;
        *pbVar9 = (byte)(uVar3 << 4) | (byte)uVar7;
        pbVar9 = pbVar9 + 1;
      } while (pbVar8 != (byte *)(buf + iVar1 * 2));
    }
    if (local_2d != '\\') goto LAB_081cd296;
    iVar1 = BIO_gets(bp,buf,size);
    if (iVar1 < 1) goto LAB_081cd247;
    local_2d = buf[iVar1 + -1];
    local_28 = local_24;
  } while( true );
}

