
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  byte bVar1;
  byte *pbVar2;
  byte *ptr;
  ushort **ppuVar3;
  size_t sVar4;
  int iVar5;
  undefined *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  byte *__s;
  ushort *puVar11;
  _STACK *local_24 [2];
  
  pbVar7 = (byte *)0x0;
  local_24[0] = (_STACK *)0x0;
  ptr = (byte *)BUF_strdup(line);
  if (ptr == (byte *)0x0) {
    ERR_put_error(0x22,0x6d,0x41,"v3_utl.c",0x121);
    goto LAB_000d0100;
  }
  puVar6 = (undefined *)(uint)*ptr;
  if (puVar6 != (undefined *)0x0) {
    __s = ptr;
    if (puVar6 != (undefined *)0xd && puVar6 != (undefined *)0xa) {
      iVar5 = 1;
      pbVar2 = ptr;
      do {
        pbVar8 = pbVar2 + 1;
        if (iVar5 == 2) {
          pbVar10 = __s;
          if (puVar6 == &DAT_0000002c) {
            *pbVar2 = 0;
            uVar9 = (uint)*__s;
            if (uVar9 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar11 = *ppuVar3;
              while ((int)((uint)puVar11[uVar9] << 0x12) < 0) {
                __s = __s + 1;
                uVar9 = (uint)*__s;
                if (uVar9 == 0) goto LAB_000d0118;
              }
              sVar4 = strlen((char *)__s);
              pbVar2 = __s + (sVar4 - 1);
              do {
                pbVar10 = pbVar2;
                if (pbVar10 == __s) goto LAB_000cffe2;
                pbVar2 = pbVar10 + -1;
              } while ((puVar11[*pbVar10] & 0x2000) != 0);
              if (pbVar10 != __s) {
                pbVar10[1] = 0;
              }
LAB_000cffe2:
              if (*__s != 0) {
                X509V3_add_value((char *)pbVar7,(char *)__s,(stack_st_CONF_VALUE **)local_24);
                pbVar7 = (byte *)0x0;
                iVar5 = 1;
                pbVar10 = pbVar8;
                goto LAB_000cff0c;
              }
            }
LAB_000d0118:
            ERR_put_error(0x22,0x6d,0x6d,"v3_utl.c",0x150);
            goto LAB_000d0100;
          }
LAB_000cff0c:
          bVar1 = *pbVar8;
          __s = pbVar10;
        }
        else {
          if (puVar6 == (undefined *)0x3a) {
            *pbVar2 = 0;
            uVar9 = (uint)*__s;
            if (uVar9 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar11 = *ppuVar3;
              while ((int)((uint)puVar11[uVar9] << 0x12) < 0) {
                __s = __s + 1;
                uVar9 = (uint)*__s;
                if (uVar9 == 0) goto LAB_000d00e8;
              }
              sVar4 = strlen((char *)__s);
              pbVar7 = __s + (sVar4 - 1);
              do {
                pbVar2 = pbVar7;
                if (pbVar2 == __s) goto LAB_000d0056;
                pbVar7 = pbVar2 + -1;
              } while ((puVar11[*pbVar2] & 0x2000) != 0);
              if (pbVar2 != __s) {
                pbVar2[1] = 0;
              }
LAB_000d0056:
              if (*__s != 0) {
                iVar5 = 2;
                pbVar10 = pbVar8;
                pbVar7 = __s;
                goto LAB_000cff0c;
              }
            }
LAB_000d00e8:
            iVar5 = 0x132;
            goto LAB_000d00f0;
          }
          pbVar10 = __s;
          if (puVar6 == &DAT_0000002c) {
            *pbVar2 = 0;
            uVar9 = (uint)*__s;
            if (uVar9 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar11 = *ppuVar3;
              while ((int)((uint)puVar11[uVar9] << 0x12) < 0) {
                __s = __s + 1;
                uVar9 = (uint)*__s;
                if (uVar9 == 0) goto LAB_000d0132;
              }
              sVar4 = strlen((char *)__s);
              pbVar7 = __s + (sVar4 - 1);
              do {
                pbVar2 = pbVar7;
                if (pbVar2 == __s) goto LAB_000d00d6;
                pbVar7 = pbVar2 + -1;
              } while ((puVar11[*pbVar2] & 0x2000) != 0);
              pbVar2[1] = 0;
LAB_000d00d6:
              if (*__s != 0) {
                X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)local_24);
                pbVar10 = pbVar8;
                pbVar7 = __s;
                goto LAB_000cff2a;
              }
            }
LAB_000d0132:
            iVar5 = 0x13f;
            goto LAB_000d00f0;
          }
LAB_000cff2a:
          bVar1 = *pbVar8;
          iVar5 = 1;
          __s = pbVar10;
        }
        puVar6 = (undefined *)(uint)bVar1;
      } while ((puVar6 != (undefined *)0x0) &&
              (pbVar2 = pbVar8, puVar6 != (undefined *)0xa && puVar6 != (undefined *)0xd));
      if (iVar5 == 2) {
        uVar9 = (uint)*__s;
        if (uVar9 != 0) {
          ppuVar3 = __ctype_b_loc();
          puVar11 = *ppuVar3;
          do {
            if (-1 < (int)((uint)puVar11[uVar9] << 0x12)) {
              sVar4 = strlen((char *)__s);
              pbVar2 = __s + (sVar4 - 1);
              goto joined_r0x000d016c;
            }
            __s = __s + 1;
            uVar9 = (uint)*__s;
          } while (uVar9 != 0);
        }
        goto LAB_000d019e;
      }
      puVar6 = (undefined *)(uint)*__s;
      if (puVar6 == (undefined *)0x0) goto LAB_000d013c;
    }
    ppuVar3 = __ctype_b_loc();
    puVar11 = *ppuVar3;
    do {
      if (-1 < (int)((uint)puVar11[(int)puVar6] << 0x12)) {
        sVar4 = strlen((char *)__s);
        pbVar7 = __s + (sVar4 - 1);
        goto joined_r0x000cff66;
      }
      __s = __s + 1;
      puVar6 = (undefined *)(uint)*__s;
    } while (puVar6 != (undefined *)0x0);
  }
  goto LAB_000d013c;
  while (pbVar2 = pbVar8 + -1, (puVar11[*pbVar8] & 0x2000) != 0) {
joined_r0x000d016c:
    pbVar8 = pbVar2;
    if (pbVar8 == __s) goto LAB_000d018e;
  }
  if (pbVar8 != __s) {
    pbVar8[1] = 0;
  }
