
uchar * asn1_d2i_read_bio_constprop_0(BIO *param_1,BUF_MEM **param_2)

{
  BUF_MEM *str;
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uchar *puVar4;
  uint uVar5;
  uchar *puVar6;
  int iVar7;
  uint uVar8;
  uint len;
  uchar *puVar9;
  char *pcVar10;
  bool bVar11;
  uchar *local_54 [3];
  int local_48;
  int local_44;
  int iStack_40;
  uint local_3c [6];
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9e);
    puVar4 = (uchar *)0xffffffff;
  }
  else {
    ERR_clear_error();
    puVar9 = (uchar *)0x0;
    iVar7 = 0;
    puVar6 = (uchar *)0x0;
LAB_000b1a32:
    uVar8 = (int)puVar9 - (int)puVar6;
    if (uVar8 < 9) {
      puVar4 = puVar6 + 8;
      if ((puVar4 < puVar9) || (iVar1 = BUF_MEM_grow_clean(str,(size_t)puVar4), iVar1 == 0)) {
        iVar7 = 0xa8;
LAB_000b1b8c:
        ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",iVar7);
        goto LAB_000b1b5a;
      }
      uVar2 = BIO_read(param_1,str->data + (int)puVar9,(int)puVar4 - (int)puVar9);
      uVar5 = count_leading_zeroes((int)puVar9 - (int)puVar6);
      if ((uVar5 >> 5 & uVar2 >> 0x1f) != 0) {
        iVar7 = 0xad;
LAB_000b1b4a:
        ERR_put_error(0xd,0x6b,0x8e,"a_d2i_fp.c",iVar7);
        goto LAB_000b1b5a;
      }
      if (0 < (int)uVar2) {
        bVar11 = CARRY4(uVar2,(uint)puVar9);
        puVar9 = puVar9 + uVar2;
        if (bVar11 != false) {
          iVar7 = 0xb2;
          goto LAB_000b1bb4;
        }
        uVar8 = (int)puVar9 - (int)puVar6;
      }
    }
    pcVar10 = str->data;
    local_54[0] = (uchar *)(pcVar10 + (int)puVar6);
    local_48 = ASN1_get_object(local_54,(long *)local_3c,&local_44,&iStack_40,uVar8);
    if (local_48 << 0x18 < 0) {
      uVar3 = ERR_peek_error();
      if ((uVar3 & 0xfff) != 0x9b) goto LAB_000b1b5a;
      ERR_clear_error();
    }
    puVar4 = local_54[0] + ((int)puVar6 - (int)(pcVar10 + (int)puVar6));
    puVar6 = puVar4;
    if (local_48 << 0x1f < 0) {
      iVar7 = iVar7 + 1;
      goto LAB_000b1a32;
    }
    if ((iVar7 != 0) && (local_3c[0] == 0)) {
      if ((local_44 == 0) && (iVar7 = iVar7 + -1, iVar7 == 0)) goto LAB_000b1b7a;
      goto LAB_000b1a32;
    }
    puVar6 = puVar4 + local_3c[0];
    if ((uint)((int)puVar9 - (int)puVar4) < local_3c[0]) {
      uVar8 = (int)puVar6 - (int)puVar9;
      if (((int)uVar8 < 0) || (puVar6 < puVar9)) {
        iVar7 = 0xe2;
        goto LAB_000b1bb4;
      }
      if (uVar8 != 0) {
        uVar2 = 0x4000;
        do {
          uVar5 = uVar2;
          if (uVar8 <= uVar2) {
            uVar5 = uVar8;
          }
          iVar1 = BUF_MEM_grow_clean(str,(size_t)(puVar9 + uVar5));
          len = uVar5;
          if (iVar1 == 0) {
            iVar7 = 0xef;
            goto LAB_000b1b8c;
          }
          do {
            iVar1 = BIO_read(param_1,str->data + (int)puVar9,len);
            puVar9 = puVar9 + iVar1;
            if (iVar1 < 1) {
              iVar7 = 0xf7;
              goto LAB_000b1b4a;
            }
            len = len - iVar1;
          } while (len != 0);
          if (uVar2 < 0x3fffffff) {
            uVar2 = uVar2 << 1;
          }
          uVar8 = uVar8 - uVar5;
        } while (uVar8 != 0);
        puVar6 = puVar4 + local_3c[0];
      }
    }
    if (puVar6 < puVar4) {
      iVar7 = 0x106;
      goto LAB_000b1bb4;
    }
    puVar4 = puVar6;
    if (iVar7 != 0) goto LAB_000b1a32;
LAB_000b1b7a:
    if ((int)puVar4 < 0) {
      iVar7 = 0x112;
LAB_000b1bb4:
      ERR_put_error(0xd,0x6b,0x9b,"a_d2i_fp.c",iVar7);
LAB_000b1b5a:
      BUF_MEM_free(str);
      puVar4 = (uchar *)0xffffffff;
    }
    else {
      *param_2 = str;
    }
  }
  return puVar4;
}

