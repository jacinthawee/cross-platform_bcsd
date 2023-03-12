
undefined4
dtls1_send_client_key_exchange(int *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined *unaff_s4;
  int iVar13;
  int *unaff_s7;
  uint unaff_s8;
  undefined uVar14;
  undefined auStack_2b0 [128];
  undefined local_230 [516];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1[0xd] != 0x1180) goto LAB_0049edd0;
  iVar12 = *(int *)(param_1[0xf] + 4);
  uVar3 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  iVar10 = iVar12 + 0xc;
  if ((uVar3 & 1) == 0) {
    if ((uVar3 & 0xe) == 0) {
      if ((uVar3 & 0xe0) != 0) {
        unaff_s4 = *(undefined **)(*(int *)(param_1[0x30] + 0x98) + 0x74);
        if (unaff_s4 == (undefined *)0x0) {
          unaff_s7 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                      (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x48));
          if (((unaff_s7 != (int *)0x0) && (*unaff_s7 == 0x198)) &&
             (unaff_s4 = (undefined *)unaff_s7[5], unaff_s4 != (undefined *)0x0)) goto LAB_0049ee4c;
          uVar9 = 0x44;
          uVar6 = 0x504;
        }
        else {
          unaff_s7 = (int *)0x0;
LAB_0049ee4c:
          iVar13 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(unaff_s4);
          iVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
          if ((iVar13 == 0) || (iVar4 == 0)) {
            uVar9 = 0x44;
            uVar6 = 0x511;
          }
          else {
            unaff_s4 = (undefined *)(*(code *)PTR_EC_KEY_new_006a82a8)();
            if (unaff_s4 != (undefined *)0x0) {
              iVar7 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(unaff_s4,iVar13);
              if (iVar7 == 0) {
                uVar9 = 0x10;
                uVar6 = 0x51d;
LAB_0049f558:
                param_4 = "d1_clnt.c";
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x106,uVar9,"d1_clnt.c",uVar6);
                (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                goto LAB_0049f460;
              }
              iVar7 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(unaff_s4);
              if (iVar7 == 0) {
                uVar9 = 0x2b;
                uVar6 = 0x539;
                goto LAB_0049f558;
              }
              iVar7 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(iVar13);
              if (iVar7 < 1) {
                uVar9 = 0x2b;
                uVar6 = 0x546;
                goto LAB_0049f558;
              }
              iVar4 = (*(code *)PTR_ECDH_compute_key_006a8bd4)
                                (iVar10,iVar7 + 7 >> 3,iVar4,unaff_s4,0);
              if (iVar4 < 1) {
                uVar9 = 0x2b;
                uVar6 = 0x54d;
                goto LAB_0049f558;
              }
              iVar7 = param_1[0x30];
              uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,iVar7 + 0x14,iVar10,iVar4);
              puVar1 = PTR_memset_006aab00;
              *(undefined4 *)(iVar7 + 0x10) = uVar6;
              (*(code *)puVar1)(iVar10,0,iVar4);
              uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
              uVar6 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(iVar13,uVar6,4,0,0,0);
              iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar6,"d1_clnt.c",0x56b);
              unaff_s8 = (*(code *)PTR_BN_CTX_new_006a8a38)();
              param_4 = "s\n";
              if (iVar10 == 0) goto LAB_0049f6c4;
              if (unaff_s8 == 0) {
                param_4 = "d1_clnt.c";
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x106,0x41,"d1_clnt.c",0x570);
                (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                (*(code *)PTR_CRYPTO_free_006a7f88)(iVar10);
                goto LAB_0049f460;
              }
              uVar9 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(unaff_s4);
              iVar13 = (*(code *)PTR_EC_POINT_point2oct_006a9118)
                                 (iVar13,uVar9,4,iVar10,uVar6,unaff_s8);
              *(char *)(iVar12 + 0xc) = (char)iVar13;
              pcVar11 = (char *)(iVar13 + 1);
              (*(code *)PTR_memcpy_006aabf4)(iVar12 + 0xd,iVar10,iVar13);
              (*(code *)PTR_BN_CTX_free_006a8a40)(unaff_s8);
              (*(code *)PTR_CRYPTO_free_006a7f88)(iVar10);
              (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(unaff_s7);
              goto LAB_0049ed80;
            }
            uVar9 = 0x41;
            uVar6 = 0x517;
          }
        }
        param_4 = "d1_clnt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x106,uVar9,"d1_clnt.c",uVar6);
        goto LAB_0049f3b4;
      }
      if ((uVar3 & 0x100) == 0) {
        ssl3_send_alert(param_1,2,0x28);
        uVar9 = 0x44;
        uVar6 = 0x5e1;
      }
      else {
        if ((code *)param_1[0x37] != (code *)0x0) {
          unaff_s4 = local_230;
          uVar3 = (*(code *)param_1[0x37])
                            (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),auStack_2b0,0x80,
                             unaff_s4,0x204);
          if (uVar3 < 0x101) {
            if (uVar3 == 0) {
              uVar9 = 0xdf;
              uVar6 = 0x5a9;
            }
            else {
              (*(code *)PTR_memmove_006aabfc)(unaff_s4 + uVar3 + 4,unaff_s4,uVar3);
              unaff_s8 = (uVar3 << 0x10) >> 0x18;
              uVar14 = (undefined)(uVar3 >> 8);
              local_230[0] = uVar14;
              local_230[1] = (char)uVar3;
              (*(code *)PTR___memset_chk_006aaa98)(local_230 + 2,0,uVar3,0x202);
              iVar10 = param_1[0x30];
              (local_230 + 2)[uVar3] = uVar14;
              local_230[uVar3 + 3] = (char)uVar3;
              if (*(int *)(iVar10 + 0x8c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar10 = param_1[0x30];
              }
              uVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(param_1[0x39] + 0x14c));
              iVar13 = param_1[0x39];
              unaff_s7 = (int *)param_1[0x30];
              *(undefined4 *)(iVar10 + 0x8c) = uVar6;
              if ((*(int *)(iVar13 + 0x14c) == 0) || (unaff_s7[0x23] != 0)) {
                if (unaff_s7[0x24] != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                  unaff_s7 = (int *)param_1[0x30];
                }
                iVar10 = (*(code *)PTR_BUF_strdup_006a80dc)(auStack_2b0);
                iVar13 = param_1[0x30];
                unaff_s7[0x24] = iVar10;
                if (*(int *)(iVar13 + 0x90) != 0) {
                  uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar13 + 0x14,unaff_s4,uVar3 * 2 + 4);
                  puVar1 = PTR_strlen_006aab30;
                  *(undefined4 *)(iVar13 + 0x10) = uVar6;
                  iVar10 = (*(code *)puVar1)(auStack_2b0);
                  *(char *)(iVar12 + 0xd) = (char)iVar10;
                  *(char *)(iVar12 + 0xc) = (char)((uint)iVar10 >> 8);
                  pcVar11 = (char *)(iVar10 + 2);
                  (*(code *)PTR_memcpy_006aabf4)(iVar12 + 0xe,auStack_2b0,iVar10);
                  (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_2b0,0x80);
                  (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
                  goto LAB_0049ed80;
                }
                uVar9 = 0x41;
                uVar6 = 0x5c7;
              }
              else {
                uVar9 = 0x41;
                uVar6 = 0x5bd;
              }
            }
          }
          else {
            uVar9 = 0x44;
            uVar6 = 0x5a3;
          }
          param_4 = "d1_clnt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x106,uVar9,"d1_clnt.c",uVar6);
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_2b0,0x80);
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s4,0x204);
          ssl3_send_alert(param_1,2,0x28);
          goto LAB_0049f3b0;
        }
        uVar9 = 0xe0;
        uVar6 = 0x599;
      }
    }
    else {
      iVar13 = *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x70);
      if (iVar13 == 0) {
        ssl3_send_alert(param_1,2,0x28);
        uVar9 = 0xee;
        uVar6 = 0x4a5;
      }
      else {
        unaff_s4 = (undefined *)(*(code *)PTR_DHparams_dup_006a90f8)(iVar13);
        if (unaff_s4 == (undefined *)0x0) {
          uVar9 = 5;
          uVar6 = 0x4ac;
        }
        else {
          iVar4 = (*(code *)PTR_DH_generate_key_006a90fc)(unaff_s4);
          if (iVar4 == 0) {
            uVar9 = 5;
            uVar6 = 0x4b1;
          }
          else {
            iVar13 = (*(code *)PTR_DH_compute_key_006a912c)
                               (iVar10,*(undefined4 *)(iVar13 + 0x14),unaff_s4);
            if (0 < iVar13) {
              iVar4 = param_1[0x30];
              uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,iVar4 + 0x14,iVar10,iVar13);
              puVar1 = PTR_memset_006aab00;
              *(undefined4 *)(iVar4 + 0x10) = uVar6;
              (*(code *)puVar1)(iVar10,0,iVar13);
              iVar13 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(unaff_s4 + 0x14));
              puVar1 = PTR_BN_bn2bin_006a8300;
              iVar10 = iVar13 + 7;
              if (iVar13 + 7 < 0) {
                iVar10 = iVar13 + 0xe;
              }
              pcVar11 = (char *)((iVar10 >> 3) + 2);
              *(char *)(iVar12 + 0xd) = (char)(iVar10 >> 3);
              *(char *)(iVar12 + 0xc) = (char)(iVar10 >> 0xb);
              (*(code *)puVar1)(*(undefined4 *)(unaff_s4 + 0x14),iVar12 + 0xe);
              (*(code *)PTR_DH_free_006a8604)(unaff_s4);
              goto LAB_0049ed80;
            }
            uVar9 = 5;
            uVar6 = 0x4bc;
          }
        }
      }
    }
