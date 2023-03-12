
int ASN1_mbstring_ncopy(ASN1_STRING **out,uchar *in,int len,int inform,ulong mask,long minsize,
                       long maxsize)

{
  ushort uVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  code *pcVar12;
  ulong *puVar13;
  byte *pbVar14;
  ushort *puVar15;
  ASN1_STRING *pAVar16;
  uint *str;
  uchar *puVar17;
  uint uVar18;
  uint local_6c;
  uchar *local_54;
  uint local_50;
  undefined auStack_4c [32];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (len == -1) {
    len = (*(code *)PTR_strlen_006aab30)(in);
    if (mask == 0) {
      mask = 0x2806;
    }
  }
  else if (mask == 0) {
    mask = 0x2806;
  }
  local_6c = len;
  if (inform != 0x1001) {
    if (inform < 0x1002) {
      if (inform != 0x1000) {
LAB_0060a16c:
        uVar10 = 0xa0;
        uVar8 = 0x8e;
        goto LAB_0060a17c;
      }
      local_6c = 0;
      if (len != 0) {
        puVar17 = in;
        uVar18 = len;
        do {
          iVar6 = UTF8_getc(puVar17,uVar18,&local_50);
          if (iVar6 < 0) {
            uVar10 = 0x86;
            uVar8 = 0x84;
            goto LAB_0060a17c;
          }
          uVar18 = uVar18 - iVar6;
          puVar17 = puVar17 + iVar6;
          local_6c = local_6c + 1;
        } while (uVar18 != 0);
      }
    }
    else if (inform == 0x1002) {
      local_6c = len >> 1;
      if ((len & 1U) != 0) {
        uVar10 = 0x81;
        uVar8 = 0x6f;
        goto LAB_0060a17c;
      }
    }
    else {
      if (inform != 0x1004) goto LAB_0060a16c;
      local_6c = len >> 2;
      if ((len & 3U) != 0) {
        uVar10 = 0x85;
        uVar8 = 0x78;
        goto LAB_0060a17c;
      }
    }
  }
  if ((0 < minsize) && ((int)local_6c < minsize)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7a,0x98,"a_mbstr.c",0x93);
    (*(code *)PTR_BIO_snprintf_006a8060)(auStack_4c,0x20,&DAT_0066fa48,minsize);
    iVar6 = -1;
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"minsize=",auStack_4c);
    goto LAB_00609fb0;
  }
  if ((0 < maxsize) && (maxsize < (int)local_6c)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7a,0x97,"a_mbstr.c",0x9a);
    (*(code *)PTR_BIO_snprintf_006a8060)(auStack_4c,0x20,&DAT_0066fa48,maxsize);
    iVar6 = -1;
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"maxsize=",auStack_4c);
    goto LAB_00609fb0;
  }
  if (len != 0) {
    str = (uint *)in;
    uVar18 = len;
    do {
      if (inform == 0x1001) {
        local_50 = (uint)*(byte *)str;
        uVar18 = uVar18 - 1;
        str = (uint *)((int)str + 1);
      }
      else if (inform == 0x1002) {
        uVar18 = uVar18 - 2;
        uVar1 = *(ushort *)str;
        str = (uint *)((int)str + 2);
        local_50 = (uint)uVar1;
      }
      else if (inform == 0x1004) {
        local_50 = *str;
        uVar18 = uVar18 - 4;
        str = str + 1;
      }
      else {
        iVar6 = UTF8_getc((uchar *)str,uVar18,&local_50);
        if (iVar6 < 0) goto LAB_0060a3d0;
        uVar18 = uVar18 - iVar6;
        str = (uint *)((int)str + iVar6);
      }
      uVar5 = local_50;
      uVar11 = mask;
      if ((mask & 2) == 0) {
LAB_0060a024:
        if (((mask & 0x10) != 0) && (0x7f < uVar5)) {
          uVar11 = uVar11 & 0xffffffef;
        }
LAB_00609e38:
        mask = uVar11;
        if (((uVar11 & 4) != 0) && (0xff < uVar5)) {
          mask = uVar11 & 0xfffffffb;
        }
      }
      else {
        if (0x7f < local_50) {
LAB_0060a018:
          uVar11 = mask & 0xfffffffd;
          goto LAB_0060a024;
        }
        if (((local_50 & 0xffffffdf) - 0x41 < 0x1a) || (local_50 - 0x30 < 10)) goto LAB_00609e38;
        if (local_50 != 0x20) {
          iVar6 = (*(code *)PTR_strchr_006aab34)("\'()+,-./:=?",local_50);
          if (iVar6 == 0) goto LAB_0060a018;
          goto LAB_00609e38;
        }
      }
      if ((mask & 0x800) == 0) {
LAB_00609e6c:
        if (mask == 0) {
LAB_0060a3d0:
          uVar10 = 0x7c;
          uVar8 = 0xa2;
          goto LAB_0060a17c;
        }
      }
      else if (0xffff < uVar5) {
        mask = mask & 0xfffff7ff;
        goto LAB_00609e6c;
      }
    } while (uVar18 != 0);
  }
  puVar3 = PTR_CRYPTO_free_006a7f88;
  if ((mask & 2) == 0) {
    uVar18 = 0x1001;
    if ((mask & 0x10) == 0) {
      if ((mask & 4) == 0) {
        if ((mask & 0x800) == 0) {
          uVar18 = 0x1004;
          if ((mask & 0x100) == 0) {
            uVar18 = 0x1000;
          }
          iVar6 = 0xc;
          if ((mask & 0x100) != 0) {
            iVar6 = 0x1c;
          }
        }
        else {
          uVar18 = 0x1002;
          iVar6 = 0x1e;
        }
      }
      else {
        iVar6 = 0x14;
      }
    }
    else {
      iVar6 = 0x16;
    }
  }
  else {
    uVar18 = 0x1001;
    iVar6 = 0x13;
  }
  if (out == (ASN1_STRING **)0x0) goto LAB_00609fb0;
  pAVar16 = *out;
  if (pAVar16 == (ASN1_STRING *)0x0) {
    pAVar16 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(iVar6);
    if (pAVar16 == (ASN1_STRING *)0x0) goto LAB_0060a648;
    bVar2 = true;
    *out = pAVar16;
  }
  else {
    if (pAVar16->data != (uchar *)0x0) {
      pAVar16->length = 0;
      (*(code *)puVar3)();
      pAVar16->data = (uchar *)0x0;
    }
    pAVar16->type = iVar6;
    bVar2 = false;
  }
  if (uVar18 == inform) {
    iVar9 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(pAVar16,in,len);
    if (iVar9 == 0) {
      uVar10 = 0x41;
      uVar8 = 0xcd;
      goto LAB_0060a17c;
    }
    goto LAB_00609fb0;
  }
  if (uVar18 == 0x1001) {
    pcVar12 = cpy_asc;
    iVar9 = local_6c + 1;
  }
  else if (uVar18 < 0x1002) {
    iVar9 = 1;
    if (uVar18 == 0x1000) {
      local_6c = 0;
      if (len == 0) {
        pcVar12 = cpy_utf8;
      }
      else {
        pbVar14 = in;
        uVar18 = len;
        if (inform == 0x1001) {
          do {
            local_50 = (uint)*pbVar14;
            uVar18 = uVar18 - 1;
            iVar9 = UTF8_putc((uchar *)0x0,-1,local_50);
            local_6c = local_6c + iVar9;
            pbVar14 = pbVar14 + 1;
          } while (uVar18 != 0);
          iVar9 = local_6c + 1;
        }
        else {
          puVar15 = (ushort *)in;
          if (inform == 0x1002) {
            do {
              uVar18 = uVar18 - 2;
              local_50 = (uint)*puVar15;
              iVar9 = UTF8_putc((uchar *)0x0,-1,local_50);
              local_6c = local_6c + iVar9;
              puVar15 = puVar15 + 1;
            } while (uVar18 != 0);
            iVar9 = local_6c + 1;
          }
          else {
            puVar17 = in;
            puVar13 = (ulong *)in;
            if (inform == 0x1004) {
              do {
                local_50 = *puVar13;
                uVar18 = uVar18 - 4;
                iVar9 = UTF8_putc((uchar *)0x0,-1,local_50);
                local_6c = local_6c + iVar9;
                puVar13 = puVar13 + 1;
              } while (uVar18 != 0);
              iVar9 = local_6c + 1;
            }
            else {
              do {
                iVar9 = UTF8_getc(puVar17,uVar18,&local_50);
                if (iVar9 < 0) break;
                uVar18 = uVar18 - iVar9;
                iVar7 = UTF8_putc((uchar *)0x0,-1,local_50);
                local_6c = local_6c + iVar7;
                puVar17 = puVar17 + iVar9;
              } while (uVar18 != 0);
              iVar9 = local_6c + 1;
            }
          }
        }
        pcVar12 = cpy_utf8;
      }
    }
    else {
LAB_0060a2dc:
      iVar9 = 1;
      local_6c = 0;
      pcVar12 = (code *)0x0;
    }
  }
  else if (uVar18 == 0x1002) {
    pcVar12 = cpy_bmp;
    local_6c = local_6c * 2;
    iVar9 = local_6c + 1;
  }
  else {
    if (uVar18 != 0x1004) goto LAB_0060a2dc;
    pcVar12 = cpy_univ;
    local_6c = local_6c * 4;
    iVar9 = local_6c + 1;
  }
  local_54 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9,"a_mbstr.c",0xea);
  if (local_54 == (uchar *)0x0) {
    if (bVar2) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar16);
    }
    iVar6 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7a,0x41,"a_mbstr.c",0xec);
  }
  else {
    pAVar16->length = local_6c;
    pAVar16->data = local_54;
    local_54[local_6c] = '\0';
    if (len != 0) {
      if (inform == 0x1001) {
        if (pcVar12 != (code *)0x0) {
          do {
            local_50 = (uint)*in;
            len = len - 1;
            iVar9 = (*pcVar12)(local_50,&local_54);
            if (iVar9 < 1) break;
            in = in + 1;
          } while (len != 0);
        }
      }
      else if (pcVar12 == (code *)0x0) {
        if ((inform != 0x1004) && (inform != 0x1002)) {
          do {
            iVar9 = UTF8_getc(in,len,&local_50);
            if (iVar9 < 0) break;
            len = len - iVar9;
            in = in + iVar9;
          } while (len != 0);
        }
      }
      else if (inform == 0x1002) {
        do {
          uVar1 = *(ushort *)in;
          len = len - 2;
          in = (uchar *)((int)in + 2);
          local_50 = (uint)uVar1;
          iVar9 = (*pcVar12)(local_50,&local_54);
          if (iVar9 < 1) break;
        } while (len != 0);
      }
      else if (inform == 0x1004) {
        do {
          local_50 = *(uint *)in;
          len = len - 4;
          in = (uchar *)((int)in + 4);
          iVar9 = (*pcVar12)(local_50,&local_54);
          if (iVar9 < 1) break;
        } while (len != 0);
      }
      else {
        while (iVar9 = UTF8_getc(in,len,&local_50), -1 < iVar9) {
          len = len - iVar9;
          in = in + iVar9;
          iVar9 = (*pcVar12)(local_50,&local_54);
          if ((iVar9 < 1) || (len == 0)) break;
        }
      }
    }
  }
LAB_00609fb0:
  while (local_2c != *(int *)puVar4) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0060a648:
    uVar10 = 0x41;
    uVar8 = 0xc5;
LAB_0060a17c:
    iVar6 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7a,uVar10,"a_mbstr.c",uVar8);
  }
  return iVar6;
}

