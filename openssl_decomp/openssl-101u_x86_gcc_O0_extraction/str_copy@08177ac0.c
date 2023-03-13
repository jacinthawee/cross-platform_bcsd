
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
  int iVar7;
  char *__s;
  byte *pbVar8;
  ushort uVar9;
  uint uVar10;
  void *pvVar11;
  uint uVar12;
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
LAB_08177c40:
    BUF_MEM_free(str);
    return 0;
  }
  pvVar11 = param_1_00->meth_data;
  uVar10 = (uint)*param_1;
  uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
  iVar5 = 0;
LAB_08177b28:
  do {
    while (cVar2 = (char)uVar10, (uVar9 & 0x40) != 0) {
      bVar3 = param_1[1];
      while( true ) {
        pbVar8 = param_1 + 1;
        uVar10 = (uint)(char)bVar3;
        uVar9 = *(ushort *)((int)pvVar11 + (uVar10 & 0xff) * 2);
        uVar12 = uVar10;
        uVar6 = uVar10 & 0xff;
        if ((uVar9 & 8) != 0) break;
        if ((int)cVar2 == uVar10) goto LAB_08177d98;
        if ((uVar9 & 0x20) != 0) {
          pbVar8 = param_1 + 2;
          bVar3 = param_1[2];
          uVar10 = (uint)bVar3;
          if ((*(byte *)((int)pvVar11 + uVar10 * 2) & 8) != 0) {
            uVar12 = (uint)(char)bVar3;
            uVar6 = uVar10;
            break;
          }
        }
        str->data[iVar5] = bVar3;
        bVar3 = pbVar8[1];
        pvVar11 = param_1_00->meth_data;
        iVar5 = iVar5 + 1;
        param_1 = pbVar8;
      }
      local_3c = (byte *)(uVar6 * 2);
      if ((int)cVar2 == uVar12) {
LAB_08177d98:
        uVar10 = (uint)pbVar8[1];
        uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
        param_1 = pbVar8 + 1;
      }
      else {
        uVar9 = *(ushort *)((int)pvVar11 + (int)local_3c);
        param_1 = pbVar8;
      }
    }
    if ((uVar9 & 0x400) == 0) {
      if ((uVar9 & 0x20) == 0) {
        if ((uVar9 & 8) != 0) goto LAB_08177f79;
        if (cVar2 == '$') {
          bVar3 = param_1[1];
          if (bVar3 == 0x7b) {
            bVar1 = 0x7d;
LAB_08177e12:
            local_38 = param_1 + 2;
            bVar3 = param_1[2];
          }
          else {
            if (bVar3 == 0x28) {
              bVar1 = 0x29;
              goto LAB_08177e12;
            }
            local_38 = param_1 + 1;
            bVar1 = 0;
          }
          uVar9 = *(ushort *)((int)pvVar11 + (uint)bVar3 * 2);
          pbVar8 = local_38;
          while ((uVar9 & 0x107) != 0) {
            pbVar8 = pbVar8 + 1;
            bVar3 = *pbVar8;
            uVar9 = *(ushort *)((int)pvVar11 + (uint)bVar3 * 2);
          }
          if ((bVar3 == 0x3a) && (pbVar8[1] == 0x3a)) {
            *pbVar8 = 0;
            name = pbVar8 + 2;
            bVar3 = pbVar8[2];
            uVar9 = *(ushort *)((int)param_1_00->meth_data + (uint)bVar3 * 2);
            local_3c = name;
            while ((uVar9 & 0x107) != 0) {
              local_3c = local_3c + 1;
              bVar3 = *local_3c;
              uVar9 = *(ushort *)((int)param_1_00->meth_data + (uint)bVar3 * 2);
            }
            *local_3c = 0;
            if (bVar1 == 0) {
              __s = _CONF_get_string(param_1_00,(char *)local_38,(char *)name);
              local_30 = local_3c;
            }
            else {
              if (bVar1 != bVar3) {
LAB_08177c21:
                ERR_put_error(0xe,0x65,0x66,"conf_def.c",0x234);
                goto LAB_08177c40;
              }
              local_30 = local_3c + 1;
              __s = _CONF_get_string(param_1_00,(char *)local_38,(char *)name);
            }
            *pbVar8 = 0x3a;
          }
          else {
            *pbVar8 = 0;
            local_3c = pbVar8;
            if (bVar1 == 0) {
              __s = _CONF_get_string(param_1_00,param_2,(char *)local_38);
              local_30 = pbVar8;
            }
            else {
              if (bVar3 != bVar1) goto LAB_08177c21;
              __s = _CONF_get_string(param_1_00,param_2,(char *)local_38);
              local_30 = pbVar8 + 1;
            }
          }
          *local_3c = bVar3;
          if (__s == (char *)0x0) {
            ERR_put_error(0xe,0x65,0x68,"conf_def.c",0x248);
            goto LAB_08177c40;
          }
          sVar4 = strlen(__s);
          iVar7 = BUF_MEM_grow_clean(str,(size_t)(param_1 + sVar4 + (str->length - (int)local_30)));
          if (iVar7 == 0) {
            ERR_put_error(0xe,0x65,0x41,"conf_def.c",0x24d);
            goto LAB_08177c40;
          }
          cVar2 = *__s;
          iVar7 = iVar5;
          while (cVar2 != '\0') {
            str->data[iVar7] = cVar2;
            cVar2 = __s[(iVar7 + 1) - iVar5];
            iVar7 = iVar7 + 1;
          }
          *local_3c = bVar3;
          uVar10 = (uint)*local_30;
          pvVar11 = param_1_00->meth_data;
          uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
          iVar5 = iVar7;
          param_1 = local_30;
        }
        else {
          param_1 = param_1 + 1;
          str->data[iVar5] = cVar2;
          uVar10 = (uint)*param_1;
          pvVar11 = param_1_00->meth_data;
          uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
          iVar5 = iVar5 + 1;
        }
      }
      else {
        bVar3 = param_1[1];
        if ((*(byte *)((int)pvVar11 + (uint)bVar3 * 2) & 8) != 0) {
LAB_08177f79:
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
        uVar10 = (uint)param_1[2];
        pvVar11 = param_1_00->meth_data;
        uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
        iVar5 = iVar5 + 1;
        param_1 = param_1 + 2;
      }
      goto LAB_08177b28;
    }
    uVar10 = (uint)param_1[1];
    uVar6 = (uint)cVar2;
    uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
    while( true ) {
      param_1 = param_1 + 1;
      bVar3 = (byte)uVar10;
      if ((uVar9 & 8) != 0) break;
      if (uVar6 == (int)(char)bVar3) {
        bVar3 = param_1[1];
        uVar10 = (uint)(char)bVar3;
        if (uVar6 != uVar10) goto LAB_08177d85;
        param_1 = param_1 + 1;
      }
      str->data[iVar5] = bVar3;
      uVar10 = (uint)param_1[1];
      pvVar11 = param_1_00->meth_data;
      uVar9 = *(ushort *)((int)pvVar11 + uVar10 * 2);
      iVar5 = iVar5 + 1;
    }
    if (uVar6 == (int)(char)bVar3) {
      uVar10 = (uint)param_1[1];
LAB_08177d85:
      uVar9 = *(ushort *)((int)pvVar11 + (uVar10 & 0xff) * 2);
      param_1 = param_1 + 1;
    }
  } while( true );
}

