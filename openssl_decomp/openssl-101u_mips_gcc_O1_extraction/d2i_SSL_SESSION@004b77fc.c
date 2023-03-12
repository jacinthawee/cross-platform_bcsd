
SSL_SESSION * d2i_SSL_SESSION(SSL_SESSION **a,uchar **pp,long length)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  SSL_SESSION *pSVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  byte *extraout_v1;
  byte **ppbVar11;
  SSL_SESSION *pSVar12;
  byte **unaff_s1;
  byte ****unaff_s7;
  code *pcVar13;
  long local_res8 [2];
  undefined4 *local_8c;
  byte ***local_88;
  undefined auStack_84 [4];
  undefined auStack_80 [4];
  byte **local_7c;
  undefined4 local_78 [2];
  void *local_70;
  byte **local_68 [2];
  byte *local_60;
  byte *local_58 [2];
  undefined4 local_50;
  byte **local_40;
  byte *local_3c;
  byte *local_38;
  uchar **local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pbVar5 = *pp;
  local_50 = 0x3a;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res8[0] = length;
  local_38 = pbVar5;
  local_34 = pp;
  if ((a == (SSL_SESSION **)0x0) || (pSVar12 = *a, pSVar12 == (SSL_SESSION *)0x0)) {
    pSVar12 = SSL_SESSION_new();
    if (pSVar12 == (SSL_SESSION *)0x0) {
      local_30 = 0x184;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x67,local_50,"ssl_asn1.c",0x184);
      ppbVar11 = (byte **)(local_38 + -(int)*pp);
      (*(code *)PTR_asn1_add_error_006a83f0)(*pp);
      pSVar7 = (SSL_SESSION *)0x0;
      goto LAB_004b7924;
    }
    pbVar5 = *pp;
  }
  local_8c = local_78;
  local_88 = local_68;
  local_58[0] = pbVar5;
  if (local_res8[0] == 0) {
    local_3c = (byte *)0x0;
    iVar6 = (*(code *)PTR_asn1_GetSequence_006a83ec)(local_58,local_res8);
  }
  else {
    local_3c = pbVar5 + local_res8[0];
    iVar6 = (*(code *)PTR_asn1_GetSequence_006a83ec)(local_58,local_res8);
  }
  if (iVar6 == 0) {
    unaff_s1 = local_58;
    local_30 = 0x18a;
    goto LAB_004b78c4;
  }
  unaff_s1 = local_58;
  local_70 = (void *)0x0;
  local_78[0] = 0;
  local_38 = local_58[0];
  iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_40);
  if (iVar6 == 0) {
    local_30 = 0x18e;
    goto LAB_004b78c4;
  }
  local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
  if (local_70 != (void *)0x0) {
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  local_38 = local_58[0];
  iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_40);
  if (iVar6 == 0) {
    local_30 = 0x196;
    goto LAB_004b78c4;
  }
  local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
  iVar6 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(local_8c);
  pSVar12->ssl_version = iVar6;
  if (local_70 != (void *)0x0) {
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  unaff_s7 = &local_88;
  local_60 = (byte *)0x0;
  local_68[0] = (byte **)0x0;
  local_38 = local_58[0];
  iVar8 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_40);
  puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a83f8;
  if (iVar8 == 0) {
    local_30 = 0x1a1;
    goto LAB_004b78c4;
  }
  local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
  if (iVar6 == 2) {
    if (local_68[0] != (byte **)0x3) {
      local_50 = 0x89;
      local_30 = 0x1a5;
      goto LAB_004b78c4;
    }
    uVar9 = (uint)*local_60 << 0x10 | local_60[2] | 0x2000000 | (uint)local_60[1] << 8;
  }
  else {
    if (((iVar6 >> 8 != 3) && (iVar6 >> 8 != 0xfe)) && (iVar6 != 0x100)) {
      local_50 = 0xfe;
      local_30 = 0x1b7;
      goto LAB_004b78c4;
    }
    if (local_68[0] != (byte **)&SUB_00000002) {
      local_50 = 0x89;
      local_30 = 0x1b0;
      goto LAB_004b78c4;
    }
    uVar9 = (uint)*local_60 << 8 | local_60[1] | 0x3000000;
  }
  *(undefined4 *)(pSVar12->krb5_client_princ + 0x24) = 0;
  *(uint *)(pSVar12->krb5_client_princ + 0x28) = uVar9;
  local_38 = local_58[0];
  iVar6 = (*(code *)puVar2)(unaff_s7,unaff_s1);
  pbVar5 = local_58[0];
  puVar2 = PTR_memcpy_006a9aec;
  if (iVar6 == 0) {
    local_30 = 0x1be;
    goto LAB_004b78c4;
  }
  ppbVar11 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
  if (0x20 < (int)local_68[0]) {
    local_68[0] = (byte **)&DAT_00000020;
  }
  pSVar12->session_id_length = (uint)local_68[0];
  local_40 = ppbVar11;
  (*(code *)puVar2)(pSVar12->session_id,local_60,local_68[0]);
  local_38 = pbVar5;
  iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,ppbVar11);
  pbVar4 = local_58[0];
  pbVar5 = local_60;
  puVar2 = PTR_memcpy_006a9aec;
  if (iVar6 == 0) {
    local_30 = 0x1cd;
    goto LAB_004b78c4;
  }
  ppbVar11 = local_68[0];
  if (0x30 < (int)local_68[0]) {
    ppbVar11 = (byte **)&DAT_00000030;
  }
  local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
  pSVar12->master_key_length = (int)ppbVar11;
  (*(code *)puVar2)(pSVar12->master_key,local_60,ppbVar11);
  puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a83f8;
  local_68[0] = (byte **)0x0;
  if (local_40 == (byte **)0x0) {
LAB_004b7ca0:
    ppbVar11 = (byte **)0x0;
  }
  else {
    bVar1 = *pbVar4;
    if ((bVar1 & 0xdf) != 0x80) goto LAB_004b7ca0;
    *pbVar4 = bVar1 & 0x20 | 4;
    local_38 = local_58[0];
    iVar6 = (*(code *)puVar2)(unaff_s7,unaff_s1,local_40);
    if (iVar6 == 0) {
      local_30 = 0x1e7;
      *local_38 = bVar1;
      goto LAB_004b78c4;
    }
    local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
    *local_38 = bVar1;
    ppbVar11 = local_68[0];
    pbVar5 = local_60;
    if (8 < (int)local_68[0]) {
      ppbVar11 = (byte **)&DAT_00000008;
    }
  }
  puVar2 = PTR_memcpy_006a9aec;
  pSVar12->key_arg_length = (uint)ppbVar11;
  (*(code *)puVar2)(pSVar12->key_arg,pbVar5);
  if (local_60 != (byte *)0x0) {
    CRYPTO_free(local_60);
  }
  local_78[0] = 0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa1)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x1f1;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b83b8;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b83b8:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        goto LAB_004b7cf4;
      }
    }
    local_30 = 0x1f1;
    goto LAB_004b78c4;
  }
