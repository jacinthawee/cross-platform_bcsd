
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
  undefined4 uVar9;
  uint uVar10;
  int extraout_v1;
  SSL_SESSION *pSVar11;
  byte **unaff_s1;
  undefined4 **unaff_s5;
  uint **unaff_s7;
  code *pcVar12;
  long local_res8 [2];
  undefined4 *local_8c;
  uint *local_88;
  undefined auStack_84 [4];
  undefined auStack_80 [4];
  int local_7c;
  undefined4 local_78 [2];
  void *local_70;
  uint local_68 [2];
  byte *local_60;
  byte *local_58 [2];
  undefined4 local_50;
  int local_40;
  byte *local_3c;
  byte *local_38;
  uchar **local_34;
  undefined4 local_30;
  byte *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pbVar5 = *pp;
  local_50 = 0x3a;
  local_2c = *(byte **)PTR___stack_chk_guard_006aabf0;
  local_res8[0] = length;
  local_38 = pbVar5;
  local_34 = pp;
  if ((a == (SSL_SESSION **)0x0) || (pSVar11 = *a, pSVar11 == (SSL_SESSION *)0x0)) {
    pSVar11 = SSL_SESSION_new();
    if (pSVar11 == (SSL_SESSION *)0x0) {
      local_30 = 0x182;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,local_50,"ssl_asn1.c",0x182);
      (*(code *)PTR_asn1_add_error_006a9508)(*pp,(int)local_38 - (int)*pp);
      pSVar7 = (SSL_SESSION *)0x0;
      goto LAB_004babc4;
    }
    pbVar5 = *pp;
  }
  local_8c = local_78;
  local_88 = local_68;
  local_58[0] = pbVar5;
  if (local_res8[0] == 0) {
    local_3c = (byte *)0x0;
    iVar6 = (*(code *)PTR_asn1_GetSequence_006a9504)(local_58,local_res8);
  }
  else {
    local_3c = pbVar5 + local_res8[0];
    iVar6 = (*(code *)PTR_asn1_GetSequence_006a9504)(local_58,local_res8);
  }
  if (iVar6 == 0) {
    unaff_s1 = local_58;
    local_30 = 0x188;
    goto LAB_004bab64;
  }
  unaff_s1 = local_58;
  unaff_s5 = &local_8c;
  local_70 = (void *)0x0;
  local_78[0] = 0;
  local_38 = local_58[0];
  iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_40);
  if (iVar6 == 0) {
    local_30 = 0x18b;
    goto LAB_004bab64;
  }
  local_40 = local_40 - ((int)local_58[0] - (int)local_38);
  if (local_70 != (void *)0x0) {
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  local_38 = local_58[0];
  iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_40);
  if (iVar6 == 0) {
    local_30 = 399;
    goto LAB_004bab64;
  }
  local_40 = local_40 - ((int)local_58[0] - (int)local_38);
  iVar6 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(local_8c);
  pSVar11->ssl_version = iVar6;
  if (local_70 != (void *)0x0) {
    CRYPTO_free(local_70);
    local_70 = (void *)0x0;
    local_78[0] = 0;
  }
  unaff_s7 = &local_88;
  local_60 = (byte *)0x0;
  local_68[0] = 0;
  local_38 = local_58[0];
  iVar8 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_40);
  puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a9510;
  if (iVar8 == 0) {
    local_30 = 0x195;
    goto LAB_004bab64;
  }
  local_40 = local_40 - ((int)local_58[0] - (int)local_38);
  if (iVar6 == 2) {
    if (local_68[0] == 3) {
      uVar10 = (uint)*local_60 << 0x10 | local_60[2] | 0x2000000 | (uint)local_60[1] << 8;
LAB_004bae24:
      *(undefined4 *)(pSVar11->krb5_client_princ + 0x24) = 0;
      *(uint *)(pSVar11->krb5_client_princ + 0x28) = uVar10;
      local_38 = local_58[0];
      iVar6 = (*(code *)puVar2)(unaff_s7,unaff_s1);
      pbVar5 = local_58[0];
      puVar2 = PTR_memcpy_006aabf4;
      if (iVar6 == 0) {
        local_30 = 0x1b6;
        goto LAB_004bab64;
      }
      iVar6 = local_40 - ((int)local_58[0] - (int)local_38);
      if (0x20 < (int)local_68[0]) {
        local_68[0] = 0x20;
      }
      pSVar11->session_id_length = local_68[0];
      local_40 = iVar6;
      (*(code *)puVar2)(pSVar11->session_id,local_60,local_68[0]);
      local_38 = pbVar5;
      iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,iVar6);
      pbVar4 = local_58[0];
      pbVar5 = local_60;
      puVar2 = PTR_memcpy_006aabf4;
      if (iVar6 == 0) {
        local_30 = 0x1c5;
        goto LAB_004bab64;
      }
      uVar10 = local_68[0];
      if (0x30 < (int)local_68[0]) {
        uVar10 = 0x30;
      }
      local_40 = local_40 - ((int)local_58[0] - (int)local_38);
      pSVar11->master_key_length = uVar10;
      (*(code *)puVar2)(pSVar11->master_key,local_60,uVar10);
      puVar2 = PTR_d2i_ASN1_OCTET_STRING_006a9510;
      local_68[0] = 0;
      if (local_40 == 0) {
LAB_004baf1c:
        uVar10 = 0;
      }
      else {
        bVar1 = *pbVar4;
        if ((bVar1 & 0xdf) != 0x80) goto LAB_004baf1c;
        *pbVar4 = bVar1 & 0x20 | 4;
        local_38 = local_58[0];
        iVar6 = (*(code *)puVar2)(unaff_s7,unaff_s1,local_40);
        if (iVar6 == 0) {
          local_30 = 0x1e0;
          *local_38 = bVar1;
          goto LAB_004bab64;
        }
        local_40 = local_40 - ((int)local_58[0] - (int)local_38);
        *local_38 = bVar1;
        uVar10 = local_68[0];
        pbVar5 = local_60;
        if (8 < (int)local_68[0]) {
          uVar10 = 8;
        }
      }
      puVar2 = PTR_memcpy_006aabf4;
      pSVar11->key_arg_length = uVar10;
      (*(code *)puVar2)(pSVar11->key_arg,pbVar5);
      if (local_60 != (byte *)0x0) {
        CRYPTO_free(local_60);
      }
      local_78[0] = 0;
      if ((local_40 != 0) && (*local_58[0] == 0xa1)) {
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 0x1e9;
          goto LAB_004bab64;
        }
        if (uVar10 == 0x21) {
          local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
          iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = local_40 - ((int)local_58[0] - (int)local_38);
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004bb61c;
            local_50 = 0x3f;
          }
        }
        else {
          iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
          if (iVar6 != 0) {
LAB_004bb61c:
            local_40 = local_40 - ((int)local_58[0] - (int)local_38);
            goto LAB_004baf70;
          }
        }
        local_30 = 0x1e9;
        goto LAB_004bab64;
      }
