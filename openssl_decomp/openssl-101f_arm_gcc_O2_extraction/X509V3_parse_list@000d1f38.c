
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  byte bVar1;
  byte *pbVar2;
  byte *ptr;
  ushort **ppuVar3;
  size_t sVar4;
  int iVar5;
  ushort uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *__s;
  ushort *puVar10;
  byte *pbVar11;
  _STACK *local_24 [2];
  
  local_24[0] = (_STACK *)0x0;
  ptr = (byte *)BUF_strdup(line);
  uVar6 = (ushort)*ptr;
  if (uVar6 != 0) {
    __s = ptr;
    if (uVar6 != 0xd && uVar6 != 10) {
      pbVar11 = (byte *)0x0;
      iVar5 = 1;
      pbVar2 = ptr;
      do {
        pbVar7 = pbVar2 + 1;
        if (iVar5 == 2) {
          pbVar9 = __s;
          if (uVar6 == 0x2c) {
            *pbVar2 = 0;
            uVar8 = (uint)*__s;
            if (uVar8 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar10 = *ppuVar3;
              while ((int)((uint)puVar10[uVar8] << 0x12) < 0) {
                __s = __s + 1;
                uVar8 = (uint)*__s;
                if (uVar8 == 0) goto LAB_000d214c;
              }
              sVar4 = strlen((char *)__s);
              pbVar2 = __s + (sVar4 - 1);
              do {
                pbVar9 = pbVar2;
                if (pbVar9 == __s) goto LAB_000d2042;
                pbVar2 = pbVar9 + -1;
              } while ((puVar10[*pbVar9] & 0x2000) != 0);
              if (__s != pbVar9) {
                pbVar9[1] = 0;
              }
LAB_000d2042:
              if (*__s != 0) {
                X509V3_add_value((char *)pbVar11,(char *)__s,(stack_st_CONF_VALUE **)local_24);
                pbVar11 = (byte *)0x0;
                iVar5 = 1;
                pbVar9 = pbVar7;
                goto LAB_000d1f6a;
              }
            }
LAB_000d214c:
            ERR_put_error(0x22,0x6d,0x6d,"v3_utl.c",299);
            goto LAB_000d2164;
          }
LAB_000d1f6a:
          bVar1 = *pbVar7;
          __s = pbVar9;
        }
        else {
          if (uVar6 == 0x3a) {
            *pbVar2 = 0;
            uVar8 = (uint)*__s;
            if (uVar8 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar10 = *ppuVar3;
              while ((int)((uint)puVar10[uVar8] << 0x12) < 0) {
                __s = __s + 1;
                uVar8 = (uint)*__s;
                if (uVar8 == 0) goto LAB_000d217c;
              }
              sVar4 = strlen((char *)__s);
              pbVar2 = __s + (sVar4 - 1);
              do {
                pbVar11 = pbVar2;
                if (pbVar11 == __s) goto LAB_000d20b6;
                pbVar2 = pbVar11 + -1;
              } while ((puVar10[*pbVar11] & 0x2000) != 0);
              if (__s != pbVar11) {
                pbVar11[1] = 0;
              }
LAB_000d20b6:
              if (*__s != 0) {
                iVar5 = 2;
                pbVar9 = pbVar7;
                pbVar11 = __s;
                goto LAB_000d1f6a;
              }
            }
LAB_000d217c:
            iVar5 = 0x10f;
            goto LAB_000d2184;
          }
          pbVar9 = __s;
          if (uVar6 == 0x2c) {
            *pbVar2 = 0;
            uVar8 = (uint)*__s;
            if (uVar8 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar10 = *ppuVar3;
              while ((int)((uint)puVar10[uVar8] << 0x12) < 0) {
                __s = __s + 1;
                uVar8 = (uint)*__s;
                if (uVar8 == 0) goto LAB_000d2196;
              }
              sVar4 = strlen((char *)__s);
              pbVar2 = __s + (sVar4 - 1);
              do {
                pbVar11 = pbVar2;
                if (pbVar11 == __s) goto LAB_000d213a;
                pbVar2 = pbVar11 + -1;
              } while ((puVar10[*pbVar11] & 0x2000) != 0);
              if (__s != pbVar11) {
                pbVar11[1] = 0;
              }
LAB_000d213a:
              if (*__s != 0) {
                X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)local_24);
                pbVar9 = pbVar7;
                pbVar11 = __s;
                goto LAB_000d1f88;
              }
            }
LAB_000d2196:
            iVar5 = 0x11b;
            goto LAB_000d2184;
          }
LAB_000d1f88:
          bVar1 = *pbVar7;
          iVar5 = 1;
          __s = pbVar9;
        }
        uVar6 = (ushort)bVar1;
      } while ((uVar6 != 0) && (pbVar2 = pbVar7, uVar6 != 10 && uVar6 != 0xd));
      if (iVar5 == 2) {
        uVar8 = (uint)*__s;
        if (uVar8 != 0) {
          ppuVar3 = __ctype_b_loc();
          puVar10 = *ppuVar3;
          do {
            if (-1 < (int)((uint)puVar10[uVar8] << 0x12)) {
              sVar4 = strlen((char *)__s);
              pbVar2 = __s + (sVar4 - 1);
              goto joined_r0x000d21d0;
            }
            __s = __s + 1;
            uVar8 = (uint)*__s;
          } while (uVar8 != 0);
        }
        goto LAB_000d2202;
      }
      uVar6 = (ushort)*__s;
      if (uVar6 == 0) goto LAB_000d21a0;
    }
    ppuVar3 = __ctype_b_loc();
    puVar10 = *ppuVar3;
    do {
      if (-1 < (int)((uint)puVar10[(short)uVar6] << 0x12)) {
        sVar4 = strlen((char *)__s);
        pbVar2 = __s + (sVar4 - 1);
        goto joined_r0x000d1fc6;
      }
      __s = __s + 1;
      uVar6 = (ushort)*__s;
    } while (uVar6 != 0);
  }
  goto LAB_000d21a0;
  while (pbVar2 = pbVar7 + -1, (puVar10[*pbVar7] & 0x2000) != 0) {
joined_r0x000d21d0:
    pbVar7 = pbVar2;
    if (pbVar7 == __s) goto LAB_000d21f2;
  }
  if (pbVar7 != __s) {
    pbVar7[1] = 0;
  }
LAB_000d21f2:
  if (*__s != 0) {
    X509V3_add_value((char *)pbVar11,(char *)__s,(stack_st_CONF_VALUE **)local_24);
    goto LAB_000d1ffa;
  }
LAB_000d2202:
  ERR_put_error(0x22,0x6d,0x6d,"v3_utl.c",0x13c);
  goto LAB_000d2164;
  while (pbVar2 = pbVar11 + -1, (puVar10[*pbVar11] & 0x2000) != 0) {
joined_r0x000d1fc6:
    pbVar11 = pbVar2;
    if (pbVar11 == __s) goto LAB_000d1fe8;
  }
  if (pbVar11 != __s) {
    pbVar11[1] = 0;
  }
LAB_000d1fe8:
  if (*__s != 0) {
    X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)local_24);
LAB_000d1ffa:
    CRYPTO_free(ptr);
    return (stack_st_CONF_VALUE *)local_24[0];
  }
LAB_000d21a0:
  iVar5 = 0x146;
LAB_000d2184:
  ERR_put_error(0x22,0x6d,0x6c,"v3_utl.c",iVar5);
LAB_000d2164:
  CRYPTO_free(ptr);
  sk_pop_free(local_24[0],X509V3_conf_free + 1);
  return (stack_st_CONF_VALUE *)0x0;
}

