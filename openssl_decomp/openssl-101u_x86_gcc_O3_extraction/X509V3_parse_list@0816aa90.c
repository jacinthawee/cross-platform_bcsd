
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  byte bVar1;
  ushort *puVar2;
  byte bVar3;
  byte *ptr;
  uint uVar4;
  ushort **ppuVar5;
  size_t sVar6;
  _STACK *p_Var7;
  byte *pbVar8;
  byte *__s;
  byte *pbVar9;
  byte *pbVar10;
  int in_GS_OFFSET;
  int iVar11;
  _STACK *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (_STACK *)0x0;
  ptr = (byte *)BUF_strdup(line);
  if (ptr != (byte *)0x0) {
    bVar3 = *ptr;
    uVar4 = (uint)bVar3;
    __s = ptr;
    pbVar8 = ptr;
    if ((0xd < bVar3) || ((0x2401U >> (uVar4 & 0x1f) & 1) == 0)) {
      do {
        if (bVar3 == 0x3a) {
          *pbVar8 = 0;
          bVar3 = *__s;
          if (bVar3 != 0) {
            ppuVar5 = __ctype_b_loc();
            puVar2 = *ppuVar5;
            while ((*(byte *)((int)puVar2 + (uint)bVar3 * 2 + 1) & 0x20) != 0) {
              __s = __s + 1;
              bVar3 = *__s;
              if (bVar3 == 0) goto LAB_0816ada0;
            }
            sVar6 = strlen((char *)__s);
            for (pbVar10 = __s + (sVar6 - 1); pbVar10 != __s; pbVar10 = pbVar10 + -1) {
              if ((*(byte *)((int)puVar2 + (uint)*pbVar10 * 2 + 1) & 0x20) == 0) {
                if (pbVar10 != __s) {
                  pbVar10[1] = 0;
                }
                break;
              }
            }
            if (*__s != 0) {
              bVar3 = pbVar8[1];
              pbVar10 = pbVar8 + 1;
              pbVar9 = pbVar10;
              bVar1 = bVar3;
              while( true ) {
                if ((bVar1 < 0xe) && ((0x2401U >> (bVar1 & 0x1f) & 1) != 0)) {
                  if (bVar3 == 0) goto LAB_0816af10;
                  ppuVar5 = __ctype_b_loc();
                  puVar2 = *ppuVar5;
                  goto LAB_0816ae0e;
                }
                if (bVar1 == 0x2c) break;
                pbVar9 = pbVar9 + 1;
                bVar1 = *pbVar9;
              }
              *pbVar9 = 0;
              bVar3 = pbVar8[1];
              if (bVar3 != 0) {
                puVar2 = *ppuVar5;
                while ((*(byte *)((int)puVar2 + (uint)bVar3 * 2 + 1) & 0x20) != 0) {
                  pbVar10 = pbVar10 + 1;
                  bVar3 = *pbVar10;
                  if (bVar3 == 0) goto LAB_0816ad40;
                }
                sVar6 = strlen((char *)pbVar10);
                for (pbVar8 = pbVar10 + (sVar6 - 1); pbVar8 != pbVar10; pbVar8 = pbVar8 + -1) {
                  if ((*(byte *)((int)puVar2 + (uint)*pbVar8 * 2 + 1) & 0x20) == 0) {
                    if ((pbVar8 != pbVar10) && (pbVar8[1] = 0, *pbVar10 == 0)) goto LAB_0816ad40;
                    break;
                  }
                }
                X509V3_add_value((char *)__s,(char *)pbVar10,(stack_st_CONF_VALUE **)&local_24);
                bVar3 = pbVar9[1];
                pbVar8 = pbVar9;
                goto joined_r0x0816ac6d;
              }
LAB_0816ad40:
              iVar11 = 0x150;
              goto LAB_0816ad48;
            }
          }
LAB_0816ada0:
          iVar11 = 0x132;
          goto LAB_0816ada8;
        }
        if ((char)uVar4 == ',') {
          *pbVar8 = 0;
          bVar3 = *__s;
          if (bVar3 == 0) {
LAB_0816adc0:
            iVar11 = 0x13f;
            goto LAB_0816ada8;
          }
          ppuVar5 = __ctype_b_loc();
          puVar2 = *ppuVar5;
          while ((*(byte *)((int)puVar2 + (uint)bVar3 * 2 + 1) & 0x20) != 0) {
            __s = __s + 1;
            bVar3 = *__s;
            if (bVar3 == 0) goto LAB_0816adc0;
          }
          sVar6 = strlen((char *)__s);
          for (pbVar10 = __s + (sVar6 - 1); pbVar10 != __s; pbVar10 = pbVar10 + -1) {
            if ((*(byte *)((int)puVar2 + (uint)*pbVar10 * 2 + 1) & 0x20) == 0) {
              pbVar10[1] = 0;
              if (*__s == 0) goto LAB_0816adc0;
              break;
            }
          }
          X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)&local_24);
          bVar3 = pbVar8[1];
joined_r0x0816ac6d:
          uVar4 = (uint)bVar3;
          __s = pbVar8 + 1;
          pbVar10 = __s;
          if ((bVar3 < 0xe) && ((0x2401U >> (uVar4 & 0x1f) & 1) != 0)) break;
        }
        else {
          uVar4 = (uint)pbVar8[1];
          pbVar10 = pbVar8 + 1;
          if ((pbVar8[1] < 0xe) && ((0x2401U >> (uVar4 & 0x1f) & 1) != 0)) goto LAB_0816ae80;
        }
        bVar3 = (byte)uVar4;
        pbVar8 = pbVar10;
      } while( true );
    }
    goto LAB_0816ae83;
  }
  ERR_put_error(0x22,0x6d,0x41,"v3_utl.c",0x121);
  goto LAB_0816ad5b;