LAB_004baf70:
      if (local_70 == (void *)0x0) {
        uVar9 = (*(code *)PTR_time_006aabe4)(0);
        *(undefined4 *)(pSVar11->krb5_client_princ + 0x1c) = uVar9;
      }
      else {
        uVar9 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(local_8c);
        *(undefined4 *)(pSVar11->krb5_client_princ + 0x1c) = uVar9;
        CRYPTO_free(local_70);
        local_70 = (void *)0x0;
      }
      local_78[0] = 0;
      if ((local_40 != 0) && (*local_58[0] == 0xa2)) {
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 499;
          goto LAB_004bab64;
        }
        if (uVar10 == 0x21) {
          local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
          iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = local_40 - ((int)local_58[0] - (int)local_38);
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004bb5dc;
            local_50 = 0x3f;
          }
        }
        else {
          iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
          if (iVar6 != 0) {
LAB_004bb5dc:
            local_40 = local_40 - ((int)local_58[0] - (int)local_38);
            goto LAB_004bafc0;
          }
        }
        local_30 = 499;
        goto LAB_004bab64;
      }
LAB_004bafc0:
      if (local_70 == (void *)0x0) {
        *(undefined4 *)(pSVar11->krb5_client_princ + 0x18) = 3;
      }
      else {
        uVar9 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(local_8c);
        *(undefined4 *)(pSVar11->krb5_client_princ + 0x18) = uVar9;
        CRYPTO_free(local_70);
        local_70 = (void *)0x0;
        local_78[0] = 0;
      }
      if (*(int *)(pSVar11->krb5_client_princ + 0xc) != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
        *(undefined4 *)(pSVar11->krb5_client_princ + 0xc) = 0;
      }
      if (local_40 == 0) {
        local_68[0] = 0;
        local_60 = (byte *)0x0;
LAB_004bb048:
        pSVar11->sid_ctx_length = 0;
      }
      else {
        if (*local_58[0] != 0xa3) {
LAB_004bb038:
          local_60 = (byte *)0x0;
          local_68[0] = 0;
          if (*local_58[0] == 0xa4) {
            local_38 = local_58[0];
            uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                               (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
            if ((uVar10 & 0x80) != 0) {
              local_50 = 0x3b;
              local_30 = 0x205;
              goto LAB_004bab64;
            }
            if (uVar10 == 0x21) {
              local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
              iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
              if (iVar6 != 0) {
                local_7c = local_40 - ((int)local_58[0] - (int)local_38);
                iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
                if (iVar6 != 0) goto LAB_004bb65c;
                local_50 = 0x3f;
              }
            }
            else {
              iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
              if (iVar6 != 0) {
LAB_004bb65c:
                pbVar5 = local_60;
                puVar2 = PTR_memcpy_006aabf4;
                local_40 = local_40 - ((int)local_58[0] - (int)local_38);
                if (local_60 != (byte *)0x0) {
                  if (0x20 < (int)local_68[0]) {
                    local_50 = 0x10f;
                    goto LAB_004bab64;
                  }
                  pSVar11->sid_ctx_length = local_68[0];
                  (*(code *)puVar2)(pSVar11->sid_ctx,local_60);
                  CRYPTO_free(pbVar5);
                  local_60 = (byte *)0x0;
                  local_68[0] = 0;
                  goto LAB_004bb04c;
                }
                goto LAB_004bb048;
              }
            }
            local_30 = 0x205;
            goto LAB_004bab64;
          }
          goto LAB_004bb048;
        }
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 0x201;
          goto LAB_004bab64;
        }
        if (uVar10 == 0x21) {
          local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
          iVar6 = (*(code *)PTR_d2i_X509_006a9070)
                            (pSVar11->krb5_client_princ + 0xc,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = local_40 - ((int)local_58[0] - (int)local_38);
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004bb588;
            local_50 = 0x3f;
          }
LAB_004bbc9c:
          local_30 = 0x201;
          goto LAB_004bab64;
        }
        iVar6 = (*(code *)PTR_d2i_X509_006a9070)(pSVar11->krb5_client_princ + 0xc,unaff_s1,local_7c)
        ;
        if (iVar6 == 0) goto LAB_004bbc9c;
LAB_004bb588:
        local_68[0] = 0;
        local_60 = (byte *)0x0;
        local_40 = local_40 - ((int)local_58[0] - (int)local_38);
        if (local_40 != 0) goto LAB_004bb038;
        pSVar11->sid_ctx_length = 0;
      }
