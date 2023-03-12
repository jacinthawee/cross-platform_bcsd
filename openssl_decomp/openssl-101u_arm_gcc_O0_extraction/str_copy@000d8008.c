
undefined4 str_copy(CONF *param_1,byte *param_2,char **param_3,byte *param_4)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  BUF_MEM *str;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  char *__s;
  void *pvVar7;
  byte *section;
  byte *pbVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  byte *name;
  
  str = BUF_MEM_new();
  if (str != (BUF_MEM *)0x0) {
    sVar4 = strlen((char *)param_4);
    iVar5 = BUF_MEM_grow(str,sVar4 + 1);
    if (iVar5 != 0) {
      pvVar7 = param_1->meth_data;
      iVar5 = 0;
      uVar10 = (uint)*param_4;
      uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar10 * 2);
      bVar3 = 0;
LAB_000d803e:
      do {
        uVar11 = uVar10;
        pbVar12 = param_4;
        if (-1 < (int)(uVar6 << 0x19)) goto LAB_000d80c0;
LAB_000d8042:
        uVar10 = (uint)pbVar12[1];
        param_4 = pbVar12 + 1;
        iVar14 = (int)(short)(ushort)pbVar12[1];
        uVar2 = *(ushort *)((int)pvVar7 + iVar14 * 2);
        if ((uVar2 & 8) == 0) {
          iVar14 = iVar5;
          if (uVar10 != uVar11) {
            do {
              bVar9 = (byte)uVar10;
              pbVar12 = param_4;
              if ((uVar2 & 0x20) != 0) {
                bVar9 = param_4[1];
                uVar10 = (uint)bVar9;
                iVar15 = (int)(short)(ushort)bVar9;
                pbVar12 = param_4 + 1;
                param_4 = param_4 + 1;
                iVar5 = iVar14;
                if ((*(ushort *)((int)pvVar7 + iVar15 * 2) & 8) == 0) goto LAB_000d8086;
LAB_000d80aa:
                if (uVar10 != uVar11) {
                  uVar6 = (uint)*(ushort *)((int)pvVar7 + iVar15 * 2);
                  goto LAB_000d803e;
                }
                break;
              }
LAB_000d8086:
              iVar5 = iVar14 + 1;
              param_4 = pbVar12 + 1;
              str->data[iVar14] = bVar9;
              uVar10 = (uint)pbVar12[1];
              pvVar7 = param_1->meth_data;
              iVar15 = (int)(short)(ushort)pbVar12[1];
              uVar2 = *(ushort *)((int)pvVar7 + iVar15 * 2);
              if ((uVar2 & 8) != 0) goto LAB_000d80aa;
              iVar14 = iVar5;
            } while (uVar10 != uVar11);
            goto LAB_000d80b4;
          }
          pbVar12 = pbVar12 + 2;
          uVar11 = (uint)*pbVar12;
          uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar11 * 2);
        }
        else {
          if (uVar10 != uVar11) {
            uVar6 = (uint)*(ushort *)((int)pvVar7 + iVar14 * 2);
            goto LAB_000d803e;
          }
LAB_000d80b4:
          uVar11 = (uint)param_4[1];
          pbVar12 = param_4 + 1;
          uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar11 * 2);
        }
LAB_000d80bc:
        if ((int)(uVar6 << 0x19) < 0) goto LAB_000d8042;
