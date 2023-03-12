
int ASN1_mbstring_ncopy(ASN1_STRING **out,uchar *in,int len,int inform,ulong mask,long minsize,
                       long maxsize)

{
  ushort uVar1;
  uint uVar2;
  bool bVar3;
  char *pcVar4;
  ASN1_STRING *str;
  code *pcVar5;
  uint *puVar6;
  byte *pbVar7;
  int iVar8;
  uchar *puVar9;
  ushort *puVar10;
  int in_GS_OFFSET;
  int iVar11;
  int local_5c;
  int local_54;
  uchar *local_48;
  uint local_44;
  char local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (len == -1) {
    len = strlen((char *)in);
  }
  if (mask == 0) {
    mask = 0x2806;
  }
  if (inform == 0x1001) {
    local_54 = len;
LAB_081cbf88:
    if ((0 < minsize) && (local_54 < minsize)) {
      ERR_put_error(0xd,0x7a,0x98,"a_mbstr.c",0x93);
      BIO_snprintf(local_40,0x20,"%ld",minsize);
      ERR_add_error_data(2,"minsize=",local_40);
      local_5c = -1;
      goto LAB_081cbf63;
    }
    puVar6 = (uint *)in;
    iVar8 = len;
    if ((0 < maxsize) && (maxsize < local_54)) {
      ERR_put_error(0xd,0x7a,0x97,"a_mbstr.c",0x9a);
      BIO_snprintf(local_40,0x20,"%ld",maxsize);
      ERR_add_error_data(2,"maxsize=",local_40);
      local_5c = -1;
      goto LAB_081cbf63;
    }
joined_r0x081cbfba:
    if (iVar8 != 0) {
      if (inform == 0x1001) {
        local_44 = (uint)*(byte *)puVar6;
        iVar8 = iVar8 + -1;
        puVar6 = (uint *)((int)puVar6 + 1);
      }
      else if (inform == 0x1002) {
        uVar1 = *(ushort *)puVar6;
        iVar8 = iVar8 + -2;
        puVar6 = (uint *)((int)puVar6 + 2);
        local_44 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
      }
      else if (inform == 0x1004) {
        uVar2 = *puVar6;
        iVar8 = iVar8 + -4;
        puVar6 = puVar6 + 1;
        local_44 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      }
      else {
        iVar11 = UTF8_getc((uchar *)puVar6,iVar8,&local_44);
        if (iVar11 < 0) goto LAB_081cc748;
        iVar8 = iVar8 - iVar11;
        puVar6 = (uint *)((int)puVar6 + iVar11);
      }
      uVar2 = local_44;
      if ((mask & 2) == 0) {
LAB_081cc084:
        if (((mask & 0x10) != 0) && (0x7f < uVar2)) {
          mask = mask & 0xffffffef;
        }
      }
      else if ((0x7f < local_44) ||
              ((((0x19 < (local_44 & 0xffffffdf) - 0x41 && (9 < local_44 - 0x30)) &&
                (local_44 != 0x20)) &&
               (pcVar4 = strchr("\'()+,-./:=?",local_44), pcVar4 == (char *)0x0)))) {
        mask = mask & 0xfffffffd;
        goto LAB_081cc084;
      }
      if (((mask & 4) != 0) && (0xff < uVar2)) {
        mask = mask & 0xfffffffb;
      }
      if ((mask & 0x800) != 0) {
        if (0xffff < uVar2) {
          mask = mask & 0xfffff7ff;
          goto LAB_081cc040;
        }
        goto joined_r0x081cbfba;
      }
LAB_081cc040:
      if (mask == 0) goto LAB_081cc748;
      goto joined_r0x081cbfba;
    }
    if ((mask & 2) == 0) {
      if ((mask & 0x10) == 0) {
        if ((mask & 4) == 0) {
          if ((mask & 0x800) == 0) {
            iVar8 = (-(uint)((mask & 0x100) == 0) & 0xfffffffc) + 0x1004;
            local_5c = (-(uint)((mask & 0x100) == 0) & 0xfffffff0) + 0x1c;
          }
          else {
            iVar8 = 0x1002;
            local_5c = 0x1e;
          }
        }
        else {
          iVar8 = 0x1001;
          local_5c = 0x14;
        }
      }
      else {
        iVar8 = 0x1001;
        local_5c = 0x16;
      }
    }
    else {
      iVar8 = 0x1001;
      local_5c = 0x13;
    }
    if (out == (ASN1_STRING **)0x0) goto LAB_081cbf63;
    str = *out;
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_STRING_type_new(local_5c);
      if (str == (ASN1_STRING *)0x0) {
        iVar11 = 0xc5;
        iVar8 = 0x41;
        goto LAB_081cbf52;
      }
      bVar3 = true;
      *out = str;
    }
    else {
      if (str->data != (uchar *)0x0) {
        str->length = 0;
        CRYPTO_free(str->data);
        str->data = (uchar *)0x0;
      }
      bVar3 = false;
      str->type = local_5c;
    }
    if (iVar8 == inform) {
      iVar8 = ASN1_STRING_set(str,in,len);
      if (iVar8 != 0) goto LAB_081cbf63;
      iVar11 = 0xcd;
      iVar8 = 0x41;
      goto LAB_081cbf52;
    }
    if (iVar8 == 0x1001) {
      pcVar5 = cpy_asc;
      iVar8 = local_54 + 1;
      goto LAB_081cc1a7;
    }
    if (0x1001 < iVar8) {
      if (iVar8 == 0x1002) {
        pcVar5 = cpy_bmp;
        local_54 = local_54 * 2;
        iVar8 = local_54 + 1;
      }
      else if (iVar8 == 0x1004) {
        pcVar5 = cpy_univ;
        local_54 = local_54 * 4;
        iVar8 = local_54 + 1;
      }
      else {
LAB_081cc418:
        iVar8 = 1;
        local_54 = 0;
        pcVar5 = (code *)0x0;
      }
      goto LAB_081cc1a7;
    }
    if (iVar8 != 0x1000) goto LAB_081cc418;
    local_54 = 0;
    iVar8 = 1;
    if (len == 0) goto LAB_081cc36a;
    if (inform == 0x1001) {
      local_54 = 0;
      pbVar7 = in;
      iVar8 = len;
      do {
        local_44 = (uint)*pbVar7;
        iVar8 = iVar8 + -1;
        iVar11 = UTF8_putc((uchar *)0x0,-1,local_44);
        local_54 = local_54 + iVar11;
        pbVar7 = pbVar7 + 1;
      } while (iVar8 != 0);
    }
    else {
      if (inform != 0x1002) {
        if (inform == 0x1004) {
          local_54 = 0;
          puVar6 = (uint *)in;
          iVar8 = len;
          do {
            uVar2 = *puVar6;
            iVar8 = iVar8 + -4;
            puVar6 = puVar6 + 1;
            local_44 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                       uVar2 << 0x18;
            iVar11 = UTF8_putc((uchar *)0x0,-1,local_44);
            local_54 = local_54 + iVar11;
          } while (iVar8 != 0);
          goto LAB_081cc57a;
        }
        local_54 = 0;
        iVar8 = len;
        puVar9 = in;
        goto LAB_081cc349;
      }
      local_54 = 0;
      iVar8 = len;
      puVar10 = (ushort *)in;
      do {
        uVar1 = *puVar10;
        iVar8 = iVar8 + -2;
        puVar10 = puVar10 + 1;
        local_44 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
        iVar11 = UTF8_putc((uchar *)0x0,-1,local_44);
        local_54 = local_54 + iVar11;
      } while (iVar8 != 0);
    }
    goto LAB_081cc57a;
  }
  if (inform < 0x1002) {
    if (inform == 0x1000) {
      if (len == 0) {
        local_54 = 0;
      }
      else {
        local_54 = 0;
        iVar8 = len;
        puVar9 = in;
        do {
          iVar11 = UTF8_getc(puVar9,iVar8,&local_44);
          if (iVar11 < 0) {
            iVar11 = 0x84;
            iVar8 = 0x86;
            goto LAB_081cbf52;
          }
          puVar9 = puVar9 + iVar11;
          local_54 = local_54 + 1;
          iVar8 = iVar8 - iVar11;
        } while (iVar8 != 0);
      }
      goto LAB_081cbf88;
    }
LAB_081cbf40:
    iVar11 = 0x8e;
    iVar8 = 0xa0;
  }
  else if (inform == 0x1002) {
    if ((len & 1U) == 0) {
      local_54 = len >> 1;
      goto LAB_081cbf88;
    }
    iVar11 = 0x6f;
    iVar8 = 0x81;
  }
  else {
    if (inform != 0x1004) goto LAB_081cbf40;
    if ((len & 3U) == 0) {
      local_54 = len >> 2;
      goto LAB_081cbf88;
    }
    iVar11 = 0x78;
    iVar8 = 0x85;
  }
  goto LAB_081cbf52;