LAB_004bb04c:
      local_78[0] = 0;
      if ((local_40 != 0) && (*local_58[0] == 0xa5)) {
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 0x219;
          goto LAB_004bab64;
        }
        if (uVar10 == 0x21) {
          local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
          iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = local_40 - ((int)local_58[0] - (int)local_38);
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004bb9b8;
            local_50 = 0x3f;
          }
        }
        else {
          iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
          if (iVar6 != 0) {
LAB_004bb9b8:
            local_40 = local_40 - ((int)local_58[0] - (int)local_38);
            goto LAB_004bb068;
          }
        }
        local_30 = 0x219;
        goto LAB_004bab64;
      }
LAB_004bb068:
      if (local_70 == (void *)0x0) {
        *(undefined4 *)(pSVar11->krb5_client_princ + 0x10) = 0;
      }
      else {
        uVar9 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(local_8c);
        *(undefined4 *)(pSVar11->krb5_client_princ + 0x10) = uVar9;
        CRYPTO_free(local_70);
        local_70 = (void *)0x0;
        local_78[0] = 0;
      }
      local_68[0] = 0;
      local_60 = (byte *)0x0;
      if ((local_40 != 0) && (*local_58[0] == 0xa6)) {
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 0x225;
          goto LAB_004bab64;
        }
        if (uVar10 == 0x21) {
          local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
          iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = local_40 - ((int)local_58[0] - (int)local_38);
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004bbb00;
            local_50 = 0x3f;
          }
        }
        else {
          iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
          if (iVar6 != 0) {
LAB_004bbb00:
            local_40 = local_40 - ((int)local_58[0] - (int)local_38);
            if (local_60 == (byte *)0x0) goto LAB_004bb0b0;
            uVar9 = (*(code *)PTR_BUF_strndup_006a9520)(local_60,local_68[0]);
            *(undefined4 *)(pSVar11->krb5_client_princ + 0x40) = uVar9;
            CRYPTO_free(local_60);
            goto LAB_004bb0b4;
          }
        }
        local_30 = 0x225;
        goto LAB_004bab64;
      }