LAB_000d018e:
  if (*__s != 0) {
    X509V3_add_value((char *)pbVar7,(char *)__s,(stack_st_CONF_VALUE **)local_24);
    goto LAB_000cff9a;
  }
LAB_000d019e:
  ERR_put_error(0x22,0x6d,0x6d,"v3_utl.c",0x162);
  goto LAB_000d0100;
  while (pbVar7 = pbVar2 + -1, (puVar11[*pbVar2] & 0x2000) != 0) {
joined_r0x000cff66:
    pbVar2 = pbVar7;
    if (pbVar2 == __s) goto LAB_000cff88;
  }
  if (pbVar2 != __s) {
    pbVar2[1] = 0;
  }
LAB_000cff88:
  if (*__s != 0) {
    X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)local_24);
LAB_000cff9a:
    CRYPTO_free(ptr);
    return (stack_st_CONF_VALUE *)local_24[0];
  }
LAB_000d013c:
  iVar5 = 0x16c;
LAB_000d00f0:
  ERR_put_error(0x22,0x6d,0x6c,"v3_utl.c",iVar5);
LAB_000d0100:
  CRYPTO_free(ptr);
  sk_pop_free(local_24[0],X509V3_conf_free + 1);
  return (stack_st_CONF_VALUE *)0x0;
}

