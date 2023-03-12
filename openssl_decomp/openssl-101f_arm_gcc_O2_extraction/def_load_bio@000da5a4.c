
void def_load_bio(CONF *param_1,BIO *param_2,BUF_MEM **param_3)

{
  ushort uVar1;
  ushort uVar2;
  BUF_MEM *pBVar3;
  BUF_MEM *str;
  BUF_MEM *dst;
  lhash_st_CONF_VALUE *conf;
  BUF_MEM *pBVar4;
  size_t sVar5;
  byte *pbVar6;
  lhash_st_CONF_VALUE *plVar7;
  void *pvVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  size_t sVar12;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  char *pcVar17;
  uint uVar18;
  int iVar19;
  BUF_MEM *pBVar20;
  byte *pbVar21;
  BUF_MEM *pBVar22;
  uint uVar23;
  BUF_MEM *local_48;
  BUF_MEM *local_44;
  BUF_MEM *local_40;
  char acStack_3c [16];
  int local_2c;
  size_t sVar13;
  
  plVar7 = param_1->data;
  uVar16 = 0;
  local_40 = (BUF_MEM *)0x0;
  local_2c = __TMC_END__;
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xe,0x79,7,"conf_def.c",0xe3);
    pBVar4 = str;
    goto LAB_000da622;
  }
  dst = (BUF_MEM *)CRYPTO_malloc(10,"conf_def.c",0xe7);
  local_40 = dst;
  if (dst == (BUF_MEM *)0x0) {
    iVar9 = 0xea;
  }
  else {
    BUF_strlcpy((char *)dst,"default",10);
    dst = (BUF_MEM *)_CONF_new_data(param_1);
    if (dst != (BUF_MEM *)0x0) {
      dst = (BUF_MEM *)_CONF_new_section(param_1,(char *)local_40);
      if (dst != (BUF_MEM *)0x0) {
        iVar9 = 0;
        pBVar3 = (BUF_MEM *)0x0;
        local_48 = dst;
LAB_000da6b2:
        dst = pBVar3;
        pBVar4 = (BUF_MEM *)BUF_MEM_grow(str,iVar9 + 0x200);
        if (pBVar4 == (BUF_MEM *)0x0) goto LAB_000dab6a;
        pcVar17 = str->data + iVar9;
        str->data[iVar9] = '\0';
        BIO_gets(param_2,pcVar17,0x1ff);
        pcVar17[0x1ff] = '\0';
        sVar5 = strlen(pcVar17);
        if ((uVar16 | sVar5) == 0) {
          BUF_MEM_free(str);
          if (local_40 == (BUF_MEM *)0x0) {
            pBVar4 = (BUF_MEM *)0x1;
          }
          else {
            CRYPTO_free(local_40);
            pBVar4 = (BUF_MEM *)0x1;
          }
          goto LAB_000da68a;
        }
        if ((int)sVar5 < 1) {
          uVar16 = 1;
          sVar12 = sVar5;
LAB_000da760:
          if (sVar5 == 0) {
            uVar16 = 0;
          }
          else {
            uVar16 = uVar16 & 1;
          }
          sVar5 = sVar12;
          if (uVar16 != 0) goto LAB_000da76e;
LAB_000da716:
          dst = (BUF_MEM *)((int)&dst->length + 1);
          uVar16 = 0;
          pcVar17[sVar12] = '\0';
        }
        else {
          sVar13 = sVar5;
          if (pcVar17[sVar5 - 1] == '\r' || pcVar17[sVar5 - 1] == '\n') {
            do {
              sVar12 = sVar13 - 1;
              if (sVar12 == 0) goto LAB_000da716;
              iVar19 = sVar13 - 2;
              sVar13 = sVar12;
            } while (pcVar17[iVar19] == '\n' || pcVar17[iVar19] == '\r');
            uVar16 = count_leading_zeroes(sVar5 - sVar12);
            uVar16 = uVar16 >> 5;
            goto LAB_000da760;
          }
LAB_000da76e:
          uVar16 = 1;
          sVar12 = sVar5;
        }
        iVar19 = iVar9 + sVar12;
        pBVar3 = dst;
        if (0 < iVar19) {
          iVar9 = iVar19 + -1;
          if ((-1 < (int)((uint)*(ushort *)
                                 ((int)param_1->meth_data + (uint)(byte)str->data[iVar9] * 2) <<
                         0x1a)) ||
             ((iVar19 != 1 &&
              ((int)((uint)*(ushort *)
                            ((int)param_1->meth_data + (uint)(byte)str->data[iVar19 + -2] * 2) <<
                    0x1a) < 0)))) goto LAB_000da74e;
LAB_000da750:
          uVar16 = 1;
          goto LAB_000da6b2;
        }
LAB_000da74e:
        iVar9 = iVar19;
        if (uVar16 != 0) goto LAB_000da750;
        pBVar20 = (BUF_MEM *)str->data;
        pvVar8 = param_1->meth_data;
        uVar18 = (uint)*(byte *)&pBVar20->length;
        uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
        uVar23 = (uint)uVar1;
        pBVar4 = pBVar20;
        uVar15 = uVar18;
        uVar10 = uVar23;
        while ((uVar1 & 0x800) == 0) {
          if ((uVar1 & 0x10) == 0) goto LAB_000da84a;
          pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
          uVar15 = (uint)*(byte *)&pBVar4->length;
          uVar1 = *(ushort *)((int)pvVar8 + uVar15 * 2);
          uVar10 = (uint)uVar1;
        }
LAB_000da7a8:
        *(undefined *)&pBVar4->length = 0;
        pvVar8 = param_1->meth_data;
        uVar18 = (uint)*(byte *)&pBVar20->length;
        uVar23 = (uint)*(ushort *)((int)pvVar8 + uVar18 * 2);
LAB_000da7be:
        while ((uVar23 & 0x18) == 0x10) {
          pBVar20 = (BUF_MEM *)((int)&pBVar20->length + 1);
          uVar18 = (uint)*(byte *)&pBVar20->length;
          uVar23 = (uint)*(ushort *)((int)pvVar8 + uVar18 * 2);
        }
        if ((uVar23 & 8) == 0) {
          pBVar4 = pBVar20;
          if (uVar18 != 0x5b) {
            do {
              if ((uVar23 & 0x20) == 0) {
                local_44 = (BUF_MEM *)(uVar23 & 0x307);
                if (local_44 == (BUF_MEM *)0x0) goto LAB_000da8ea;
              }
              else {
                do {
                  uVar18 = (uint)*(byte *)((int)&pBVar4->length + 1);
                  uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
                  if ((uVar1 & 8) == 0) {
                    uVar18 = (uint)*(byte *)((int)&pBVar4->length + 2);
                    pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 2);
                    uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
                  }
                  else {
                    pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
                  }
                  uVar23 = (uint)uVar1;
                } while ((uVar1 & 0x20) != 0);
                local_44 = (BUF_MEM *)(uVar23 & 0x307);
                if ((uVar1 & 0x307) == 0) goto LAB_000da8ea;
              }
              uVar18 = (uint)*(byte *)((int)&pBVar4->length + 1);
              uVar23 = (uint)*(ushort *)((int)pvVar8 + uVar18 * 2);
              pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
            } while( true );
          }
          pBVar4 = (BUF_MEM *)(uint)*(byte *)((int)&pBVar20->length + 1);
          pbVar21 = (byte *)((int)&pBVar20->length + 1);
          uVar1 = *(ushort *)((int)pvVar8 + (int)pBVar4 * 2);
          while (uVar18 = (uint)uVar1, pbVar11 = pbVar21, (uVar18 & 0x18) == 0x10) {
            pbVar21 = pbVar21 + 1;
            pBVar4 = (BUF_MEM *)(uint)*pbVar21;
            uVar1 = *(ushort *)((int)pvVar8 + (int)pBVar4 * 2);
          }
          while( true ) {
            while( true ) {
              while ((int)(uVar18 << 0x1a) < 0) {
                pBVar4 = (BUF_MEM *)(uint)pbVar11[1];
                uVar18 = (uint)*(ushort *)((int)pvVar8 + (int)pBVar4 * 2);
                if ((int)(uVar18 << 0x1c) < 0) {
                  pbVar11 = pbVar11 + 1;
                }
                else {
                  pBVar4 = (BUF_MEM *)(uint)pbVar11[2];
                  uVar18 = (uint)*(ushort *)((int)pvVar8 + (int)pBVar4 * 2);
                  pbVar11 = pbVar11 + 2;
                }
              }
              pbVar6 = pbVar11;
              if ((uVar18 & 0x307) == 0) break;
              pBVar4 = (BUF_MEM *)(uint)pbVar11[1];
              uVar18 = (uint)*(ushort *)((int)pvVar8 + (int)pBVar4 * 2);
              pbVar11 = pbVar11 + 1;
            }
            while ((uVar18 & 0x18) == 0x10) {
              pBVar4 = (BUF_MEM *)(uint)pbVar6[1];
              pbVar6 = pbVar6 + 1;
              uVar18 = (uint)*(ushort *)((int)pvVar8 + (int)pBVar4 * 2);
            }
            if (pBVar4 == (BUF_MEM *)0x5d) break;
            pbVar11 = pbVar6;
            if (pBVar4 == (BUF_MEM *)0x0) {
              ERR_put_error(0xe,0x79,100,"conf_def.c",0x14a);
              goto LAB_000da61c;
            }
          }
          *pbVar11 = 0;
          pBVar4 = (BUF_MEM *)str_copy(param_1,0,&local_40,pbVar21);
          if (pBVar4 != (BUF_MEM *)0x0) {
            local_48 = (BUF_MEM *)_CONF_get_section(param_1,(char *)local_40);
            if ((local_48 != (BUF_MEM *)0x0) ||
               (local_48 = (BUF_MEM *)_CONF_new_section(param_1,(char *)local_40),
               local_48 != (BUF_MEM *)0x0)) goto LAB_000daa26;
            ERR_put_error(0xe,0x79,0x67,"conf_def.c",0x154);
            pBVar4 = local_48;
          }
          goto LAB_000da61c;
        }
        goto LAB_000daa26;
      }
      ERR_put_error(0xe,0x79,0x67,"conf_def.c",0xf9);
      pBVar4 = dst;
      goto LAB_000da61c;
    }
    iVar9 = 0xf1;
  }
  ERR_put_error(0xe,0x79,0x41,"conf_def.c",iVar9);
  pBVar4 = dst;
  goto LAB_000da61c;