LAB_004bb0b0:
      *(undefined4 *)(pSVar11->krb5_client_princ + 0x40) = 0;
LAB_004bb0b4:
      local_68[0] = 0;
      local_60 = (byte *)0x0;
      if ((local_40 != 0) && (*local_58[0] == 0xa7)) {
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) != 0) {
          local_50 = 0x3b;
          local_30 = 0x234;
          goto LAB_004bab64;
        }
        if (uVar10 == 0x21) {
          local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
          iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
          if (iVar6 != 0) {
            local_7c = local_40 - ((int)local_58[0] - (int)local_38);
            iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
            if (iVar6 != 0) goto LAB_004bba88;
            local_50 = 0x3f;
          }
        }
        else {
          iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
          if (iVar6 != 0) {
LAB_004bba88:
            local_40 = local_40 - ((int)local_58[0] - (int)local_38);
            if (local_60 == (byte *)0x0) goto LAB_004bb0c0;
            uVar10 = (*(code *)PTR_BUF_strndup_006a9520)(local_60,local_68[0]);
            pSVar11->krb5_client_princ_len = uVar10;
            CRYPTO_free(local_60);
            goto LAB_004bb0c4;
          }
        }
        local_30 = 0x234;
        goto LAB_004bab64;
      }
LAB_004bb0c0:
      pSVar11->krb5_client_princ_len = 0;
LAB_004bb0c4:
      local_68[0] = 0;
      local_60 = (byte *)0x0;
      if ((local_40 == 0) || (*local_58[0] != 0xa8)) {
LAB_004bb0d0:
        *(undefined4 *)pSVar11->krb5_client_princ = 0;
LAB_004bb0d4:
        local_78[0] = 0;
        pSVar7 = pSVar11;
        if (local_40 == 0) goto LAB_004bb0f0;
        iVar6 = local_40;
        pbVar5 = local_58[0];
        pcVar12 = (code *)PTR_ASN1_get_object_006a9514;
        if (*local_58[0] == 0xa9) goto LAB_004bb728;
        goto LAB_004bb0f0;
      }
      local_38 = local_58[0];
      uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                         (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
      if ((uVar10 & 0x80) != 0) {
        local_50 = 0x3b;
        local_30 = 0x241;
        goto LAB_004bab64;
      }
      if (uVar10 == 0x21) {
        local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
        iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
        if (iVar6 != 0) {
          local_7c = local_40 - ((int)local_58[0] - (int)local_38);
          iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
          if (iVar6 != 0) goto LAB_004bbb78;
          local_50 = 0x3f;
        }
      }
      else {
        iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
        if (iVar6 != 0) {
LAB_004bbb78:
          local_40 = local_40 - ((int)local_58[0] - (int)local_38);
          if (local_60 != (byte *)0x0) {
            uVar9 = (*(code *)PTR_BUF_strndup_006a9520)(local_60,local_68[0]);
            *(undefined4 *)pSVar11->krb5_client_princ = uVar9;
            CRYPTO_free(local_60);
            local_60 = (byte *)0x0;
            local_68[0] = 0;
            goto LAB_004bb0d4;
          }
          goto LAB_004bb0d0;
        }
      }
      local_30 = 0x241;
      goto LAB_004bab64;
    }
  }
  else {
    if (iVar6 < 0x300) {
      local_50 = 0xfe;
      goto LAB_004bab64;
    }
    if (local_68[0] == 2) {
      uVar10 = (uint)*local_60 << 8 | local_60[1] | 0x3000000;
      goto LAB_004bae24;
    }
  }
  local_50 = 0x89;
