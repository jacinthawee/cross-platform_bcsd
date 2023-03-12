
undefined4 str_copy(CONF *param_1,byte *param_2,char **param_3,byte *param_4)

{
  ushort uVar1;
  byte bVar2;
  BUF_MEM *str;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *__s;
  void *pvVar6;
  byte *section;
  byte *pbVar7;
  byte bVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  byte *name;
  
  str = BUF_MEM_new();
  if (str != (BUF_MEM *)0x0) {
    sVar3 = strlen((char *)param_4);
    iVar4 = BUF_MEM_grow(str,sVar3 + 1);
    if (iVar4 != 0) {
      pvVar6 = param_1->meth_data;
      iVar4 = 0;
      uVar10 = (uint)*param_4;
      uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar10 * 2);
      bVar2 = 0;
LAB_000da296:
      do {
        uVar11 = uVar10;
        pbVar12 = param_4;
        if (-1 < (int)(uVar5 << 0x19)) goto LAB_000da318;
LAB_000da29a:
        uVar10 = (uint)pbVar12[1];
        param_4 = pbVar12 + 1;
        iVar14 = (int)(short)(ushort)pbVar12[1];
        uVar1 = *(ushort *)((int)pvVar6 + iVar14 * 2);
        if ((uVar1 & 8) == 0) {
          iVar14 = iVar4;
          if (uVar10 != uVar11) {
            do {
              bVar8 = (byte)uVar10;
              pbVar12 = param_4;
              if ((uVar1 & 0x20) != 0) {
                bVar8 = param_4[1];
                uVar10 = (uint)bVar8;
                iVar15 = (int)(short)(ushort)bVar8;
                pbVar12 = param_4 + 1;
                param_4 = param_4 + 1;
                iVar4 = iVar14;
                if ((*(ushort *)((int)pvVar6 + iVar15 * 2) & 8) == 0) goto LAB_000da2de;
LAB_000da302:
                if (uVar10 != uVar11) {
                  uVar5 = (uint)*(ushort *)((int)pvVar6 + iVar15 * 2);
                  goto LAB_000da296;
                }
                break;
              }
LAB_000da2de:
              iVar4 = iVar14 + 1;
              param_4 = pbVar12 + 1;
              str->data[iVar14] = bVar8;
              uVar10 = (uint)pbVar12[1];
              pvVar6 = param_1->meth_data;
              iVar15 = (int)(short)(ushort)pbVar12[1];
              uVar1 = *(ushort *)((int)pvVar6 + iVar15 * 2);
              if ((uVar1 & 8) != 0) goto LAB_000da302;
              iVar14 = iVar4;
            } while (uVar10 != uVar11);
            goto LAB_000da30c;
          }
          pbVar12 = pbVar12 + 2;
          uVar11 = (uint)*pbVar12;
          uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar11 * 2);
        }
        else {
          if (uVar10 != uVar11) {
            uVar5 = (uint)*(ushort *)((int)pvVar6 + iVar14 * 2);
            goto LAB_000da296;
          }
LAB_000da30c:
          uVar11 = (uint)param_4[1];
          pbVar12 = param_4 + 1;
          uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar11 * 2);
        }
LAB_000da314:
        if ((int)(uVar5 << 0x19) < 0) goto LAB_000da29a;
LAB_000da318:
        if ((int)(uVar5 << 0x15) < 0) {
          uVar10 = (uint)pbVar12[1];
          param_4 = pbVar12 + 1;
          uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar10 * 2);
          iVar14 = iVar4;
          if ((int)(uVar5 << 0x1c) < 0) goto LAB_000da3c0;
          goto LAB_000da348;
        }
        if ((int)(uVar5 << 0x1a) < 0) {
          bVar8 = pbVar12[1];
          uVar5 = (uint)bVar8;
          param_4 = pbVar12 + 2;
          if ((int)((uint)*(ushort *)((int)pvVar6 + uVar5 * 2) << 0x1c) < 0) {
LAB_000da52a:
            str->data[iVar4] = '\0';
            if (*param_3 != (char *)0x0) {
              CRYPTO_free(*param_3);
            }
            *param_3 = str->data;
            CRYPTO_free(str);
            return 1;
          }
          if (uVar5 == 0x72) {
            bVar8 = 0xd;
          }
          else if (uVar5 == 0x6e) {
            bVar8 = 10;
          }
          else if (uVar5 == 0x62) {
            bVar8 = 8;
          }
          else if (uVar5 == 0x74) {
            bVar8 = 9;
          }
          str->data[iVar4] = bVar8;
          iVar4 = iVar4 + 1;
          uVar10 = (uint)pbVar12[2];
          pvVar6 = param_1->meth_data;
          uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar10 * 2);
          goto LAB_000da296;
        }
        uVar5 = uVar5 & 8;
        if (uVar5 != 0) goto LAB_000da52a;
        if (uVar11 != 0x24) goto code_r0x000da3e2;
        uVar10 = (uint)pbVar12[1];
        if (uVar10 == 0x7b) {
          uVar5 = 0x7d;
LAB_000da51e:
          pbVar7 = pbVar12 + 2;
          uVar10 = (uint)pbVar12[2];
        }
        else {
          if (uVar10 == 0x28) {
            uVar5 = 0x29;
            goto LAB_000da51e;
          }
          pbVar7 = pbVar12 + 1;
        }
        uVar1 = *(ushort *)((int)pvVar6 + uVar10 * 2);
        pbVar13 = pbVar7;
        while ((uVar1 & 0x107) != 0) {
          pbVar13 = pbVar13 + 1;
          uVar10 = (uint)*pbVar13;
          uVar1 = *(ushort *)((int)pvVar6 + uVar10 * 2);
        }
        if ((uVar10 == 0x3a) && (bVar8 = pbVar13[1], bVar8 == 0x3a)) {
          name = pbVar13 + 2;
          *pbVar13 = 0;
          uVar10 = (uint)pbVar13[2];
          section = pbVar7;
          pbVar7 = pbVar13;
          pbVar13 = name;
          if ((*(ushort *)((int)param_1->meth_data + uVar10 * 2) & 0x107) != 0) {
            do {
              pbVar13 = pbVar13 + 1;
              uVar10 = (uint)*pbVar13;
            } while ((*(ushort *)((int)param_1->meth_data + uVar10 * 2) & 0x107) != 0);
            bVar8 = 0x3a;
          }
        }
        else {
          section = param_2;
          name = pbVar7;
          pbVar7 = (byte *)0x0;
          bVar8 = bVar2;
        }
        *pbVar13 = 0;
        param_4 = pbVar13;
        if (uVar5 != 0) {
          if (uVar10 == uVar5) {
            param_4 = pbVar13 + 1;
            goto LAB_000da44c;
          }
          ERR_put_error(0xe,0x65,0x66,"conf_def.c",599);
          break;
        }
