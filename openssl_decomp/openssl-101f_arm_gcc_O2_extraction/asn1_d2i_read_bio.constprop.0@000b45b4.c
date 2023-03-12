
uchar * asn1_d2i_read_bio_constprop_0(BIO *param_1,BUF_MEM **param_2)

{
  BUF_MEM *str;
  int iVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  uchar *puVar5;
  uint uVar6;
  uchar *puVar7;
  uint omax;
  uchar *puVar8;
  int iVar9;
  char *pcVar10;
  bool bVar11;
  uchar *local_54 [3];
  int local_48;
  int local_44;
  int iStack_40;
  uint local_3c [6];
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
    puVar8 = (uchar *)0xffffffff;
  }
  else {
    ERR_clear_error();
    puVar7 = (uchar *)0x0;
    puVar8 = (uchar *)0x0;
    iVar9 = 0;
LAB_000b45d4:
    omax = (int)puVar7 - (int)puVar8;
    if (omax < 9) {
      puVar5 = puVar8 + 8;
      if ((puVar5 < puVar7) || (iVar1 = BUF_MEM_grow_clean(str,(size_t)puVar5), iVar1 == 0)) {
        iVar9 = 0xa9;
LAB_000b46f4:
        ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",iVar9);
        goto LAB_000b46ba;
      }
      uVar2 = BIO_read(param_1,str->data + (int)puVar7,(int)puVar5 - (int)puVar7);
      uVar6 = count_leading_zeroes((int)puVar7 - (int)puVar8);
      if ((uVar6 >> 5 & uVar2 >> 0x1f) != 0) {
        iVar9 = 0xaf;
LAB_000b46aa:
        ERR_put_error(0xd,0x6b,0x8e,"a_d2i_fp.c",iVar9);
        goto LAB_000b46ba;
      }
      if (0 < (int)uVar2) {
        bVar11 = CARRY4(uVar2,(uint)puVar7);
        puVar7 = puVar7 + uVar2;
        if (bVar11 == false) {
          omax = (int)puVar7 - (int)puVar8;
          goto LAB_000b4616;
        }
        iVar9 = 0xb6;
        goto LAB_000b4714;
      }
    }
LAB_000b4616:
    pcVar10 = str->data;
    local_54[0] = (uchar *)(pcVar10 + (int)puVar8);
    local_48 = ASN1_get_object(local_54,(long *)local_3c,&local_44,&iStack_40,omax);
    if (local_48 << 0x18 < 0) {
      uVar4 = ERR_peek_error();
      if ((uVar4 & 0xfff) != 0x9b) goto LAB_000b46ba;
      ERR_clear_error();
    }
    puVar8 = local_54[0] + ((int)puVar8 - (int)(pcVar10 + (int)puVar8));
    if (local_48 << 0x1f < 0) {
      iVar9 = iVar9 + 1;
      goto LAB_000b45d4;
    }
    if ((iVar9 != 0) && (local_3c[0] == 0)) {
      if ((local_44 == 0) && (iVar9 = iVar9 + -1, iVar9 == 0)) goto LAB_000b465a;
      goto LAB_000b45d4;
    }
    if ((uint)((int)puVar7 - (int)puVar8) < local_3c[0]) {
      puVar5 = puVar8 + local_3c[0];
      iVar1 = (int)puVar5 - (int)puVar7;
      if ((iVar1 < 0) || (puVar5 < puVar7)) {
        iVar9 = 0xed;
        goto LAB_000b4714;
      }
      iVar3 = BUF_MEM_grow_clean(str,(size_t)puVar5);
      if (iVar3 == 0) {
        iVar9 = 0xf2;
        goto LAB_000b46f4;
      }
      for (; iVar1 != 0; iVar1 = iVar1 - iVar3) {
        iVar3 = BIO_read(param_1,str->data + (int)puVar7,iVar1);
        puVar7 = puVar7 + iVar3;
        if (iVar3 < 1) {
          iVar9 = 0xfb;
          goto LAB_000b46aa;
        }
      }
    }
    bVar11 = CARRY4(local_3c[0],(uint)puVar8);
    puVar8 = puVar8 + local_3c[0];
    if (bVar11 != false) {
      iVar9 = 0x106;
      goto LAB_000b4714;
    }
    if (iVar9 != 0) goto LAB_000b45d4;
LAB_000b465a:
    if ((int)puVar8 < 0) {
      iVar9 = 0x115;
LAB_000b4714:
      ERR_put_error(0xd,0x6b,0x9b,"a_d2i_fp.c",iVar9);
LAB_000b46ba:
      BUF_MEM_free(str);
      puVar8 = (uchar *)0xffffffff;
    }
    else {
      *param_2 = str;
    }
  }
  return puVar8;
}

