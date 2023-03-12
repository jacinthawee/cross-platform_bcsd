
undefined4 __regparm3 str_copy(CONF *param_1_00,char *param_2,char **param_3,byte *param_1)

{
  byte *name;
  byte bVar1;
  char cVar2;
  byte bVar3;
  BUF_MEM *str;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  char *__s;
  byte *pbVar7;
  ushort uVar8;
  uint uVar9;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  byte *local_3c;
  byte *local_38;
  byte *local_30;
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    return 0;
  }
  sVar4 = strlen((char *)param_1);
  iVar5 = BUF_MEM_grow(str,sVar4 + 1);
  if (iVar5 == 0) {
LAB_08179a90:
    BUF_MEM_free(str);
    return 0;
  }
  pvVar10 = param_1_00->meth_data;
  iVar5 = 0;
  uVar9 = (uint)*param_1;
  uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
LAB_08179978:
  do {
    while (cVar2 = (char)uVar9, (uVar8 & 0x40) != 0) {
      bVar3 = param_1[1];
      while( true ) {
        pbVar7 = param_1 + 1;
        uVar9 = (uint)(char)bVar3;
        uVar8 = *(ushort *)((int)pvVar10 + (uVar9 & 0xff) * 2);
        uVar11 = uVar9;
        uVar6 = uVar9 & 0xff;
        if ((uVar8 & 8) != 0) break;
        if ((int)cVar2 == uVar9) goto LAB_08179be8;
        if ((uVar8 & 0x20) != 0) {
          pbVar7 = param_1 + 2;
          bVar3 = param_1[2];
          uVar9 = (uint)bVar3;
          if ((*(byte *)((int)pvVar10 + uVar9 * 2) & 8) != 0) {
            uVar11 = (uint)(char)bVar3;
            uVar6 = uVar9;
            break;
          }
        }
        str->data[iVar5] = bVar3;
        bVar3 = pbVar7[1];
        pvVar10 = param_1_00->meth_data;
        iVar5 = iVar5 + 1;
        param_1 = pbVar7;
      }
      local_3c = (byte *)(uVar6 * 2);
      if ((int)cVar2 == uVar11) {
LAB_08179be8:
        uVar9 = (uint)pbVar7[1];
        uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
        param_1 = pbVar7 + 1;
      }
      else {
        uVar8 = *(ushort *)((int)pvVar10 + (int)local_3c);
        param_1 = pbVar7;
      }
    }
    if ((uVar8 & 0x400) == 0) {
      if ((uVar8 & 0x20) == 0) {
        if ((uVar8 & 8) != 0) goto LAB_08179d18;
        if (cVar2 == '$') {
          bVar3 = param_1[1];
          if (bVar3 == 0x7b) {
            bVar1 = 0x7d;
LAB_08179c62:
            local_38 = param_1 + 2;
            bVar3 = param_1[2];
          }
          else {
            if (bVar3 == 0x28) {
              bVar1 = 0x29;
              goto LAB_08179c62;
            }
            local_38 = param_1 + 1;
            bVar1 = 0;
          }
          uVar8 = *(ushort *)((int)pvVar10 + (uint)bVar3 * 2);
          pbVar7 = local_38;
          while ((uVar8 & 0x107) != 0) {
            pbVar7 = pbVar7 + 1;
            bVar3 = *pbVar7;
            uVar8 = *(ushort *)((int)pvVar10 + (uint)bVar3 * 2);
          }
          if ((bVar3 == 0x3a) && (pbVar7[1] == 0x3a)) {
            *pbVar7 = 0;
            name = pbVar7 + 2;
            bVar3 = pbVar7[2];
            uVar8 = *(ushort *)((int)param_1_00->meth_data + (uint)bVar3 * 2);
            local_3c = name;
            while ((uVar8 & 0x107) != 0) {
              local_3c = local_3c + 1;
              bVar3 = *local_3c;
              uVar8 = *(ushort *)((int)param_1_00->meth_data + (uint)bVar3 * 2);
            }
            *local_3c = 0;
            if (bVar1 == 0) {
              __s = _CONF_get_string(param_1_00,(char *)local_38,(char *)name);
              local_30 = local_3c;
            }
            else {
              if (bVar1 != bVar3) {
LAB_08179a71:
                ERR_put_error(0xe,0x65,0x66,"conf_def.c",599);
                goto LAB_08179a90;
              }
              local_30 = local_3c + 1;
              __s = _CONF_get_string(param_1_00,(char *)local_38,(char *)name);
            }
            *pbVar7 = 0x3a;
          }
          else {
            *pbVar7 = 0;
            local_3c = pbVar7;
            if (bVar1 == 0) {
              __s = _CONF_get_string(param_1_00,param_2,(char *)local_38);
              local_30 = pbVar7;
            }
            else {
              if (bVar3 != bVar1) goto LAB_08179a71;
              __s = _CONF_get_string(param_1_00,param_2,(char *)local_38);
              local_30 = pbVar7 + 1;
            }
          }
          *local_3c = bVar3;
          if (__s == (char *)0x0) {
            ERR_put_error(0xe,0x65,0x68,"conf_def.c",0x26a);
            goto LAB_08179a90;
          }
          sVar4 = strlen(__s);
          BUF_MEM_grow_clean(str,(size_t)(param_1 + sVar4 + (str->length - (int)local_30)));
          cVar2 = *__s;
          iVar13 = iVar5;
          if (cVar2 != '\0') {
            iVar12 = iVar5;
            do {
              iVar13 = iVar12 + 1;
              str->data[iVar12] = cVar2;
              cVar2 = __s[iVar13 - iVar5];
              iVar12 = iVar13;
            } while (cVar2 != '\0');
          }
          iVar5 = iVar13;
          *local_3c = bVar3;
          uVar9 = (uint)*local_30;
          pvVar10 = param_1_00->meth_data;
          uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
          param_1 = local_30;
        }
        else {
          param_1 = param_1 + 1;
          str->data[iVar5] = cVar2;
          iVar5 = iVar5 + 1;
          uVar9 = (uint)*param_1;
          pvVar10 = param_1_00->meth_data;
          uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
        }
      }
      else {
        bVar3 = param_1[1];
        if ((*(byte *)((int)pvVar10 + (uint)bVar3 * 2) & 8) != 0) {
LAB_08179d18:
          str->data[iVar5] = '\0';
          if (*param_3 != (char *)0x0) {
            CRYPTO_free(*param_3);
          }
          *param_3 = str->data;
          CRYPTO_free(str);
          return 1;
        }
        if (bVar3 == 0x72) {
          bVar3 = 0xd;
        }
        else if (bVar3 == 0x6e) {
          bVar3 = 10;
        }
        else if (bVar3 == 0x62) {
          bVar3 = 8;
        }
        else if (bVar3 == 0x74) {
          bVar3 = 9;
        }
        str->data[iVar5] = bVar3;
        iVar5 = iVar5 + 1;
        uVar9 = (uint)param_1[2];
        pvVar10 = param_1_00->meth_data;
        uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
        param_1 = param_1 + 2;
      }
      goto LAB_08179978;
    }
    uVar9 = (uint)param_1[1];
    uVar6 = (uint)cVar2;
    uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
    while( true ) {
      param_1 = param_1 + 1;
      bVar3 = (byte)uVar9;
      if ((uVar8 & 8) != 0) break;
      if (uVar6 == (int)(char)bVar3) {
        bVar3 = param_1[1];
        uVar9 = (uint)(char)bVar3;
        if (uVar6 != uVar9) goto LAB_08179bd5;
        param_1 = param_1 + 1;
      }
      str->data[iVar5] = bVar3;
      uVar9 = (uint)param_1[1];
      pvVar10 = param_1_00->meth_data;
      uVar8 = *(ushort *)((int)pvVar10 + uVar9 * 2);
      iVar5 = iVar5 + 1;
    }
    if (uVar6 == (int)(char)bVar3) {
      uVar9 = (uint)param_1[1];
LAB_08179bd5:
      uVar8 = *(ushort *)((int)pvVar10 + (uVar9 & 0xff) * 2);
      param_1 = param_1 + 1;
    }
  } while( true );
}