joined_r0x0816ae27:
  if (pbVar8 == pbVar10) goto LAB_0816ae4e;
  if ((*(byte *)((int)puVar2 + (uint)*pbVar8 * 2 + 1) & 0x20) == 0) {
    pbVar8[1] = 0;
    if (*pbVar10 == 0) goto LAB_0816af10;
    goto LAB_0816ae4e;
  }
  pbVar8 = pbVar8 + -1;
  goto joined_r0x0816ae27;
LAB_0816ae4e:
  X509V3_add_value((char *)__s,(char *)pbVar10,(stack_st_CONF_VALUE **)&local_24);
  goto LAB_0816ae60;
LAB_0816ae80:
  bVar3 = *__s;
LAB_0816ae83:
  if (bVar3 != 0) {
    ppuVar5 = __ctype_b_loc();
    puVar2 = *ppuVar5;
    do {
      if ((*(byte *)((int)puVar2 + (uint)bVar3 * 2 + 1) & 0x20) == 0) {
        sVar6 = strlen((char *)__s);
        pbVar8 = __s + (sVar6 - 1);
        goto joined_r0x0816aec3;
      }
      __s = __s + 1;
      bVar3 = *__s;
    } while (bVar3 != 0);
  }
LAB_0816af20:
  iVar11 = 0x16c;
LAB_0816ada8:
  ERR_put_error(0x22,0x6d,0x6c,"v3_utl.c",iVar11);
  goto LAB_0816ad5b;
joined_r0x0816aec3:
  if (pbVar8 == __s) goto LAB_0816aeea;
  if ((*(byte *)((int)puVar2 + (uint)*pbVar8 * 2 + 1) & 0x20) == 0) {
    pbVar8[1] = 0;
    if (*__s == 0) goto LAB_0816af20;
    goto LAB_0816aeea;
  }
  pbVar8 = pbVar8 + -1;
  goto joined_r0x0816aec3;
LAB_0816aeea:
  X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)&local_24);
LAB_0816ae60:
  CRYPTO_free(ptr);
  p_Var7 = local_24;
  goto LAB_0816ad80;
  while( true ) {
    pbVar10 = pbVar10 + 1;
    bVar3 = *pbVar10;
    if (bVar3 == 0) break;
LAB_0816ae0e:
    if ((*(byte *)((int)puVar2 + (uint)bVar3 * 2 + 1) & 0x20) == 0) {
      sVar6 = strlen((char *)pbVar10);
      pbVar8 = pbVar10 + (sVar6 - 1);
      goto joined_r0x0816ae27;
    }
  }
LAB_0816af10:
  iVar11 = 0x162;
LAB_0816ad48:
  ERR_put_error(0x22,0x6d,0x6d,"v3_utl.c",iVar11);
LAB_0816ad5b:
  CRYPTO_free(ptr);
  sk_pop_free(local_24,X509V3_conf_free);
  p_Var7 = (_STACK *)0x0;
LAB_0816ad80:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (stack_st_CONF_VALUE *)p_Var7;
}