LAB_000da44c:
        __s = _CONF_get_string(param_1,(char *)section,(char *)name);
        if (pbVar7 != (byte *)0x0) {
          *pbVar7 = bVar8;
        }
        *pbVar13 = (byte)uVar10;
        if (__s == (char *)0x0) {
          ERR_put_error(0xe,0x65,0x68,"conf_def.c",0x26a);
          break;
        }
        sVar3 = strlen(__s);
        BUF_MEM_grow_clean(str,(size_t)(pbVar12 + sVar3 + (str->length - (int)param_4)));
        cVar9 = *__s;
        if (cVar9 != '\0') {
          iVar14 = iVar4 - (int)__s;
          do {
            iVar4 = iVar4 + 1;
            (str->data + (int)__s)[iVar14] = cVar9;
            __s = __s + 1;
            cVar9 = *__s;
          } while (cVar9 != '\0');
        }
        *pbVar13 = (byte)uVar10;
        pvVar6 = param_1->meth_data;
        uVar10 = (uint)*param_4;
        uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar10 * 2);
        bVar2 = bVar8;
      } while( true );
    }
    BUF_MEM_free(str);
  }
  return 0;
LAB_000da348:
  do {
    bVar8 = (byte)uVar10;
    if (uVar10 == uVar11) {
      bVar8 = param_4[1];
      uVar10 = (uint)bVar8;
      iVar4 = iVar14;
      if (uVar10 != uVar11) goto LAB_000da3ca;
      param_4 = param_4 + 1;
    }
    iVar4 = iVar14 + 1;
    pbVar12 = param_4 + 1;
    str->data[iVar14] = bVar8;
    pvVar6 = param_1->meth_data;
    uVar10 = (uint)param_4[1];
    uVar1 = *(ushort *)((int)pvVar6 + uVar10 * 2);
    uVar5 = (uint)uVar1;
    param_4 = pbVar12;
    iVar14 = iVar4;
  } while ((uVar1 & 8) == 0);
LAB_000da3c0:
  if (uVar10 == uVar11) {
    uVar10 = (uint)param_4[1];
LAB_000da3ca:
    param_4 = param_4 + 1;
    uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar10 * 2);
  }
  goto LAB_000da296;
code_r0x000da3e2:
  pbVar12 = pbVar12 + 1;
  str->data[iVar4] = (char)uVar11;
  iVar4 = iVar4 + 1;
  uVar11 = (uint)*pbVar12;
  pvVar6 = param_1->meth_data;
  uVar5 = (uint)*(ushort *)((int)pvVar6 + uVar11 * 2);
  goto LAB_000da314;
}

