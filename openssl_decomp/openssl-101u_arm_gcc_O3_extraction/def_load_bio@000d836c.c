
void def_load_bio(CONF *param_1,BIO *param_2,BUF_MEM **param_3)

{
  ushort uVar1;
  ushort uVar2;
  byte *pbVar3;
  BUF_MEM *pBVar4;
  BUF_MEM *str;
  BUF_MEM *pBVar5;
  lhash_st_CONF_VALUE *conf;
  BUF_MEM *pBVar6;
  size_t sVar7;
  byte *pbVar8;
  void *pvVar9;
  lhash_st_CONF_VALUE *plVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  size_t sVar14;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  char *pcVar19;
  uint uVar20;
  int iVar21;
  BUF_MEM *pBVar22;
  byte *pbVar23;
  BUF_MEM *pBVar24;
  uint uVar25;
  bool bVar26;
  BUF_MEM *local_48;
  BUF_MEM *local_44;
  BUF_MEM *local_40;
  char acStack_3c [16];
  int local_2c;
  size_t sVar15;
  
  uVar18 = 0;
  plVar10 = param_1->data;
  local_40 = (BUF_MEM *)0x0;
  local_2c = __stack_chk_guard;
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xe,0x79,7,"conf_def.c",0xe0);
    pBVar6 = str;
    goto LAB_000d83d8;
  }
  pBVar5 = (BUF_MEM *)BUF_strdup("default");
  local_40 = pBVar5;
  if (pBVar5 == (BUF_MEM *)0x0) {
    iVar11 = 0xe6;
  }
  else {
    pBVar5 = (BUF_MEM *)_CONF_new_data(param_1);
    if (pBVar5 != (BUF_MEM *)0x0) {
      pBVar5 = (BUF_MEM *)_CONF_new_section(param_1,(char *)local_40);
      if (pBVar5 != (BUF_MEM *)0x0) {
        iVar11 = 0;
        pBVar4 = (BUF_MEM *)0x0;
        local_44 = pBVar5;
LAB_000d8468:
        pBVar5 = pBVar4;
        pBVar6 = (BUF_MEM *)BUF_MEM_grow(str,iVar11 + 0x200);
        if (pBVar6 == (BUF_MEM *)0x0) goto LAB_000d8986;
        pcVar19 = str->data + iVar11;
        str->data[iVar11] = '\0';
        BIO_gets(param_2,pcVar19,0x1ff);
        pcVar19[0x1ff] = '\0';
        sVar7 = strlen(pcVar19);
        if ((uVar18 | sVar7) == 0) {
          BUF_MEM_free(str);
          if (local_40 == (BUF_MEM *)0x0) {
            pBVar6 = (BUF_MEM *)0x1;
          }
          else {
            CRYPTO_free(local_40);
            pBVar6 = (BUF_MEM *)0x1;
          }
          goto LAB_000d8440;
        }
        if ((int)sVar7 < 1) {
          uVar18 = 1;
          sVar14 = sVar7;
LAB_000d8516:
          if (sVar7 == 0) {
            uVar18 = 0;
          }
          else {
            uVar18 = uVar18 & 1;
          }
          sVar7 = sVar14;
          if (uVar18 != 0) goto LAB_000d8524;
LAB_000d84cc:
          pBVar5 = (BUF_MEM *)((int)&pBVar5->length + 1);
          uVar18 = 0;
          pcVar19[sVar14] = '\0';
        }
        else {
          sVar15 = sVar7;
          if (pcVar19[sVar7 - 1] == '\n' || pcVar19[sVar7 - 1] == '\r') {
            do {
              sVar14 = sVar15 - 1;
              if (sVar14 == 0) goto LAB_000d84cc;
              iVar21 = sVar15 - 2;
              sVar15 = sVar14;
            } while (pcVar19[iVar21] == '\n' || pcVar19[iVar21] == '\r');
            uVar18 = count_leading_zeroes(sVar7 - sVar14);
            uVar18 = uVar18 >> 5;
            goto LAB_000d8516;
          }
LAB_000d8524:
          uVar18 = 1;
          sVar14 = sVar7;
        }
        iVar21 = iVar11 + sVar14;
        pBVar4 = pBVar5;
        if (0 < iVar21) {
          iVar11 = iVar21 + -1;
          if ((-1 < (int)((uint)*(ushort *)
                                 ((int)param_1->meth_data + (uint)(byte)str->data[iVar11] * 2) <<
                         0x1a)) ||
             ((iVar21 != 1 &&
              ((int)((uint)*(ushort *)
                            ((int)param_1->meth_data + (uint)(byte)str->data[iVar21 + -2] * 2) <<
                    0x1a) < 0)))) goto LAB_000d8504;
LAB_000d8506:
          uVar18 = 1;
          goto LAB_000d8468;
        }
LAB_000d8504:
        iVar11 = iVar21;
        if (uVar18 != 0) goto LAB_000d8506;
        pBVar22 = (BUF_MEM *)str->data;
        pvVar9 = param_1->meth_data;
        uVar20 = (uint)*(byte *)&pBVar22->length;
        uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
        uVar25 = (uint)uVar1;
        pBVar6 = pBVar22;
        uVar17 = uVar20;
        uVar12 = uVar25;
        while ((uVar1 & 0x800) == 0) {
          if ((uVar1 & 0x10) == 0) goto LAB_000d8602;
          pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
          uVar17 = (uint)*(byte *)&pBVar6->length;
          uVar1 = *(ushort *)((int)pvVar9 + uVar17 * 2);
          uVar12 = (uint)uVar1;
        }
LAB_000d855e:
        *(undefined *)&pBVar6->length = 0;
        pvVar9 = param_1->meth_data;
        uVar20 = (uint)*(byte *)&pBVar22->length;
        uVar25 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
LAB_000d8574:
        while ((uVar25 & 0x18) == 0x10) {
          pBVar22 = (BUF_MEM *)((int)&pBVar22->length + 1);
          uVar20 = (uint)*(byte *)&pBVar22->length;
          uVar25 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
        }
        if ((uVar25 & 8) == 0) {
          pBVar6 = pBVar22;
          if (uVar20 != 0x5b) {
            do {
              if ((uVar25 & 0x20) == 0) {
                local_48 = (BUF_MEM *)(uVar25 & 0x307);
                if (local_48 == (BUF_MEM *)0x0) goto LAB_000d86a2;
              }
              else {
                do {
                  uVar20 = (uint)*(byte *)((int)&pBVar6->length + 1);
                  uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
                  if ((uVar1 & 8) == 0) {
                    uVar20 = (uint)*(byte *)((int)&pBVar6->length + 2);
                    pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 2);
                    uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
                  }
                  else {
                    pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
                  }
                  uVar25 = (uint)uVar1;
                } while ((uVar1 & 0x20) != 0);
                local_48 = (BUF_MEM *)(uVar25 & 0x307);
                if ((uVar1 & 0x307) == 0) goto LAB_000d86a2;
              }
              uVar20 = (uint)*(byte *)((int)&pBVar6->length + 1);
              uVar25 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
              pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
            } while( true );
          }
          uVar20 = (uint)*(byte *)((int)&pBVar22->length + 1);
          pbVar23 = (byte *)((int)&pBVar22->length + 1);
          uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
          while (uVar17 = (uint)uVar1, pbVar13 = pbVar23, pbVar8 = pbVar23, (uVar17 & 0x18) == 0x10)
          {
            pbVar23 = pbVar23 + 1;
            uVar20 = (uint)*pbVar23;
            uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
          }
          while( true ) {
            while( true ) {
              while ((int)(uVar17 << 0x1a) < 0) {
                uVar20 = (uint)pbVar13[1];
                uVar17 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
                if ((int)(uVar17 << 0x1c) < 0) {
                  pbVar13 = pbVar13 + 1;
                }
                else {
                  uVar20 = (uint)pbVar13[2];
                  uVar17 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
                  pbVar13 = pbVar13 + 2;
                }
              }
              pbVar3 = pbVar13;
              if ((uVar17 & 0x307) == 0) break;
              uVar20 = (uint)pbVar13[1];
              uVar17 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
              pbVar13 = pbVar13 + 1;
            }
            while ((uVar17 & 0x18) == 0x10) {
              uVar20 = (uint)pbVar3[1];
              pbVar3 = pbVar3 + 1;
              uVar17 = (uint)*(ushort *)((int)pvVar9 + uVar20 * 2);
            }
            if (uVar20 == 0x5d) break;
            if ((uVar20 == 0) ||
               (bVar26 = pbVar8 == pbVar3, pbVar13 = pbVar3, pbVar8 = pbVar3, bVar26)) {
              ERR_put_error(0xe,0x79,100,"conf_def.c",0x13e);
              pBVar6 = (BUF_MEM *)0x0;
              goto LAB_000d83d2;
            }
          }
          *pbVar13 = 0;
          pBVar6 = (BUF_MEM *)str_copy(param_1,0,&local_40,pbVar23);
          if (pBVar6 != (BUF_MEM *)0x0) {
            local_44 = (BUF_MEM *)_CONF_get_section(param_1,(char *)local_40);
            if ((local_44 != (BUF_MEM *)0x0) ||
               (local_44 = (BUF_MEM *)_CONF_new_section(param_1,(char *)local_40),
               local_44 != (BUF_MEM *)0x0)) goto LAB_000d87de;
            ERR_put_error(0xe,0x79,0x67,"conf_def.c",0x148);
            pBVar6 = local_44;
          }
          goto LAB_000d83d2;
        }
        goto LAB_000d87de;
      }
      ERR_put_error(0xe,0x79,0x67,"conf_def.c",0xf1);
      pBVar6 = pBVar5;
      goto LAB_000d83d2;
    }
    iVar11 = 0xeb;
  }
  ERR_put_error(0xe,0x79,0x41,"conf_def.c",iVar11);
  pBVar6 = pBVar5;
  goto LAB_000d83d2;