LAB_081cc748:
  iVar11 = 0xa2;
  iVar8 = 0x7c;
  goto LAB_081cbf52;
  while( true ) {
    iVar8 = iVar8 - iVar11;
    puVar9 = puVar9 + iVar11;
    iVar11 = UTF8_putc((uchar *)0x0,-1,local_44);
    local_54 = local_54 + iVar11;
    if (iVar8 == 0) break;
LAB_081cc349:
    iVar11 = UTF8_getc(puVar9,iVar8,&local_44);
    if (iVar11 < 0) {
      iVar8 = local_54 + 1;
      goto LAB_081cc36a;
    }
  }
LAB_081cc57a:
  iVar8 = local_54 + 1;
LAB_081cc36a:
  pcVar5 = cpy_utf8;
LAB_081cc1a7:
  local_48 = (uchar *)CRYPTO_malloc(iVar8,"a_mbstr.c",0xea);
  if (local_48 != (uchar *)0x0) {
    str->data = local_48;
    str->length = local_54;
    local_48[local_54] = '\0';
    if (len != 0) {
      if (inform == 0x1001) {
        if (pcVar5 != (code *)0x0) {
          do {
            local_44 = (uint)*in;
            len = len + -1;
            iVar8 = (*pcVar5)(local_44,&local_48);
            if (iVar8 < 1) break;
            in = in + 1;
          } while (len != 0);
        }
      }
      else if (pcVar5 == (code *)0x0) {
        if ((inform != 0x1004) && (inform != 0x1002)) {
          do {
            iVar8 = UTF8_getc(in,len,&local_44);
            if (iVar8 < 0) break;
            in = in + iVar8;
            len = len - iVar8;
          } while (len != 0);
        }
      }
      else if (inform == 0x1002) {
        do {
          uVar1 = *(ushort *)in;
          in = (uchar *)((int)in + 2);
          len = len + -2;
          local_44 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
          iVar8 = (*pcVar5)(local_44,&local_48);
          if (iVar8 < 1) break;
        } while (len != 0);
      }
      else if (inform == 0x1004) {
        do {
          uVar2 = *(uint *)in;
          in = (uchar *)((int)in + 4);
          len = len + -4;
          local_44 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18
          ;
          iVar8 = (*pcVar5)(local_44,&local_48);
          if (iVar8 < 1) break;
        } while (len != 0);
      }
      else {
        while (iVar8 = UTF8_getc(in,len,&local_44), -1 < iVar8) {
          len = len - iVar8;
          in = in + iVar8;
          iVar8 = (*pcVar5)(local_44,&local_48);
          if ((iVar8 < 1) || (len == 0)) break;
        }
      }
    }
    goto LAB_081cbf63;
  }
  if (bVar3) {
    ASN1_STRING_free(str);
  }
  iVar11 = 0xec;
  iVar8 = 0x41;
LAB_081cbf52:
  ERR_put_error(0xd,0x7a,iVar8,"a_mbstr.c",iVar11);
  local_5c = -1;
LAB_081cbf63:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_5c;
}