LAB_000da84a:
  if ((uVar10 & 0x80) == 0) {
    uVar14 = uVar15;
    if ((uVar10 & 0x400) == 0) {
      do {
        if ((uVar10 & 0x40) != 0) goto LAB_000daa66;
        if (-1 < (int)(uVar10 << 0x1a)) {
          if (-1 < (int)(uVar10 << 0x1c)) goto LAB_000daa5a;
          goto LAB_000da7be;
        }
        uVar14 = (uint)*(byte *)((int)&pBVar4->length + 1);
        uVar1 = *(ushort *)((int)pvVar8 + uVar14 * 2);
        if ((uVar1 & 8) == 0) {
          uVar14 = (uint)*(byte *)((int)&pBVar4->length + 2);
          pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 2);
          uVar1 = *(ushort *)((int)pvVar8 + uVar14 * 2);
        }
        else {
          pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
        }
        uVar10 = (uint)uVar1;
        if ((uVar1 & 0x80) != 0) goto LAB_000da7a8;
      } while ((uVar1 & 0x400) == 0);
    }
    while( true ) {
      pBVar22 = pBVar4;
      uVar15 = (uint)*(byte *)((int)&pBVar22->length + 1);
      pBVar4 = (BUF_MEM *)((int)&pBVar22->length + 1);
      uVar1 = *(ushort *)((int)pvVar8 + uVar15 * 2);
      uVar10 = (uint)uVar1;
      if ((uVar1 & 8) != 0) break;
      if (uVar14 == uVar15) {
        uVar15 = (uint)*(byte *)((int)&pBVar22->length + 2);
        if (uVar14 != uVar15) goto LAB_000da842;
        pBVar4 = (BUF_MEM *)((int)&pBVar22->length + 2);
      }
    }
    if (uVar14 == uVar15) {
      uVar15 = (uint)*(byte *)((int)&pBVar22->length + 2);
LAB_000da842:
      pBVar4 = (BUF_MEM *)((int)&pBVar22->length + 2);
      uVar10 = (uint)*(ushort *)((int)pvVar8 + (short)uVar15 * 2);
    }
    goto LAB_000da84a;
  }
  goto LAB_000da7a8;
  while( true ) {
    uVar15 = (uint)*(byte *)((int)&pBVar22->length + 2);
    pBVar4 = (BUF_MEM *)((int)&pBVar22->length + 2);
    uVar1 = *(ushort *)((int)pvVar8 + uVar15 * 2);
    uVar10 = (uint)uVar1;
    if ((uVar1 & 8) != 0) break;
LAB_000daa66:
    do {
      pBVar22 = pBVar4;
      uVar15 = (uint)*(byte *)((int)&pBVar22->length + 1);
      pBVar4 = (BUF_MEM *)((int)&pBVar22->length + 1);
      uVar1 = *(ushort *)((int)pvVar8 + uVar15 * 2);
      uVar10 = (uint)uVar1;
      if ((uVar1 & 8) != 0) {
        if (uVar14 == uVar15) {
LAB_000daa5a:
          uVar15 = (uint)*(byte *)((int)&pBVar4->length + 1);
          pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
          uVar10 = (uint)*(ushort *)((int)pvVar8 + uVar15 * 2);
        }
        goto LAB_000da84a;
      }
      if (uVar14 == uVar15) goto LAB_000daa5a;
    } while (-1 < (int)(uVar10 << 0x1a));
  }
  goto LAB_000da84a;