LAB_0049f4fc:
    param_4 = "d1_clnt.c";
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x106,uVar9,"d1_clnt.c",uVar6);
  }
  else {
    iVar13 = *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x6c);
    if (iVar13 == 0) {
      piVar8 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
      if (((piVar8 == (int *)0x0) || (param_4 = "s\n", *piVar8 != 6)) ||
         (iVar13 = piVar8[5], iVar13 == 0)) {
        uVar9 = 0x44;
        uVar6 = 0x3ea;
        goto LAB_0049f4fc;
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar8);
    }
    local_230[1] = (undefined)param_1[0x44];
    local_230[0] = (undefined)((uint)param_1[0x44] >> 8);
    iVar4 = (*(code *)PTR_RAND_bytes_006a8d44)(local_230 + 2,0x2e);
    puVar1 = PTR_RSA_public_encrypt_006a8744;
    if (0 < iVar4) {
      unaff_s4 = local_230;
      iVar4 = iVar12 + 0xe;
      if (*param_1 < 0x301) {
        iVar4 = iVar10;
      }
      *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
      pcVar5 = (char *)(*(code *)puVar1)(0x30,unaff_s4,iVar4,iVar13,1);
      if ((int)pcVar5 < 1) {
        uVar9 = 0x77;
        uVar6 = 0x404;
        goto LAB_0049f4fc;
      }
      pcVar11 = pcVar5;
      if (0x300 < *param_1) {
        *(char *)(iVar12 + 0xd) = (char)pcVar5;
        pcVar11 = pcVar5 + 2;
        *(char *)(iVar12 + 0xc) = (char)((uint)pcVar5 >> 8);
      }
      iVar10 = param_1[0x30];
      uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar10 + 0x14,unaff_s4,0x30);
      puVar1 = PTR_OPENSSL_cleanse_006a8174;
      *(undefined4 *)(iVar10 + 0x10) = uVar6;
      (*(code *)puVar1)(unaff_s4,0x30);
LAB_0049ed80:
      param_4 = pcVar11;
      dtls1_set_message_header(param_1,iVar12,0x10,pcVar11,0,pcVar11);
      param_1[0x12] = 0;
      param_1[0x11] = (int)(pcVar11 + 0xc);
      param_1[0xd] = 0x1181;
      dtls1_buffer_message(param_1,0);
LAB_0049edd0:
      uVar6 = dtls1_do_write(param_1,0x16);
      goto LAB_0049ede0;
    }
  }
LAB_0049f3b0:
  unaff_s7 = (int *)0x0;
LAB_0049f3b4:
  (*(code *)PTR_BN_CTX_free_006a8a40)(0);
  while( true ) {
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(unaff_s7);
    uVar6 = 0xffffffff;
LAB_0049ede0:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0049f6c4:
    param_4 = param_4 + 0x7cfc;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x106,0x41,param_4,0x570);
    (*(code *)PTR_BN_CTX_free_006a8a40)(unaff_s8);
LAB_0049f460:
    (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s4);
  }
  return uVar6;
}