LAB_004b7cf4:
  if (local_70 == (void *)0x0) {
    uVar10 = (*(code *)PTR_time_006a9adc)(0);
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x1c) = uVar10;
  }
  else {
    uVar10 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(local_8c);
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x1c) = uVar10;
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
  }
  local_78[0] = 0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa2)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x1fb;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b8378;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b8378:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        goto LAB_004b7d44;
      }
    }
    local_30 = 0x1fb;
    goto LAB_004b78c4;
  }
LAB_004b7d44:
  if (local_70 == (void *)0x0) {
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x18) = 3;
  }
  else {
    uVar10 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(local_8c);
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x18) = uVar10;
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  if (*(int *)(pSVar12->krb5_client_princ + 0xc) != 0) {
    (*(code *)PTR_X509_free_006a6e90)();
    *(undefined4 *)(pSVar12->krb5_client_princ + 0xc) = 0;
  }
  if (local_40 == (byte **)0x0) {
    local_68[0] = (byte **)0x0;
    local_60 = (byte *)0x0;
LAB_004b7dcc:
    pSVar12->sid_ctx_length = 0;
  }
  else {
    if (*local_58[0] != 0xa3) {
LAB_004b7dbc:
      local_60 = (byte *)0x0;
      local_68[0] = (byte **)0x0;
      if (*local_58[0] == 0xa4) {
        local_38 = local_58[0];
        uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                          (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar9 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 0x20c;
          goto LAB_004b78c4;
        }
        if (uVar9 == 0x21) {
          local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
          iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004b83f8;
            local_50 = 0x3f;
          }
        }
        else {
          iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
          if (iVar6 != 0) {
LAB_004b83f8:
            pbVar5 = local_60;
            puVar2 = PTR_memcpy_006a9aec;
            local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
            if (local_60 != (byte *)0x0) {
              if (0x20 < (int)local_68[0]) {
                local_50 = 0x10f;
                local_30 = 0x211;
                goto LAB_004b78c4;
              }
              pSVar12->sid_ctx_length = (uint)local_68[0];
              (*(code *)puVar2)(pSVar12->sid_ctx,local_60);
              CRYPTO_free(pbVar5);
              local_60 = (byte *)0x0;
              local_68[0] = (byte **)0x0;
              goto LAB_004b7dd0;
            }
            goto LAB_004b7dcc;
          }
        }
        local_30 = 0x20c;
        goto LAB_004b78c4;
      }
      goto LAB_004b7dcc;
    }
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x208;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_X509_006a7fe0)(pSVar12->krb5_client_princ + 0xc,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b8324;
        local_50 = 0x3f;
      }
