
undefined4 def_load_bio(CONF *param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  CONF_VALUE *section;
  lhash_st_CONF_VALUE *plVar11;
  int iVar12;
  ushort uVar14;
  byte *pbVar13;
  lhash_st_CONF_VALUE *conf;
  undefined *puVar15;
  void *pvVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  undefined4 uVar20;
  bool bVar22;
  ushort uVar21;
  uint uVar23;
  byte *pbVar24;
  ushort uVar25;
  CONF_VALUE *value;
  undefined *puVar26;
  int iVar27;
  byte *local_4c;
  CONF_VALUE *local_48;
  byte *local_40;
  undefined auStack_3c [16];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  plVar11 = param_1->data;
  local_40 = (byte *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar3 = (undefined *)(*(code *)PTR_BUF_MEM_new_006a859c)();
  if (puVar3 == (undefined *)0x0) {
    value = (CONF_VALUE *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,7,"conf_def.c",0xe3);
    iVar4 = 0;
    goto LAB_0059f37c;
  }
  local_40 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(10,"conf_def.c",0xe7);
  if (local_40 == (byte *)0x0) {
    uVar20 = 0x41;
    uVar5 = 0xea;
  }
  else {
    (*(code *)PTR_BUF_strlcpy_006a8064)(local_40,"default",10);
    iVar4 = _CONF_new_data(param_1);
    if (iVar4 == 0) {
      uVar20 = 0x41;
      uVar5 = 0xf1;
    }
    else {
      local_48 = _CONF_new_section(param_1,(char *)local_40);
      if (local_48 != (CONF_VALUE *)0x0) {
        iVar4 = 0;
        bVar22 = false;
        iVar27 = 0;
LAB_0059f4c4:
        iVar6 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(puVar3,iVar27 + 0x200);
        if (iVar6 != 0) {
          do {
            puVar15 = PTR_BIO_gets_006a85d0;
            puVar26 = (undefined *)(*(int *)(puVar3 + 4) + iVar27);
            *puVar26 = 0;
            (*(code *)puVar15)(param_2,puVar26,0x1ff);
            puVar15 = PTR_strlen_006aab30;
            puVar26[0x1ff] = 0;
            iVar7 = (*(code *)puVar15)(puVar26);
            iVar6 = iVar7;
            if (iVar7 == 0) {
              iVar12 = 0;
              if (!bVar22) {
                (*(code *)PTR_BUF_MEM_free_006a8594)(puVar3);
                if (local_40 != (byte *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                  uVar5 = 1;
                  goto LAB_0059f454;
                }
                uVar5 = 1;
                goto LAB_0059f454;
              }
LAB_0059f568:
              iVar27 = iVar27 + iVar6;
              puVar26[iVar12] = 0;
              iVar4 = iVar4 + 1;
              if (iVar27 < 1) {
                pbVar24 = *(byte **)(puVar3 + 4);
                goto LAB_0059f618;
              }
              bVar22 = false;
LAB_0059f57c:
              pbVar24 = *(byte **)(puVar3 + 4);
              iVar6 = iVar27;
            }
            else {
              puVar15 = puVar26 + iVar7;
              if (0 < iVar7) {
                do {
                  if ((puVar15[-1] != '\r') && (puVar15[-1] != '\n')) {
                    iVar12 = iVar6;
                    if (iVar7 == iVar6) {
                      iVar27 = iVar27 + iVar7;
                      bVar22 = true;
                      if (iVar27 < 1) goto LAB_0059f4c4;
                      bVar22 = true;
                      goto LAB_0059f57c;
                    }
                    break;
                  }
                  iVar6 = iVar6 + -1;
                  puVar15 = puVar15 + -1;
                  iVar12 = iVar6;
                } while (iVar6 != 0);
                goto LAB_0059f568;
              }
              iVar27 = iVar27 + iVar7;
              bVar22 = true;
              if (iVar27 < 1) goto LAB_0059f60c;
              pbVar24 = *(byte **)(puVar3 + 4);
              iVar6 = iVar27;
            }
            iVar27 = iVar6 + -1;
            if (((*(ushort *)((int)param_1->meth_data + (uint)pbVar24[iVar27] * 2) & 0x20) == 0) ||
               ((iVar6 != 1 &&
                ((*(ushort *)((int)param_1->meth_data + (uint)(pbVar24 + iVar27)[-1] * 2) & 0x20) !=
                 0)))) goto LAB_0059f604;
            iVar6 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(puVar3,iVar6 + 0x1ff);
            bVar22 = true;
            if (iVar6 == 0) break;
          } while( true );
        }
        uVar20 = 7;
        uVar5 = 0x103;
LAB_0059fc34:
        value = (CONF_VALUE *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,uVar20,"conf_def.c",uVar5);
        goto LAB_0059f36c;
      }
      uVar20 = 0x67;
      uVar5 = 0xf9;
    }
  }
  value = (CONF_VALUE *)0x0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,uVar20,"conf_def.c",uVar5);
  iVar4 = 0;
LAB_0059f36c:
  while( true ) {
    (*(code *)PTR_BUF_MEM_free_006a8594)(puVar3);
LAB_0059f37c:
    if (local_40 != (byte *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (param_3 != (int *)0x0) {
      *param_3 = iVar4;
    }
    puVar3 = auStack_3c;
    (*(code *)PTR_BIO_snprintf_006a8060)(puVar3,0xd,&DAT_0066fa28,iVar4);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"line ",puVar3);
    conf = param_1->data;
    if ((plVar11 != conf) && (conf != (lhash_st_CONF_VALUE *)0x0)) {
      CONF_free(conf);
      param_1->data = (lhash_st_CONF_VALUE *)0x0;
    }
    uVar5 = 0;
    if (value != (CONF_VALUE *)0x0) {
      if (value->name != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      if (value->value != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(value);
      uVar5 = 0;
    }
LAB_0059f454:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0059ff64:
    value = (CONF_VALUE *)0x0;
  }
  return uVar5;
LAB_0059f604:
  iVar27 = iVar6;
  if (bVar22) {
LAB_0059f60c:
    bVar22 = true;
    goto LAB_0059f4c4;
  }
LAB_0059f618:
  uVar23 = (uint)(char)*pbVar24;
  pvVar16 = param_1->meth_data;
  uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
  pbVar8 = pbVar24;
  if ((uVar21 & 0x800) == 0) {
    uVar17 = uVar23;
    uVar14 = uVar21;
    if ((uVar21 & 0x10) == 0) goto LAB_0059f750;
    do {
      pbVar8 = pbVar8 + 1;
      uVar17 = (uint)(char)*pbVar8;
      uVar14 = *(ushort *)((int)pvVar16 + (uVar17 & 0xff) * 2);
      if ((uVar14 & 0x800) != 0) goto LAB_0059f67c;
      uVar25 = uVar14 & 0x80;
    } while ((uVar14 & 0x10) != 0);
    while (pbVar9 = pbVar8, uVar18 = uVar17, uVar25 == 0) {
      while ((uVar14 & 0x400) == 0) {
        if ((uVar14 & 0x40) != 0) {
LAB_0059f838:
          uVar17 = (uint)(char)pbVar9[1];
          uVar14 = *(ushort *)((int)pvVar16 + (uVar17 & 0xff) * 2);
          pbVar9 = pbVar9 + 1;
          do {
            if ((uVar14 & 8) != 0) {
              pbVar8 = pbVar9;
              if (uVar18 == uVar17) {
LAB_0059f8bc:
                pbVar8 = pbVar9 + 1;
                uVar17 = (int)(char)pbVar9[1];
                uVar14 = *(ushort *)((int)pvVar16 + ((int)(char)pbVar9[1] & 0xffU) * 2);
              }
              goto LAB_0059f750;
            }
            if (uVar18 == uVar17) goto LAB_0059f8bc;
            if ((uVar14 & 0x20) == 0) goto LAB_0059f838;
            uVar14 = *(ushort *)((int)pvVar16 + ((int)(char)pbVar9[1] & 0xffU) * 2);
            pbVar8 = pbVar9 + 1;
            uVar17 = (int)(char)pbVar9[1];
            if ((uVar14 & 8) != 0) goto LAB_0059f750;
            uVar17 = (uint)(char)pbVar9[2];
            uVar14 = *(ushort *)((int)pvVar16 + (uVar17 & 0xff) * 2);
            pbVar9 = pbVar9 + 2;
          } while( true );
        }
        if ((uVar14 & 0x20) == 0) {
          if ((uVar14 & 8) != 0) goto LAB_0059f6b0;
          pbVar8 = pbVar9 + 1;
          uVar17 = (int)(char)pbVar9[1];
          uVar14 = *(ushort *)((int)pvVar16 + ((int)(char)pbVar9[1] & 0xffU) * 2);
          goto LAB_0059f750;
        }
        uVar18 = (uint)(char)pbVar9[1];
        uVar14 = *(ushort *)((int)pvVar16 + (uVar18 & 0xff) * 2);
        if ((uVar14 & 8) == 0) {
          pbVar8 = pbVar9 + 2;
          uVar17 = (int)(char)pbVar9[2];
          uVar14 = *(ushort *)((int)pvVar16 + ((int)(char)pbVar9[2] & 0xffU) * 2);
          goto LAB_0059f750;
        }
        pbVar9 = pbVar9 + 1;
        pbVar8 = pbVar9;
        if ((uVar14 & 0x80) != 0) goto LAB_0059f67c;
      }
      while( true ) {
        pbVar19 = pbVar9;
        uVar17 = (uint)(char)pbVar19[1];
        uVar14 = *(ushort *)((int)pvVar16 + (uVar17 & 0xff) * 2);
        pbVar8 = pbVar19 + 1;
        if ((uVar14 & 8) != 0) break;
        pbVar9 = pbVar8;
        if (uVar18 == uVar17) {
          uVar17 = (uint)(char)pbVar19[2];
          if (uVar18 != uVar17) goto LAB_0059f740;
          pbVar9 = pbVar19 + 2;
        }
      }
      uVar25 = uVar14 & 0x80;
      if (uVar18 == uVar17) {
        uVar17 = (uint)(char)pbVar19[2];
LAB_0059f740:
        pbVar8 = pbVar19 + 2;
        uVar14 = *(ushort *)((int)pvVar16 + (uVar17 & 0xff) * 2);
LAB_0059f750:
        uVar25 = uVar14 & 0x80;
      }
    }
  }
LAB_0059f67c:
  *pbVar8 = 0;
  uVar23 = (uint)(char)*pbVar24;
  pvVar16 = param_1->meth_data;
  uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
LAB_0059f6b0:
  while ((uVar21 & 0x18) == 0x10) {
    uVar23 = (uint)(char)pbVar24[1];
    pbVar24 = pbVar24 + 1;
    uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
  }
  if ((uVar21 & 8) == 0) {
    pbVar8 = pbVar24;
    if (uVar23 == 0x5b) {
      bVar1 = pbVar24[1];
      pbVar24 = pbVar24 + 1;
      while( true ) {
        uVar23 = (uint)(char)bVar1;
        uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
        if ((uVar21 & 0x18) != 0x10) break;
        bVar1 = pbVar24[1];
        pbVar24 = pbVar24 + 1;
      }
      while( true ) {
        while( true ) {
          while ((uVar21 & 0x20) != 0) {
            uVar23 = (uint)(char)pbVar24[1];
            uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
            if ((uVar21 & 8) == 0) {
              uVar23 = (uint)(char)pbVar24[2];
              pbVar24 = pbVar24 + 2;
              uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
            }
            else {
              pbVar24 = pbVar24 + 1;
            }
          }
          pbVar8 = pbVar24;
          if ((uVar21 & 0x307) == 0) break;
          uVar23 = (uint)(char)pbVar24[1];
          uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
          pbVar24 = pbVar24 + 1;
        }
        while ((uVar21 & 0x18) == 0x10) {
          uVar23 = (uint)(char)pbVar8[1];
          pbVar8 = pbVar8 + 1;
          uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
        }
        if (uVar23 == 0x5d) break;
        pbVar24 = pbVar8;
        if (uVar23 == 0) {
          uVar20 = 100;
          uVar5 = 0x14a;
          goto LAB_0059fc34;
        }
      }
      *pbVar24 = 0;
      iVar27 = str_copy(param_1,0,&local_40);
      if (iVar27 == 0) goto LAB_0059ff64;
      local_48 = _CONF_get_section(param_1,(char *)local_40);
      if ((local_48 == (CONF_VALUE *)0x0) &&
         (local_48 = _CONF_new_section(param_1,(char *)local_40), local_48 == (CONF_VALUE *)0x0)) {
        uVar20 = 0x67;
        uVar5 = 0x154;
        goto LAB_0059fc34;
      }
      goto LAB_0059fa08;
    }
    while( true ) {
      while ((uVar21 & 0x20) != 0) {
        uVar23 = (uint)(char)pbVar8[1];
        uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
        if ((uVar21 & 8) == 0) {
          uVar23 = (uint)(char)pbVar8[2];
          pbVar8 = pbVar8 + 2;
          uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
        }
        else {
          pbVar8 = pbVar8 + 1;
        }
      }
      if ((uVar21 & 0x307) == 0) break;
      uVar23 = (uint)(char)pbVar8[1];
      pbVar8 = pbVar8 + 1;
      uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
    }
    pbVar9 = pbVar8;
    if (uVar23 == 0x3a) {
      if (pbVar8[1] != 0x3a) {
        if ((uVar21 & 0x18) == 0x10) {
          local_4c = (byte *)0x0;
          goto LAB_0059fa34;
        }
        goto LAB_0059fee4;
      }
      uVar23 = (uint)(char)pbVar8[2];
      pbVar19 = pbVar8 + 2;
      *pbVar8 = 0;
      pvVar16 = param_1->meth_data;
      uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
      pbVar8 = pbVar19;
      while( true ) {
        while ((uVar21 & 0x20) != 0) {
          uVar23 = (uint)(char)pbVar8[1];
          uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
          if ((uVar21 & 8) == 0) {
            uVar23 = (uint)(char)pbVar8[2];
            pbVar8 = pbVar8 + 2;
            uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
          }
          else {
            pbVar8 = pbVar8 + 1;
          }
        }
        pbVar9 = pbVar8;
        local_4c = pbVar24;
        if ((uVar21 & 0x307) == 0) break;
        uVar23 = (uint)(char)pbVar8[1];
        pbVar8 = pbVar8 + 1;
        uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
      }
    }
    else {
      local_4c = (byte *)0x0;
      pbVar19 = pbVar24;
    }
    while (pbVar24 = pbVar19, (uVar21 & 0x18) == 0x10) {
LAB_0059fa34:
      pbVar8 = pbVar8 + 1;
      uVar23 = (uint)(char)*pbVar8;
      pbVar19 = pbVar24;
      uVar21 = *(ushort *)((int)pvVar16 + (uVar23 & 0xff) * 2);
    }
    if (uVar23 != 0x3d) {
LAB_0059fee4:
      uVar20 = 0x65;
      uVar5 = 0x16a;
      goto LAB_0059fc34;
    }
    *pbVar9 = 0;
    puVar15 = PTR_CRYPTO_malloc_006a8108;
    pbVar19 = pbVar8 + 1;
    pvVar16 = param_1->meth_data;
    uVar21 = *(ushort *)((int)pvVar16 + (uint)pbVar8[1] * 2);
    pbVar9 = pbVar19;
    if ((uVar21 & 0x18) == 0x10) {
      pbVar13 = pbVar8 + 2;
      do {
        pbVar9 = pbVar13;
        pbVar13 = pbVar9 + 1;
      } while ((*(ushort *)((int)pvVar16 + (uint)*pbVar9 * 2) & 0x18) == 0x10);
    }
    if ((uVar21 & 8) == 0) {
      pbVar8 = pbVar8 + 2;
      do {
        pbVar19 = pbVar8;
        pbVar8 = pbVar19 + 1;
      } while ((*(ushort *)((int)pvVar16 + (uint)*pbVar19 * 2) & 8) == 0);
      pbVar8 = pbVar19 + -1;
    }
    pbVar13 = pbVar9;
    if (pbVar8 != pbVar9) {
      bVar1 = pbVar19[-1];
      pbVar13 = pbVar8;
      while ((pbVar8 = pbVar13 + -1, (*(ushort *)((int)pvVar16 + (uint)bVar1 * 2) & 0x10) != 0 &&
             (pbVar13 = pbVar8, pbVar8 != pbVar9))) {
        bVar1 = *pbVar8;
      }
    }
    pbVar13[1] = 0;
    value = (CONF_VALUE *)(*(code *)puVar15)(0xc,"conf_def.c",0x178);
    if (value == (CONF_VALUE *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,0x41,"conf_def.c",0x17b);
      goto LAB_0059f36c;
    }
    if (local_4c == (byte *)0x0) {
      local_4c = local_40;
    }
    iVar27 = (*(code *)PTR_strlen_006aab30)(pbVar24);
    pcVar10 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar27 + 1,"conf_def.c",0x17f);
    value->value = (char *)0x0;
    value->name = pcVar10;
    if (pcVar10 == (char *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,0x41,"conf_def.c",0x184);
      goto LAB_0059f36c;
    }
    iVar27 = (*(code *)PTR_strlen_006aab30)(pbVar24);
    (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar10,pbVar24,iVar27 + 1);
    iVar27 = str_copy(param_1,local_4c,&value->value,pbVar9);
    if (iVar27 == 0) goto LAB_0059f36c;
    iVar27 = (*(code *)PTR_strcmp_006aac20)(local_4c,local_40);
    section = local_48;
    if (((iVar27 != 0) &&
        (section = _CONF_get_section(param_1,(char *)local_4c), section == (CONF_VALUE *)0x0)) &&
       (section = _CONF_new_section(param_1,(char *)local_4c), section == (CONF_VALUE *)0x0)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,0x67,"conf_def.c",0x192);
      goto LAB_0059f36c;
    }
    iVar27 = _CONF_add_string(param_1,section,value);
    if (iVar27 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x79,0x41,"conf_def.c",0x19c);
      goto LAB_0059f36c;
    }
  }
LAB_0059fa08:
  bVar22 = false;
  iVar27 = 0;
  goto LAB_0059f4c4;
}

