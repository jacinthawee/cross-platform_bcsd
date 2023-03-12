
/* WARNING: Could not reconcile some variable overlaps */

int asn1_d2i_ex_primitive
              (ASN1_VALUE **param_1,uchar **param_2,int param_3,ASN1_ITEM *param_4,int param_5,
              int param_6,char param_7,char *param_8)

{
  uint uVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  uchar *omax;
  uchar *puVar5;
  uchar *puVar6;
  char local_50 [4];
  int local_4c;
  uchar *local_48;
  int local_44;
  int local_40;
  uchar *local_3c;
  BUF_MEM local_38;
  
  local_50[0] = '\0';
  if (param_1 == (ASN1_VALUE **)0x0) {
    ERR_put_error(0xd,0x6c,0x7d,"tasn_dec.c",0x30c);
    return 0;
  }
  if (param_4->itype == '\x05') {
    local_4c = param_5;
    if (param_5 == -4) {
      param_5 = -1;
      goto LAB_000bd814;
    }
LAB_000bd80a:
    param_6 = 0;
    param_5 = local_4c;
  }
  else {
    local_4c = param_4->utype;
    if (local_4c == -4) {
      if (-1 < param_5) {
        ERR_put_error(0xd,0x6c,0x7f,"tasn_dec.c",799);
        return 0;
      }
LAB_000bd814:
      if (param_7 != '\0') {
        ERR_put_error(0xd,0x6c,0x7e,"tasn_dec.c",0x325);
        return 0;
      }
      local_48 = *param_2;
      iVar3 = asn1_check_tlen_constprop_1(0,&local_4c,&local_38,0,0,&local_48,param_3,0,param_8);
      if (iVar3 == 0) {
        ERR_put_error(0xd,0x6c,0x3a,"tasn_dec.c",0x32e);
        return 0;
      }
      if ((char)local_38.length != '\0') {
        local_4c = -3;
      }
    }
    if (param_5 == -1) goto LAB_000bd80a;
  }
  puVar6 = *param_2;
  local_48 = puVar6;
  local_38.length = (size_t)puVar6;
  if (param_8 == (char *)0x0) {
    uVar1 = ASN1_get_object((uchar **)&local_38,(long *)&local_3c,&local_44,&local_40,param_3);
  }
  else if (*param_8 == '\0') {
    uVar1 = ASN1_get_object((uchar **)&local_38,(long *)&local_3c,&local_44,&local_40,param_3);
    *(int *)(param_8 + 0x10) = local_40;
    *param_8 = '\x01';
    *(uchar **)(param_8 + 8) = local_3c;
    *(size_t *)(param_8 + 0x14) = local_38.length - (int)puVar6;
    *(int *)(param_8 + 0xc) = local_44;
    *(uint *)(param_8 + 4) = uVar1;
    if (((uVar1 & 0x81) == 0) && (param_3 < (int)(local_3c + (local_38.length - (int)puVar6)))) {
      ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x511);
      *param_8 = '\0';
      goto LAB_000bd762;
    }
  }
  else {
    local_3c = *(uchar **)(param_8 + 8);
    local_40 = *(int *)(param_8 + 0x10);
    local_44 = *(int *)(param_8 + 0xc);
    uVar1 = *(uint *)(param_8 + 4);
    local_38.length = (size_t)(puVar6 + *(int *)(param_8 + 0x14));
  }
  if ((uVar1 & 0x80) != 0) {
    ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
    if (param_8 != (char *)0x0) {
      *param_8 = '\0';
    }
LAB_000bd762:
    ERR_put_error(0xd,0x6c,0x3a,"tasn_dec.c",0x33f);
    return 0;
  }
  if (-1 < param_5) {
    if ((param_5 != local_44) || (param_6 != local_40)) {
      if (param_7 != '\0') {
        return -1;
      }
      if (param_8 != (char *)0x0) {
        *param_8 = '\0';
      }
      ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x527);
      goto LAB_000bd762;
    }
    if (param_8 != (char *)0x0) {
      *param_8 = '\0';
    }
  }
  puVar2 = (uchar *)(uVar1 & 1);
  omax = local_3c;
  if ((int)(uVar1 << 0x1f) < 0) {
    omax = puVar6 + (param_3 - local_38.length);
  }
  local_48 = (uchar *)local_38.length;
  puVar6 = (uchar *)(uint)(local_4c == -3);
  if (local_4c - 0x10U < 2) {
    puVar6 = (uchar *)0x1;
  }
  if (puVar6 == (uchar *)0x0) {
    if ((uVar1 & 0x20) == 0) {
      local_48 = (uchar *)(local_38.length + (int)omax);
      puVar6 = (uchar *)local_38.length;
    }
    else {
      local_38.length = (size_t)puVar6;
      local_38.data = (char *)puVar6;
      local_38.max = (size_t)puVar6;
      iVar3 = asn1_collect_constprop_0(&local_38,&local_48,omax,puVar2,0);
      omax = (uchar *)local_38.length;
      if (iVar3 == 0) {
        local_50[0] = '\x01';
        goto LAB_000bd8d6;
      }
      iVar3 = BUF_MEM_grow_clean(&local_38,(size_t)(local_38.length + 1));
      if (iVar3 == 0) {
        ERR_put_error(0xd,0x6c,0x41,"tasn_dec.c",0x37c);
        return 0;
      }
      local_38.data[(int)omax] = '\0';
      local_50[0] = '\x01';
      puVar6 = (uchar *)local_38.data;
    }
LAB_000bd8b0:
    iVar3 = asn1_ex_c2i(param_1,puVar6,(int)omax,local_4c,local_50,param_4);
    if (iVar3 != 0) {
      iVar3 = 1;
      *param_2 = local_48;
    }
  }
  else {
    if ((uchar *)(uint)(local_4c == -3) == (uchar *)0x0) {
      if ((uVar1 & 0x20) == 0) {
        ERR_put_error(0xd,0x6c,0x9c,"tasn_dec.c",0x354);
        return 0;
      }
    }
    else if (param_8 != (char *)0x0) {
      *param_8 = '\0';
    }
    puVar6 = *param_2;
    if (puVar2 == (uchar *)0x0) {
      local_48 = (uchar *)(local_38.length + (int)omax);
      omax = omax + (local_38.length - (int)puVar6);
      local_38.data = (char *)puVar2;
      goto LAB_000bd8b0;
    }
    if (0 < (int)omax) {
      iVar3 = 1;
      puVar2 = (uchar *)local_38.length;
      do {
        if (((omax == (uchar *)0x1) || (*puVar2 != '\0')) || (puVar2[1] != '\0')) {
          local_38.length = (size_t)puVar2;
          uVar1 = ASN1_get_object((uchar **)&local_38,(long *)&local_3c,&local_44,&local_40,
                                  (long)omax);
          if ((int)(uVar1 << 0x18) < 0) {
            ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
            ERR_put_error(0xd,0xbe,0x3a,"tasn_dec.c",0x461);
            goto LAB_000bd98e;
          }
          if ((uVar1 & 1) == 0) {
            puVar5 = (uchar *)(local_38.length + (int)local_3c);
          }
          else {
            iVar3 = iVar3 + 1;
            puVar5 = (uchar *)local_38.length;
          }
          iVar4 = (int)puVar2 - (int)puVar5;
        }
        else {
          iVar3 = iVar3 + -1;
          puVar5 = puVar2 + 2;
          if (iVar3 == 0) {
            omax = puVar5 + -(int)puVar6;
            local_48 = puVar5;
            goto LAB_000bd8b0;
          }
          iVar4 = -2;
        }
        omax = omax + iVar4;
        puVar2 = puVar5;
      } while (0 < (int)omax);
    }
    ERR_put_error(0xd,0xbe,0x89,"tasn_dec.c",0x46c);
LAB_000bd98e:
    iVar3 = 0;
  }
  if (local_50[0] == '\0') {
    return iVar3;
  }
LAB_000bd8d6:
  if ((uchar *)local_38.data == (uchar *)0x0) {
    return iVar3;
  }
  CRYPTO_free(local_38.data);
  return iVar3;
}