LAB_004b8acc:
      local_30 = 0x208;
      goto LAB_004b78c4;
    }
    iVar6 = (*(code *)PTR_d2i_X509_006a7fe0)(pSVar12->krb5_client_princ + 0xc,unaff_s1,local_7c);
    if (iVar6 == 0) goto LAB_004b8acc;
LAB_004b8324:
    local_68[0] = (byte **)0x0;
    local_60 = (byte *)0x0;
    local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
    if (local_40 != (byte **)0x0) goto LAB_004b7dbc;
    pSVar12->sid_ctx_length = 0;
  }
LAB_004b7dd0:
  local_78[0] = 0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa5)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x21e;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b891c;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b891c:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        goto LAB_004b7dec;
      }
    }
    local_30 = 0x21e;
    goto LAB_004b78c4;
  }
LAB_004b7dec:
  if (local_70 == (void *)0x0) {
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x10) = 0;
  }
  else {
    uVar10 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(local_8c);
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x10) = uVar10;
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  local_68[0] = (byte **)0x0;
  local_60 = (byte *)0x0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa6)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x22a;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b882c;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b882c:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        if (local_60 == (byte *)0x0) goto LAB_004b7e34;
        uVar10 = (*(code *)PTR_BUF_strndup_006a7fcc)(local_60,local_68[0]);
        *(undefined4 *)(pSVar12->krb5_client_princ + 0x40) = uVar10;
        CRYPTO_free(local_60);
        goto LAB_004b7e38;
      }
    }
    local_30 = 0x22a;
    goto LAB_004b78c4;
  }
LAB_004b7e34:
  *(undefined4 *)(pSVar12->krb5_client_princ + 0x40) = 0;
LAB_004b7e38:
  local_68[0] = (byte **)0x0;
  local_60 = (byte *)0x0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa7)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x237;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b88a4;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b88a4:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        if (local_60 == (byte *)0x0) goto LAB_004b7e44;
        uVar9 = (*(code *)PTR_BUF_strndup_006a7fcc)(local_60,local_68[0]);
        pSVar12->krb5_client_princ_len = uVar9;
        CRYPTO_free(local_60);
        goto LAB_004b7e48;
      }
    }
    local_30 = 0x237;
    goto LAB_004b78c4;
  }
