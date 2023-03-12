
/* WARNING: Could not reconcile some variable overlaps */

int asn1_d2i_ex_primitive
              (ASN1_VALUE **param_1,uchar **param_2,int param_3,ASN1_ITEM *param_4,uchar *param_5,
              int param_6,char param_7,char *param_8)

{
  uint uVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  uchar *omax;
  uchar *puVar5;
  bool bVar6;
  char local_50 [4];
  uchar *local_4c;
  uchar *local_48;
  uchar *local_44;
  int local_40;
  uchar *local_3c;
  BUF_MEM local_38;
  
  local_50[0] = '\0';
  if (param_1 == (ASN1_VALUE **)0x0) {
    ERR_put_error(0xd,0x6c,0x7d,"tasn_dec.c",0x2d4);
    return 0;
  }
  if (param_4->itype == '\x05') {
    local_4c = param_5;
    if (param_5 == (uchar *)0xfffffffc) {
      param_5 = (uchar *)0xffffffff;
      goto LAB_000baf5c;
    }
LAB_000baf52:
    param_6 = 0;
    param_5 = local_4c;
  }
  else {
    local_4c = (uchar *)param_4->utype;
    if (local_4c == (uchar *)0xfffffffc) {
      if (-1 < (int)param_5) {
        ERR_put_error(0xd,0x6c,0x7f,"tasn_dec.c",0x2e2);
        return 0;
      }
LAB_000baf5c:
      if (param_7 != '\0') {
        ERR_put_error(0xd,0x6c,0x7e,"tasn_dec.c",0x2e7);
        return 0;
      }
      local_48 = *param_2;
      iVar2 = asn1_check_tlen_constprop_1(0,&local_4c,&local_38,0,0,&local_48,param_3,0,param_8);
      if (iVar2 == 0) {
        ERR_put_error(0xd,0x6c,0x3a,"tasn_dec.c",0x2ee);
        return 0;
      }
      if ((char)local_38.length != '\0') {
        local_4c = (uchar *)0xfffffffd;
      }
    }
    if (param_5 == (uchar *)0xffffffff) goto LAB_000baf52;
  }
  puVar5 = *param_2;
  local_48 = puVar5;
  local_38.length = (size_t)puVar5;
  if (param_8 == (char *)0x0) {
    uVar1 = ASN1_get_object((uchar **)&local_38,(long *)&local_3c,(int *)&local_44,&local_40,param_3
                           );
  }
  else if (*param_8 == '\0') {
    uVar1 = ASN1_get_object((uchar **)&local_38,(long *)&local_3c,(int *)&local_44,&local_40,param_3
                           );
    *(int *)(param_8 + 0x10) = local_40;
    *param_8 = '\x01';
    *(uchar **)(param_8 + 8) = local_3c;
    *(size_t *)(param_8 + 0x14) = local_38.length - (int)puVar5;
    *(uchar **)(param_8 + 0xc) = local_44;
    *(uint *)(param_8 + 4) = uVar1;
    if (((uVar1 & 0x81) == 0) && (param_3 < (int)(local_3c + (local_38.length - (int)puVar5)))) {
      ERR_put_error(0xd,0x68,0x9b,"tasn_dec.c",0x49b);
      *param_8 = '\0';
      goto LAB_000baeaa;
    }
  }
  else {
    local_3c = *(uchar **)(param_8 + 8);
    local_40 = *(int *)(param_8 + 0x10);
    local_44 = *(uchar **)(param_8 + 0xc);
    uVar1 = *(uint *)(param_8 + 4);
    local_38.length = (size_t)(puVar5 + *(int *)(param_8 + 0x14));
  }
  if ((uVar1 & 0x80) != 0) {
    ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
    if (param_8 != (char *)0x0) {
      *param_8 = '\0';
    }
LAB_000baeaa:
    ERR_put_error(0xd,0x6c,0x3a,"tasn_dec.c",0x2fd);
    return 0;
  }
  if (-1 < (int)param_5) {
    if ((param_5 != local_44) || (param_6 != local_40)) {
      if (param_7 != '\0') {
        return -1;
      }
      if (param_8 != (char *)0x0) {
        *param_8 = '\0';
      }
      ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x4af);
      goto LAB_000baeaa;
    }
    if (param_8 != (char *)0x0) {
      *param_8 = '\0';
    }
  }
  bVar6 = (int)(uVar1 << 0x1f) < 0;
  if (bVar6) {
    param_5 = (uchar *)local_38.length;
  }
  if (!bVar6) {
    param_5 = (uchar *)local_38.length;
  }
  omax = local_3c;
  if (bVar6) {
    omax = puVar5 + (param_3 - (int)param_5);
  }
  puVar5 = (uchar *)(uint)(local_4c == (uchar *)0xfffffffd);
  if (local_4c + -0x10 < (uchar *)0x2) {
    puVar5 = (uchar *)0x1;
  }
  puVar3 = (uchar *)(uVar1 & 1);
  local_48 = param_5;
  if (puVar5 == (uchar *)0x0) {
    if ((uVar1 & 0x20) == 0) {
      local_48 = param_5 + (int)omax;
    }
    else {
      if ((((uint)local_4c & 0xfffffffb) - 1 < 2) || (local_4c == (uchar *)0xa)) {
        ERR_put_error(0xd,0x6c,0xda,"tasn_dec.c",0x322);
        return 0;
      }
      local_38.length = (size_t)puVar5;
      local_38.data = (char *)puVar5;
      local_38.max = (size_t)puVar5;
      iVar2 = asn1_collect_constprop_0(&local_38,&local_48,omax,puVar3,0);
      omax = (uchar *)local_38.length;
      if (iVar2 == 0) {
        local_50[0] = '\x01';
        goto LAB_000bb016;
      }
      iVar2 = BUF_MEM_grow_clean(&local_38,(size_t)(local_38.length + 1));
      if (iVar2 == 0) {
        ERR_put_error(0xd,0x6c,0x41,"tasn_dec.c",0x335);
        return 0;
      }
      local_38.data[(int)omax] = '\0';
      local_50[0] = '\x01';
      param_5 = (uchar *)local_38.data;
    }
LAB_000baff2:
    iVar2 = asn1_ex_c2i(param_1,param_5,(int)omax,(int)local_4c,local_50,param_4);
    if (iVar2 != 0) {
      iVar2 = 1;
      *param_2 = local_48;
    }
  }
  else {
    if ((uchar *)(uint)(local_4c == (uchar *)0xfffffffd) == (uchar *)0x0) {
      if ((uVar1 & 0x20) == 0) {
        ERR_put_error(0xd,0x6c,0x9c,"tasn_dec.c",0x30f);
        return 0;
      }
    }
    else if (param_8 != (char *)0x0) {
      *param_8 = '\0';
    }
    puVar5 = *param_2;
    if (puVar3 == (uchar *)0x0) {
      local_48 = param_5 + (int)omax;
      omax = omax + ((int)param_5 - (int)puVar5);
      param_5 = puVar5;
      local_38.data = (char *)puVar3;
      goto LAB_000baff2;
    }
    if (0 < (int)omax) {
      iVar2 = 1;
      do {
        if (((omax == (uchar *)0x1) || (*param_5 != '\0')) || (param_5[1] != '\0')) {
          local_38.length = (size_t)param_5;
          uVar1 = ASN1_get_object((uchar **)&local_38,(long *)&local_3c,(int *)&local_44,&local_40,
                                  (long)omax);
          if ((int)(uVar1 << 0x18) < 0) {
            ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
            ERR_put_error(0xd,0xbe,0x3a,"tasn_dec.c",0x3fc);
            goto LAB_000bb0fa;
          }
          if ((uVar1 & 1) == 0) {
            puVar3 = (uchar *)(local_38.length + (int)local_3c);
          }
          else {
            iVar2 = iVar2 + 1;
            puVar3 = (uchar *)local_38.length;
          }
          iVar4 = (int)param_5 - (int)puVar3;
        }
        else {
          iVar2 = iVar2 + -1;
          puVar3 = param_5 + 2;
          if (iVar2 == 0) {
            omax = puVar3 + -(int)puVar5;
            param_5 = puVar5;
            local_48 = puVar3;
            goto LAB_000baff2;
          }
          iVar4 = -2;
        }
        omax = omax + iVar4;
        param_5 = puVar3;
      } while (0 < (int)omax);
    }
    ERR_put_error(0xd,0xbe,0x89,"tasn_dec.c",0x406);
LAB_000bb0fa:
    iVar2 = 0;
  }
  if (local_50[0] == '\0') {
    return iVar2;
  }
LAB_000bb016:
  if ((uchar *)local_38.data == (uchar *)0x0) {
    return iVar2;
  }
  CRYPTO_free(local_38.data);
  return iVar2;
}

