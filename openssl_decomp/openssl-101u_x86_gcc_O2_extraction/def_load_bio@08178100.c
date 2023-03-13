
undefined4 def_load_bio(CONF *param_1,BIO *param_2,int *param_3)

{
  lhash_st_CONF_VALUE *plVar1;
  lhash_st_CONF_VALUE *conf;
  char cVar2;
  BUF_MEM *str;
  int iVar3;
  size_t sVar4;
  CONF_VALUE *section;
  byte *pbVar5;
  void *pvVar6;
  byte bVar7;
  ushort uVar8;
  size_t sVar9;
  byte *pbVar11;
  uint uVar12;
  byte *pbVar13;
  ushort uVar14;
  uint uVar15;
  CONF_VALUE *value;
  char *pcVar16;
  byte *pbVar17;
  int in_GS_OFFSET;
  bool bVar18;
  int iVar19;
  undefined4 local_64;
  byte *local_5c;
  int local_54;
  byte *local_50;
  CONF_VALUE *local_40;
  byte *local_34;
  char local_2d [13];
  int local_20;
  size_t sVar10;
  
  local_34 = (byte *)0x0;
  plVar1 = param_1->data;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    value = (CONF_VALUE *)0x0;
    ERR_put_error(0xe,0x79,7,"conf_def.c",0xe0);
    local_54 = 0;
    goto LAB_081781b3;
  }
  local_34 = (byte *)BUF_strdup("default");
  if (local_34 == (byte *)0x0) {
    iVar19 = 0xe6;
    iVar3 = 0x41;
LAB_0817818e:
    value = (CONF_VALUE *)0x0;
    ERR_put_error(0xe,0x79,iVar3,"conf_def.c",iVar19);
    local_54 = 0;
  }
  else {
    iVar3 = _CONF_new_data(param_1);
    if (iVar3 == 0) {
      iVar19 = 0xeb;
      iVar3 = 0x41;
      goto LAB_0817818e;
    }
    local_40 = _CONF_new_section(param_1,(char *)local_34);
    if (local_40 == (CONF_VALUE *)0x0) {
      iVar19 = 0xf1;
      iVar3 = 0x67;
      goto LAB_0817818e;
    }
    local_54 = 0;
    uVar12 = 0;
    uVar15 = 0;
LAB_081782a8:
    while( true ) {
      iVar3 = BUF_MEM_grow(str,uVar12 + 0x200);
      if (iVar3 == 0) {
        iVar19 = 0xf9;
        iVar3 = 7;
        goto LAB_08178932;
      }
      pcVar16 = str->data + uVar12;
      *pcVar16 = '\0';
      BIO_gets(param_2,pcVar16,0x1ff);
      pcVar16[0x1ff] = '\0';
      sVar4 = strlen(pcVar16);
      if ((uVar15 | sVar4) == 0) {
        BUF_MEM_free(str);
        local_64 = 1;
        if (local_34 != (byte *)0x0) {
          local_64 = 1;
          CRYPTO_free(local_34);
        }
        goto LAB_0817825d;
      }
      if ((int)sVar4 < 1) break;
      sVar10 = sVar4;
      if ((pcVar16[sVar4 - 1] == '\n') || (pcVar16[sVar4 - 1] == '\r')) {
        do {
          sVar9 = sVar10 - 1;
          if (sVar9 == 0) goto LAB_08178398;
          iVar3 = sVar10 - 2;
          sVar10 = sVar9;
        } while ((pcVar16[iVar3] == '\r') || (pcVar16[iVar3] == '\n'));
        bVar18 = sVar4 == sVar9;
        goto LAB_08178339;
      }
      uVar12 = uVar12 + sVar4;
      if (0 < (int)uVar12) {
        bVar18 = true;
        goto LAB_08178350;
      }
LAB_08178a28:
      uVar15 = 1;
    }
    bVar18 = true;
    sVar9 = sVar4;
LAB_08178339:
    if ((sVar4 == 0) || (!bVar18)) {
LAB_08178398:
      uVar12 = uVar12 + sVar9;
      pcVar16[sVar9] = '\0';
      local_54 = local_54 + 1;
      bVar18 = false;
      if (0 < (int)uVar12) goto LAB_08178350;
      local_5c = (byte *)str->data;
    }
    else {
      uVar12 = uVar12 + sVar9;
      bVar18 = true;
      if ((int)uVar12 < 1) goto LAB_08178a28;
LAB_08178350:
      local_5c = (byte *)str->data;
      if (((*(byte *)((int)param_1->meth_data + (uint)local_5c[uVar12 - 1] * 2) & 0x20) != 0) &&
         ((uVar12 == 1 ||
          ((*(byte *)((int)param_1->meth_data + (uint)(local_5c + (uVar12 - 1))[-1] * 2) & 0x20) ==
           0)))) {
        uVar12 = uVar12 - 1;
        uVar15 = 1;
        goto LAB_081782a8;
      }
      uVar15 = 1;
      if (bVar18) goto LAB_081782a8;
    }
    bVar7 = *local_5c;
    pvVar6 = param_1->meth_data;
    uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
    pbVar13 = local_5c;
    local_50 = local_5c;
    if ((uVar14 & 0x800) == 0) {
      if ((uVar14 & 0x10) == 0) {
        uVar12 = (uint)bVar7;
        uVar8 = uVar14;
      }
      else {
        do {
          pbVar13 = pbVar13 + 1;
          uVar12 = (uint)*pbVar13;
          uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
          if ((uVar8 & 0x800) != 0) goto LAB_0817840a;
        } while ((uVar8 & 0x10) != 0);
      }
LAB_081785d8:
      if ((uVar8 & 0x80) == 0) {
        while (cVar2 = (char)uVar12, (uVar8 & 0x400) == 0) {
          if ((uVar8 & 0x40) != 0) {
            goto LAB_081786c8;
          }
          if ((uVar8 & 0x20) == 0) {
            if ((uVar8 & 8) != 0) goto joined_r0x08178424;
            uVar12 = (uint)pbVar13[1];
            pbVar13 = pbVar13 + 1;
            uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
            goto LAB_081785d8;
          }
          uVar12 = (uint)pbVar13[1];
          uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
          if ((uVar8 & 8) == 0) {
            uVar12 = (uint)pbVar13[2];
            pbVar13 = pbVar13 + 2;
            uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
            goto LAB_081785d8;
          }
          pbVar13 = pbVar13 + 1;
          if ((uVar8 & 0x80) != 0) goto LAB_0817860f;
        }
        uVar12 = (uint)pbVar13[1];
        uVar15 = (uint)cVar2;
        uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
        while( true ) {
          pbVar13 = pbVar13 + 1;
          if ((uVar8 & 8) != 0) break;
          if (uVar15 == (int)(char)uVar12) {
            uVar12 = (uint)(char)pbVar13[1];
            if (uVar15 != uVar12) goto LAB_081786af;
            pbVar13 = pbVar13 + 1;
          }
          uVar12 = (uint)pbVar13[1];
          uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
        }
        if (uVar15 == (int)(char)uVar12) {
          uVar12 = (uint)pbVar13[1];
LAB_081786af:
          pbVar13 = pbVar13 + 1;
          uVar8 = *(ushort *)((int)pvVar6 + (uVar12 & 0xff) * 2);
        }
        goto LAB_081785d8;
      }
LAB_0817860f:
      *pbVar13 = 0;
      bVar7 = *local_5c;
      pvVar6 = param_1->meth_data;
      uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
    }
    else {
LAB_0817840a:
      *pbVar13 = 0;
      bVar7 = *local_5c;
      pvVar6 = param_1->meth_data;
      uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
    }
joined_r0x08178424:
    while ((uVar14 & 0x18) == 0x10) {
      local_50 = local_50 + 1;
      bVar7 = *local_50;
      uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
    }
    if ((uVar14 & 8) != 0) {
LAB_081785bf:
      uVar12 = 0;
      uVar15 = 0;
      goto LAB_081782a8;
    }
    uVar12 = (uint)bVar7;
    pbVar13 = local_50;
    if (bVar7 != 0x5b) {
LAB_08178470:
      bVar7 = (byte)uVar12;
      while ((uVar14 & 0x20) != 0) {
        bVar7 = pbVar13[1];
        uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
        if ((uVar14 & 8) == 0) {
          uVar12 = (uint)pbVar13[2];
          uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
          pbVar13 = pbVar13 + 2;
          goto LAB_08178470;
        }
        pbVar13 = pbVar13 + 1;
      }
      if ((uVar14 & 0x307) != 0) {
        uVar12 = (uint)pbVar13[1];
        uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
        pbVar13 = pbVar13 + 1;
        goto LAB_08178470;
      }
      pbVar5 = pbVar13;
      pbVar17 = (byte *)0x0;
      pbVar11 = local_50;
      if (bVar7 == 0x3a) {
        if (pbVar13[1] == 0x3a) {
          *pbVar13 = 0;
          pbVar11 = pbVar13 + 2;
          uVar12 = (uint)pbVar13[2];
          pvVar6 = param_1->meth_data;
          uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
          pbVar13 = pbVar11;
LAB_08178adc:
          bVar7 = (byte)uVar12;
          while ((uVar14 & 0x20) != 0) {
            bVar7 = pbVar13[1];
            uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
            if ((uVar14 & 8) == 0) {
              uVar12 = (uint)pbVar13[2];
              pbVar13 = pbVar13 + 2;
              uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
              goto LAB_08178adc;
            }
            pbVar13 = pbVar13 + 1;
          }
          pbVar5 = pbVar13;
          pbVar17 = local_50;
          if ((uVar14 & 0x307) != 0) {
            uVar12 = (uint)pbVar13[1];
            pbVar13 = pbVar13 + 1;
            uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
            goto LAB_08178adc;
          }
          goto joined_r0x0817875a;
        }
        if ((uVar14 & 0x18) == 0x10) {
          pbVar17 = (byte *)0x0;
          goto LAB_08178768;
        }
      }
      else {
joined_r0x0817875a:
        while (local_50 = pbVar11, (uVar14 & 0x18) == 0x10) {
LAB_08178768:
          pbVar13 = pbVar13 + 1;
          bVar7 = *pbVar13;
          pbVar11 = local_50;
          uVar14 = *(ushort *)((int)pvVar6 + (uint)bVar7 * 2);
        }
        if (bVar7 == 0x3d) {
          *pbVar5 = 0;
          pbVar11 = pbVar13 + 1;
          pvVar6 = param_1->meth_data;
          uVar14 = *(ushort *)((int)pvVar6 + (uint)pbVar13[1] * 2);
          pbVar13 = pbVar11;
          uVar8 = uVar14;
          while ((uVar8 & 0x18) == 0x10) {
            pbVar13 = pbVar13 + 1;
            uVar8 = *(ushort *)((int)pvVar6 + (uint)*pbVar13 * 2);
          }
          if ((uVar14 & 8) == 0) {
            do {
              pbVar11 = pbVar11 + 1;
            } while ((*(byte *)((int)pvVar6 + (uint)*pbVar11 * 2) & 8) == 0);
          }
          pbVar5 = pbVar13;
          if (pbVar11 + -1 != pbVar13) {
            bVar7 = *(byte *)((int)pvVar6 + (uint)pbVar11[-1] * 2);
            pbVar5 = pbVar11 + -1;
            while (((bVar7 & 0x10) != 0 && (pbVar5 = pbVar5 + -1, pbVar5 != pbVar13))) {
              bVar7 = *(byte *)((int)pvVar6 + (uint)*pbVar5 * 2);
            }
          }
          pbVar5[1] = 0;
          value = (CONF_VALUE *)CRYPTO_malloc(0xc,"conf_def.c",0x167);
          if (value == (CONF_VALUE *)0x0) {
            iVar3 = 0x168;
          }
          else {
            if (pbVar17 == (byte *)0x0) {
              pbVar17 = local_34;
            }
            sVar4 = strlen((char *)local_50);
            pcVar16 = (char *)CRYPTO_malloc(sVar4 + 1,"conf_def.c",0x16d);
            value->name = pcVar16;
            value->value = (char *)0x0;
            if (pcVar16 == (char *)0x0) {
              iVar3 = 0x170;
            }
            else {
              sVar4 = strlen((char *)local_50);
              BUF_strlcpy(pcVar16,(char *)local_50,sVar4 + 1);
              iVar3 = str_copy(pbVar13);
              if (iVar3 == 0) goto LAB_081781a4;
              iVar3 = strcmp((char *)pbVar17,(char *)local_34);
              section = local_40;
              if (((iVar3 != 0) &&
                  (section = _CONF_get_section(param_1,(char *)pbVar17),
                  section == (CONF_VALUE *)0x0)) &&
                 (section = _CONF_new_section(param_1,(char *)pbVar17), section == (CONF_VALUE *)0x0
                 )) {
                ERR_put_error(0xe,0x79,0x67,"conf_def.c",0x17d);
                goto LAB_081781a4;
              }
              iVar3 = _CONF_add_string(param_1,section,value);
              if (iVar3 != 0) goto LAB_081785bf;
              iVar3 = 0x184;
            }
          }
          ERR_put_error(0xe,0x79,0x41,"conf_def.c",iVar3);
          goto LAB_081781a4;
        }
      }
      iVar19 = 0x159;
      iVar3 = 0x65;
      goto LAB_08178932;
    }
    pbVar13 = local_50 + 1;
    uVar12 = (uint)local_50[1];
    uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
    while (pbVar11 = pbVar13, pbVar5 = pbVar13, (uVar14 & 0x18) == 0x10) {
      pbVar13 = pbVar13 + 1;
      uVar12 = (uint)*pbVar13;
      uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
    }
    while( true ) {
      while( true ) {
        while ((uVar14 & 0x20) != 0) {
          uVar12 = (uint)pbVar11[1];
          uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
          if ((uVar14 & 8) == 0) {
            uVar12 = (uint)pbVar11[2];
            uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
            pbVar11 = pbVar11 + 2;
          }
          else {
            pbVar11 = pbVar11 + 1;
          }
        }
        pbVar17 = pbVar11;
        if ((uVar14 & 0x307) == 0) break;
        uVar12 = (uint)pbVar11[1];
        uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
        pbVar11 = pbVar11 + 1;
      }
      while ((uVar14 & 0x18) == 0x10) {
        uVar12 = (uint)pbVar17[1];
        pbVar17 = pbVar17 + 1;
        uVar14 = *(ushort *)((int)pvVar6 + uVar12 * 2);
      }
      if ((char)uVar12 == ']') break;
      if ((pbVar5 == pbVar17) || (pbVar11 = pbVar17, pbVar5 = pbVar17, (char)uVar12 == '\0')) {
        iVar19 = 0x13e;
        iVar3 = 100;
        goto LAB_08178932;
      }
    }
    *pbVar11 = 0;
    iVar3 = str_copy(pbVar13);
    if (iVar3 == 0) goto LAB_0817893e;
    uVar12 = 0;
    local_40 = _CONF_get_section(param_1,(char *)local_34);
    uVar15 = 0;
    if ((local_40 != (CONF_VALUE *)0x0) ||
       (local_40 = _CONF_new_section(param_1,(char *)local_34), uVar15 = uVar12,
       local_40 != (CONF_VALUE *)0x0)) goto LAB_081782a8;
    iVar19 = 0x148;
    iVar3 = 0x67;
LAB_08178932:
    ERR_put_error(0xe,0x79,iVar3,"conf_def.c",iVar19);
LAB_0817893e:
    value = (CONF_VALUE *)0x0;
  }