LAB_004b7e44:
  pSVar12->krb5_client_princ_len = 0;
LAB_004b7e48:
  local_68[0] = (byte **)0x0;
  local_60 = (byte *)0x0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa8)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x242;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b8738;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b8738:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        if (local_60 == (byte *)0x0) goto LAB_004b7e54;
        uVar10 = (*(code *)PTR_BUF_strndup_006a7fcc)(local_60,local_68[0]);
        *(undefined4 *)pSVar12->krb5_client_princ = uVar10;
        CRYPTO_free(local_60);
        local_60 = (byte *)0x0;
        local_68[0] = (byte **)0x0;
        goto LAB_004b7e58;
      }
    }
    local_30 = 0x242;
    goto LAB_004b78c4;
  }
LAB_004b7e54:
  *(undefined4 *)pSVar12->krb5_client_princ = 0;
LAB_004b7e58:
  local_78[0] = 0;
  if ((local_40 != (byte **)0x0) && (*local_58[0] == 0xa9)) {
    local_38 = local_58[0];
    uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                      (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x24e;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b89e8;
        local_50 = 0x3f;
      }
    }
    else {
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(&local_8c,unaff_s1,local_7c);
      if (iVar6 != 0) {
LAB_004b89e8:
        local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        goto LAB_004b7e74;
      }
    }
    local_30 = 0x24e;
    goto LAB_004b78c4;
  }
LAB_004b7e74:
  if (local_70 == (void *)0x0) {
    if ((*(int *)(pSVar12->krb5_client_princ + 0x58) == 0) || (pSVar12->session_id_length == 0)) {
      *(undefined4 *)(pSVar12->krb5_client_princ + 0x5c) = 0;
    }
    else {
      *(undefined4 *)(pSVar12->krb5_client_princ + 0x5c) = 0xffffffff;
    }
  }
  else {
    uVar10 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(local_8c);
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x5c) = uVar10;
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  local_68[0] = (byte **)0x0;
  local_60 = (byte *)0x0;
  if (local_40 == (byte **)0x0) {
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x54) = 0;
    local_68[0] = (byte **)0x0;
    local_60 = (byte *)0x0;
    ppbVar11 = local_40;
    goto LAB_004b7f04;
  }
  if (*local_58[0] != 0xaa) {
    *(undefined4 *)(pSVar12->krb5_client_princ + 0x54) = 0;
    goto LAB_004b7edc;
  }
  local_38 = local_58[0];
  uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)(unaff_s1,&local_7c,auStack_84,auStack_80,local_40)
  ;
  if ((uVar9 & 0x80) != 0) {
    local_50 = 0x3b;
    local_30 = 0x25a;
    goto LAB_004b78c4;
  }
  if (uVar9 == 0x21) {
    local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
    iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
    if (iVar6 != 0) {
      local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
      iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
      if (iVar6 != 0) goto LAB_004b85b8;
      local_50 = 0x3f;
    }
  }
  else {
    iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
    if (iVar6 != 0) {
LAB_004b85b8:
      local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
      if (local_60 != (byte *)0x0) {
        *(byte ***)(pSVar12->krb5_client_princ + 0x58) = local_68[0];
      }
      *(byte **)(pSVar12->krb5_client_princ + 0x54) = local_60;
      if (local_40 == (byte **)0x0) {
        local_68[0] = (byte **)0x0;
        local_60 = (byte *)0x0;
        ppbVar11 = local_40;
        goto LAB_004b7f04;
      }
LAB_004b7edc:
      local_60 = (byte *)0x0;
      local_68[0] = (byte **)0x0;
      pbVar5 = local_58[0];
      ppbVar11 = local_40;
      pcVar13 = (code *)PTR_ASN1_get_object_006a7fb0;
      if (*local_58[0] == 0xab) goto LAB_004b8514;
      goto LAB_004b7ef4;
    }
  }
  local_30 = 0x25a;
