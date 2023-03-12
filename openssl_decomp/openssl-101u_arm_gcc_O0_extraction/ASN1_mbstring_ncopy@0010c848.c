
int ASN1_mbstring_ncopy(ASN1_STRING **out,uchar *in,int len,int inform,ulong mask,long minsize,
                       long maxsize)

{
  uchar *puVar1;
  uchar *puVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  int line;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  ASN1_STRING *str;
  uint uVar9;
  uint uVar10;
  code *pcVar11;
  uchar *puVar12;
  uint local_58 [2];
  uchar *local_50;
  char acStack_4c [32];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (len == -1) {
    len = strlen((char *)in);
  }
  if (mask == 0) {
    mask = 0x2806;
  }
  uVar10 = len;
  switch(inform) {
  case 0x1000:
    if (len != 0) {
      uVar10 = 0;
      puVar12 = in;
      uVar9 = len;
      do {
        iVar5 = UTF8_getc(puVar12,uVar9,(ulong *)&local_50);
        if (iVar5 < 0) {
          ERR_put_error(0xd,0x7a,0x86,"a_mbstr.c",0x88);
          iVar5 = -1;
          goto LAB_0010ca62;
        }
        uVar9 = uVar9 - iVar5;
        puVar12 = puVar12 + iVar5;
        uVar10 = uVar10 + 1;
      } while (uVar9 != 0);
    }
    break;
  case 0x1001:
    break;
  case 0x1002:
    if ((len & 1U) != 0) {
      ERR_put_error(0xd,0x7a,0x81,"a_mbstr.c",0x74);
      iVar5 = -1;
      goto LAB_0010ca62;
    }
    uVar10 = len >> 1;
    break;
  default:
    ERR_put_error(0xd,0x7a,0xa0,"a_mbstr.c",0x92);
    iVar5 = -1;
    goto LAB_0010ca62;
  case 0x1004:
    if ((len & 3U) != 0) {
      ERR_put_error(0xd,0x7a,0x85,"a_mbstr.c",0x7d);
      iVar5 = -1;
      goto LAB_0010ca62;
    }
    uVar10 = len >> 2;
  }
  if ((minsize < 1) || (minsize <= (int)uVar10)) {
    pbVar7 = in;
    uVar9 = len;
    if ((maxsize < 1) || ((int)uVar10 <= maxsize)) {
joined_r0x0010c8ae:
      do {
        if (uVar9 == 0) {
          if ((int)(mask << 0x1e) < 0) {
            iVar6 = 0x1001;
            iVar5 = 0x13;
          }
          else if ((int)(mask << 0x1b) < 0) {
            iVar6 = 0x1001;
            iVar5 = 0x16;
          }
          else if ((int)(mask << 0x1d) < 0) {
            iVar6 = 0x1001;
            iVar5 = 0x14;
          }
          else if ((int)(mask << 0x14) < 0) {
            iVar6 = 0x1002;
            iVar5 = 0x1e;
          }
          else if ((mask & 0x100) == 0) {
            iVar6 = 0x1000;
            iVar5 = 0xc;
          }
          else {
            iVar6 = 0x1004;
            iVar5 = 0x1c;
          }
          if (out == (ASN1_STRING **)0x0) goto LAB_0010ca62;
          str = *out;
          if (str == (ASN1_STRING *)0x0) {
            str = ASN1_STRING_type_new(iVar5);
            line = 0xcb;
            if (str == (ASN1_STRING *)0x0) goto LAB_0010cd94;
            bVar3 = true;
            *out = str;
          }
          else {
            if (str->data != (uchar *)0x0) {
              str->length = 0;
              CRYPTO_free(str->data);
              str->data = (uchar *)0x0;
            }
            str->type = iVar5;
            bVar3 = false;
          }
          if (inform == iVar6) {
            iVar6 = ASN1_STRING_set(str,in,len);
            line = 0xd3;
            if (iVar6 == 0) goto LAB_0010cd94;
            goto LAB_0010ca62;
          }
          switch(iVar6) {
          case 0x1000:
            goto switchD_0010c9a0_caseD_1000;
          case 0x1001:
            iVar6 = uVar10 + 1;
            pcVar11 = cpy_asc + 1;
            goto LAB_0010cb3e;
          case 0x1002:
            uVar10 = uVar10 * 2;
            iVar6 = uVar10 + 1;
            pcVar11 = cpy_bmp + 1;
            goto LAB_0010cb3e;
          default:
            uVar10 = 0;
            pcVar11 = (code *)0x0;
            iVar6 = 1;
            goto LAB_0010cb3e;
          case 0x1004:
            uVar10 = uVar10 * 4;
            iVar6 = uVar10 + 1;
            pcVar11 = cpy_univ + 1;
            goto LAB_0010cb3e;
          }
        }
        if (inform == 0x1001) {
          local_50 = (uchar *)(uint)*pbVar7;
          uVar9 = uVar9 - 1;
          pbVar8 = pbVar7 + 1;
        }
        else if (inform == 0x1002) {
          uVar9 = uVar9 - 2;
          pbVar8 = pbVar7 + 2;
          local_50 = (uchar *)(uint)CONCAT11(*pbVar7,pbVar7[1]);
        }
        else if (inform == 0x1004) {
          uVar9 = uVar9 - 4;
          pbVar8 = pbVar7 + 4;
          local_50 = (uchar *)((uint)pbVar7[1] << 0x10 | (uint)*pbVar7 << 0x18 | (uint)pbVar7[3] |
                              (uint)pbVar7[2] << 8);
        }
        else {
          iVar5 = UTF8_getc(pbVar7,uVar9,(ulong *)&local_50);
          if (iVar5 < 0) break;
          uVar9 = uVar9 - iVar5;
          pbVar8 = pbVar7 + iVar5;
        }
        puVar12 = local_50;
        if ((int)(mask << 0x1e) < 0) {
          if (((uchar *)0x7f < local_50) ||
             ((((0x19 < ((uint)local_50 & 0xffffffdf) - 0x41 && ((uchar *)0x9 < local_50 + -0x30))
               && (local_50 != (uchar *)0x20)) &&
              (pcVar4 = strchr("\'()+,-./:=?",(int)local_50), pcVar4 == (char *)0x0)))) {
            mask = mask & 0xfffffffd;
            goto LAB_0010ca78;
          }
        }
        else {
LAB_0010ca78:
          if (((int)(mask << 0x1b) < 0) && ((uchar *)0x7f < puVar12)) {
            mask = mask & 0xffffffef;
          }
        }
        if (((int)(mask << 0x1d) < 0) && ((uchar *)0xff < puVar12)) {
          mask = mask & 0xfffffffb;
        }
        pbVar7 = pbVar8;
        if ((int)(mask << 0x14) < 0) {
          if ((uchar *)0xffff < puVar12) {
            mask = mask & 0xfffff7ff;
            goto LAB_0010c94c;
          }
          goto joined_r0x0010c8ae;
        }
LAB_0010c94c:
      } while (mask != 0);
      ERR_put_error(0xd,0x7a,0x7c,"a_mbstr.c",0xa6);
      iVar5 = -1;
    }
    else {
      ERR_put_error(0xd,0x7a,0x97,"a_mbstr.c",0x9e);
      BIO_snprintf(acStack_4c,0x20,"%ld",maxsize);
      ERR_add_error_data(2,"maxsize=",acStack_4c);
      iVar5 = -1;
    }
  }
  else {
    ERR_put_error(0xd,0x7a,0x98,"a_mbstr.c",0x97);
    BIO_snprintf(acStack_4c,0x20,"%ld",minsize);
    ERR_add_error_data(2,"minsize=",acStack_4c);
    iVar5 = -1;
  }
  goto LAB_0010ca62;
switchD_0010c9a0_caseD_1000:
  iVar6 = 1;
  uVar10 = len;
  if (len == 0) goto LAB_0010cc2e;
  if (inform == 0x1001) {
    uVar10 = 0;
    uVar9 = len;
    pbVar7 = in;
    do {
      local_50 = (uchar *)(uint)*pbVar7;
      uVar9 = uVar9 - 1;
      iVar6 = UTF8_putc((uchar *)0x0,-1,(ulong)local_50);
      uVar10 = uVar10 + iVar6;
      pbVar7 = pbVar7 + 1;
    } while (uVar9 != 0);
  }
  else {
    if (inform != 0x1002) {
      if (inform == 0x1004) {
        uVar10 = 0;
        pbVar7 = in;
        uVar9 = len;
        do {
          uVar9 = uVar9 - 4;
          local_50 = (uchar *)((uint)*pbVar7 << 0x18 | (uint)pbVar7[1] << 0x10 | (uint)pbVar7[3] |
                              (uint)pbVar7[2] << 8);
          iVar6 = UTF8_putc((uchar *)0x0,-1,(ulong)local_50);
          uVar10 = uVar10 + iVar6;
          pbVar7 = pbVar7 + 4;
        } while (uVar9 != 0);
        goto LAB_0010cc2a;
      }
      uVar10 = 0;
      uVar9 = len;
      puVar12 = in;
      goto LAB_0010cc00;
    }
    puVar12 = in + 2;
    uVar10 = 0;
    uVar9 = len;
    do {
      puVar1 = puVar12 + -2;
      puVar2 = puVar12 + -1;
      uVar9 = uVar9 - 2;
      puVar12 = puVar12 + 2;
      local_50 = (uchar *)(uint)CONCAT11(*puVar1,*puVar2);
      iVar6 = UTF8_putc((uchar *)0x0,-1,(ulong)local_50);
      uVar10 = uVar10 + iVar6;
    } while (uVar9 != 0);
  }
  goto LAB_0010cc2a;
  while( true ) {
    uVar9 = uVar9 - iVar6;
    puVar12 = puVar12 + iVar6;
    iVar6 = UTF8_putc((uchar *)0x0,-1,(ulong)local_50);
    uVar10 = uVar10 + iVar6;
    if (uVar9 == 0) break;
LAB_0010cc00:
    iVar6 = UTF8_getc(puVar12,uVar9,(ulong *)&local_50);
    if (iVar6 < 0) {
      iVar6 = uVar10 + 1;
      goto LAB_0010cc2e;
    }
  }
LAB_0010cc2a:
  iVar6 = uVar10 + 1;
LAB_0010cc2e:
  pcVar11 = cpy_utf8 + 1;
LAB_0010cb3e:
  local_50 = (uchar *)CRYPTO_malloc(iVar6,"a_mbstr.c",0xf0);
  if (local_50 == (uchar *)0x0) {
    if (bVar3) {
      ASN1_STRING_free(str);
    }
    line = 0xf3;
LAB_0010cd94:
    ERR_put_error(0xd,0x7a,0x41,"a_mbstr.c",line);
    iVar5 = -1;
  }
  else {
    str->length = uVar10;
    str->data = local_50;
    local_50[uVar10] = '\0';
    if (len != 0) {
      if (inform == 0x1001) {
        if (pcVar11 != (code *)0x0) {
          do {
            local_58[0] = (uint)*in;
            len = len - 1;
            iVar6 = (*pcVar11)(local_58[0],&local_50);
            if (iVar6 < 1) break;
            in = in + 1;
          } while (len != 0);
        }
      }
      else if (pcVar11 == (code *)0x0) {
        if ((inform != 0x1004) && (inform != 0x1002)) {
          do {
            iVar6 = UTF8_getc(in,len,local_58);
            if (iVar6 < 0) break;
            len = len - iVar6;
            in = in + iVar6;
          } while (len != 0);
        }
      }
      else if (inform == 0x1002) {
        puVar12 = in + 2;
        do {
          len = len - 2;
          local_58[0] = (uint)CONCAT11(puVar12[-2],puVar12[-1]);
          iVar6 = (*pcVar11)(local_58[0],&local_50);
          if (iVar6 < 1) break;
          puVar12 = puVar12 + 2;
        } while (len != 0);
      }
      else if (inform == 0x1004) {
        do {
          len = len - 4;
          local_58[0] = (uint)in[1] << 0x10 | (uint)*in << 0x18 | (uint)in[3] | (uint)in[2] << 8;
          iVar6 = (*pcVar11)(local_58[0],&local_50);
          if (iVar6 < 1) break;
          in = in + 4;
        } while (len != 0);
      }
      else {
        while (iVar6 = UTF8_getc(in,len,local_58), -1 < iVar6) {
          len = len - iVar6;
          in = in + iVar6;
          iVar6 = (*pcVar11)(local_58[0],&local_50);
          if ((iVar6 < 1) || (len == 0)) break;
        }
      }
    }
  }
LAB_0010ca62:
  if (local_2c == __stack_chk_guard) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

