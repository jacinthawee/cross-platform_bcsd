
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  byte *pbVar1;
  bool bVar2;
  int old_num;
  int iVar3;
  uint uVar4;
  int iVar5;
  uchar *puVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  char local_31;
  uchar *local_30;
  int local_2c;
  int local_28;
  
  bs->type = 2;
  iVar3 = BIO_gets(bp,buf,size);
  if (0 < iVar3) {
    local_31 = buf[iVar3 + -1];
    bVar2 = true;
    local_28 = 0;
    local_2c = 0;
    local_30 = (uchar *)0x0;
    old_num = local_28;
    do {
      if (local_31 == '\n') {
        iVar5 = iVar3 + -1;
        buf[iVar5] = '\0';
        if (iVar5 == 0) goto LAB_0814d084;
        local_31 = buf[iVar3 + -2];
        iVar3 = iVar5;
      }
      iVar5 = iVar3;
      if (local_31 == '\r') {
        buf[iVar3 + -1] = '\0';
        iVar5 = iVar3 + -1;
        if (iVar5 == 0) goto LAB_0814d084;
        local_31 = buf[iVar3 + -2];
      }
      iVar3 = 0;
      pbVar7 = (byte *)buf;
      do {
        if ((9 < (byte)(*pbVar7 - 0x30)) && (5 < (byte)((*pbVar7 & 0xdf) + 0xbf)))
        goto LAB_0814ce88;
        iVar3 = iVar3 + 1;
        pbVar7 = pbVar7 + 1;
      } while (iVar3 < iVar5);
      pbVar7 = (byte *)(buf + iVar5);
      iVar3 = iVar5;
LAB_0814ce88:
      *pbVar7 = 0;
      if (iVar3 < 2) goto LAB_0814d084;
      pbVar7 = (byte *)buf;
      if (((bVar2) && (*buf == '0')) && (buf[1] == '0')) {
        pbVar7 = (byte *)(buf + 2);
        iVar3 = iVar3 + -2;
      }
      uVar4 = iVar3 - (uint)(local_31 == '\\');
      if ((uVar4 & 1) != 0) {
        ERR_put_error(0xd,0x66,0x91,"f_int.c",0xa3);
        goto LAB_0814d04e;
      }
      iVar3 = (int)uVar4 >> 1;
      iVar5 = local_2c + iVar3;
      puVar6 = local_30;
      local_28 = old_num;
      if (old_num < iVar5) {
        local_28 = iVar3 + iVar5;
        if (local_30 == (uchar *)0x0) {
          puVar6 = (uchar *)CRYPTO_malloc(local_28,"f_int.c",0xaa);
        }
        else {
          puVar6 = (uchar *)CRYPTO_realloc_clean(local_30,old_num,local_28,"f_int.c",0xac);
        }
        if (puVar6 == (uchar *)0x0) {
          ERR_put_error(0xd,0x66,0x41,"f_int.c",0xae);
          goto LAB_0814d04e;
        }
      }
      local_30 = puVar6;
      if (iVar3 != 0) {
        pbVar1 = pbVar7 + iVar3 * 2;
        pbVar10 = local_30 + local_2c;
        do {
          uVar9 = (uint)*pbVar7;
          uVar4 = uVar9 - 0x30;
          if (9 < uVar4) {
            if (uVar9 - 0x61 < 6) {
              uVar4 = uVar9 - 0x57;
              goto LAB_0814cf2f;
            }
            if (uVar9 - 0x41 < 6) {
              uVar4 = uVar9 - 0x37;
              goto LAB_0814cf2f;
            }
LAB_0814d030:
            ERR_put_error(0xd,0x66,0x8d,"f_int.c",0xbf);
            goto LAB_0814d04e;
          }
LAB_0814cf2f:
          uVar4 = uVar4 | (uint)*pbVar10 << 4;
          *pbVar10 = (byte)uVar4;
          uVar8 = (uint)pbVar7[1];
          uVar9 = uVar8 - 0x30;
          if (9 < uVar9) {
            if (uVar8 - 0x61 < 6) {
              uVar9 = uVar8 - 0x57;
            }
            else {
              if (5 < uVar8 - 0x41) goto LAB_0814d030;
              uVar9 = uVar8 - 0x37;
            }
          }
          pbVar7 = pbVar7 + 2;
          *pbVar10 = (byte)(uVar4 << 4) | (byte)uVar9;
          pbVar10 = pbVar10 + 1;
        } while (pbVar7 != pbVar1);
      }
      if (local_31 != '\\') {
        bs->length = iVar5;
        bs->data = local_30;
        return 1;
      }
      iVar3 = BIO_gets(bp,buf,size);
      bVar2 = false;
      if (iVar3 < 1) goto LAB_0814d084;
      local_31 = buf[iVar3 + -1];
      old_num = local_28;
      local_2c = iVar5;
    } while( true );
  }
  local_30 = (uchar *)0x0;
LAB_0814d084:
  ERR_put_error(0xd,0x66,0x96,"f_int.c",0xd2);
LAB_0814d04e:
  CRYPTO_free(local_30);
  return 0;
}

