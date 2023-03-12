
undefined4 def_load_bio(CONF *param_1,undefined4 param_2,int *param_3)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  CONF_VALUE *section;
  lhash_st_CONF_VALUE *plVar12;
  int iVar13;
  ushort uVar15;
  byte *pbVar14;
  lhash_st_CONF_VALUE *conf;
  undefined *puVar16;
  void *pvVar17;
  uint uVar18;
  uint uVar19;
  byte *pbVar20;
  undefined4 uVar21;
  ushort uVar22;
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
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  plVar12 = param_1->data;
  local_40 = (byte *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar4 = (undefined *)(*(code *)PTR_BUF_MEM_new_006a749c)();
  if (puVar4 == (undefined *)0x0) {
    value = (CONF_VALUE *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,7,"conf_def.c",0xe0);
    iVar5 = 0;
    goto LAB_0059c630;
  }
  local_40 = (byte *)(*(code *)PTR_BUF_strdup_006a6fdc)("default");
  if (local_40 == (byte *)0x0) {
    uVar21 = 0x41;
    uVar6 = 0xe6;
  }
  else {
    iVar5 = _CONF_new_data(param_1);
    if (iVar5 == 0) {
      uVar21 = 0x41;
      uVar6 = 0xeb;
    }
    else {
      local_48 = _CONF_new_section(param_1,(char *)local_40);
      if (local_48 != (CONF_VALUE *)0x0) {
        iVar5 = 0;
        bVar1 = false;
        iVar27 = 0;
LAB_0059c784:
        iVar7 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(puVar4,iVar27 + 0x200);
        puVar16 = PTR_BIO_gets_006a74d4;
        if (iVar7 != 0) {
          puVar26 = (undefined *)(*(int *)(puVar4 + 4) + iVar27);
          *puVar26 = 0;
          (*(code *)puVar16)(param_2,puVar26,0x1ff);
          puVar16 = PTR_strlen_006a9a24;
          puVar26[0x1ff] = 0;
          iVar8 = (*(code *)puVar16)(puVar26);
          iVar7 = iVar8;
          if (iVar8 == 0) {
            iVar13 = 0;
            if (!bVar1) {
              (*(code *)PTR_BUF_MEM_free_006a7494)(puVar4);
              if (local_40 != (byte *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)();
                uVar6 = 1;
                goto LAB_0059c708;
              }
              uVar6 = 1;
              goto LAB_0059c708;
            }
            goto LAB_0059c828;
          }
          puVar16 = puVar26 + iVar8;
          if (0 < iVar8) goto LAB_0059c800;
          iVar27 = iVar27 + iVar8;
          bVar1 = true;
          if (0 < iVar27) {
            pbVar24 = *(byte **)(puVar4 + 4);
            iVar7 = iVar27;
            goto LAB_0059c840;
          }
          goto LAB_0059c8a0;
        }
        uVar21 = 7;
        uVar6 = 0xf9;
LAB_0059cf1c:
        value = (CONF_VALUE *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,uVar21,"conf_def.c",uVar6);
        goto LAB_0059c620;
      }
      uVar21 = 0x67;
      uVar6 = 0xf1;
    }
  }
  value = (CONF_VALUE *)0x0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,uVar21,"conf_def.c",uVar6);
  iVar5 = 0;