LAB_004bab64:
  do {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,local_50,"ssl_asn1.c",local_30);
    (*(code *)PTR_asn1_add_error_006a9508)(*pp,(int)local_38 - (int)*pp);
    if ((a == (SSL_SESSION **)0x0) || (pSVar7 = (SSL_SESSION *)0x0, pSVar11 != *a)) {
      SSL_SESSION_free(pSVar11);
      pSVar7 = (SSL_SESSION *)0x0;
    }
LAB_004babc4:
    if (local_2c == *(byte **)puVar3) {
      return pSVar7;
    }
    pbVar5 = local_2c;
    pcVar12 = (code *)PTR___stack_chk_fail_006aabb8;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar6 = extraout_v1;
LAB_004bb728:
    local_38 = pbVar5;
    uVar10 = (*pcVar12)(unaff_s1,&local_7c,auStack_84,auStack_80,iVar6);
    if ((uVar10 & 0x80) != 0) {
      local_50 = 0x3b;
      local_30 = 0x24f;
      goto LAB_004bab64;
    }
    if (uVar10 == 0x21) {
      local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
      iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
      if (iVar6 != 0) {
        local_7c = local_40 - ((int)local_58[0] - (int)local_38);
        iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
        if (iVar6 != 0) goto LAB_004bb8ec;
        local_50 = 0x3f;
      }
LAB_004bc148:
      local_30 = 0x24f;
      goto LAB_004bab64;
    }
    iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(unaff_s5,unaff_s1,local_7c);
    if (iVar6 == 0) goto LAB_004bc148;
LAB_004bb8ec:
    local_40 = local_40 - ((int)local_58[0] - (int)local_38);
    pSVar7 = pSVar11;