LAB_004b78c4:
  do {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x67,local_50,"ssl_asn1.c",local_30);
    ppbVar11 = (byte **)(local_38 + -(int)*pp);
    (*(code *)PTR_asn1_add_error_006a83f0)(*pp);
    if ((a == (SSL_SESSION **)0x0) || (pSVar7 = (SSL_SESSION *)0x0, pSVar12 != *a)) {
      SSL_SESSION_free(pSVar12);
      pSVar7 = (SSL_SESSION *)0x0;
    }
LAB_004b7924:
    if (local_2c == *(int *)puVar3) {
      return pSVar7;
    }
    pcVar13 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pbVar5 = extraout_v1;
LAB_004b8514:
    local_38 = pbVar5;
    uVar9 = (*pcVar13)(unaff_s1,&local_7c,auStack_84,auStack_80,ppbVar11);
    if ((uVar9 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x266;
      goto LAB_004b78c4;
    }
    if (uVar9 == 0x21) {
      local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004b8620;
        local_50 = 0x3f;
      }
LAB_004b8d78:
      local_30 = 0x266;
      goto LAB_004b78c4;
    }
    iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
    if (iVar6 == 0) goto LAB_004b8d78;
LAB_004b8620:
    local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
    if (local_60 != (byte *)0x0) {
      *(uint *)(pSVar12->krb5_client_princ + 0x20) = (uint)*local_60;
      CRYPTO_free(local_60);
    }
    local_68[0] = (byte **)0x0;
    local_60 = (byte *)0x0;
    ppbVar11 = local_40;
    if (local_40 == (byte **)0x0) {
LAB_004b7f04:
      *(undefined4 *)(pSVar12->krb5_client_princ + 0x60) = 0;
      pSVar7 = pSVar12;
    }
    else {
LAB_004b7ef4:
      local_60 = (byte *)0x0;
      local_68[0] = (byte **)0x0;
      ppbVar11 = local_40;
      if (*local_58[0] != 0xac) goto LAB_004b7f04;
      local_38 = local_58[0];
      uVar9 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                        (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
      if ((uVar9 & 0x80) != 0) {
        local_50 = 0x3b;
        local_30 = 0x271;
        goto LAB_004b78c4;
      }
      if (uVar9 == 0x21) {
        local_7c = (byte **)((int)local_40 + (-2 - ((int)local_58[0] - (int)local_38)));
        iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
        if (iVar6 != 0) {
          ppbVar11 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
          local_7c = ppbVar11;
          iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)(unaff_s1);
          if (iVar6 != 0) goto LAB_004b87b8;
          local_50 = 0x3f;
        }
LAB_004b8eec:
        local_30 = 0x271;
        goto LAB_004b78c4;
      }
      ppbVar11 = unaff_s1;
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(unaff_s7,unaff_s1,local_7c);
      if (iVar6 == 0) goto LAB_004b8eec;
LAB_004b87b8:
      local_40 = (byte **)((int)local_40 - ((int)local_58[0] - (int)local_38));
      if (local_60 == (byte *)0x0) goto LAB_004b7f04;
      ppbVar11 = local_68[0];
      uVar10 = (*(code *)PTR_BUF_strndup_006a7fcc)();
      *(undefined4 *)(pSVar12->krb5_client_princ + 0x60) = uVar10;
      CRYPTO_free(local_60);
      local_60 = (byte *)0x0;
      local_68[0] = (byte **)0x0;
      pSVar7 = pSVar12;
    }
    iVar6 = (*(code *)PTR_asn1_const_Finish_006a83fc)(unaff_s1);
    pSVar12 = pSVar7;
    if (iVar6 != 0) {
      *pp = local_58[0];
      if (a != (SSL_SESSION **)0x0) {
        *a = pSVar7;
      }
      goto LAB_004b7924;
    }
    local_30 = 0x27b;
  } while( true );
}