LAB_000d8602:
  if ((uVar12 & 0x80) == 0) {
    uVar16 = uVar17;
    if ((uVar12 & 0x400) == 0) {
      do {
        if ((uVar12 & 0x40) != 0) goto LAB_000d8824;
        if (-1 < (int)(uVar12 << 0x1a)) {
          if (-1 < (int)(uVar12 << 0x1c)) goto LAB_000d8818;
          goto LAB_000d8574;
        }
        uVar16 = (uint)*(byte *)((int)&pBVar6->length + 1);
        uVar1 = *(ushort *)((int)pvVar9 + uVar16 * 2);
        if ((uVar1 & 8) == 0) {
          uVar16 = (uint)*(byte *)((int)&pBVar6->length + 2);
          pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 2);
          uVar1 = *(ushort *)((int)pvVar9 + uVar16 * 2);
        }
        else {
          pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
        }
        uVar12 = (uint)uVar1;
        if ((uVar1 & 0x80) != 0) goto LAB_000d855e;
      } while ((uVar1 & 0x400) == 0);
    }
    while( true ) {
      pBVar24 = pBVar6;
      uVar17 = (uint)*(byte *)((int)&pBVar24->length + 1);
      pBVar6 = (BUF_MEM *)((int)&pBVar24->length + 1);
      uVar1 = *(ushort *)((int)pvVar9 + uVar17 * 2);
      uVar12 = (uint)uVar1;
      if ((uVar1 & 8) != 0) break;
      if (uVar16 == uVar17) {
        uVar17 = (uint)*(byte *)((int)&pBVar24->length + 2);
        if (uVar16 != uVar17) goto LAB_000d85fa;
        pBVar6 = (BUF_MEM *)((int)&pBVar24->length + 2);
      }
    }
    if (uVar16 == uVar17) {
      uVar17 = (uint)*(byte *)((int)&pBVar24->length + 2);
LAB_000d85fa:
      pBVar6 = (BUF_MEM *)((int)&pBVar24->length + 2);
      uVar12 = (uint)*(ushort *)((int)pvVar9 + (short)uVar17 * 2);
    }
    goto LAB_000d8602;
  }
  goto LAB_000d855e;
  while( true ) {
    uVar17 = (uint)*(byte *)((int)&pBVar24->length + 2);
    pBVar6 = (BUF_MEM *)((int)&pBVar24->length + 2);
    uVar1 = *(ushort *)((int)pvVar9 + uVar17 * 2);
    uVar12 = (uint)uVar1;
    if ((uVar1 & 8) != 0) break;
LAB_000d8824:
    do {
      pBVar24 = pBVar6;
      uVar17 = (uint)*(byte *)((int)&pBVar24->length + 1);
      pBVar6 = (BUF_MEM *)((int)&pBVar24->length + 1);
      uVar1 = *(ushort *)((int)pvVar9 + uVar17 * 2);
      uVar12 = (uint)uVar1;
      if ((uVar1 & 8) != 0) {
        if (uVar16 == uVar17) {
LAB_000d8818:
          uVar17 = (uint)*(byte *)((int)&pBVar6->length + 1);
          pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
          uVar12 = (uint)*(ushort *)((int)pvVar9 + uVar17 * 2);
        }
        goto LAB_000d8602;
      }
      if (uVar16 == uVar17) goto LAB_000d8818;
    } while (-1 < (int)(uVar12 << 0x1a));
  }
  goto LAB_000d8602;