LAB_004bb0f0:
    if (local_70 == (void *)0x0) {
      if ((*(int *)(pSVar7->krb5_client_princ + 0x58) == 0) || (pSVar7->session_id_length == 0)) {
        *(undefined4 *)(pSVar7->krb5_client_princ + 0x5c) = 0;
      }
      else {
        *(undefined4 *)(pSVar7->krb5_client_princ + 0x5c) = 0xffffffff;
      }
    }
    else {
      uVar9 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(local_8c);
      *(undefined4 *)(pSVar7->krb5_client_princ + 0x5c) = uVar9;
      CRYPTO_free(local_70);
      local_70 = (void *)0x0;
      local_78[0] = 0;
    }
    local_68[0] = 0;
    local_60 = (byte *)0x0;
    pSVar11 = pSVar7;
    if (local_40 != 0) {
      if (*local_58[0] == 0xaa) {
        local_38 = local_58[0];
        uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                           (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
        if ((uVar10 & 0x80) == 0) {
          if (uVar10 == 0x21) {
            local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
            iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
            if (iVar6 != 0) {
              local_7c = local_40 - ((int)local_58[0] - (int)local_38);
              iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
              if (iVar6 != 0) goto LAB_004bb814;
              local_50 = 0x3f;
            }
          }
          else {
            iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
            if (iVar6 != 0) {
LAB_004bb814:
              local_40 = local_40 - ((int)local_58[0] - (int)local_38);
              if (local_60 != (byte *)0x0) {
                *(uint *)(pSVar7->krb5_client_princ + 0x58) = local_68[0];
              }
              *(byte **)(pSVar7->krb5_client_princ + 0x54) = local_60;
              if (local_40 == 0) {
                local_68[0] = 0;
                local_60 = (byte *)0x0;
                goto LAB_004bb180;
              }
              goto LAB_004bb158;
            }
          }
          local_30 = 0x25b;
        }
        else {
          local_50 = 0x3b;
          local_30 = 0x25b;
        }
      }
      else {
        *(undefined4 *)(pSVar7->krb5_client_princ + 0x54) = 0;
LAB_004bb158:
        local_60 = (byte *)0x0;
        local_68[0] = 0;
        if (*local_58[0] == 0xab) {
          local_38 = local_58[0];
          uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                             (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
          if ((uVar10 & 0x80) == 0) {
            if (uVar10 == 0x21) {
              local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
              iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
              if (iVar6 != 0) {
                local_7c = local_40 - ((int)local_58[0] - (int)local_38);
                iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
                if (iVar6 != 0) goto LAB_004bb87c;
                local_50 = 0x3f;
              }
            }
            else {
              iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
              if (iVar6 != 0) {
LAB_004bb87c:
                local_40 = local_40 - ((int)local_58[0] - (int)local_38);
                if (local_60 != (byte *)0x0) {
                  *(uint *)(pSVar7->krb5_client_princ + 0x20) = (uint)*local_60;
                  CRYPTO_free(local_60);
                }
                local_68[0] = 0;
                local_60 = (byte *)0x0;
                if (local_40 == 0) goto LAB_004bb180;
                goto LAB_004bb170;
              }
            }
            local_30 = 0x269;
          }
          else {
            local_50 = 0x3b;
            local_30 = 0x269;
          }
        }
        else {
LAB_004bb170:
          local_60 = (byte *)0x0;
          local_68[0] = 0;
          if (*local_58[0] != 0xac) goto LAB_004bb180;
          local_38 = local_58[0];
          uVar10 = (*(code *)PTR_ASN1_get_object_006a9514)
                             (unaff_s1,&local_7c,auStack_84,auStack_80,local_40);
          if ((uVar10 & 0x80) == 0) {
            if (uVar10 == 0x21) {
              local_7c = (local_40 - ((int)local_58[0] - (int)local_38)) + -2;
              iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
              if (iVar6 != 0) {
                local_7c = local_40 - ((int)local_58[0] - (int)local_38);
                iVar6 = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)(unaff_s1,local_7c);
                if (iVar6 != 0) goto LAB_004bba14;
                local_50 = 0x3f;
              }
            }
            else {
              iVar6 = (*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(unaff_s7,unaff_s1,local_7c);
              if (iVar6 != 0) {
LAB_004bba14:
                local_40 = local_40 - ((int)local_58[0] - (int)local_38);
                if (local_60 == (byte *)0x0) goto LAB_004bb180;
                uVar9 = (*(code *)PTR_BUF_strndup_006a9520)(local_60,local_68[0]);
                *(undefined4 *)(pSVar7->krb5_client_princ + 0x60) = uVar9;
                CRYPTO_free(local_60);
                local_60 = (byte *)0x0;
                local_68[0] = 0;
                goto LAB_004bb184;
              }
            }
            local_30 = 0x275;
          }
          else {
            local_50 = 0x3b;
            local_30 = 0x275;
          }
        }
      }
      goto LAB_004bab64;
    }
    *(undefined4 *)(pSVar7->krb5_client_princ + 0x54) = 0;
    local_68[0] = 0;
    local_60 = (byte *)0x0;
LAB_004bb180:
    *(undefined4 *)(pSVar7->krb5_client_princ + 0x60) = 0;
LAB_004bb184:
    iVar6 = (*(code *)PTR_asn1_const_Finish_006a9518)(unaff_s1);
    if (iVar6 != 0) {
      *pp = local_58[0];
      if (a != (SSL_SESSION **)0x0) {
        *a = pSVar7;
      }
      goto LAB_004babc4;
    }
    local_30 = 0x281;
  } while( true );
}