LAB_0059c620:
  while( true ) {
    (*(code *)PTR_BUF_MEM_free_006a7494)(puVar4);
LAB_0059c630:
    if (local_40 != (byte *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (param_3 != (int *)0x0) {
      *param_3 = iVar5;
    }
    puVar4 = auStack_3c;
    (*(code *)PTR_BIO_snprintf_006a6f60)(puVar4,0xd,&DAT_0066f118,iVar5);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"line ",puVar4);
    conf = param_1->data;
    if ((plVar12 != conf) && (conf != (lhash_st_CONF_VALUE *)0x0)) {
      CONF_free(conf);
      param_1->data = (lhash_st_CONF_VALUE *)0x0;
    }
    uVar6 = 0;
    if (value != (CONF_VALUE *)0x0) {
      if (value->name != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      if (value->value != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(value);
      uVar6 = 0;
    }
LAB_0059c708:
    if (local_2c == *(int *)puVar3) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0059d1ec:
    value = (CONF_VALUE *)0x0;
  }
  return uVar6;
LAB_0059c800:
  do {
    if ((puVar16[-1] != '\r') && (puVar16[-1] != '\n')) {
      iVar13 = iVar7;
      if (iVar8 == iVar7) {
        iVar27 = iVar27 + iVar8;
        bVar1 = true;
        if (iVar27 < 1) goto LAB_0059c784;
        bVar1 = true;
        goto LAB_0059c83c;
      }
      break;
    }
    iVar7 = iVar7 + -1;
    puVar16 = puVar16 + -1;
    iVar13 = iVar7;
  } while (iVar7 != 0);
LAB_0059c828:
  iVar27 = iVar27 + iVar7;
  puVar26[iVar13] = 0;
  iVar5 = iVar5 + 1;
  if (iVar27 < 1) {
    pbVar24 = *(byte **)(puVar4 + 4);
  }
  else {
    bVar1 = false;
LAB_0059c83c:
    pbVar24 = *(byte **)(puVar4 + 4);
    iVar7 = iVar27;
LAB_0059c840:
    iVar27 = iVar7 + -1;
    if (((*(ushort *)((int)param_1->meth_data + (uint)pbVar24[iVar27] * 2) & 0x20) != 0) &&
       ((iVar7 == 1 ||
        ((*(ushort *)((int)param_1->meth_data + (uint)(pbVar24 + iVar27)[-1] * 2) & 0x20) == 0)))) {
      bVar1 = true;
      goto LAB_0059c784;
    }
    iVar27 = iVar7;
    if (bVar1) {
LAB_0059c8a0:
      bVar1 = true;
      goto LAB_0059c784;
    }
  }
  uVar23 = (uint)(char)*pbVar24;
  pvVar17 = param_1->meth_data;
  uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
  pbVar9 = pbVar24;
  if ((uVar22 & 0x800) == 0) {
    uVar18 = uVar23;
    uVar15 = uVar22;
    if ((uVar22 & 0x10) == 0) goto LAB_0059c9e4;
    do {
      pbVar9 = pbVar9 + 1;
      uVar18 = (uint)(char)*pbVar9;
      uVar15 = *(ushort *)((int)pvVar17 + (uVar18 & 0xff) * 2);
      if ((uVar15 & 0x800) != 0) goto LAB_0059c910;
      uVar25 = uVar15 & 0x80;
    } while ((uVar15 & 0x10) != 0);
    while (pbVar10 = pbVar9, uVar19 = uVar18, uVar25 == 0) {
      while ((uVar15 & 0x400) == 0) {
        if ((uVar15 & 0x40) != 0) {
LAB_0059cacc:
          uVar18 = (uint)(char)pbVar10[1];
          uVar15 = *(ushort *)((int)pvVar17 + (uVar18 & 0xff) * 2);
          pbVar10 = pbVar10 + 1;
          do {
            if ((uVar15 & 8) != 0) {
              pbVar9 = pbVar10;
              if (uVar19 == uVar18) {
LAB_0059cb50:
                pbVar9 = pbVar10 + 1;
                uVar18 = (int)(char)pbVar10[1];
                uVar15 = *(ushort *)((int)pvVar17 + ((int)(char)pbVar10[1] & 0xffU) * 2);
              }
              goto LAB_0059c9e4;
            }
            if (uVar19 == uVar18) goto LAB_0059cb50;
            if ((uVar15 & 0x20) == 0) goto LAB_0059cacc;
            uVar15 = *(ushort *)((int)pvVar17 + ((int)(char)pbVar10[1] & 0xffU) * 2);
            pbVar9 = pbVar10 + 1;
            uVar18 = (int)(char)pbVar10[1];
            if ((uVar15 & 8) != 0) goto LAB_0059c9e4;
            uVar18 = (uint)(char)pbVar10[2];
            uVar15 = *(ushort *)((int)pvVar17 + (uVar18 & 0xff) * 2);
            pbVar10 = pbVar10 + 2;
          } while( true );
        }
        if ((uVar15 & 0x20) == 0) {
          if ((uVar15 & 8) != 0) goto LAB_0059c944;
          pbVar9 = pbVar10 + 1;
          uVar18 = (int)(char)pbVar10[1];
          uVar15 = *(ushort *)((int)pvVar17 + ((int)(char)pbVar10[1] & 0xffU) * 2);
          goto LAB_0059c9e4;
        }
        uVar19 = (uint)(char)pbVar10[1];
        uVar15 = *(ushort *)((int)pvVar17 + (uVar19 & 0xff) * 2);
        if ((uVar15 & 8) == 0) {
          pbVar9 = pbVar10 + 2;
          uVar18 = (int)(char)pbVar10[2];
          uVar15 = *(ushort *)((int)pvVar17 + ((int)(char)pbVar10[2] & 0xffU) * 2);
          goto LAB_0059c9e4;
        }
        pbVar10 = pbVar10 + 1;
        pbVar9 = pbVar10;
        if ((uVar15 & 0x80) != 0) goto LAB_0059c910;
      }
      while( true ) {
        pbVar20 = pbVar10;
        uVar18 = (uint)(char)pbVar20[1];
        uVar15 = *(ushort *)((int)pvVar17 + (uVar18 & 0xff) * 2);
        pbVar9 = pbVar20 + 1;
        if ((uVar15 & 8) != 0) break;
        pbVar10 = pbVar9;
        if (uVar19 == uVar18) {
          uVar18 = (uint)(char)pbVar20[2];
          if (uVar19 != uVar18) goto LAB_0059c9d4;
          pbVar10 = pbVar20 + 2;
        }
      }
      uVar25 = uVar15 & 0x80;
      if (uVar19 == uVar18) {
        uVar18 = (uint)(char)pbVar20[2];
LAB_0059c9d4:
        pbVar9 = pbVar20 + 2;
        uVar15 = *(ushort *)((int)pvVar17 + (uVar18 & 0xff) * 2);
LAB_0059c9e4:
        uVar25 = uVar15 & 0x80;
      }
    }
  }
LAB_0059c910:
  *pbVar9 = 0;
  uVar23 = (uint)(char)*pbVar24;
  pvVar17 = param_1->meth_data;
  uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
LAB_0059c944:
  while ((uVar22 & 0x18) == 0x10) {
    uVar23 = (uint)(char)pbVar24[1];
    pbVar24 = pbVar24 + 1;
    uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
  }
  if ((uVar22 & 8) == 0) {
    pbVar9 = pbVar24;
    if (uVar23 == 0x5b) {
      bVar2 = pbVar24[1];
      pbVar24 = pbVar24 + 1;
      while( true ) {
        uVar23 = (uint)(char)bVar2;
        uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
        pbVar9 = pbVar24;
        if ((uVar22 & 0x18) != 0x10) break;
        bVar2 = pbVar24[1];
        pbVar24 = pbVar24 + 1;
      }
      while( true ) {
        while( true ) {
          while ((uVar22 & 0x20) != 0) {
            uVar23 = (uint)(char)pbVar24[1];
            uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
            if ((uVar22 & 8) == 0) {
              uVar23 = (uint)(char)pbVar24[2];
              uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
              pbVar24 = pbVar24 + 2;
            }
            else {
              pbVar24 = pbVar24 + 1;
            }
          }
          pbVar10 = pbVar24;
          if ((uVar22 & 0x307) == 0) break;
          uVar23 = (uint)(char)pbVar24[1];
          uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
          pbVar24 = pbVar24 + 1;
        }
        while ((uVar22 & 0x18) == 0x10) {
          uVar23 = (uint)(char)pbVar10[1];
          pbVar10 = pbVar10 + 1;
          uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
        }
        if (uVar23 == 0x5d) break;
        if ((uVar23 == 0) || (bVar1 = pbVar9 == pbVar10, pbVar24 = pbVar10, pbVar9 = pbVar10, bVar1)
           ) {
          uVar21 = 100;
          uVar6 = 0x13e;
          goto LAB_0059cf1c;
        }
      }
      *pbVar24 = 0;
      iVar27 = str_copy(param_1,0,&local_40);
      if (iVar27 == 0) goto LAB_0059d1ec;
      local_48 = _CONF_get_section(param_1,(char *)local_40);
      if ((local_48 == (CONF_VALUE *)0x0) &&
         (local_48 = _CONF_new_section(param_1,(char *)local_40), local_48 == (CONF_VALUE *)0x0)) {
        uVar21 = 0x67;
        uVar6 = 0x148;
        goto LAB_0059cf1c;
      }
      goto LAB_0059cc88;
    }
    while( true ) {
      while ((uVar22 & 0x20) != 0) {
        uVar23 = (uint)(char)pbVar9[1];
        uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
        if ((uVar22 & 8) == 0) {
          uVar23 = (uint)(char)pbVar9[2];
          pbVar9 = pbVar9 + 2;
          uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
        }
        else {
          pbVar9 = pbVar9 + 1;
        }
      }
      if ((uVar22 & 0x307) == 0) break;
      uVar23 = (uint)(char)pbVar9[1];
      pbVar9 = pbVar9 + 1;
      uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
    }
    pbVar10 = pbVar9;
    if (uVar23 == 0x3a) {
      if (pbVar9[1] != 0x3a) {
        if ((uVar22 & 0x18) == 0x10) {
          local_4c = (byte *)0x0;
          goto LAB_0059ccb4;
        }
        goto LAB_0059d1a4;
      }
      uVar23 = (uint)(char)pbVar9[2];
      pbVar20 = pbVar9 + 2;
      *pbVar9 = 0;
      pvVar17 = param_1->meth_data;
      uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
      pbVar9 = pbVar20;
      while( true ) {
        while ((uVar22 & 0x20) != 0) {
          uVar23 = (uint)(char)pbVar9[1];
          uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
          if ((uVar22 & 8) == 0) {
            uVar23 = (uint)(char)pbVar9[2];
            pbVar9 = pbVar9 + 2;
            uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
          }
          else {
            pbVar9 = pbVar9 + 1;
          }
        }
        pbVar10 = pbVar9;
        local_4c = pbVar24;
        if ((uVar22 & 0x307) == 0) break;
        uVar23 = (uint)(char)pbVar9[1];
        pbVar9 = pbVar9 + 1;
        uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
      }
    }
    else {
      local_4c = (byte *)0x0;
      pbVar20 = pbVar24;
    }
    while (pbVar24 = pbVar20, (uVar22 & 0x18) == 0x10) {
LAB_0059ccb4:
      pbVar9 = pbVar9 + 1;
      uVar23 = (uint)(char)*pbVar9;
      pbVar20 = pbVar24;
      uVar22 = *(ushort *)((int)pvVar17 + (uVar23 & 0xff) * 2);
    }
    pbVar20 = pbVar9 + 1;
    if (uVar23 != 0x3d) {
LAB_0059d1a4:
      uVar21 = 0x65;
      uVar6 = 0x159;
      goto LAB_0059cf1c;
    }
    *pbVar10 = 0;
    puVar16 = PTR_CRYPTO_malloc_006a7008;
    pvVar17 = param_1->meth_data;
    uVar22 = *(ushort *)((int)pvVar17 + (uint)pbVar9[1] * 2);
    pbVar10 = pbVar20;
    if ((uVar22 & 0x18) == 0x10) {
      pbVar14 = pbVar9 + 2;
      do {
        pbVar10 = pbVar14;
        pbVar14 = pbVar10 + 1;
      } while ((*(ushort *)((int)pvVar17 + (uint)*pbVar10 * 2) & 0x18) == 0x10);
    }
    if ((uVar22 & 8) == 0) {
      pbVar9 = pbVar9 + 2;
      do {
        pbVar20 = pbVar9;
        pbVar9 = pbVar20 + 1;
      } while ((*(ushort *)((int)pvVar17 + (uint)*pbVar20 * 2) & 8) == 0);
      pbVar9 = pbVar20 + -1;
    }
    pbVar14 = pbVar10;
    if (pbVar9 != pbVar10) {
      bVar2 = pbVar20[-1];
      pbVar14 = pbVar9;
      while ((pbVar9 = pbVar14 + -1, (*(ushort *)((int)pvVar17 + (uint)bVar2 * 2) & 0x10) != 0 &&
             (pbVar14 = pbVar9, pbVar9 != pbVar10))) {
        bVar2 = *pbVar9;
      }
    }
    pbVar14[1] = 0;
    value = (CONF_VALUE *)(*(code *)puVar16)(0xc,"conf_def.c",0x167);
    if (value == (CONF_VALUE *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,0x41,"conf_def.c",0x168);
      goto LAB_0059c620;
    }
    if (local_4c == (byte *)0x0) {
      local_4c = local_40;
    }
    iVar27 = (*(code *)PTR_strlen_006a9a24)(pbVar24);
    pcVar11 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar27 + 1,"conf_def.c",0x16d);
    value->value = (char *)0x0;
    value->name = pcVar11;
    if (pcVar11 == (char *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,0x41,"conf_def.c",0x170);
      goto LAB_0059c620;
    }
    iVar27 = (*(code *)PTR_strlen_006a9a24)(pbVar24);
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar11,pbVar24,iVar27 + 1);
    iVar27 = str_copy(param_1,local_4c,&value->value,pbVar10);
    if (iVar27 == 0) goto LAB_0059c620;
    iVar27 = (*(code *)PTR_strcmp_006a9b18)(local_4c,local_40);
    section = local_48;
    if (((iVar27 != 0) &&
        (section = _CONF_get_section(param_1,(char *)local_4c), section == (CONF_VALUE *)0x0)) &&
       (section = _CONF_new_section(param_1,(char *)local_4c), section == (CONF_VALUE *)0x0)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,0x67,"conf_def.c",0x17d);
      goto LAB_0059c620;
    }
    iVar27 = _CONF_add_string(param_1,section,value);
    if (iVar27 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x79,0x41,"conf_def.c",0x184);
      goto LAB_0059c620;
    }
  }
LAB_0059cc88:
  bVar1 = false;
  iVar27 = 0;
  goto LAB_0059c784;
}