LAB_000d86a2:
  pBVar24 = pBVar22;
  if ((uVar20 == 0x3a) && (*(char *)((int)&pBVar6->length + 1) == ':')) {
    pBVar24 = (BUF_MEM *)((int)&pBVar6->length + 2);
    *(char *)&pBVar6->length = (char)local_48;
    pvVar9 = param_1->meth_data;
    uVar20 = (uint)*(byte *)((int)&pBVar6->length + 2);
    uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
    pBVar6 = pBVar24;
    while( true ) {
      while ((uVar1 & 0x20) != 0) {
        uVar20 = (uint)*(byte *)((int)&pBVar6->length + 1);
        uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
        if ((uVar1 & 8) == 0) {
          uVar20 = (uint)*(byte *)((int)&pBVar6->length + 2);
          pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 2);
          uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
        }
        else {
          pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
        }
      }
      uVar25 = (uint)uVar1;
      local_48 = pBVar22;
      if ((uVar1 & 0x307) == 0) break;
      uVar20 = (uint)*(byte *)((int)&pBVar6->length + 1);
      pBVar6 = (BUF_MEM *)((int)&pBVar6->length + 1);
      uVar1 = *(ushort *)((int)pvVar9 + uVar20 * 2);
    }
  }
  pBVar22 = pBVar6;
  if ((uVar25 & 0x18) == 0x10) {
    do {
      pBVar22 = (BUF_MEM *)((int)&pBVar22->length + 1);
      uVar20 = (uint)*(byte *)&pBVar22->length;
    } while ((*(ushort *)((int)pvVar9 + uVar20 * 2) & 0x18) == 0x10);
  }
  if (uVar20 != 0x3d) {
    ERR_put_error(0xe,0x79,0x65,"conf_def.c",0x159);
    pBVar6 = (BUF_MEM *)0x0;
    goto LAB_000d83d2;
  }
  *(undefined *)&pBVar6->length = 0;
  pbVar13 = (byte *)((int)&pBVar22->length + 1);
  pvVar9 = param_1->meth_data;
  uVar1 = *(ushort *)((int)pvVar9 + (uint)*(byte *)((int)&pBVar22->length + 1) * 2);
  pbVar23 = pbVar13;
  uVar2 = uVar1;
  while ((uVar2 & 0x18) == 0x10) {
    pbVar23 = pbVar23 + 1;
    uVar2 = *(ushort *)((int)pvVar9 + (uint)*pbVar23 * 2);
  }
  if ((uVar1 & 8) == 0) {
    do {
      pbVar13 = pbVar13 + 1;
    } while (-1 < (int)((uint)*(ushort *)((int)pvVar9 + (uint)*pbVar13 * 2) << 0x1c));
  }
  pbVar8 = pbVar13 + -1;
  if ((pbVar8 != pbVar23) && ((*(ushort *)((int)pvVar9 + (uint)pbVar13[-1] * 2) & 0x10) != 0)) {
    pbVar13 = pbVar13 + -2;
    do {
      pbVar8 = pbVar13;
      if (pbVar8 == pbVar23) break;
      pbVar13 = pbVar8 + -1;
    } while ((int)((uint)*(ushort *)((int)pvVar9 + (uint)*pbVar8 * 2) << 0x1b) < 0);
  }
  pbVar8[1] = 0;
  pBVar6 = (BUF_MEM *)CRYPTO_malloc(0xc,"conf_def.c",0x167);
  if (pBVar6 == (BUF_MEM *)0x0) {
    iVar11 = 0x168;
  }
  else {
    if (local_48 == (BUF_MEM *)0x0) {
      local_48 = local_40;
    }
    sVar7 = strlen((char *)pBVar24);
    pcVar19 = (char *)CRYPTO_malloc(sVar7 + 1,"conf_def.c",0x16d);
    pBVar6->max = 0;
    pBVar6->data = pcVar19;
    if (pcVar19 == (char *)0x0) {
      iVar11 = 0x170;
    }
    else {
      sVar7 = strlen((char *)pBVar24);
      BUF_strlcpy(pcVar19,(char *)pBVar24,sVar7 + 1);
      iVar11 = str_copy(param_1,local_48,&pBVar6->max,pbVar23);
      if (iVar11 == 0) goto LAB_000d83d2;
      iVar11 = strcmp((char *)local_48,(char *)local_40);
      pBVar22 = local_44;
      if (((iVar11 != 0) &&
          (pBVar22 = (BUF_MEM *)_CONF_get_section(param_1,(char *)local_48),
          pBVar22 == (BUF_MEM *)0x0)) &&
         (pBVar22 = (BUF_MEM *)_CONF_new_section(param_1,(char *)local_48),
         pBVar22 == (BUF_MEM *)0x0)) {
        ERR_put_error(0xe,0x79,0x67,"conf_def.c",0x17d);
        goto LAB_000d83d2;
      }
      iVar11 = _CONF_add_string(param_1,(CONF_VALUE *)pBVar22,(CONF_VALUE *)pBVar6);
      if (iVar11 != 0) {
LAB_000d87de:
        iVar11 = 0;
        goto LAB_000d8468;
      }
      iVar11 = 0x184;
    }
  }
  ERR_put_error(0xe,0x79,0x41,"conf_def.c",iVar11);
  goto LAB_000d83d2;
LAB_000d8986:
  ERR_put_error(0xe,0x79,7,"conf_def.c",0xf9);
LAB_000d83d2:
  BUF_MEM_free(str);
  str = pBVar5;
LAB_000d83d8:
  if (local_40 != (BUF_MEM *)0x0) {
    CRYPTO_free(local_40);
  }
  if (param_3 != (BUF_MEM **)0x0) {
    *param_3 = str;
  }
  BIO_snprintf(acStack_3c,0xd,"%ld",str);
  ERR_add_error_data(2,"line ",acStack_3c);
  conf = param_1->data;
  if ((conf != plVar10) && (conf != (lhash_st_CONF_VALUE *)0x0)) {
    CONF_free(conf);
    param_1->data = (lhash_st_CONF_VALUE *)0x0;
  }
  if (pBVar6 != (BUF_MEM *)0x0) {
    if (pBVar6->data != (char *)0x0) {
      CRYPTO_free(pBVar6->data);
    }
    if ((void *)pBVar6->max != (void *)0x0) {
      CRYPTO_free((void *)pBVar6->max);
    }
    CRYPTO_free(pBVar6);
    pBVar6 = (BUF_MEM *)0x0;
  }
LAB_000d8440:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar6);
}