LAB_000da8ea:
  pBVar22 = pBVar20;
  if ((uVar18 == 0x3a) && (*(char *)((int)&pBVar4->length + 1) == ':')) {
    pBVar22 = (BUF_MEM *)((int)&pBVar4->length + 2);
    *(char *)&pBVar4->length = (char)local_44;
    pvVar8 = param_1->meth_data;
    uVar18 = (uint)*(byte *)((int)&pBVar4->length + 2);
    uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
    pBVar4 = pBVar22;
    while( true ) {
      while ((uVar1 & 0x20) != 0) {
        uVar18 = (uint)*(byte *)((int)&pBVar4->length + 1);
        uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
        if ((uVar1 & 8) == 0) {
          uVar18 = (uint)*(byte *)((int)&pBVar4->length + 2);
          pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 2);
          uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
        }
        else {
          pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
        }
      }
      uVar23 = (uint)uVar1;
      local_44 = pBVar20;
      if ((uVar1 & 0x307) == 0) break;
      uVar18 = (uint)*(byte *)((int)&pBVar4->length + 1);
      pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 1);
      uVar1 = *(ushort *)((int)pvVar8 + uVar18 * 2);
    }
  }
  pBVar20 = pBVar4;
  if ((uVar23 & 0x18) == 0x10) {
    do {
      pBVar20 = (BUF_MEM *)((int)&pBVar20->length + 1);
      uVar18 = (uint)*(byte *)&pBVar20->length;
    } while ((*(ushort *)((int)pvVar8 + uVar18 * 2) & 0x18) == 0x10);
  }
  if (uVar18 != 0x3d) {
    ERR_put_error(0xe,0x79,0x65,"conf_def.c",0x16a);
    pBVar4 = (BUF_MEM *)0x0;
    goto LAB_000da61c;
  }
  *(undefined *)&pBVar4->length = 0;
  pbVar11 = (byte *)((int)&pBVar20->length + 1);
  pvVar8 = param_1->meth_data;
  uVar1 = *(ushort *)((int)pvVar8 + (uint)*(byte *)((int)&pBVar20->length + 1) * 2);
  pbVar21 = pbVar11;
  uVar2 = uVar1;
  while ((uVar2 & 0x18) == 0x10) {
    pbVar21 = pbVar21 + 1;
    uVar2 = *(ushort *)((int)pvVar8 + (uint)*pbVar21 * 2);
  }
  if ((uVar1 & 8) == 0) {
    do {
      pbVar11 = pbVar11 + 1;
    } while (-1 < (int)((uint)*(ushort *)((int)pvVar8 + (uint)*pbVar11 * 2) << 0x1c));
  }
  pbVar6 = pbVar11 + -1;
  if ((pbVar6 != pbVar21) && ((*(ushort *)((int)pvVar8 + (uint)pbVar11[-1] * 2) & 0x10) != 0)) {
    pbVar11 = pbVar11 + -2;
    do {
      pbVar6 = pbVar11;
      if (pbVar6 == pbVar21) break;
      pbVar11 = pbVar6 + -1;
    } while ((int)((uint)*(ushort *)((int)pvVar8 + (uint)*pbVar6 * 2) << 0x1b) < 0);
  }
  pbVar6[1] = 0;
  pBVar4 = (BUF_MEM *)CRYPTO_malloc(0xc,"conf_def.c",0x178);
  if (pBVar4 == (BUF_MEM *)0x0) {
    iVar9 = 0x17b;
  }
  else {
    if (local_44 == (BUF_MEM *)0x0) {
      local_44 = local_40;
    }
    sVar5 = strlen((char *)pBVar22);
    pcVar17 = (char *)CRYPTO_malloc(sVar5 + 1,"conf_def.c",0x17f);
    pBVar4->max = 0;
    pBVar4->data = pcVar17;
    if (pcVar17 == (char *)0x0) {
      iVar9 = 0x184;
    }
    else {
      sVar5 = strlen((char *)pBVar22);
      BUF_strlcpy(pcVar17,(char *)pBVar22,sVar5 + 1);
      iVar9 = str_copy(param_1,local_44,&pBVar4->max,pbVar21);
      if (iVar9 == 0) goto LAB_000da61c;
      iVar9 = strcmp((char *)local_44,(char *)local_40);
      pBVar20 = local_48;
      if (((iVar9 != 0) &&
          (pBVar20 = (BUF_MEM *)_CONF_get_section(param_1,(char *)local_44),
          pBVar20 == (BUF_MEM *)0x0)) &&
         (pBVar20 = (BUF_MEM *)_CONF_new_section(param_1,(char *)local_44),
         pBVar20 == (BUF_MEM *)0x0)) {
        ERR_put_error(0xe,0x79,0x67,"conf_def.c",0x192);
        goto LAB_000da61c;
      }
      iVar9 = _CONF_add_string(param_1,(CONF_VALUE *)pBVar20,(CONF_VALUE *)pBVar4);
      if (iVar9 != 0) {
LAB_000daa26:
        iVar9 = 0;
        goto LAB_000da6b2;
      }
      iVar9 = 0x19c;
    }
  }
  ERR_put_error(0xe,0x79,0x41,"conf_def.c",iVar9);
  goto LAB_000da61c;
LAB_000dab6a:
  ERR_put_error(0xe,0x79,7,"conf_def.c",0x103);
LAB_000da61c:
  BUF_MEM_free(str);
  str = dst;
LAB_000da622:
  if (local_40 != (BUF_MEM *)0x0) {
    CRYPTO_free(local_40);
  }
  if (param_3 != (BUF_MEM **)0x0) {
    *param_3 = str;
  }
  BIO_snprintf(acStack_3c,0xd,"%ld",str);
  ERR_add_error_data(2,"line ",acStack_3c);
  conf = param_1->data;
  if ((conf != plVar7) && (conf != (lhash_st_CONF_VALUE *)0x0)) {
    CONF_free(conf);
    param_1->data = (lhash_st_CONF_VALUE *)0x0;
  }
  if (pBVar4 != (BUF_MEM *)0x0) {
    if (pBVar4->data != (char *)0x0) {
      CRYPTO_free(pBVar4->data);
    }
    if ((void *)pBVar4->max != (void *)0x0) {
      CRYPTO_free((void *)pBVar4->max);
    }
    CRYPTO_free(pBVar4);
    pBVar4 = (BUF_MEM *)0x0;
  }
LAB_000da68a:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar4);
}