LAB_000d80c0:
        if ((int)(uVar6 << 0x15) < 0) {
          uVar10 = (uint)pbVar12[1];
          param_4 = pbVar12 + 1;
          uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar10 * 2);
          iVar14 = iVar5;
          if ((int)(uVar6 << 0x1c) < 0) goto LAB_000d8168;
          goto LAB_000d80f0;
        }
        if ((int)(uVar6 << 0x1a) < 0) {
          bVar9 = pbVar12[1];
          uVar6 = (uint)bVar9;
          param_4 = pbVar12 + 2;
          if ((int)((uint)*(ushort *)((int)pvVar7 + uVar6 * 2) << 0x1c) < 0) {
LAB_000d82da:
            str->data[iVar5] = '\0';
            if (*param_3 != (char *)0x0) {
              CRYPTO_free(*param_3);
            }
            *param_3 = str->data;
            CRYPTO_free(str);
            return 1;
          }
          if (uVar6 == 0x72) {
            bVar9 = 0xd;
          }
          else if (uVar6 == 0x6e) {
            bVar9 = 10;
          }
          else if (uVar6 == 0x62) {
            bVar9 = 8;
          }
          else if (uVar6 == 0x74) {
            bVar9 = 9;
          }
          str->data[iVar5] = bVar9;
          iVar5 = iVar5 + 1;
          uVar10 = (uint)pbVar12[2];
          pvVar7 = param_1->meth_data;
          uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar10 * 2);
          goto LAB_000d803e;
        }
        uVar6 = uVar6 & 8;
        if (uVar6 != 0) goto LAB_000d82da;
        if (uVar11 != 0x24) goto code_r0x000d818a;
        uVar10 = (uint)pbVar12[1];
        if (uVar10 == 0x7b) {
          uVar6 = 0x7d;
LAB_000d82ce:
          pbVar8 = pbVar12 + 2;
          uVar10 = (uint)pbVar12[2];
        }
        else {
          if (uVar10 == 0x28) {
            uVar6 = 0x29;
            goto LAB_000d82ce;
          }
          pbVar8 = pbVar12 + 1;
        }
        uVar2 = *(ushort *)((int)pvVar7 + uVar10 * 2);
        pbVar13 = pbVar8;
        while ((uVar2 & 0x107) != 0) {
          pbVar13 = pbVar13 + 1;
          uVar10 = (uint)*pbVar13;
          uVar2 = *(ushort *)((int)pvVar7 + uVar10 * 2);
        }
        if ((uVar10 == 0x3a) && (bVar9 = pbVar13[1], bVar9 == 0x3a)) {
          name = pbVar13 + 2;
          *pbVar13 = 0;
          uVar10 = (uint)pbVar13[2];
          section = pbVar8;
          pbVar8 = pbVar13;
          pbVar13 = name;
          if ((*(ushort *)((int)param_1->meth_data + uVar10 * 2) & 0x107) != 0) {
            do {
              pbVar13 = pbVar13 + 1;
              uVar10 = (uint)*pbVar13;
            } while ((*(ushort *)((int)param_1->meth_data + uVar10 * 2) & 0x107) != 0);
            bVar9 = 0x3a;
          }
        }
        else {
          section = param_2;
          name = pbVar8;
          pbVar8 = (byte *)0x0;
          bVar9 = bVar3;
        }
        *pbVar13 = 0;
        param_4 = pbVar13;
        if (uVar6 != 0) {
          if (uVar10 == uVar6) {
            param_4 = pbVar13 + 1;
            goto LAB_000d81f6;
          }
          ERR_put_error(0xe,0x65,0x66,"conf_def.c",0x234);
          break;
        }
LAB_000d81f6:
        __s = _CONF_get_string(param_1,(char *)section,(char *)name);
        if (pbVar8 != (byte *)0x0) {
          *pbVar8 = bVar9;
        }
        *pbVar13 = (byte)uVar10;
        if (__s == (char *)0x0) {
          ERR_put_error(0xe,0x65,0x68,"conf_def.c",0x248);
          break;
        }
        sVar4 = strlen(__s);
        iVar14 = BUF_MEM_grow_clean(str,(size_t)(pbVar12 + sVar4 + (str->length - (int)param_4)));
        if (iVar14 == 0) {
          ERR_put_error(0xe,0x65,0x41,"conf_def.c",0x24d);
          break;
        }
        iVar14 = iVar5 - (int)__s;
        cVar1 = *__s;
        while (cVar1 != '\0') {
          iVar5 = iVar5 + 1;
          (str->data + (int)__s)[iVar14] = cVar1;
          __s = __s + 1;
          cVar1 = *__s;
        }
        *pbVar13 = (byte)uVar10;
        pvVar7 = param_1->meth_data;
        uVar10 = (uint)*param_4;
        uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar10 * 2);
        bVar3 = bVar9;
      } while( true );
    }
    BUF_MEM_free(str);
  }
  return 0;
LAB_000d80f0:
  do {
    bVar9 = (byte)uVar10;
    if (uVar10 == uVar11) {
      bVar9 = param_4[1];
      uVar10 = (uint)bVar9;
      iVar5 = iVar14;
      if (uVar10 != uVar11) goto LAB_000d8172;
      param_4 = param_4 + 1;
    }
    iVar5 = iVar14 + 1;
    pbVar12 = param_4 + 1;
    str->data[iVar14] = bVar9;
    pvVar7 = param_1->meth_data;
    uVar10 = (uint)param_4[1];
    uVar2 = *(ushort *)((int)pvVar7 + uVar10 * 2);
    uVar6 = (uint)uVar2;
    param_4 = pbVar12;
    iVar14 = iVar5;
  } while ((uVar2 & 8) == 0);
LAB_000d8168:
  if (uVar10 == uVar11) {
    uVar10 = (uint)param_4[1];
LAB_000d8172:
    param_4 = param_4 + 1;
    uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar10 * 2);
  }
  goto LAB_000d803e;
code_r0x000d818a:
  pbVar12 = pbVar12 + 1;
  str->data[iVar5] = (char)uVar11;
  iVar5 = iVar5 + 1;
  uVar11 = (uint)*pbVar12;
  pvVar7 = param_1->meth_data;
  uVar6 = (uint)*(ushort *)((int)pvVar7 + uVar11 * 2);
  goto LAB_000d80bc;
}