LAB_081781a4:
  BUF_MEM_free(str);
LAB_081781b3:
  if (local_34 != (byte *)0x0) {
    CRYPTO_free(local_34);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_54;
  }
  BIO_snprintf(local_2d,0xd,"%ld",local_54);
  ERR_add_error_data(2,"line ",local_2d);
  conf = param_1->data;
  if ((conf != (lhash_st_CONF_VALUE *)0x0) && (plVar1 != conf)) {
    CONF_free(conf);
    param_1->data = (lhash_st_CONF_VALUE *)0x0;
  }
  if (value == (CONF_VALUE *)0x0) {
    local_64 = 0;
  }
  else {
    if (value->name != (char *)0x0) {
      CRYPTO_free(value->name);
    }
    if (value->value != (char *)0x0) {
      CRYPTO_free(value->value);
    }
    CRYPTO_free(value);
    local_64 = 0;
  }
LAB_0817825d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_64;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    uVar12 = (uint)pbVar11[2];
    pbVar13 = pbVar11 + 2;
    uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
    if ((uVar8 & 8) != 0) break;
LAB_081786c8:
    do {
      pbVar11 = pbVar13;
      uVar12 = (uint)(char)pbVar11[1];
      uVar8 = *(ushort *)((int)pvVar6 + (uVar12 & 0xff) * 2);
      pbVar13 = pbVar11 + 1;
      if ((uVar8 & 8) != 0) {
        if ((int)cVar2 == uVar12) {
LAB_08178730:
          uVar12 = (uint)pbVar11[2];
          pbVar13 = pbVar11 + 2;
          uVar8 = *(ushort *)((int)pvVar6 + uVar12 * 2);
        }
        goto LAB_081785d8;
      }
      if ((int)cVar2 == uVar12) goto LAB_08178730;
    } while ((uVar8 & 0x20) == 0);
  }
  goto LAB_081785d8;
}

